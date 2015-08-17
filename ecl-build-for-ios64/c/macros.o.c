#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/macros.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    macros.c -- Macros.
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
#include <ecl/internal.h>

/******************************* ------- ******************************/
/*
 * The are two kinds of lisp environments. One of them is by the interpreter
 * when executing bytecodes and it contains local variable and function
 * definitions.
 *
 * The other environment is shared by the bytecodes compiler and by the C
 * compiler and it contains information for the compiler, including local
 * variable definitions, and local function and macro definitions. The
 * structure is as follows:
 *
 *	env -> ( var-list . fun-list )
 *	fun-list -> ( { definition | atomic-marker }* )
 *	definition -> ( macro-name SI::MACRO { extra-data }* )
 *		    | ( function-name FUNCTION { extra-data }* )
 *		    | ( a-symbol anything { extra-data }* )
 *	atomic-marker -> CB | LB
 *
 * The main difference between the bytecode and C compilers is on the extra
 * information. On the other hand, both environments are similar enough that
 * the functions MACROEXPAND-1, MACROEXPAND and MACRO-FUNCTION can find the
 * required information.
 */

static cl_object
search_symbol_macro(cl_object name, cl_object env)
{
	for (env = CAR(env); env != ECL_NIL; env = CDR(env)) {
		cl_object record = CAR(env);
		if (CONSP(record) && CAR(record) == name) {
			if (CADR(record) == ECL_SYM("SI::SYMBOL-MACRO",1159))
				return CADDR(record);
			return ECL_NIL;
		}
	}
	return si_get_sysprop(name, ECL_SYM("SI::SYMBOL-MACRO",1159));
}

static cl_object
search_macro_function(cl_object name, cl_object env)
{
	int type = ecl_symbol_type(name);
	if (env != ECL_NIL) {
		/* When the environment has been produced by the
		   compiler, there might be atoms/symbols signalling
		   closure and block boundaries. */
		while (!Null(env = CDR(env))) {
			cl_object record = CAR(env);
			if (CONSP(record) && CAR(record) == name) {
				cl_object tag = CADR(record);
				if (tag == ECL_SYM("SI::MACRO",1101))
					return CADDR(record);
				if (tag == ECL_SYM("FUNCTION",396))
					return ECL_NIL;
				break;
			}
		}
	}
	if (type & ecl_stp_macro) {
		return ECL_SYM_FUN(name);
	} else {
		return ECL_NIL;
	}
}

// ------------------------------1
#line 86
cl_object cl_macro_function(cl_narg narg, ...)
{
#line 86
// ------------------------------2
#line 86
	const cl_env_ptr the_env = ecl_process_env();
#line 86
	cl_object env;
#line 86
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object sym = va_arg(ARGS,cl_object);  
#line 86
// ------------------------------3

#line 88
// ------------------------------4
#line 88
#line 88
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(518));
#line 88
	if (narg > 1) {
#line 88
		env = va_arg(ARGS,cl_object);  
#line 88
	} else {
#line 88
		env = ECL_NIL;
#line 88
	}
#line 88
// ------------------------------5
	{
#line 88
		#line 88
		cl_object __value0 = (search_macro_function(sym, env));
#line 88
		the_env->nvalues = 1;
#line 88
		return __value0;
#line 88
	}

}

/*
	Analyze a form and expand it once if it is a macro form.
	VALUES(0) contains either the expansion or the original form.
	VALUES(1) is true when there was a macroexpansion.
*/

// ------------------------------1
#line 97
cl_object cl_macroexpand_1(cl_narg narg, ...)
{
#line 97
// ------------------------------2
#line 97
	const cl_env_ptr the_env = ecl_process_env();
#line 97
	cl_object env;
#line 97
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object form = va_arg(ARGS,cl_object);  
#line 97
// ------------------------------3

	cl_object exp_fun = ECL_NIL;
#line 100
// ------------------------------4
#line 100
#line 100
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(520));
#line 100
	if (narg > 1) {
#line 100
		env = va_arg(ARGS,cl_object);  
#line 100
	} else {
#line 100
		env = ECL_NIL;
#line 100
	}
#line 100
// ------------------------------5
	if (ECL_ATOM(form)) {
		if (ECL_SYMBOLP(form))
			exp_fun = search_symbol_macro(form, env);
	} else {
		cl_object head = CAR(form);
		if (ECL_SYMBOLP(head))
			exp_fun = search_macro_function(head, env);
	}
	if (!Null(exp_fun)) {
		cl_object hook = ecl_symbol_value(ECL_SYM("*MACROEXPAND-HOOK*",40));
		if (hook == ECL_SYM("FUNCALL",394))
			form = _ecl_funcall3(exp_fun, form, env);
		else
			form = _ecl_funcall4(hook, exp_fun, form, env);
	}
	{
#line 115
		#line 115
		cl_object __value0 = form;
#line 115
		cl_object __value1 = exp_fun;
#line 115
		the_env->nvalues = 2;
#line 115
		the_env->values[1] = __value1;
#line 115
		return __value0;
#line 115
	}

}

