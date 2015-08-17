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

typedef cl_object (*t_test_fn)(cl_narg narg, cl_object a, cl_object b);

static bool
test_compare(struct cl_test *t, cl_object x)
{
        nlogd(">>test_compare!!");
	x = KEY(t,x);
	t->env->function = t->test_function;
        // printf("string tag 1st(%d) 2nd(%d)", t->item_compared->string.t, x->string.t);
        return (/*(t_test_fn)*/t->test_fn)(2, t->item_compared, x) != ECL_NIL;
}

static bool
test_compare_not(struct cl_test *t, cl_object x)
{
	x = KEY(t,x);
	t->env->function = t->test_function;
	return (/*(t_test_fn)*/t->test_fn)(2, t->item_compared, x) == ECL_NIL;
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

// ------------------------------1
#line 140
cl_object cl_list(cl_narg narg, ...)
{
#line 140
// ------------------------------2
#line 140
	const cl_env_ptr the_env = ecl_process_env();
#line 140
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 140
// ------------------------------3

	cl_object head = ECL_NIL;
#line 143
// ------------------------------4
#line 143
#line 143
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(481));
#line 143
// ------------------------------5
	if (narg--) {
		cl_object tail = head = ecl_list1(ecl_va_arg(args));
		while (narg--) {
			cl_object cons = ecl_list1(ecl_va_arg(args));
			ECL_RPLACD(tail, cons);
			tail = cons;
		}
	}
	{
#line 151
		#line 151
		cl_object __value0 = head;
#line 151
		the_env->nvalues = 1;
#line 151
		return __value0;
#line 151
	}

}

// ------------------------------1
#line 154
cl_object cl_listX(cl_narg narg, ...)
{
#line 154
// ------------------------------2
#line 154
	const cl_env_ptr the_env = ecl_process_env();
#line 154
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 154
// ------------------------------3

	cl_object head;
#line 157
// ------------------------------4
#line 157
#line 157
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(482));
#line 157
// ------------------------------5
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
#line 169
		#line 169
		cl_object __value0 = head;
#line 169
		the_env->nvalues = 1;
#line 169
		return __value0;
#line 169
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

// ------------------------------1
#line 189
cl_object cl_append(cl_narg narg, ...)
{
#line 189
// ------------------------------2
#line 189
	const cl_env_ptr the_env = ecl_process_env();
#line 189
	ecl_va_list rest;
	ecl_va_start(rest, narg, narg, 0);
#line 189
// ------------------------------3

	cl_object head = ECL_NIL, *tail = &head;
#line 192
// ------------------------------4
#line 192
#line 192
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(88));
#line 192
// ------------------------------5
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
#line 203
		#line 203
		cl_object __value0 = head;
#line 203
		the_env->nvalues = 1;
#line 203
		return __value0;
#line 203
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

// ------------------------------1
#line 259
cl_object cl_tree_equal(cl_narg narg, ...)
{
#line 259
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object x = ecl_va_arg(ARGS);  
	cl_object y = ecl_va_arg(ARGS);  
#line 259
// ------------------------------3

	struct cl_test t;
	cl_object output;
#line 263
// ------------------------------4
#line 263
#line 263
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(863));
#line 263
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 263
	if (KEY_VARS[2]==ECL_NIL) {
#line 263
	  test = ECL_NIL;
	} else {
#line 263
	  test = KEY_VARS[0];
	}
#line 263
	if (KEY_VARS[3]==ECL_NIL) {
#line 263
	  test_not = ECL_NIL;
	} else {
#line 263
	  test_not = KEY_VARS[1];
	}
