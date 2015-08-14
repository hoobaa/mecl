#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/unixsys.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    unixsys.s  -- Unix shell interface.
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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h> /* to see whether we have SIGCHLD */
#if !defined(_MSC_VER)
# include <unistd.h>
#endif
#include <ecl/ecl.h>
#include <ecl/internal.h>
#ifdef cygwin
# include <sys/cygwin.h> /* For cygwin_attach_handle_to_fd() */
#endif
#if defined(ECL_MS_WINDOWS_HOST) || defined(cygwin)
# include <windows.h>
#endif
#ifdef HAVE_SYS_WAIT_H
# include <sys/wait.h>
#endif
#include <ecl/ecl-inl.h>

/* Mingw defines 'environ' to be a macro instead of a global variable. */
#ifdef environ
# undef environ
#endif

cl_object
si_getpid(void)
{
	{
#line 48
		const cl_env_ptr the_env = ecl_process_env();
#line 48
		#line 48
		cl_object __value0 = ecl_make_fixnum(getpid());
#line 48
		the_env->nvalues = 1;
#line 48
		return __value0;
#line 48
	}

}

cl_object
si_getuid(void)
{
#if defined(ECL_MS_WINDOWS_HOST)
        {
#line 55
	const cl_env_ptr the_env = ecl_process_env();
#line 55
	#line 55
	cl_object __value0 = ecl_make_fixnum(0);
#line 55
	the_env->nvalues = 1;
#line 55
	return __value0;
#line 55
}
;
#else
	{
#line 57
		const cl_env_ptr the_env = ecl_process_env();
#line 57
		#line 57
		cl_object __value0 = ecl_make_integer(getuid());
#line 57
		the_env->nvalues = 1;
#line 57
		return __value0;
#line 57
	}
;
#endif
}

ecl_def_ct_base_string(fake_in_name, "PIPE-READ-ENDPOINT", 18, static, const);
ecl_def_ct_base_string(fake_out_name, "PIPE-WRITE-ENDPOINT", 19, static, const);

cl_object
si_make_pipe()
{
	cl_object output;
	int fds[2], ret;
#if defined(ECL_MS_WINDOWS_HOST)
	ret = _pipe(fds, 4096, _O_BINARY);
#else
	ret = pipe(fds);
#endif
	if (ret < 0) {
		FElibc_error("Unable to create pipe", 0);
		output = ECL_NIL;
	} else {
		cl_object in = ecl_make_stream_from_fd(fake_in_name, fds[0], ecl_smm_input, 8,
						       ECL_STREAM_DEFAULT_FORMAT, ECL_NIL);
		cl_object out = ecl_make_stream_from_fd(fake_out_name, fds[1], ecl_smm_output, 8,
						       ECL_STREAM_DEFAULT_FORMAT, ECL_NIL);
		output = cl_make_two_way_stream(in, out);
	}
	{
#line 84
		const cl_env_ptr the_env = ecl_process_env();
#line 84
		#line 84
		cl_object __value0 = output;
#line 84
		the_env->nvalues = 1;
#line 84
		return __value0;
#line 84
	}

}

static cl_object
from_list_to_execve_argument(cl_object l, char ***environp)
{
        cl_object p;
        cl_index i, j, total_size = 0, nstrings = 0;
        cl_object buffer;
        char **environ;
        for (p = l; !Null(p); p = ECL_CONS_CDR(p)) {
                cl_object s;
                if (!CONSP(p)) {
                        FEerror("In EXT:RUN-PROGRAM, environment "
                                "is not a list of strings", 0);
                }
                s = ECL_CONS_CAR(p);
                if (!ECL_BASE_STRING_P(s)) {
                        FEerror("In EXT:RUN-PROGRAM, environment "
                                "is not a list of base strings", 0);
                }
                total_size += s->base_string.fillp + 1;
                nstrings++;
        }
        /* Extra place for ending null */
        total_size++;
        buffer = ecl_alloc_simple_base_string(++total_size);
        environ = ecl_alloc_atomic((nstrings + 1) * sizeof(char*));
        for (j = i = 0, p = l; !Null(p); p = ECL_CONS_CDR(p)) {
                cl_object s = ECL_CONS_CAR(p);
                cl_index l = s->base_string.fillp;
                if (i + l + 1 >= total_size) {
                        FEerror("In EXT:RUN-PROGRAM, environment list"
                                " changed during execution.", 0);
                        break;
                }
                environ[j++] = (char*)(buffer->base_string.self + i);
                memcpy(buffer->base_string.self + i,
                       s->base_string.self,
                       l);
                i += l;
                buffer->base_string.self[i++] = 0;
        }
        buffer->base_string.self[i++] = 0;
        environ[j] = 0;
        if (environp) *environp = environ;
        return buffer;
}

