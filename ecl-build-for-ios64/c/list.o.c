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


extern void test_at_string(cl_object string1, cl_object string2);
extern void test3_at_string(cl_narg narg, cl_object string1, cl_object string2);
extern void test5_at_string(int a, int b);

static void test_at_list(cl_object string1, cl_object string2) {
        printf("sizeof fixnum(%d) long(%d) pointer(%d)\n", sizeof(cl_narg), sizeof(long), sizeof(cl_object));
        printf(">>>>FUCKFUCK-at-list:%d:%d\n", string1->string.t, string2->string.t);
}
static void test3_at_list(cl_narg narg, cl_object string1, cl_object string2) {
        printf(">>>>FUCKFUCK-at-list:%d:%d:%d\n", narg, string1->string.t, string2->string.t);
}
static void test5_at_list(int a, int b) {
        printf("order-at-list:%d:%d\n", a, b);
}

typedef cl_object (*t_fuckfn)(cl_narg narg, cl_object a, cl_object b);
typedef cl_object (*t_fuckfn2)(cl_narg narg, cl_object string1, cl_object string2, ...);
typedef cl_object (*t_fuckfn3)(cl_narg narg, ...);

static bool
test_compare(struct cl_test *t, cl_object x)
{
	x = KEY(t,x);
	t->env->function = t->test_function;
        
        printf("string tag 1st(%d) 2nd(%d)\n", t->item_compared->string.t, x->string.t);
        test5_at_list(1, 10);
        test5_at_string(1, 10);
        
        test_at_list(t->item_compared, x);
        test_at_string(t->item_compared, x);
        test3_at_list(1, t->item_compared, x);
        printf(">>FUCK-CANCER-FROM\n");
        test3_at_string(1, t->item_compared, x);
        printf(">>FUCK-CANCER-TO\n");
        cl_string_equal(2, t->item_compared, x);
        printf(">>FUCK-CANCER-TO2\n");
        printf(">>!!!!FUCK-test_fn(%ld) cl_string_equal(%ld)\n", t->test_fn, &cl_string_equal);
        ((t_fuckfn)(t->test_fn))(2, t->item_compared, x);
        printf(">>FUCK-CANCER-TO4\n");
        // t_fuckfn3 fuckfn = &cl_string_equal;
        // printf(">>FUCK-CANCER-TO3\n");
        // fuckfn(2, t->item_compared, x);
        // printf(">>FUCK-CANCER-TO4\n");
        
	return ((t_fuckfn)(t->test_fn))(2, t->item_compared, x) != ECL_NIL;
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

#line 177
cl_object cl_list(cl_narg narg, ...)
{
#line 177

	cl_object head = ECL_NIL;
#line 180
	const cl_env_ptr the_env = ecl_process_env();
#line 180
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 180
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(481));
#line 180
	if (narg--) {
		cl_object tail = head = ecl_list1(ecl_va_arg(args));
		while (narg--) {
			cl_object cons = ecl_list1(ecl_va_arg(args));
			ECL_RPLACD(tail, cons);
			tail = cons;
		}
	}
	{
#line 188
		#line 188
		cl_object __value0 = head;
#line 188
		the_env->nvalues = 1;
#line 188
		return __value0;
#line 188
	}

}

#line 191
cl_object cl_listX(cl_narg narg, ...)
{
#line 191

	cl_object head;
#line 194
	const cl_env_ptr the_env = ecl_process_env();
#line 194
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 194
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(482));
#line 194
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
#line 206
		#line 206
		cl_object __value0 = head;
#line 206
		the_env->nvalues = 1;
#line 206
		return __value0;
#line 206
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

#line 226
cl_object cl_append(cl_narg narg, ...)
{
#line 226

	cl_object head = ECL_NIL, *tail = &head;
#line 229
	const cl_env_ptr the_env = ecl_process_env();
#line 229
	ecl_va_list rest;
	ecl_va_start(rest, narg, narg, 0);
#line 229
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(88));
#line 229
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
#line 240
		#line 240
		cl_object __value0 = head;
#line 240
		the_env->nvalues = 1;
#line 240
		return __value0;
#line 240
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

#line 296
cl_object cl_tree_equal(cl_narg narg, cl_object x, cl_object y, ...)
{
#line 296

	struct cl_test t;
	cl_object output;
#line 300
	const cl_env_ptr the_env = ecl_process_env();
#line 300
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317)};
	cl_object test;
	cl_object test_not;
