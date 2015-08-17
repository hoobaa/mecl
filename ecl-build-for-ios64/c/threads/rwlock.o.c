#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/threads/rwlock.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    rwlock.d -- POSIX read-write locks
*/
/*
    Copyright (c) 2003, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#ifndef __sun__ /* See unixinit.d for this */
#define _XOPEN_SOURCE 600	/* For pthread mutex attributes */
#endif
#include <errno.h>
#include <ecl/ecl.h>
#ifdef ECL_WINDOWS_THREADS
# include <windows.h>
#else
# include <pthread.h>
#endif
#include <ecl/internal.h>

/*----------------------------------------------------------------------
 * READ/WRITE LOCKS
 */

static void
FEerror_not_a_rwlock(cl_object lock)
{
        FEwrong_type_argument(ECL_SYM("MP::RWLOCK",1435), lock);
}

static void
FEunknown_rwlock_error(cl_object lock, int rc)
{
#ifdef ECL_WINDOWS_THREADS
        FEwin32_error("When acting on rwlock ~A, got an unexpected error.", 1, lock);
#else
        const char *msg = NULL;
        switch (rc) {
        case EINVAL:
                msg = "The value specified by rwlock is invalid";
                break;
        case EPERM:
                msg = "Read/write lock not owned by us";
                break;
        case EDEADLK:
                msg = "Thread already owns this lock";
                break;
        case ENOMEM:
                msg = "Out of memory";
                break;
        default:
                FElibc_error("When acting on rwlock ~A, got an unexpected error.",
                             1, lock);
        }
        FEerror("When acting on rwlock ~A, got the following C library error:~%"
                "~A", 2, lock, make_constant_base_string(msg));
#endif
}

cl_object
ecl_make_rwlock(cl_object name)
{
        const cl_env_ptr the_env = ecl_process_env();
	cl_object output = ecl_alloc_object(t_rwlock);
#ifdef ECL_RWLOCK
        int rc;
	ecl_disable_interrupts_env(the_env);
	rc = pthread_rwlock_init(&output->rwlock.mutex, NULL);
	ecl_enable_interrupts_env(the_env);
        if (rc) {
                FEerror("Unable to create read/write lock", 0);
        }
	ecl_set_finalizer_unprotected(output, ECL_T);
#else
        output->rwlock.mutex = ecl_make_lock(name, 0);
#endif
	output->rwlock.name = name;
        return output;
}

// ------------------------------1
#line 88
cl_object mp_make_rwlock(cl_narg narg, ...)
{
#line 88
// ------------------------------2
#line 88
	const cl_env_ptr the_env = ecl_process_env();
#line 88
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1273)};
	cl_object name;
#line 88
	cl_object KEY_VARS[2];
#line 88
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
#line 88
// ------------------------------3

#line 90
// ------------------------------4
#line 90
#line 90
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(1434));
#line 90
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 90
	if (KEY_VARS[1]==ECL_NIL) {
#line 90
	  name = ECL_NIL;
	} else {
#line 90
	  name = KEY_VARS[0];
	}
#line 90
// ------------------------------5
	{
#line 90
		#line 90
		cl_object __value0 = ecl_make_rwlock(name);
#line 90
		the_env->nvalues = 1;
#line 90
		return __value0;
#line 90
	}

}

cl_object
mp_rwlock_name(cl_object lock)
{
	const cl_env_ptr env = ecl_process_env();
	if (ecl_t_of(lock) != t_rwlock)
		FEerror_not_a_rwlock(lock);
        ecl_return1(env, lock->rwlock.name);
}

cl_object
mp_giveup_rwlock_read(cl_object lock)
{
        /* Must be called with interrupts disabled. */
	if (ecl_t_of(lock) != t_rwlock)
		FEerror_not_a_rwlock(lock);
#ifdef ECL_RWLOCK
        {
                int rc = pthread_rwlock_unlock(&lock->rwlock.mutex);
                if (rc)
                        FEunknown_rwlock_error(lock, rc);
                {
#line 113
	const cl_env_ptr the_env = ecl_process_env();
#line 113
	#line 113
	cl_object __value0 = ECL_T;
#line 113
	the_env->nvalues = 1;
#line 113
	return __value0;
#line 113
}
;
        }
#else
        return mp_giveup_lock(lock->rwlock.mutex);
#endif
}

cl_object
mp_giveup_rwlock_write(cl_object lock)
{
	return mp_giveup_rwlock_read(lock);
}