static cl_object
make_external_process()
{
        return _ecl_funcall1(ECL_SYM("EXT::MAKE-EXTERNAL-PROCESS",1743));
}

static cl_object
external_process_pid(cl_object p)
{
        return ecl_structure_ref(p, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 0);
}

static cl_object
external_process_status(cl_object p)
{
        return ecl_structure_ref(p, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 3);
}

static cl_object
external_process_code(cl_object p)
{
        return ecl_structure_ref(p, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 4);
}

static void
set_external_process_pid(cl_object process, cl_object pid)
{
        ecl_structure_set(process, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 0, pid);
}

static void
set_external_process_streams(cl_object process, cl_object input, cl_object output)
{
        ecl_structure_set(process, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 1, input);
        ecl_structure_set(process, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 2, output);
}


static void
update_process_status(cl_object process, cl_object status, cl_object code)
{
        ecl_structure_set(process, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 0, ECL_NIL);
        ecl_structure_set(process, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 4, code);
        ecl_structure_set(process, ECL_SYM("EXT::EXTERNAL-PROCESS",1744), 3, status);
}

#if defined(SIGCHLD) && !defined(ECL_MS_WINDOWS_HOST)
static void
add_external_process(cl_env_ptr env, cl_object process)
{
        cl_object l = ecl_list1(process);
        ecl_disable_interrupts_env(env);
	ECL_WITH_SPINLOCK_BEGIN(env, &cl_core.external_processes_lock);
	{
                ECL_RPLACD(l, cl_core.external_processes);
                cl_core.external_processes = l;
        }
	ECL_WITH_SPINLOCK_END;
        ecl_enable_interrupts_env(env);
}

static void
remove_external_process(cl_env_ptr env, cl_object process)
{
        ecl_disable_interrupts_env(env);
	ECL_WITH_SPINLOCK_BEGIN(env, &cl_core.external_processes_lock);
	{
                cl_core.external_processes =
                        ecl_delete_eq(process, cl_core.external_processes);
        }
	ECL_WITH_SPINLOCK_END;
        ecl_enable_interrupts_env(env);
}

static cl_object
find_external_process(cl_env_ptr env, cl_object pid)
{
	cl_object output = ECL_NIL;
	ecl_disable_interrupts_env(env);
	ECL_WITH_SPINLOCK_BEGIN(env, &cl_core.external_processes_lock);
	{
		cl_object p;
		for (p = cl_core.external_processes; p != ECL_NIL; p = ECL_CONS_CDR(p)) {
			cl_object process = ECL_CONS_CAR(p);
			if (external_process_pid(process) == pid) {
				output = process;
				break;
			}
		}
	}
	ECL_WITH_SPINLOCK_END(&cl_core.external_processes_lock);
	ecl_enable_interrupts_env(env);
        return output;
}
#else
#define add_external_process(env,p)
#define remove_external_process(env,p)
#endif

static cl_object
ecl_waitpid(cl_object pid, cl_object wait)
{
        cl_object status, code;
#if defined(ECL_MS_WINDOWS_HOST)
        cl_env_ptr the_env = ecl_process_env();
        HANDLE *hProcess = ecl_foreign_data_pointer_safe(pid);
        DWORD exitcode;
        int ok;
        WaitForSingleObject(*hProcess, Null(wait)? 0 : INFINITE);
        ecl_disable_interrupts_env(the_env);
        ok = GetExitCodeProcess(*hProcess, &exitcode);
        if (!ok) {
                status = ECL_SYM(":ERROR",1229);
                code = ECL_NIL;
        } else if (exitcode == STILL_ACTIVE) {
                status = ECL_SYM(":RUNNING",1749);
                code = ECL_NIL;
        } else {
                status = ECL_SYM(":EXITED",1750);
                code = ecl_make_fixnum(exitcode);
                pid->foreign.data = NULL;
                CloseHandle(*hProcess);
        }
        ecl_enable_interrupts_env(the_env);
#else
        int code_int, error;
        error = waitpid(ecl_to_fix(pid), &code_int, Null(wait)? WNOHANG : 0);
        if (error < 0) {
                if (errno == EINTR) {
                        status = ECL_SYM(":ABORT",1195);
                } else {
                        status = ECL_SYM(":ERROR",1229);
                }
                code = ECL_NIL;
                pid = ECL_NIL;
        } else if (error == 0) {
                status = ECL_NIL;
                code = ECL_NIL;
                pid = ECL_NIL;
        } else {
                pid = ecl_make_fixnum(error);
                if (WIFEXITED(code_int)) {
                        status = ECL_SYM(":EXITED",1750);
                        code = ecl_make_fixnum(WEXITSTATUS(code_int));
                } else if (WIFSIGNALED(code_int)) {
                        status = ECL_SYM(":SIGNALED",1751);
                        code = ecl_make_fixnum(WTERMSIG(code_int));
                } else if (WIFSTOPPED(code_int)) {
                        status = ECL_SYM(":STOPPED",1752);
                        code = ecl_make_fixnum(WSTOPSIG(code_int));
                } else {
                        status = ECL_SYM(":RUNNING",1749);
                        code = ECL_NIL;
                }
        }
#endif
        {
#line 289
	const cl_env_ptr the_env = ecl_process_env();
#line 289
	#line 289
	cl_object __value0 = status;
#line 289
	cl_object __value1 = code;
#line 289
	cl_object __value2 = pid;
#line 289
	the_env->nvalues = 3;
#line 289
	the_env->values[2] = __value2;
#line 289
	the_env->values[1] = __value1;
#line 289
	return __value0;
#line 289
}

}

