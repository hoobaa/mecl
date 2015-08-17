#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/symbol.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    symbol.d -- Symbols.
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

/******************************* ------- ******************************/
/* FIXME! CURRENTLY SYMBOLS ARE RESTRICTED TO HAVE NON-UNICODE NAMES */

cl_object
ecl_symbol_package(cl_object s)
{
        if (Null(s))
                return ECL_NIL_SYMBOL->symbol.hpack;
        if (ecl_t_of(s) == t_symbol)
                return s->symbol.hpack;
        FEwrong_type_nth_arg(ecl_make_fixnum(/*SYMBOL-PACKAGE*/844), 1, s, ecl_make_fixnum(/*SYMBOL*/840));
}

int
ecl_symbol_type(cl_object s)
{
        if (Null(s))
                return ECL_NIL_SYMBOL->symbol.stype;
        if (ecl_t_of(s) == t_symbol)
                return s->symbol.stype;
        FEwrong_type_nth_arg(ecl_make_fixnum(/*SYMBOL-NAME*/843), 1, s, ecl_make_fixnum(/*SYMBOL*/840));
}

void
ecl_symbol_type_set(cl_object s, int type)
{
        if (Null(s)) {
                ECL_NIL_SYMBOL->symbol.stype = type;
                return;
        }
        if (ecl_t_of(s) == t_symbol) {
                s->symbol.stype = type;
                return;
        }
        FEwrong_type_nth_arg(ecl_make_fixnum(/*SYMBOL-NAME*/843), 1, s, ecl_make_fixnum(/*SYMBOL*/840));
}

cl_object
ecl_symbol_name(cl_object s)
{
        if (Null(s)) {
                return ECL_NIL_SYMBOL->symbol.name;
        }
        if (ecl_t_of(s) == t_symbol) {
                return s->symbol.name;
        }
        FEwrong_type_nth_arg(ecl_make_fixnum(/*SYMBOL-NAME*/843), 1, s, ecl_make_fixnum(/*SYMBOL*/840));
}

static cl_object *
ecl_symbol_plist(cl_object s)
{
        if (Null(s)) {
                return &ECL_NIL_SYMBOL->symbol.plist;
        }
        if (ecl_t_of(s) == t_symbol) {
                return &s->symbol.plist;
        }
        FEwrong_type_nth_arg(ecl_make_fixnum(/*SYMBOL-PLIST*/845), 1, s, ecl_make_fixnum(/*SYMBOL*/840));
}

/**********************************************************************/

static void FEtype_error_plist(cl_object x) /*__attribute__((noreturn))*/;

cl_object
cl_make_symbol(cl_object str)
{
	cl_object x;
	/* INV: In several places it is assumed that we copy the string! */
	switch (ecl_t_of(str)) {
#ifdef ECL_UNICODE
	case t_string:
		if (!ecl_fits_in_base_string(str)) {
			str = cl_copy_seq(str);
		} else {
			str = si_copy_to_simple_base_string(str);
		}
		break;
#endif
	case t_base_string:
		str = si_copy_to_simple_base_string(str);
		break;
	default:
		FEwrong_type_nth_arg(ecl_make_fixnum(/*MAKE-SYMBOL*/537),1,str,ecl_make_fixnum(/*STRING*/805));
	}
	x = ecl_alloc_object(t_symbol);
	x->symbol.name = str;
	x->symbol.dynamic = 0;
#ifdef ECL_THREADS
	x->symbol.binding = ECL_MISSING_SPECIAL_BINDING;
#endif	/*  */
	ECL_SET(x,OBJNULL);
	ECL_SYM_FUN(x) = ECL_NIL;
	x->symbol.plist = ECL_NIL;
	x->symbol.hpack = ECL_NIL;
	x->symbol.stype = ecl_stp_ordinary;
	{
#line 119
		const cl_env_ptr the_env = ecl_process_env();
#line 119
		#line 119
		cl_object __value0 = x;
#line 119
		the_env->nvalues = 1;
#line 119
		return __value0;
#line 119
	}

}

/*
	ecl_make_keyword(s) makes a keyword from C string s.
*/
cl_object
ecl_make_keyword(const char *s)
{
	cl_object x = _ecl_intern(s, cl_core.keyword_package);
	/* cl_export(x, keyword_package); this is implicit in ecl_intern() */
	return x;
}

cl_object
ecl_make_symbol(const char *s, const char *p)
{
	cl_object package = ecl_find_package(p);
	cl_object x = _ecl_intern(s, package);
	/* cl_export(x, keyword_package); this is implicit in ecl_intern() */
	return x;
}

