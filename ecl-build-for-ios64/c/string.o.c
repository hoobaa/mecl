#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/string.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    string.d -- String routines.
*/
/*
    Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under thep terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/


#include <ecl/ecl.h>
#include <string.h>
#include <ecl/internal.h>
#include <ecl/ecl-inl.h>

typedef ecl_character (*ecl_casefun)(ecl_character, bool *);

static cl_object
do_make_base_string(cl_index s, ecl_base_char code)
{
	cl_object x = ecl_alloc_simple_base_string(s);
	cl_index i;
	for (i = 0;  i < s;  i++)
		x->base_string.self[i] = code;
	return x;
}

#ifdef ECL_UNICODE
static cl_object
do_make_string(cl_index s, ecl_character code)
{
	cl_object x = ecl_alloc_simple_extended_string(s);
	cl_index i;
	for (i = 0;  i < s;  i++)
		x->string.self[i] = code;
	return x;
}
#else
#define do_make_string do_make_base_string
#endif

#line 51
cl_object cl_make_string(cl_narg narg, cl_object size, ...)
{
#line 51

	cl_index s;
	cl_object x;
#line 55
	const cl_env_ptr the_env = ecl_process_env();
#line 55
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1251), (cl_object)(cl_symbols+1224)};
	cl_object initial_element;
	cl_object element_type;
#line 55
	cl_object KEY_VARS[4];
#line 55
	ecl_va_list ARGS;
	ecl_va_start(ARGS, size, narg, 1);
#line 55
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(534));
#line 55
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 55
	if (KEY_VARS[2]==ECL_NIL) {
#line 55
	  initial_element = ECL_CODE_CHAR(' ');
	} else {
#line 55
	  initial_element = KEY_VARS[0];
	}
#line 55
	if (KEY_VARS[3]==ECL_NIL) {
#line 55
	  element_type = ECL_SYM("CHARACTER",222);
	} else {
#line 55
	  element_type = KEY_VARS[1];
	}
#line 55
	s = ecl_to_index(size);
	/* INV: ecl_[base_]char_code() checks the type of initial_element() */
	if (element_type == ECL_SYM("BASE-CHAR",120) || element_type == ECL_SYM("STANDARD-CHAR",794)) {
		int code = ecl_base_char_code(initial_element);
		x = do_make_base_string(s, code);
	} else if (element_type == ECL_SYM("CHARACTER",222)) {
		cl_index code = ecl_char_code(initial_element);
		x = do_make_string(s, code);
	} else if (_ecl_funcall3(ECL_SYM("SUBTYPEP",837), element_type, ECL_SYM("BASE-CHAR",120)) == ECL_T) {
		int code = ecl_base_char_code(initial_element);
		x = do_make_base_string(s, code);
	} else if (_ecl_funcall3(ECL_SYM("SUBTYPEP",837), element_type, ECL_SYM("CHARACTER",222)) == ECL_T) {
		cl_index code = ecl_char_code(initial_element);
		x = do_make_string(s, code);
	} else {
		FEerror("The type ~S is not a valid string char type.",
			1, element_type);
	}
	{
#line 73
		#line 73
		cl_object __value0 = x;
#line 73
		the_env->nvalues = 1;
#line 73
		return __value0;
#line 73
	}

}

/*
	Make a string of a certain size, with some eading zeros to
	keep C happy. The string must be adjustable, to allow further
	growth. (See unixfsys.c for its use).
*/
cl_object
ecl_alloc_adjustable_base_string(cl_index l)
{
	cl_object output = ecl_alloc_object(t_base_string);
	output->base_string.self       = (ecl_base_char *)ecl_alloc_atomic(l+1);
        output->base_string.self[l]    = 0;
	output->base_string.flags      = ECL_FLAG_HAS_FILL_POINTER | ECL_FLAG_ADJUSTABLE;
        output->base_string.elttype    = ecl_aet_bc;
	output->base_string.displaced  = ECL_NIL;
	output->base_string.dim        = l;
	output->base_string.fillp      = 0;
	return output;
}

#ifdef ECL_UNICODE
cl_object
ecl_alloc_adjustable_extended_string(cl_index l)
{
        cl_index bytes = sizeof(ecl_character) * l;
	cl_object output = ecl_alloc_object(t_string);
	output->string.self       = (ecl_character *)ecl_alloc_atomic(bytes);
	output->string.flags      = ECL_FLAG_HAS_FILL_POINTER | ECL_FLAG_ADJUSTABLE;
        output->string.elttype    = ecl_aet_ch;
	output->string.displaced  = ECL_NIL;
	output->string.dim        = l;
        output->string.fillp      = 0;
	return output;
}
#endif