#line 263
// ------------------------------5
	setup_test(&t, ECL_NIL, test, test_not, ECL_NIL);
	output = tree_equal(&t, x, y)? ECL_T : ECL_NIL;
	close_test(&t);
	{
#line 266
		#line 266
		cl_object __value0 = output;
#line 266
		the_env->nvalues = 1;
#line 266
		return __value0;
#line 266
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
#line 278
	const cl_env_ptr the_env = ecl_process_env();
#line 278
	#line 278
	cl_object __value0 = output;
#line 278
	the_env->nvalues = 1;
#line 278
	return __value0;
#line 278
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
#line 305
				const cl_env_ptr the_env = ecl_process_env();
#line 305
				#line 305
				cl_object __value0 = ECL_NIL;
#line 305
				the_env->nvalues = 1;
#line 305
				return __value0;
#line 305
			}
;
			slow = ECL_CONS_CDR(slow);
		}
	}
	{
#line 309
		const cl_env_ptr the_env = ecl_process_env();
#line 309
		#line 309
		cl_object __value0 = ecl_make_fixnum(n);
#line 309
		the_env->nvalues = 1;
#line 309
		return __value0;
#line 309
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
#line 333
		const cl_env_ptr the_env = ecl_process_env();
#line 333
		#line 333
		cl_object __value0 = test;
#line 333
		the_env->nvalues = 1;
#line 333
		return __value0;
#line 333
	}
;
}

cl_object
cl_nth(cl_object n, cl_object x)
{
	{
#line 339
		const cl_env_ptr the_env = ecl_process_env();
#line 339
		#line 339
		cl_object __value0 = ecl_nth(ecl_to_size(n), x);
#line 339
		the_env->nvalues = 1;
#line 339
		return __value0;
#line 339
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
#line 361
		const cl_env_ptr the_env = ecl_process_env();
#line 361
		#line 361
		cl_object __value0 = ecl_nthcdr(ecl_to_size(n), x);
#line 361
		the_env->nvalues = 1;
#line 361
		return __value0;
#line 361
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

// ------------------------------1
#line 407
cl_object cl_last(cl_narg narg, ...)
{
#line 407
// ------------------------------2
#line 407
	const cl_env_ptr the_env = ecl_process_env();
#line 407
	cl_object k;
#line 407
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object l = va_arg(ARGS,cl_object);  
#line 407
// ------------------------------3

#line 409
// ------------------------------4
#line 409
#line 409
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(455));
#line 409
	if (narg > 1) {
#line 409
		k = va_arg(ARGS,cl_object);  
#line 409
	} else {
#line 409
		k = ecl_make_fixnum(1);
#line 409
	}
#line 409
// ------------------------------5
	if (ecl_t_of(k) == t_bignum)
		{
#line 410
			#line 410
			cl_object __value0 = l;
#line 410
			the_env->nvalues = 1;
#line 410
			return __value0;
#line 410
		}

	{
#line 411
		#line 411
		cl_object __value0 = ecl_last(l, ecl_to_size(k));
#line 411
		the_env->nvalues = 1;
#line 411
		return __value0;
#line 411
	}

}

// ------------------------------1
#line 414
cl_object cl_make_list(cl_narg narg, ...)
{
#line 414
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object size = ecl_va_arg(ARGS);  
#line 414
// ------------------------------3

	cl_fixnum i;
#line 417
// ------------------------------4
#line 417
#line 417
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(529));
#line 417
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 417
	if (KEY_VARS[1]==ECL_NIL) {
#line 417
	  initial_element = ECL_NIL;
	} else {
#line 417
	  initial_element = KEY_VARS[0];
	}
#line 417
	x = ECL_NIL;
#line 417
// ------------------------------5
	/* INV: ecl_to_size() signals a type-error if SIZE is not a integer >=0 */
	i = ecl_to_size(size);
	while (i-- > 0)
		x = CONS(initial_element, x);
	{
#line 421
		#line 421
		cl_object __value0 = x;
#line 421
		the_env->nvalues = 1;
#line 421
		return __value0;
#line 421
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
#line 441
		const cl_env_ptr the_env = ecl_process_env();
#line 441
		#line 441
		cl_object __value0 = copy;
#line 441
		the_env->nvalues = 1;
#line 441
		return __value0;
#line 441
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
#line 473
		const cl_env_ptr the_env = ecl_process_env();
#line 473
		#line 473
		cl_object __value0 = copy;
#line 473
		the_env->nvalues = 1;
#line 473
		return __value0;
#line 473
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
#line 489
		const cl_env_ptr the_env = ecl_process_env();
#line 489
		#line 489
		cl_object __value0 = do_copy_tree(x);
#line 489
		the_env->nvalues = 1;
#line 489
		return __value0;
#line 489
	}

}

