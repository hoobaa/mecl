#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/numbers/tan.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    tan.d  -- Trascendental functions: tangent
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

/*
 * As of 2006-10-13 I found this bug in GLIBC's tanf, which overflows
 * when the argument is pi/4. It is 2008 and this has not yet been
 * solved. Not only that, but if we use tan() on float, GCC automatically
 * and stupidly forces the use of tanf().
 */
#if defined(__amd64__) && defined(__GLIBC__)
static double safe_tanf(double x) { return tan(x); }
#else
# define safe_tanf(x) tanf(x)
#endif

cl_object
cl_tan(cl_object x)
{
        {
#line 40
	const cl_env_ptr the_env = ecl_process_env();
#line 40
	#line 40
	cl_object __value0 = ecl_tan(x);
#line 40
	the_env->nvalues = 1;
#line 40
	return __value0;
#line 40
}
;
}

static cl_object
ecl_tan_rational(cl_object x)
{
        return ecl_make_single_float(safe_tanf(ecl_to_float(x)));
}

static cl_object
ecl_tan_single_float(cl_object x)
{
        return ecl_make_single_float(safe_tanf(ecl_single_float(x)));
}

static cl_object
ecl_tan_double_float(cl_object x)
{
        return ecl_make_double_float(tan(ecl_double_float(x)));
}

#ifdef ECL_LONG_FLOAT
static cl_object
ecl_tan_long_float(cl_object x)
{
        return ecl_make_long_float(tanl(ecl_long_float(x)));
}
#endif

static cl_object
ecl_tan_complex(cl_object x)
{
        cl_object a = ecl_sin(x);
        cl_object b = ecl_cos(x);
        return ecl_divide(a, b);
}

MATH_DEF_DISPATCH1(tan, ecl_make_fixnum(/*TAN*/852), ecl_make_fixnum(/*NUMBER*/606),
                   ecl_tan_rational, ecl_tan_rational, ecl_tan_rational,
                   ecl_tan_single_float, ecl_tan_double_float, ecl_tan_long_float,
                   ecl_tan_complex);