/*
	Make_simple_base_string(s) makes a simple-base string from C string s.
*/
cl_object
ecl_make_simple_base_string(char *s, cl_fixnum l)
{
	cl_object x = ecl_alloc_object(t_base_string);
        x->base_string.elttype = ecl_aet_bc;
        x->base_string.flags = 0; /* no fill pointer, no adjustable */
	x->base_string.displaced = ECL_NIL;
        if (l < 0) l = strlen(s);
	x->base_string.dim = (x->base_string.fillp = l);
	x->base_string.self = (ecl_base_char *)s;
	return x;
}

cl_object
make_base_string_copy(const char *s)
{
	cl_object x;
	cl_index l = strlen(s);

	x = ecl_alloc_simple_base_string(l);
	memcpy(x->base_string.self, s, l);
	return x;
}

cl_object
ecl_cstring_to_base_string_or_nil(const char *s)
{
	if (s == NULL)
		return ECL_NIL;
	else
		return make_base_string_copy(s);
}

bool
ecl_fits_in_base_string(cl_object s)
{
	switch (ecl_t_of(s)) {
#ifdef ECL_UNICODE
	case t_string: {
		cl_index i;
		for (i = 0; i < s->string.fillp; i++) {
			if (!ECL_BASE_CHAR_CODE_P(s->string.self[i]))
				return 0;
		}
		return 1;
	}
#endif
	case t_base_string:
		return 1;
	default:
		FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::COPY-TO-SIMPLE-BASE-STRING*/1060),1,s,ecl_make_fixnum(/*STRING*/805));
	}
}

cl_object
si_copy_to_simple_base_string(cl_object x)
{
	cl_object y;
 AGAIN:
	switch(ecl_t_of(x)) {
	case t_symbol:
		x = x->symbol.name;
		goto AGAIN;
	case t_character:
		x = cl_string(x);
		goto AGAIN;
#ifdef ECL_UNICODE
	case t_string: {
		cl_index index, length = x->string.fillp;
		y = ecl_alloc_simple_base_string(length);
		for (index=0; index < length; index++) {
			ecl_character c = x->string.self[index];
			if (!ECL_BASE_CHAR_CODE_P(c))
				FEerror("Cannot coerce string ~A to a base-string", 1, x);
			y->base_string.self[index] = c;
		}
		break;
	}
#endif
	case t_base_string: {
		cl_index length = x->base_string.fillp;
		y = ecl_alloc_simple_base_string(length);
		memcpy(y->base_string.self, x->base_string.self, length);
		break;
	}
	case t_list:
		if (Null(x)) {
			x = ECL_NIL_SYMBOL->symbol.name;
			goto AGAIN;
		}
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::COPY-TO-SIMPLE-BASE-STRING*/1060),1,x,ecl_make_fixnum(/*STRING*/805));
	}
	{
#line 207
		const cl_env_ptr the_env = ecl_process_env();
#line 207
		#line 207
		cl_object __value0 = y;
#line 207
		the_env->nvalues = 1;
#line 207
		return __value0;
#line 207
	}

}

cl_object
cl_string(cl_object x)
{
	switch (ecl_t_of(x)) {
	case t_symbol:
		x = x->symbol.name;
		break;
	case t_character: {
		cl_object y;
                ecl_character c = ECL_CHAR_CODE(x);
#ifdef ECL_UNICODE
		if (ECL_BASE_CHAR_CODE_P(c)) {
			y = ecl_alloc_simple_base_string(1);
			y->base_string.self[0] = c;
			x = y;
		} else {
			y = ecl_alloc_simple_extended_string(1);
			y->string.self[0] = c;
			x = y;
		}
#else
		y = ecl_alloc_simple_base_string(1);
		y->base_string.self[0] = c;
		x = y;
		break;
#endif
	}
#ifdef ECL_UNICODE
	case t_string:
#endif
	case t_base_string:
		break;
	case t_list:
		if (Null(x)) {
			x = ECL_NIL_SYMBOL->symbol.name;
			break;
		}
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*STRING*/805),1,x,ecl_make_fixnum(/*STRING*/805));
	}
	{
#line 250
		const cl_env_ptr the_env = ecl_process_env();
#line 250
		#line 250
		cl_object __value0 = x;
#line 250
		the_env->nvalues = 1;
#line 250
		return __value0;
#line 250
	}

}

#ifdef ECL_UNICODE
cl_object
si_coerce_to_base_string(cl_object x)
{
	if (!ECL_BASE_STRING_P(x)) {
		x = si_copy_to_simple_base_string(x);
	}
	{
#line 260
		const cl_env_ptr the_env = ecl_process_env();
#line 260
		#line 260
		cl_object __value0 = x;
#line 260
		the_env->nvalues = 1;
#line 260
		return __value0;
#line 260
	}

}

