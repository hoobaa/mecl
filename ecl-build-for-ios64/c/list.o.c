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
	x = KEY(t,x);
	t->env->function = t->test_function;
        // printf("string tag 1st(%d) 2nd(%d)", t->item_compared->string.t, x->string.t);
	return ((t_test_fn)t->test_fn)(2, t->item_compared, x) != ECL_NIL;
}

static bool
test_compare_not(struct cl_test *t, cl_object x)
{
	x = KEY(t,x);
	t->env->function = t->test_function;
	return ((t_test_fn)t->test_fn)(2, t->item_compared, x) == ECL_NIL;
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
#line 139
cl_object cl_list(cl_narg narg, ...)
{
#line 139
// ------------------------------2
#line 139
	const cl_env_ptr the_env = ecl_process_env();
#line 139
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 139
// ------------------------------3

	cl_object head = ECL_NIL;
#line 142
// ------------------------------4
#line 142
#line 142
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(481));
#line 142
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
#line 150
		#line 150
		cl_object __value0 = head;
#line 150
		the_env->nvalues = 1;
#line 150
		return __value0;
#line 150
	}

}

// ------------------------------1
#line 153
cl_object cl_listX(cl_narg narg, ...)
{
#line 153
// ------------------------------2
#line 153
	const cl_env_ptr the_env = ecl_process_env();
#line 153
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 153
// ------------------------------3

	cl_object head;
#line 156
// ------------------------------4
#line 156
#line 156
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(482));
#line 156
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
#line 168
		#line 168
		cl_object __value0 = head;
#line 168
		the_env->nvalues = 1;
#line 168
		return __value0;
#line 168
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
#line 188
cl_object cl_append(cl_narg narg, ...)
{
#line 188
// ------------------------------2
#line 188
	const cl_env_ptr the_env = ecl_process_env();
#line 188
	ecl_va_list rest;
	ecl_va_start(rest, narg, narg, 0);
#line 188
// ------------------------------3

	cl_object head = ECL_NIL, *tail = &head;
#line 191
// ------------------------------4
#line 191
#line 191
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(88));
#line 191
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
#line 202
		#line 202
		cl_object __value0 = head;
#line 202
		the_env->nvalues = 1;
#line 202
		return __value0;
#line 202
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
#line 258
cl_object cl_tree_equal(cl_narg narg, ...)
{
#line 258
// ------------------------------2
#line 258
	const cl_env_ptr the_env = ecl_process_env();
#line 258
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317)};
	cl_object test;
	cl_object test_not;
#line 258
	cl_object KEY_VARS[4];
#line 258
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object x = ecl_va_arg(ARGS);  
	cl_object y = ecl_va_arg(ARGS);  
#line 258
// ------------------------------3

	struct cl_test t;
	cl_object output;
#line 262
// ------------------------------4
#line 262
#line 262
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(863));
#line 262
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 262
	if (KEY_VARS[2]==ECL_NIL) {
#line 262
	  test = ECL_NIL;
	} else {
#line 262
	  test = KEY_VARS[0];
	}
#line 262
	if (KEY_VARS[3]==ECL_NIL) {
#line 262
	  test_not = ECL_NIL;
	} else {
#line 262
	  test_not = KEY_VARS[1];
	}
#line 262
// ------------------------------5
	setup_test(&t, ECL_NIL, test, test_not, ECL_NIL);
	output = tree_equal(&t, x, y)? ECL_T : ECL_NIL;
	close_test(&t);
	{
#line 265
		#line 265
		cl_object __value0 = output;
#line 265
		the_env->nvalues = 1;
#line 265
		return __value0;
#line 265
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
#line 277
	const cl_env_ptr the_env = ecl_process_env();
#line 277
	#line 277
	cl_object __value0 = output;
#line 277
	the_env->nvalues = 1;
#line 277
	return __value0;
#line 277
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
#line 304
				const cl_env_ptr the_env = ecl_process_env();
#line 304
				#line 304
				cl_object __value0 = ECL_NIL;
#line 304
				the_env->nvalues = 1;
#line 304
				return __value0;
#line 304
			}
;
			slow = ECL_CONS_CDR(slow);
		}
	}
	{
#line 308
		const cl_env_ptr the_env = ecl_process_env();
#line 308
		#line 308
		cl_object __value0 = ecl_make_fixnum(n);
#line 308
		the_env->nvalues = 1;
#line 308
		return __value0;
#line 308
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
#line 332
		const cl_env_ptr the_env = ecl_process_env();
#line 332
		#line 332
		cl_object __value0 = test;
#line 332
		the_env->nvalues = 1;
#line 332
		return __value0;
#line 332
	}