cl_object
cl_revappend(cl_object x, cl_object y)
{
	loop_for_in(x) {
		y = CONS(ECL_CONS_CAR(x),y);
	} end_loop_for_in;
	{
#line 498
		const cl_env_ptr the_env = ecl_process_env();
#line 498
		#line 498
		cl_object __value0 = y;
#line 498
		the_env->nvalues = 1;
#line 498
		return __value0;
#line 498
	}

}

// ------------------------------1
#line 501
cl_object cl_nconc(cl_narg narg, ...)
{
#line 501
// ------------------------------2
#line 501
	const cl_env_ptr the_env = ecl_process_env();
#line 501
	ecl_va_list lists;
	ecl_va_start(lists, narg, narg, 0);
#line 501
// ------------------------------3

	cl_object head = ECL_NIL, tail = ECL_NIL;
#line 503
// ------------------------------4
#line 503
#line 503
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(581));
#line 503
// ------------------------------5

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
#line 521
		#line 521
		cl_object __value0 = head;
#line 521
		the_env->nvalues = 1;
#line 521
		return __value0;
#line 521
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
#line 550
		const cl_env_ptr the_env = ecl_process_env();
#line 550
		#line 550
		cl_object __value0 = y;
#line 550
		the_env->nvalues = 1;
#line 550
		return __value0;
#line 550
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

// ------------------------------1
#line 581
cl_object cl_butlast(cl_narg narg, ...)
{
#line 581
// ------------------------------2
#line 581
	const cl_env_ptr the_env = ecl_process_env();
#line 581
	cl_object nn;
#line 581
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object lis = va_arg(ARGS,cl_object);  
#line 581
// ------------------------------3

#line 583
// ------------------------------4
#line 583
#line 583
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(161));
#line 583
	if (narg > 1) {
#line 583
		nn = va_arg(ARGS,cl_object);  
#line 583
	} else {
#line 583
		nn = ecl_make_fixnum(1);
#line 583
	}
#line 583
// ------------------------------5
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 585
			#line 585
			cl_object __value0 = ECL_NIL;
#line 585
			the_env->nvalues = 1;
#line 585
			return __value0;
#line 585
		}
;
	/* INV: ecl_to_size() signals a type-error if NN is not an integer >=0 */
	{
#line 587
		#line 587
		cl_object __value0 = ecl_butlast(lis, ecl_to_size(nn));
#line 587
		the_env->nvalues = 1;
#line 587
		return __value0;
#line 587
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

// ------------------------------1
#line 610
cl_object cl_nbutlast(cl_narg narg, ...)
{
#line 610
// ------------------------------2
#line 610
	const cl_env_ptr the_env = ecl_process_env();
#line 610
	cl_object nn;
#line 610
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object lis = va_arg(ARGS,cl_object);  
#line 610
// ------------------------------3

#line 612
// ------------------------------4
#line 612
#line 612
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(580));
#line 612
	if (narg > 1) {
#line 612
		nn = va_arg(ARGS,cl_object);  
#line 612
	} else {
#line 612
		nn = ecl_make_fixnum(1);
#line 612
	}
#line 612
// ------------------------------5
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 614
			#line 614
			cl_object __value0 = ECL_NIL;
#line 614
			the_env->nvalues = 1;
#line 614
			return __value0;
#line 614
		}

	/* INV: ecl_to_size() signas a type-error if NN is not an integer >=0 */
	{
#line 616
		#line 616
		cl_object __value0 = ecl_nbutlast(lis, ecl_to_size(nn));
#line 616
		the_env->nvalues = 1;
#line 616
		return __value0;
#line 616
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
#line 646
		const cl_env_ptr the_env = ecl_process_env();
#line 646
		#line 646
		cl_object __value0 = head;
#line 646
		the_env->nvalues = 1;
#line 646
		return __value0;
#line 646
	}

}

