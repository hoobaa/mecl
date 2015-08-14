#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/list.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    list.d -- List manipulating routines.
*/
/*
    Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <ecl/ecl.h>
#include <ecl/ecl-inl.h>

struct cl_test {
	bool (*test_c_function)(struct cl_test *, cl_object);
	cl_object (*key_c_function)(struct cl_test *, cl_object);
	cl_env_ptr env;
	cl_object key_function;
	cl_objectfn key_fn;
	cl_object test_function;
	cl_objectfn test_fn;
	cl_object item_compared;
};

static cl_object subst(struct cl_test *t, cl_object new_obj, cl_object tree);
static cl_object nsubst(struct cl_test *t, cl_object new_obj, cl_object tree);
static cl_object sublis(struct cl_test *t, cl_object alist, cl_object tree);
static cl_object nsublis(struct cl_test *t, cl_object alist, cl_object tree);
static cl_object do_assoc(struct cl_test *t, cl_object alist);

#define TEST(t,k) ((t)->test_c_function)((t),(k))
#define KEY(t,x) ((t)->key_c_function)((t),(x))
#define close_test(t) (void)0

static bool
test_compare(struct cl_test *t, cl_object x)
{
	x = KEY(t,x);
	t->env->function = t->test_function;
    printf("string tag 1st(%d) 2nd(%d)", t->item_compared->string.t, x->string.t);
	return t->test_fn(2, t->item_compared, x) != ECL_NIL;
}

static bool
test_compare_not(struct cl_test *t, cl_object x)
{
	x = KEY(t,x);
	t->env->function = t->test_function;
	return t->test_fn(2, t->item_compared, x) == ECL_NIL;
}

static bool
test_eq(struct cl_test *t, cl_object x)
{
	return (t->item_compared == KEY(t,x));
}

static bool
test_eql(struct cl_test *t, cl_object x)
{
	return ecl_eql(t->item_compared, KEY(t,x));
}

static bool
test_equal(struct cl_test *t, cl_object x)
{
	return ecl_equal(t->item_compared, KEY(t,x));
}

static bool
test_equalp(struct cl_test *t, cl_object x)
{
	return ecl_equalp(t->item_compared, KEY(t,x));
}

static cl_object
key_function(struct cl_test *t, cl_object x)
{
	t->env->function = t->key_function;
	return t->key_fn(1,x);
}

static cl_object
key_identity(struct cl_test *t, cl_object x)
{
	return x;
}

static void
setup_test(struct cl_test *t, cl_object item, cl_object test,
	   cl_object test_not, cl_object key)
{
	cl_env_ptr env = t->env = ecl_process_env();
	t->item_compared = item;
	if (test != ECL_NIL) {
		if (test_not != ECL_NIL)
		    FEerror("Both :TEST and :TEST-NOT are specified.", 0);
		t->test_function = test = si_coerce_to_function(test);
		if (test == ECL_SYM_FUN(ECL_SYM("EQ",333))) {
			t->test_c_function = test_eq;
		} else if (test == ECL_SYM_FUN(ECL_SYM("EQL",334))) {
			t->test_c_function = test_eql;
		} else if (test == ECL_SYM_FUN(ECL_SYM("EQUAL",335))) {
			t->test_c_function = test_equal;
		} else if (test == ECL_SYM_FUN(ECL_SYM("EQUALP",336))) {
			t->test_c_function = test_equalp;
		} else {
			t->test_c_function = test_compare;
			t->test_fn = ecl_function_dispatch(env, test);
			t->test_function = env->function;
		}
	} else if (test_not != ECL_NIL) {
		t->test_c_function = test_compare_not;
		test_not = si_coerce_to_function(test_not);
		t->test_fn = ecl_function_dispatch(env, test_not);
		t->test_function = env->function;
	} else {
		t->test_c_function = test_eql;
	}
	if (key != ECL_NIL) {
		key = si_coerce_to_function(key);
		t->key_fn = ecl_function_dispatch(env, key);
		t->key_function = env->function;
		t->key_c_function = key_function;
	} else {
		t->key_c_function = key_identity;
	}
}

#line 137
cl_object cl_list(cl_narg narg, ...)
{
#line 137

	cl_object head = ECL_NIL;
#line 140
	const cl_env_ptr the_env = ecl_process_env();
#line 140
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 140
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(481));
#line 140
	if (narg--) {
		cl_object tail = head = ecl_list1(ecl_va_arg(args));
		while (narg--) {
			cl_object cons = ecl_list1(ecl_va_arg(args));
			ECL_RPLACD(tail, cons);
			tail = cons;
		}
	}
	{
#line 148
		#line 148
		cl_object __value0 = head;
#line 148
		the_env->nvalues = 1;
#line 148
		return __value0;
#line 148
	}

}

#line 151
cl_object cl_listX(cl_narg narg, ...)
{
#line 151

	cl_object head;
#line 154
	const cl_env_ptr the_env = ecl_process_env();
#line 154
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 154
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(482));
#line 154
	if (narg == 0)
		FEwrong_num_arguments(ecl_make_fixnum(/*LIST**/482));
	head = ecl_va_arg(args);
	if (--narg) {
		cl_object tail = head = ecl_list1(head);
		while (--narg) {
			cl_object cons = ecl_list1(ecl_va_arg(args));
			ECL_RPLACD(tail, cons);
			tail = cons;
		}
		ECL_RPLACD(tail, ecl_va_arg(args));
	}
	{
#line 166
		#line 166
		cl_object __value0 = head;
#line 166
		the_env->nvalues = 1;
#line 166
		return __value0;
#line 166
	}

}

static cl_object *
append_into(cl_object head, cl_object *tail, cl_object l)
{
	if (!Null(*tail)) {
		/* (APPEND '(1 . 2) 3) */
		FEtype_error_proper_list(head);
	}
	while (CONSP(l)) {
		cl_object cons = ecl_list1(ECL_CONS_CAR(l));
		*tail = cons;
		tail = &ECL_CONS_CDR(cons);
		l = ECL_CONS_CDR(l);
	}
        *tail = l;
	return tail;
}

