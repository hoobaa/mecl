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

#line 136
cl_object cl_list(cl_narg narg, ...)
{
#line 136

	cl_object head = ECL_NIL;
#line 139
	const cl_env_ptr the_env = ecl_process_env();
#line 139
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 139
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(481));
#line 139
	if (narg--) {
		cl_object tail = head = ecl_list1(ecl_va_arg(args));
		while (narg--) {
			cl_object cons = ecl_list1(ecl_va_arg(args));
			ECL_RPLACD(tail, cons);
			tail = cons;
		}
	}
	{
#line 147
		#line 147
		cl_object __value0 = head;
#line 147
		the_env->nvalues = 1;
#line 147
		return __value0;
#line 147
	}

}

#line 150
cl_object cl_listX(cl_narg narg, ...)
{
#line 150

	cl_object head;
#line 153
	const cl_env_ptr the_env = ecl_process_env();
#line 153
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 153
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(482));
#line 153
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
#line 165
		#line 165
		cl_object __value0 = head;
#line 165
		the_env->nvalues = 1;
#line 165
		return __value0;
#line 165
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

#line 185
cl_object cl_append(cl_narg narg, ...)
{
#line 185

	cl_object head = ECL_NIL, *tail = &head;
#line 188
	const cl_env_ptr the_env = ecl_process_env();
#line 188
	ecl_va_list rest;
	ecl_va_start(rest, narg, narg, 0);
#line 188
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(88));
#line 188
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
#line 199
		#line 199
		cl_object __value0 = head;
#line 199
		the_env->nvalues = 1;
#line 199
		return __value0;
#line 199
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

#line 255
cl_object cl_tree_equal(cl_narg narg, cl_object x, cl_object y, ...)
{
#line 255

	struct cl_test t;
	cl_object output;
#line 259
	const cl_env_ptr the_env = ecl_process_env();
#line 259
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317)};
	cl_object test;
	cl_object test_not;
#line 259
	cl_object KEY_VARS[4];
#line 259
	ecl_va_list ARGS;
	ecl_va_start(ARGS, y, narg, 2);
#line 259
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(863));
#line 259
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 259
	if (KEY_VARS[2]==ECL_NIL) {
#line 259
	  test = ECL_NIL;
	} else {
#line 259
	  test = KEY_VARS[0];
	}
#line 259
	if (KEY_VARS[3]==ECL_NIL) {
#line 259
	  test_not = ECL_NIL;
	} else {
#line 259
	  test_not = KEY_VARS[1];
	}
#line 259
	setup_test(&t, ECL_NIL, test, test_not, ECL_NIL);
	output = tree_equal(&t, x, y)? ECL_T : ECL_NIL;
	close_test(&t);
	{
#line 262
		#line 262
		cl_object __value0 = output;
#line 262
		the_env->nvalues = 1;
#line 262
		return __value0;
#line 262
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
#line 274
	const cl_env_ptr the_env = ecl_process_env();
#line 274
	#line 274
	cl_object __value0 = output;
#line 274
	the_env->nvalues = 1;
#line 274
	return __value0;
#line 274
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
#line 301
				const cl_env_ptr the_env = ecl_process_env();
#line 301
				#line 301
				cl_object __value0 = ECL_NIL;
#line 301
				the_env->nvalues = 1;
#line 301
				return __value0;
#line 301
			}
;
			slow = ECL_CONS_CDR(slow);
		}
	}
	{
#line 305
		const cl_env_ptr the_env = ecl_process_env();
#line 305
		#line 305
		cl_object __value0 = ecl_make_fixnum(n);
#line 305
		the_env->nvalues = 1;
#line 305
		return __value0;
#line 305
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
#line 329
		const cl_env_ptr the_env = ecl_process_env();
#line 329
		#line 329
		cl_object __value0 = test;
#line 329
		the_env->nvalues = 1;
#line 329
		return __value0;
#line 329
	}
;
}