;
}

cl_object
cl_nth(cl_object n, cl_object x)
{
	{
#line 338
		const cl_env_ptr the_env = ecl_process_env();
#line 338
		#line 338
		cl_object __value0 = ecl_nth(ecl_to_size(n), x);
#line 338
		the_env->nvalues = 1;
#line 338
		return __value0;
#line 338
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
#line 360
		const cl_env_ptr the_env = ecl_process_env();
#line 360
		#line 360
		cl_object __value0 = ecl_nthcdr(ecl_to_size(n), x);
#line 360
		the_env->nvalues = 1;
#line 360
		return __value0;
#line 360
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
#line 406
cl_object cl_last(cl_narg narg, ...)
{
#line 406
// ------------------------------2
#line 406
	const cl_env_ptr the_env = ecl_process_env();
#line 406
	cl_object k;
#line 406
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object l = va_arg(ARGS,cl_object);  
#line 406
// ------------------------------3

#line 408
// ------------------------------4
#line 408
#line 408
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(455));
#line 408
	if (narg > 1) {
#line 408
		k = va_arg(ARGS,cl_object);  
#line 408
	} else {
#line 408
		k = ecl_make_fixnum(1);
#line 408
	}
#line 408
// ------------------------------5
	if (ecl_t_of(k) == t_bignum)
		{
#line 409
			#line 409
			cl_object __value0 = l;
#line 409
			the_env->nvalues = 1;
#line 409
			return __value0;
#line 409
		}

	{
#line 410
		#line 410
		cl_object __value0 = ecl_last(l, ecl_to_size(k));
#line 410
		the_env->nvalues = 1;
#line 410
		return __value0;
#line 410
	}

}

// ------------------------------1
#line 413
cl_object cl_make_list(cl_narg narg, ...)
{
#line 413
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object size = ecl_va_arg(ARGS);  
#line 413
// ------------------------------3

	cl_fixnum i;
#line 416
// ------------------------------4
#line 416
#line 416
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(529));
#line 416
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 416
	if (KEY_VARS[1]==ECL_NIL) {
#line 416
	  initial_element = ECL_NIL;
	} else {
#line 416
	  initial_element = KEY_VARS[0];
	}
#line 416
	x = ECL_NIL;
#line 416
// ------------------------------5
	/* INV: ecl_to_size() signals a type-error if SIZE is not a integer >=0 */
	i = ecl_to_size(size);
	while (i-- > 0)
		x = CONS(initial_element, x);
	{
#line 420
		#line 420
		cl_object __value0 = x;
#line 420
		the_env->nvalues = 1;
#line 420
		return __value0;
#line 420
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
#line 440
		const cl_env_ptr the_env = ecl_process_env();
#line 440
		#line 440
		cl_object __value0 = copy;
#line 440
		the_env->nvalues = 1;
#line 440
		return __value0;
#line 440
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
#line 472
		const cl_env_ptr the_env = ecl_process_env();
#line 472
		#line 472
		cl_object __value0 = copy;
#line 472
		the_env->nvalues = 1;
#line 472
		return __value0;
#line 472
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
#line 488
		const cl_env_ptr the_env = ecl_process_env();
#line 488
		#line 488
		cl_object __value0 = do_copy_tree(x);
#line 488
		the_env->nvalues = 1;
#line 488
		return __value0;
#line 488
	}

}

cl_object
cl_revappend(cl_object x, cl_object y)
{
	loop_for_in(x) {
		y = CONS(ECL_CONS_CAR(x),y);
	} end_loop_for_in;
	{
#line 497
		const cl_env_ptr the_env = ecl_process_env();
#line 497
		#line 497
		cl_object __value0 = y;
#line 497
		the_env->nvalues = 1;
#line 497
		return __value0;
#line 497
	}

}

// ------------------------------1
#line 500
cl_object cl_nconc(cl_narg narg, ...)
{
#line 500
// ------------------------------2
#line 500
	const cl_env_ptr the_env = ecl_process_env();
#line 500
	ecl_va_list lists;
	ecl_va_start(lists, narg, narg, 0);
#line 500
// ------------------------------3

	cl_object head = ECL_NIL, tail = ECL_NIL;
#line 502
// ------------------------------4
#line 502
#line 502
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(581));
#line 502
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
#line 520
		#line 520
		cl_object __value0 = head;
