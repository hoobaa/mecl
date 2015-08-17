#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/cinit.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    init.c  -- Lisp Initialization.
*/
/*
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <stdio.h>
#include <ecl/ecl.h>
#include <ecl/internal.h>

/*
 * HOOKS.
 *
 * The following functions are only used to bootstrap ECL. They divert
 * the calls to the interpreted code which is loaded by bare.lsp. Once
 * the whole of ECL is built, the file cinit.o will be replaced by the
 * actual initialization code, and the compiled function will be
 * called instead.
 */

extern cl_object
cl_upgraded_array_element_type(cl_narg narg, /*cl_object type, */...)
{
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
        cl_object type = ecl_va_arg(args);
	return _ecl_funcall2(ECL_SYM("UPGRADED-ARRAY-ELEMENT-TYPE",889), type);
}

extern cl_object
si_safe_eval(cl_narg narg, /*cl_object form, cl_object env,*/ ...)
{
        ecl_va_list args;
        ecl_va_start(args, narg, narg, 0);
        cl_object form = ecl_va_arg(args);
        cl_object env = ecl_va_arg(args);

        if (narg == 3) {
                cl_object err_value;
                va_list args; va_start(args, env);
                err_value = va_arg(args, cl_object);
                return _ecl_funcall4(ECL_SYM("EXT::SAFE-EVAL",1133), form, env, err_value);
        }
        return _ecl_funcall3(ECL_SYM("EXT::SAFE-EVAL",1133), form, env);
}

extern cl_object
cl_slot_value(cl_object instance, cl_object name)
{
	return _ecl_funcall3(ECL_SYM("SLOT-VALUE",971), instance, name);
}

extern cl_object
clos_slot_value_set(cl_object value, cl_object instance, cl_object name)
{
	return _ecl_funcall4(ECL_SYM("CLOS::SLOT-VALUE-SET",1554), value, instance, name);
}

extern cl_object
clos_std_compute_applicable_methods(cl_object gf, cl_object arglist)
{
	return _ecl_funcall3(ECL_SYM("CLOS::STD-COMPUTE-APPLICABLE-METHODS",1568), gf, arglist);
}

extern cl_object
si_bind_simple_restarts(cl_object tag, cl_object names)
{
	if (ECL_SYM_FUN(ECL_SYM("SI::BIND-SIMPLE-RESTARTS",2025)) != Cnil)
		return _ecl_funcall3(ECL_SYM("SI::BIND-SIMPLE-RESTARTS",2025), tag, names);
	else
		return ECL_SYM_VAL(ecl_process_env(), ECL_SYM("SI::*RESTART-CLUSTERS*",4));
}

extern cl_object
si_bind_simple_handlers(cl_object tag, cl_object names)
{
	if (ECL_SYM_FUN(ECL_SYM("SI::BIND-SIMPLE-HANDLERS",2026)) != Cnil)
		return _ecl_funcall3(ECL_SYM("SI::BIND-SIMPLE-HANDLERS",2026), tag, names);
	else
		return ECL_SYM_VAL(ecl_process_env(), ECL_SYM("SI::*HANDLER-CLUSTERS*",5));
}

extern cl_object
clos_std_compute_effective_method(cl_object gf, cl_object combination, cl_object methods_list)
{
	return _ecl_funcall4(ECL_SYM("CLOS::STD-COMPUTE-EFFECTIVE-METHOD",1570), gf, combination, methods_list);
}

extern cl_object
clos_compute_effective_method_function(cl_object gf, cl_object combination, cl_object methods_list)
{
	return _ecl_funcall4(ECL_SYM("CLOS::COMPUTE-EFFECTIVE-METHOD-FUNCTION",1571), gf, combination, methods_list);
}

extern cl_object
si_string_to_object(cl_narg narg, /*cl_object string, */...)
{
        ecl_va_list args;
        ecl_va_start(args, narg, narg, 0);
        cl_object string = ecl_va_arg(args);

        if (narg == 2) {
                cl_object err_value;
                va_list args; va_start(args, string);
                err_value = va_arg(args, cl_object);
                return _ecl_funcall3(ECL_SYM("SI::STRING-TO-OBJECT",1150), string, err_value);
        }
        return _ecl_funcall2(ECL_SYM("SI::STRING-TO-OBJECT",1150), string);
}