#line 292
cl_object si_wait_for_all_processes(cl_narg narg, ...)
{
#line 292

#line 294
	const cl_env_ptr the_env = ecl_process_env();
#line 294
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1294)};
	cl_object process;
#line 294
	cl_object KEY_VARS[2];
#line 294
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
#line 294
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(1132));
#line 294
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 294
	if (KEY_VARS[1]==ECL_NIL) {
#line 294
	  process = ECL_NIL;
	} else {
#line 294
	  process = KEY_VARS[0];
	}
#line 294
{
        const cl_env_ptr env = ecl_process_env();
#if defined(SIGCHLD) && !defined(ECL_WINDOWS_HOST)
        do {
                cl_object status = ecl_waitpid(ecl_make_fixnum(-1), ECL_NIL);
                cl_object code = env->values[1];
                cl_object pid = env->values[2];
                if (Null(pid)) {
                        if (status != ECL_SYM(":ABORT",1195))
                                break;
                } else {
                        cl_object p = find_external_process(env, pid);
                        if (!Null(p)) {
				set_external_process_pid(p, ECL_NIL);
                                update_process_status(p, status, code);
                        }
                        if (status != ECL_SYM(":RUNNING",1749)) {
				remove_external_process(env, p);                                        ecl_delete_eq(p, cl_core.external_processes);
                        }
                }
        } while (1);
#endif
        ecl_return0(env);
}
}

#if defined(ECL_MS_WINDOWS_HOST) || defined(cygwin)
cl_object
si_close_windows_handle(cl_object h)
{
        if (ecl_t_of(h) == t_foreign) {
                HANDLE *ph = (HANDLE*)h->foreign.data;
                if (ph) CloseHandle(*ph);
        }
}

static cl_object
make_windows_handle(HANDLE h)
{
        cl_object foreign = ecl_allocate_foreign_data(ECL_SYM(":POINTER-VOID",1377),
						      sizeof(HANDLE*));
        HANDLE *ph = (HANDLE*)foreign->foreign.data;
        *ph = h;
        si_set_finalizer(foreign, ECL_SYM("SI::CLOSE-WINDOWS-HANDLE",1754));
        return foreign;
}
#endif

#line 342
cl_object si_external_process_wait(cl_narg narg, cl_object process, ...)
{
#line 342

#line 344
	const cl_env_ptr the_env = ecl_process_env();
#line 344
	cl_object wait;
#line 344
	va_list ARGS;
	va_start(ARGS, process);
#line 344
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(1753));
#line 344
	if (narg > 1) {
#line 344
		wait = va_arg(ARGS,cl_object);
#line 344
	} else {
#line 344
		wait = ECL_NIL;
#line 344
	}