cl_object
mp_get_rwlock_read_nowait(cl_object lock)
{
        if (ecl_t_of(lock) != t_rwlock)
		FEerror_not_a_rwlock(lock);
#ifdef ECL_RWLOCK
        {
                const cl_env_ptr env = ecl_process_env();
                cl_object output = ECL_T;
                int rc = pthread_rwlock_tryrdlock(&lock->rwlock.mutex);
                if (rc == 0) {
                        output = ECL_T;
                } else if (rc == EBUSY) {
                        output = ECL_NIL;
                } else {
                        FEunknown_rwlock_error(lock, rc);
                }
                ecl_return1(env, output);
        }
#else
        return mp_get_lock_nowait(lock->rwlock.mutex);
#endif
}

cl_object
mp_get_rwlock_read_wait(cl_object lock)
{
        if (ecl_t_of(lock) != t_rwlock)
		FEerror_not_a_rwlock(lock);
#ifdef ECL_RWLOCK
        {
                const cl_env_ptr env = ecl_process_env();
                int rc = pthread_rwlock_rdlock(&lock->rwlock.mutex);
                if (rc != 0) {
                        FEunknown_rwlock_error(lock, rc);
                }
                ecl_return1(env, ECL_T);
        }
#else
        return mp_get_lock_wait(lock->rwlock.mutex);
#endif
}

// ------------------------------1
#line 169
cl_object mp_get_rwlock_read(cl_narg narg, ...)
{
#line 169
// ------------------------------2
#line 169
	const cl_env_ptr the_env = ecl_process_env();
#line 169
	cl_object wait;
#line 169
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object lock = va_arg(ARGS,cl_object);  
#line 169
// ------------------------------3

#line 171
// ------------------------------4
#line 171
#line 171
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(1437));
#line 171
	if (narg > 1) {
#line 171
		wait = va_arg(ARGS,cl_object);  
#line 171
	} else {
#line 171
		wait = ECL_T;
#line 171
	}
#line 171
// ------------------------------5
	if (Null(wait))
        	return mp_get_rwlock_read_nowait(lock);
        else
        	return mp_get_rwlock_read_wait(lock);
}

cl_object
mp_get_rwlock_write_nowait(cl_object lock)
{
        if (ecl_t_of(lock) != t_rwlock)
		FEerror_not_a_rwlock(lock);
#ifdef ECL_RWLOCK
        {
                const cl_env_ptr env = ecl_process_env();
                cl_object output = ECL_T;
                int rc = pthread_rwlock_trywrlock(&lock->rwlock.mutex);
                if (rc == 0) {
                        output = ECL_T;
                } else if (rc == EBUSY) {
                        output = ECL_NIL;
                } else {
                        FEunknown_rwlock_error(lock, rc);
                }
                ecl_return1(env, output);
        }
#else
        return mp_get_lock_nowait(lock->rwlock.mutex);
#endif
}

cl_object
mp_get_rwlock_write_wait(cl_object lock)
{
        cl_env_ptr env = ecl_process_env();
        if (ecl_t_of(lock) != t_rwlock)
		FEerror_not_a_rwlock(lock);
#ifdef ECL_RWLOCK
        {
                int rc = pthread_rwlock_wrlock(&lock->rwlock.mutex);
                if (rc != 0) {
                        FEunknown_rwlock_error(lock, rc);
                }
                {
#line 213
	const cl_env_ptr the_env = ecl_process_env();
#line 213
	#line 213
	cl_object __value0 = ECL_T;
#line 213
	the_env->nvalues = 1;
#line 213
	return __value0;
#line 213
}

        }
#else
        return mp_get_lock_wait(lock->rwlock.mutex);
#endif
}

// ------------------------------1
#line 220
cl_object mp_get_rwlock_write(cl_narg narg, ...)
{
#line 220
// ------------------------------2
#line 220
	const cl_env_ptr the_env = ecl_process_env();
#line 220
	cl_object wait;
#line 220
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object lock = va_arg(ARGS,cl_object);  
#line 220
// ------------------------------3

#line 222
// ------------------------------4
#line 222
#line 222
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(1438));
#line 222
	if (narg > 1) {
#line 222
		wait = va_arg(ARGS,cl_object);  
#line 222
	} else {
#line 222
		wait = ECL_T;
#line 222
	}
#line 222
// ------------------------------5
	if (Null(wait))
        	return mp_get_rwlock_write_nowait(lock);
        else
        	return mp_get_rwlock_write_wait(lock);
}