#line 520
		the_env->nvalues = 1;
#line 520
		return __value0;
#line 520
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
#line 549
		const cl_env_ptr the_env = ecl_process_env();
#line 549
		#line 549
		cl_object __value0 = y;
#line 549
		the_env->nvalues = 1;
#line 549
		return __value0;
#line 549
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
#line 580
cl_object cl_butlast(cl_narg narg, ...)
{
#line 580
// ------------------------------2
#line 580
	const cl_env_ptr the_env = ecl_process_env();
#line 580
	cl_object nn;
#line 580
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object lis = va_arg(ARGS,cl_object);  
#line 580
// ------------------------------3

#line 582
// ------------------------------4
#line 582
#line 582
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(161));
#line 582
	if (narg > 1) {
#line 582
		nn = va_arg(ARGS,cl_object);  
#line 582
	} else {
#line 582
		nn = ecl_make_fixnum(1);
#line 582
	}
#line 582
// ------------------------------5
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 584
			#line 584
			cl_object __value0 = ECL_NIL;
#line 584
			the_env->nvalues = 1;
#line 584
			return __value0;
#line 584
		}
;
	/* INV: ecl_to_size() signals a type-error if NN is not an integer >=0 */
	{
#line 586
		#line 586
		cl_object __value0 = ecl_butlast(lis, ecl_to_size(nn));
#line 586
		the_env->nvalues = 1;
#line 586
		return __value0;
#line 586
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
#line 609
cl_object cl_nbutlast(cl_narg narg, ...)
{
#line 609
// ------------------------------2
#line 609
	const cl_env_ptr the_env = ecl_process_env();
#line 609
	cl_object nn;
#line 609
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object lis = va_arg(ARGS,cl_object);  
#line 609
// ------------------------------3

#line 611
// ------------------------------4
#line 611
#line 611
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(580));
#line 611
	if (narg > 1) {
#line 611
		nn = va_arg(ARGS,cl_object);  
#line 611
	} else {
#line 611
		nn = ecl_make_fixnum(1);
#line 611
	}
#line 611
// ------------------------------5
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 613
			#line 613
			cl_object __value0 = ECL_NIL;
#line 613
			the_env->nvalues = 1;
#line 613
			return __value0;
#line 613
		}

	/* INV: ecl_to_size() signas a type-error if NN is not an integer >=0 */
	{
#line 615
		#line 615
		cl_object __value0 = ecl_nbutlast(lis, ecl_to_size(nn));
#line 615
		the_env->nvalues = 1;
#line 615
		return __value0;
#line 615
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
#line 645
		const cl_env_ptr the_env = ecl_process_env();
#line 645
		#line 645
		cl_object __value0 = head;
#line 645
		the_env->nvalues = 1;
#line 645
		return __value0;
#line 645
	}

}

cl_object
cl_rplaca(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACA*/732), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACA(x, v);
	{
#line 654
		const cl_env_ptr the_env = ecl_process_env();
#line 654
		#line 654
		cl_object __value0 = x;
#line 654
		the_env->nvalues = 1;
#line 654
		return __value0;
#line 654
	}

}

cl_object
cl_rplacd(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACD*/733), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACD(x, v);
	{
#line 663
		const cl_env_ptr the_env = ecl_process_env();
#line 663
		#line 663
		cl_object __value0 = x;
#line 663
		the_env->nvalues = 1;
#line 663
		return __value0;
#line 663
	}

}

// ------------------------------1
#line 666
cl_object cl_subst(cl_narg narg, ...)
{
#line 666
// ------------------------------2
#line 666
	const cl_env_ptr the_env = ecl_process_env();
#line 666
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 666
	cl_object KEY_VARS[6];
#line 666
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object new_obj = ecl_va_arg(ARGS);  
	cl_object old_obj = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 666
// ------------------------------3

	struct cl_test t;
	cl_object output;
#line 670
// ------------------------------4
#line 670
#line 670
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(831));
#line 670
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 670
	if (KEY_VARS[3]==ECL_NIL) {
#line 670
	  test = ECL_NIL;
	} else {
#line 670
	  test = KEY_VARS[0];
	}
