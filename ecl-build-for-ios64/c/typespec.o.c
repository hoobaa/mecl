#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/typespec.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    typespec.c -- Type specifier routines.
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

void
FEtype_error_fixnum(cl_object x) {
	FEwrong_type_argument(ecl_make_fixnum(/*FIXNUM*/372), x);
}

void
FEtype_error_size(cl_object x) {
	FEwrong_type_argument(cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0),
				      ecl_make_fixnum(MOST_POSITIVE_FIXNUM)),
			      x);
}

void
FEtype_error_cons(cl_object x) {
	FEwrong_type_argument(ecl_make_fixnum(/*CONS*/251), x);
}

void
FEtype_error_list(cl_object x) {
	FEwrong_type_argument(ecl_make_fixnum(/*LIST*/481), x);
}

void
FEtype_error_proper_list(cl_object x) {
	cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM(":FORMAT-CONTROL",1240),
		    make_constant_base_string("Not a proper list ~D"),
		    ECL_SYM(":FORMAT-ARGUMENTS",1239), cl_list(1, x),
		    ECL_SYM(":EXPECTED-TYPE",1232), ecl_read_from_cstring("si::proper-list"),
		    ECL_SYM(":DATUM",1214), x);
}

void
FEcircular_list(cl_object x)
{
	/* FIXME: Is this the right way to rebind it? */
	ecl_bds_bind(ecl_process_env(), ECL_SYM("*PRINT-CIRCLE*",47), ECL_T);
	cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM(":FORMAT-CONTROL",1240),
		    make_constant_base_string("Circular list ~D"),
		    ECL_SYM(":FORMAT-ARGUMENTS",1239), cl_list(1, x),
		    ECL_SYM(":EXPECTED-TYPE",1232), ECL_SYM("LIST",481),
		    ECL_SYM(":DATUM",1214), x);
}

void
FEtype_error_index(cl_object seq, cl_fixnum ndx)
{
        cl_object n = ecl_make_fixnum(ndx);
	cl_index l = ECL_INSTANCEP(seq)? seq->instance.length : ecl_length(seq);
	cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM(":FORMAT-CONTROL",1240),
		    make_constant_base_string("~S is not a valid index into the object ~S"),
		    ECL_SYM(":FORMAT-ARGUMENTS",1239), cl_list(2, n, seq),
		    ECL_SYM(":EXPECTED-TYPE",1232), cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), ecl_make_fixnum(l-1)),
		    ECL_SYM(":DATUM",1214), n);
}

void
FEtype_error_array(cl_object v)
{
	FEwrong_type_argument(ecl_make_fixnum(/*ARRAY*/96), v);
}

void
FEtype_error_vector(cl_object v)
{
	FEwrong_type_argument(ecl_make_fixnum(/*VECTOR*/898), v);
}

void
FEtype_error_sequence(cl_object x) {
	FEwrong_type_argument(ecl_make_fixnum(/*SEQUENCE*/741), x);
}

cl_object
ecl_type_error(cl_object function, const char *place, cl_object o,
	       cl_object type)
{
	si_wrong_type_argument(4, o, type,
			       (*place? make_constant_base_string(place) : ECL_NIL),
			       function);
}

/**********************************************************************/

