#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/threads/barrier.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    barrier.d -- wait barriers
*/
/*
    Copyright (c) 2012, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#define AO_ASSUME_WINDOWS98 /* We need this for CAS */
#include <ecl/ecl.h>
#include <ecl/internal.h>
#include "threads/ecl_atomics.h"

static ECL_INLINE void
FEerror_not_a_barrier(cl_object barrier)
{
        FEwrong_type_argument(ECL_SYM("MP::BARRIER",1451), barrier);
}

cl_object
ecl_make_barrier(cl_object name, cl_index count)
{
	cl_object output = ecl_alloc_object(t_barrier);
	output->barrier.name = name;
	output->barrier.arrivers_count = count;
	output->barrier.count = count;
	output->barrier.queue_list = ECL_NIL;
	output->barrier.queue_spinlock = ECL_NIL;
        return output;
}

// ------------------------------1
#line 39
cl_object mp_make_barrier(cl_narg narg, ...)
{
#line 39
// ------------------------------2
#line 39
	const cl_env_ptr the_env = ecl_process_env();
#line 39
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1273)};
	cl_object name;
#line 39
	cl_object KEY_VARS[2];
#line 39
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object count = ecl_va_arg(ARGS);  
#line 39
// ------------------------------3

#line 41
// ------------------------------4
#line 41
#line 41
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(1452));
#line 41
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 41
	if (KEY_VARS[1]==ECL_NIL) {
#line 41
	  name = ECL_NIL;
	} else {
#line 41
	  name = KEY_VARS[0];
	}
#line 41
// ------------------------------5
	if (count == ECL_T)
		count = ecl_make_fixnum(MOST_POSITIVE_FIXNUM);
	{
#line 43
		#line 43
		cl_object __value0 = ecl_make_barrier(name, fixnnint(count));
#line 43
		the_env->nvalues = 1;
#line 43
		return __value0;
#line 43
	}

}

cl_object
mp_barrier_name(cl_object barrier)
{
	cl_env_ptr env = ecl_process_env();
	unlikely_if (ecl_t_of(barrier) != t_barrier) {
		FEerror_not_a_barrier(barrier);
	}
        ecl_return1(env, barrier->barrier.name);
}

cl_object
mp_barrier_count(cl_object barrier)
{
	cl_env_ptr env = ecl_process_env();
	unlikely_if (ecl_t_of(barrier) != t_barrier) {
		FEerror_not_a_barrier(barrier);
	}
	ecl_return1(env, ecl_make_fixnum(barrier->barrier.count));
}

cl_object
mp_barrier_arrivers_count(cl_object barrier)
{
	cl_fixnum arrivers, count;
	cl_env_ptr env = ecl_process_env();
	unlikely_if (ecl_t_of(barrier) != t_barrier) {
		FEerror_not_a_barrier(barrier);
	}
	arrivers = barrier->barrier.arrivers_count;
	count = barrier->barrier.count;
	if (arrivers < 0)
		arrivers = 0; /* Disabled barrier */
	else
		arrivers = count - arrivers;
	ecl_return1(env, ecl_make_fixnum(arrivers));
}

// ------------------------------1
#line 83
cl_object mp_barrier_unblock(cl_narg narg, ...)
{
#line 83
// ------------------------------2
#line 83
	const cl_env_ptr the_env = ecl_process_env();
#line 83
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1459), (cl_object)(cl_symbols+1458), (cl_object)(cl_symbols+1460)};
	cl_object reset_count;
	cl_object disable;
	cl_object kill_waiting;
#line 83
	cl_object KEY_VARS[6];
#line 83
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object barrier = ecl_va_arg(ARGS);  
#line 83
// ------------------------------3

	int ping_flags = ECL_WAKEUP_RESET_FLAG | ECL_WAKEUP_ALL;
	int kill_flags = ECL_WAKEUP_RESET_FLAG | ECL_WAKEUP_KILL | ECL_WAKEUP_ALL;
#line 87
// ------------------------------4
#line 87
#line 87
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(1453));
#line 87
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 87
	if (KEY_VARS[3]==ECL_NIL) {
#line 87
	  reset_count = ECL_NIL;
	} else {
#line 87
	  reset_count = KEY_VARS[0];
	}
