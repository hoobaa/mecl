#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/numbers/plus.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    plus.d  -- Implementation of CL:+
*/
/*
    Copyright (c) 2010, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../../Copyright' for full details.
*/

#include <ecl/ecl.h>
#include <ecl/impl/math_dispatch2.h>

// ------------------------------1
#line 19
cl_object cl_P(cl_narg narg, ...)
{
#line 19
// ------------------------------2
#line 19
	const cl_env_ptr the_env = ecl_process_env();
#line 19
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
#line 19
// ------------------------------3

	cl_object sum = ecl_make_fixnum(0);
#line 22
// ------------------------------4
#line 22
#line 22
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(14));
#line 22
// ------------------------------5
  nlogd("c_PL");
	/* INV: type check is in ecl_plus() */
	while (narg--)
		sum = ecl_plus(sum, ecl_va_arg(nums));
	{
#line 26
		#line 26
		cl_object __value0 = sum;
#line 26
		the_env->nvalues = 1;
#line 26
		return __value0;
#line 26
	}

}

#ifdef MATH_DISPATCH2_BEGIN

cl_object
ecl_plus(cl_object x, cl_object y)
{
        nlogd(">fix plus1");
MATH_DISPATCH2_BEGIN(x,y)
{
        nlogd(">fix plus2");

        CASE_FIXNUM_FIXNUM {
                nlogd(">fix plus");
                return ecl_make_integer(ecl_fixnum(x) + ecl_fixnum(y));
        }
        CASE_FIXNUM_BIGNUM {
                return _ecl_big_plus_fix(y, ecl_fixnum(x));
        }
        CASE_FIXNUM_RATIO;
        CASE_BIGNUM_RATIO {
                cl_object z = ecl_times(x, y->ratio.den);
                z = ecl_plus(z, y->ratio.num);
                return ecl_make_ratio(z, y->ratio.den);
        }
        CASE_FIXNUM_SINGLE_FLOAT {
                return ecl_make_single_float(ecl_fixnum(x) + ecl_single_float(y));
        }
        CASE_FIXNUM_DOUBLE_FLOAT {
                return ecl_make_double_float(ecl_fixnum(x) + ecl_double_float(y));
        }
        CASE_BIGNUM_FIXNUM {
                return _ecl_big_plus_fix(x, ecl_fixnum(y));
        }
        CASE_BIGNUM_BIGNUM {
                return _ecl_big_plus_big(x, y);
        }
        CASE_BIGNUM_SINGLE_FLOAT;
        CASE_RATIO_SINGLE_FLOAT {
                return ecl_make_single_float(ecl_to_float(x) + ecl_single_float(y));
        }
        CASE_BIGNUM_DOUBLE_FLOAT;
        CASE_RATIO_DOUBLE_FLOAT {
                return ecl_make_double_float(ecl_to_double(x) + ecl_double_float(y));
        }
        CASE_RATIO_FIXNUM;
        CASE_RATIO_BIGNUM {
                cl_object z = ecl_times(x->ratio.den, y);
                z = ecl_plus(x->ratio.num, z);
                return ecl_make_ratio(z, x->ratio.den);
        }
        CASE_RATIO_RATIO {
                cl_object z1 = ecl_times(x->ratio.num,y->ratio.den);
                cl_object z = ecl_times(x->ratio.den,y->ratio.num);
                z = ecl_plus(z1, z);
                z1 = ecl_times(x->ratio.den,y->ratio.den);
                return ecl_make_ratio(z, z1);
        }
        CASE_SINGLE_FLOAT_FIXNUM {
                return ecl_make_single_float(ecl_single_float(x) + ecl_fixnum(y));
        }
        CASE_SINGLE_FLOAT_BIGNUM;
        CASE_SINGLE_FLOAT_RATIO {
                return ecl_make_single_float(ecl_single_float(x) + ecl_to_float(y));
        }
        CASE_SINGLE_FLOAT_SINGLE_FLOAT {
                return ecl_make_single_float(ecl_single_float(x) + ecl_single_float(y));
        }
        CASE_SINGLE_FLOAT_DOUBLE_FLOAT {
                return ecl_make_double_float(ecl_single_float(x) + ecl_double_float(y));
        }
        CASE_DOUBLE_FLOAT_FIXNUM {
                return ecl_make_double_float(ecl_double_float(x) + ecl_fixnum(y));
        }
        CASE_DOUBLE_FLOAT_BIGNUM;
        CASE_DOUBLE_FLOAT_RATIO {
                return ecl_make_double_float(ecl_double_float(x) + ecl_to_double(y));
        }
        CASE_DOUBLE_FLOAT_SINGLE_FLOAT {
                return ecl_make_double_float(ecl_double_float(x) + ecl_single_float(y));
        }
        CASE_DOUBLE_FLOAT_DOUBLE_FLOAT {
                return ecl_make_double_float(ecl_double_float(x) + ecl_double_float(y));
        }
#ifdef ECL_LONG_FLOAT
        CASE_FIXNUM_LONG_FLOAT {
                return ecl_make_long_float(ecl_fixnum(x) + ecl_long_float(y));
        }
        CASE_BIGNUM_LONG_FLOAT {
                return ecl_make_long_float(ecl_to_long_double(x) + ecl_long_float(y));
        }
        CASE_RATIO_LONG_FLOAT {
                return ecl_make_long_float(ecl_to_long_double(x) + ecl_long_float(y));
        }
        CASE_SINGLE_FLOAT_LONG_FLOAT {
                return ecl_make_long_float(ecl_single_float(x) + ecl_long_float(y));
        }
        CASE_DOUBLE_FLOAT_LONG_FLOAT {
                return ecl_make_long_float(ecl_double_float(x) + ecl_long_float(y));
        }
        CASE_LONG_FLOAT_FIXNUM {
                return ecl_make_long_float(ecl_long_float(x) + ecl_fixnum(y));
        }
        CASE_LONG_FLOAT_BIGNUM;
        CASE_LONG_FLOAT_RATIO {
                return ecl_make_long_float(ecl_long_float(x) + ecl_to_long_double(y));
        }
        CASE_LONG_FLOAT_SINGLE_FLOAT {
                return ecl_make_long_float(ecl_long_float(x) + ecl_single_float(y));
        }
        CASE_LONG_FLOAT_DOUBLE_FLOAT {
                return ecl_make_long_float(ecl_long_float(x) + ecl_double_float(y));
        }
        CASE_LONG_FLOAT_LONG_FLOAT {
                return ecl_make_long_float(ecl_long_float(x) + ecl_long_float(y));
        }
        CASE_LONG_FLOAT_COMPLEX {
                goto COMPLEX_Y;
        }
        CASE_COMPLEX_LONG_FLOAT;  {
                goto COMPLEX_X;
        }
#endif
        CASE_COMPLEX_FIXNUM;
        CASE_COMPLEX_BIGNUM;
        CASE_COMPLEX_RATIO;
        CASE_COMPLEX_SINGLE_FLOAT;
        CASE_COMPLEX_DOUBLE_FLOAT; COMPLEX_X: {
                cl_object aux = x;
                x = y; y = aux;
                goto COMPLEX_Y;
        }
        CASE_BIGNUM_COMPLEX;
        CASE_RATIO_COMPLEX;
        CASE_SINGLE_FLOAT_COMPLEX;
        CASE_DOUBLE_FLOAT_COMPLEX;
        CASE_FIXNUM_COMPLEX {
        COMPLEX_Y:
                return ecl_make_complex(ecl_plus(x, y->complex.real),
                                        y->complex.imag);
        }
        CASE_COMPLEX_COMPLEX {
                cl_object z = ecl_plus(x->complex.real, y->complex.real);
		cl_object z1 = ecl_plus(x->complex.imag, y->complex.imag);
		return ecl_make_complex(z, z1);
        }
        CASE_UNKNOWN(ecl_make_fixnum(/*+*/14),x,y,ecl_make_fixnum(/*NUMBER*/606));
}
MATH_DISPATCH2_END;
}