cl_object
cl_nth(cl_object n, cl_object x)
{
	{
#line 335
		const cl_env_ptr the_env = ecl_process_env();
#line 335
		#line 335
		cl_object __value0 = ecl_nth(ecl_to_size(n), x);
#line 335
		the_env->nvalues = 1;
#line 335
		return __value0;
#line 335
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
#line 357
		const cl_env_ptr the_env = ecl_process_env();
#line 357
		#line 357
		cl_object __value0 = ecl_nthcdr(ecl_to_size(n), x);
#line 357
		the_env->nvalues = 1;
#line 357
		return __value0;
#line 357
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

#line 403
cl_object cl_last(cl_narg narg, cl_object l, ...)
{
#line 403

#line 405
	const cl_env_ptr the_env = ecl_process_env();
#line 405
	cl_object k;
#line 405
	va_list ARGS;
	va_start(ARGS, l);
#line 405
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(455));
#line 405
	if (narg > 1) {
#line 405
		k = va_arg(ARGS,cl_object);
#line 405
	} else {
#line 405
		k = ecl_make_fixnum(1);
#line 405
	}
#line 405
	if (ecl_t_of(k) == t_bignum)
		{
#line 406
			#line 406
			cl_object __value0 = l;
#line 406
			the_env->nvalues = 1;
#line 406
			return __value0;
#line 406
		}

	{
#line 407
		#line 407
		cl_object __value0 = ecl_last(l, ecl_to_size(k));
#line 407
		the_env->nvalues = 1;
#line 407
		return __value0;
#line 407
	}

}

#line 410
cl_object cl_make_list(cl_narg narg, cl_object size, ...)
{
#line 410

	cl_fixnum i;
#line 413
	const cl_env_ptr the_env = ecl_process_env();
#line 413
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1251)};
	cl_object initial_element;
#line 413
	cl_object x;
#line 413
	cl_object KEY_VARS[2];
#line 413
	ecl_va_list ARGS;
	ecl_va_start(ARGS, size, narg, 1);
#line 413
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(529));
#line 413
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 413
	if (KEY_VARS[1]==ECL_NIL) {
#line 413
	  initial_element = ECL_NIL;
	} else {
#line 413
	  initial_element = KEY_VARS[0];
	}
#line 413
	x = ECL_NIL;
#line 413
	/* INV: ecl_to_size() signals a type-error if SIZE is not a integer >=0 */
	i = ecl_to_size(size);
	while (i-- > 0)
		x = CONS(initial_element, x);
	{
#line 417
		#line 417
		cl_object __value0 = x;
#line 417
		the_env->nvalues = 1;
#line 417
		return __value0;
#line 417
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
#line 437
		const cl_env_ptr the_env = ecl_process_env();
#line 437
		#line 437
		cl_object __value0 = copy;
#line 437
		the_env->nvalues = 1;
#line 437
		return __value0;
#line 437
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
#line 469
		const cl_env_ptr the_env = ecl_process_env();
#line 469
		#line 469
		cl_object __value0 = copy;
#line 469
		the_env->nvalues = 1;
#line 469
		return __value0;
#line 469
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
#line 485
		const cl_env_ptr the_env = ecl_process_env();
#line 485
		#line 485
		cl_object __value0 = do_copy_tree(x);
#line 485
		the_env->nvalues = 1;
#line 485
		return __value0;
#line 485
	}

}

cl_object
cl_revappend(cl_object x, cl_object y)
{
	loop_for_in(x) {
		y = CONS(ECL_CONS_CAR(x),y);
	} end_loop_for_in;
	{
#line 494
		const cl_env_ptr the_env = ecl_process_env();
#line 494
		#line 494
		cl_object __value0 = y;
#line 494
		the_env->nvalues = 1;
#line 494
		return __value0;
#line 494
	}

}

#line 497
cl_object cl_nconc(cl_narg narg, ...)
{
#line 497

	cl_object head = ECL_NIL, tail = ECL_NIL;
#line 499
	const cl_env_ptr the_env = ecl_process_env();
#line 499
	ecl_va_list lists;
	ecl_va_start(lists, narg, narg, 0);
#line 499
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(581));
#line 499

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
#line 517
		#line 517
		cl_object __value0 = head;
