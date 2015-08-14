#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/mapfun.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    mapfun.c -- Mapping.
*/
/*
    Copyright (c) 1993, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/


#include <ecl/ecl.h>
#include <ecl/internal.h>
#include <string.h>

#define PREPARE_MAP(env, list, cdrs_frame, cars_frame, narg)            \
	struct ecl_stack_frame frames_aux[2];                           \
	const cl_object cdrs_frame = (cl_object)frames_aux;             \
        const cl_object cars_frame = (cl_object)(frames_aux+1);         \
	ECL_STACK_FRAME_FROM_VA_LIST(env,cdrs_frame,list);              \
	ECL_STACK_FRAME_COPY(cars_frame, cdrs_frame);                   \
	narg = cars_frame->frame.size;                                  \
	if (ecl_unlikely(narg == 0)) {                                  \
		FEprogram_error_noreturn("MAP*: Too few arguments", 0); \
	}

#line 33
cl_object cl_mapcar(cl_narg narg, cl_object fun, ...)
{
#line 33

	cl_object res, *val = &res;
#line 35
	const cl_env_ptr the_env = ecl_process_env();
#line 35
	ecl_va_list lists;
	ecl_va_start(lists, fun, narg, 1);
#line 35
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(545));
#line 35
{
	PREPARE_MAP(the_env, lists, cdrs_frame, cars_frame, narg);
	res = ECL_NIL;
	while (TRUE) {
		cl_index i;
		for (i = 0;  i < narg;  i++) {
			cl_object cdr = ECL_STACK_FRAME_REF(cdrs_frame, i);
                        if (ecl_unlikely(!LISTP(cdr)))
                                FEwrong_type_nth_arg(ecl_make_fixnum(/*MAPCAR*/545), i+2, cdr, ecl_make_fixnum(/*LIST*/481));
			if (Null(cdr)) {
				ecl_stack_frame_close(cars_frame);
				ecl_stack_frame_close(cdrs_frame);
				{
#line 47
					#line 47
					cl_object __value0 = res;
#line 47
					the_env->nvalues = 1;
#line 47
					return __value0;
#line 47
				}

			}
			ECL_STACK_FRAME_SET(cars_frame, i, ECL_CONS_CAR(cdr));
			ECL_STACK_FRAME_SET(cdrs_frame, i, ECL_CONS_CDR(cdr));
		}
		*val = ecl_list1(ecl_apply_from_stack_frame(cars_frame, fun));
		val = &ECL_CONS_CDR(*val);
	}
} }

#line 57
cl_object cl_maplist(cl_narg narg, cl_object fun, ...)
{
#line 57

	cl_object res, *val = &res;
#line 59
	const cl_env_ptr the_env = ecl_process_env();
#line 59
	ecl_va_list lists;
	ecl_va_start(lists, fun, narg, 1);
#line 59
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(549));
#line 59
{
	PREPARE_MAP(the_env, lists, cdrs_frame, cars_frame, narg);
	res = ECL_NIL;
	while (TRUE) {
		cl_index i;
		for (i = 0;  i < narg;  i++) {
			cl_object cdr = ECL_STACK_FRAME_REF(cdrs_frame, i);
                        if (ecl_unlikely(!LISTP(cdr)))
                                FEwrong_type_nth_arg(ecl_make_fixnum(/*MAPLIST*/549), i+2, cdr, ecl_make_fixnum(/*LIST*/481));
			if (Null(cdr)) {
				ecl_stack_frame_close(cars_frame);
				ecl_stack_frame_close(cdrs_frame);
				{
#line 71
					#line 71
					cl_object __value0 = res;
#line 71
					the_env->nvalues = 1;
#line 71
					return __value0;
#line 71
				}

			}
			ECL_STACK_FRAME_SET(cars_frame, i, cdr);
			ECL_STACK_FRAME_SET(cdrs_frame, i, ECL_CONS_CDR(cdr));
		}
		*val = ecl_list1(ecl_apply_from_stack_frame(cars_frame, fun));
		val = &ECL_CONS_CDR(*val);
	}
} }

#line 81
cl_object cl_mapc(cl_narg narg, cl_object fun, ...)
{
#line 81

	cl_object onelist;
#line 83
	const cl_env_ptr the_env = ecl_process_env();
#line 83
	ecl_va_list lists;
	ecl_va_start(lists, fun, narg, 1);
#line 83
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(543));
#line 83
{
	PREPARE_MAP(the_env, lists, cdrs_frame, cars_frame, narg);
	onelist = ECL_STACK_FRAME_REF(cdrs_frame, 0);
	while (TRUE) {
		cl_index i;
		for (i = 0;  i < narg;  i++) {
			cl_object cdr = ECL_STACK_FRAME_REF(cdrs_frame, i);
                        if (ecl_unlikely(!LISTP(cdr)))
                                FEwrong_type_nth_arg(ecl_make_fixnum(/*MAPC*/543), i+2, cdr, ecl_make_fixnum(/*LIST*/481));
			if (Null(cdr)) {
				ecl_stack_frame_close(cars_frame);
				ecl_stack_frame_close(cdrs_frame);
				{
#line 95
					#line 95
					cl_object __value0 = onelist;
#line 95
					the_env->nvalues = 1;
#line 95
					return __value0;
#line 95
				}

			}
			ECL_STACK_FRAME_SET(cars_frame, i, ECL_CONS_CAR(cdr));
			ECL_STACK_FRAME_SET(cdrs_frame, i, ECL_CONS_CDR(cdr));
		}
		ecl_apply_from_stack_frame(cars_frame, fun);
	}
} }