#line 300
	cl_object KEY_VARS[4];
#line 300
	ecl_va_list ARGS;
	ecl_va_start(ARGS, y, narg, 2);
#line 300
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(863));
#line 300
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 300
	if (KEY_VARS[2]==ECL_NIL) {
#line 300
	  test = ECL_NIL;
	} else {
#line 300
	  test = KEY_VARS[0];
	}
#line 300
	if (KEY_VARS[3]==ECL_NIL) {
#line 300
	  test_not = ECL_NIL;
	} else {
#line 300
	  test_not = KEY_VARS[1];
	}
#line 300
	setup_test(&t, ECL_NIL, test, test_not, ECL_NIL);
	output = tree_equal(&t, x, y)? ECL_T : ECL_NIL;
	close_test(&t);
	{
#line 303
		#line 303
		cl_object __value0 = output;
#line 303
		the_env->nvalues = 1;
#line 303
		return __value0;
#line 303
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
#line 315
	const cl_env_ptr the_env = ecl_process_env();
#line 315
	#line 315
	cl_object __value0 = output;
#line 315
	the_env->nvalues = 1;
#line 315
	return __value0;
#line 315
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
#line 342
				const cl_env_ptr the_env = ecl_process_env();
#line 342
				#line 342
				cl_object __value0 = ECL_NIL;
#line 342
				the_env->nvalues = 1;
#line 342
				return __value0;
#line 342
			}
;
			slow = ECL_CONS_CDR(slow);
		}
	}
	{
#line 346
		const cl_env_ptr the_env = ecl_process_env();
#line 346
		#line 346
		cl_object __value0 = ecl_make_fixnum(n);
#line 346
		the_env->nvalues = 1;
#line 346
		return __value0;
#line 346
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
#line 370
		const cl_env_ptr the_env = ecl_process_env();
#line 370
		#line 370
		cl_object __value0 = test;
#line 370
		the_env->nvalues = 1;
#line 370
		return __value0;
#line 370
	}
;
}

cl_object
cl_nth(cl_object n, cl_object x)
{
	{
#line 376
		const cl_env_ptr the_env = ecl_process_env();
#line 376
		#line 376
		cl_object __value0 = ecl_nth(ecl_to_size(n), x);
#line 376
		the_env->nvalues = 1;
#line 376
		return __value0;
#line 376
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
#line 398
		const cl_env_ptr the_env = ecl_process_env();
#line 398
		#line 398
		cl_object __value0 = ecl_nthcdr(ecl_to_size(n), x);
#line 398
		the_env->nvalues = 1;
#line 398
		return __value0;
#line 398
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

#line 444
cl_object cl_last(cl_narg narg, cl_object l, ...)
{
#line 444

#line 446
	const cl_env_ptr the_env = ecl_process_env();
#line 446
	cl_object k;
#line 446
	va_list ARGS;
	va_start(ARGS, l);
#line 446
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(455));
#line 446
	if (narg > 1) {
#line 446
		k = va_arg(ARGS,cl_object);
#line 446
	} else {
#line 446
		k = ecl_make_fixnum(1);
#line 446
	}
#line 446
	if (ecl_t_of(k) == t_bignum)
		{
#line 447
			#line 447
			cl_object __value0 = l;
#line 447
			the_env->nvalues = 1;
#line 447
			return __value0;
#line 447
		}

	{
#line 448
		#line 448
		cl_object __value0 = ecl_last(l, ecl_to_size(k));
#line 448
		the_env->nvalues = 1;
#line 448
		return __value0;
#line 448
	}

}

#line 451
cl_object cl_make_list(cl_narg narg, cl_object size, ...)
{
#line 451

	cl_fixnum i;
#line 454
	const cl_env_ptr the_env = ecl_process_env();
#line 454
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1251)};
	cl_object initial_element;
#line 454
	cl_object x;
#line 454
	cl_object KEY_VARS[2];
#line 454
	ecl_va_list ARGS;
	ecl_va_start(ARGS, size, narg, 1);
#line 454
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(529));
#line 454
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 454
	if (KEY_VARS[1]==ECL_NIL) {
#line 454
	  initial_element = ECL_NIL;
	} else {
#line 454
	  initial_element = KEY_VARS[0];
	}
#line 454
	x = ECL_NIL;