cl_object
ecl_symbol_value(cl_object s)
{
	if (Null(s)) {
		return s;
	} else {
		/* FIXME: Should we check symbol type? */
		const cl_env_ptr the_env = ecl_process_env();
		cl_object value = ECL_SYM_VAL(the_env, s);
		unlikely_if (value == OBJNULL)
			FEunbound_variable(s);
		return value;
	}
}

static void
FEtype_error_plist(cl_object x)
{
	cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM(":FORMAT-CONTROL",1240),
		 make_constant_base_string("Not a valid property list ~D"),
		 ECL_SYM(":FORMAT-ARGUMENTS",1239), cl_list(1, x),
		 ECL_SYM(":EXPECTED-TYPE",1232), ECL_SYM("SI::PROPERTY-LIST",1658),
		 ECL_SYM(":DATUM",1214), x);
}

cl_object
ecl_getf(cl_object place, cl_object indicator, cl_object deflt)
{
	cl_object l;

#ifdef ECL_SAFE
	assert_type_proper_list(place);
#endif
	for (l = place; CONSP(l); ) {
		cl_object cdr_l = ECL_CONS_CDR(l);
		if (!CONSP(cdr_l))
			break;
		if (ECL_CONS_CAR(l) == indicator)
			return ECL_CONS_CAR(cdr_l);
		l = ECL_CONS_CDR(cdr_l);
	}
	if (l != ECL_NIL)
		FEtype_error_plist(place);
	return(deflt);
}

cl_object
ecl_get(cl_object s, cl_object p, cl_object d)
{
	return ecl_getf(*ecl_symbol_plist(s), p, d);
}

/*
	(SI:PUT-F plist value indicator)
	returns the new property list with value for property indicator.
	It will be used in SETF for GETF.
*/
cl_object
si_put_f(cl_object place, cl_object value, cl_object indicator)
{
	cl_object l;

#ifdef ECL_SAFE
	assert_type_proper_list(place);
#endif
	/* This loop guarantees finishing for circular lists */
	for (l = place; CONSP(l); ) {
		cl_object cdr_l = ECL_CONS_CDR(l);
		if (!CONSP(cdr_l))
			break;
		if (ECL_CONS_CAR(l) == indicator) {
			ECL_RPLACA(cdr_l, value);
			{
#line 214
				const cl_env_ptr the_env = ecl_process_env();
#line 214
				#line 214
				cl_object __value0 = place;
#line 214
				the_env->nvalues = 1;
#line 214
				return __value0;
#line 214
			}
;
		}
		l = ECL_CONS_CDR(cdr_l);
	}
	if (l != ECL_NIL)
		FEtype_error_plist(place);
	place = CONS(value, place);
	{
#line 221
		const cl_env_ptr the_env = ecl_process_env();
#line 221
		#line 221
		cl_object __value0 = CONS(indicator, place);
#line 221
		the_env->nvalues = 1;
#line 221
		return __value0;
#line 221
	}
;
}

/*
	Remf(p, i) removes property i
	from the property list pointed by p,
	which is a pointer to an cl_object.
	The returned value of remf(p, i) is:

		TRUE    if the property existed
		FALSE   otherwise.
*/
static bool
remf(cl_object *place, cl_object indicator)
{
	cl_object l = *place, tail = ECL_NIL;
	while (!Null(l)) {
		cl_object ind;
		if (!LISTP(l))
			FEtype_error_plist(*place);
		ind = ECL_CONS_CAR(l);
		l = ECL_CONS_CDR(l);
		if (!CONSP(l))
			FEtype_error_plist(*place);
		if (ind == indicator) {
			l = ECL_CONS_CDR(l);
			if (Null(tail))
				*place = l;
			else
				ECL_RPLACD(tail, l);
			return TRUE;
		}
		tail = l;
		l = ECL_CONS_CDR(l);
	}
	return FALSE;
}

bool
ecl_keywordp(cl_object s)
{
	return (ecl_t_of(s) == t_symbol) && (s->symbol.hpack == cl_core.keyword_package);
}

// ------------------------------1
#line 265
cl_object cl_get(cl_narg narg, ...)
{
#line 265
// ------------------------------2
#line 265
	const cl_env_ptr the_env = ecl_process_env();
#line 265
	cl_object deflt;
#line 265
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object sym = va_arg(ARGS,cl_object);  
	cl_object indicator = va_arg(ARGS,cl_object);  
#line 265
// ------------------------------3

	cl_object *plist;
#line 268
// ------------------------------4
#line 268
#line 268
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(402));
#line 268
	if (narg > 2) {
#line 268
		deflt = va_arg(ARGS,cl_object);  
#line 268
	} else {
#line 268
		deflt = ECL_NIL;
#line 268
	}