static cl_object
ecl_type_to_symbol(cl_type t)
{
	switch(t) {
	case t_character:
		return ECL_SYM("CHARACTER",222);
	case t_fixnum:
		return ECL_SYM("FIXNUM",372);
	case t_bignum:
		return ECL_SYM("BIGNUM",122);
	case t_ratio:
		return ECL_SYM("RATIO",686);
	case t_singlefloat:
		return ECL_SYM("SINGLE-FLOAT",778);
	case t_doublefloat:
		return ECL_SYM("DOUBLE-FLOAT",315);
#ifdef ECL_LONG_FLOAT
	case t_longfloat:
		return ECL_SYM("LONG-FLOAT",508);
#endif
	case t_complex:
		return ECL_SYM("COMPLEX",241);
	case t_symbol:
		return ECL_SYM("SYMBOL",840);
	case t_package:
		return ECL_SYM("PACKAGE",617);
	case t_list:
		return ECL_SYM("LIST",481);
	case t_hashtable:
		return ECL_SYM("HASH-TABLE",418);
	case t_array:
		return ECL_SYM("ARRAY",96);
	case t_vector:
		return ECL_SYM("VECTOR",898);
	case t_bitvector:
		return ECL_SYM("BIT-VECTOR",134);
#ifdef ECL_UNICODE
	case t_string:
		return ECL_SYM("STRING",805);
#endif
	case t_base_string:
		return ECL_SYM("BASE-STRING",121);
	case t_stream:
		return ECL_SYM("STREAM",799);
	case t_readtable:
		return ECL_SYM("READTABLE",700);
	case t_pathname:
		return ECL_SYM("PATHNAME",630);
	case t_random:
		return ECL_SYM("RANDOM-STATE",681);
	case t_bytecodes:
	case t_bclosure:
	case t_cfun:
	case t_cfunfixed:
	case t_cclosure:
		return ECL_SYM("COMPILED-FUNCTION",236);
#ifdef ECL_THREADS
	case t_process:
		return ECL_SYM("MP::PROCESS",1395);
	case t_lock:
		return ECL_SYM("MP::LOCK",1396);
	case t_condition_variable:
		return ECL_SYM("MP::CONDITION-VARIABLE",1397);
	case t_semaphore:
		return ECL_SYM("MP::SEMAPHORE",1443);
	case t_barrier:
		return ECL_SYM("MP::BARRIER",1451);
	case t_mailbox:
		return ECL_SYM("MP::MAILBOX",1462);
#endif
	case t_codeblock:
		return ECL_SYM("SI::CODE-BLOCK",1613);
	case t_foreign:
		return ECL_SYM("SI::FOREIGN-DATA",1345);
	case t_frame:
		return ECL_SYM("SI::FRAME",1614);
	case t_weak_pointer:
		return ECL_SYM("EXT::WEAK-POINTER",1727);
#ifdef ECL_SSE2
	case t_sse_pack:
		return ECL_SYM("EXT::SSE-PACK",1790);
#endif
	default:
		ecl_internal_error("not a lisp data object");
	}
}

cl_object
ecl_check_cl_type(cl_object fun, cl_object p, cl_type t)
{
	while (ecl_t_of(p) != t) {
		p = ecl_type_error(fun, "argument", p, ecl_type_to_symbol(t));
	}
	return p;
}

void
assert_type_integer(cl_object p)
{
	cl_type t = ecl_t_of(p);
	if (t != t_fixnum && t != t_bignum)
                FEwrong_type_nth_arg(ecl_make_fixnum(/*COERCE*/231), 1, p, ecl_make_fixnum(/*INTEGER*/437));
}

void
assert_type_non_negative_integer(cl_object p)
{
	cl_type t = ecl_t_of(p);

	if (t == t_fixnum) {
		if (ecl_fixnum_plusp(p))
			return;
	} else if (t == t_bignum) {
		if (_ecl_big_sign(p) >= 0)
			return;
	}
	FEwrong_type_argument(cl_list(3,ECL_SYM("INTEGER",437),ecl_make_fixnum(0),ECL_SYM("*",18)), p);
}

void
assert_type_proper_list(cl_object p)
{
	if (ECL_ATOM(p) && p != ECL_NIL)
		FEtype_error_list(p);
	if (cl_list_length(p) == ECL_NIL)
		FEcircular_list(p);
}

