#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/numbers/one_minus.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    one_minus.d  -- Implementation of CL:1-
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
#include <ecl/impl/math_dispatch.h>

static cl_object
ecl_one_minus_fix(cl_object x)
{
        if (x == ecl_make_fixnum(MOST_NEGATIVE_FIXNUM))
                return ecl_make_integer(MOST_NEGATIVE_FIXNUM-1);
        return (cl_object)((cl_fixnum)x - ((cl_fixnum)ecl_make_fixnum(1) - ECL_FIXNUM_TAG));
}

static cl_object
ecl_one_minus_big(cl_object x)
{
        return ecl_minus(x, ecl_make_fixnum(1));
}

static cl_object
ecl_one_minus_ratio(cl_object x)
{
        return ecl_make_ratio(ecl_minus(x->ratio.num,x->ratio.den), x->ratio.den);
}

static cl_object
ecl_one_minus_single_float(cl_object x)
{
        return ecl_make_single_float(ecl_single_float(x) - 1);
}

static cl_object
ecl_one_minus_double_float(cl_object x)
{
        return ecl_make_double_float(ecl_double_float(x) - 1);
}

#ifdef ECL_LONG_FLOAT
static cl_object
ecl_one_minus_long_float(cl_object x)
{
        return ecl_make_long_float(ecl_long_float(x) - 1);
}
#endif

static cl_object
ecl_one_minus_complex(cl_object x)
{
        return ecl_make_complex(ecl_one_minus(x->complex.real),
                                x->complex.imag);
}

MATH_DEF_DISPATCH1_NE(one_minus, ecl_make_fixnum(/*1-*/71), ecl_make_fixnum(/*NUMBER*/606),
                      ecl_one_minus_fix, ecl_one_minus_big, ecl_one_minus_ratio,
                      ecl_one_minus_single_float, ecl_one_minus_double_float,
                      ecl_one_minus_long_float,
                      ecl_one_minus_complex);

/*  (1-	x)  */
cl_object
cl_1M(cl_object x)
{	/* INV: type check is in ecl_one_minus() */
	{
#line 78
		const cl_env_ptr the_env = ecl_process_env();
#line 78
		#line 78
		cl_object __value0 = ecl_one_minus(x);
#line 78
		the_env->nvalues = 1;
#line 78
		return __value0;
#line 78
	}

}