#line 186
cl_object cl_append(cl_narg narg, ...)
{
#line 186

	cl_object head = ECL_NIL, *tail = &head;
#line 189
	const cl_env_ptr the_env = ecl_process_env();
#line 189
	ecl_va_list rest;
	ecl_va_start(rest, narg, narg, 0);
#line 189
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(88));
#line 189
	for (; narg > 1; narg--) {
		cl_object other = ecl_va_arg(rest);
                tail = append_into(head, tail, other);
	}
        if (narg) {
                if (!Null(*tail)) {
                        /* (APPEND '(1 . 2) 3) */
                        FEtype_error_proper_list(head);
                }
                *tail = ecl_va_arg(rest);
        }
	{
#line 200
		#line 200
		cl_object __value0 = head;
#line 200
		the_env->nvalues = 1;
#line 200
		return __value0;
#line 200
	}

}

cl_object
ecl_append(cl_object x, cl_object y)
{
	cl_object head = ECL_NIL;
        cl_object *tail = &head;
	if (!Null(x)) {
                tail = append_into(head, tail, x);
        }
        if (!Null(*tail)) {
                /* (APPEND '(1 . 2) 3) */
                FEtype_error_proper_list(head);
        }
        *tail = y;
	return head;
}

#define LENTH(n) (cl_object x) {				\
		const cl_env_ptr the_env = ecl_process_env();	\
		ecl_return1(the_env, ecl_nth(n, x));		\
	}
cl_object cl_fifth	LENTH(4)
cl_object cl_sixth	LENTH(5)
cl_object cl_seventh	LENTH(6)
cl_object cl_eighth	LENTH(7)
cl_object cl_ninth	LENTH(8)
cl_object cl_tenth	LENTH(9)
#undef LENTH

static bool
tree_equal(struct cl_test *t, cl_object x, cl_object y)
{
BEGIN:
	if (CONSP(x)) {
		if (CONSP(y)) {
			if (tree_equal(t, ECL_CONS_CAR(x), ECL_CONS_CAR(y))) {
				x = ECL_CONS_CDR(x);
				y = ECL_CONS_CDR(y);
				goto BEGIN;
			} else {
				return(FALSE);
			}
		} else {
			return(FALSE);
		}
	} else {
		t->item_compared = x;
		if (TEST(t, y))
			return(TRUE);
		else
			return(FALSE);
	}
}

#line 256
cl_object cl_tree_equal(cl_narg narg, cl_object x, cl_object y, ...)
{
#line 256

	struct cl_test t;
	cl_object output;
#line 260
	const cl_env_ptr the_env = ecl_process_env();
#line 260
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317)};
	cl_object test;
	cl_object test_not;
#line 260
	cl_object KEY_VARS[4];
#line 260
	ecl_va_list ARGS;
	ecl_va_start(ARGS, y, narg, 2);
#line 260
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(863));
#line 260
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 260
	if (KEY_VARS[2]==ECL_NIL) {
#line 260
	  test = ECL_NIL;
	} else {
#line 260
	  test = KEY_VARS[0];
	}
#line 260
	if (KEY_VARS[3]==ECL_NIL) {
#line 260
	  test_not = ECL_NIL;
	} else {
#line 260
	  test_not = KEY_VARS[1];
	}
#line 260
	setup_test(&t, ECL_NIL, test, test_not, ECL_NIL);
	output = tree_equal(&t, x, y)? ECL_T : ECL_NIL;
	close_test(&t);
	{
#line 263
		#line 263
		cl_object __value0 = output;
#line 263
		the_env->nvalues = 1;
#line 263
		return __value0;
#line 263
	}

}

cl_object
cl_endp(cl_object x)
{
        cl_object output = ECL_NIL;
	if (Null(x)) {
                output = ECL_T;
        } else if (ecl_unlikely(!LISTP(x))) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*ENDP*/330), x, ecl_make_fixnum(/*LIST*/481));
        }
        {
#line 275
	const cl_env_ptr the_env = ecl_process_env();
#line 275
	#line 275
	cl_object __value0 = output;
#line 275
	the_env->nvalues = 1;
#line 275
	return __value0;
#line 275
}
;
}

bool
ecl_endp(cl_object x)
{
	if (Null(x)) {
                return TRUE;
        } else if (ecl_unlikely(!LISTP(x))) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*ENDP*/330), x, ecl_make_fixnum(/*LIST*/481));
        }
        return FALSE;
}

cl_object
cl_list_length(cl_object x)
{
	cl_fixnum n;
	cl_object fast, slow;
	/* INV: A list's length always fits in a fixnum */
	fast = slow = x;
	for (n = 0; !Null(fast); n++, fast = ECL_CONS_CDR(fast)) {
		if (ecl_unlikely(!LISTP(fast))) {
			FEtype_error_list(fast);
		}
		if (n & 1) {
			/* Circular list? */
			if (slow == fast) {
#line 302
				const cl_env_ptr the_env = ecl_process_env();
#line 302
				#line 302
				cl_object __value0 = ECL_NIL;
#line 302
				the_env->nvalues = 1;
#line 302
				return __value0;
#line 302
			}
;
			slow = ECL_CONS_CDR(slow);
		}
	}
	{
#line 306
		const cl_env_ptr the_env = ecl_process_env();
#line 306
		#line 306
		cl_object __value0 = ecl_make_fixnum(n);
#line 306
		the_env->nvalues = 1;
#line 306
		return __value0;
#line 306
	}
;
}

