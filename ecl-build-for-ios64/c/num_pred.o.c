#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/num_pred.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    num_pred.c  -- Predicates on numbers.
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

int
ecl_oddp(cl_object x)
{
	if (ECL_FIXNUMP(x))
		return ecl_fixnum(x) & 1;
	unlikely_if (!ECL_BIGNUMP(x))
                FEwrong_type_only_arg(ecl_make_fixnum(/*ODDP*/610), x, ecl_make_fixnum(/*INTEGER*/437));
        return _ecl_big_odd_p(x);
}

int
ecl_evenp(cl_object x)
{
	if (ECL_FIXNUMP(x))
		return ~ecl_fixnum(x) & 1;
	unlikely_if (!ECL_BIGNUMP(x))
                FEwrong_type_only_arg(ecl_make_fixnum(/*EVENP*/341), x, ecl_make_fixnum(/*INTEGER*/437));
        return _ecl_big_even_p(x);
}

cl_object
cl_oddp(cl_object x)
{	/* INV: ecl_oddp() checks type */
	{
#line 46
		const cl_env_ptr the_env = ecl_process_env();
#line 46
		#line 46
		cl_object __value0 = (ecl_oddp(x) ? ECL_T : ECL_NIL);
#line 46
		the_env->nvalues = 1;
#line 46
		return __value0;
#line 46
	}

}

cl_object
cl_evenp(cl_object x)
{	/* INV: ecl_evenp() checks_type */
	{
#line 52
		const cl_env_ptr the_env = ecl_process_env();
#line 52
		#line 52
		cl_object __value0 = (ecl_evenp(x) ? ECL_T : ECL_NIL);
#line 52
		the_env->nvalues = 1;
#line 52
		return __value0;
#line 52
	}

}

cl_object
si_float_nan_p(cl_object x)
{
	{
#line 58
		const cl_env_ptr the_env = ecl_process_env();
#line 58
		#line 58
		cl_object __value0 = (ecl_float_nan_p(x)? ECL_T : ECL_NIL);
#line 58
		the_env->nvalues = 1;
#line 58
		return __value0;
#line 58
	}

}

cl_object
si_float_infinity_p(cl_object x)
{
	{
#line 64
		const cl_env_ptr the_env = ecl_process_env();
#line 64
		#line 64
		cl_object __value0 = (ecl_float_infinity_p(x)? ECL_T : ECL_NIL);
#line 64
		the_env->nvalues = 1;
#line 64
		return __value0;
#line 64
	}

}

bool
ecl_float_nan_p(cl_object x)
{
	return !ecl_number_equalp(x,x);
}

bool
ecl_float_infinity_p(cl_object x)
{
	switch (ecl_t_of(x)) {
	case t_singlefloat:
		return !isfinite(ecl_single_float(x));
	case t_doublefloat:
		return !isfinite(ecl_double_float(x));
#ifdef ECL_LONG_FLOAT
	case t_longfloat:
		return !isfinite(ecl_long_float(x));
#endif
	default:
		return 0;
	}
}