#line 670
	if (KEY_VARS[4]==ECL_NIL) {
#line 670
	  test_not = ECL_NIL;
	} else {
#line 670
	  test_not = KEY_VARS[1];
	}
#line 670
	if (KEY_VARS[5]==ECL_NIL) {
#line 670
	  key = ECL_NIL;
	} else {
#line 670
	  key = KEY_VARS[2];
	}
#line 670
// ------------------------------5
	setup_test(&t, old_obj, test, test_not, key);
	output = subst(&t, new_obj, tree);
	close_test(&t);
	{
#line 673
		#line 673
		cl_object __value0 = output;
#line 673
		the_env->nvalues = 1;
#line 673
		return __value0;
#line 673
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
#line 704
cl_object cl_nsubst(cl_narg narg, ...)
{
#line 704
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object new_obj = ecl_va_arg(ARGS);  
	cl_object old_obj = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 704
// ------------------------------3

	struct cl_test t;
#line 707
// ------------------------------4
#line 707
#line 707
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(596));
#line 707
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 707
	if (KEY_VARS[3]==ECL_NIL) {
#line 707
	  test = ECL_NIL;
	} else {
#line 707
	  test = KEY_VARS[0];
	}
#line 707
	if (KEY_VARS[4]==ECL_NIL) {
#line 707
	  test_not = ECL_NIL;
	} else {
#line 707
	  test_not = KEY_VARS[1];
	}
#line 707
	if (KEY_VARS[5]==ECL_NIL) {
#line 707
	  key = ECL_NIL;
	} else {
#line 707
	  key = KEY_VARS[2];
	}
#line 707
// ------------------------------5
	setup_test(&t, old_obj, test, test_not, key);
	tree = nsubst(&t, new_obj, tree);
	close_test(&t);
	{
#line 710
		#line 710
		cl_object __value0 = tree;
#line 710
		the_env->nvalues = 1;
#line 710
		return __value0;
#line 710
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
#line 744
cl_object cl_sublis(cl_narg narg, ...)
{
#line 744
// ------------------------------2
#line 744
	const cl_env_ptr the_env = ecl_process_env();
#line 744
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 744
	cl_object KEY_VARS[6];
#line 744
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object alist = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 744
// ------------------------------3

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 751
// ------------------------------4
#line 751
#line 751
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(828));
#line 751
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 751
	if (KEY_VARS[3]==ECL_NIL) {
#line 751
	  test = ECL_NIL;
	} else {
#line 751
	  test = KEY_VARS[0];
	}
#line 751
	if (KEY_VARS[4]==ECL_NIL) {
#line 751
	  test_not = ECL_NIL;
	} else {
#line 751
	  test_not = KEY_VARS[1];
	}
#line 751
	if (KEY_VARS[5]==ECL_NIL) {
#line 751
	  key = ECL_NIL;
	} else {
#line 751
	  key = KEY_VARS[2];
	}
#line 751
// ------------------------------5
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = sublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 756
		#line 756
		cl_object __value0 = tree;
#line 756
		the_env->nvalues = 1;
#line 756
		return __value0;
#line 756
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
#line 779
cl_object cl_nsublis(cl_narg narg, ...)
{
#line 779
// ------------------------------2
#line 779
	const cl_env_ptr the_env = ecl_process_env();
#line 779
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 779
	cl_object KEY_VARS[6];
#line 779
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object alist = ecl_va_arg(ARGS);  
	cl_object tree = ecl_va_arg(ARGS);  
#line 779
// ------------------------------3

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 786
// ------------------------------4
#line 786
#line 786
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(595));
#line 786
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 786
	if (KEY_VARS[3]==ECL_NIL) {
#line 786
	  test = ECL_NIL;
	} else {
#line 786
	  test = KEY_VARS[0];
	}
#line 786
	if (KEY_VARS[4]==ECL_NIL) {
#line 786
	  test_not = ECL_NIL;
	} else {
#line 786
	  test_not = KEY_VARS[1];
	}
#line 786
	if (KEY_VARS[5]==ECL_NIL) {
#line 786
	  key = ECL_NIL;
	} else {
#line 786
	  key = KEY_VARS[2];
	}
#line 786
// ------------------------------5
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = nsublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 791
		#line 791
		cl_object __value0 = tree;
#line 791
		the_env->nvalues = 1;
#line 791
		return __value0;
#line 791
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
#line 815
cl_object cl_member(cl_narg narg, ...)
{
#line 815
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object list = ecl_va_arg(ARGS);  
#line 815
// ------------------------------3

	struct cl_test t;
#line 818
// ------------------------------4
#line 818
#line 818
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(552));
#line 818
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 818
	if (KEY_VARS[3]==ECL_NIL) {
#line 818
	  test = ECL_NIL;
	} else {
#line 818
	  test = KEY_VARS[0];
	}
#line 818
	if (KEY_VARS[4]==ECL_NIL) {
#line 818
	  test_not = ECL_NIL;
	} else {
#line 818
	  test_not = KEY_VARS[1];
	}
#line 818
	if (KEY_VARS[5]==ECL_NIL) {
#line 818
	  key = ECL_NIL;
	} else {
#line 818
	  key = KEY_VARS[2];
	}
#line 818
// ------------------------------5
	setup_test(&t, item, test, test_not, key);
	loop_for_in(list) {
		if (TEST(&t, ECL_CONS_CAR(list)))
			break;
	} end_loop_for_in;
	close_test(&t);
	{
#line 824
		#line 824
		cl_object __value0 = list;
#line 824
		the_env->nvalues = 1;
#line 824
		return __value0;
#line 824
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
#line 842
				const cl_env_ptr the_env = ecl_process_env();
#line 842
				#line 842
				cl_object __value0 = l;
#line 842
				the_env->nvalues = 1;
#line 842
				return __value0;
#line 842
			}

	} end_loop_for_in;
	{
#line 844
		const cl_env_ptr the_env = ecl_process_env();
#line 844
		#line 844
		cl_object __value0 = ECL_NIL;
#line 844
		the_env->nvalues = 1;
#line 844
		return __value0;
#line 844
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
#line 882
		const cl_env_ptr the_env = ecl_process_env();
#line 882
		#line 882
		cl_object __value0 = list;
#line 882
		the_env->nvalues = 1;
#line 882
		return __value0;
#line 882
	}

}