#line 268
// ------------------------------5
	plist = ecl_symbol_plist(sym);
	{
#line 269
		#line 269
		cl_object __value0 = ecl_getf(*plist, indicator, deflt);
#line 269
		the_env->nvalues = 1;
#line 269
		return __value0;
#line 269
	}

}

cl_object
cl_remprop(cl_object sym, cl_object prop)
{
	cl_object *plist = ecl_symbol_plist(sym);
	{
#line 276
		const cl_env_ptr the_env = ecl_process_env();
#line 276
		#line 276
		cl_object __value0 = (remf(plist, prop)? ECL_T: ECL_NIL);
#line 276
		the_env->nvalues = 1;
#line 276
		return __value0;
#line 276
	}

}

cl_object
cl_symbol_plist(cl_object sym)
{
	{
#line 282
		const cl_env_ptr the_env = ecl_process_env();
#line 282
		#line 282
		cl_object __value0 = *ecl_symbol_plist(sym);
#line 282
		the_env->nvalues = 1;
#line 282
		return __value0;
#line 282
	}

}

// ------------------------------1
#line 285
cl_object cl_getf(cl_narg narg, ...)
{
#line 285
// ------------------------------2
#line 285
	const cl_env_ptr the_env = ecl_process_env();
#line 285
	cl_object deflt;
#line 285
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object place = va_arg(ARGS,cl_object);  
	cl_object indicator = va_arg(ARGS,cl_object);  
#line 285
// ------------------------------3

#line 287
// ------------------------------4
#line 287
#line 287
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(412));
#line 287
	if (narg > 2) {
#line 287
		deflt = va_arg(ARGS,cl_object);  
#line 287
	} else {
#line 287
		deflt = ECL_NIL;
#line 287
	}
#line 287
// ------------------------------5
	{
#line 287
		#line 287
		cl_object __value0 = ecl_getf(place, indicator, deflt);
#line 287
		the_env->nvalues = 1;
#line 287
		return __value0;
#line 287
	}

}

cl_object
cl_get_properties(cl_object place, cl_object indicator_list)
{
	const cl_env_ptr the_env = ecl_process_env();
	cl_object l;

#ifdef ECL_SAFE
	assert_type_proper_list(place);
#endif
	for (l = place;  CONSP(l); ) {
		cl_object cdr_l = ECL_CONS_CDR(l);
		if (!CONSP(cdr_l))
			break;
		if (ecl_member_eq(ECL_CONS_CAR(l), indicator_list))
			ecl_return3(the_env,ECL_CONS_CAR(l),ECL_CONS_CAR(cdr_l),l);
		l = ECL_CONS_CDR(cdr_l);
	}
	if (l != ECL_NIL)
		FEtype_error_plist(place);
	ecl_return3(the_env, ECL_NIL, ECL_NIL, ECL_NIL);
}

cl_object
cl_symbol_name(cl_object x)
{
	ecl_return1(ecl_process_env(), ecl_symbol_name(x));
}

// ------------------------------1
#line 318
cl_object cl_copy_symbol(cl_narg narg, ...)
{
#line 318
// ------------------------------2
#line 318
	const cl_env_ptr the_env = ecl_process_env();
#line 318
	cl_object cp;
#line 318
	cl_object x;
#line 318
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object sym = va_arg(ARGS,cl_object);  
#line 318
// ------------------------------3

#line 320
// ------------------------------4
#line 320
#line 320
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(262));
#line 320
	if (narg > 1) {
#line 320
		cp = va_arg(ARGS,cl_object);  
#line 320
	} else {
#line 320
		cp = ECL_NIL;
#line 320
	}
#line 320
	x = ECL_NIL;
#line 320
// ------------------------------5
	if (Null(sym))
		sym = ECL_NIL_SYMBOL;
	x = cl_make_symbol(ecl_symbol_name(sym));
	if (!Null(cp)) {
		x->symbol.dynamic = 0;
		x->symbol.stype = sym->symbol.stype;
		x->symbol.value = sym->symbol.value;
		x->symbol.gfdef = sym->symbol.gfdef;
		x->symbol.plist = cl_copy_list(sym->symbol.plist);
#ifdef ECL_THREADS
		x->symbol.binding = ECL_MISSING_SPECIAL_BINDING;
#endif
		/* FIXME!!! We should also copy the system property list */
	}
	{
#line 334
		#line 334
		cl_object __value0 = x;
#line 334
		the_env->nvalues = 1;
#line 334
		return __value0;
#line 334
	}

}