/*
	Expands a form as many times as possible and returns the
	finally expanded form.
*/
// ------------------------------1
#line 122
cl_object cl_macroexpand(cl_narg narg, ...)
{
#line 122
// ------------------------------2
#line 122
	const cl_env_ptr the_env = ecl_process_env();
#line 122
	cl_object env;
#line 122
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object form = va_arg(ARGS,cl_object);  
#line 122
// ------------------------------3

	cl_object done, old_form;
#line 125
// ------------------------------4
#line 125
#line 125
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(519));
#line 125
	if (narg > 1) {
#line 125
		env = va_arg(ARGS,cl_object);  
#line 125
	} else {
#line 125
		env = ECL_NIL;
#line 125
	}
#line 125
// ------------------------------5
	done = ECL_NIL;
	do {
		form = cl_macroexpand_1(2, old_form = form, env);
		if (ecl_nth_value(the_env, 1) == ECL_NIL) {
			break;
		} else if (old_form == form) {
			FEerror("Infinite loop when expanding macro form ~A", 1, old_form);
		} else {
			done = ECL_T;
		}
	} while (1);
	{
#line 136
		#line 136
		cl_object __value0 = form;
#line 136
		cl_object __value1 = done;
#line 136
		the_env->nvalues = 2;
#line 136
		the_env->values[1] = __value1;
#line 136
		return __value0;
#line 136
	}

}

static cl_object
or_macro(cl_object whole, cl_object env)
{
	cl_object output = ECL_NIL;
	whole = CDR(whole);
	if (Null(whole))	/* (OR) => NIL */
		{
#line 145
			const cl_env_ptr the_env = ecl_process_env();
#line 145
			#line 145
			cl_object __value0 = ECL_NIL;
#line 145
			the_env->nvalues = 1;
#line 145
			return __value0;
#line 145
		}
;
	while (!Null(CDR(whole))) {
		output = CONS(CONS(CAR(whole), ECL_NIL), output);
		whole = CDR(whole);
	}
	if (Null(output))	/* (OR form1) => form1 */
		{
#line 151
			const cl_env_ptr the_env = ecl_process_env();
#line 151
			#line 151
			cl_object __value0 = CAR(whole);
#line 151
			the_env->nvalues = 1;
#line 151
			return __value0;
#line 151
		}
;
	/* (OR form1 ... formn forml) => (COND (form1) ... (formn) (t forml)) */
	output = CONS(cl_list(2, ECL_T, CAR(whole)), output);
	{
#line 154
		const cl_env_ptr the_env = ecl_process_env();
#line 154
		#line 154
		cl_object __value0 = CONS(ECL_SYM("COND",247), cl_nreverse(output));
#line 154
		the_env->nvalues = 1;
#line 154
		return __value0;
#line 154
	}

}

static cl_object
expand_and(cl_object whole)
{
	if (Null(whole))
		return ECL_T;
	if (Null(CDR(whole)))
		return CAR(whole);
	return cl_list(3, ECL_SYM("IF",946), CAR(whole), expand_and(CDR(whole)));
}

static cl_object
and_macro(cl_object whole, cl_object env)
{
	{
#line 170
		const cl_env_ptr the_env = ecl_process_env();
#line 170
		#line 170
		cl_object __value0 = expand_and(CDR(whole));
#line 170
		the_env->nvalues = 1;
#line 170
		return __value0;
#line 170
	}

}

static cl_object
when_macro(cl_object whole, cl_object env)
{
	cl_object args = CDR(whole);
	if (ecl_unlikely(ecl_endp(args)))
		FEprogram_error_noreturn("Syntax error: ~S.", 1, whole);
	return cl_list(3, ECL_SYM("IF",946), CAR(args), CONS(ECL_SYM("PROGN",671), CDR(args)));
}

void
init_macros(void)
{
	ECL_SET(ECL_SYM("*MACROEXPAND-HOOK*",40), ECL_SYM("FUNCALL",394));
	ecl_def_c_macro(ECL_SYM("OR",614), or_macro, 2);
	ecl_def_c_macro(ECL_SYM("AND",87), and_macro, 2);
	ecl_def_c_macro(ECL_SYM("WHEN",905), when_macro, 2);
}
