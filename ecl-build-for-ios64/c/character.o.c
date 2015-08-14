#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/character.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    character.d -- Character routines.
*/
/*
    Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
    Copyright (c) 1990, Giuseppe Attardi.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <stdio.h>
#include <ecl/ecl.h>

#include "char_ctype.d"

ecl_character
ecl_char_code(cl_object c)
{
	if (ecl_unlikely(!ECL_CHARACTERP(c)))
                FEwrong_type_only_arg(ecl_make_fixnum(/*CHAR-CODE*/204), c, ecl_make_fixnum(/*CHARACTER*/222));
        return ECL_CHAR_CODE(c);
}

ecl_base_char
ecl_base_char_code(cl_object c)
{
#ifdef ECL_UNICODE
	if (ECL_CHARACTERP(c)) {
		cl_fixnum code = ECL_CHAR_CODE(c);
		if (code <= 255) {
			return (int)code;
		}
	}
	FEwrong_type_only_arg(ecl_make_fixnum(/*CHAR-CODE*/204), c, ecl_make_fixnum(/*BASE-CHAR*/120));
#else
	return ecl_char_code(c);
#endif
}

cl_object
cl_standard_char_p(cl_object c)
{
	/* INV: ecl_char_code() checks the type */
	cl_fixnum i = ecl_char_code(c);
	{
#line 51
		const cl_env_ptr the_env = ecl_process_env();
#line 51
		#line 51
		cl_object __value0 = (ecl_standard_char_p(i)? ECL_T : ECL_NIL);
#line 51
		the_env->nvalues = 1;
#line 51
		return __value0;
#line 51
	}

}

bool
ecl_standard_char_p(ecl_character code)
{
	return ((' ' <= code) && (code < '\177')) || (code == '\n');
}

bool
ecl_base_char_p(ecl_character c)
{
	return c <= 255;
}

cl_object
cl_graphic_char_p(cl_object c)
{
	/* INV: ecl_char_code() checks the type */
	{
#line 70
		const cl_env_ptr the_env = ecl_process_env();
#line 70
		#line 70
		cl_object __value0 = (ecl_graphic_char_p(ecl_char_code(c))? ECL_T : ECL_NIL);
#line 70
		the_env->nvalues = 1;
#line 70
		return __value0;
#line 70
	}

}

cl_object
cl_alpha_char_p(cl_object c)
{
	/* INV: ecl_char_code() checks the type */
	{
#line 77
		const cl_env_ptr the_env = ecl_process_env();
#line 77
		#line 77
		cl_object __value0 = (ecl_alpha_char_p(ecl_char_code(c))? ECL_T : ECL_NIL);
#line 77
		the_env->nvalues = 1;
#line 77
		return __value0;
#line 77
	}

}

cl_object
cl_upper_case_p(cl_object c)
{
	/* INV: ecl_char_code() checks the type */
	{
#line 84
		const cl_env_ptr the_env = ecl_process_env();
#line 84
		#line 84
		cl_object __value0 = (ecl_upper_case_p(ecl_char_code(c))? ECL_T : ECL_NIL);
#line 84
		the_env->nvalues = 1;
#line 84
		return __value0;
#line 84
	}

}

cl_object
cl_lower_case_p(cl_object c)
{
	/* INV: ecl_char_code() checks the type */
	{
#line 91
		const cl_env_ptr the_env = ecl_process_env();
#line 91
		#line 91
		cl_object __value0 = (ecl_lower_case_p(ecl_char_code(c))? ECL_T : ECL_NIL);
#line 91
		the_env->nvalues = 1;
#line 91
		return __value0;
#line 91
	}

}

cl_object
cl_both_case_p(cl_object c)
{
	/* INV: ecl_char_code() checks the type */
	{
#line 98
		const cl_env_ptr the_env = ecl_process_env();
#line 98
		#line 98
		cl_object __value0 = (ecl_both_case_p(ecl_char_code(c))? ECL_T : ECL_NIL);
#line 98
		the_env->nvalues = 1;
#line 98
		return __value0;
#line 98
	}

}