cl_object
cl_rplaca(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACA*/732), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACA(x, v);
	{
#line 655
		const cl_env_ptr the_env = ecl_process_env();
#line 655
		#line 655
		cl_object __value0 = x;
#line 655
		the_env->nvalues = 1;
#line 655
		return __value0;
#line 655
	}

}

cl_object
cl_rplacd(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACD*/733), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACD(x, v);
	{
#line 664
		const cl_env_ptr the_env = ecl_process_env();
#line 664
		#line 664
		cl_object __value0 = x;
#line 664
		the_env->nvalues = 1;
#line 664
		return __value0;
#line 664
	}

}

// ------------------------------1
#line 667
cl_object cl_subst(cl_narg narg, ...)
{
#line 667
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object new_obj = ecl_va_arg(ARGS);  
	cl_object old_obj = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 667
// ------------------------------3

	struct cl_test t;
	cl_object output;
#line 671
// ------------------------------4
#line 671
#line 671
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(831));
#line 671
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 671
	if (KEY_VARS[3]==ECL_NIL) {
#line 671
	  test = ECL_NIL;
	} else {
#line 671
	  test = KEY_VARS[0];
	}
#line 671
	if (KEY_VARS[4]==ECL_NIL) {
#line 671
	  test_not = ECL_NIL;
	} else {
#line 671
	  test_not = KEY_VARS[1];
	}
#line 671
	if (KEY_VARS[5]==ECL_NIL) {
#line 671
	  key = ECL_NIL;
	} else {
#line 671
	  key = KEY_VARS[2];
	}