cl_object
si_coerce_to_extended_string(cl_object x)
{
	cl_object y;
 AGAIN:
	switch (ecl_t_of(x)) {
	case t_symbol:
		x = x->symbol.name;
		goto AGAIN;
	case t_character:
		y = ecl_alloc_simple_extended_string(1);
		y->string.self[0] = ECL_CHAR_CODE(x);
		break;
	case t_base_string: {
		cl_index index, len = x->base_string.dim;
		y = ecl_alloc_simple_extended_string(x->base_string.fillp);
		for(index=0; index < len; index++) {
			y->string.self[index] = x->base_string.self[index];
		}
		y->string.fillp = x->base_string.fillp;
	}
	case t_string:
		y = x;
		break;
	case t_list:
		if (Null(x)) {
			x = ECL_NIL_SYMBOL->symbol.name;
			goto AGAIN;
		}
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::COERCE-TO-EXTENDED-STRING*/1056),1,x,ecl_make_fixnum(/*STRING*/805));
	}
	{
#line 295
		const cl_env_ptr the_env = ecl_process_env();
#line 295
		#line 295
		cl_object __value0 = y;
#line 295
		the_env->nvalues = 1;
#line 295
		return __value0;
#line 295
	}

}
#endif

cl_object
cl_char(cl_object object, cl_object index)
{
	cl_index position = ecl_to_index(index);
	{
#line 303
		const cl_env_ptr the_env = ecl_process_env();
#line 303
		#line 303
		cl_object __value0 = ECL_CODE_CHAR(ecl_char(object, position));
#line 303
		the_env->nvalues = 1;
#line 303
		return __value0;
#line 303
	}

}

ecl_character
ecl_char(cl_object object, cl_index index)
{
	/* CHAR bypasses fill pointers when accessing strings */
	switch(ecl_t_of(object)) {
#ifdef ECL_UNICODE
	case t_string:
		if (index >= object->string.dim)
			FEtype_error_index(object, index);
		return object->string.self[index];
#endif
	case t_base_string:
		if (index >= object->base_string.dim)
			FEtype_error_index(object, index);
		return object->base_string.self[index];
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*CHAR*/203),1,object,ecl_make_fixnum(/*STRING*/805));
	}
}

cl_object
si_char_set(cl_object object, cl_object index, cl_object value)
{
	cl_index position = ecl_to_index(index);
	cl_index c = ecl_char_code(value);
	ecl_char_set(object, position, c);
	{
#line 332
		const cl_env_ptr the_env = ecl_process_env();
#line 332
		#line 332
		cl_object __value0 = value;
#line 332
		the_env->nvalues = 1;
#line 332
		return __value0;
#line 332
	}

}

ecl_character
ecl_char_set(cl_object object, cl_index index, ecl_character value)
{
	/* CHAR bypasses fill pointers when accessing strings */
	switch(ecl_t_of(object)) {
#ifdef ECL_UNICODE
	case t_string:
		if (index >= object->string.dim)
			FEtype_error_index(object, index);
		return object->string.self[index] = value;
#endif
	case t_base_string:
		if (index >= object->base_string.dim)
			FEtype_error_index(object, index);
		return object->base_string.self[index] = value;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::CHAR-SET*/1052),1,object,ecl_make_fixnum(/*STRING*/805));
	}
}

#ifdef ECL_UNICODE
static int
compare_strings(cl_object string1, cl_index s1, cl_index e1,
		cl_object string2, cl_index s2, cl_index e2,
		int case_sensitive, cl_index *m)
{
	cl_index c1, c2;
	for (; s1 < e1; s1++, s2++) {
		if (s2 >= e2) { /* s1 is longer than s2, therefore s2 < s1 */
			*m = s1;
			return +1;
		}
		c1 = ecl_char(string1, s1);
		c2 = ecl_char(string2, s2);
		if (!case_sensitive) {
			c1 = ecl_char_upcase(c1);
			c2 = ecl_char_upcase(c2);
		}
		if (c1 < c2) {
			*m = s1;
			return -1;
		} else if (c1 > c2) {
			*m = s1;
			return +1;
		}
	}
	*m = s1;
	if (s2 >= e2) {
		return 0;
	} else { /* s1 is shorter than s2, hence s1 < s2 */
		return -1;
	}
}
#endif

static int
compare_base(unsigned char *s1, cl_index l1, unsigned char *s2, cl_index l2,
	     int case_sensitive, cl_index *m)
{
	cl_index l, c1, c2;
	for (l = 0; l < l1; l++, s1++, s2++) {
		if (l == l2) { /* s1 is longer than s2, therefore s2 < s1 */
			*m = l;
			return +1;
		}
		c1 = *s1;
		c2 = *s2;
		if (!case_sensitive) {
			c1 = ecl_char_upcase(c1);
			c2 = ecl_char_upcase(c2);
		}
		if (c1 < c2) {
			*m = l;
			return -1;
		} else if (c1 > c2) {
			*m = l;
			return +1;
		}
	}
	*m = l;
	if (l1 == l2) 
		return 0;
	else { /* s1 is shorter than s2, hence s1 < s2 */
		return -1;
	}
}

