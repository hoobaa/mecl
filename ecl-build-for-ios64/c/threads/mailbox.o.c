#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/threads/mailbox.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    mailbox.d -- thread communication queue
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
FEerror_not_a_mailbox(cl_object mailbox)
{
        FEwrong_type_argument(ECL_SYM("MP::MAILBOX",1462), mailbox);
}

cl_object
ecl_make_mailbox(cl_object name, cl_fixnum count)
{
	cl_object output = ecl_alloc_object(t_mailbox);
	cl_fixnum mask;
	for (mask = 1; mask < count; mask <<= 1) {}
	if (mask == 1)
		mask = 63;
	count = mask;
	mask = count - 1;
	output->mailbox.name = name;
	output->mailbox.data = si_make_vector(ECL_T, /* element type */
					      ecl_make_fixnum(count), /* size */
					      ECL_NIL, /* adjustable */
					      ECL_NIL, /* fill pointer */
					      ECL_NIL, /* displaced to */
					      ECL_NIL); /* displacement */
	output->mailbox.reader_semaphore =
	  ecl_make_semaphore(name, 0);
	output->mailbox.writer_semaphore =
	  ecl_make_semaphore(name, count);
	output->mailbox.read_pointer = 0;
	output->mailbox.write_pointer = 0;
	output->mailbox.mask = mask;
        return output;
}

#line 54
cl_object mp_make_mailbox(cl_narg narg, ...)
{
#line 54

#line 56
	const cl_env_ptr the_env = ecl_process_env();
#line 56
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1273), (cl_object)(cl_symbols+1450)};
	cl_object name;
	cl_object count;
#line 56
	cl_object KEY_VARS[4];
#line 56
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
#line 56
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(1463));
#line 56
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 56
	if (KEY_VARS[2]==ECL_NIL) {
#line 56
	  name = ECL_NIL;
	} else {
#line 56
	  name = KEY_VARS[0];
	}
#line 56
	if (KEY_VARS[3]==ECL_NIL) {
#line 56
	  count = ecl_make_fixnum(128);
	} else {
#line 56
	  count = KEY_VARS[1];
	}
#line 56
{
	{
#line 57
		#line 57
		cl_object __value0 = ecl_make_mailbox(name, fixnnint(count));
#line 57
		the_env->nvalues = 1;
#line 57
		return __value0;
#line 57
	}

}
}

cl_object
mp_mailbox_name(cl_object mailbox)
{
	cl_env_ptr env = ecl_process_env();
	unlikely_if (ecl_t_of(mailbox) != t_mailbox) {
		FEerror_not_a_mailbox(mailbox);
	}
        ecl_return1(env, mailbox->mailbox.name);
}

cl_object
mp_mailbox_count(cl_object mailbox)
{
	cl_env_ptr env = ecl_process_env();
	unlikely_if (ecl_t_of(mailbox) != t_mailbox) {
		FEerror_not_a_mailbox(mailbox);
	}
	ecl_return1(env, ecl_make_fixnum(mailbox->mailbox.data->vector.dim));
}

cl_object
mp_mailbox_empty_p(cl_object mailbox)
{
	cl_env_ptr env = ecl_process_env();
	unlikely_if (ecl_t_of(mailbox) != t_mailbox) {
		FEerror_not_a_mailbox(mailbox);
	}
	ecl_return1(env, mailbox->mailbox.reader_semaphore->semaphore.counter? ECL_NIL : ECL_T);
}

cl_object
mp_mailbox_read(cl_object mailbox)
{
	cl_env_ptr env = ecl_process_env();
	cl_fixnum ndx;
	cl_object output;
	unlikely_if (ecl_t_of(mailbox) != t_mailbox) {
		FEerror_not_a_mailbox(mailbox);
	}
	mp_wait_on_semaphore(mailbox->mailbox.reader_semaphore);
	{
		ndx = AO_fetch_and_add1((AO_t*)&mailbox->mailbox.read_pointer) &
			mailbox->mailbox.mask;
		output = mailbox->mailbox.data->vector.self.t[ndx];
	}
	mp_signal_semaphore(1, mailbox->mailbox.writer_semaphore);
	ecl_return1(env, output);
}

cl_object
mp_mailbox_send(cl_object mailbox, cl_object msg)
{
	cl_env_ptr env = ecl_process_env();
	cl_fixnum ndx;
	unlikely_if (ecl_t_of(mailbox) != t_mailbox) {
		FEerror_not_a_mailbox(mailbox);
	}
	mp_wait_on_semaphore(mailbox->mailbox.writer_semaphore);
	{
		ndx = AO_fetch_and_add1((AO_t*)&mailbox->mailbox.write_pointer) &
			mailbox->mailbox.mask;
		mailbox->mailbox.data->vector.self.t[ndx] = msg;
	}
	mp_signal_semaphore(1, mailbox->mailbox.reader_semaphore);
	ecl_return0(env);
}
