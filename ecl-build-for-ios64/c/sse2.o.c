#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/sse2.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    sse2.c --  SSE2 vector type support
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

#include <limits.h>
#include <string.h>
#include <ecl/ecl.h>
#define ECL_DEFINE_AET_SIZE
#include <ecl/internal.h>

#ifdef ECL_SSE2

/* Predicates */

cl_object
si_sse_pack_p(cl_object x)
{
	{
#line 31
		const cl_env_ptr the_env = ecl_process_env();
#line 31
		#line 31
		cl_object __value0 = (ECL_SSE_PACK_P(x) ? ECL_T : ECL_NIL);
#line 31
		the_env->nvalues = 1;
#line 31
		return __value0;
#line 31
	}

}

/* Element type substitution */

static void verify_sse_elttype(cl_elttype eltt) {
	switch (eltt) {
	case ecl_aet_sf:
	case ecl_aet_df:
	case ecl_aet_b8:
	case ecl_aet_i8:
#ifdef ecl_uint16_t
	case ecl_aet_b16:
	case ecl_aet_i16:
#endif
#ifdef ecl_uint32_t
	case ecl_aet_b32:
	case ecl_aet_i32:
#endif
#ifdef ecl_uint64_t
	case ecl_aet_b64:
	case ecl_aet_i64:
#endif
		break; /* OK */
	default:
		FEerror("Invalid element type for an SSE pack: ~S", 1, ecl_elttype_to_symbol(eltt));
	}
}

static
cl_elttype symbol_to_sse_elttype(cl_object type) {
	cl_elttype eltt = ecl_symbol_to_elttype(type);
	verify_sse_elttype(eltt);
	return eltt;
}

cl_object
si_sse_pack_as_elt_type(cl_object x, cl_object type)
{
	cl_elttype rtype;

	if (ecl_unlikely(!ECL_SSE_PACK_P(x))) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*EXT::SSE-PACK-AS-ELT-TYPE*/1792), 1, x, ecl_make_fixnum(/*EXT::SSE-PACK*/1790));
	}

	rtype = symbol_to_sse_elttype(type);

	if (x->sse.elttype != rtype) {
		cl_object new = ecl_alloc_object(t_sse_pack);
		new->sse.elttype = rtype;
		new->sse.data.vi = x->sse.data.vi;
		x = new;
	}

	{
#line 85
		const cl_env_ptr the_env = ecl_process_env();
#line 85
		#line 85
		cl_object __value0 = x;
#line 85
		the_env->nvalues = 1;
#line 85
		return __value0;
#line 85
	}

}

cl_object
si_sse_pack_element_type(cl_object x)
{
	if (ecl_unlikely(!ECL_SSE_PACK_P(x))) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*EXT::SSE-PACK-ELEMENT-TYPE*/1798), 1, x, ecl_make_fixnum(/*EXT::SSE-PACK*/1790));
	}

	{
#line 95
		const cl_env_ptr the_env = ecl_process_env();
#line 95
		#line 95
		cl_object __value0 = ecl_elttype_to_symbol(x->sse.elttype);
#line 95
		cl_object __value1 = ecl_make_fixnum(x->sse.elttype);
#line 95
		the_env->nvalues = 2;
#line 95
		the_env->values[1] = __value1;
#line 95
		return __value0;
#line 95
	}
;
}

/* Conversion to and from specialized vectors */

cl_object
si_sse_pack_to_vector(cl_object x, cl_object elt_type)
{
	cl_elttype etype;
	cl_object vec;

	if (ecl_unlikely(!ECL_SSE_PACK_P(x))) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*EXT::SSE-PACK-TO-VECTOR*/1794), 1, x, ecl_make_fixnum(/*EXT::SSE-PACK*/1790));
	}

	etype = x->sse.elttype;
	if (elt_type != ECL_NIL)
		etype = symbol_to_sse_elttype(elt_type);

	vec = ecl_alloc_simple_vector(16/ecl_aet_size[etype], etype);
	memcpy(vec->vector.self.b8, x->sse.data.b8, 16);

	{
#line 117
		const cl_env_ptr the_env = ecl_process_env();
#line 117
		#line 117
		cl_object __value0 = vec;
#line 117
		the_env->nvalues = 1;
#line 117
		return __value0;
#line 117
	}

}