cl_object
si_proper_list_p(cl_object x)
{
	cl_fixnum n;
	cl_object fast, slow, test = ECL_T;
	/* INV: A list's length always fits in a fixnum */
	fast = slow = x;
	for (n = 0; !Null(fast); n++, fast = ECL_CONS_CDR(fast)) {
		if (!LISTP(fast)) {
                        test = ECL_NIL;
                        break;
		}
		if (n & 1) {
			/* Circular list? */
			if (slow == fast) {
                                test = ECL_NIL;
                                break;
                        }
			slow = ECL_CONS_CDR(slow);
		}
	}
	{
#line 330
		const cl_env_ptr the_env = ecl_process_env();
#line 330
		#line 330
		cl_object __value0 = test;
#line 330
		the_env->nvalues = 1;
#line 330
		return __value0;
#line 330
	}
;
}

cl_object
cl_nth(cl_object n, cl_object x)
{
	{
#line 336
		const cl_env_ptr the_env = ecl_process_env();
#line 336
		#line 336
		cl_object __value0 = ecl_nth(ecl_to_size(n), x);
#line 336
		the_env->nvalues = 1;
#line 336
		return __value0;
#line 336
	}

}

cl_object
ecl_nth(cl_fixnum n, cl_object x)
{
	if (n < 0)
		FEtype_error_index(x, n);
	/* INV: No need to check for circularity since we visit
	   at most `n' conses */
	for (; n > 0 && CONSP(x); n--)
		x = ECL_CONS_CDR(x);
	if (Null(x))
		return ECL_NIL;
	if (!LISTP(x))
		FEtype_error_list(x);
	return ECL_CONS_CAR(x);
}

cl_object
cl_nthcdr(cl_object n, cl_object x)
{
	{
#line 358
		const cl_env_ptr the_env = ecl_process_env();
#line 358
		#line 358
		cl_object __value0 = ecl_nthcdr(ecl_to_size(n), x);
#line 358
		the_env->nvalues = 1;
#line 358
		return __value0;
#line 358
	}

}

cl_object
ecl_nthcdr(cl_fixnum n, cl_object x)
{
	if (n < 0)
		FEtype_error_index(x, n);
	while (n-- > 0 && !Null(x)) {
		if (LISTP(x)) {
			x = ECL_CONS_CDR(x);
		} else {
			FEtype_error_list(x);
		}
	}
	return x;
}

cl_object
ecl_last(cl_object l, cl_index n)
{
	/* The algorithm is very simple. We run over the list with
	 * two pointers, "l" and "r". The separation between both
	 * must be "n", so that when "l" finds no more conses, "r"
	 * contains the output. */
	cl_object r;
	for (r = l; n && CONSP(r); n--, r = ECL_CONS_CDR(r))
		;
	/* If "l" has not moved, we have to ensure that it is a list */
	if (r == l) {
		if (!LISTP(r)) FEtype_error_list(l);
		while (CONSP(r)) {
			r = ECL_CONS_CDR(r);
		}
		return r;
	} else if (n == 0) {
		while (CONSP(r)) {
			r = ECL_CONS_CDR(r);
			l = ECL_CONS_CDR(l);
		}
		return l;
	} else {
		return l;
	}
}

#line 404
cl_object cl_last(cl_narg narg, cl_object l, ...)
{
#line 404

#line 406
	const cl_env_ptr the_env = ecl_process_env();
#line 406
	cl_object k;
#line 406
	va_list ARGS;
	va_start(ARGS, l);
#line 406
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(455));
#line 406
	if (narg > 1) {
#line 406
		k = va_arg(ARGS,cl_object);
#line 406
	} else {
#line 406
		k = ecl_make_fixnum(1);
#line 406
	}
#line 406
	if (ecl_t_of(k) == t_bignum)
		{
#line 407
			#line 407
			cl_object __value0 = l;
#line 407
			the_env->nvalues = 1;
#line 407
			return __value0;
#line 407
		}

	{
#line 408
		#line 408
		cl_object __value0 = ecl_last(l, ecl_to_size(k));
#line 408
		the_env->nvalues = 1;
#line 408
		return __value0;
#line 408
	}

}

#line 411
cl_object cl_make_list(cl_narg narg, cl_object size, ...)
{
#line 411

	cl_fixnum i;
#line 414
	const cl_env_ptr the_env = ecl_process_env();
#line 414
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1251)};
	cl_object initial_element;
#line 414
	cl_object x;
#line 414
	cl_object KEY_VARS[2];
#line 414
	ecl_va_list ARGS;
	ecl_va_start(ARGS, size, narg, 1);
#line 414
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(529));
#line 414
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 414
	if (KEY_VARS[1]==ECL_NIL) {
#line 414
	  initial_element = ECL_NIL;
	} else {
#line 414
	  initial_element = KEY_VARS[0];
	}
#line 414
	x = ECL_NIL;
#line 414
	/* INV: ecl_to_size() signals a type-error if SIZE is not a integer >=0 */
	i = ecl_to_size(size);
	while (i-- > 0)
		x = CONS(initial_element, x);
	{
#line 418
		#line 418
		cl_object __value0 = x;
#line 418
		the_env->nvalues = 1;
#line 418
		return __value0;
#line 418
	}

}

cl_object
cl_copy_list(cl_object x)
{
	cl_object copy;
	if (ecl_unlikely(!LISTP(x))) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*COPY-LIST*/257), x, ecl_make_fixnum(/*LIST*/481));
	}
	copy = ECL_NIL;
	if (!Null(x)) {
		cl_object tail = copy = ecl_list1(CAR(x));
		while (x = ECL_CONS_CDR(x), CONSP(x)) {
			cl_object cons = ecl_list1(ECL_CONS_CAR(x));
			ECL_RPLACD(tail, cons);
			tail = cons;
		}
		ECL_RPLACD(tail, x);
	}
	{
#line 438
		const cl_env_ptr the_env = ecl_process_env();
#line 438
		#line 438
		cl_object __value0 = copy;
#line 438
		the_env->nvalues = 1;
#line 438
		return __value0;
#line 438
	}
;
}

