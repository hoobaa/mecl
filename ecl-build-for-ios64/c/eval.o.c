#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/eval.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    eval.c -- Eval.
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
#include <ecl/ecl-inl.h>
#include <ecl/internal.h>

cl_object *
_ecl_va_sp(cl_narg narg)
{
	return ecl_process_env()->stack_top - narg;
}

/* Calling conventions:
   Compiled C code calls lisp function supplying #args, and args.
   Linking function performs check_args, gets jmp_buf with _setjmp, then
    if cfun then stores C code address into function link location
	    and transfers to jmp_buf at cf_self
    if cclosure then replaces #args with cc_env and calls cc_self
    otherwise, it emulates funcall.
 */

cl_object
ecl_apply_from_stack_frame(cl_object frame, cl_object x)
{
        nlogd(">>ecl_apply_from_stack_frame");
	cl_object *sp = frame->frame.base;
	cl_index narg = frame->frame.size;
	cl_object fun = x;
      AGAIN:
        frame->frame.env->function = fun;
	if (ecl_unlikely(fun == OBJNULL || fun == ECL_NIL))
		FEundefined_function(x);
	switch (ecl_t_of(fun)) {
	case t_cfunfixed:
		if (ecl_unlikely(narg != (cl_index)fun->cfun.narg))
			FEwrong_num_arguments(fun);
		return APPLY_fixed(narg, fun->cfunfixed.entry_fixed, sp);
	case t_cfun:
		return APPLY(narg, fun->cfun.entry, sp);
	case t_cclosure:
		return APPLY(narg, fun->cclosure.entry, sp);
#ifdef CLOS
	case t_instance:
		switch (fun->instance.isgf) {
		case ECL_STANDARD_DISPATCH:
		case ECL_RESTRICTED_DISPATCH:
			return _ecl_standard_dispatch(frame, fun);
		case ECL_USER_DISPATCH:
			fun = fun->instance.slots[fun->instance.length - 1];
                        goto AGAIN;
		case ECL_READER_DISPATCH:
		case ECL_WRITER_DISPATCH:
			return APPLY(narg, fun->instance.entry, sp);
		default:
			FEinvalid_function(fun);
		}
#endif
	case t_symbol:
		if (ecl_unlikely(fun->symbol.stype & ecl_stp_macro))
			FEundefined_function(x);
		fun = ECL_SYM_FUN(fun);
		goto AGAIN;
	case t_bytecodes:
		return ecl_interpret(frame, ECL_NIL, fun);
	case t_bclosure:
		return ecl_interpret(frame, fun->bclosure.lex, fun->bclosure.code);
	default:
		FEinvalid_function(x);
	}
}

cl_objectfn
ecl_function_dispatch(cl_env_ptr env, cl_object x)
{
	cl_object fun = x;
 AGAIN:
	if (ecl_unlikely(fun == OBJNULL || fun == ECL_NIL))
		FEundefined_function(x);
	switch (ecl_t_of(fun)) {
	case t_cfunfixed:
		env->function = fun;
		return fun->cfunfixed.entry;
	case t_cfun:
		env->function = fun;
		return fun->cfun.entry;
	case t_cclosure:
		env->function = fun;
		return fun->cclosure.entry;
#ifdef CLOS
	case t_instance:
                env->function = fun;
                return fun->instance.entry;
#endif
	case t_symbol:
		if (ecl_unlikely(fun->symbol.stype & ecl_stp_macro))
			FEundefined_function(x);
		fun = ECL_SYM_FUN(fun);
		goto AGAIN;
	case t_bytecodes:
		env->function = fun;
                return fun->bytecodes.entry;
	case t_bclosure:
		env->function = fun;
                return fun->bclosure.entry;
	default:
		FEinvalid_function(x);
	}
}

cl_object
cl_funcall(cl_narg narg, cl_object function, ...)
{
        cl_object output;
        --narg;
        {
                ECL_STACK_FRAME_VARARGS_BEGIN(narg, function, frame);
                output = ecl_apply_from_stack_frame(frame, function);
                ECL_STACK_FRAME_VARARGS_END(frame);
        }
        return output;
}

#line 139
cl_object cl_apply(cl_narg narg, cl_object fun, cl_object lastarg, ...)
{
#line 139

#line 141
	const cl_env_ptr the_env = ecl_process_env();
#line 141
	ecl_va_list args;
	ecl_va_start(args, lastarg, narg, 2);
#line 141
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(89));
#line 141
	if (narg == 2 && ecl_t_of(lastarg) == t_frame) {
		return ecl_apply_from_stack_frame(lastarg, fun);
	} else {
		cl_object out;
		cl_index i;
		struct ecl_stack_frame frame_aux;
		const cl_object frame = ecl_stack_frame_open(the_env,
							     (cl_object)&frame_aux,
							     narg -= 2);
		for (i = 0; i < narg; i++) {
			ECL_STACK_FRAME_SET(frame, i, lastarg);
			lastarg = ecl_va_arg(args);
		}
		if (ecl_t_of(lastarg) == t_frame) {
			/* This could be replaced with a memcpy() */
                        for (i = 0; i < lastarg->frame.size; i++) {
				ecl_stack_frame_push(frame, lastarg->frame.base[i]);
			}
		} else loop_for_in (lastarg) {
                        if (ecl_unlikely(i >= ECL_CALL_ARGUMENTS_LIMIT)) {
				ecl_stack_frame_close(frame);
				FEprogram_error_noreturn("CALL-ARGUMENTS-LIMIT exceeded",0);
			}
			ecl_stack_frame_push(frame, CAR(lastarg));
			i++;
		} end_loop_for_in;
		out = ecl_apply_from_stack_frame(frame, fun);
		ecl_stack_frame_close(frame);
		return out;
	}
}

cl_object
cl_eval(cl_object form)
{
	return si_eval_with_env(1, form);
}

#line 179
cl_object cl_constantp(cl_narg narg, cl_object arg, ...)
{
#line 179

	cl_object flag;
#line 182
	const cl_env_ptr the_env = ecl_process_env();
#line 182
	cl_object env;
#line 182
	va_list ARGS;
	va_start(ARGS, arg);
#line 182
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(254));
#line 182
	if (narg > 1) {
#line 182
		env = va_arg(ARGS,cl_object);
#line 182
	} else {
#line 182
		env = ECL_NIL;
#line 182
	}
#line 182
	switch (ecl_t_of(arg)) {
	case t_list:
		if (Null(arg)) {
			flag = ECL_T;
		} else if (CAR(arg) == ECL_SYM("QUOTE",679)) {
			flag = ECL_T;
		} else {
			flag = ECL_NIL;
		}
		break;
	case t_symbol:
		flag = (arg->symbol.stype & ecl_stp_constant) ? ECL_T : ECL_NIL;
		break;
	default:
		flag = ECL_T;
	}
	{
#line 198
		#line 198
		cl_object __value0 = flag;
#line 198
		the_env->nvalues = 1;
#line 198
		return __value0;
#line 198
	}

}
