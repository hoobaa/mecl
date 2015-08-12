#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/numbers/cos.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    cos.d  -- Trascendental functions: cosine
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

#define ECL_INCLUDE_MATH_H
#include <ecl/ecl.h>
#include <ecl/internal.h>
#include <ecl/impl/math_dispatch.h>

#pragma STDC FENV_ACCESS ON

cl_object
cl_cos(cl_object x)
{
        {
#line 28
	const cl_env_ptr the_env = ecl_process_env();
#line 28
	#line 28
	cl_object __value0 = ecl_cos(x);
#line 28
	the_env->nvalues = 1;
#line 28
	return __value0;
#line 28
}
;
}

static cl_object
ecl_cos_rational(cl_object x)
{
        return ecl_make_single_float(cosf(ecl_to_float(x)));
}

static cl_object
ecl_cos_single_float(cl_object x)
{
        return ecl_make_single_float(cosf(ecl_single_float(x)));
}

static cl_object
ecl_cos_double_float(cl_object x)
{
        return ecl_make_double_float(cos(ecl_double_float(x)));
}

#ifdef ECL_LONG_FLOAT
static cl_object
ecl_cos_long_float(cl_object x)
{
        return ecl_make_long_float(cosl(ecl_long_float(x)));
}
#endif

static cl_object
ecl_cos_complex(cl_object x)
{
	/* z = x + I y
           cos(z) = cosh(I z) = cosh(-y + I x)
        */
        cl_object dx = x->complex.real;
        cl_object dy = x->complex.imag;
        cl_object a = ecl_times(ecl_cos(dx), ecl_cosh(dy));
        cl_object b = ecl_times(ecl_negate(ecl_sin(dx)), ecl_sinh(dy));
        return ecl_make_complex(a, b);
}

MATH_DEF_DISPATCH1(cos, ecl_make_fixnum(/*COS*/264), ecl_make_fixnum(/*NUMBER*/606),
                   ecl_cos_rational, ecl_cos_rational, ecl_cos_rational,
                   ecl_cos_single_float, ecl_cos_double_float, ecl_cos_long_float,
                   ecl_cos_complex);