static cl_object
duplicate_pairs(cl_object x)
{
	cl_object p = ECL_CONS_CAR(x);
	if (CONSP(p))
		p = CONS(ECL_CONS_CAR(p), ECL_CONS_CDR(p));
	return ecl_list1(p);
}

cl_object
cl_copy_alist(cl_object x)
{
	cl_object copy;
	if (ecl_unlikely(!LISTP(x))) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*COPY-ALIST*/256), x, ecl_make_fixnum(/*LIST*/481));
	}
	copy = ECL_NIL;
	if (!Null(x)) {
		cl_object tail = copy = duplicate_pairs(x);
		while (x = ECL_CONS_CDR(x), !Null(x)) {
			if (!LISTP(x)) {
				FEtype_error_list(x);
			} else {
				cl_object cons = duplicate_pairs(x);
				tail = ECL_RPLACD(tail, cons);
				tail = cons;
			}
		}
	}
	{
#line 470
		const cl_env_ptr the_env = ecl_process_env();
#line 470
		#line 470
		cl_object __value0 = copy;
#line 470
		the_env->nvalues = 1;
#line 470
		return __value0;
#line 470
	}
;
}

static cl_object
do_copy_tree(cl_object x)
{
	if (CONSP(x)) {
		x = CONS(do_copy_tree(ECL_CONS_CAR(x)),
			 do_copy_tree(ECL_CONS_CDR(x)));
	}
	return x;
}

cl_object
cl_copy_tree(cl_object x)
{
	{
#line 486
		const cl_env_ptr the_env = ecl_process_env();
#line 486
		#line 486
		cl_object __value0 = do_copy_tree(x);
#line 486
		the_env->nvalues = 1;
#line 486
		return __value0;
#line 486
	}

}

cl_object
cl_revappend(cl_object x, cl_object y)
{
	loop_for_in(x) {
		y = CONS(ECL_CONS_CAR(x),y);
	} end_loop_for_in;
	{
#line 495
		const cl_env_ptr the_env = ecl_process_env();
#line 495
		#line 495
		cl_object __value0 = y;
#line 495
		the_env->nvalues = 1;
#line 495
		return __value0;
#line 495
	}

}

#line 498
cl_object cl_nconc(cl_narg narg, ...)
{
#line 498

	cl_object head = ECL_NIL, tail = ECL_NIL;
#line 500
	const cl_env_ptr the_env = ecl_process_env();
#line 500
	ecl_va_list lists;
	ecl_va_start(lists, narg, narg, 0);
#line 500
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(581));
#line 500

	while (narg--) {
		cl_object new_tail, other = ecl_va_arg(lists);
		if (Null(other)) {
			new_tail = tail;
		} else if (CONSP(other)) {
			new_tail = ecl_last(other, 1);
		} else {
			if (narg) FEtype_error_list(other);
			new_tail = tail;
		}
		if (Null(head)) {
			head = other;
		} else {
			ECL_RPLACD(tail, other);
		}
		tail = new_tail;
	}
	{
#line 518
		#line 518
		cl_object __value0 = head;
#line 518
		the_env->nvalues = 1;
#line 518
		return __value0;
#line 518
	}

}

cl_object
ecl_nconc(cl_object l, cl_object y)
{
	if (Null(l)) {
		return y;
	} else {
		ECL_RPLACD(ecl_last(l, 1), y);
		return l;
	}
}

cl_object
cl_nreconc(cl_object l, cl_object y)
{
	cl_object x, z;
	/* INV: when a circular list is "reconc'ed", the pointer ends
	   up at the beginning of the original list, hence we need no
	   slow pointer */
	for (x = l; !Null(x); ) {
                if (!LISTP(x)) FEtype_error_list(x);
		z = x;
		x = ECL_CONS_CDR(x);
		if (x == l) FEcircular_list(l);
		ECL_RPLACD(z, y);
		y = z;
	}
	{
#line 547
		const cl_env_ptr the_env = ecl_process_env();
#line 547
		#line 547
		cl_object __value0 = y;
#line 547
		the_env->nvalues = 1;
#line 547
		return __value0;
#line 547
	}

}

cl_object
ecl_butlast(cl_object l, cl_index n)
{
	/* See LAST for details on this algorithm */
	cl_object r;
	for (r = l; n && CONSP(r); n--, r = ECL_CONS_CDR(r))
		;
	if (Null(r)) {
		return ECL_NIL;
	} else if (!LISTP(r)) {
		/* We reach here either because l is shorter than n conses,
		 * or because it is not a list */
		if (r == l) FEtype_error_list(r);
		return ECL_NIL;
	} else {
		/* We reach here because l has at least n conses and
		 * thus we can take CAR(l) */
		cl_object head, tail;
		head = tail = ecl_list1(CAR(l));
		while (l = ECL_CONS_CDR(l), r = ECL_CONS_CDR(r), CONSP(r)) {
			cl_object cons = ecl_list1(ECL_CONS_CAR(l));
			ECL_RPLACD(tail, cons);
			tail = cons;
		}
		return head;
	}
}

#line 578
cl_object cl_butlast(cl_narg narg, cl_object lis, ...)
{
#line 578

#line 580
	const cl_env_ptr the_env = ecl_process_env();
#line 580
	cl_object nn;
#line 580
	va_list ARGS;
	va_start(ARGS, lis);
#line 580
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(161));
#line 580
	if (narg > 1) {
#line 580
		nn = va_arg(ARGS,cl_object);
#line 580
	} else {
#line 580
		nn = ecl_make_fixnum(1);
#line 580
	}
#line 580
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 582
			#line 582
			cl_object __value0 = ECL_NIL;
#line 582
			the_env->nvalues = 1;
#line 582
			return __value0;
#line 582
		}
;
	/* INV: ecl_to_size() signals a type-error if NN is not an integer >=0 */
	{
#line 584
		#line 584
		cl_object __value0 = ecl_butlast(lis, ecl_to_size(nn));
#line 584
		the_env->nvalues = 1;
#line 584
		return __value0;
#line 584
	}

}