#line 344
{
        cl_object status, code, pid;
 AGAIN:
        pid = external_process_pid(process);
        if (Null(pid)) {
		/* If PID is NIL, it may be because the process failed,
		 * or because it is being updated by a separate thread,
		 * which is why we have to spin here. Note also the order
		 * here: status is updated _after_ code, and hence we
		 * check it _before_ code. */
		do {
			status = external_process_status(process);
			code = external_process_code(process);
			ecl_musleep(0.0, 1);
		} while (status == ECL_SYM(":RUNNING",1749));
        } else {
                status = ecl_waitpid(pid, wait);
                code = ecl_nth_value(the_env, 1);
                pid = ecl_nth_value(the_env, 2);
                /* A SIGCHLD interrupt may abort waitpid. If this
                 * is the case, the signal handler may have consumed
                 * the process status and we have to start over again */
                if (Null(pid)) {
                        if (!Null(wait)) goto AGAIN;
                        status = external_process_status(process);
                        code = external_process_code(process);
                } else {
                        update_process_status(process, status, code);
                        remove_external_process(the_env, process);
                }
        }
        {
#line 375
	#line 375
	cl_object __value0 = status;
#line 375
	cl_object __value1 = code;
#line 375
	the_env->nvalues = 2;
#line 375
	the_env->values[1] = __value1;
#line 375
	return __value0;
#line 375
}

}
}

#if defined(ECL_MS_WINDOWS_HOST)
HANDLE
ecl_stream_to_HANDLE(cl_object s, bool output)
{
	if (ecl_unlikely(!ECL_ANSI_STREAM_P(s)))
		return INVALID_HANDLE_VALUE;
	switch ((enum ecl_smmode)s->stream.mode) {
#if defined(ECL_WSOCK)
	case ecl_smm_input_wsock:
	case ecl_smm_output_wsock:
	case ecl_smm_io_wsock:
#endif
#if defined(ECL_MS_WINDOWS_HOST)
	case ecl_smm_io_wcon:
#endif
		return (HANDLE)IO_FILE_DESCRIPTOR(s);
	default: {
		int stream_descriptor = ecl_stream_to_handle(s, output);
		return (stream_descriptor < 0)?
			INVALID_HANDLE_VALUE:
			(HANDLE)_get_osfhandle(stream_descriptor);
	}
	}
}
#endif

#line 407
cl_object si_run_program(cl_narg narg, cl_object command, cl_object argv, ...)
{
#line 407

	int parent_write = 0, parent_read = 0;
	int child_pid;
	cl_object pid, process;
	cl_object stream_write;
	cl_object stream_read;
	cl_object exit_status = ECL_NIL;
#line 415
	const cl_env_ptr the_env = ecl_process_env();
#line 415
	static cl_object KEYS[6] = {(cl_object)(cl_symbols+1254), (cl_object)(cl_symbols+1282), (cl_object)(cl_symbols+1229), (cl_object)(cl_symbols+1329), (cl_object)(cl_symbols+1742), (cl_object)(cl_symbols+1246)};
	cl_object input;
	cl_object output;
	cl_object error;
	cl_object wait;
	cl_object environ;
	cl_object if_output_exists;
#line 415
	cl_object KEY_VARS[12];
#line 415
	ecl_va_list ARGS;
	ecl_va_start(ARGS, argv, narg, 2);
#line 415
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(1131));
#line 415
	cl_parse_key(ARGS, 6, KEYS, KEY_VARS, NULL, 0);
#line 415
	if (KEY_VARS[6]==ECL_NIL) {
#line 415
	  input = ECL_SYM(":STREAM",1313);
	} else {
#line 415
	  input = KEY_VARS[0];
	}
#line 415
	if (KEY_VARS[7]==ECL_NIL) {
#line 415
	  output = ECL_SYM(":STREAM",1313);
	} else {
#line 415
	  output = KEY_VARS[1];
	}
#line 415
	if (KEY_VARS[8]==ECL_NIL) {
#line 415
	  error = ECL_SYM("T",1);
	} else {
#line 415
	  error = KEY_VARS[2];
	}
#line 415
	if (KEY_VARS[9]==ECL_NIL) {
#line 415
	  wait = ECL_SYM("T",1);
	} else {
#line 415
	  wait = KEY_VARS[3];
	}
#line 415
	if (KEY_VARS[10]==ECL_NIL) {
#line 415
	  environ = ECL_NIL;
	} else {
#line 415
	  environ = KEY_VARS[4];
	}
#line 415
	if (KEY_VARS[11]==ECL_NIL) {
#line 415
	  if_output_exists = ECL_SYM(":SUPERSEDE",1314);
	} else {
#line 415
	  if_output_exists = KEY_VARS[5];
	}
#line 415
	command = si_copy_to_simple_base_string(command);
	argv = cl_mapcar(2, ECL_SYM("SI::COPY-TO-SIMPLE-BASE-STRING",1060), argv);
	process = make_external_process();