int
ecl_string_case(cl_object s)
{
	int upcase;
	cl_index i;
	const ecl_base_char *text = (ecl_base_char*)s->base_string.self;
	for (i = 0, upcase = 0; i <= s->base_string.dim; i++) {
		if (ecl_upper_case_p(text[i])) {
			if (upcase < 0)
				return 0;
			upcase = +1;
		} else if (ecl_lower_case_p(text[i])) {
			if (upcase > 0)
				return 0;
			upcase = -1;
		}
	}
	return upcase;
}

#line 121
cl_object cl_digit_char_p(cl_narg narg, cl_object c, ...)
{
#line 121

#line 122
	const cl_env_ptr the_env = ecl_process_env();
#line 122
	cl_object radix;
#line 122
	va_list ARGS;
	va_start(ARGS, c);
#line 122
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(302));
#line 122
	if (narg > 1) {
#line 122
		radix = va_arg(ARGS,cl_object);
#line 122
	} else {
#line 122
		radix = ecl_make_fixnum(10);
#line 122
	}
#line 122
{
	cl_fixnum basis, value;
        if (ecl_unlikely(!ECL_FIXNUMP(radix) ||
                         ecl_fixnum_lower(radix, ecl_make_fixnum(2)) ||
                         ecl_fixnum_greater(radix, ecl_make_fixnum(36)))) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*DIGIT-CHAR-P*/302), 2, radix,
                                     ecl_make_integer_type(ecl_make_fixnum(2),
                                                           ecl_make_fixnum(36)));
        }
        basis = ecl_fixnum(radix);
	value = ecl_digitp(ecl_char_code(c), basis);
	{
#line 133
		#line 133
		cl_object __value0 = ((value < 0)? ECL_NIL: ecl_make_fixnum(value));
#line 133
		the_env->nvalues = 1;
#line 133
		return __value0;
#line 133
	}
;
} }

/*
	Ecl_Digitp(i, r) returns the weight of code i
	as a digit of radix r, which must be 1 < r <= 36.
	If i is not a digit, -1 is returned.
*/
int
ecl_digitp(ecl_character i, int r)
{
	if (('0' <= i) && (i <= '9') && (i < '0' + r))
		return i - '0';
	if (('A' <= i) && (10 < r) && (i < 'A' + (r - 10)))
		return i - 'A' + 10;
	if (('a' <= i) && (10 < r) && (i < 'a' + (r - 10)))
		return i - 'a' + 10;
#ifdef ECL_UNICODE
	if (i > 255) {
		int number = ucd_decimal_digit(i);
		if (number < r)
			return number;
	}
#endif
	return -1;
}

cl_object
cl_alphanumericp(cl_object c)
{
	/* INV: ecl_char_code() checks type of `c' */
	cl_fixnum i = ecl_char_code(c);
	{
#line 165
		const cl_env_ptr the_env = ecl_process_env();
#line 165
		#line 165
		cl_object __value0 = (ecl_alphanumericp(i)? ECL_T : ECL_NIL);
#line 165
		the_env->nvalues = 1;
#line 165
		return __value0;
#line 165
	}

}

#line 168
cl_object cl_charE(cl_narg narg, cl_object c, ...)
{
#line 168

#line 170
	const cl_env_ptr the_env = ecl_process_env();
#line 170
	ecl_va_list cs;
	ecl_va_start(cs, c, narg, 1);
#line 170
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(219));
#line 170
	/* INV: ecl_char_eq() checks types of `c' and `cs' */
	while (--narg)
		if (!ecl_char_eq(c, ecl_va_arg(cs)))
			{
#line 173
				#line 173
				cl_object __value0 = ECL_NIL;
#line 173
				the_env->nvalues = 1;
#line 173
				return __value0;
#line 173
			}

	{
#line 174
		#line 174
		cl_object __value0 = ECL_T;
#line 174
		the_env->nvalues = 1;
#line 174
		return __value0;
#line 174
	}

}