cl_object
ecl_nbutlast(cl_object l, cl_index n)
{
	cl_object r;
	if (ecl_unlikely(!LISTP(l)))
                FEwrong_type_only_arg(ecl_make_fixnum(/*NBUTLAST*/580), l, ecl_make_fixnum(/*LIST*/481));
	for (n++, r = l; n && CONSP(r); n--, r = ECL_CONS_CDR(r))
		;
	if (n == 0) {
		cl_object tail = l;
		while (CONSP(r)) {
			tail = ECL_CONS_CDR(tail);
			r = ECL_CONS_CDR(r);
		}
		ECL_RPLACD(tail, ECL_NIL);
		return l;
	}
	return ECL_NIL;
}

#line 607
cl_object cl_nbutlast(cl_narg narg, cl_object lis, ...)
{
#line 607

#line 609
	const cl_env_ptr the_env = ecl_process_env();
#line 609
	cl_object nn;
#line 609
	va_list ARGS;
	va_start(ARGS, lis);
#line 609
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(580));
#line 609
	if (narg > 1) {
#line 609
		nn = va_arg(ARGS,cl_object);
#line 609
	} else {
#line 609
		nn = ecl_make_fixnum(1);
#line 609
	}
#line 609
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 611
			#line 611
			cl_object __value0 = ECL_NIL;
#line 611
			the_env->nvalues = 1;
#line 611
			return __value0;
#line 611
		}

	/* INV: ecl_to_size() signas a type-error if NN is not an integer >=0 */
	{
#line 613
		#line 613
		cl_object __value0 = ecl_nbutlast(lis, ecl_to_size(nn));
#line 613
		the_env->nvalues = 1;
#line 613
		return __value0;
#line 613
	}

}

cl_object
cl_ldiff(cl_object x, cl_object y)
{
	cl_object head = ECL_NIL;
	if (ecl_unlikely(!LISTP(x))) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*LDIFF*/459), x, ecl_make_fixnum(/*LIST*/481));
	}
	/* Here we use that, if X or Y are CONS, then (EQL X Y)
	 * only when X == Y */
	if (!Null(x) && (x != y)) {
		cl_object tail = head = ecl_list1(ECL_CONS_CAR(x));
		while (1) {
			x = ECL_CONS_CDR(x);
			if (!CONSP(x)) {
				if (!ecl_eql(x, y)) {
					ECL_RPLACD(tail, x);
				}
				break;
			} else if (x == y) {
				break;
			} else {
				cl_object cons = ecl_list1(ECL_CONS_CAR(x));
				ECL_RPLACD(tail, cons);
				tail = cons;
			}
		}
	}
	{
#line 643
		const cl_env_ptr the_env = ecl_process_env();
#line 643
		#line 643
		cl_object __value0 = head;
#line 643
		the_env->nvalues = 1;
#line 643
		return __value0;
#line 643
	}

}

cl_object
cl_rplaca(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACA*/732), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACA(x, v);
	{
#line 652
		const cl_env_ptr the_env = ecl_process_env();
#line 652
		#line 652
		cl_object __value0 = x;
#line 652
		the_env->nvalues = 1;
#line 652
		return __value0;
#line 652
	}

}

cl_object
cl_rplacd(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACD*/733), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACD(x, v);
	{
#line 661
		const cl_env_ptr the_env = ecl_process_env();
#line 661
		#line 661
		cl_object __value0 = x;
#line 661
		the_env->nvalues = 1;
#line 661
		return __value0;
#line 661
	}

}

#line 664
cl_object cl_subst(cl_narg narg, cl_object new_obj, cl_object old_obj, cl_object tree, ...)
{
#line 664

	struct cl_test t;
	cl_object output;
#line 668
	const cl_env_ptr the_env = ecl_process_env();
#line 668
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 668
	cl_object KEY_VARS[6];
#line 668
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 3);
#line 668
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(831));
#line 668
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 668
	if (KEY_VARS[3]==ECL_NIL) {
#line 668
	  test = ECL_NIL;
	} else {
#line 668
	  test = KEY_VARS[0];
	}
#line 668
	if (KEY_VARS[4]==ECL_NIL) {
#line 668
	  test_not = ECL_NIL;
	} else {
#line 668
	  test_not = KEY_VARS[1];
	}
#line 668
	if (KEY_VARS[5]==ECL_NIL) {
#line 668
	  key = ECL_NIL;
	} else {
#line 668
	  key = KEY_VARS[2];
	}
#line 668
	setup_test(&t, old_obj, test, test_not, key);
	output = subst(&t, new_obj, tree);
	close_test(&t);
	{
#line 671
		#line 671
		cl_object __value0 = output;
#line 671
		the_env->nvalues = 1;
#line 671
		return __value0;
#line 671
	}

}


static cl_object
subst(struct cl_test *t, cl_object new_obj, cl_object tree)
{
	if (TEST(t, tree)) {
		return new_obj;
	} else if (ECL_ATOM(tree)) {
		return tree;
	} else {
		cl_object head, tail = ECL_NIL;
		do {
			cl_object cons = subst(t, new_obj, ECL_CONS_CAR(tree));
			cons = ecl_cons(cons, tree = ECL_CONS_CDR(tree));
			if (Null(tail)) {
				head = cons;
			} else {
				ECL_RPLACD(tail, cons);
			}
			tail = cons;
			if (TEST(t, tree)) {
				ECL_RPLACD(tail, new_obj);
				return head;
			}
		} while (CONSP(tree));
		return head;
	}
}

#line 702
cl_object cl_nsubst(cl_narg narg, cl_object new_obj, cl_object old_obj, cl_object tree, ...)
{
#line 702

	struct cl_test t;
#line 705
	const cl_env_ptr the_env = ecl_process_env();
#line 705
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 705
	cl_object KEY_VARS[6];
#line 705
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 3);
#line 705
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(596));
#line 705
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 705
	if (KEY_VARS[3]==ECL_NIL) {
#line 705
	  test = ECL_NIL;
	} else {
#line 705
	  test = KEY_VARS[0];
	}