cl_object
si_vector_to_sse_pack(cl_object x)
{
	cl_object ssev;

	if (ecl_unlikely(!ECL_ARRAYP(x))) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*EXT::VECTOR-TO-SSE-PACK*/1793), 1, x, ecl_make_fixnum(/*ARRAY*/96));
        }

	verify_sse_elttype(x->vector.elttype);

	if (ecl_unlikely(x->vector.dim * ecl_aet_size[x->vector.elttype] != 16))
		FEerror("Wrong vector size in VECTOR-TO-SSE-PACK: ~S",1,ecl_make_fixnum(x->vector.dim));

	ssev = ecl_alloc_object(t_sse_pack);
	ssev->sse.elttype = x->vector.elttype;
	memcpy(ssev->sse.data.b8, x->vector.self.b8, 16);

	{
#line 138
		const cl_env_ptr the_env = ecl_process_env();
#line 138
		#line 138
		cl_object __value0 = ssev;
#line 138
		the_env->nvalues = 1;
#line 138
		return __value0;
#line 138
	}

}

/* Boxing and unboxing.

   The unboxing primitives accept any kind of sse-pack on purpose. */

cl_object
ecl_make_int_sse_pack(__m128i value)
{
	cl_object obj = ecl_alloc_object(t_sse_pack);
	obj->sse.elttype = ecl_aet_b8;
	obj->sse.data.vi = value;
	{
#line 151
		const cl_env_ptr the_env = ecl_process_env();
#line 151
		#line 151
		cl_object __value0 = obj;
#line 151
		the_env->nvalues = 1;
#line 151
		return __value0;
#line 151
	}
;
}

__m128i
ecl_unbox_int_sse_pack(cl_object x)
{
	do {
		if (ECL_SSE_PACK_P(x))
			return x->sse.data.vi;
		x = ecl_type_error(ECL_SYM("COERCE",231), "variable", x, ECL_SYM("EXT::SSE-PACK",1790));
	} while(1);
}

cl_object
ecl_make_float_sse_pack(__m128 value)
{
	cl_object obj = ecl_alloc_object(t_sse_pack);
	obj->sse.elttype = ecl_aet_sf;
	obj->sse.data.vf = value;
	{
#line 170
		const cl_env_ptr the_env = ecl_process_env();
#line 170
		#line 170
		cl_object __value0 = obj;
#line 170
		the_env->nvalues = 1;
#line 170
		return __value0;
#line 170
	}
;
}

__m128
ecl_unbox_float_sse_pack(cl_object x)
{
	do {
		if (ECL_SSE_PACK_P(x))
			return x->sse.data.vf;
		x = ecl_type_error(ECL_SYM("COERCE",231), "variable", x, ECL_SYM("EXT::SSE-PACK",1790));
	} while(1);
}

cl_object
ecl_make_double_sse_pack(__m128d value)
{
	cl_object obj = ecl_alloc_object(t_sse_pack);
	obj->sse.elttype = ecl_aet_df;
	obj->sse.data.vd = value;
	{
#line 189
		const cl_env_ptr the_env = ecl_process_env();
#line 189
		#line 189
		cl_object __value0 = obj;
#line 189
		the_env->nvalues = 1;
#line 189
		return __value0;
#line 189
	}
;
}

__m128d
ecl_unbox_double_sse_pack(cl_object x)
{
	do {
		if (ECL_SSE_PACK_P(x))
			return x->sse.data.vd;
		x = ecl_type_error(ECL_SYM("COERCE",231), "variable", x, ECL_SYM("EXT::SSE-PACK",1790));
	} while(1);
}

#endif // ECL_SSE2