extern cl_object
//si_signal_simple_error(cl_narg narg, cl_object condition, cl_object continuable, cl_object format, cl_object format_args, ...)
si_signal_simple_error(cl_narg narg, ...)
{
	ecl_va_list args;
	cl_object rest;
	ecl_va_start(args, narg, narg, 0);
        cl_object condition = ecl_va_arg(args);
        cl_object continuable = ecl_va_arg(args);
        cl_object format = ecl_va_arg(args);
        cl_object format_args = ecl_va_arg(args);
        
	rest = cl_grab_rest_args(args);
	return cl_apply(6, ECL_SYM("SI::SIGNAL-SIMPLE-ERROR",1144), condition, continuable, format, format_args, rest);
}

extern cl_object
cl_set_difference(cl_narg narg, /*cl_object l1, cl_object l2, */...)
{
        ecl_va_list args;
        ecl_va_start(args, narg, narg, 0);
        cl_object l1 = ecl_va_arg(args);
        cl_object l2 = ecl_va_arg(args);

        {
#line 145
	const cl_env_ptr the_env = ecl_process_env();
#line 145
	#line 145
	cl_object __value0 = l1;
#line 145
	the_env->nvalues = 1;
#line 145
	return __value0;
#line 145
}

}

extern cl_object
cl_array_dimensions(cl_object array)
{
	return funcall(2, ECL_SYM("ARRAY-DIMENSIONS",99), array);
}

extern cl_object
si_find_relative_package(cl_narg narg, /*cl_object package, */...)
{
        ecl_va_list args;
        ecl_va_start(args, narg, narg, 0);
        cl_object package = ecl_va_arg(args);

	{
#line 161
		const cl_env_ptr the_env = ecl_process_env();
#line 161
		#line 161
		cl_object __value0 = ECL_NIL;
#line 161
		the_env->nvalues = 1;
#line 161
		return __value0;
#line 161
	}
;
}

extern cl_object
si_wrong_type_argument(cl_narg narg, /*cl_object object, cl_object type, */...)
{
        ecl_va_list args;
        ecl_va_start(args, narg, narg, 0);
        cl_object object = ecl_va_arg(args);
        cl_object type = ecl_va_arg(args);

	return _ecl_funcall3(ECL_SYM("SI::WRONG-TYPE-ARGUMENT",1611), object, type);
}

static cl_object si_simple_toplevel ()
{
        cl_env_ptr env = ecl_process_env();
	cl_object output = cl_core.standard_output;
	cl_object sentence;
	int i;

	/* Simple minded top level loop */
        ECL_CATCH_ALL_BEGIN(env) {
                writestr_stream(";*** Lisp core booted ****\n"
                                "ECL (Embeddable Common Lisp)\n",
                                output);
                ecl_force_output(output);
                for (i = 1; i<ecl_fixnum(si_argc()); i++) {
                        cl_object arg = si_argv(ecl_make_fixnum(i));
                        cl_load(1, arg);
                }
                while (1) {
                        writestr_stream("\n> ", output);
                        sentence = cl_read(3, ECL_NIL, ECL_NIL, OBJNULL);
                        if (sentence == OBJNULL)
                                {
#line 196
	const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 196
}
;
			sentence = si_eval_with_env(1, sentence);
                        ecl_prin1(sentence, output);
                }
        } ECL_CATCH_ALL_END;
}

void fuck() {printf("FUCK\n");}

int
main(int argc, char **args)
{
	cl_object top_level, features;

	/* This should be always the first call */
        nlogd(">>");
	cl_boot(argc, args);
        nlogd(">>");
        nlogd("cl_boot ended");

	/* We are computing unnormalized numbers at some point */
	si_trap_fpe(ECL_T, ECL_NIL);

#ifdef ECL_CMU_FORMAT
	ECL_SET(ECL_SYM("*LOAD-VERBOSE*",39), ECL_NIL);
#endif
	ECL_SET(ECL_SYM("*PACKAGE*",43), cl_core.system_package);

	features = ecl_symbol_value(ECL_SYM("*FEATURES*",34));
	features = CONS(ecl_make_keyword("ECL-MIN"), features);
#ifdef HAVE_UNAME
	features = CONS(ecl_make_keyword("UNAME"), features);
#endif
	ECL_SET(ECL_SYM("*FEATURES*",34), features);
	top_level = _ecl_intern("TOP-LEVEL", cl_core.system_package);
	ecl_def_c_function(top_level, si_simple_toplevel, 0);
        nlogd(">>");
	funcall(1, top_level);
        nlogd(">>");
	return(0);
}

#ifdef __cplusplus
extern "C" void init_lib_LSP(cl_object);
#endif

void init_lib_LSP(cl_object o) {}