#line 423
cl_object cl_stringE(cl_narg narg, cl_object string1, cl_object string2, ...)
{
#line 423

        cl_index_pair p;
	cl_index s1, e1, s2, e2;
#line 427
	const cl_env_ptr the_env = ecl_process_env();
#line 427
	static cl_object KEYS[4] = {(cl_object)(cl_symbols+1311), (cl_object)(cl_symbols+1226), (cl_object)(cl_symbols+1312), (cl_object)(cl_symbols+1227)};
	cl_object start1;
	cl_object end1;
	cl_object start2;
	cl_object end2;
#line 427
	cl_object KEY_VARS[8];
#line 427
	ecl_va_list ARGS;
	ecl_va_start(ARGS, string2, narg, 2);
#line 427
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(822));
#line 427
	cl_parse_key(ARGS, 4, KEYS, KEY_VARS, NULL, 0);
#line 427
	if (KEY_VARS[4]==ECL_NIL) {
#line 427
	  start1 = ecl_make_fixnum(0);
	} else {
#line 427
	  start1 = KEY_VARS[0];
	}
#line 427
	if (KEY_VARS[5]==ECL_NIL) {
#line 427
	  end1 = ECL_NIL;
	} else {
#line 427
	  end1 = KEY_VARS[1];
	}
#line 427
	if (KEY_VARS[6]==ECL_NIL) {
#line 427
	  start2 = ecl_make_fixnum(0);
	} else {
#line 427
	  start2 = KEY_VARS[2];
	}
#line 427
	if (KEY_VARS[7]==ECL_NIL) {
#line 427
	  end2 = ECL_NIL;
	} else {
#line 427
	  end2 = KEY_VARS[3];
	}
#line 427
{
	string1 = cl_string(string1);
	string2 = cl_string(string2);
	p = ecl_vector_start_end(ecl_make_fixnum(/*STRING=*/822), string1, start1, end1);
        s1 = p.start; e1 = p.end;
	p = ecl_vector_start_end(ecl_make_fixnum(/*STRING=*/822), string2, start2, end2);
        s2 = p.start; e2 = p.end;
	if (e1 - s1 != e2 - s2)
		{
#line 435
			#line 435
			cl_object __value0 = ECL_NIL;
#line 435
			the_env->nvalues = 1;
#line 435
			return __value0;
#line 435
		}
;
#ifdef ECL_UNICODE
	if (string1->string.t == t_string) {
		if (string2->string.t == t_string) {
			while (s1 < e1)
				if (string1->string.self[s1++] != string2->string.self[s2++])
					{
#line 441
						#line 441
						cl_object __value0 = ECL_NIL;
#line 441
						the_env->nvalues = 1;
#line 441
						return __value0;
#line 441
					}
;
			{
#line 442
				#line 442
				cl_object __value0 = ECL_T;
#line 442
				the_env->nvalues = 1;
#line 442
				return __value0;
#line 442
			}
;
		} else {
			while (s1 < e1)
				if (string1->string.self[s1++] != string2->base_string.self[s2++])
					{
#line 446
						#line 446
						cl_object __value0 = ECL_NIL;
#line 446
						the_env->nvalues = 1;
#line 446
						return __value0;
#line 446
					}
;
			{
#line 447
				#line 447
				cl_object __value0 = ECL_T;
#line 447
				the_env->nvalues = 1;
#line 447
				return __value0;
#line 447
			}
;
		}
	} else {
		if (string2->string.t == t_string) {
			while (s1 < e1)
				if (string1->base_string.self[s1++] != string2->string.self[s2++])
					{
#line 453
						#line 453
						cl_object __value0 = ECL_NIL;
#line 453
						the_env->nvalues = 1;
#line 453
						return __value0;
#line 453
					}
;
			{
#line 454
				#line 454
				cl_object __value0 = ECL_T;
#line 454
				the_env->nvalues = 1;
#line 454
				return __value0;
#line 454
			}
;
		} else {
			while (s1 < e1)
				if (string1->base_string.self[s1++] != string2->base_string.self[s2++])
					{
#line 458
						#line 458
						cl_object __value0 = ECL_NIL;
#line 458
						the_env->nvalues = 1;
#line 458
						return __value0;
#line 458
					}
;
			{
#line 459
				#line 459
				cl_object __value0 = ECL_T;
#line 459
				the_env->nvalues = 1;
#line 459
				return __value0;
#line 459
			}
;
		}
 	}
#else
	while (s1 < e1)
		if (string1->base_string.self[s1++] != string2->base_string.self[s2++])
			{
#line 465
				#line 465
				cl_object __value0 = ECL_NIL;
#line 465
				the_env->nvalues = 1;
#line 465
				return __value0;
#line 465
			}
;
#endif
	{
#line 467
		#line 467
		cl_object __value0 = ECL_T;
#line 467
		the_env->nvalues = 1;
#line 467
		return __value0;
#line 467
	}
;
}
}

