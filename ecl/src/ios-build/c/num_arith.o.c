#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/num_arith.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    num_arith.c  -- Arithmetic operations
*/
/*
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <ecl/ecl.h>
#include <ecl/number.h>
#include <stdlib.h>

cl_object
ecl_integer_divide(cl_object x, cl_object y)
{
	cl_type tx, ty;

	tx = ecl_t_of(x);
	ty = ecl_t_of(y);
	if (tx == t_fixnum) {
 		if (ty == t_fixnum) {
			if (y == ecl_make_fixnum(0))
				FEdivision_by_zero(x, y);
			return ecl_make_fixnum(ecl_fixnum(x) / ecl_fixnum(y));
		} else if (ty == t_bignum) {
                        return _ecl_fix_divided_by_big(ecl_fixnum(x), y);
		} else {
                        FEwrong_type_nth_arg(ecl_make_fixnum(/*ROUND*/730), 2, y, ecl_make_fixnum(/*INTEGER*/437));
                }
	}
	if (tx == t_bignum) {
		if (ty == t_bignum) {
			return _ecl_big_divided_by_big(x, y);
		} else if (ty == t_fixnum) {
                        return _ecl_big_divided_by_fix(x, ecl_fixnum(y));
		} else {
                        FEwrong_type_nth_arg(ecl_make_fixnum(/*ROUND*/730), 2, y, ecl_make_fixnum(/*INTEGER*/437));
		}
	}
        FEwrong_type_nth_arg(ecl_make_fixnum(/*ROUND*/730), 1, x, ecl_make_fixnum(/*INTEGER*/437));
}

#line 51
cl_object cl_gcd(cl_narg narg, ...)
{
#line 51

	cl_object gcd;
#line 54
	const cl_env_ptr the_env = ecl_process_env();
#line 54
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
#line 54
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(399));
#line 54
	if (narg == 0)
		{
#line 55
			#line 55
			cl_object __value0 = ecl_make_fixnum(0);
#line 55
			the_env->nvalues = 1;
#line 55
			return __value0;
#line 55
		}

	/* INV: ecl_gcd() checks types */
	gcd = ecl_va_arg(nums);
	if (narg == 1) {
		assert_type_integer(gcd);
		{
#line 60
			#line 60
			cl_object __value0 = (ecl_minusp(gcd) ? ecl_negate(gcd) : gcd);
#line 60
			the_env->nvalues = 1;
#line 60
			return __value0;
#line 60
		}

	}
	while (--narg)
		gcd = ecl_gcd(gcd, ecl_va_arg(nums));
	{
#line 64
		#line 64
		cl_object __value0 = gcd;
#line 64
		the_env->nvalues = 1;
#line 64
		return __value0;
#line 64
	}

}

cl_object
ecl_gcd(cl_object x, cl_object y)
{
        ECL_WITH_TEMP_BIGNUM(x_big,1);
        ECL_WITH_TEMP_BIGNUM(y_big,1);

	switch (ecl_t_of(x)) {
	case t_fixnum:
                _ecl_big_set_fixnum(x_big, ecl_fixnum(x));
                x = x_big;
	case t_bignum:
		break;
	default:
		FEwrong_type_nth_arg(ecl_make_fixnum(/*GCD*/399), 1, x, ecl_make_fixnum(/*INTEGER*/437));
	}
	switch (ecl_t_of(y)) {
	case t_fixnum:
                _ecl_big_set_fixnum(y_big, ecl_fixnum(y));
                y = y_big;
	case t_bignum:
                break;
	default:
		FEwrong_type_nth_arg(ecl_make_fixnum(/*GCD*/399), 2, y, ecl_make_fixnum(/*INTEGER*/437));
        }
        return _ecl_big_gcd(x, y);
}

#line 94
cl_object cl_lcm(cl_narg narg, ...)
{
#line 94

	cl_object lcm;
#line 97
	const cl_env_ptr the_env = ecl_process_env();
#line 97
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
#line 97
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(456));
#line 97
	if (narg == 0)
		{
#line 98
			#line 98
			cl_object __value0 = ecl_make_fixnum(1);
#line 98
			the_env->nvalues = 1;
#line 98
			return __value0;
#line 98
		}

	/* INV: ecl_gcd() checks types. By placing `numi' before `lcm' in
	   this call, we make sure that errors point to `numi' */
	lcm = ecl_va_arg(nums);
	assert_type_integer(lcm);
	while (narg-- > 1) {
		cl_object numi = ecl_va_arg(nums);
		cl_object t = ecl_times(lcm, numi);
		cl_object g = ecl_gcd(numi, lcm);
		if (g != ecl_make_fixnum(0))
			lcm = ecl_divide(t, g);
	}
	{
#line 110
		#line 110
		cl_object __value0 = (ecl_minusp(lcm) ? ecl_negate(lcm) : lcm);
#line 110
		the_env->nvalues = 1;
#line 110
		return __value0;
#line 110
	}

}