cl_object
cl_tailp(cl_object y, cl_object x)
{
	loop_for_on(x) {
		if (ecl_eql(x, y)) {
#line 889
			const cl_env_ptr the_env = ecl_process_env();
#line 889
			#line 889
			cl_object __value0 = ECL_T;
#line 889
			the_env->nvalues = 1;
#line 889
			return __value0;
#line 889
		}
;
	} end_loop_for_on(x);
	return cl_eql(x, y);
}

// ------------------------------1
#line 894
cl_object cl_adjoin(cl_narg narg, ...)
{
#line 894
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object list = ecl_va_arg(ARGS);  
#line 894
// ------------------------------3

	cl_object output;
#line 897
// ------------------------------4
#line 897
#line 897
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(82));
#line 897
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 897
	if (KEY_VARS[3]==ECL_NIL) {
#line 897
	  test = ECL_NIL;
	} else {
#line 897
	  test = KEY_VARS[0];
	}
#line 897
	if (KEY_VARS[4]==ECL_NIL) {
#line 897
	  test_not = ECL_NIL;
	} else {
#line 897
	  test_not = KEY_VARS[1];
	}
#line 897
	if (KEY_VARS[5]==ECL_NIL) {
#line 897
	  key = ECL_NIL;
	} else {
#line 897
	  key = KEY_VARS[2];
	}
#line 897
// ------------------------------5
	if (narg < 2)
		FEwrong_num_arguments(ecl_make_fixnum(/*ADJOIN*/82));
	output = si_member1(item, list, test, test_not, key);
	if (Null(output))
		output = CONS(item, list);
	else
		output = list;
	{
#line 904
		#line 904
		cl_object __value0 = output;
#line 904
		the_env->nvalues = 1;
#line 904
		return __value0;
#line 904
	}

}

cl_object
cl_cons(cl_object x, cl_object y)
{
	{
#line 910
		const cl_env_ptr the_env = ecl_process_env();
#line 910
		#line 910
		cl_object __value0 = CONS(x, y);
#line 910
		the_env->nvalues = 1;
#line 910
		return __value0;
#line 910
	}

}

cl_object
cl_acons(cl_object x, cl_object y, cl_object z)
{
	{
#line 916
		const cl_env_ptr the_env = ecl_process_env();
#line 916
		#line 916
		cl_object __value0 = CONS(CONS(x, y), z);
#line 916
		the_env->nvalues = 1;
#line 916
		return __value0;
#line 916
	}

}

