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

// ------------------------------1
#line 20
cl_object cl_max(cl_narg narg, ...)
{
#line 20
// ------------------------------2
#line 20
	const cl_env_ptr the_env = ecl_process_env();
#line 20
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
	cl_object max = ecl_va_arg(nums);  
#line 20
// ------------------------------3

#line 22
// ------------------------------4
#line 22
#line 22
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(551));
#line 22
// ------------------------------5
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

// ------------------------------1
#line 34
cl_object cl_min(cl_narg narg, ...)
{
#line 34
// ------------------------------2
#line 34
	const cl_env_ptr the_env = ecl_process_env();
#line 34
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
	cl_object min = ecl_va_arg(nums);  
#line 34
// ------------------------------3

#line 36
// ------------------------------4
#line 36
#line 36
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(557));
#line 36
// ------------------------------5
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