// ------------------------------1
#line 337
cl_object cl_gensym(cl_narg narg, ...)
{
#line 337
// ------------------------------2
#line 337
	const cl_env_ptr the_env = ecl_process_env();
#line 337
	cl_object prefix;
#line 337
	va_list ARGS;
	va_start(ARGS, narg);
#line 337
// ------------------------------3

	cl_type t;
	cl_object counter, output;
	bool increment;
#line 341
// ------------------------------4
#line 341
#line 341
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(400));
#line 341
	if (narg > 0) {
#line 341
		prefix = va_arg(ARGS,cl_object);  
#line 341
	} else {
#line 341
		prefix = cl_core.gensym_prefix;
#line 341
	}
#line 341
// ------------------------------5
{
	if (ecl_stringp(prefix)) {
		counter = ECL_SYM_VAL(the_env, ECL_SYM("*GENSYM-COUNTER*",35));
		increment = 1;
	} else if ((t = ecl_t_of(prefix)) == t_fixnum || t == t_bignum) {
		counter = prefix;
		prefix = cl_core.gensym_prefix;
		increment = 0;
	} else {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*GENSYM*/400),2,prefix,
                                     cl_list(3, ECL_SYM("OR",614), ECL_SYM("STRING",805), ECL_SYM("INTEGER",437)));
	}
	output = ecl_make_string_output_stream(64, 1);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-ESCAPE*",48), ECL_NIL);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-READABLY*",57), ECL_NIL);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-BASE*",45), ecl_make_fixnum(10));
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-RADIX*",56), ECL_NIL);
	si_write_ugly_object(prefix, output);
	si_write_ugly_object(counter, output);
	ecl_bds_unwind_n(the_env, 4);
	output = cl_make_symbol(cl_get_output_stream_string(output));
	if (increment)
		ECL_SETQ(the_env, ECL_SYM("*GENSYM-COUNTER*",35),ecl_one_plus(counter));
	{
#line 364
		#line 364
		cl_object __value0 = output;
#line 364
		the_env->nvalues = 1;
#line 364
		return __value0;
#line 364
	}
;
} }

// ------------------------------1
#line 367
cl_object cl_gentemp(cl_narg narg, ...)
{
#line 367
// ------------------------------2
#line 367
	const cl_env_ptr the_env = ecl_process_env();
#line 367
	cl_object prefix;
#line 367
	cl_object pack;
#line 367
	va_list ARGS;
	va_start(ARGS, narg);
#line 367
// ------------------------------3

	cl_object output, s;
	int intern_flag;
#line 371
// ------------------------------4
#line 371
#line 371
	if (ecl_unlikely(narg < 0|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(401));
#line 371
	if (narg > 0) {
#line 371
		prefix = va_arg(ARGS,cl_object);  
#line 371
	} else {
#line 371
		prefix = cl_core.gentemp_prefix;
#line 371
	}
#line 371
	if (narg > 1) {
#line 371
		pack = va_arg(ARGS,cl_object);  
#line 371
	} else {
#line 371
		pack = ecl_current_package();
#line 371
	}
#line 371
// ------------------------------5
        unlikely_if (!ECL_STRINGP(prefix))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*GENTEMP*/401), 1, prefix, ecl_make_fixnum(/*STRING*/805));
	pack = si_coerce_to_package(pack);
ONCE_MORE:
	output = ecl_make_string_output_stream(64, 1);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-ESCAPE*",48), ECL_NIL);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-READABLY*",57), ECL_NIL);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-BASE*",45), ecl_make_fixnum(10));
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-RADIX*",56), ECL_NIL);
	si_write_ugly_object(prefix, output);
	si_write_ugly_object(cl_core.gentemp_counter, output);
	ecl_bds_unwind_n(the_env, 4);
	cl_core.gentemp_counter = ecl_one_plus(cl_core.gentemp_counter);
	s = ecl_intern(cl_get_output_stream_string(output), pack, &intern_flag);
	if (intern_flag != 0)
		goto ONCE_MORE;
	{
#line 387
		#line 387
		cl_object __value0 = s;
#line 387
		the_env->nvalues = 1;
#line 387
		return __value0;
#line 387
	}

}

