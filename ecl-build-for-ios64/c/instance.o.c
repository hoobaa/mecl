#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/instance.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    instance.c -- CLOS interface.
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

#include <string.h>
#include <ecl/ecl.h>
#include <ecl/internal.h>

cl_object
ecl_allocate_instance(cl_object clas, cl_index size)
{
	cl_object x = ecl_alloc_instance(size);
	cl_index i;
	ECL_CLASS_OF(x) = clas;
	for (i = 0;  i < size;  i++)
		x->instance.slots[i] = ECL_UNBOUND;
	return x;
}

cl_object
si_allocate_raw_instance(cl_object orig, cl_object clas, cl_object size)
{
	cl_object output = ecl_allocate_instance(clas, ecl_to_size(size));
	if (orig == ECL_NIL) {
		orig = output;
	} else {
		orig->instance.clas = clas;
		orig->instance.length = output->instance.length;
		orig->instance.slots = output->instance.slots;
	}
	{
#line 43
		const cl_env_ptr the_env = ecl_process_env();
#line 43
		#line 43
		cl_object __value0 = orig;
#line 43
		the_env->nvalues = 1;
#line 43
		return __value0;
#line 43
	}

}

cl_object
si_instance_sig(cl_object x)
{
	{
#line 49
		const cl_env_ptr the_env = ecl_process_env();
#line 49
		#line 49
		cl_object __value0 = x->instance.sig;
#line 49
		the_env->nvalues = 1;
#line 49
		return __value0;
#line 49
	}
;
}

cl_object
si_instance_sig_set(cl_object x)
{
	{
#line 55
		const cl_env_ptr the_env = ecl_process_env();
#line 55
		#line 55
		cl_object __value0 = (x->instance.sig = ECL_CLASS_SLOTS(ECL_CLASS_OF(x)));
#line 55
		the_env->nvalues = 1;
#line 55
		return __value0;
#line 55
	}
;
}

cl_object
si_instance_class(cl_object x)
{
	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_only_arg(ecl_make_fixnum(/*CLASS-OF*/935), x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	{
#line 63
		const cl_env_ptr the_env = ecl_process_env();
#line 63
		#line 63
		cl_object __value0 = ECL_CLASS_OF(x);
#line 63
		the_env->nvalues = 1;
#line 63
		return __value0;
#line 63
	}

}

cl_object
si_instance_class_set(cl_object x, cl_object y)
{
	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-CLASS-SET*/1174), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	if (ecl_unlikely(!ECL_INSTANCEP(y)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-CLASS-SET*/1174), 2, y, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	ECL_CLASS_OF(x) = y;
	{
#line 74
		const cl_env_ptr the_env = ecl_process_env();
#line 74
		#line 74
		cl_object __value0 = x;
#line 74
		the_env->nvalues = 1;
#line 74
		return __value0;
#line 74
	}

}

cl_object
ecl_instance_ref(cl_object x, cl_fixnum i)
{
	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-REF*/1169), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	if (ecl_unlikely(i < 0 || i >= (cl_fixnum)x->instance.length))
	        FEtype_error_index(x, i);
	return(x->instance.slots[i]);
}

cl_object
si_instance_ref(cl_object x, cl_object index)
{
	cl_fixnum i;

	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-REF*/1169), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	if (ecl_unlikely(!ECL_FIXNUMP(index)))
		FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-REF*/1169), 2, index, ecl_make_fixnum(/*FIXNUM*/372));
	i = ecl_fixnum(index);
	if (ecl_unlikely(i < 0 || i >= (cl_fixnum)x->instance.length))
		FEtype_error_index(x, i);
	{
#line 99
		const cl_env_ptr the_env = ecl_process_env();
#line 99
		#line 99
		cl_object __value0 = x->instance.slots[i];
#line 99
		the_env->nvalues = 1;
#line 99
		return __value0;
#line 99
	}

}

#ifdef CLOS
cl_object
clos_safe_instance_ref(cl_object x, cl_object index)
{
	cl_fixnum i;

	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-REF*/1169), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	if (ecl_unlikely(!ECL_FIXNUMP(index)))
		FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-REF*/1169), 2, index, ecl_make_fixnum(/*FIXNUM*/372));
	i = ecl_fixnum(index);
	if (ecl_unlikely(i < 0 || i >= x->instance.length))
		FEtype_error_index(x, i);
	x = x->instance.slots[i];
	if (ecl_unlikely(x == ECL_UNBOUND))
		x = _ecl_funcall4(ECL_SYM("SLOT-UNBOUND",970), ECL_NIL, x, index);
	{
#line 118
		const cl_env_ptr the_env = ecl_process_env();
#line 118
		#line 118
		cl_object __value0 = x;
#line 118
		the_env->nvalues = 1;
#line 118
		return __value0;
#line 118
	}

}
#endif