#line 517
		the_env->nvalues = 1;
#line 517
		return __value0;
#line 517
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
#line 546
		const cl_env_ptr the_env = ecl_process_env();
#line 546
		#line 546
		cl_object __value0 = y;
#line 546
		the_env->nvalues = 1;
#line 546
		return __value0;
#line 546
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

#line 577
cl_object cl_butlast(cl_narg narg, cl_object lis, ...)
{
#line 577

#line 579
	const cl_env_ptr the_env = ecl_process_env();
#line 579
	cl_object nn;
#line 579
	va_list ARGS;
	va_start(ARGS, lis);
#line 579
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(161));
#line 579
	if (narg > 1) {
#line 579
		nn = va_arg(ARGS,cl_object);
#line 579
	} else {
#line 579
		nn = ecl_make_fixnum(1);
#line 579
	}
#line 579
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 581
			#line 581
			cl_object __value0 = ECL_NIL;
#line 581
			the_env->nvalues = 1;
#line 581
			return __value0;
#line 581
		}
;
	/* INV: ecl_to_size() signals a type-error if NN is not an integer >=0 */
	{
#line 583
		#line 583
		cl_object __value0 = ecl_butlast(lis, ecl_to_size(nn));
#line 583
		the_env->nvalues = 1;
#line 583
		return __value0;
#line 583
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

#line 606
cl_object cl_nbutlast(cl_narg narg, cl_object lis, ...)
{
#line 606

#line 608
	const cl_env_ptr the_env = ecl_process_env();
#line 608
	cl_object nn;
#line 608
	va_list ARGS;
	va_start(ARGS, lis);
#line 608
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(580));
#line 608
	if (narg > 1) {
#line 608
		nn = va_arg(ARGS,cl_object);
#line 608
	} else {
#line 608
		nn = ecl_make_fixnum(1);
#line 608
	}
#line 608
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 610
			#line 610
			cl_object __value0 = ECL_NIL;
#line 610
			the_env->nvalues = 1;
#line 610
			return __value0;
#line 610
		}

	/* INV: ecl_to_size() signas a type-error if NN is not an integer >=0 */
	{
#line 612
		#line 612
		cl_object __value0 = ecl_nbutlast(lis, ecl_to_size(nn));
#line 612
		the_env->nvalues = 1;
#line 612
		return __value0;
#line 612
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
#line 642
		const cl_env_ptr the_env = ecl_process_env();
#line 642
		#line 642
		cl_object __value0 = head;
#line 642
		the_env->nvalues = 1;
#line 642
		return __value0;
#line 642
	}

}

cl_object
cl_rplaca(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACA*/732), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACA(x, v);
	{
#line 651
		const cl_env_ptr the_env = ecl_process_env();
#line 651
		#line 651
		cl_object __value0 = x;
#line 651
		the_env->nvalues = 1;
#line 651
		return __value0;
#line 651
	}

}

cl_object
cl_rplacd(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACD*/733), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACD(x, v);
	{
#line 660
		const cl_env_ptr the_env = ecl_process_env();
#line 660
		#line 660
		cl_object __value0 = x;
#line 660
		the_env->nvalues = 1;
#line 660
		return __value0;
#line 660
	}

}

#line 663
cl_object cl_subst(cl_narg narg, cl_object new_obj, cl_object old_obj, cl_object tree, ...)
{
#line 663

	struct cl_test t;
	cl_object output;
#line 667
	const cl_env_ptr the_env = ecl_process_env();
#line 667
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 667
	cl_object KEY_VARS[6];
#line 667
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 3);
#line 667
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(831));
#line 667
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 667
	if (KEY_VARS[3]==ECL_NIL) {
#line 667
	  test = ECL_NIL;
	} else {
#line 667
	  test = KEY_VARS[0];
	}
