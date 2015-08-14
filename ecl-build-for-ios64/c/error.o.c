#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/error.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    error.c -- Error handling.
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
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#if defined(ECL_MS_WINDOWS_HOST) || defined(cygwin)
# include <windows.h>
#endif
#include <ecl/internal.h>
#include <ecl/ecl-inl.h>

static cl_object
cl_symbol_or_object(cl_object x)
{
        if (ECL_FIXNUMP(x))
                return (cl_object)(cl_symbols + ecl_fixnum(x));
        return x;
}

void
_ecl_unexpected_return()
{
        ecl_internal_error(
"*** \n"
"*** A call to ERROR returned without handling the error.\n"
"*** This should have never happened and is usually a signal\n"
"*** that the debugger or the universal error handler were\n"
"*** improperly coded or altered. Please contact the maintainers\n"
"***\n");
}

void
ecl_internal_error(const char *s)
{
        int saved_errno = errno;
	fprintf(stderr, "\nInternal or unrecoverable error in:\n%s\n", s);
        if (saved_errno) {
                fprintf(stderr, "  [%d: %s]\n", saved_errno,
                        strerror(saved_errno));
        }
	fflush(stderr);
        si_dump_c_backtrace(ecl_make_fixnum(32));
#ifdef SIGIOT
	signal(SIGIOT, SIG_DFL); /* avoid getting into a loop with abort */
#endif
	abort();
}


void
ecl_unrecoverable_error(cl_env_ptr the_env, const char *message)
{
	/*
	 * Right now we have no means of specifying a jump point
	 * for really bad events. We just jump to the outermost
	 * frame, which is equivalent to quitting, and wait for
	 * someone to intercept this jump.
	 */
        ecl_frame_ptr destination;
        cl_object tag;

        /*
         * We output the error message with very low level routines
         * because we can not risk another stack overflow.
         */
        writestr_stream(message, cl_core.error_output);

        tag = ECL_SYM_VAL(the_env, ECL_SYM("SI::*QUIT-TAG*",1737));
        the_env->nvalues = 0;
        if (tag) {
                destination = frs_sch(tag);
                if (destination) {
                        ecl_unwind(the_env, destination);
                }
        }
	if (the_env->frs_org <= the_env->frs_top) {
		destination = ecl_process_env()->frs_org;
		ecl_unwind(the_env, destination);
	} else {
		ecl_internal_error("\n;;;\n;;; No frame to jump to\n;;; Aborting ECL\n;;;");
	}
}

/*****************************************************************************/
/*		Support for Lisp Error Handler				     */
/*****************************************************************************/

void
FEerror(const char *s, int narg, ...)
{
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
	ecl_enable_interrupts();
	funcall(4, ECL_SYM("SI::UNIVERSAL-ERROR-HANDLER",1163),
		ECL_NIL,                    /*  not correctable  */
		make_constant_base_string(s),	 /*  condition text  */
		cl_grab_rest_args(args));
        _ecl_unexpected_return();
}

cl_object
CEerror(cl_object c, const char *err, int narg, ...)
{
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
	ecl_enable_interrupts();
	return funcall(4, ECL_SYM("SI::UNIVERSAL-ERROR-HANDLER",1163),
		       c,			/*  correctable  */
		       make_constant_base_string(err),	/*  continue-format-string  */
		       cl_grab_rest_args(args));
}

/***********************
 * Conditions signaler *
 ***********************/

void
FEprogram_error(const char *s, int narg, ...)
{
	cl_object real_args, text;
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
	text = make_constant_base_string(s);
	real_args = cl_grab_rest_args(args);
	if (cl_boundp(ECL_SYM("SI::*CURRENT-FORM*",1612)) != ECL_NIL) {
	    /* When FEprogram_error is invoked from the compiler, we can
	     * provide information about the offending form.
	     */
	    cl_object stmt = ecl_symbol_value(ECL_SYM("SI::*CURRENT-FORM*",1612));
	    if (stmt != ECL_NIL) {
		real_args = cl_list(3, stmt, text, real_args);
		text = make_constant_base_string("In form~%~S~%~?");
	    }
	}
	si_signal_simple_error(4, 
			       ECL_SYM("PROGRAM-ERROR",672), /* condition name */
			       ECL_NIL, /* not correctable */
			       text,
			       real_args);
}