#else

cl_object
ecl_plus(cl_object x, cl_object y)
{
	cl_fixnum i, j;
	cl_object z, z1;

	switch (ecl_t_of(x)) {
	case t_fixnum:
	        switch (ecl_t_of(y)) {
		case t_fixnum:
                        return ecl_make_integer(ecl_fixnum(x) + ecl_fixnum(y));
		case t_bignum:
                        return _ecl_big_plus_fix(y, ecl_fixnum(x));
		case t_ratio:
			z = ecl_times(x, y->ratio.den);
			z = ecl_plus(z, y->ratio.num);
			return ecl_make_ratio(z, y->ratio.den);
		case t_singlefloat:
			return ecl_make_single_float(ecl_fixnum(x) + ecl_single_float(y));
		case t_doublefloat:
			return ecl_make_double_float(ecl_fixnum(x) + ecl_double_float(y));
#ifdef ECL_LONG_FLOAT
		case t_longfloat:
			return ecl_make_long_float(ecl_fixnum(x) + ecl_long_float(y));
#endif
		case t_complex:
		COMPLEX: /* INV: x is real, y is complex */
			return ecl_make_complex(ecl_plus(x, y->complex.real),
					    y->complex.imag);
		default:
			FEwrong_type_nth_arg(ecl_make_fixnum(/*+*/14), 2, y, ecl_make_fixnum(/*NUMBER*/606));
		}
	case t_bignum:
		switch (ecl_t_of(y)) {
		case t_fixnum:
                        return _ecl_big_plus_fix(x, ecl_fixnum(y));
		case t_bignum:
                        return _ecl_big_plus_big(x, y);
		case t_ratio:
			z = ecl_times(x, y->ratio.den);
			z = ecl_plus(z, y->ratio.num);
			return ecl_make_ratio(z, y->ratio.den);
		case t_singlefloat:
			return ecl_make_single_float(ecl_to_double(x) + ecl_single_float(y));
		case t_doublefloat:
			return ecl_make_double_float(ecl_to_double(x) + ecl_double_float(y));
#ifdef ECL_LONG_FLOAT
		case t_longfloat:
			return ecl_make_long_float(ecl_to_double(x) + ecl_long_float(y));
#endif
		case t_complex:
			goto COMPLEX;
		default:
			FEwrong_type_nth_arg(ecl_make_fixnum(/*+*/14), 2, y, ecl_make_fixnum(/*NUMBER*/606));
		}
	case t_ratio:
		switch (ecl_t_of(y)) {
		case t_fixnum:
		case t_bignum:
			z = ecl_times(x->ratio.den, y);
			z = ecl_plus(x->ratio.num, z);
			return ecl_make_ratio(z, x->ratio.den);
		case t_ratio:
			z1 = ecl_times(x->ratio.num,y->ratio.den);
			z = ecl_times(x->ratio.den,y->ratio.num);
			z = ecl_plus(z1, z);
			z1 = ecl_times(x->ratio.den,y->ratio.den);
			return ecl_make_ratio(z, z1);
		case t_singlefloat:
			return ecl_make_single_float(ecl_to_double(x) + ecl_single_float(y));
		case t_doublefloat:
			return ecl_make_double_float(ecl_to_double(x) + ecl_double_float(y));
#ifdef ECL_LONG_FLOAT
		case t_longfloat:
			return ecl_make_long_float(ecl_to_double(x) + ecl_long_float(y));
#endif
		case t_complex:
			goto COMPLEX;
		default:
			FEwrong_type_nth_arg(ecl_make_fixnum(/*+*/14), 2, y, ecl_make_fixnum(/*NUMBER*/606));
		}
	case t_singlefloat:
		switch (ecl_t_of(y)) {
		case t_fixnum:
			return ecl_make_single_float(ecl_single_float(x) + ecl_fixnum(y));
		case t_bignum:
		case t_ratio:
			return ecl_make_single_float(ecl_single_float(x) + ecl_to_double(y));
		case t_singlefloat:
			return ecl_make_single_float(ecl_single_float(x) + ecl_single_float(y));
		case t_doublefloat:
			return ecl_make_double_float(ecl_single_float(x) + ecl_double_float(y));
#ifdef ECL_LONG_FLOAT
		case t_longfloat:
			return ecl_make_long_float(ecl_single_float(x) + ecl_long_float(y));
#endif
		case t_complex:
			goto COMPLEX;
		default:
			FEwrong_type_nth_arg(ecl_make_fixnum(/*+*/14), 2, y, ecl_make_fixnum(/*NUMBER*/606));
		}
	case t_doublefloat:
		switch (ecl_t_of(y)) {
		case t_fixnum:
			return ecl_make_double_float(ecl_double_float(x) + ecl_fixnum(y));
		case t_bignum:
		case t_ratio:
			return ecl_make_double_float(ecl_double_float(x) + ecl_to_double(y));
		case t_singlefloat:
			return ecl_make_double_float(ecl_double_float(x) + ecl_single_float(y));
		case t_doublefloat:
			return ecl_make_double_float(ecl_double_float(x) + ecl_double_float(y));
#ifdef ECL_LONG_FLOAT
		case t_longfloat:
			return ecl_make_long_float(ecl_double_float(x) + ecl_long_float(y));
#endif
		case t_complex:
			goto COMPLEX;
		default:
			FEwrong_type_nth_arg(ecl_make_fixnum(/*+*/14), 2, y, ecl_make_fixnum(/*NUMBER*/606));
		}
#ifdef ECL_LONG_FLOAT
	case t_longfloat:
		switch (ecl_t_of(y)) {
		case t_fixnum:
			return ecl_make_long_float(ecl_long_float(x) + ecl_fixnum(y));
		case t_bignum:
		case t_ratio:
			return ecl_make_long_float(ecl_long_float(x) + ecl_to_double(y));
		case t_singlefloat:
			return ecl_make_long_float(ecl_long_float(x) + ecl_single_float(y));
		case t_doublefloat:
			return ecl_make_long_float(ecl_long_float(x) + ecl_double_float(y));
		case t_longfloat:
			return ecl_make_long_float(ecl_long_float(x) + ecl_long_float(y));
		case t_complex:
			goto COMPLEX;
		default:
			FEwrong_type_nth_arg(ecl_make_fixnum(/*+*/14), 2, y, ecl_make_fixnum(/*NUMBER*/606));
		}
#endif
	case t_complex:
		if (ecl_t_of(y) != t_complex) {
			cl_object aux = x;
			x = y; y = aux;
			goto COMPLEX;
		}
		z = ecl_plus(x->complex.real, y->complex.real);
		z1 = ecl_plus(x->complex.imag, y->complex.imag);
		return ecl_make_complex(z, z1);
	default:
		FEwrong_type_nth_arg(ecl_make_fixnum(/*+*/14), 1, x, ecl_make_fixnum(/*NUMBER*/606));
	}
}
#endif