bool
ecl_char_eq(cl_object x, cl_object y)
{
	return ecl_char_code(x) == ecl_char_code(y);
}

#line 183
cl_object cl_charNE(cl_narg narg, ...)
{
#line 183

	int i, j;
	cl_object c;
#line 187
	const cl_env_ptr the_env = ecl_process_env();
#line 187
	ecl_va_list cs;
	ecl_va_start(cs, narg, narg, 0);
#line 187
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(216));
#line 187
	/* INV: ecl_char_eq() checks types of its arguments */
	if (narg == 0)
		FEwrong_num_arguments(ecl_make_fixnum(/*CHAR/=*/216));
	c = ecl_va_arg(cs);
	for (i = 2; i<=narg; i++) {
		ecl_va_list ds;
		ecl_va_start(ds, narg, narg, 0);
		c = ecl_va_arg(cs);
		for (j = 1; j<i; j++)
			if (ecl_char_eq(ecl_va_arg(ds), c))
				{
#line 197
					#line 197
					cl_object __value0 = ECL_NIL;
#line 197
					the_env->nvalues = 1;
#line 197
					return __value0;
#line 197
				}

	}
	{
#line 199
		#line 199
		cl_object __value0 = ECL_T;
#line 199
		the_env->nvalues = 1;
#line 199
		return __value0;
#line 199
	}

}

static cl_object
Lchar_cmp(cl_env_ptr env, cl_narg narg, int s, int t, ecl_va_list args)
{
	cl_object c, d;

	if (narg == 0)
		FEwrong_num_arguments_anonym();
	c = ecl_va_arg(args);
	for (; --narg; c = d) {
		d = ecl_va_arg(args);
		if (s*ecl_char_cmp(d, c) < t)
			ecl_return1(env, ECL_NIL);
	}
	ecl_return1(env, ECL_T);
}

int
ecl_char_cmp(cl_object x, cl_object y)
{
	/* ecl_char_code(x) returns an integer which is well in the range
	 * of positive fixnums. Therefore, this subtraction never
	 * oveflows. */
	return ecl_char_code(x) - ecl_char_code(y);
}

#line 227
cl_object cl_charL(cl_narg narg, ...)
{
#line 227

#line 229
	const cl_env_ptr the_env = ecl_process_env();
#line 229
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 229
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(217));
#line 229
	return Lchar_cmp(the_env, narg, 1, 1, args);
}

#line 232
cl_object cl_charG(cl_narg narg, ...)
{
#line 232

#line 234
	const cl_env_ptr the_env = ecl_process_env();
#line 234
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 234
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(220));
#line 234
	return Lchar_cmp(the_env, narg,-1, 1, args);
}

#line 237
cl_object cl_charLE(cl_narg narg, ...)
{
#line 237

#line 239
	const cl_env_ptr the_env = ecl_process_env();
#line 239
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 239
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(218));
#line 239
	return Lchar_cmp(the_env, narg, 1, 0, args);
}

#line 242
cl_object cl_charGE(cl_narg narg, ...)
{
#line 242

#line 244
	const cl_env_ptr the_env = ecl_process_env();
#line 244
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 244
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(221));
#line 244
	return Lchar_cmp(the_env, narg,-1, 0, args);
}

#line 247
cl_object cl_char_equal(cl_narg narg, cl_object c, ...)
{
#line 247

	int i;
#line 250
	const cl_env_ptr the_env = ecl_process_env();
#line 250
	ecl_va_list cs;
	ecl_va_start(cs, c, narg, 1);
#line 250
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(207));
#line 250
	/* INV: ecl_char_equal() checks the type of its arguments */
	for (narg--, i = 0;  i < narg;  i++) {
		if (!ecl_char_equal(c, ecl_va_arg(cs)))
			{
#line 253
				#line 253
				cl_object __value0 = ECL_NIL;
#line 253
				the_env->nvalues = 1;
#line 253
				return __value0;
#line 253
			}

	}
	{
#line 255
		#line 255
		cl_object __value0 = ECL_T;
#line 255
		the_env->nvalues = 1;
#line 255
		return __value0;
#line 255
	}

}