void
FEprogram_error_noreturn(const char *s, int narg, ...)
{
	cl_object real_args, text;
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
	text = make_constant_base_string(s);
	real_args = cl_grab_rest_args(args);
	if (cl_boundp(ECL_SYM("SI::*CURRENT-FORM*",1612)) != ECL_NIL) {
	    /* When FEprogram_error is invoked from the compiler, we can
	     * provide information about the offending form.
	     */
	    cl_object stmt = ecl_symbol_value(ECL_SYM("SI::*CURRENT-FORM*",1612));
	    if (stmt != ECL_NIL) {
		real_args = cl_list(3, stmt, text, real_args);
		text = make_constant_base_string("In form~%~S~%~?");
	    }
	}
	si_signal_simple_error(4, 
			       ECL_SYM("PROGRAM-ERROR",672), /* condition name */
			       ECL_NIL, /* not correctable */
			       text,
			       real_args);
}

void
FEcontrol_error(const char *s, int narg, ...)
{
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
	si_signal_simple_error(4,
			       ECL_SYM("CONTROL-ERROR",255), /* condition name */
			       ECL_NIL, /* not correctable */
			       make_constant_base_string(s), /* format control */
			       cl_grab_rest_args(args)); /* format args */
}

void
FEreader_error(const char *s, cl_object stream, int narg, ...)
{
        cl_object message = make_constant_base_string(s);
        cl_object args_list;
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
        args_list = cl_grab_rest_args(args);
        if (Null(stream)) {
                /* Parser error */
                si_signal_simple_error(4,
                                       ECL_SYM("PARSE-ERROR",627), /* condition name */
                                       ECL_NIL, /* not correctable */
                                       message, /* format control */
                                       args_list);
        } else {
                /* Actual reader error */
                cl_object prefix = make_constant_base_string("Reader error in file ~S, "
                                                             "position ~D:~%");
                cl_object position = cl_file_position(1, stream);
                message = si_base_string_concatenate(2, prefix, message);
                args_list = cl_listX(3, stream, position, args_list);
                si_signal_simple_error(6,
                                       ECL_SYM("READER-ERROR",699), /* condition name */
                                       ECL_NIL, /* not correctable */
                                       message, /* format control */
                                       args_list, /* format args */
                                       ECL_SYM(":STREAM",1313), stream);
        }
}


void
FEcannot_open(cl_object fn)
{
	cl_error(3, ECL_SYM("FILE-ERROR",353), ECL_SYM(":PATHNAME",1285), fn);
}

void
FEend_of_file(cl_object strm)
{
	cl_error(3, ECL_SYM("END-OF-FILE",329), ECL_SYM(":STREAM",1313), strm);
}

void
FEclosed_stream(cl_object strm)
{
	cl_error(3, ECL_SYM("STREAM-ERROR",801), ECL_SYM(":STREAM",1313), strm);
}

cl_object
si_signal_type_error(cl_object value, cl_object type)
{
	return cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM(":EXPECTED-TYPE",1232), type,
                        ECL_SYM(":DATUM",1214), value);
}

void
FEwrong_type_argument(cl_object type, cl_object value)
{
        si_signal_type_error(value, cl_symbol_or_object(type));
}

void
FEwrong_type_only_arg(cl_object function, cl_object value, cl_object type)
{
        const char *message =
                "In ~:[an anonymous function~;~:*function ~A~], "
                "the value of the only argument is~&  ~S~&which is "
                "not of the expected type ~A";
        cl_env_ptr env = ecl_process_env();
        struct ecl_ihs_frame tmp_ihs;
        function = cl_symbol_or_object(function);
        type = cl_symbol_or_object(type);
        if (!Null(function) && env->ihs_top && env->ihs_top->function != function) {
                ecl_ihs_push(env,&tmp_ihs,function,ECL_NIL);
        }        
        si_signal_simple_error(8,
                               ECL_SYM("TYPE-ERROR",870), /* condition name */
                               ECL_NIL, /* not correctable */
                               make_constant_base_string(message), /* format control */
                               cl_list(3, function, value, type),
                               ECL_SYM(":EXPECTED-TYPE",1232), type,
                               ECL_SYM(":DATUM",1214), value);
}

void
FEwrong_type_nth_arg(cl_object function, cl_narg narg, cl_object value, cl_object type)
{
        const char *message =
                "In ~:[an anonymous function~;~:*function ~A~], "
                "the value of the ~:R argument is~&  ~S~&which is "
                "not of the expected type ~A";
        cl_env_ptr env = ecl_process_env();
        struct ecl_ihs_frame tmp_ihs;
        function = cl_symbol_or_object(function);
        type = cl_symbol_or_object(type);
        if (!Null(function) && env->ihs_top && env->ihs_top->function != function) {
                ecl_ihs_push(env,&tmp_ihs,function,ECL_NIL);
        }        
        si_signal_simple_error(8,
                               ECL_SYM("TYPE-ERROR",870), /* condition name */
                               ECL_NIL, /* not correctable */
                               make_constant_base_string(message), /* format control */
                               cl_list(4, function, ecl_make_fixnum(narg),
                                       value, type),
                               ECL_SYM(":EXPECTED-TYPE",1232), type,
                               ECL_SYM(":DATUM",1214), value);
}

