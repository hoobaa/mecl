#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/reader/parse_integer.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../../Copyright' for full details.
*/

#include <ecl/ecl.h>
#include <ecl/number.h>
#include <ecl/internal.h>

#define basep(d) (d <= 36)

cl_object
ecl_parse_integer(cl_object str, cl_index start, cl_index end,
		  cl_index *ep, unsigned int radix)
{
	int sign, d;
	cl_object integer_part, output;
	cl_index i, c;

	if (start >= end || !basep(radix)) {
		*ep = start;
		return OBJNULL;
	}
	sign = 1;
	c = ecl_char(str, start);
	if (c == '+') {
		start++;
	} else if (c == '-') {
		sign = -1;
		start++;
	}
	integer_part = _ecl_big_register0();
        _ecl_big_set_ui(integer_part, 0);
	for (i = start; i < end; i++) {
		c = ecl_char(str, i);
		d = ecl_digitp(c, radix);
		if (d < 0) {
			break;
		}
		_ecl_big_mul_ui(integer_part, integer_part, radix);
		_ecl_big_add_ui(integer_part, integer_part, d);
	}
	if (sign < 0) {
		_ecl_big_complement(integer_part, integer_part);
	}
	output = _ecl_big_register_normalize(integer_part);
	*ep = i;
	return (i == start)? OBJNULL : output;
}

#line 65
cl_object cl_parse_integer(cl_narg narg, cl_object strng, ...)
{
#line 65

	cl_index s, e, ep;
	cl_object rtbl = ecl_current_readtable();
#line 68
	const cl_env_ptr the_env = ecl_process_env();
#line 68
	static cl_object KEYS[4] = {(cl_object)(cl_symbols+1310), (cl_object)(cl_symbols+1225), (cl_object)(cl_symbols+1295), (cl_object)(cl_symbols+1261)};
	cl_object start;
	cl_object end;
	cl_object radix;
	cl_object junk_allowed;
#line 68
	cl_object x;
#line 68
	cl_object KEY_VARS[8];
#line 68
	ecl_va_list ARGS;
	ecl_va_start(ARGS, strng, narg, 1);
#line 68
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(628));
#line 68
	cl_parse_key(ARGS, 4, KEYS, KEY_VARS, NULL, 0);
#line 68
	if (KEY_VARS[4]==ECL_NIL) {
#line 68
	  start = ecl_make_fixnum(0);
	} else {
#line 68
	  start = KEY_VARS[0];
	}
#line 68
	if (KEY_VARS[5]==ECL_NIL) {
#line 68
	  end = ECL_NIL;
	} else {
#line 68
	  end = KEY_VARS[1];
	}
#line 68
	if (KEY_VARS[6]==ECL_NIL) {
#line 68
	  radix = ecl_make_fixnum(10);
	} else {
#line 68
	  radix = KEY_VARS[2];
	}
#line 68
	if (KEY_VARS[7]==ECL_NIL) {
#line 68
	  junk_allowed = ECL_NIL;
	} else {
#line 68
	  junk_allowed = KEY_VARS[3];
	}
#line 68
	x = ECL_NIL;
#line 68
{
        unlikely_if (!ECL_STRINGP(strng)) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*PARSE-INTEGER*/628), 1, strng, ecl_make_fixnum(/*STRING*/805));
        }
	unlikely_if (!ECL_FIXNUMP(radix) ||
                     ecl_fixnum_lower(radix, ecl_make_fixnum(2)) ||
                     ecl_fixnum_greater(radix, ecl_make_fixnum(36)))
        {
		FEerror("~S is an illegal radix.", 1, radix);
        }
        {
                cl_index_pair p =
                        ecl_vector_start_end(ecl_make_fixnum(/*PARSE-INTEGER*/628), strng, start, end);
                s = p.start;
                e = p.end;
        }
	while (s < e &&
	       ecl_readtable_get(rtbl, ecl_char(strng, s), NULL) == cat_whitespace) {
		s++;
	}
	if (s >= e) {
		if (junk_allowed != ECL_NIL)
			{
#line 90
				#line 90
				cl_object __value0 = ECL_NIL;
#line 90
				cl_object __value1 = ecl_make_fixnum(s);
#line 90
				the_env->nvalues = 2;
#line 90
				the_env->values[1] = __value1;
#line 90
				return __value0;
#line 90
			}

		else
			goto CANNOT_PARSE;
	}
	x = ecl_parse_integer(strng, s, e, &ep, ecl_fixnum(radix));
	if (x == OBJNULL) {
		if (junk_allowed != ECL_NIL) {
			{
#line 97
				#line 97
				cl_object __value0 = ECL_NIL;
#line 97
				cl_object __value1 = ecl_make_fixnum(ep);
#line 97
				the_env->nvalues = 2;
#line 97
				the_env->values[1] = __value1;
#line 97
				return __value0;
#line 97
			}
;
		} else {
			goto CANNOT_PARSE;
		}
	}
	if (junk_allowed != ECL_NIL) {
		{
#line 103
			#line 103
			cl_object __value0 = x;
#line 103
			cl_object __value1 = ecl_make_fixnum(ep);
#line 103
			the_env->nvalues = 2;
#line 103
			the_env->values[1] = __value1;
#line 103
			return __value0;
#line 103
		}
;
	}
	for (s = ep; s < e; s++) {
		unlikely_if (ecl_readtable_get(rtbl, ecl_char(strng, s), NULL)
                             != cat_whitespace) 
                {
CANNOT_PARSE:		FEparse_error("Cannot parse an integer in the string ~S.",
				      ECL_NIL, 1, strng);
		}
	}
	{
#line 113
		#line 113
		cl_object __value0 = x;
#line 113
		cl_object __value1 = ecl_make_fixnum(e);
#line 113
		the_env->nvalues = 2;
#line 113
		the_env->values[1] = __value1;
#line 113
		return __value0;
#line 113
	}
;
} }