#line 454
	/* INV: ecl_to_size() signals a type-error if SIZE is not a integer >=0 */
	i = ecl_to_size(size);
	while (i-- > 0)
		x = CONS(initial_element, x);
	{
#line 458
		#line 458
		cl_object __value0 = x;
#line 458
		the_env->nvalues = 1;
#line 458
		return __value0;
#line 458
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
#line 478
		const cl_env_ptr the_env = ecl_process_env();
#line 478
		#line 478
		cl_object __value0 = copy;
#line 478
		the_env->nvalues = 1;
#line 478
		return __value0;
#line 478
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
#line 510
		const cl_env_ptr the_env = ecl_process_env();
#line 510
		#line 510
		cl_object __value0 = copy;
#line 510
		the_env->nvalues = 1;
#line 510
		return __value0;
#line 510
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
#line 526
		const cl_env_ptr the_env = ecl_process_env();
#line 526
		#line 526
		cl_object __value0 = do_copy_tree(x);
#line 526
		the_env->nvalues = 1;
#line 526
		return __value0;
#line 526
	}

}

cl_object
cl_revappend(cl_object x, cl_object y)
{
	loop_for_in(x) {
		y = CONS(ECL_CONS_CAR(x),y);
	} end_loop_for_in;
	{
#line 535
		const cl_env_ptr the_env = ecl_process_env();
#line 535
		#line 535
		cl_object __value0 = y;
#line 535
		the_env->nvalues = 1;
#line 535
		return __value0;
#line 535
	}

}

#line 538
cl_object cl_nconc(cl_narg narg, ...)
{
#line 538

	cl_object head = ECL_NIL, tail = ECL_NIL;
#line 540
	const cl_env_ptr the_env = ecl_process_env();
#line 540
	ecl_va_list lists;
	ecl_va_start(lists, narg, narg, 0);
#line 540
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(581));
#line 540

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
#line 558
		#line 558
		cl_object __value0 = head;
#line 558
		the_env->nvalues = 1;
#line 558
		return __value0;
#line 558
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
#line 587
		const cl_env_ptr the_env = ecl_process_env();
#line 587
		#line 587
		cl_object __value0 = y;
#line 587
		the_env->nvalues = 1;
#line 587
		return __value0;
#line 587
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

#line 618
cl_object cl_butlast(cl_narg narg, cl_object lis, ...)
{
#line 618

#line 620
	const cl_env_ptr the_env = ecl_process_env();
#line 620
	cl_object nn;
#line 620
	va_list ARGS;
	va_start(ARGS, lis);
#line 620
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(161));
#line 620
	if (narg > 1) {
#line 620
		nn = va_arg(ARGS,cl_object);
#line 620
	} else {
#line 620
		nn = ecl_make_fixnum(1);
#line 620
	}
#line 620
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 622
			#line 622
			cl_object __value0 = ECL_NIL;
#line 622
			the_env->nvalues = 1;
#line 622
			return __value0;
#line 622
		}
;
	/* INV: ecl_to_size() signals a type-error if NN is not an integer >=0 */
	{
#line 624
		#line 624
		cl_object __value0 = ecl_butlast(lis, ecl_to_size(nn));
#line 624
		the_env->nvalues = 1;
#line 624
		return __value0;
#line 624
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

#line 647
cl_object cl_nbutlast(cl_narg narg, cl_object lis, ...)
{
#line 647

#line 649
	const cl_env_ptr the_env = ecl_process_env();
#line 649
	cl_object nn;
#line 649
	va_list ARGS;
	va_start(ARGS, lis);
#line 649
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(580));
#line 649
	if (narg > 1) {
#line 649
		nn = va_arg(ARGS,cl_object);
#line 649
	} else {
#line 649
		nn = ecl_make_fixnum(1);
#line 649
	}
#line 649
	/* INV: No list has more than MOST_POSITIVE_FIXNUM elements */
	if (ecl_t_of(nn) == t_bignum)
		{
#line 651
			#line 651
			cl_object __value0 = ECL_NIL;
#line 651
			the_env->nvalues = 1;
#line 651
			return __value0;
#line 651
		}

	/* INV: ecl_to_size() signas a type-error if NN is not an integer >=0 */
	{
#line 653
		#line 653
		cl_object __value0 = ecl_nbutlast(lis, ecl_to_size(nn));
#line 653
		the_env->nvalues = 1;
#line 653
		return __value0;
#line 653
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
#line 683
		const cl_env_ptr the_env = ecl_process_env();
#line 683
		#line 683
		cl_object __value0 = head;
#line 683
		the_env->nvalues = 1;
#line 683
		return __value0;
#line 683
	}

}