#define char_equal_code(x) ecl_char_upcase(ecl_char_code(x))

bool
ecl_char_equal(cl_object x, cl_object y)
{
	return char_equal_code(x) == char_equal_code(y);
}

#line 266
cl_object cl_char_not_equal(cl_narg narg, ...)
{
#line 266

	int i, j;
	cl_object c;
#line 270
	const cl_env_ptr the_env = ecl_process_env();
#line 270
	ecl_va_list cs;
	ecl_va_start(cs, narg, narg, 0);
#line 270
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(212));
#line 270
	/* INV: ecl_char_equal() checks the type of its arguments */
	if (narg == 0)
		FEwrong_num_arguments(ecl_make_fixnum(/*CHAR-NOT-EQUAL*/212));
	c = ecl_va_arg(cs);
	for (i = 2;  i<=narg;  i++) {
		ecl_va_list ds;
		ecl_va_start(ds, narg, narg, 0);
		c = ecl_va_arg(cs);
		for (j=1;  j<i;  j++)
			if (ecl_char_equal(c, ecl_va_arg(ds)))
				{
#line 280
					#line 280
					cl_object __value0 = ECL_NIL;
#line 280
					the_env->nvalues = 1;
#line 280
					return __value0;
#line 280
				}

	}
	{
#line 282
		#line 282
		cl_object __value0 = ECL_T;
#line 282
		the_env->nvalues = 1;
#line 282
		return __value0;
#line 282
	}

}

static cl_object
Lchar_compare(cl_env_ptr env, cl_narg narg, int s, int t, ecl_va_list args)
{
	cl_object c, d;

	/* INV: ecl_char_compare() checks the types of its arguments */
	if (narg == 0)
		FEwrong_num_arguments_anonym();
	c = ecl_va_arg(args);
	for (; --narg; c = d) {
		d = ecl_va_arg(args);
		if (s*ecl_char_compare(d, c) < t)
			ecl_return1(env, ECL_NIL);
	}
	ecl_return1(env, ECL_T);
}

int
ecl_char_compare(cl_object x, cl_object y)
{
	cl_fixnum i = char_equal_code(x);
	cl_fixnum j = char_equal_code(y);

	if (i < j)
		return(-1);
	else if (i == j)
		return(0);
	else
		return(1);
}

#line 316
cl_object cl_char_lessp(cl_narg narg, ...)
{
#line 316

#line 318
	const cl_env_ptr the_env = ecl_process_env();
#line 318
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 318
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(210));
#line 318
	return Lchar_compare(the_env, narg, 1, 1, args);
}

#line 321
cl_object cl_char_greaterp(cl_narg narg, ...)
{
#line 321

#line 323
	const cl_env_ptr the_env = ecl_process_env();
#line 323
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 323
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(208));
#line 323
	return Lchar_compare(the_env, narg,-1, 1, args);
}

#line 326
cl_object cl_char_not_greaterp(cl_narg narg, ...)
{
#line 326

#line 328
	const cl_env_ptr the_env = ecl_process_env();
#line 328
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 328
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(213));
#line 328
	return Lchar_compare(the_env, narg, 1, 0, args);
}

#line 331
cl_object cl_char_not_lessp(cl_narg narg, ...)
{
#line 331

#line 333
	const cl_env_ptr the_env = ecl_process_env();
#line 333
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 333
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(214));
#line 333
	return Lchar_compare(the_env, narg,-1, 0, args);
}