void
FEwrong_type_key_arg(cl_object function, cl_object key, cl_object value, cl_object type)
{
        const char *message =
                "In ~:[an anonymous function~;~:*function ~A~], "
                "the value of the argument ~S is~&  ~S~&which is "
                "not of the expected type ~A";
        cl_env_ptr env = ecl_process_env();
        struct ecl_ihs_frame tmp_ihs;
        function = cl_symbol_or_object(function);
        type = cl_symbol_or_object(type);
        key = cl_symbol_or_object(key);
        if (!Null(function) && env->ihs_top && env->ihs_top->function != function) {
                ecl_ihs_push(env,&tmp_ihs,function,ECL_NIL);
        }        
        si_signal_simple_error(8,
                               ECL_SYM("TYPE-ERROR",870), /* condition name */
                               ECL_NIL, /* not correctable */
                               make_constant_base_string(message), /* format control */
                               cl_list(4, function, key, value, type),
                               ECL_SYM(":EXPECTED-TYPE",1232), type,
                               ECL_SYM(":DATUM",1214), value);
}

void
FEwrong_index(cl_object function, cl_object a, int which, cl_object ndx,
              cl_index nonincl_limit)
{
        const char *message1 =
                "In ~:[an anonymous function~;~:*function ~A~], "
                "the ~*index into the object~% ~A.~%"
                "takes a value ~D out of the range ~A.";
        const char *message2 =
                "In ~:[an anonymous function~;~:*function ~A~], "
                "the ~:R index into the object~% ~A~%"
                "takes a value ~D out of the range ~A.";
        cl_object limit = ecl_make_integer(nonincl_limit-1);
	cl_object type = ecl_make_integer_type(ecl_make_fixnum(0), limit);
        cl_object message = make_constant_base_string((which<0) ? message1 : message2);
        cl_env_ptr env = ecl_process_env();
        struct ecl_ihs_frame tmp_ihs;
        function = cl_symbol_or_object(function);
        if (!Null(function) && env->ihs_top && env->ihs_top->function != function) {
                ecl_ihs_push(env,&tmp_ihs,function,ECL_NIL);
        }        
        cl_error(9,
                 ECL_SYM("SIMPLE-TYPE-ERROR",773), /* condition name */
                 ECL_SYM(":FORMAT-CONTROL",1240), message,
                 ECL_SYM(":FORMAT-ARGUMENTS",1239),
                 cl_list(5, function, ecl_make_fixnum(which+1), a, ndx, type),
                 ECL_SYM(":EXPECTED-TYPE",1232), type,
                 ECL_SYM(":DATUM",1214), ndx);
}

void
FEunbound_variable(cl_object sym)
{
	cl_error(3, ECL_SYM("UNBOUND-VARIABLE",878), ECL_SYM(":NAME",1273), sym);
}

void
FEundefined_function(cl_object fname)
{
	cl_error(3, ECL_SYM("UNDEFINED-FUNCTION",879), ECL_SYM(":NAME",1273), fname);
}

void
FEprint_not_readable(cl_object x)
{
	cl_error(3, ECL_SYM("PRINT-NOT-READABLE",663), ECL_SYM(":OBJECT",1278), x);
}

/*************
 * Shortcuts *
 *************/

void
FEwrong_num_arguments(cl_object fun)
{
        fun = cl_symbol_or_object(fun);
	FEprogram_error("Wrong number of arguments passed to function ~S.",
			1, fun);
}

void
FEwrong_num_arguments_anonym(void)
{
	FEprogram_error("Wrong number of arguments passed to an anonymous function", 0);
}

void
FEinvalid_macro_call(cl_object name)
{
	FEerror("Invalid macro call to ~S.", 1, name);
}

void
FEinvalid_variable(const char *s, cl_object obj)
{
	FEerror(s, 1, obj);
}

void
FEassignment_to_constant(cl_object v)
{
	FEprogram_error("SETQ: Tried to assign a value to the constant ~S.", 1, v);
}

void
FEinvalid_function(cl_object obj)
{
	FEwrong_type_argument(ECL_SYM("FUNCTION",396), obj);
}

void
FEinvalid_function_name(cl_object fname)
{
	cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM(":FORMAT-CONTROL",1240),
		 make_constant_base_string("Not a valid function name ~D"),
		 ECL_SYM(":FORMAT-ARGUMENTS",1239), cl_list(1, fname),
		 ECL_SYM(":EXPECTED-TYPE",1232), cl_list(2, ECL_SYM("SATISFIES",735), ECL_SYM("SI::VALID-FUNCTION-NAME-P",1164)),
		 ECL_SYM(":DATUM",1214), fname);
}