cl_object
cl_rplaca(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACA*/732), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACA(x, v);
	{
#line 692
		const cl_env_ptr the_env = ecl_process_env();
#line 692
		#line 692
		cl_object __value0 = x;
#line 692
		the_env->nvalues = 1;
#line 692
		return __value0;
#line 692
	}

}

cl_object
cl_rplacd(cl_object x, cl_object v)
{
        if (ecl_unlikely(!CONSP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*RPLACD*/733), 1, x, ecl_make_fixnum(/*CONS*/251));
	ECL_RPLACD(x, v);
	{
#line 701
		const cl_env_ptr the_env = ecl_process_env();
#line 701
		#line 701
		cl_object __value0 = x;
#line 701
		the_env->nvalues = 1;
#line 701
		return __value0;
#line 701
	}

}

#line 704
cl_object cl_subst(cl_narg narg, cl_object new_obj, cl_object old_obj, cl_object tree, ...)
{
#line 704

	struct cl_test t;
	cl_object output;
#line 708
	const cl_env_ptr the_env = ecl_process_env();
#line 708
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 708
	cl_object KEY_VARS[6];
#line 708
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 3);
#line 708
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(831));
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
	setup_test(&t, old_obj, test, test_not, key);
	output = subst(&t, new_obj, tree);
	close_test(&t);
	{
#line 711
		#line 711
		cl_object __value0 = output;
#line 711
		the_env->nvalues = 1;
#line 711
		return __value0;
#line 711
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

#line 742
cl_object cl_nsubst(cl_narg narg, cl_object new_obj, cl_object old_obj, cl_object tree, ...)
{
#line 742

	struct cl_test t;
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
	ecl_va_start(ARGS, tree, narg, 3);
#line 745
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(596));
#line 745
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 745
	if (KEY_VARS[3]==ECL_NIL) {
#line 745
	  test = ECL_NIL;
	} else {
#line 745
	  test = KEY_VARS[0];
	}
#line 745
	if (KEY_VARS[4]==ECL_NIL) {
#line 745
	  test_not = ECL_NIL;
	} else {
#line 745
	  test_not = KEY_VARS[1];
	}
#line 745
	if (KEY_VARS[5]==ECL_NIL) {
#line 745
	  key = ECL_NIL;
	} else {
#line 745
	  key = KEY_VARS[2];
	}
#line 745
	setup_test(&t, old_obj, test, test_not, key);
	tree = nsubst(&t, new_obj, tree);
	close_test(&t);
	{
#line 748
		#line 748
		cl_object __value0 = tree;
#line 748
		the_env->nvalues = 1;
#line 748
		return __value0;
#line 748
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

#line 782
cl_object cl_sublis(cl_narg narg, cl_object alist, cl_object tree, ...)
{
#line 782

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 789
	const cl_env_ptr the_env = ecl_process_env();
#line 789
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 789
	cl_object KEY_VARS[6];
#line 789
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 2);
#line 789
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(828));
#line 789
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 789
	if (KEY_VARS[3]==ECL_NIL) {
#line 789
	  test = ECL_NIL;
	} else {
#line 789
	  test = KEY_VARS[0];
	}
#line 789
	if (KEY_VARS[4]==ECL_NIL) {
#line 789
	  test_not = ECL_NIL;
	} else {
#line 789
	  test_not = KEY_VARS[1];
	}
#line 789
	if (KEY_VARS[5]==ECL_NIL) {
#line 789
	  key = ECL_NIL;
	} else {
#line 789
	  key = KEY_VARS[2];
	}
#line 789
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = sublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 794
		#line 794
		cl_object __value0 = tree;
#line 794
		the_env->nvalues = 1;
#line 794
		return __value0;
#line 794
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

#line 817
cl_object cl_nsublis(cl_narg narg, cl_object alist, cl_object tree, ...)
{
#line 817

	/* t[0] is the test for the objects in the tree, configured
	   with test, test_not and key. t[1] is the test for searching
	   in the association list.
	 */
	struct cl_test t[2];
#line 824
	const cl_env_ptr the_env = ecl_process_env();
#line 824
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 824
	cl_object KEY_VARS[6];
#line 824
	ecl_va_list ARGS;
	ecl_va_start(ARGS, tree, narg, 2);
#line 824
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(595));
#line 824
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 824
	if (KEY_VARS[3]==ECL_NIL) {
#line 824
	  test = ECL_NIL;
	} else {
#line 824
	  test = KEY_VARS[0];
	}
#line 824
	if (KEY_VARS[4]==ECL_NIL) {
#line 824
	  test_not = ECL_NIL;
	} else {
#line 824
	  test_not = KEY_VARS[1];
	}
#line 824
	if (KEY_VARS[5]==ECL_NIL) {
#line 824
	  key = ECL_NIL;
	} else {
#line 824
	  key = KEY_VARS[2];
	}
#line 824
	setup_test(t, ECL_NIL, ECL_NIL, ECL_NIL, key);
	setup_test(t+1, ECL_NIL, test, test_not, ECL_NIL);
	tree = nsublis(t, alist, tree);
	close_test(t+1);
	close_test(t);
	{
#line 829
		#line 829
		cl_object __value0 = tree;
#line 829
		the_env->nvalues = 1;
#line 829
		return __value0;
#line 829
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

#line 853
cl_object cl_member(cl_narg narg, cl_object item, cl_object list, ...)
{
#line 853

	struct cl_test t;
#line 856
	const cl_env_ptr the_env = ecl_process_env();
#line 856
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 856
	cl_object KEY_VARS[6];
#line 856
	ecl_va_list ARGS;
	ecl_va_start(ARGS, list, narg, 2);
#line 856
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(552));
#line 856
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 856
	if (KEY_VARS[3]==ECL_NIL) {
#line 856
	  test = ECL_NIL;
	} else {
#line 856
	  test = KEY_VARS[0];
	}
#line 856
	if (KEY_VARS[4]==ECL_NIL) {
#line 856
	  test_not = ECL_NIL;
	} else {
#line 856
	  test_not = KEY_VARS[1];
	}
#line 856
	if (KEY_VARS[5]==ECL_NIL) {
#line 856
	  key = ECL_NIL;
	} else {
#line 856
	  key = KEY_VARS[2];
	}
#line 856
	setup_test(&t, item, test, test_not, key);
	loop_for_in(list) {
		if (TEST(&t, ECL_CONS_CAR(list)))
			break;
	} end_loop_for_in;
	close_test(&t);
	{
#line 862
		#line 862
		cl_object __value0 = list;
#line 862
		the_env->nvalues = 1;
#line 862
		return __value0;
#line 862
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
#line 880
				const cl_env_ptr the_env = ecl_process_env();
#line 880
				#line 880
				cl_object __value0 = l;
#line 880
				the_env->nvalues = 1;
#line 880
				return __value0;
#line 880
			}

	} end_loop_for_in;
	{
#line 882
		const cl_env_ptr the_env = ecl_process_env();
#line 882
		#line 882
		cl_object __value0 = ECL_NIL;
#line 882
		the_env->nvalues = 1;
#line 882
		return __value0;
#line 882
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
#line 920
		const cl_env_ptr the_env = ecl_process_env();
#line 920
		#line 920
		cl_object __value0 = list;
#line 920
		the_env->nvalues = 1;
#line 920
		return __value0;
#line 920
	}

}

