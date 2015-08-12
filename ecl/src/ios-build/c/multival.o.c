#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/multival.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    multival.c -- Multiple Values.
*/
/*
    Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
    Copyright (c) 1990, Giuseppe Attardi.

    ECoLisp is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/


#include <ecl/ecl.h>
#include <ecl/internal.h>

#line 21
cl_object cl_values(cl_narg narg, ...)
{
#line 21

	cl_object output;
#line 24
	const cl_env_ptr the_env = ecl_process_env();
#line 24
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 24
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(895));
#line 24
	unlikely_if (narg > ECL_MULTIPLE_VALUES_LIMIT)
		FEerror("Too many values in VALUES",0);
	the_env->nvalues = narg;
	output = ECL_NIL;
	if (narg) {
		int i = 0;
		do { 
			the_env->values[i] = ecl_va_arg(args);
		} while (++i < narg);
		output = the_env->values[0];
	}
	return output;
}

cl_object
cl_values_list(cl_object list)
{
	cl_env_ptr the_env = ecl_process_env();
	int i;
	the_env->values[0] = ECL_NIL;
	for (i = 0; !Null(list); list=ECL_CONS_CDR(list)) {
                unlikely_if (!LISTP(list))
			FEtype_error_list(list);
		unlikely_if (i == ECL_MULTIPLE_VALUES_LIMIT)
			FEerror("Too many values in VALUES-LIST",0);
		the_env->values[i++] = ECL_CONS_CAR(list);
	}
	the_env->nvalues = i;
	return the_env->values[0];
}