#if defined(ECL_MS_WINDOWS_HOST)
{
	BOOL ok;
	STARTUPINFO st_info;
	PROCESS_INFORMATION pr_info;
	HANDLE child_stdout, child_stdin, child_stderr;
	HANDLE current = GetCurrentProcess();
	HANDLE saved_stdout, saved_stdin, saved_stderr;
	SECURITY_ATTRIBUTES attr;
        cl_object env_buffer;
        char *env = NULL;

	/* Enclose each argument, as well as the file name
	   in double quotes, to avoid problems when these
	   arguments or file names have spaces */
	command =
		cl_format(4, ECL_NIL,
			  ecl_make_simple_base_string("~S~{ ~S~}", -1),
			  command, argv);
	command = si_copy_to_simple_base_string(command);
	command = ecl_null_terminated_base_string(command);

        if (!Null(environ)) {
                env_buffer = from_list_to_execve_argument(environ, NULL);
                env = env_buffer->base_string.self;
        }

	attr.nLength = sizeof(SECURITY_ATTRIBUTES);
	attr.lpSecurityDescriptor = NULL;
	attr.bInheritHandle = TRUE;
 AGAIN_INPUT:
	if (input == ECL_SYM(":STREAM",1313)) {
		/* Creates a pipe that we can read from what the child
		   writes to it. We duplicate one extreme of the pipe
		   so that the child does not inherit it. */
		HANDLE tmp;
		ok = CreatePipe(&child_stdin, &tmp, &attr, 0);
		if (ok) {
			ok = DuplicateHandle(current, tmp, current,
					     &tmp, 0, FALSE,
					     DUPLICATE_CLOSE_SOURCE |
					     DUPLICATE_SAME_ACCESS);
			if (ok) {
#ifdef cygwin
				parent_write =
                                        cygwin_attach_handle_to_fd
                                        (0, -1, tmp, S_IRWXU, GENERIC_WRITE);
#else
				parent_write = _open_osfhandle((intptr_t)tmp,
                                                               _O_WRONLY /*| _O_TEXT*/);
#endif
				if (parent_write < 0)
					printf("open_osfhandle failed\n");
			}
		}
	} else if (input == ECL_SYM("T",1)) {
		/* The child inherits a duplicate of our input
		   handle. Creating a duplicate avoids problems when
		   the child closes it */
		input = ecl_symbol_value(ECL_SYM("*STANDARD-INPUT*",66));
                goto AGAIN_INPUT;
        } else if (Null(input)) {
		child_stdin = NULL;
		/*child_stdin = open("/dev/null", O_RDONLY);*/
        } else if (!Null(cl_streamp(input))) {
                /* If stream provides a handle, pass it to the child. Otherwise
                 * complain. */
		HANDLE stream_handle = ecl_stream_to_HANDLE(input, 0);
		unlikely_if (stream_handle == INVALID_HANDLE_VALUE) {
                        FEerror(":INPUT argument to RUN-PROGRAM does not "
                                "have a file handle:~%~S", 1, input);
                }
                DuplicateHandle(current, stream_handle,
                                /*GetStdHandle(STD_INPUT_HANDLE)*/
                                current, &child_stdin, 0, TRUE,
                                DUPLICATE_SAME_ACCESS);
	} else if (ECL_STRINGP(input) || ECL_PATHNAMEP(input)) {
                input = cl_open(5, input,
                                ECL_SYM(":DIRECTION",1218), ECL_SYM(":INPUT",1254),
                                ECL_SYM(":IF-DOES-NOT-EXIST",1244), ECL_SYM(":ERROR",1229));
                goto AGAIN_INPUT;
	} else {
                FEerror("Invalid :INPUT argument to EXT:RUN-PROGRAM", 1,
                        input);
        }
 AGAIN_OUTPUT:
	if (output == ECL_SYM(":STREAM",1313)) {
		/* Creates a pipe that we can write to and the
		   child reads from. We duplicate one extreme of the
		   pipe so that the child does not inherit it. */
		HANDLE tmp;
		ok = CreatePipe(&tmp, &child_stdout, &attr, 0);
		if (ok) {
			ok = DuplicateHandle(current, tmp, current,
					     &tmp, 0, FALSE,
					     DUPLICATE_CLOSE_SOURCE |
					     DUPLICATE_SAME_ACCESS);
			if (ok) {
#ifdef cygwin
				parent_read =
                                        cygwin_attach_handle_to_fd
                                        (0, -1, tmp, S_IRWXU, GENERIC_READ);
#else
				parent_read = _open_osfhandle((intptr_t)tmp,
                                                              _O_RDONLY /*| _O_TEXT*/);
#endif
				if (parent_read < 0)
					printf("open_osfhandle failed\n");
			}
		}
	} else if (output == ECL_SYM("T",1)) {
		/* The child inherits a duplicate of our output
		   handle. Creating a duplicate avoids problems when
		   the child closes it */
		output = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
                goto AGAIN_OUTPUT;
        } else if (Null(output)) {
                child_stdout = NULL;
        } else if (ECL_STRINGP(output) || ECL_PATHNAMEP(output)) {
                output = cl_open(7, output,
                                 ECL_SYM(":DIRECTION",1218), ECL_SYM(":OUTPUT",1282),
                                 ECL_SYM(":IF-EXISTS",1245), if_output_exists,
                                 ECL_SYM(":IF-DOES-NOT-EXIST",1244), ECL_SYM(":CREATE",1213));
                goto AGAIN_OUTPUT;
        } else if (!Null(cl_streamp(output))) {
		HANDLE stream_handle = ecl_stream_to_HANDLE(output, 1);
                unlikely_if(stream_handle == INVALID_HANDLE_VALUE) {
                        FEerror(":OUTPUT argument to RUN-PROGRAM does not "
                                "have a file handle:~%~S", 1, output);
                }
                DuplicateHandle(current, stream_handle,
                                /*GetStdHandle(STD_OUTPUT_HANDLE)*/
                                current, &child_stdout, 0, TRUE,
                                DUPLICATE_SAME_ACCESS);
	} else {
                FEerror("Invalid :OUTPUT argument to EXT:RUN-PROGRAM", 1,
                        output);
        }
 AGAIN_ERROR:
	if (error == ECL_SYM(":OUTPUT",1282)) {
		/* The child inherits a duplicate of its own output
		   handle.*/
		DuplicateHandle(current, child_stdout, current,
				&child_stderr, 0, TRUE,
				DUPLICATE_SAME_ACCESS);
	} else if (error == ECL_SYM("T",1)) {
		/* The child inherits a duplicate of our output
		   handle. Creating a duplicate avoids problems when
		   the child closes it */
		error = ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33));
                goto AGAIN_ERROR;
        } else if (Null(error)) {
		child_stderr = NULL;
        } else if (!Null(cl_streamp(error))) {
		HANDLE stream_handle = ecl_stream_to_HANDLE(error, 1);
		unlikely_if (stream_handle == INVALID_HANDLE_VALUE) {
                        FEerror(":ERROR argument to RUN-PROGRAM does not "
                                "have a file handle:~%~S", 1, error);
                }
                DuplicateHandle(current, stream_handle,
                                /*GetStdHandle(STD_ERROR_HANDLE)*/
                                current, &child_stderr, 0, TRUE,
                                DUPLICATE_SAME_ACCESS);
	} else {
                FEerror("Invalid :ERROR argument to EXT:RUN-PROGRAM:~%~S", 1,
                        error);
	}
	add_external_process(the_env, process);