#line 667
	if (KEY_VARS[4]==ECL_NIL) {
#line 667
	  test_not = ECL_NIL;
	} else {
#line 667
	  test_not = KEY_VARS[1];
	}
#line 667
	if (KEY_VARS[5]==ECL_NIL) {
#line 667
	  key = ECL_NIL;
	} else {
#line 667
	  key = KEY_VARS[2];
	}
#line 667
	setup_test(&t, old_obj, test, test_not, key);
	output = subst(&t, new_obj, tree);
	close_test(&t);
	{
#line 670
		#line 670
		cl_object __value0 = output;
#line 670
		the_env->nvalues = 1;
#line 670
		return __value0;
#line 670
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

#line 701
cl_object cl_nsubst(cl_narg narg, cl_object new_obj, cl_object old_obj, cl_object tree, ...)
{
#line 701

	struct cl_test t;
#line 704
	const cl_env_ptr the_env = ecl_process_env();
#line 704
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 704
	cl_object KEY_VARS[6];
#line 704
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 3);
#line 704
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(596));
#line 704
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 704
	if (KEY_VARS[3]==ECL_NIL) {
#line 704
	  test = ECL_NIL;
	} else {
#line 704
	  test = KEY_VARS[0];
	}
#line 704
	if (KEY_VARS[4]==ECL_NIL) {
#line 704
	  test_not = ECL_NIL;
	} else {
#line 704
	  test_not = KEY_VARS[1];
	}
#line 704
	if (KEY_VARS[5]==ECL_NIL) {
#line 704
	  key = ECL_NIL;
	} else {
#line 704
	  key = KEY_VARS[2];
	}
#line 704
	setup_test(&t, old_obj, test, test_not, key);
	tree = nsubst(&t, new_obj, tree);
	close_test(&t);
	{
#line 707
		#line 707
		cl_object __value0 = tree;
#line 707
		the_env->nvalues = 1;
#line 707
		return __value0;
#line 707
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

#line 741
cl_object cl_sublis(cl_narg narg, cl_object alist, cl_object tree, ...)
{
#line 741

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 748
	const cl_env_ptr the_env = ecl_process_env();
#line 748
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 748
	cl_object KEY_VARS[6];
#line 748
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 2);
#line 748
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(828));
#line 748
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 748
	if (KEY_VARS[3]==ECL_NIL) {
#line 748
	  test = ECL_NIL;
	} else {
#line 748
	  test = KEY_VARS[0];
	}
#line 748
	if (KEY_VARS[4]==ECL_NIL) {
#line 748
	  test_not = ECL_NIL;
	} else {
#line 748
	  test_not = KEY_VARS[1];
	}
#line 748
	if (KEY_VARS[5]==ECL_NIL) {
#line 748
	  key = ECL_NIL;
	} else {
#line 748
	  key = KEY_VARS[2];
	}
#line 748
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = sublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 753
		#line 753
		cl_object __value0 = tree;
#line 753
		the_env->nvalues = 1;
#line 753
		return __value0;
#line 753
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

#line 776
cl_object cl_nsublis(cl_narg narg, cl_object alist, cl_object tree, ...)
{
#line 776

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 783
	const cl_env_ptr the_env = ecl_process_env();
#line 783
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 783
	cl_object KEY_VARS[6];
#line 783
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 2);
#line 783
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(595));
#line 783
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 783
	if (KEY_VARS[3]==ECL_NIL) {
#line 783
	  test = ECL_NIL;
	} else {
#line 783
	  test = KEY_VARS[0];
	}
#line 783
	if (KEY_VARS[4]==ECL_NIL) {
#line 783
	  test_not = ECL_NIL;
	} else {
#line 783
	  test_not = KEY_VARS[1];
	}
#line 783
	if (KEY_VARS[5]==ECL_NIL) {
#line 783
	  key = ECL_NIL;
	} else {
#line 783
	  key = KEY_VARS[2];
	}
#line 783
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = nsublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 788
		#line 788
		cl_object __value0 = tree;
#line 788
		the_env->nvalues = 1;