#line 104
cl_object cl_mapl(cl_narg narg, cl_object fun, ...)
{
#line 104

	cl_object onelist;
#line 106
	const cl_env_ptr the_env = ecl_process_env();
#line 106
	ecl_va_list lists;
	ecl_va_start(lists, fun, narg, 1);
#line 106
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(548));
#line 106
{
	PREPARE_MAP(the_env, lists, cdrs_frame, cars_frame, narg);
	onelist = ECL_STACK_FRAME_REF(cdrs_frame, 0);
	while (TRUE) {
		cl_index i;
		for (i = 0;  i < narg;  i++) {
			cl_object cdr = ECL_STACK_FRAME_REF(cdrs_frame, i);
                        if (ecl_unlikely(!LISTP(cdr)))
                                FEwrong_type_nth_arg(ecl_make_fixnum(/*MAPL*/548), i+2, cdr, ecl_make_fixnum(/*LIST*/481));
			if (Null(cdr)) {
				ecl_stack_frame_close(cars_frame);
				ecl_stack_frame_close(cdrs_frame);
				{
#line 118
					#line 118
					cl_object __value0 = onelist;
#line 118
					the_env->nvalues = 1;
#line 118
					return __value0;
#line 118
				}

			}
			ECL_STACK_FRAME_SET(cars_frame, i, cdr);
			ECL_STACK_FRAME_SET(cdrs_frame, i, ECL_CONS_CDR(cdr));
		}
		ecl_apply_from_stack_frame(cars_frame, fun);
	}
} }

#line 127
cl_object cl_mapcan(cl_narg narg, cl_object fun, ...)
{
#line 127

	cl_object res, *val = &res;
#line 129
	const cl_env_ptr the_env = ecl_process_env();
#line 129
	ecl_va_list lists;
	ecl_va_start(lists, fun, narg, 1);
#line 129
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(544));
#line 129
{
	PREPARE_MAP(the_env, lists, cdrs_frame, cars_frame, narg);
	res = ECL_NIL;
	while (TRUE) {
		cl_index i;
		for (i = 0;  i < narg;  i++) {
			cl_object cdr = ECL_STACK_FRAME_REF(cdrs_frame, i);
                        if (ecl_unlikely(!LISTP(cdr)))
                                FEwrong_type_nth_arg(ecl_make_fixnum(/*MAPCAN*/544), i+2, cdr, ecl_make_fixnum(/*LIST*/481));
			if (Null(cdr)) {
				ecl_stack_frame_close(cars_frame);
				ecl_stack_frame_close(cdrs_frame);
				{
#line 141
					#line 141
					cl_object __value0 = res;
#line 141
					the_env->nvalues = 1;
#line 141
					return __value0;
#line 141
				}

			}
			ECL_STACK_FRAME_SET(cars_frame, i, ECL_CONS_CAR(cdr));
			ECL_STACK_FRAME_SET(cdrs_frame, i, ECL_CONS_CDR(cdr));
		}
		*val = ecl_apply_from_stack_frame(cars_frame, fun);
		while (CONSP(*val))
			val = &ECL_CONS_CDR(*val);
	}
} }

#line 152
cl_object cl_mapcon(cl_narg narg, cl_object fun, ...)
{
#line 152

	cl_object res, *val = &res;
#line 154
	const cl_env_ptr the_env = ecl_process_env();
#line 154
	ecl_va_list lists;
	ecl_va_start(lists, fun, narg, 1);
#line 154
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(546));
#line 154
{
	PREPARE_MAP(the_env, lists, cdrs_frame, cars_frame, narg);
	res = ECL_NIL;
	while (TRUE) {
		cl_index i;
		for (i = 0;  i < narg;  i++) {
			cl_object cdr = ECL_STACK_FRAME_REF(cdrs_frame, i);
                        if (ecl_unlikely(!LISTP(cdr)))
                                FEwrong_type_nth_arg(ecl_make_fixnum(/*MAPCON*/546), i+2, cdr, ecl_make_fixnum(/*LIST*/481));
			if (Null(cdr)) {
				ecl_stack_frame_close(cars_frame);
				ecl_stack_frame_close(cdrs_frame);
				{
#line 166
					#line 166
					cl_object __value0 = res;
#line 166
					the_env->nvalues = 1;
#line 166
					return __value0;
#line 166
				}

			}
			ECL_STACK_FRAME_SET(cars_frame, i, cdr);
			ECL_STACK_FRAME_SET(cdrs_frame, i, ECL_CONS_CDR(cdr));
		}
		*val = ecl_apply_from_stack_frame(cars_frame, fun);
		while (CONSP(*val))
			val = &ECL_CONS_CDR(*val);
	}
} }
