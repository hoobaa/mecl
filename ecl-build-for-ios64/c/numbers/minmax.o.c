#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/numbers/minmax.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    minmax.c  -- number sorting.
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

#line 20
cl_object cl_max(cl_narg narg, cl_object max, ...)
{
#line 20

#line 22
	const cl_env_ptr the_env = ecl_process_env();
#line 22
	ecl_va_list nums;
	ecl_va_start(nums, max, narg, 1);
#line 22
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(551));
#line 22
	/* INV: type check occurs in ecl_number_compare() for the rest of
	   numbers, but for the first argument it happens in ecl_zerop(). */
	if (narg-- == 1) {
		ecl_zerop(max);
	} else do {
		cl_object numi = ecl_va_arg(nums);
		if (ecl_number_compare(max, numi) < 0)
			max = numi;
	} while (--narg);
	{
#line 31
		#line 31
		cl_object __value0 = max;
#line 31
		the_env->nvalues = 1;
#line 31
		return __value0;
#line 31
	}

}

#line 34
cl_object cl_min(cl_narg narg, cl_object min, ...)
{
#line 34

#line 36
	const cl_env_ptr the_env = ecl_process_env();
#line 36
	ecl_va_list nums;
	ecl_va_start(nums, min, narg, 1);
#line 36
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(557));
#line 36
	/* INV: type check occurs in ecl_number_compare() for the rest of
	   numbers, but for the first argument it happens in ecl_zerop(). */
	if (narg-- == 1) {
		ecl_zerop(min);
	} else do {
		cl_object numi = ecl_va_arg(nums);
		if (ecl_number_compare(min, numi) > 0)
			min = numi;
	} while (--narg);
	{
#line 45
		#line 45
		cl_object __value0 = min;
#line 45
		the_env->nvalues = 1;
#line 45
		return __value0;
#line 45
	}

}