#line 87
	if (KEY_VARS[4]==ECL_NIL) {
#line 87
	  disable = ECL_NIL;
	} else {
#line 87
	  disable = KEY_VARS[1];
	}
#line 87
	if (KEY_VARS[5]==ECL_NIL) {
#line 87
	  kill_waiting = ECL_NIL;
	} else {
#line 87
	  kill_waiting = KEY_VARS[2];
	}
#line 87
// ------------------------------5
	unlikely_if (ecl_t_of(barrier) != t_barrier) {
		FEerror_not_a_barrier(barrier);
	}
	if (!Null(reset_count))
		barrier->barrier.count = fixnnint(reset_count);
	if (!Null(disable))
		barrier->barrier.arrivers_count = -1;
	else
		barrier->barrier.arrivers_count = barrier->barrier.count;
	ecl_wakeup_waiters(the_env, barrier,
			   Null(kill_waiting)? ping_flags : kill_flags);
        {
the_env->nvalues = 0; return ECL_NIL;
#line 98
}

}

static cl_object
barrier_wait_condition(cl_env_ptr env, cl_object barrier)
{
	/* We were signaled */
	if (env->own_process->process.woken_up != ECL_NIL)
		return ECL_T;
	/* Disabled barrier */
	else if (barrier->barrier.arrivers_count < 0)
		return ECL_T;
	else
		return ECL_NIL;
}

static cl_fixnum
decrement_counter(cl_fixnum *counter)
{
	/* The logic is as follows:
	 *  - If the counter is negative, we abort. This is a way of
	 *    disabling the counter.
	 *  - Otherwise, we decrease the counter only if it is positive
	 *  - If the counter is currently zero, then we block. This
	 *    situation implies that some other thread is unblocking.
	 */
	cl_fixnum c;
	do {
		c = *counter;
		if (c < 0) {
			return c;
		} else if (c > 0) {
			if (AO_compare_and_swap_full((AO_t*)counter,
						     (AO_t)c, (AO_t)(c-1)))
				return c;
		}
	} while (1);
}

// ------------------------------1
#line 137
cl_object mp_barrier_wait(cl_narg narg, ...)
{
#line 137
// ------------------------------2
#line 137
	const cl_env_ptr the_env = ecl_process_env();
#line 137
	cl_object *KEYS = NULL;
#line 137
	cl_object *KEY_VARS = NULL;
#line 137
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object barrier = ecl_va_arg(ARGS);  
#line 137
// ------------------------------3

	cl_object output;
	cl_fixnum counter;
#line 141
// ------------------------------4
#line 141
#line 141
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(1454));
#line 141
	cl_parse_key(ARGS, 0, KEYS, KEY_VARS, NULL, 0);
#line 141
// ------------------------------5
{
	cl_object own_process = the_env->own_process;

	unlikely_if (ecl_t_of(barrier) != t_barrier) {
		FEerror_not_a_barrier(barrier);
	}
	ecl_disable_interrupts_env(the_env);
	counter = decrement_counter(&barrier->barrier.arrivers_count);
	if (counter == 0) {
		print_lock("barrier %p saturated", barrier, barrier);
		/* There are (count-1) threads in the queue and we
		 * are the last one. We thus unblock all threads and
		 * proceed. */
		mp_barrier_unblock(1, barrier);
		ecl_enable_interrupts_env(the_env);
		output = ECL_SYM(":UNBLOCKED",1461);
	} else if (counter > 0) {
		print_lock("barrier %p waiting", barrier, barrier);
		ecl_enable_interrupts_env(the_env);
		ecl_wait_on(the_env, barrier_wait_condition, barrier);
		output = ECL_T;
	} else {
		print_lock("barrier %p pass-through", barrier, barrier);
		/* Barrier disabled */
		output = ECL_NIL;
	}
	{
#line 167
		#line 167
		cl_object __value0 = output;
#line 167
		the_env->nvalues = 1;
#line 167
		return __value0;
#line 167
	}

}
}