cl_object
cl_type_of(cl_object x)
{
	cl_object t;
	cl_type tx = ecl_t_of(x);
	switch (tx) {
#ifdef CLOS
        case t_instance: {
		cl_object cl = ECL_CLASS_OF(x);
		t = ECL_CLASS_NAME(cl);
		if (t == ECL_NIL || cl != cl_find_class(2, t, ECL_NIL))
			t = cl;
		break;
	}
#endif
#if 1
	case t_fixnum:
	case t_bignum:
		t = cl_list(3, ECL_SYM("INTEGER",437), x, x); break;
#endif
	case t_character: {
		int i = ECL_CHAR_CODE(x);
		if (ecl_standard_char_p(i)) {
			t = ECL_SYM("STANDARD-CHAR",794);
		} else if (ecl_base_char_p(i)) {
			t = ECL_SYM("BASE-CHAR",120);
		} else {
			t = ECL_SYM("CHARACTER",222);
		}
		break;
	}

	case t_symbol:
		if (x == ECL_T)
			t = ECL_SYM("BOOLEAN",155);
		else if (x->symbol.hpack == cl_core.keyword_package)
			t = ECL_SYM("KEYWORD",449);
		else
			t = ECL_SYM("SYMBOL",840);
		break;
	case t_array:
		if (ECL_ADJUSTABLE_ARRAY_P(x) ||
		    !Null(CAR(x->array.displaced)))
			t = ECL_SYM("ARRAY",96);
		else
			t = ECL_SYM("SIMPLE-ARRAY",763);
		t = cl_list(3, t, ecl_elttype_to_symbol(ecl_array_elttype(x)),
                            cl_array_dimensions(x));
		break;
	case t_vector:
		if (ECL_ADJUSTABLE_ARRAY_P(x) ||
		    !Null(CAR(x->vector.displaced))) {
			t = cl_list(3, ECL_SYM("VECTOR",898), ecl_elttype_to_symbol(ecl_array_elttype(x)),
				    ecl_make_fixnum(x->vector.dim));
		} else if (ECL_ARRAY_HAS_FILL_POINTER_P(x) ||
			   (cl_elttype)x->vector.elttype != ecl_aet_object) {
			t = cl_list(3, ECL_SYM("SIMPLE-ARRAY",763),
                                    ecl_elttype_to_symbol(ecl_array_elttype(x)),
				    cl_array_dimensions(x));
		} else {
			t = cl_list(2, ECL_SYM("SIMPLE-VECTOR",774), ecl_make_fixnum(x->vector.dim));
		}
		break;
#ifdef ECL_UNICODE
	case t_string:
		if (ECL_ADJUSTABLE_ARRAY_P(x) ||
		    ECL_ARRAY_HAS_FILL_POINTER_P(x) ||
		    !Null(CAR(x->string.displaced)))
			t = ECL_SYM("ARRAY",96);
		else
			t = ECL_SYM("SIMPLE-ARRAY",763);
		t = cl_list(3, t, ECL_SYM("CHARACTER",222), cl_list(1, ecl_make_fixnum(x->string.dim)));
		break;
#endif
	case t_base_string:
		if (ECL_ADJUSTABLE_ARRAY_P(x) ||
		    ECL_ARRAY_HAS_FILL_POINTER_P(x) ||
		    !Null(CAR(x->base_string.displaced)))
			t = ECL_SYM("ARRAY",96);
		else
			t = ECL_SYM("SIMPLE-ARRAY",763);
		t = cl_list(3, t, ECL_SYM("BASE-CHAR",120), cl_list(1, ecl_make_fixnum(x->base_string.dim)));
		break;
	case t_bitvector:
		if (ECL_ADJUSTABLE_ARRAY_P(x) ||
		    ECL_ARRAY_HAS_FILL_POINTER_P(x) ||
		    !Null(CAR(x->vector.displaced)))
			t = ECL_SYM("ARRAY",96);
		else
			t = ECL_SYM("SIMPLE-ARRAY",763);
		t = cl_list(3, t, ECL_SYM("BIT",123), cl_list(1, ecl_make_fixnum(x->vector.dim)));
		break;
#ifndef CLOS
	case t_structure:
		t = x->str.name; break;
#endif
	case t_stream:
		switch (x->stream.mode) {
		case ecl_smm_synonym:	t = ECL_SYM("SYNONYM-STREAM",848); break;
		case ecl_smm_broadcast:	t = ECL_SYM("BROADCAST-STREAM",159); break;
		case ecl_smm_concatenated:	t = ECL_SYM("CONCATENATED-STREAM",245); break;
		case ecl_smm_two_way:	t =  ECL_SYM("TWO-WAY-STREAM",866); break;
		case ecl_smm_string_input:
		case ecl_smm_string_output:	t = ECL_SYM("STRING-STREAM",816); break;
		case ecl_smm_echo:		t = ECL_SYM("ECHO-STREAM",322); break;
                case ecl_smm_sequence_input:
                case ecl_smm_sequence_output: t = ECL_SYM("EXT::SEQUENCE-STREAM",1925); break;
		default:		t = ECL_SYM("FILE-STREAM",358); break;
		}
		break;
	case t_pathname:
		t = x->pathname.logical? ECL_SYM("LOGICAL-PATHNAME",498) : ECL_SYM("PATHNAME",630);
		break;
	case t_list:
		t = Null(x) ? ECL_SYM("NULL",605) : ECL_SYM("CONS",251);
		break;
#ifdef ECL_SSE2
	case t_sse_pack:
		t = ECL_SYM("EXT::SSE-PACK",1790);
		break;
#endif
	default:
		t = ecl_type_to_symbol(tx);
	}
	{
#line 355
		const cl_env_ptr the_env = ecl_process_env();
#line 355
		#line 355
		cl_object __value0 = t;
#line 355
		the_env->nvalues = 1;
#line 355
		return __value0;
#line 355
	}

}

cl_object
ecl_make_integer_type(cl_object min, cl_object max)
{
        return cl_list(3, ECL_SYM("INTEGER",437), min, max);
}