cl_object
ecl_instance_set(cl_object x, cl_fixnum i, cl_object v)
{
        if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-SET*/1170), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	if (ecl_unlikely(i >= x->instance.length || i < 0))
	        FEtype_error_index(x, i);
	x->instance.slots[i] = v;
	return(v);
}

cl_object
si_instance_set(cl_object x, cl_object index, cl_object value)
{
	cl_fixnum i;

	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-SET*/1170), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	if (ecl_unlikely(!ECL_FIXNUMP(index)))
		FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::INSTANCE-SET*/1170), 2, index, ecl_make_fixnum(/*FIXNUM*/372));
	i = ecl_fixnum(index);
	if (ecl_unlikely(i >= (cl_fixnum)x->instance.length || i < 0))
		FEtype_error_index(x, i);
	x->instance.slots[i] = value;
	{
#line 146
		const cl_env_ptr the_env = ecl_process_env();
#line 146
		#line 146
		cl_object __value0 = value;
#line 146
		the_env->nvalues = 1;
#line 146
		return __value0;
#line 146
	}

}

cl_object
si_instancep(cl_object x)
{
	{
#line 152
		const cl_env_ptr the_env = ecl_process_env();
#line 152
		#line 152
		cl_object __value0 = (ECL_INSTANCEP(x) ? ecl_make_fixnum(x->instance.length) : ECL_NIL);
#line 152
		the_env->nvalues = 1;
#line 152
		return __value0;
#line 152
	}

}

cl_object
si_unbound()
{
	/* Returns an object that cannot be read or written and which
	   is used to represent an unitialized slot */
	{
#line 160
		const cl_env_ptr the_env = ecl_process_env();
#line 160
		#line 160
		cl_object __value0 = ECL_UNBOUND;
#line 160
		the_env->nvalues = 1;
#line 160
		return __value0;
#line 160
	}

}

cl_object
si_sl_boundp(cl_object x)
{
	{
#line 166
		const cl_env_ptr the_env = ecl_process_env();
#line 166
		#line 166
		cl_object __value0 = ((x == ECL_UNBOUND) ? ECL_NIL : ECL_T);
#line 166
		the_env->nvalues = 1;
#line 166
		return __value0;
#line 166
	}

}

cl_object
si_sl_makunbound(cl_object x, cl_object index)
{
	cl_fixnum i;

	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::SL-MAKUNBOUND*/1177), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	if (ecl_unlikely(!ECL_FIXNUMP(index)))
		FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::SL-MAKUNBOUND*/1177), 2, index, ecl_make_fixnum(/*FIXNUM*/372));
	i = ecl_fixnum(index);
	unlikely_if (i >= x->instance.length || i < 0)
		FEtype_error_index(x, i);
	x->instance.slots[i] = ECL_UNBOUND;
	{
#line 182
		const cl_env_ptr the_env = ecl_process_env();
#line 182
		#line 182
		cl_object __value0 = x;
#line 182
		the_env->nvalues = 1;
#line 182
		return __value0;
#line 182
	}

}

cl_object
si_copy_instance(cl_object x)
{
	cl_object y;

	if (ecl_unlikely(!ECL_INSTANCEP(x)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::COPY-INSTANCE*/1167), 1, x, ecl_make_fixnum(/*EXT::INSTANCE*/1342));
	y = ecl_allocate_instance(x->instance.clas, x->instance.length);
	y->instance.sig = x->instance.sig;
	memcpy(y->instance.slots, x->instance.slots,
	       x->instance.length * sizeof(cl_object));
	{
#line 196
		const cl_env_ptr the_env = ecl_process_env();
#line 196
		#line 196
		cl_object __value0 = y;
#line 196
		the_env->nvalues = 1;
#line 196
		return __value0;
#line 196
	}

}