#line 705
	if (KEY_VARS[4]==ECL_NIL) {
#line 705
	  test_not = ECL_NIL;
	} else {
#line 705
	  test_not = KEY_VARS[1];
	}
#line 705
	if (KEY_VARS[5]==ECL_NIL) {
#line 705
	  key = ECL_NIL;
	} else {
#line 705
	  key = KEY_VARS[2];
	}
#line 705
	setup_test(&t, old_obj, test, test_not, key);
	tree = nsubst(&t, new_obj, tree);
	close_test(&t);
	{
#line 708
		#line 708
		cl_object __value0 = tree;
#line 708
		the_env->nvalues = 1;
#line 708
		return __value0;
#line 708
	}

}

static cl_object
nsubst_cons(struct cl_test *t, cl_object new_obj, cl_object tree)
{
	cl_object l = tree;
	do {
		cl_object o = ECL_CONS_CAR(l);
		if (TEST(t, o)) {
			ECL_RPLACA(l, new_obj);
		} else if (CONSP(o)) {
			nsubst_cons(t, new_obj, o);
		}
		o = ECL_CONS_CDR(l);
		if (TEST(t, o)) {
			ECL_RPLACD(l, new_obj);
			return tree;
		}
		l = o;
	} while (CONSP(l));
	return tree;
}

static cl_object
nsubst(struct cl_test *t, cl_object new_obj, cl_object tree)
{
	if (TEST(t, tree))
		return new_obj;
	if (CONSP(tree))
		return nsubst_cons(t, new_obj, tree);
	return tree;
}

#line 742
cl_object cl_sublis(cl_narg narg, cl_object alist, cl_object tree, ...)
{
#line 742

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 749
	const cl_env_ptr the_env = ecl_process_env();
#line 749
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 749
	cl_object KEY_VARS[6];
#line 749
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 2);
#line 749
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(828));
#line 749
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 749
	if (KEY_VARS[3]==ECL_NIL) {
#line 749
	  test = ECL_NIL;
	} else {
#line 749
	  test = KEY_VARS[0];
	}
#line 749
	if (KEY_VARS[4]==ECL_NIL) {
#line 749
	  test_not = ECL_NIL;
	} else {
#line 749
	  test_not = KEY_VARS[1];
	}
#line 749
	if (KEY_VARS[5]==ECL_NIL) {
#line 749
	  key = ECL_NIL;
	} else {
#line 749
	  key = KEY_VARS[2];
	}
#line 749
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = sublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 754
		#line 754
		cl_object __value0 = tree;
#line 754
		the_env->nvalues = 1;
#line 754
		return __value0;
#line 754
	}

}

/*
	Sublis(alist, tree) returns
	result of substituting tree by alist.
*/
static cl_object
sublis(struct cl_test *t, cl_object alist, cl_object tree)
{
	cl_object node;
	t[1].item_compared = KEY(t, tree);
	node = do_assoc(t+1, alist);
	if (!Null(node)) {
		return ECL_CONS_CDR(node);
	}
	if (CONSP(tree)) {
		tree = CONS(sublis(t, alist, ECL_CONS_CAR(tree)),
			    sublis(t, alist, ECL_CONS_CDR(tree)));
	}
	return tree;
}

#line 777
cl_object cl_nsublis(cl_narg narg, cl_object alist, cl_object tree, ...)
{
#line 777

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 784
	const cl_env_ptr the_env = ecl_process_env();
#line 784
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 784
	cl_object KEY_VARS[6];
#line 784
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 2);
#line 784
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(595));
#line 784
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 784
	if (KEY_VARS[3]==ECL_NIL) {
#line 784
	  test = ECL_NIL;
	} else {
#line 784
	  test = KEY_VARS[0];
	}
#line 784
	if (KEY_VARS[4]==ECL_NIL) {
#line 784
	  test_not = ECL_NIL;
	} else {
#line 784
	  test_not = KEY_VARS[1];
	}
#line 784
	if (KEY_VARS[5]==ECL_NIL) {
#line 784
	  key = ECL_NIL;
	} else {
#line 784
	  key = KEY_VARS[2];
	}
#line 784
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = nsublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 789
		#line 789
		cl_object __value0 = tree;
#line 789
		the_env->nvalues = 1;
#line 789
		return __value0;
#line 789
	}

}

/*
	Nsublis(alist, treep) stores
	the result of substiting *treep by alist
	to *treep.
*/
static cl_object
nsublis(struct cl_test *t, cl_object alist, cl_object tree)
{
	cl_object node;
	t[1].item_compared = KEY(t, tree);
	node = do_assoc(t+1, alist);
	if (!Null(node)) {
		return ECL_CONS_CDR(node);
	}
	if (CONSP(tree)) {
		ECL_RPLACA(tree, nsublis(t, alist, ECL_CONS_CAR(tree)));
		ECL_RPLACD(tree, nsublis(t, alist, ECL_CONS_CDR(tree)));
	}
	return tree;
}

#line 813
cl_object cl_member(cl_narg narg, cl_object item, cl_object list, ...)
{
#line 813

	struct cl_test t;
#line 816
	const cl_env_ptr the_env = ecl_process_env();
#line 816
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 816
	cl_object KEY_VARS[6];
#line 816
	ecl_va_list ARGS;
	ecl_va_start(ARGS, list, narg, 2);
#line 816
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(552));
#line 816
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 816
	if (KEY_VARS[3]==ECL_NIL) {
#line 816
	  test = ECL_NIL;
	} else {
#line 816
	  test = KEY_VARS[0];
	}
#line 816
	if (KEY_VARS[4]==ECL_NIL) {
#line 816
	  test_not = ECL_NIL;
	} else {
#line 816
	  test_not = KEY_VARS[1];
	}