// ------------------------------1
#line 919
cl_object cl_pairlis(cl_narg narg, ...)
{
#line 919
// ------------------------------2
#line 919
	const cl_env_ptr the_env = ecl_process_env();
#line 919
	cl_object a_list;
#line 919
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object keys = va_arg(ARGS,cl_object);  
	cl_object data = va_arg(ARGS,cl_object);  
#line 919
// ------------------------------3

	cl_object k, d;
#line 922
// ------------------------------4
#line 922
#line 922
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(626));
#line 922
	if (narg > 2) {
#line 922
		a_list = va_arg(ARGS,cl_object);  
#line 922
	} else {
#line 922
		a_list = ECL_NIL;
#line 922
	}
#line 922
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
#line 933
		#line 933
		cl_object __value0 = a_list;
#line 933
		the_env->nvalues = 1;
#line 933
		return __value0;
#line 933
	}

}


// ------------------------------1
#line 937
cl_object cl_assoc(cl_narg narg, ...)
{
#line 937
// ------------------------------2
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
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object a_list = ecl_va_arg(ARGS);  
#line 937
// ------------------------------3

	struct cl_test t;
#line 940
// ------------------------------4
#line 940
#line 940
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(114));
#line 940
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 940
	if (KEY_VARS[3]==ECL_NIL) {
#line 940
	  test = ECL_NIL;
	} else {
#line 940
	  test = KEY_VARS[0];
	}
#line 940
	if (KEY_VARS[4]==ECL_NIL) {
#line 940
	  test_not = ECL_NIL;
	} else {
#line 940
	  test_not = KEY_VARS[1];
	}
#line 940
	if (KEY_VARS[5]==ECL_NIL) {
#line 940
	  key = ECL_NIL;
	} else {
#line 940
	  key = KEY_VARS[2];
	}
#line 940
// ------------------------------5
  nlogd("---assoc");
  setup_test(&t, item, test, test_not, key);
  nlogd("---assoc");
  a_list = do_assoc(&t, a_list);
  nlogd("---assoc");
  close_test(&t);
  nlogd("---assoc");
  {
#line 947
	#line 947
	cl_object __value0 = a_list;
#line 947
	the_env->nvalues = 1;
#line 947
	return __value0;
#line 947
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
                        nlogd(">>> do_assoc6");
                        ECL_CONS_CAR(pair);
                        nlogd(">>> do_assoc6.1");
                        void *tmp = ((t)->test_c_function);
                        nlogd(">>> do_assoc6.1.1");
                        test_equal(t, ECL_CONS_CAR(pair));
                        nlogd(">>> do_assoc6.1.2");
                        // TEST(t, ECL_CONS_CAR(pair));
                        nlogd(">>> do_assoc6.2");
			//if (TEST(t, ECL_CONS_CAR(pair))) {
                        if (test_equal(t, ECL_CONS_CAR(pair))) {
                                nlogd(">>> do_assoc7");
				return pair;
                        }
                        nlogd(">>> do_assoc8");
		}
	} end_loop_for_in;
	return ECL_NIL;
}

// ------------------------------1
#line 984
cl_object cl_rassoc(cl_narg narg, ...)
{
#line 984
// ------------------------------2
#line 984
	const cl_env_ptr the_env = ecl_process_env();
#line 984
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 984
	cl_object KEY_VARS[6];
#line 984
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object item = ecl_va_arg(ARGS);  
	cl_object a_list = ecl_va_arg(ARGS);  
#line 984
// ------------------------------3

	struct cl_test t;
#line 987
// ------------------------------4
#line 987
#line 987
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(683));
#line 987
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 987
	if (KEY_VARS[3]==ECL_NIL) {
#line 987
	  test = ECL_NIL;
	} else {
#line 987
	  test = KEY_VARS[0];
	}
#line 987
	if (KEY_VARS[4]==ECL_NIL) {
#line 987
	  test_not = ECL_NIL;
	} else {
#line 987
	  test_not = KEY_VARS[1];
	}
#line 987
	if (KEY_VARS[5]==ECL_NIL) {
#line 987
	  key = ECL_NIL;
	} else {
#line 987
	  key = KEY_VARS[2];
	}
#line 987
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
#line 1000
		#line 1000
		cl_object __value0 = a_list;
#line 1000
		the_env->nvalues = 1;
#line 1000
		return __value0;
#line 1000
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