#line 671
// ------------------------------5
	setup_test(&t, old_obj, test, test_not, key);
	output = subst(&t, new_obj, tree);
	close_test(&t);
	{
#line 674
		#line 674
		cl_object __value0 = output;
#line 674
		the_env->nvalues = 1;
#line 674
		return __value0;
#line 674
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

// ------------------------------1
#line 705
cl_object cl_nsubst(cl_narg narg, ...)
{
#line 705
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object new_obj = ecl_va_arg(ARGS);  
	cl_object old_obj = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 705
// ------------------------------3

	struct cl_test t;
#line 708
// ------------------------------4
#line 708
#line 708
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(596));
#line 708
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 708
	if (KEY_VARS[3]==ECL_NIL) {
#line 708
	  test = ECL_NIL;
	} else {
#line 708
	  test = KEY_VARS[0];
	}
#line 708
	if (KEY_VARS[4]==ECL_NIL) {
#line 708
	  test_not = ECL_NIL;
	} else {
#line 708
	  test_not = KEY_VARS[1];
	}
#line 708
	if (KEY_VARS[5]==ECL_NIL) {
#line 708
	  key = ECL_NIL;
	} else {
#line 708
	  key = KEY_VARS[2];
	}
#line 708
// ------------------------------5
	setup_test(&t, old_obj, test, test_not, key);
	tree = nsubst(&t, new_obj, tree);
	close_test(&t);
	{
#line 711
		#line 711
		cl_object __value0 = tree;
#line 711
		the_env->nvalues = 1;
#line 711
		return __value0;
#line 711
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

// ------------------------------1
#line 745
cl_object cl_sublis(cl_narg narg, ...)
{
#line 745
// ------------------------------2
#line 745
	const cl_env_ptr the_env = ecl_process_env();
#line 745
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 745
	cl_object KEY_VARS[6];
#line 745
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object alist = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 745
// ------------------------------3

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 752
// ------------------------------4
#line 752
#line 752
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(828));
#line 752
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 752
	if (KEY_VARS[3]==ECL_NIL) {
#line 752
	  test = ECL_NIL;
	} else {
#line 752
	  test = KEY_VARS[0];
	}
#line 752
	if (KEY_VARS[4]==ECL_NIL) {
#line 752
	  test_not = ECL_NIL;
	} else {
#line 752
	  test_not = KEY_VARS[1];
	}
#line 752
	if (KEY_VARS[5]==ECL_NIL) {
#line 752
	  key = ECL_NIL;
	} else {
#line 752
	  key = KEY_VARS[2];
	}
#line 752
// ------------------------------5
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = sublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 757
		#line 757
		cl_object __value0 = tree;
#line 757
		the_env->nvalues = 1;
#line 757
		return __value0;
#line 757
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

// ------------------------------1
#line 780
cl_object cl_nsublis(cl_narg narg, ...)
{
#line 780
// ------------------------------2
#line 780
	const cl_env_ptr the_env = ecl_process_env();
#line 780
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 780
	cl_object KEY_VARS[6];
#line 780
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object alist = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 780
// ------------------------------3

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 787
// ------------------------------4
#line 787
#line 787
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(595));
#line 787
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 787
	if (KEY_VARS[3]==ECL_NIL) {
#line 787
	  test = ECL_NIL;
	} else {
#line 787
	  test = KEY_VARS[0];
	}
#line 787
	if (KEY_VARS[4]==ECL_NIL) {
#line 787
	  test_not = ECL_NIL;
	} else {
#line 787
	  test_not = KEY_VARS[1];
	}
#line 787
	if (KEY_VARS[5]==ECL_NIL) {
#line 787
	  key = ECL_NIL;
	} else {
#line 787
	  key = KEY_VARS[2];
	}
#line 787
// ------------------------------5
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = nsublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 792
		#line 792
		cl_object __value0 = tree;
#line 792
		the_env->nvalues = 1;
#line 792
		return __value0;
#line 792
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

// ------------------------------1
#line 816
cl_object cl_member(cl_narg narg, ...)
{
#line 816
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object list = ecl_va_arg(ARGS);  
#line 816
// ------------------------------3

	struct cl_test t;
#line 819
// ------------------------------4
#line 819
#line 819
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(552));
#line 819
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 819
	if (KEY_VARS[3]==ECL_NIL) {
#line 819
	  test = ECL_NIL;
	} else {
#line 819
	  test = KEY_VARS[0];
	}
#line 819
	if (KEY_VARS[4]==ECL_NIL) {
#line 819
	  test_not = ECL_NIL;
	} else {
#line 819
	  test_not = KEY_VARS[1];
	}
#line 819
	if (KEY_VARS[5]==ECL_NIL) {
#line 819
	  key = ECL_NIL;
	} else {
#line 819
	  key = KEY_VARS[2];
	}
#line 819
// ------------------------------5
	setup_test(&t, item, test, test_not, key);
	loop_for_in(list) {
		if (TEST(&t, ECL_CONS_CAR(list)))
			break;
	} end_loop_for_in;
	close_test(&t);
	{
#line 825
		#line 825
		cl_object __value0 = list;
#line 825
		the_env->nvalues = 1;
#line 825
		return __value0;
#line 825
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
#line 843
				const cl_env_ptr the_env = ecl_process_env();
#line 843
				#line 843
				cl_object __value0 = l;
#line 843
				the_env->nvalues = 1;
#line 843
				return __value0;
#line 843
			}

	} end_loop_for_in;
	{
#line 845
		const cl_env_ptr the_env = ecl_process_env();
#line 845
		#line 845
		cl_object __value0 = ECL_NIL;
#line 845
		the_env->nvalues = 1;
#line 845
		return __value0;
#line 845
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
#line 883
		const cl_env_ptr the_env = ecl_process_env();
#line 883
		#line 883
		cl_object __value0 = list;
#line 883
		the_env->nvalues = 1;
#line 883
		return __value0;
#line 883
	}

}