#line 816
	if (KEY_VARS[5]==ECL_NIL) {
#line 816
	  key = ECL_NIL;
	} else {
#line 816
	  key = KEY_VARS[2];
	}
#line 816
	setup_test(&t, item, test, test_not, key);
	loop_for_in(list) {
		if (TEST(&t, ECL_CONS_CAR(list)))
			break;
	} end_loop_for_in;
	close_test(&t);
	{
#line 822
		#line 822
		cl_object __value0 = list;
#line 822
		the_env->nvalues = 1;
#line 822
		return __value0;
#line 822
	}

}

bool
ecl_member_eq(cl_object x, cl_object l)
{
	loop_for_in(l) {
		if (x == ECL_CONS_CAR(l))
			return(TRUE);
	} end_loop_for_in;
	return(FALSE);
}

cl_object
si_memq(cl_object x, cl_object l)
{
	loop_for_in(l) {
		if (x == ECL_CONS_CAR(l))
			{
#line 840
				const cl_env_ptr the_env = ecl_process_env();
#line 840
				#line 840
				cl_object __value0 = l;
#line 840
				the_env->nvalues = 1;
#line 840
				return __value0;
#line 840
			}

	} end_loop_for_in;
	{
#line 842
		const cl_env_ptr the_env = ecl_process_env();
#line 842
		#line 842
		cl_object __value0 = ECL_NIL;
#line 842
		the_env->nvalues = 1;
#line 842
		return __value0;
#line 842
	}

}

/* Added for use by the compiler, instead of open coding them. Beppe */
cl_object
ecl_memql(cl_object x, cl_object l)
{
	loop_for_in(l) {
		if (ecl_eql(x, ECL_CONS_CAR(l)))
			return(l);
	} end_loop_for_in;
	return(ECL_NIL);
}

cl_object
ecl_member(cl_object x, cl_object l)
{
	loop_for_in(l) {
		if (ecl_equal(x, ECL_CONS_CAR(l)))
			return(l);
	} end_loop_for_in;
	return(ECL_NIL);
}
/* End of addition. Beppe */

cl_object
si_member1(cl_object item, cl_object list, cl_object test, cl_object test_not, cl_object key)
{
	struct cl_test t;

	if (key != ECL_NIL)
		item = funcall(2, key, item);
	setup_test(&t, item, test, test_not, key);
	loop_for_in(list) {
		if (TEST(&t, ECL_CONS_CAR(list)))
			break;
	} end_loop_for_in;
	close_test(&t);
	{
#line 880
		const cl_env_ptr the_env = ecl_process_env();
#line 880
		#line 880
		cl_object __value0 = list;
#line 880
		the_env->nvalues = 1;
#line 880
		return __value0;
#line 880
	}

}

cl_object
cl_tailp(cl_object y, cl_object x)
{
	loop_for_on(x) {
		if (ecl_eql(x, y)) {
#line 887
			const cl_env_ptr the_env = ecl_process_env();
#line 887
			#line 887
			cl_object __value0 = ECL_T;
#line 887
			the_env->nvalues = 1;
#line 887
			return __value0;
#line 887
		}
;
	} end_loop_for_on(x);
	return cl_eql(x, y);
}

#line 892
cl_object cl_adjoin(cl_narg narg, cl_object item, cl_object list, ...)
{
#line 892

	cl_object output;
#line 895
	const cl_env_ptr the_env = ecl_process_env();
#line 895
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 895
	cl_object KEY_VARS[6];
#line 895
	ecl_va_list ARGS;
	ecl_va_start(ARGS, list, narg, 2);
#line 895
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(82));
#line 895
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 895
	if (KEY_VARS[3]==ECL_NIL) {
#line 895
	  test = ECL_NIL;
	} else {
#line 895
	  test = KEY_VARS[0];
	}
#line 895
	if (KEY_VARS[4]==ECL_NIL) {
#line 895
	  test_not = ECL_NIL;
	} else {
#line 895
	  test_not = KEY_VARS[1];
	}
#line 895
	if (KEY_VARS[5]==ECL_NIL) {
#line 895
	  key = ECL_NIL;
	} else {
#line 895
	  key = KEY_VARS[2];
	}
#line 895
	if (narg < 2)
		FEwrong_num_arguments(ecl_make_fixnum(/*ADJOIN*/82));
	output = si_member1(item, list, test, test_not, key);
	if (Null(output))
		output = CONS(item, list);
	else
		output = list;
	{
#line 902
		#line 902
		cl_object __value0 = output;
#line 902
		the_env->nvalues = 1;
#line 902
		return __value0;
#line 902
	}

}

cl_object
cl_cons(cl_object x, cl_object y)
{
	{
#line 908
		const cl_env_ptr the_env = ecl_process_env();
#line 908
		#line 908
		cl_object __value0 = CONS(x, y);
#line 908
		the_env->nvalues = 1;
#line 908
		return __value0;
#line 908
	}

}

cl_object
cl_acons(cl_object x, cl_object y, cl_object z)
{
	{
#line 914
		const cl_env_ptr the_env = ecl_process_env();
#line 914
		#line 914
		cl_object __value0 = CONS(CONS(x, y), z);
#line 914
		the_env->nvalues = 1;
#line 914
		return __value0;
#line 914
	}

}

#line 917
cl_object cl_pairlis(cl_narg narg, cl_object keys, cl_object data, ...)
{
#line 917

	cl_object k, d;
#line 920
	const cl_env_ptr the_env = ecl_process_env();
#line 920
	cl_object a_list;
#line 920
	va_list ARGS;
	va_start(ARGS, data);
#line 920
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(626));
#line 920
	if (narg > 2) {
#line 920
		a_list = va_arg(ARGS,cl_object);
#line 920
	} else {
#line 920
		a_list = ECL_NIL;
#line 920
	}
#line 920
	k = keys;
	d = data;
	loop_for_in(k) {
		if (ecl_endp(d))
			goto error;
		a_list = CONS(CONS(ECL_CONS_CAR(k), ECL_CONS_CAR(d)), a_list);
		d = CDR(d);
	} end_loop_for_in;
	if (!ecl_endp(d))
