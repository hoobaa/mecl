#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/vector_push.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    string.d -- String routines.
*/
/*
    Copyright (c) 1984, Taiichi Yuasa and Masami Hagiya.
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under thep terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/


#include <ecl/ecl.h>
#include <ecl/internal.h>

static cl_object
extend_vector(cl_object v, cl_index amount)
{
	cl_object other;
	cl_index new_length;
	unlikely_if (!ECL_VECTORP(v)) {
		FEwrong_type_nth_arg(ecl_make_fixnum(/*VECTOR-PUSH-EXTEND*/901),1,v,ecl_make_fixnum(/*VECTOR*/898));
	}
	if (!ECL_ADJUSTABLE_ARRAY_P(v))
		FEerror("vector-push-extend: the array ~S is not adjustable.",
			1, v);
	if (v->vector.dim >= ECL_ARRAY_DIMENSION_LIMIT)
		FEerror("Can't extend the array.", 0);
	if (amount == 0)
		amount = v->vector.dim / 2 + 1;
	new_length = v->vector.dim + amount;
	if (new_length > ECL_ARRAY_DIMENSION_LIMIT)
		new_length = ECL_ARRAY_DIMENSION_LIMIT;
	other = si_make_vector(cl_array_element_type(v),
			       ecl_make_fixnum(new_length), ECL_T,
			       ecl_make_fixnum(v->vector.fillp),
			       ECL_NIL, ecl_make_fixnum(0));
	ecl_copy_subarray(other, 0, v, 0, v->vector.fillp);
	return si_replace_array(v, other);
}

ecl_character
ecl_string_push_extend(cl_object s, ecl_character c)
{
	switch(ecl_t_of(s)) {
#ifdef ECL_UNICODE
	case t_string:
#endif
	case t_base_string:
		/* We use the fact that both string types are
		   byte-compatible except for the data. */
		if (s->base_string.fillp >= s->base_string.dim) {
			s = extend_vector(s, 0);
		}
		ecl_char_set(s, s->base_string.fillp++, c);
		return c;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*VECTOR-PUSH-EXTEND*/901),1,s,ecl_make_fixnum(/*STRING*/805));
	}
}

cl_object
cl_vector_push(cl_object value, cl_object v)
{
	cl_index f = ecl_fixnum(cl_fill_pointer(v));
	if (f >= v->vector.dim) {
		{
#line 73
			const cl_env_ptr the_env = ecl_process_env();
#line 73
			#line 73
			cl_object __value0 = ECL_NIL;
#line 73
			the_env->nvalues = 1;
#line 73
			return __value0;
#line 73
		}
;
	} else {
		ecl_aset1(v, v->vector.fillp, value);
		{
#line 76
			const cl_env_ptr the_env = ecl_process_env();
#line 76
			#line 76
			cl_object __value0 = ecl_make_fixnum(v->vector.fillp++);
#line 76
			the_env->nvalues = 1;
#line 76
			return __value0;
#line 76
		}
;
	}
}

#line 80
cl_object cl_vector_push_extend(cl_narg narg, cl_object value, cl_object v, ...)
{
#line 80

#line 82
	const cl_env_ptr the_env = ecl_process_env();
#line 82
	cl_object extent;
#line 82
	va_list ARGS;
	va_start(ARGS, v);
#line 82
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(901));
#line 82
	if (narg > 2) {
#line 82
		extent = va_arg(ARGS,cl_object);
#line 82
	} else {
#line 82
		extent = ecl_make_fixnum(0);
#line 82
	}
#line 82
{
	cl_index f = ecl_fixnum(cl_fill_pointer(v));
	if (f >= v->vector.dim) {
		v = extend_vector(v, ecl_to_size(extent));
	}
	ecl_aset1(v, v->vector.fillp, value);
	{
#line 88
		#line 88
		cl_object __value0 = ecl_make_fixnum(v->vector.fillp++);
#line 88
		the_env->nvalues = 1;
#line 88
		return __value0;
#line 88
	}
;
}
}