/*
	This correponds to string= (just the string equality).
*/
bool
ecl_string_eq(cl_object x, cl_object y)
{
	cl_index i, j;
	i = x->base_string.fillp;
	j = y->base_string.fillp;
	if (i != j) return 0;
#ifdef ECL_UNICODE
	switch(ecl_t_of(x)) {
	case t_string:
		switch(ecl_t_of(y)) {
		case t_string:
			return memcmp(x->string.self, y->string.self, i * sizeof *x->string.self) == 0;
		case t_base_string: {
			cl_index index;
			for(index=0; index<i; index++)
				if (x->string.self[index] != y->base_string.self[index])
					return 0;
			return 1;
			}
		default:
                        FEwrong_type_nth_arg(ecl_make_fixnum(/*STRING=*/822),2,y,ecl_make_fixnum(/*STRING*/805));
		}
		break;
	case t_base_string:
		switch(ecl_t_of(y)) {
		case t_string:
			return ecl_string_eq(y, x);
		case t_base_string:
			return memcmp(x->base_string.self, y->base_string.self, i) == 0;
		default:
                        FEwrong_type_nth_arg(ecl_make_fixnum(/*STRING=*/822),2,y,ecl_make_fixnum(/*STRING*/805));
		}
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*STRING=*/822),2,x,ecl_make_fixnum(/*STRING*/805));
	}
#else
	return memcmp(x->base_string.self, y->base_string.self, i) == 0;
#endif
}


static void test(cl_object string1, cl_object string2) {
        printf(">>>>FUCKFUCK:%d:%d\n", string1->string.t, string2->string.t);
}

#line 522
cl_object cl_string_equal(cl_narg narg, cl_object string1, cl_object string2, ...)
{
#line 522

	cl_index s1, e1, s2, e2;
        cl_index_pair p;
	int output;
#line 527
	const cl_env_ptr the_env = ecl_process_env();
#line 527
	static cl_object KEYS[4] = {(cl_object)(cl_symbols+1311), (cl_object)(cl_symbols+1226), (cl_object)(cl_symbols+1312), (cl_object)(cl_symbols+1227)};
	cl_object start1;
	cl_object end1;
	cl_object start2;
	cl_object end2;
#line 527
	cl_object KEY_VARS[8];
#line 527
	ecl_va_list ARGS;
	ecl_va_start(ARGS, string2, narg, 2);
#line 527
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(808));
#line 527
	cl_parse_key(ARGS, 4, KEYS, KEY_VARS, NULL, 0);
#line 527
	if (KEY_VARS[4]==ECL_NIL) {
#line 527
	  start1 = ecl_make_fixnum(0);
	} else {
#line 527
	  start1 = KEY_VARS[0];
	}
#line 527
	if (KEY_VARS[5]==ECL_NIL) {
#line 527
	  end1 = ECL_NIL;
	} else {
#line 527
	  end1 = KEY_VARS[1];
	}
#line 527
	if (KEY_VARS[6]==ECL_NIL) {
#line 527
	  start2 = ecl_make_fixnum(0);
	} else {
#line 527
	  start2 = KEY_VARS[2];
	}
#line 527
	if (KEY_VARS[7]==ECL_NIL) {
#line 527
	  end2 = ECL_NIL;
	} else {
#line 527
	  end2 = KEY_VARS[3];
	}
#line 527
  printf("FUCK:%d, %d", string1->string.t, string2->string.t);
	string1 = cl_string(string1);
	string2 = cl_string(string2); // this is fuckin string2->string.t == \xf4 (must be 10)
	p = ecl_vector_start_end(ecl_make_fixnum(/*STRING=*/822), string1, start1, end1);
        s1 = p.start; e1 = p.end;
	p = ecl_vector_start_end(ecl_make_fixnum(/*STRING=*/822), string2, start2, end2);
        s2 = p.start; e2 = p.end;
	if (e1 - s1 != e2 - s2)
		{
#line 535
			#line 535
			cl_object __value0 = ECL_NIL;
#line 535
			the_env->nvalues = 1;
#line 535
			return __value0;
#line 535
		}
;
#ifdef ECL_UNICODE
        if (ECL_EXTENDED_STRING_P(string1) || ECL_EXTENDED_STRING_P(string2)) {
		output = compare_strings(string1, s1, e1, string2, s2, e2, 0, &e1);
	} else
#endif
	output = compare_base(string1->base_string.self + s1, e1 - s1,
			      string2->base_string.self + s2, e2 - s2,
			      0, &e1);
	{
#line 544
		#line 544
		cl_object __value0 = ((output == 0)? ECL_T : ECL_NIL);
#line 544
		the_env->nvalues = 1;
#line 544
		return __value0;
#line 544
	}

}

