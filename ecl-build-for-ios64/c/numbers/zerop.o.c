#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/numbers/zerop.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    zerop.d  -- Implementation of CL:ZEROP
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

cl_object
cl_zerop(cl_object x)
{	/* INV: ecl_zerop() checks type */
	{
#line 24
		const cl_env_ptr the_env = ecl_process_env();
#line 24
		#line 24
		cl_object __value0 = (ecl_zerop(x) ? ECL_T : ECL_NIL);
#line 24
		the_env->nvalues = 1;
#line 24
		return __value0;
#line 24
	}

}

static int
ecl_zerop_fixnum(cl_object x)
{
        return x == ecl_make_fixnum(0);
}

static int
ecl_zerop_ratio(cl_object x)
{
        return 0;
}

static int
ecl_zerop_single_float(cl_object x)
{
        return ecl_single_float(x) == 0;
}

static int
ecl_zerop_double_float(cl_object x)
{
        return ecl_double_float(x) == 0;
}

#ifdef ECL_LONG_FLOAT
static int ecl_zerop_long_float(cl_object x)
{
        return ecl_long_float(x) == 0;
}
#endif

static int
ecl_zerop_complex(cl_object x)
{
        return ecl_zerop(x->complex.real) && ecl_zerop(x->complex.imag);
}

MATH_DEF_DISPATCH1_BOOL(zerop, ecl_make_fixnum(/*ZEROP*/926), ecl_make_fixnum(/*NUMBER*/606),
                        ecl_zerop_fixnum, ecl_zerop_ratio, ecl_zerop_ratio,
                        ecl_zerop_single_float, ecl_zerop_double_float,
                        ecl_zerop_long_float,
                        ecl_zerop_complex)