cl_object
cl_symbol_package(cl_object sym)
{
	{
#line 393
		const cl_env_ptr the_env = ecl_process_env();
#line 393
		#line 393
		cl_object __value0 = ecl_symbol_package(sym);
#line 393
		the_env->nvalues = 1;
#line 393
		return __value0;
#line 393
	}

}

cl_object
cl_keywordp(cl_object sym)
{
	{
#line 399
		const cl_env_ptr the_env = ecl_process_env();
#line 399
		#line 399
		cl_object __value0 = (ecl_keywordp(sym)? ECL_T: ECL_NIL);
#line 399
		the_env->nvalues = 1;
#line 399
		return __value0;
#line 399
	}

}

/*
	(SI:REM-F plist indicator) returns two values:

		* the new property list
		  in which property indcator is removed

		* T     if really removed
		  NIL   otherwise.

	It will be used for macro REMF.
*/
cl_object
si_rem_f(cl_object plist, cl_object indicator)
{
	cl_env_ptr the_env = ecl_process_env();
	bool found = remf(&plist, indicator);
	ecl_return2(the_env, plist, (found? ECL_T : ECL_NIL));
}

cl_object
si_set_symbol_plist(cl_object sym, cl_object plist)
{
	*ecl_symbol_plist(sym) = plist;
	{
#line 425
		const cl_env_ptr the_env = ecl_process_env();
#line 425
		#line 425
		cl_object __value0 = plist;
#line 425
		the_env->nvalues = 1;
#line 425
		return __value0;
#line 425
	}

}

cl_object
si_putprop(cl_object sym, cl_object value, cl_object indicator)
{
	cl_object *plist = ecl_symbol_plist(sym);
	*plist = si_put_f(*plist, value, indicator);
	{
#line 433
		const cl_env_ptr the_env = ecl_process_env();
#line 433
		#line 433
		cl_object __value0 = value;
#line 433
		the_env->nvalues = 1;
#line 433
		return __value0;
#line 433
	}

}

/* Added for defstruct. Beppe */
// ------------------------------1
#line 437
cl_object si_put_properties(cl_narg narg, ...)
{
#line 437
// ------------------------------2
#line 437
	const cl_env_ptr the_env = ecl_process_env();
#line 437
	ecl_va_list ind_values;
	ecl_va_start(ind_values, narg, narg, 0);
	cl_object sym = ecl_va_arg(ind_values);  
#line 437
// ------------------------------3

#line 439
// ------------------------------4
#line 439
#line 439
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(1123));
#line 439
// ------------------------------5
	while (--narg >= 2) {
		cl_object prop = ecl_va_arg(ind_values);
		si_putprop(sym, ecl_va_arg(ind_values), prop);
		narg--;
	}
	{
#line 444
		#line 444
		cl_object __value0 = sym;
#line 444
		the_env->nvalues = 1;
#line 444
		return __value0;
#line 444
	}

}

cl_object
si_Xmake_special(cl_object sym)
{
	int type = ecl_symbol_type(sym);
	if (type & ecl_stp_constant)
		FEerror("~S is a constant.", 1, sym);
	ecl_symbol_type_set(sym, type | ecl_stp_special);
	cl_remprop(sym, ECL_SYM("SI::SYMBOL-MACRO",1159));
	{
#line 455
		const cl_env_ptr the_env = ecl_process_env();
#line 455
		#line 455
		cl_object __value0 = sym;
#line 455
		the_env->nvalues = 1;
#line 455
		return __value0;
#line 455
	}

}

cl_object
si_Xmake_constant(cl_object sym, cl_object val)
{
	int type = ecl_symbol_type(sym);
	if (type & ecl_stp_special)
		FEerror("The argument ~S to DEFCONSTANT is a special variable.",
			1, sym);
	ecl_symbol_type_set(sym, type | ecl_stp_constant);
	ECL_SET(sym, val);
	{
#line 467
		const cl_env_ptr the_env = ecl_process_env();
#line 467
		#line 467
		cl_object __value0 = sym;
#line 467
		the_env->nvalues = 1;
#line 467
		return __value0;
#line 467
	}

}

void
ecl_defvar(cl_object sym, cl_object val)
{
	si_safe_eval(3, cl_list(3, ECL_SYM("DEFVAR",290), sym, cl_list(2, ECL_SYM("QUOTE",679), val)), ECL_NIL, ECL_NIL);
}

void
ecl_defparameter(cl_object sym, cl_object val)
{
	si_safe_eval(3, cl_list(3, ECL_SYM("DEFPARAMETER",285), sym, cl_list(2, ECL_SYM("QUOTE",679), val)), ECL_NIL, ECL_NIL);
}