static cl_object
string_compare(cl_narg narg, int sign1, int sign2, int case_sensitive, ecl_va_list ARGS)
{
	cl_object string1 = ecl_va_arg(ARGS);
	cl_object string2 = ecl_va_arg(ARGS);
	cl_index s1, e1, s2, e2;
        cl_index_pair p;
	int output;
	cl_object result;
	cl_object KEYS[4];
#define start1 KEY_VARS[0]
#define end1 KEY_VARS[1]
#define start2 KEY_VARS[2]
#define end2 KEY_VARS[3]
#define start1p KEY_VARS[4]
#define start2p KEY_VARS[6]
	cl_object KEY_VARS[8];

	if (narg < 2) FEwrong_num_arguments_anonym();
	KEYS[0]=ECL_SYM(":START1",1311);
	KEYS[1]=ECL_SYM(":END1",1226);
	KEYS[2]=ECL_SYM(":START2",1312);
	KEYS[3]=ECL_SYM(":END2",1227);
	cl_parse_key(ARGS, 4, KEYS, KEY_VARS, NULL, FALSE);

	string1 = cl_string(string1);
	string2 = cl_string(string2);
	if (start1p == ECL_NIL) start1 = ecl_make_fixnum(0);
	if (start2p == ECL_NIL) start2 = ecl_make_fixnum(0);
	p = ecl_vector_start_end(ecl_make_fixnum(/*STRING=*/822), string1, start1, end1);
        s1 = p.start; e1 = p.end;
	p = ecl_vector_start_end(ecl_make_fixnum(/*STRING=*/822), string2, start2, end2);
        s2 = p.start; e2 = p.end;
#ifdef ECL_UNICODE
	if (ECL_EXTENDED_STRING_P(string1) || ECL_EXTENDED_STRING_P(string2)) {
		output = compare_strings(string1, s1, e1, string2, s2, e2,
					 case_sensitive, &e1);
	} else
#endif
	{
		output = compare_base(string1->base_string.self + s1, e1 - s1,
				      string2->base_string.self + s2, e2 - s2,
				      case_sensitive, &e1);
		e1 += s1;
	}
	if (output == sign1 || output == sign2) {
		result = ecl_make_fixnum(e1);
	} else {
		result = ECL_NIL;
	}
	{
#line 597
		const cl_env_ptr the_env = ecl_process_env();
#line 597
		#line 597
		cl_object __value0 = result;
#line 597
		the_env->nvalues = 1;
#line 597
		return __value0;
#line 597
	}

#undef start1p
#undef start2p
#undef start1
#undef end1
#undef start2
#undef end2
}

#line 606
cl_object cl_stringL(cl_narg narg, ...)
{
#line 606

#line 608
	const cl_env_ptr the_env = ecl_process_env();
#line 608
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 608
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(820));
#line 608
	return string_compare(narg, -1, -1, 1, args);
}

#line 611
cl_object cl_stringG(cl_narg narg, ...)
{
#line 611

#line 613
	const cl_env_ptr the_env = ecl_process_env();
#line 613
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 613
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(823));
#line 613
	return string_compare(narg, +1, +1, 1, args);
}

#line 616
cl_object cl_stringLE(cl_narg narg, ...)
{
#line 616

#line 618
	const cl_env_ptr the_env = ecl_process_env();
#line 618
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 618
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(821));
#line 618
	return string_compare(narg, -1, 0, 1, args);
}

#line 621
cl_object cl_stringGE(cl_narg narg, ...)
{
#line 621

#line 623
	const cl_env_ptr the_env = ecl_process_env();
#line 623
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 623
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(824));
#line 623
	return string_compare(narg, 0, +1, 1, args);
}

#line 626
cl_object cl_stringNE(cl_narg narg, ...)
{
#line 626

#line 628
	const cl_env_ptr the_env = ecl_process_env();
#line 628
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 628
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(819));
#line 628
	return string_compare(narg, -1, +1, 1, args);
}

#line 631
cl_object cl_string_lessp(cl_narg narg, ...)
{
#line 631

#line 633
	const cl_env_ptr the_env = ecl_process_env();
#line 633
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 633
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(811));
#line 633
	return string_compare(narg, -1, -1, 0, args);
}

#line 636
cl_object cl_string_greaterp(cl_narg narg, ...)
{
#line 636

#line 638
	const cl_env_ptr the_env = ecl_process_env();
#line 638
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 638
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(809));
#line 638
	return string_compare(narg, +1, +1, 0, args);
}

#line 641
cl_object cl_string_not_greaterp(cl_narg narg, ...)
{
#line 641

#line 643
	const cl_env_ptr the_env = ecl_process_env();
#line 643
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 643
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(813));
#line 643
	return string_compare(narg, -1, 0, 0, args);
}

#line 646
cl_object cl_string_not_lessp(cl_narg narg, ...)
{
#line 646

#line 648
	const cl_env_ptr the_env = ecl_process_env();
#line 648
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 648
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(814));
#line 648
	return string_compare(narg, 0, +1, 0, args);
}

#line 651
cl_object cl_string_not_equal(cl_narg narg, ...)
{
#line 651

#line 653
	const cl_env_ptr the_env = ecl_process_env();
#line 653
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 653
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(812));
#line 653
	return string_compare(narg, -1, +1, 0, args);
}