cl_object
cl_tailp(cl_object y, cl_object x)
{
	loop_for_on(x) {
		if (ecl_eql(x, y)) {
#line 927
			const cl_env_ptr the_env = ecl_process_env();
#line 927
			#line 927
			cl_object __value0 = ECL_T;
#line 927
			the_env->nvalues = 1;
#line 927
			return __value0;
#line 927
		}
;
	} end_loop_for_on(x);
	return cl_eql(x, y);
}

#line 932
cl_object cl_adjoin(cl_narg narg, cl_object item, cl_object list, ...)
{
#line 932

	cl_object output;
#line 935
	const cl_env_ptr the_env = ecl_process_env();
#line 935
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 935
	cl_object KEY_VARS[6];
#line 935
	ecl_va_list ARGS;
	ecl_va_start(ARGS, list, narg, 2);
#line 935
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(82));
#line 935
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 935
	if (KEY_VARS[3]==ECL_NIL) {
#line 935
	  test = ECL_NIL;
	} else {
#line 935
	  test = KEY_VARS[0];
	}
#line 935
	if (KEY_VARS[4]==ECL_NIL) {
#line 935
	  test_not = ECL_NIL;
	} else {
#line 935
	  test_not = KEY_VARS[1];
	}
#line 935
	if (KEY_VARS[5]==ECL_NIL) {
#line 935
	  key = ECL_NIL;
	} else {
#line 935
	  key = KEY_VARS[2];
	}