#line 788
		return __value0;
#line 788
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

#line 812
cl_object cl_member(cl_narg narg, cl_object item, cl_object list, ...)
{
#line 812

	struct cl_test t;
#line 815
	const cl_env_ptr the_env = ecl_process_env();
#line 815
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 815
	cl_object KEY_VARS[6];
#line 815
	ecl_va_list ARGS;
	ecl_va_start(ARGS, list, narg, 2);
#line 815
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(552));
#line 815
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 815
	if (KEY_VARS[3]==ECL_NIL) {
#line 815
	  test = ECL_NIL;
	} else {
#line 815
	  test = KEY_VARS[0];
	}
#line 815
	if (KEY_VARS[4]==ECL_NIL) {
#line 815
	  test_not = ECL_NIL;
	} else {
#line 815
	  test_not = KEY_VARS[1];
	}
#line 815
	if (KEY_VARS[5]==ECL_NIL) {
#line 815
	  key = ECL_NIL;
	} else {
#line 815
	  key = KEY_VARS[2];
	}
#line 815
	setup_test(&t, item, test, test_not, key);
	loop_for_in(list) {
		if (TEST(&t, ECL_CONS_CAR(list)))
			break;
	} end_loop_for_in;
	close_test(&t);
	{
#line 821
		#line 821
		cl_object __value0 = list;
#line 821
		the_env->nvalues = 1;
#line 821
		return __value0;
#line 821
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
#line 839
				const cl_env_ptr the_env = ecl_process_env();
#line 839
				#line 839
				cl_object __value0 = l;
#line 839
				the_env->nvalues = 1;
#line 839
				return __value0;
#line 839
			}

	} end_loop_for_in;
	{
#line 841
		const cl_env_ptr the_env = ecl_process_env();
#line 841
		#line 841
		cl_object __value0 = ECL_NIL;
#line 841
		the_env->nvalues = 1;
#line 841
		return __value0;
#line 841
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
#line 879
		const cl_env_ptr the_env = ecl_process_env();
#line 879
		#line 879
		cl_object __value0 = list;
#line 879
		the_env->nvalues = 1;
#line 879
		return __value0;
#line 879
	}

}

cl_object
cl_tailp(cl_object y, cl_object x)
{
	loop_for_on(x) {
		if (ecl_eql(x, y)) {
#line 886
			const cl_env_ptr the_env = ecl_process_env();
#line 886
			#line 886
			cl_object __value0 = ECL_T;
#line 886
			the_env->nvalues = 1;
#line 886
			return __value0;
#line 886
		}
;
	} end_loop_for_on(x);
	return cl_eql(x, y);
}

#line 891
cl_object cl_adjoin(cl_narg narg, cl_object item, cl_object list, ...)
{
#line 891

	cl_object output;
#line 894
	const cl_env_ptr the_env = ecl_process_env();
#line 894
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 894
	cl_object KEY_VARS[6];
#line 894
	ecl_va_list ARGS;
	ecl_va_start(ARGS, list, narg, 2);
#line 894
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(82));
#line 894
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 894
	if (KEY_VARS[3]==ECL_NIL) {
#line 894
	  test = ECL_NIL;
	} else {
#line 894
	  test = KEY_VARS[0];
	}
#line 894
	if (KEY_VARS[4]==ECL_NIL) {
#line 894
	  test_not = ECL_NIL;
	} else {
#line 894
	  test_not = KEY_VARS[1];
	}
#line 894
	if (KEY_VARS[5]==ECL_NIL) {
#line 894
	  key = ECL_NIL;
	} else {
#line 894
	  key = KEY_VARS[2];
	}
#line 894
	if (narg < 2)
		FEwrong_num_arguments(ecl_make_fixnum(/*ADJOIN*/82));
	output = si_member1(item, list, test, test_not, key);
	if (Null(output))
		output = CONS(item, list);
	else
		output = list;
	{
#line 901
		#line 901
		cl_object __value0 = output;
#line 901
		the_env->nvalues = 1;
#line 901
		return __value0;
#line 901
	}

}