error:	    FEerror("The keys ~S and the data ~S are not of the same length",
		    2, keys, data);
	{
#line 931
		#line 931
		cl_object __value0 = a_list;
#line 931
		the_env->nvalues = 1;
#line 931
		return __value0;
#line 931
	}

}


#line 935
cl_object cl_assoc(cl_narg narg, cl_object item, cl_object a_list, ...)
{
#line 935

	struct cl_test t;
#line 938
	const cl_env_ptr the_env = ecl_process_env();
#line 938
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 938
	cl_object KEY_VARS[6];
#line 938
	ecl_va_list ARGS;
	ecl_va_start(ARGS, a_list, narg, 2);
#line 938
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(114));
#line 938
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 938
	if (KEY_VARS[3]==ECL_NIL) {
#line 938
	  test = ECL_NIL;
	} else {
#line 938
	  test = KEY_VARS[0];
	}
#line 938
	if (KEY_VARS[4]==ECL_NIL) {
#line 938
	  test_not = ECL_NIL;
	} else {
#line 938
	  test_not = KEY_VARS[1];
	}
#line 938
	if (KEY_VARS[5]==ECL_NIL) {
#line 938
	  key = ECL_NIL;
	} else {
#line 938
	  key = KEY_VARS[2];
	}
#line 938
	setup_test(&t, item, test, test_not, key);
	a_list = do_assoc(&t, a_list);
	close_test(&t);
	{
#line 941
		#line 941
		cl_object __value0 = a_list;
#line 941
		the_env->nvalues = 1;
#line 941
		return __value0;
#line 941
	}

}

static cl_object
do_assoc(struct cl_test *t, cl_object a_list)
{
	loop_for_in(a_list) {
		cl_object pair = ECL_CONS_CAR(a_list);
		if (!Null(pair)) {
			if (!LISTP(pair))
				FEtype_error_list(pair);
			if (TEST(t, ECL_CONS_CAR(pair)))
				return pair;
		}
	} end_loop_for_in;
	return ECL_NIL;
}

#line 959
cl_object cl_rassoc(cl_narg narg, cl_object item, cl_object a_list, ...)
{
#line 959

	struct cl_test t;
#line 962
	const cl_env_ptr the_env = ecl_process_env();
#line 962
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 962
	cl_object KEY_VARS[6];
#line 962
	ecl_va_list ARGS;
	ecl_va_start(ARGS, a_list, narg, 2);
#line 962
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(683));
#line 962
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 962
	if (KEY_VARS[3]==ECL_NIL) {
#line 962
	  test = ECL_NIL;
	} else {
#line 962
	  test = KEY_VARS[0];
	}
#line 962
	if (KEY_VARS[4]==ECL_NIL) {
#line 962
	  test_not = ECL_NIL;
	} else {
#line 962
	  test_not = KEY_VARS[1];
	}
#line 962
	if (KEY_VARS[5]==ECL_NIL) {
#line 962
	  key = ECL_NIL;
	} else {
#line 962
	  key = KEY_VARS[2];
	}
#line 962
	setup_test(&t, item, test, test_not, key);
	loop_for_in(a_list) {
		cl_object pair = ECL_CONS_CAR(a_list);
		if (!Null(pair)) {
			if (!LISTP(pair))
				FEtype_error_list(pair);
			if (TEST(&t, ECL_CONS_CDR(pair))) {
				a_list = pair;
				break;
			}
		}
	} end_loop_for_in;
	close_test(&t);
	{
#line 975
		#line 975
		cl_object __value0 = a_list;
#line 975
		the_env->nvalues = 1;
#line 975
		return __value0;
#line 975
	}

}

cl_object
ecl_remove_eq(cl_object x, cl_object l)
{
	cl_object head = ECL_NIL, tail = ECL_NIL;
	loop_for_on_unsafe(l) {
		if (ECL_CONS_CAR(l) != x) {
			cl_object cons = ecl_list1(ECL_CONS_CAR(l));
			if (Null(tail)) {
				head = tail = cons;
			} else {
				ECL_RPLACD(tail, cons);
				tail = cons;
			}
		}
	} end_loop_for_on_unsafe(l);
	return head;
}

cl_object
ecl_delete_eq(cl_object x, cl_object l)
{
	cl_object head = l;
        cl_object *p = &head;
        while (!ECL_ATOM(l)) {
                if (ECL_CONS_CAR(l) == x) {
                        *p = l = ECL_CONS_CDR(l);
                } else {
                        p = &ECL_CONS_CDR(l);
                        l = *p;
                }
        }
	return head;
}

/* Added for use by the compiler, instead of open coding them. Beppe */
cl_object
ecl_assq(cl_object x, cl_object l)
{
	loop_for_in(l) {
		cl_object pair = ECL_CONS_CAR(l);
		if (x == CAR(pair))
			return pair;
	} end_loop_for_in;
	return(ECL_NIL);
}

cl_object
ecl_assql(cl_object x, cl_object l)
{
	loop_for_in(l) {
		cl_object pair = ECL_CONS_CAR(l);
		if (ecl_eql(x, CAR(pair)))
			return pair;
	} end_loop_for_in;
	return(ECL_NIL);
}

cl_object
ecl_assoc(cl_object x, cl_object l)
{
	loop_for_in(l) {
		cl_object pair = ECL_CONS_CAR(l);
		if (ecl_equal(x, CAR(pair)))
			return pair;
	} end_loop_for_in;
	return(ECL_NIL);
}

cl_object
ecl_assqlp(cl_object x, cl_object l)
{
	loop_for_in(l) {
		cl_object pair = ECL_CONS_CAR(l);
		if (ecl_equalp(x, CAR(pair)))
			return pair;
	} end_loop_for_in;
	return(ECL_NIL);
}
/* End of addition. Beppe */