#if 1
	ZeroMemory(&st_info, sizeof(STARTUPINFO));
	st_info.cb = sizeof(STARTUPINFO);
	st_info.lpTitle = NULL; /* No window title, just exec name */
	st_info.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW; /* Specify std{in,out,err} */
	st_info.wShowWindow = SW_HIDE;
	st_info.hStdInput = child_stdin;
	st_info.hStdOutput = child_stdout;
	st_info.hStdError = child_stderr;
	ZeroMemory(&pr_info, sizeof(PROCESS_INFORMATION));
	ok = CreateProcess(NULL, command->base_string.self,
			   NULL, NULL, /* lpProcess/ThreadAttributes */
			   TRUE, /* Inherit handles (for files) */
			   /*CREATE_NEW_CONSOLE |*/
			   0 /*(input == ECL_T || output == ECL_T || error == ECL_T ? 0 : CREATE_NO_WINDOW)*/,
			   env, /* Inherit environment */
			   NULL, /* Current directory */
			   &st_info, /* Startup info */
			   &pr_info); /* Process info */
#else /* 1 */
	saved_stdin = GetStdHandle(STD_INPUT_HANDLE);
	saved_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	saved_stderr = GetStdHandle(STD_ERROR_HANDLE);
	SetStdHandle(STD_INPUT_HANDLE, child_stdin);
	SetStdHandle(STD_OUTPUT_HANDLE, child_stdout);
	SetStdHandle(STD_ERROR_HANDLE, child_stderr);
	ZeroMemory(&st_info, sizeof(STARTUPINFO));
	st_info.cb = sizeof(STARTUPINFO);
	ZeroMemory(&pr_info, sizeof(PROCESS_INFORMATION));
	ok = CreateProcess(NULL, command->base_string.self,
			   NULL, NULL, /* lpProcess/ThreadAttributes */
			   TRUE, /* Inherit handles (for files) */
			   /*CREATE_NEW_CONSOLE |*/
			   0,
			   NULL, /* Inherit environment */
			   NULL, /* Current directory */
			   &st_info, /* Startup info */
			   &pr_info); /* Process info */
	SetStdHandle(STD_INPUT_HANDLE, saved_stdin);
	SetStdHandle(STD_OUTPUT_HANDLE, saved_stdout);
	SetStdHandle(STD_ERROR_HANDLE, saved_stderr);