cl_object
cl_cons(cl_object x, cl_object y)
{
	{
#line 907
		const cl_env_ptr the_env = ecl_process_env();
#line 907
		#line 907
		cl_object __value0 = CONS(x, y);
#line 907
		the_env->nvalues = 1;
#line 907
		return __value0;
#line 907
	}

}

cl_object
cl_acons(cl_object x, cl_object y, cl_object z)
{
	{
#line 913
		const cl_env_ptr the_env = ecl_process_env();
#line 913
		#line 913
		cl_object __value0 = CONS(CONS(x, y), z);
#line 913
		the_env->nvalues = 1;
#line 913
		return __value0;
#line 913
	}

}

#line 916
cl_object cl_pairlis(cl_narg narg, cl_object keys, cl_object data, ...)
{
#line 916

	cl_object k, d;
#line 919
	const cl_env_ptr the_env = ecl_process_env();
#line 919
	cl_object a_list;
#line 919
	va_list ARGS;
	va_start(ARGS, data);
#line 919
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(626));
#line 919
	if (narg > 2) {
#line 919
		a_list = va_arg(ARGS,cl_object);
#line 919
	} else {
#line 919
		a_list = ECL_NIL;
#line 919
	}
#line 919
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
#line 930
		#line 930
		cl_object __value0 = a_list;
#line 930
		the_env->nvalues = 1;
#line 930
		return __value0;
#line 930
	}

}


#line 934
cl_object cl_assoc(cl_narg narg, cl_object item, cl_object a_list, ...)
{
#line 934

	struct cl_test t;
#line 937
	const cl_env_ptr the_env = ecl_process_env();
#line 937
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 937
	cl_object KEY_VARS[6];
#line 937
	ecl_va_list ARGS;
	ecl_va_start(ARGS, a_list, narg, 2);
#line 937
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(114));
#line 937
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 937
	if (KEY_VARS[3]==ECL_NIL) {
#line 937
	  test = ECL_NIL;
	} else {
#line 937
	  test = KEY_VARS[0];
	}
#line 937
	if (KEY_VARS[4]==ECL_NIL) {
#line 937
	  test_not = ECL_NIL;
	} else {
#line 937
	  test_not = KEY_VARS[1];
	}
#line 937
	if (KEY_VARS[5]==ECL_NIL) {
#line 937
	  key = ECL_NIL;
	} else {
#line 937
	  key = KEY_VARS[2];
	}
#line 937
	setup_test(&t, item, test, test_not, key);
	a_list = do_assoc(&t, a_list);
	close_test(&t);
	{
#line 940
		#line 940
		cl_object __value0 = a_list;
#line 940
		the_env->nvalues = 1;
#line 940
		return __value0;
#line 940
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

#line 958
cl_object cl_rassoc(cl_narg narg, cl_object item, cl_object a_list, ...)
{
#line 958

	struct cl_test t;
#line 961
	const cl_env_ptr the_env = ecl_process_env();
#line 961
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 961
	cl_object KEY_VARS[6];
#line 961
	ecl_va_list ARGS;
	ecl_va_start(ARGS, a_list, narg, 2);
#line 961
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(683));
#line 961
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 961
	if (KEY_VARS[3]==ECL_NIL) {
#line 961
	  test = ECL_NIL;
	} else {
#line 961
	  test = KEY_VARS[0];
	}
#line 961
	if (KEY_VARS[4]==ECL_NIL) {
#line 961
	  test_not = ECL_NIL;
	} else {
#line 961
	  test_not = KEY_VARS[1];
	}
#line 961
	if (KEY_VARS[5]==ECL_NIL) {
#line 961
	  key = ECL_NIL;
	} else {
#line 961
	  key = KEY_VARS[2];
	}
#line 961
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
#line 974
		#line 974
		cl_object __value0 = a_list;
#line 974
		the_env->nvalues = 1;
#line 974
		return __value0;
#line 974
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