bool
ecl_member_char(ecl_character c, cl_object char_bag)
{
	cl_index i, f;
	switch (ecl_t_of(char_bag)) {
	case t_list:
		loop_for_in(char_bag) {
			cl_object other = CAR(char_bag);
			if (ECL_CHARACTERP(other) && c == ECL_CHAR_CODE(other))
				return(TRUE);
		} end_loop_for_in;
		return(FALSE);
	case t_vector:
		for (i = 0, f = char_bag->vector.fillp;  i < f;  i++) {
			cl_object other = char_bag->vector.self.t[i];
			if (ECL_CHARACTERP(other) && c == ECL_CHAR_CODE(other))
				return(TRUE);
		}
		return(FALSE);
#ifdef ECL_UNICODE
	case t_string:
		for (i = 0, f = char_bag->string.fillp;  i < f;  i++) {
			if (c == char_bag->string.self[i])
				return(TRUE);
		}
		return(FALSE);
#endif
	case t_base_string:
		for (i = 0, f = char_bag->base_string.fillp;  i < f;  i++) {
			if (c == char_bag->base_string.self[i])
				return(TRUE);
		}
		return(FALSE);
	case t_bitvector:
		return(FALSE);
	default:
		FEwrong_type_nth_arg(ecl_make_fixnum(/*MEMBER*/552),2,char_bag,ecl_make_fixnum(/*SEQUENCE*/741));
	}
}

static cl_object
string_trim0(bool left_trim, bool right_trim, cl_object char_bag, cl_object strng)
{
	cl_index i, j;

	strng = cl_string(strng);
	i = 0;
	j = ecl_length(strng);
	if (left_trim) {
		for (;  i < j;  i++) {
			cl_index c = ecl_char(strng, i);
			if (!ecl_member_char(c, char_bag))
				break;
		}
	}
	if (right_trim) {
		for (; j > i; j--) {
			cl_index c = ecl_char(strng, j-1);
			if (!ecl_member_char(c, char_bag)) {
				break;
			}
		}
	}
	return cl_subseq(3, strng, ecl_make_fixnum(i), ecl_make_fixnum(j));
}

cl_object
cl_string_trim(cl_object char_bag, cl_object strng)
{
	return string_trim0(TRUE, TRUE, char_bag, strng);
}

cl_object
cl_string_left_trim(cl_object char_bag, cl_object strng)
{
	return string_trim0(TRUE, FALSE, char_bag, strng);
}

cl_object
cl_string_right_trim(cl_object char_bag, cl_object strng)
{
	return string_trim0(FALSE, TRUE, char_bag, strng);
}

static cl_object
string_case(cl_narg narg, cl_object fun, ecl_casefun casefun, ecl_va_list ARGS)
{
	cl_object strng = ecl_va_arg(ARGS);
        cl_index_pair p;
	cl_index i;
	bool b;
	cl_object KEYS[2];
#define kstart KEY_VARS[0]
#define kend KEY_VARS[1]
#define kstartp KEY_VARS[2]
	cl_object KEY_VARS[4];

	if (narg < 1) FEwrong_num_arguments_anonym();
	KEYS[0]=ECL_SYM(":START",1310);
	KEYS[1]=ECL_SYM(":END",1225);
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, FALSE);

        strng = cl_string(strng);
        strng = cl_copy_seq(strng);
	if (kstartp == ECL_NIL)
                kstart = ecl_make_fixnum(0);
	p = ecl_vector_start_end(fun, strng, kstart, kend);
	b = TRUE;
#ifdef ECL_UNICODE
	if (ECL_EXTENDED_STRING_P(strng)) {
		for (i = p.start;  i < p.end;  i++)
			strng->string.self[i] = (*casefun)(strng->string.self[i], &b);
        } else
#endif
	for (i = p.start;  i < p.end;  i++)
		strng->base_string.self[i] = (*casefun)(strng->base_string.self[i], &b);
	{
#line 772
		const cl_env_ptr the_env = ecl_process_env();
#line 772
		#line 772
		cl_object __value0 = strng;
#line 772
		the_env->nvalues = 1;
#line 772
		return __value0;
#line 772
	}

#undef kstartp
#undef kstart
#undef kend
}

static ecl_character
char_upcase(ecl_character c, bool *bp)
{
	return ecl_char_upcase(c);
}

#line 784
cl_object cl_string_upcase(cl_narg narg, ...)
{
#line 784

#line 786
	const cl_env_ptr the_env = ecl_process_env();
#line 786
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 786
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(818));
#line 786
	return string_case(narg, ecl_make_fixnum(/*STRING-UPCASE*/818), char_upcase, args);
}

static ecl_character
char_downcase(ecl_character c, bool *bp)
{
	return ecl_char_downcase(c);
}