cl_object
cl_character(cl_object x)
{
	switch (ecl_t_of(x)) {
	case t_character:
		break;
	case t_symbol:
		return cl_character(x->symbol.name);
#ifdef ECL_UNICODE
	case t_string:
		if (x->string.fillp == 1) {
			x = ECL_CODE_CHAR(x->string.self[0]);
			break;
		}
		goto ERROR;
#endif
	case t_base_string:
		if (x->base_string.fillp == 1) {
			x = ECL_CODE_CHAR(x->base_string.self[0]);
			break;
		}
	default: ERROR:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*CHARACTER*/222), 1, x, ecl_read_from_cstring("(OR CHARACTER SYMBOL (ARRAY CHARACTER (1)) (ARRAY BASE-CHAR (1)))"));
	}
	{
#line 361
		const cl_env_ptr the_env = ecl_process_env();
#line 361
		#line 361
		cl_object __value0 = x;
#line 361
		the_env->nvalues = 1;
#line 361
		return __value0;
#line 361
	}

}

cl_object
cl_char_code(cl_object c)
{
	/* INV: ecl_char_code() checks the type of `c' */
	{
#line 368
		const cl_env_ptr the_env = ecl_process_env();
#line 368
		#line 368
		cl_object __value0 = ecl_make_fixnum(ecl_char_code(c));
#line 368
		the_env->nvalues = 1;
#line 368
		return __value0;
#line 368
	}

}

cl_object
cl_code_char(cl_object c)
{
	cl_fixnum fc;

	switch (ecl_t_of(c)) {
	case t_fixnum:
		fc = ecl_fixnum(c);
		if (fc < ECL_CHAR_CODE_LIMIT && fc >= 0) {
			c = ECL_CODE_CHAR(fc);
			break;
		}
	case t_bignum:
		c = ECL_NIL;
		break;
	default:
                FEwrong_type_only_arg(ecl_make_fixnum(/*CODE-CHAR*/230), c, ecl_make_fixnum(/*INTEGER*/437));
	}
	{
#line 389
		const cl_env_ptr the_env = ecl_process_env();
#line 389
		#line 389
		cl_object __value0 = c;
#line 389
		the_env->nvalues = 1;
#line 389
		return __value0;
#line 389
	}

}

cl_object
cl_char_upcase(cl_object c)
{
	/* INV: ecl_char_code() checks the type of `c' */
	cl_fixnum code = ecl_char_code(c);
	{
#line 397
		const cl_env_ptr the_env = ecl_process_env();
#line 397
		#line 397
		cl_object __value0 = ECL_CODE_CHAR(ecl_char_upcase(code));
#line 397
		the_env->nvalues = 1;
#line 397
		return __value0;
#line 397
	}

}

cl_object
cl_char_downcase(cl_object c)
{
	/* INV: ecl_char_code() checks the type of `c' */
	cl_fixnum code = ecl_char_code(c);
	{
#line 405
		const cl_env_ptr the_env = ecl_process_env();
#line 405
		#line 405
		cl_object __value0 = ECL_CODE_CHAR(ecl_char_downcase(code));
#line 405
		the_env->nvalues = 1;
#line 405
		return __value0;
#line 405
	}

}

#line 408
cl_object cl_digit_char(cl_narg narg, cl_object weight, ...)
{
#line 408

#line 409
	const cl_env_ptr the_env = ecl_process_env();
#line 409
	cl_object radix;
#line 409
	va_list ARGS;
	va_start(ARGS, weight);
#line 409
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(301));
#line 409
	if (narg > 1) {
#line 409
		radix = va_arg(ARGS,cl_object);
#line 409
	} else {
#line 409
		radix = ecl_make_fixnum(10);
#line 409
	}