cl_object
cl_tailp(cl_object y, cl_object x)
{
	loop_for_on(x) {
		if (ecl_eql(x, y)) {
#line 890
			const cl_env_ptr the_env = ecl_process_env();
#line 890
			#line 890
			cl_object __value0 = ECL_T;
#line 890
			the_env->nvalues = 1;
#line 890
			return __value0;
#line 890
		}
;
	} end_loop_for_on(x);
	return cl_eql(x, y);
}

// ------------------------------1
#line 895
cl_object cl_adjoin(cl_narg narg, ...)
{
#line 895
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object list = ecl_va_arg(ARGS);  
#line 895
// ------------------------------3

	cl_object output;
#line 898
// ------------------------------4
#line 898
#line 898
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(82));
#line 898
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 898
	if (KEY_VARS[3]==ECL_NIL) {
#line 898
	  test = ECL_NIL;
	} else {
#line 898
	  test = KEY_VARS[0];
	}
#line 898
	if (KEY_VARS[4]==ECL_NIL) {
#line 898
	  test_not = ECL_NIL;
	} else {
#line 898
	  test_not = KEY_VARS[1];
	}
#line 898
	if (KEY_VARS[5]==ECL_NIL) {
#line 898
	  key = ECL_NIL;
	} else {
#line 898
	  key = KEY_VARS[2];
	}
#line 898
// ------------------------------5
	if (narg < 2)
		FEwrong_num_arguments(ecl_make_fixnum(/*ADJOIN*/82));
	output = si_member1(item, list, test, test_not, key);
	if (Null(output))
		output = CONS(item, list);
	else
		output = list;
	{
#line 905
		#line 905
		cl_object __value0 = output;
#line 905
		the_env->nvalues = 1;
#line 905
		return __value0;
#line 905
	}

}

cl_object
cl_cons(cl_object x, cl_object y)
{
	{
#line 911
		const cl_env_ptr the_env = ecl_process_env();
#line 911
		#line 911
		cl_object __value0 = CONS(x, y);
#line 911
		the_env->nvalues = 1;
#line 911
		return __value0;
#line 911
	}

}

cl_object
cl_acons(cl_object x, cl_object y, cl_object z)
{
	{
#line 917
		const cl_env_ptr the_env = ecl_process_env();
#line 917
		#line 917
		cl_object __value0 = CONS(CONS(x, y), z);
#line 917
		the_env->nvalues = 1;
#line 917
		return __value0;
#line 917
	}

}

// ------------------------------1
#line 920
cl_object cl_pairlis(cl_narg narg, ...)
{
#line 920
// ------------------------------2
#line 920
	const cl_env_ptr the_env = ecl_process_env();
#line 920
	cl_object a_list;
#line 920
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object keys = va_arg(ARGS,cl_object);  
	cl_object data = va_arg(ARGS,cl_object);  
#line 920
// ------------------------------3

	cl_object k, d;
#line 923
// ------------------------------4
#line 923
#line 923
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(626));
#line 923
	if (narg > 2) {
#line 923
		a_list = va_arg(ARGS,cl_object);  
#line 923
	} else {
#line 923
		a_list = ECL_NIL;
#line 923
	}
#line 923
// ------------------------------5
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
#line 934
		#line 934
		cl_object __value0 = a_list;
#line 934
		the_env->nvalues = 1;
#line 934
		return __value0;
#line 934
	}

}