/*      bootstrap version                */
static int recursive_error = 0;

static cl_object
universal_error_handler(cl_object continue_string, cl_object datum,
                        cl_object args)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object stream;
        if (recursive_error)
                goto ABORT;
        recursive_error = 1;
        stream = cl_core.error_output;
        if (!Null(stream)) {
                ecl_bds_bind(the_env, ECL_SYM("*PRINT-READABLY*",57), ECL_NIL);
                ecl_bds_bind(the_env, ECL_SYM("*PRINT-LEVEL*",51), ecl_make_fixnum(3));
                ecl_bds_bind(the_env, ECL_SYM("*PRINT-LENGTH*",50), ecl_make_fixnum(3));
                ecl_bds_bind(the_env, ECL_SYM("*PRINT-CIRCLE*",47), ECL_NIL);
                ecl_bds_bind(the_env, ECL_SYM("*PRINT-BASE*",45), ecl_make_fixnum(10));
                writestr_stream("\n;;; Unhandled lisp initialization error",
                                stream);
                writestr_stream("\n;;; Message:\n", stream);
                si_write_ugly_object(datum, stream);
                writestr_stream("\n;;; Arguments:\n", stream);
                si_write_ugly_object(datum, args);
                ecl_bds_unwind_n(the_env, 5);
        }
 ABORT:
	ecl_internal_error("\nLisp initialization error.\n");
}

void
FEdivision_by_zero(cl_object x, cl_object y)
{
	cl_error(5, ECL_SYM("DIVISION-BY-ZERO",306), ECL_SYM(":OPERATION",1280), ECL_SYM("/",21),
		 ECL_SYM(":OPERANDS",1281), cl_list(2, x, y));
}

cl_object
_ecl_strerror(int code)
{
	const char *error = strerror(code);
	return make_base_string_copy(error);
}

/*************************************
 * Errors generated by the C library *
 *************************************/
/*
 * Interprets an error code from the C library according to the POSIX
 * standard, and produces a suitable error message by combining the user
 * supplied format with an explanation of the cause of the error.
 */
void
FElibc_error(const char *msg, int narg, ...)
{
	ecl_va_list args;
	cl_object rest, error = _ecl_strerror(errno);

	ecl_va_start(args, narg, narg, 0);
	rest = cl_grab_rest_args(args);

	FEerror("~?~%C library explanation: ~A.", 3,
		make_constant_base_string(msg), rest,
		error);
}

#if defined(ECL_MS_WINDOWS_HOST) || defined(cygwin)
ecl_def_ct_base_string(unknown_error,"[Unable to get error message]",28,static,const);

void
FEwin32_error(const char *msg, int narg, ...)
{
	ecl_va_list args;
	cl_object rest, win_msg_obj;
	char *win_msg;

	if (FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_ALLOCATE_BUFFER,
	                  0, GetLastError(), 0, (void*)&win_msg, 0, NULL) == 0)
		win_msg_obj = unknown_error;
	else {
		win_msg_obj = make_base_string_copy(win_msg);
		LocalFree(win_msg);
	}

	ecl_va_start(args, narg, narg, 0);
	rest = cl_grab_rest_args(args);
	FEerror("~?~%Windows library explanation: ~A.", 3,
		make_constant_base_string(msg), rest,
		win_msg_obj);
}
#endif

/************************************
 * Higher level interface to errors *
 ************************************/

#line 528
cl_object cl_error(cl_narg narg, cl_object eformat, ...)
{
#line 528

#line 530
	const cl_env_ptr the_env = ecl_process_env();
#line 530
	ecl_va_list args;
	ecl_va_start(args, eformat, narg, 1);
#line 530
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(337));
#line 530
	ecl_enable_interrupts();
	funcall(4, ECL_SYM("SI::UNIVERSAL-ERROR-HANDLER",1163), ECL_NIL, eformat,
                cl_grab_rest_args(args));
	_ecl_unexpected_return();
	{
the_env->nvalues = 0; return ECL_NIL;
#line 534
	}
;
}

#line 537
cl_object cl_cerror(cl_narg narg, cl_object cformat, cl_object eformat, ...)
{
#line 537

#line 539
	const cl_env_ptr the_env = ecl_process_env();
#line 539
	ecl_va_list args;
	ecl_va_start(args, eformat, narg, 2);
#line 539
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(202));
#line 539
	ecl_enable_interrupts();
	return funcall(4, ECL_SYM("SI::UNIVERSAL-ERROR-HANDLER",1163), cformat, eformat,
		       cl_grab_rest_args(args));
}

void
init_error(void)
{
	ecl_def_c_function(ECL_SYM("SI::UNIVERSAL-ERROR-HANDLER",1163),
                           (cl_objectfn_fixed)universal_error_handler,
                           3);
}