#line 409
{
        cl_fixnum basis;
        cl_object output = ECL_NIL;
        if (ecl_unlikely(!ECL_FIXNUMP(radix) ||
                         ecl_fixnum_lower(radix, ecl_make_fixnum(2)) ||
                         ecl_fixnum_greater(radix, ecl_make_fixnum(36)))) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*DIGIT-CHAR*/301), 2, radix,
                                     ecl_make_integer_type(ecl_make_fixnum(2),
                                                           ecl_make_fixnum(36)));
        }
        basis = ecl_fixnum(radix);
	switch (ecl_t_of(weight)) {
	case t_fixnum: {
		cl_fixnum value = ecl_fixnum(weight);
		if (value >= 0) {
			int dw = ecl_digit_char(value, basis);
			if (dw >= 0) {
				output = ECL_CODE_CHAR(dw);
			}
		}
		break;
	}
	case t_bignum:
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*DIGIT-CHAR*/301),1,weight,ecl_make_fixnum(/*INTEGER*/437));
	}
	{
#line 436
		#line 436
		cl_object __value0 = output;
#line 436
		the_env->nvalues = 1;
#line 436
		return __value0;
#line 436
	}

} }

short
ecl_digit_char(cl_fixnum w, cl_fixnum r)
{
	if (r < 2 || r > 36 || w < 0 || w >= r)
		return(-1);
	if (w < 10)
		return(w + '0');
	else
		return(w - 10 + 'A');
}

cl_object
cl_char_int(cl_object c)
{
	const cl_env_ptr the_env = ecl_process_env();
	/* INV: ecl_char_code() checks the type of `c' */
	ecl_return1(the_env, ecl_make_fixnum(ecl_char_code(c)));
}

/* here we give every character an implicit name of the form 'u#' where # is a hexadecimal number,
   corresponding to a unicode code point.
   #\u14ea should work, for example
*/

cl_object
cl_char_name(cl_object c)
{
	ecl_character code = ecl_char_code(c);
	cl_object output;
	if (code > 127) {
		ecl_base_char name[8];
                ecl_base_char *start;
                name[7] = 0;
                name[6] = ecl_digit_char(code & 0xF, 16); code >>= 4;
                name[5] = ecl_digit_char(code & 0xF, 16); code >>= 4;
                name[4] = ecl_digit_char(code & 0xF, 16); code >>= 4;
                name[3] = ecl_digit_char(code & 0xF, 16); code >>= 4;
                if (code == 0) {
                        start = name + 2;
                } else {
                        name[2] = ecl_digit_char(code & 0xF, 16); code >>= 4;
                        name[1] = ecl_digit_char(code & 0xF, 16);
                        start = name;
                }
                start[0] = 'U';
		output = make_base_string_copy((const char*)start);
	} else {
		output = ecl_gethash_safe(ecl_make_fixnum(code), cl_core.char_names, ECL_NIL);
	}
	{
#line 488
		const cl_env_ptr the_env = ecl_process_env();
#line 488
		#line 488
		cl_object __value0 = output;
#line 488
		the_env->nvalues = 1;
#line 488
		return __value0;
#line 488
	}
;
}

cl_object
cl_name_char(cl_object name)
{
	cl_object c;
	cl_index l;
	name = cl_string(name);
	c = ecl_gethash_safe(name, cl_core.char_names, ECL_NIL);
        if (c != ECL_NIL) {
                c = ECL_CODE_CHAR(ecl_fixnum(c));
        } else if (ecl_stringp(name) && (l = ecl_length(name))) {
		c = cl_char(name, ecl_make_fixnum(0));
		if (l == 1) {
			(void)0;
		} else if (c != ECL_CODE_CHAR('u') && c != ECL_CODE_CHAR('U')) {
			c = ECL_NIL;
		} else {
			cl_index used_l;
			cl_index end = name->base_string.fillp;
			cl_index real_end = end;
			c = ecl_parse_integer(name, 1, end, &real_end, 16);
			used_l = real_end;
			if (!ECL_FIXNUMP(c) || (used_l == (l - 1))) {
				c = ECL_NIL;
			} else {
				c = ECL_CODE_CHAR(ecl_fixnum(c));
			}
		}
	}
	{
#line 519
		const cl_env_ptr the_env = ecl_process_env();
#line 519
		#line 519
		cl_object __value0 = c;
#line 519
		the_env->nvalues = 1;
#line 519
		return __value0;
#line 519
	}
;
}