// ------------------------------1
#line 938
cl_object cl_assoc(cl_narg narg, ...)
{
#line 938
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object a_list = ecl_va_arg(ARGS);  
#line 938
// ------------------------------3

	struct cl_test t;
#line 941
// ------------------------------4
#line 941
#line 941
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(114));
#line 941
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 941
	if (KEY_VARS[3]==ECL_NIL) {
#line 941
	  test = ECL_NIL;
	} else {
#line 941
	  test = KEY_VARS[0];
	}
#line 941
	if (KEY_VARS[4]==ECL_NIL) {
#line 941
	  test_not = ECL_NIL;
	} else {
#line 941
	  test_not = KEY_VARS[1];
	}
#line 941
	if (KEY_VARS[5]==ECL_NIL) {
#line 941
	  key = ECL_NIL;
	} else {
#line 941
	  key = KEY_VARS[2];
	}
#line 941
// ------------------------------5
  nlogd("---assoc");
  setup_test(&t, item, test, test_not, key);
  nlogd("---assoc");
  a_list = do_assoc(&t, a_list);
  nlogd("---assoc");
  close_test(&t);
  nlogd("---assoc");
  {
#line 948
	#line 948
	cl_object __value0 = a_list;
#line 948
	the_env->nvalues = 1;
#line 948
	return __value0;
#line 948
}

}

static cl_object
do_assoc(struct cl_test *t, cl_object a_list)
{
        nlogd(">>> do_assoc1");
	loop_for_in(a_list) {
                nlogd(">>> do_assoc2");
		cl_object pair = ECL_CONS_CAR(a_list);
                nlogd(">>> do_assoc3");
		if (!Null(pair)) {
                        nlogd(">>> do_assoc4");
			if (!LISTP(pair)) {
                                nlogd(">>> do_assoc5");
				FEtype_error_list(pair);
                        }
                        // nlogd(">>> do_assoc6");
                        // ECL_CONS_CAR(pair);
                        // nlogd(">>> do_assoc6.1");
                        // void *tmp = ((t)->test_c_function);
                        // nlogd(">>> do_assoc6.1.1");
                        // test_equal(t, ECL_CONS_CAR(pair));
                        // nlogd(">>> do_assoc6.1.2");
                        // // TEST(t, ECL_CONS_CAR(pair));
                        // nlogd(">>> do_assoc6.2");
			if (TEST(t, ECL_CONS_CAR(pair))) {
                        //if (test_equal(t, ECL_CONS_CAR(pair))) { // patch . work tmporaly.
                                nlogd(">>> do_assoc7");
				return pair;
                        }
                        nlogd(">>> do_assoc8");
		}
	} end_loop_for_in;
	return ECL_NIL;
}

// ------------------------------1
#line 985
cl_object cl_rassoc(cl_narg narg, ...)
{
#line 985
// ------------------------------2
#line 985
	const cl_env_ptr the_env = ecl_process_env();
#line 985
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 985
	cl_object KEY_VARS[6];
#line 985
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object a_list = ecl_va_arg(ARGS);  
#line 985
// ------------------------------3

	struct cl_test t;
#line 988
// ------------------------------4
#line 988
#line 988
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(683));
#line 988
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 988
	if (KEY_VARS[3]==ECL_NIL) {
#line 988
	  test = ECL_NIL;
	} else {
#line 988
	  test = KEY_VARS[0];
	}
#line 988
	if (KEY_VARS[4]==ECL_NIL) {
#line 988
	  test_not = ECL_NIL;
	} else {
#line 988
	  test_not = KEY_VARS[1];
	}
#line 988
	if (KEY_VARS[5]==ECL_NIL) {
#line 988
	  key = ECL_NIL;
	} else {
#line 988
	  key = KEY_VARS[2];
	}
#line 988
// ------------------------------5
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
#line 1001
		#line 1001
		cl_object __value0 = a_list;
#line 1001
		the_env->nvalues = 1;
#line 1001
		return __value0;
#line 1001
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