#endif /* 1 */
	/* Child handles must be closed in the parent process */
	/* otherwise the created pipes are never closed       */
	if (ok) {
		CloseHandle(pr_info.hThread);
                pid = make_windows_handle(pr_info.hProcess);
	} else {
		char *message;
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
			      FORMAT_MESSAGE_ALLOCATE_BUFFER,
			      0, GetLastError(), 0, (void*)&message, 0, NULL);
		printf("%s\n", message);
		LocalFree(message);
		pid = ECL_NIL;
	}
        set_external_process_pid(process, pid);
        if (child_stdin) CloseHandle(child_stdin);
	if (child_stdout) CloseHandle(child_stdout);
	if (child_stderr) CloseHandle(child_stderr);
}
#else /* mingw */
{
	int child_stdin, child_stdout, child_stderr;
	int pipe_fd[2];
	argv = CONS(command, ecl_nconc(argv, ecl_list1(ECL_NIL)));
	argv = _ecl_funcall3(ECL_SYM("COERCE",231), argv, ECL_SYM("VECTOR",898));
 AGAIN_INPUT:
	if (input == ECL_SYM(":STREAM",1313)) {
		int fd[2];
		pipe(fd);
		parent_write = fd[1];
		child_stdin = fd[0];
	} else if (input == ECL_SYM("T",1)) {
                input = ecl_symbol_value(ECL_SYM("*STANDARD-INPUT*",66));
                goto AGAIN_INPUT;
        } else if (Null(input)) {
                child_stdin = open("/dev/null", O_RDONLY);
        } else if (!Null(cl_streamp(input))) {
                child_stdin = ecl_stream_to_handle(input, 0);
		if (child_stdin >= 0) {
			child_stdin = dup(child_stdin);
                } else {
                        FEerror(":INPUT argument to RUN-PROGRAM does not "
                                "have a file handle:~%~S", 1, input);
                }
	} else if (ECL_STRINGP(input) || ECL_PATHNAMEP(input)) {
                input = cl_open(5, input,
                                ECL_SYM(":DIRECTION",1218), ECL_SYM(":INPUT",1254),
                                ECL_SYM(":IF-DOES-NOT-EXIST",1244), ECL_SYM(":ERROR",1229));
                goto AGAIN_INPUT;
	} else {
                FEerror("Invalid :INPUT argument to EXT:RUN-PROGRAM:~%~S", 1,
                        input);
        }
 AGAIN_OUTPUT:
	if (output == ECL_SYM(":STREAM",1313)) {
		int fd[2];
		pipe(fd);
		parent_read = fd[0];
		child_stdout = fd[1];
	} else if (output == ECL_SYM("T",1)) {
                output = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
                goto AGAIN_OUTPUT;
        } else if (Null(output)) {
                child_stdout = open("/dev/null", O_WRONLY);
        } else if (ECL_STRINGP(output) || ECL_PATHNAMEP(output)) {
                output = cl_open(7, output,
                                 ECL_SYM(":DIRECTION",1218), ECL_SYM(":OUTPUT",1282),
                                 ECL_SYM(":IF-EXISTS",1245), if_output_exists,
                                 ECL_SYM(":IF-DOES-NOT-EXIST",1244), ECL_SYM(":CREATE",1213));
                goto AGAIN_OUTPUT;
        } else if (!Null(cl_streamp(output))) {
                child_stdout = ecl_stream_to_handle(output, 1);
		unlikely_if (child_stdout < 0) {
                        FEerror(":OUTPUT argument to RUN-PROGRAM does not "
                                "have a file handle:~%~S", 1, output);
                }
                child_stdout = dup(child_stdout);
	} else {
                FEerror("Invalid :OUTPUT argument to EXT:RUN-PROGRAM:~%~S", 1,
                        output);
        }
 AGAIN_ERROR:
	if (error == ECL_SYM(":OUTPUT",1282)) {
		child_stderr = child_stdout;
	} else if (error == ECL_SYM("T",1)) {
		error = ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33));
                goto AGAIN_ERROR;
        } else if (!Null(cl_streamp(error))) {
		child_stderr = ecl_stream_to_handle(error, 1);
		unlikely_if (child_stderr < 0) {
                        FEerror(":ERROR argument to RUN-PROGRAM does not "
                                "have a file handle:~%~S", 1, error);
                }
		child_stderr = dup(child_stderr);
	} else if (Null(error)) {
                child_stderr = open("/dev/null", O_WRONLY);
        } else {
                FEerror("Invalid :ERROR argument to EXT:RUN-PROGRAM:~%~S", 1,
                        error);
	}
	add_external_process(the_env, process);
	pipe(pipe_fd);
	child_pid = fork();
	if (child_pid == 0) {
		/* Child */
		int j;
		void **argv_ptr = (void **)argv->vector.self.t;
		{
			/* Wait for the parent to set up its process structure */
			char sync[1];
			close(pipe_fd[1]);
			while (read(pipe_fd[0], sync, 1) < 1) {
				printf("\nError reading child pipe %d", errno);
				fflush(stdout);
			}
			close(pipe_fd[0]);
		}
		dup2(child_stdin, STDIN_FILENO);
		if (parent_write) close(parent_write);
		dup2(child_stdout, STDOUT_FILENO);
		if (parent_read) close(parent_read);
		dup2(child_stderr, STDERR_FILENO);
		for (j = 0; j < argv->vector.fillp; j++) {
			cl_object arg = argv->vector.self.t[j];
			if (arg == ECL_NIL) {
				argv_ptr[j] = NULL;
			} else {
				argv_ptr[j] = arg->base_string.self;
			}
		}
                if (!Null(environ)) {
                        char **pstrings;
                        cl_object buffer = from_list_to_execve_argument(environ,
                                                                        &pstrings);
                        execve((char*)command->base_string.self, argv_ptr, pstrings);
                } else {
                        execvp((char*)command->base_string.self, argv_ptr);
                }
		/* at this point exec has failed */
		perror("exec");
		abort();
	}
        if (child_pid < 0) {
                pid = ECL_NIL;
        } else {
                pid = ecl_make_fixnum(child_pid);
        }
        set_external_process_pid(process, pid);
	{
		/* This guarantees that the child process does not exit
		 * before we have created the process structure. If we do not
		 * do this, the SIGPIPE signal may arrive before
		 * set_external_process_pid() and our call to external-process-wait
		 * down there may block indefinitely. */
		char sync[1];
		close(pipe_fd[0]);
		while (write(pipe_fd[1], sync, 1) < 1) {
			printf("\nError writing child pipe %d", errno);
			fflush(stdout);
		}
		close(pipe_fd[1]);
	}
	close(child_stdin);
	close(child_stdout);
	close(child_stderr);
}
#endif /* mingw */
	if (Null(pid)) {
		if (parent_write) close(parent_write);
		if (parent_read) close(parent_read);
		parent_write = 0;
		parent_read = 0;
                remove_external_process(the_env, process);
		FEerror("Could not spawn subprocess to run ~S.", 1, command);
	}
	if (parent_write > 0) {
		stream_write = ecl_make_stream_from_fd(command, parent_write,
						       ecl_smm_output, 8,
						       ECL_STREAM_DEFAULT_FORMAT, ECL_T);
	} else {
		parent_write = 0;
		stream_write = cl_core.null_stream;
	}
	if (parent_read > 0) {
		stream_read = ecl_make_stream_from_fd(command, parent_read,
						      ecl_smm_input, 8,
						      ECL_STREAM_DEFAULT_FORMAT, ECL_T);
	} else {
		parent_read = 0;
		stream_read = cl_core.null_stream;
	}
	set_external_process_streams(process, stream_write, stream_read);
	if (!Null(wait)) {
                exit_status = si_external_process_wait(2, process, ECL_T);
                exit_status = ecl_nth_value(the_env, 1);
        }
	{
#line 828
		#line 828
		cl_object __value0 = ((parent_read || parent_write)?
		  cl_make_two_way_stream(stream_read, stream_write) :
		  ECL_NIL);
#line 828
		cl_object __value1 = exit_status;
#line 828
		cl_object __value2 = process;
#line 828
		the_env->nvalues = 3;
#line 828
		the_env->values[2] = __value2;
#line 828
		the_env->values[1] = __value1;
#line 828
		return __value0;
#line 828
	}

}