#line 199
cl_object cl_find_class(cl_narg narg, cl_object name, ...)
{
#line 199

	cl_object class, hash;
#line 202
	const cl_env_ptr the_env = ecl_process_env();
#line 202
	cl_object errorp;
#line 202
	cl_object env;
#line 202
	va_list ARGS;
	va_start(ARGS, name);
#line 202
	if (ecl_unlikely(narg < 1|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(943));
#line 202
	if (narg > 1) {
#line 202
		errorp = va_arg(ARGS,cl_object);
#line 202
	} else {
#line 202
		errorp = ECL_T;
#line 202
	}
#line 202
	if (narg > 2) {
#line 202
		env = va_arg(ARGS,cl_object);
#line 202
	} else {
#line 202
		env = ECL_NIL;
#line 202
	}
#line 202
	hash = ECL_SYM_VAL(the_env, ECL_SYM("SI::*CLASS-NAME-HASH-TABLE*",1016));
	class = ecl_gethash_safe(name, hash, ECL_NIL);
	if (class == ECL_NIL) {
		if (!Null(errorp))
			FEerror("No class named ~S.", 1, name);
	}
	{
#line 208
		#line 208
		cl_object __value0 = class;
#line 208
		the_env->nvalues = 1;
#line 208
		return __value0;
#line 208
	}

}

cl_object
ecl_slot_value(cl_object x, const char *slot)
{
	cl_object slot_name = ecl_read_from_cstring(slot);
	return funcall(3, ECL_SYM("SLOT-VALUE",971), x, slot_name);
}

cl_object
ecl_slot_value_set(cl_object x, const char *slot, cl_object value)
{
	cl_object slot_name = ecl_read_from_cstring(slot);
	cl_object slot_setter = ecl_read_from_cstring("(SETF SLOT-VALUE)");
	return funcall(4, ecl_fdefinition(slot_setter), value, x, slot_name);
}

/**********************************************************************
 * IMPORTANT: THE FOLLOWING LIST IS LINKED TO src/clos/builtin.lsp
 **********************************************************************/
enum ecl_built_in_classes {
	ECL_BUILTIN_T = 0,
	ECL_BUILTIN_SEQUENCE,
	ECL_BUILTIN_LIST,
	ECL_BUILTIN_CONS,
	ECL_BUILTIN_ARRAY,
	ECL_BUILTIN_VECTOR,
	ECL_BUILTIN_STRING,
#ifdef ECL_UNICODE
	ECL_BUILTIN_BASE_STRING,
#endif
	ECL_BUILTIN_BIT_VECTOR,
	ECL_BUILTIN_STREAM,
	ECL_BUILTIN_ANSI_STREAM,
	ECL_BUILTIN_FILE_STREAM,
	ECL_BUILTIN_ECHO_STREAM,
	ECL_BUILTIN_STRING_STREAM,
	ECL_BUILTIN_TWO_WAY_STREAM,
	ECL_BUILTIN_SYNONYM_STREAM,
	ECL_BUILTIN_BROADCAST_STREAM,
	ECL_BUILTIN_CONCATENATED_STREAM,
	ECL_BUILTIN_SEQUENCE_STREAM,
	ECL_BUILTIN_CHARACTER,
	ECL_BUILTIN_NUMBER,
	ECL_BUILTIN_REAL,
	ECL_BUILTIN_RATIONAL,
	ECL_BUILTIN_INTEGER,
	ECL_BUILTIN_RATIO,
	ECL_BUILTIN_FLOAT,
	ECL_BUILTIN_COMPLEX,
	ECL_BUILTIN_SYMBOL,
	ECL_BUILTIN_NULL,
	ECL_BUILTIN_KEYWORD,
	ECL_BUILTIN_PACKAGE,
	ECL_BUILTIN_FUNCTION,
	ECL_BUILTIN_PATHNAME,
	ECL_BUILTIN_LOGICAL_PATHNAME,
	ECL_BUILTIN_HASH_TABLE,
	ECL_BUILTIN_RANDOM_STATE,
	ECL_BUILTIN_READTABLE,
	ECL_BUILTIN_CODE_BLOCK,
	ECL_BUILTIN_FOREIGN_DATA,
	ECL_BUILTIN_FRAME,
	ECL_BUILTIN_WEAK_POINTER
#ifdef ECL_THREADS
        ,
	ECL_BUILTIN_PROCESS,
	ECL_BUILTIN_LOCK,
	ECL_BUILTIN_RWLOCK,
	ECL_BUILTIN_CONDITION_VARIABLE,
        ECL_BUILTIN_SEMAPHORE,
	ECL_BUILTIN_BARRIER,
	ECL_BUILTIN_MAILBOX
#endif
#ifdef ECL_SSE2
	, ECL_BUILTIN_SSE_PACK
#endif
};

cl_object
cl_class_of(cl_object x)
{
	size_t index;
	switch (ecl_t_of(x)) {
	case t_instance:
		{
#line 294
			const cl_env_ptr the_env = ecl_process_env();
#line 294
			#line 294
			cl_object __value0 = ECL_CLASS_OF(x);
#line 294
			the_env->nvalues = 1;
#line 294
			return __value0;
#line 294
		}

	case t_fixnum:
	case t_bignum:
		index = ECL_BUILTIN_INTEGER; break;
	case t_ratio:
		index = ECL_BUILTIN_RATIO; break;
	case t_singlefloat:
	case t_doublefloat:
#ifdef ECL_LONG_FLOAT
	case t_longfloat:
#endif
		index = ECL_BUILTIN_FLOAT; break;
		/* XXX index = ECL_BUILTIN_long-float; break; */
	case t_complex:
		index = ECL_BUILTIN_COMPLEX; break;
	case t_character:
		index = ECL_BUILTIN_CHARACTER; break;
	case t_symbol:
		if (x->symbol.hpack == cl_core.keyword_package)
			index = ECL_BUILTIN_KEYWORD;
		else
			index = ECL_BUILTIN_SYMBOL;
		break;
	case t_package:
		index = ECL_BUILTIN_PACKAGE; break;
	case t_list:
		index = Null(x)? ECL_BUILTIN_NULL : ECL_BUILTIN_CONS; break;
	case t_hashtable:
		index = ECL_BUILTIN_HASH_TABLE; break;
	case t_array:
		index = ECL_BUILTIN_ARRAY; break;
	case t_vector:
		index = ECL_BUILTIN_VECTOR; break;
#ifdef ECL_UNICODE
	case t_string:
		index = ECL_BUILTIN_STRING; break;
	case t_base_string:
		index = ECL_BUILTIN_BASE_STRING; break;
#else
	case t_base_string:
		index = ECL_BUILTIN_STRING; break;
#endif
	case t_bitvector:
		index = ECL_BUILTIN_BIT_VECTOR; break;
	case t_stream:
		switch (x->stream.mode) {
		case ecl_smm_synonym:	index = ECL_BUILTIN_SYNONYM_STREAM; break;
		case ecl_smm_broadcast:	index = ECL_BUILTIN_BROADCAST_STREAM; break;
		case ecl_smm_concatenated:	index = ECL_BUILTIN_CONCATENATED_STREAM; break;
		case ecl_smm_two_way:	index = ECL_BUILTIN_TWO_WAY_STREAM; break;
		case ecl_smm_string_input:
		case ecl_smm_string_output:	index = ECL_BUILTIN_STRING_STREAM; break;
		case ecl_smm_echo:		index = ECL_BUILTIN_ECHO_STREAM; break;
                case ecl_smm_sequence_input:
                case ecl_smm_sequence_output: index = ECL_BUILTIN_SEQUENCE_STREAM; break;
		default:		index = ECL_BUILTIN_FILE_STREAM; break;
		}
		break;
	case t_readtable:
		index = ECL_BUILTIN_READTABLE; break;
	case t_pathname:
		index = ECL_BUILTIN_PATHNAME; break;
	case t_random:
		index = ECL_BUILTIN_RANDOM_STATE; break;
	case t_bytecodes:
	case t_bclosure:
	case t_cfun:
	case t_cfunfixed:
	case t_cclosure:
		index = ECL_BUILTIN_FUNCTION; break;
#ifdef ECL_THREADS
	case t_process:
		index = ECL_BUILTIN_PROCESS; break;
	case t_lock:
		index = ECL_BUILTIN_LOCK; break;
	case t_condition_variable:
		index = ECL_BUILTIN_CONDITION_VARIABLE; break;
	case t_semaphore:
		index = ECL_BUILTIN_SEMAPHORE; break;
	case t_barrier:
		index = ECL_BUILTIN_BARRIER; break;
	case t_mailbox:
		index = ECL_BUILTIN_MAILBOX; break;
#endif
	case t_codeblock:
		index = ECL_BUILTIN_CODE_BLOCK; break;
	case t_foreign:
		index = ECL_BUILTIN_FOREIGN_DATA; break;
	case t_frame:
		index = ECL_BUILTIN_FRAME; break;
	case t_weak_pointer:
		index = ECL_BUILTIN_WEAK_POINTER; break;
#ifdef ECL_SSE2
	case t_sse_pack:
		index = ECL_BUILTIN_SSE_PACK; break;
#endif
	default:
		ecl_internal_error("not a lisp data object");
	}
	{
		/* We have to be careful because +builtin-classes+ might be empty! */
		/* In any case, since +builtin-classes+ is a constant, we may
		 * optimize the slot access */
		cl_object v = ECL_SYM("CLOS::+BUILTIN-CLASSES+",1474)->symbol.value;
		cl_object output = Null(v)?
			cl_find_class(1,ECL_SYM("T",1)) :
			v->vector.self.t[index];
		{
#line 401
			const cl_env_ptr the_env = ecl_process_env();
#line 401
			#line 401
			cl_object __value0 = output;
#line 401
			the_env->nvalues = 1;
#line 401
			return __value0;
#line 401
		}

	}
}