#line 935
	if (narg < 2)
		FEwrong_num_arguments(ecl_make_fixnum(/*ADJOIN*/82));
	output = si_member1(item, list, test, test_not, key);
	if (Null(output))
		output = CONS(item, list);
	else
		output = list;
	{
#line 942
		#line 942
		cl_object __value0 = output;
#line 942
		the_env->nvalues = 1;
#line 942
		return __value0;
#line 942
	}

}

cl_object
cl_cons(cl_object x, cl_object y)
{
	{
#line 948
		const cl_env_ptr the_env = ecl_process_env();
#line 948
		#line 948
		cl_object __value0 = CONS(x, y);
#line 948
		the_env->nvalues = 1;
#line 948
		return __value0;
#line 948
	}

}

cl_object
cl_acons(cl_object x, cl_object y, cl_object z)
{
	{
#line 954
		const cl_env_ptr the_env = ecl_process_env();
#line 954
		#line 954
		cl_object __value0 = CONS(CONS(x, y), z);
#line 954
		the_env->nvalues = 1;
#line 954
		return __value0;
#line 954
	}

}

#line 957
cl_object cl_pairlis(cl_narg narg, cl_object keys, cl_object data, ...)
{
#line 957

	cl_object k, d;
#line 960
	const cl_env_ptr the_env = ecl_process_env();
#line 960
	cl_object a_list;
#line 960
	va_list ARGS;
	va_start(ARGS, data);
#line 960
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(626));
#line 960
	if (narg > 2) {
#line 960
		a_list = va_arg(ARGS,cl_object);
#line 960
	} else {
#line 960
		a_list = ECL_NIL;
#line 960
	}
#line 960
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
#line 971
		#line 971
		cl_object __value0 = a_list;
#line 971
		the_env->nvalues = 1;
#line 971
		return __value0;
#line 971
	}

}


#line 975
cl_object cl_assoc(cl_narg narg, cl_object item, cl_object a_list, ...)
{
#line 975

	struct cl_test t;
#line 978
	const cl_env_ptr the_env = ecl_process_env();
#line 978
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 978
	cl_object KEY_VARS[6];
#line 978
	ecl_va_list ARGS;
	ecl_va_start(ARGS, a_list, narg, 2);
#line 978
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(114));
#line 978
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 978
	if (KEY_VARS[3]==ECL_NIL) {
#line 978
	  test = ECL_NIL;
	} else {
#line 978
	  test = KEY_VARS[0];
	}
#line 978
	if (KEY_VARS[4]==ECL_NIL) {
#line 978
	  test_not = ECL_NIL;
	} else {
#line 978
	  test_not = KEY_VARS[1];
	}
#line 978
	if (KEY_VARS[5]==ECL_NIL) {
#line 978
	  key = ECL_NIL;
	} else {
#line 978
	  key = KEY_VARS[2];
	}
#line 978
	setup_test(&t, item, test, test_not, key);
	a_list = do_assoc(&t, a_list);
	close_test(&t);
	{
#line 981
		#line 981
		cl_object __value0 = a_list;
#line 981
		the_env->nvalues = 1;
#line 981
		return __value0;
#line 981
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

#line 999
cl_object cl_rassoc(cl_narg narg, cl_object item, cl_object a_list, ...)
{
#line 999

	struct cl_test t;
#line 1002
	const cl_env_ptr the_env = ecl_process_env();
#line 1002
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1317), (cl_object)(cl_symbols+1262)};
	cl_object test;
	cl_object test_not;
	cl_object key;
#line 1002
	cl_object KEY_VARS[6];
#line 1002
	ecl_va_list ARGS;
	ecl_va_start(ARGS, a_list, narg, 2);
#line 1002
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(683));
#line 1002
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 1002
	if (KEY_VARS[3]==ECL_NIL) {
#line 1002
	  test = ECL_NIL;
	} else {
#line 1002
	  test = KEY_VARS[0];
	}
#line 1002
	if (KEY_VARS[4]==ECL_NIL) {
#line 1002
	  test_not = ECL_NIL;
	} else {
#line 1002
	  test_not = KEY_VARS[1];
	}
#line 1002
	if (KEY_VARS[5]==ECL_NIL) {
#line 1002
	  key = ECL_NIL;
	} else {
#line 1002
	  key = KEY_VARS[2];
	}
#line 1002
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
#line 1015
		#line 1015
		cl_object __value0 = a_list;
#line 1015
		the_env->nvalues = 1;
#line 1015
		return __value0;
#line 1015
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