#line 795
cl_object cl_string_downcase(cl_narg narg, ...)
{
#line 795

#line 797
	const cl_env_ptr the_env = ecl_process_env();
#line 797
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 797
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(806));
#line 797
	return string_case(narg, ecl_make_fixnum(/*STRING-DOWNCASE*/806), char_downcase, args);
}

static ecl_character
char_capitalize(ecl_character c, bool *bp)
{
	if (ecl_lower_case_p(c)) {
		if (*bp)
			c = ecl_char_upcase(c);
		*bp = FALSE;
	} else if (ecl_upper_case_p(c)) {
		if (!*bp)
			c = ecl_char_downcase(c);
		*bp = FALSE;
	} else {
		*bp = !ecl_alphanumericp(c);
	}
	return c;
}

#line 817
cl_object cl_string_capitalize(cl_narg narg, ...)
{
#line 817

#line 819
	const cl_env_ptr the_env = ecl_process_env();
#line 819
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 819
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(807));
#line 819
	return string_case(narg, ecl_make_fixnum(/*STRING-CAPITALIZE*/807), char_capitalize, args);
}


static cl_object
nstring_case(cl_narg narg, cl_object fun, ecl_casefun casefun, ecl_va_list ARGS)
{
	cl_object strng = ecl_va_arg(ARGS);
        cl_index_pair p;
	cl_index i;
	bool b;
	cl_object KEYS[2];
#define kstart KEY_VARS[0]
#define kend KEY_VARS[1]
#define kstartp KEY_VARS[2]
	cl_object KEY_VARS[4];

	if (narg < 1) FEwrong_num_arguments_anonym();
	KEYS[0]=ECL_SYM(":START",1310);
	KEYS[1]=ECL_SYM(":END",1225);
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, FALSE);

        if (ecl_unlikely(!ECL_STRINGP(strng)))
                FEwrong_type_nth_arg(fun, 1, strng, ecl_make_fixnum(/*STRING*/805));
	if (kstartp == ECL_NIL)
                kstart = ecl_make_fixnum(0);
	p = ecl_vector_start_end(fun, strng, kstart, kend);
	b = TRUE;
#ifdef ECL_UNICODE
	if (ECL_EXTENDED_STRING_P(strng)) {
		for (i = p.start;  i < p.end;  i++)
			strng->string.self[i] = (*casefun)(strng->string.self[i], &b);
	} else
#endif
	for (i = p.start;  i < p.end;  i++)
		strng->base_string.self[i] = (*casefun)(strng->base_string.self[i], &b);
	{
#line 855
		const cl_env_ptr the_env = ecl_process_env();
#line 855
		#line 855
		cl_object __value0 = strng;
#line 855
		the_env->nvalues = 1;
#line 855
		return __value0;
#line 855
	}

#undef kstartp
#undef kstart
#undef kend
}

#line 861
cl_object cl_nstring_upcase(cl_narg narg, ...)
{
#line 861

#line 863
	const cl_env_ptr the_env = ecl_process_env();
#line 863
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 863
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(594));
#line 863
	return nstring_case(narg, ECL_SYM("NSTRING-UPCASE",594), char_upcase, args);
}

#line 866
cl_object cl_nstring_downcase(cl_narg narg, ...)
{
#line 866

#line 868
	const cl_env_ptr the_env = ecl_process_env();
#line 868
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 868
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(593));
#line 868
	return nstring_case(narg, ECL_SYM("NSTRING-DOWNCASE",593), char_downcase, args);
}

#line 871
cl_object cl_nstring_capitalize(cl_narg narg, ...)
{
#line 871

#line 873
	const cl_env_ptr the_env = ecl_process_env();
#line 873
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 873
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(592));
#line 873
	return nstring_case(narg, ECL_SYM("NSTRING-CAPITALIZE",592), char_capitalize, args);
}

#line 876
cl_object si_base_string_concatenate(cl_narg narg, ...)
{
#line 876

	cl_index l;
	int i;
	cl_object output;
#line 881
	const cl_env_ptr the_env = ecl_process_env();
#line 881
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 881
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(1149));
#line 881
	/* Compute final size and store NONEMPTY coerced strings. */
	for (i = 0, l = 0; i < narg; i++) {
		cl_object s = si_coerce_to_base_string(ecl_va_arg(args));
		if (s->base_string.fillp) {
			ECL_STACK_PUSH(the_env, s);
			l += s->base_string.fillp;
		}
	}
	/* Do actual copying by recovering those strings */
	output = ecl_alloc_simple_base_string(l);
	while (l) {
		cl_object s = ECL_STACK_POP_UNSAFE(the_env);
		size_t bytes = s->base_string.fillp;
		l -= bytes;
		memcpy(output->base_string.self + l, s->base_string.self, bytes);
	}
	{
#line 897
		#line 897
		cl_object __value0 = output;
#line 897
		the_env->nvalues = 1;
#line 897
		return __value0;
#line 897
	}
;
}
