#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/ffi.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    ffi.c -- User defined data types and foreign functions interface.
*/
/*
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <string.h>
#define ECL_INCLUDE_FFI_H
#include <ecl/ecl.h>
#include <ecl/internal.h>

static const cl_object ecl_aet_to_ffi_table[ecl_aet_bc+1] = {
	ECL_SYM(":VOID",1381), /* ecl_aet_object */
	ECL_SYM(":FLOAT",1368), /* ecl_aet_df */
	ECL_SYM(":DOUBLE",1366), /* ecl_aet_df */
	ECL_SYM(":VOID",1381), /* ecl_aet_bit */
#if ECL_FIXNUM_BITS == 32 && defined(ecl_uint32_t)
        ECL_SYM(":INT32-T",1372), /* ecl_aet_fix */
        ECL_SYM(":UINT32-T",1384), /* ecl_aet_index */
#else
# if ECL_FIXNUM_BITS == 64 && defined(ecl_uint64_t)
        ECL_SYM(":INT64-T",1373), /* ecl_aet_fix */
        ECL_SYM(":UINT64-T",1385), /* ecl_aet_index */
# else
        ECL_SYM(":VOID",1381), /* ecl_aet_fix */
        ECL_SYM(":VOID",1381), /* ecl_aet_index */
# endif
#endif
	ECL_SYM(":UINT8-T",1382), /* ecl_aet_b8 */
        ECL_SYM(":INT8-T",1370), /* ecl_aet_i8 */
#ifdef ecl_uint16_t
        ECL_SYM(":UINT16-T",1383), /* ecl_aet_b16 */
        ECL_SYM(":INT16-T",1371), /* ecl_aet_i16 */
#endif
#ifdef ecl_uint32_t
        ECL_SYM(":UINT32-T",1384), /* ecl_aet_b32 */
        ECL_SYM(":INT32-T",1372), /* ecl_aet_i32 */
#endif
#ifdef ecl_uint64_t
        ECL_SYM(":UINT64-T",1385), /* ecl_aet_b64 */
        ECL_SYM(":INT64-T",1373), /* ecl_aet_i64 */
#endif
#ifdef ECL_UNICODE
# ifdef ecl_int32_t
	ECL_SYM(":INT32-T",1372), /* ecl_aet_ch */
# else
        ECL_SYM(":VOID",1381), /* ecl_aet_ch */
# endif
#endif
	ECL_SYM(":CHAR",1364) /* ecl_aet_bc */
};

#define AUX_PTR(type) \
	((struct { char a[1]; union { type c[1]; char d[sizeof(type)]; } b; } *)0)
#ifdef __GNUC__
typedef struct {
	cl_object name;
	cl_index size;
	cl_index alignment;
} ecl_foreign_type_record;
# define ALIGNMENT(tag) (ecl_foreign_type_table[tag].alignment)
# define FFI_DESC(symbol,type)			\
  {symbol, sizeof(type), (AUX_PTR(type)->b.d - AUX_PTR(type)->a)}
#else
typedef struct {
	cl_object name;
	cl_index size;
	char *d, *a;
} ecl_foreign_type_record;
#define ALIGNMENT(tag) (ecl_foreign_type_table[tag].d - ecl_foreign_type_table[tag].a)
#define AUX_PTR(type) \
	((struct { char a[1]; union { type c[1]; char d[sizeof(type)]; } b; } *)0)
#define FFI_DESC(symbol,type) \
  {symbol, sizeof(type), AUX_PTR(type)->b.d, AUX_PTR(type)->a}
#endif

static const ecl_foreign_type_record
ecl_foreign_type_table[] = {
	FFI_DESC(ECL_SYM(":CHAR",1364), char),
	FFI_DESC(ECL_SYM(":UNSIGNED-CHAR",1387), unsigned char),
	FFI_DESC(ECL_SYM(":BYTE",1363), ecl_int8_t),
        FFI_DESC(ECL_SYM(":UNSIGNED-BYTE",1386), ecl_uint8_t),
	FFI_DESC(ECL_SYM(":SHORT",1378), short),
	FFI_DESC(ECL_SYM(":UNSIGNED-SHORT",1391), unsigned short),
	FFI_DESC(ECL_SYM(":INT",1369), int),
	FFI_DESC(ECL_SYM(":UNSIGNED-INT",1388), unsigned int),
	FFI_DESC(ECL_SYM(":LONG",1374), long),
	FFI_DESC(ECL_SYM(":UNSIGNED-LONG",1389), unsigned long),
#ifdef ecl_uint8_t
        FFI_DESC(ECL_SYM(":INT8-T",1370), ecl_int8_t),
        FFI_DESC(ECL_SYM(":UINT8-T",1382), ecl_uint8_t),
#endif
#ifdef ecl_uint16_t
        FFI_DESC(ECL_SYM(":INT16-T",1371), ecl_int16_t),
        FFI_DESC(ECL_SYM(":UINT16-T",1383), ecl_uint16_t),
#endif
#ifdef ecl_uint32_t
        FFI_DESC(ECL_SYM(":INT32-T",1372), ecl_int32_t),
        FFI_DESC(ECL_SYM(":UINT32-T",1384), ecl_uint32_t),
#endif
#ifdef ecl_uint64_t
        FFI_DESC(ECL_SYM(":INT64-T",1373), ecl_int64_t),
        FFI_DESC(ECL_SYM(":UINT64-T",1385), ecl_uint64_t),
#endif
#ifdef ecl_long_long_t
        FFI_DESC(ECL_SYM(":LONG-LONG",1375), long long),
        FFI_DESC(ECL_SYM(":UNSIGNED-LONG-LONG",1390), unsigned long long),
#endif
	FFI_DESC(ECL_SYM(":POINTER-VOID",1377), void *),
	FFI_DESC(ECL_SYM(":CSTRING",1365), char *),
	FFI_DESC(ECL_SYM(":OBJECT",1278), cl_object),
	FFI_DESC(ECL_SYM(":FLOAT",1368), float),
	FFI_DESC(ECL_SYM(":DOUBLE",1366), double),
	{ECL_SYM(":VOID",1381), 0, 0}
};

#ifdef ECL_DYNAMIC_FFI
static const cl_object ecl_foreign_cc_table[] = {
	ECL_SYM(":CDECL",1593),
	ECL_SYM(":STDCALL",1594)
};
#endif

#ifdef HAVE_LIBFFI
static struct {
        const cl_object symbol;
        ffi_abi abi;
} ecl_foreign_cc_table[] = {
        {ECL_SYM(":DEFAULT",1215), FFI_DEFAULT_ABI},
#ifdef X86_WIN32
	{ECL_SYM(":CDECL",1593), FFI_SYSV},
	{ECL_SYM(":SYSV",1724), FFI_SYSV},
	{ECL_SYM(":STDCALL",1594), FFI_STDCALL},
#elif defined(X86_WIN64)
	{ECL_SYM(":WIN64",1726), FFI_WIN64},
#elif defined(X86_ANY) || defined(X86) || defined(X86_64)
	{ECL_SYM(":CDECL",1593), FFI_SYSV},
	{ECL_SYM(":SYSV",1724), FFI_SYSV},
	{ECL_SYM(":UNIX64",1725), FFI_UNIX64},
#endif
};

static ffi_type *ecl_type_to_libffi_type[] = {
	&ffi_type_schar, /*ECL_SYM(":CHAR",1364),*/
	&ffi_type_uchar, /*ECL_SYM(":UNSIGNED-CHAR",1387),*/
	&ffi_type_sint8, /*ECL_SYM(":BYTE",1363),*/
	&ffi_type_uint8, /*ECL_SYM(":UNSIGNED-BYTE",1386),*/
	&ffi_type_sshort, /*ECL_SYM(":SHORT",1378),*/
	&ffi_type_ushort, /*ECL_SYM(":UNSIGNED-SHORT",1391),*/
	&ffi_type_sint, /*ECL_SYM(":INT",1369),*/
	&ffi_type_uint, /*ECL_SYM(":UNSIGNED-INT",1388),*/
	&ffi_type_slong, /*ECL_SYM(":LONG",1374),*/
	&ffi_type_ulong, /*ECL_SYM(":UNSIGNED-LONG",1389),*/
#ifdef ecl_uint8_t
        &ffi_type_sint8, /*ECL_SYM(":INT8-T",1370),*/
        &ffi_type_uint8, /*ECL_SYM(":UINT8-T",1382),*/
#endif
#ifdef ecl_uint16_t
        &ffi_type_sint16, /*ECL_SYM(":INT16-T",1371),*/
        &ffi_type_uint16, /*ECL_SYM(":UINT16-T",1383),*/
#endif
#ifdef ecl_uint32_t
        &ffi_type_sint32, /*ECL_SYM(":INT32-T",1372),*/
        &ffi_type_uint32, /*ECL_SYM(":UINT32-T",1384),*/
#endif
#ifdef ecl_uint64_t
        &ffi_type_sint64, /*ECL_SYM(":INT64-T",1373),*/
        &ffi_type_uint64, /*ECL_SYM(":UINT64-T",1385),*/
#endif
#ifdef ecl_long_long_t
        &ffi_type_sint64, /*ECL_SYM(":LONG-LONG",1375),*/ /*FIXME! libffi does not have long long */
        &ffi_type_uint64, /*ECL_SYM(":UNSIGNED-LONG-LONG",1390),*/
#endif
	&ffi_type_pointer, /*ECL_SYM(":POINTER-VOID",1377),*/
	&ffi_type_pointer, /*ECL_SYM(":CSTRING",1365),*/
	&ffi_type_pointer, /*ECL_SYM(":OBJECT",1278),*/
	&ffi_type_float, /*ECL_SYM(":FLOAT",1368),*/
	&ffi_type_double, /*ECL_SYM(":DOUBLE",1366),*/
	&ffi_type_void /*ECL_SYM(":VOID",1381)*/
};
#endif /* HAVE_LIBFFI */

cl_object
ecl_make_foreign_data(cl_object tag, cl_index size, void *data)
{
	cl_object output = ecl_alloc_object(t_foreign);
	output->foreign.tag = tag == ECL_NIL ? ECL_SYM(":VOID",1381) : tag;
	output->foreign.size = size;
	output->foreign.data = (char*)data;
	return output;
}

cl_object
ecl_allocate_foreign_data(cl_object tag, cl_index size)
{
	cl_object output = ecl_alloc_object(t_foreign);
	output->foreign.tag = tag;
	output->foreign.size = size;
	output->foreign.data = (char*)ecl_alloc_atomic(size);
	return output;
}

void *
ecl_foreign_data_pointer_safe(cl_object f)
{
	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-POINTER*/1349), f,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
        }
	return f->foreign.data;
}

char *
ecl_base_string_pointer_safe(cl_object f)
{
	unsigned char *s;
	/* FIXME! Is there a better function name? */
	f = ecl_check_cl_type(ECL_SYM("SI::MAKE-FOREIGN-DATA-FROM-ARRAY",1358), f, t_base_string);
	s = f->base_string.self;
	if (ecl_unlikely(ECL_ARRAY_HAS_FILL_POINTER_P(f) &&
                         s[f->base_string.fillp] != 0)) {
		FEerror("Cannot coerce a string with fill pointer to (char *)", 0);
	}
	return (char *)s;
}

cl_object
ecl_null_terminated_base_string(cl_object f)
{
	/* FIXME! Is there a better function name? */
	f = ecl_check_cl_type(ECL_SYM("SI::MAKE-FOREIGN-DATA-FROM-ARRAY",1358), f, t_base_string);
	if (ECL_ARRAY_HAS_FILL_POINTER_P(f) &&
            f->base_string.self[f->base_string.fillp] != 0) {
		return cl_copy_seq(f);
	} else {
		return f;
	}
}

cl_object
si_allocate_foreign_data(cl_object tag, cl_object size)
{
	cl_object output = ecl_alloc_object(t_foreign);
	cl_index bytes = ecl_to_size(size);
	output->foreign.tag = tag;
	output->foreign.size = bytes;
	/* FIXME! Should be atomic uncollectable or malloc, but we do not export
	 * that garbage collector interface and malloc may be overwritten
	 * by the GC library */
	output->foreign.data = bytes? ecl_alloc_uncollectable(bytes) : NULL;
	{
#line 260
		const cl_env_ptr the_env = ecl_process_env();
#line 260
		#line 260
		cl_object __value0 = output;
#line 260
		the_env->nvalues = 1;
#line 260
		return __value0;
#line 260
	}

}

cl_object
si_free_foreign_data(cl_object f)
{
	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::FREE-FOREIGN-DATA*/1357), f,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	if (f->foreign.size) {
		/* See si_allocate_foreign_data() */
		ecl_free_uncollectable(f->foreign.data);
	}
	f->foreign.size = 0;
	f->foreign.data = NULL;
        {
#line 276
	const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 276
}

}

cl_object
si_make_foreign_data_from_array(cl_object array)
{
	cl_object tag;
	if (ecl_unlikely(ecl_t_of(array) != t_array && ecl_t_of(array) != t_vector)) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::MAKE-FOREIGN-DATA-FROM-ARRAY*/1358), array,
                                      ecl_make_fixnum(/*ARRAY*/96));
	}
        tag = ecl_aet_to_ffi_table[array->array.elttype];
        if (ecl_unlikely(Null(tag))) {
		FEerror("Cannot make foreign object from array "
                        "with element type ~S.", 1,
                        ecl_elttype_to_symbol(array->array.elttype));
	}
	{
#line 293
		const cl_env_ptr the_env = ecl_process_env();
#line 293
		#line 293
		cl_object __value0 = ecl_make_foreign_data(tag, 0, array->array.self.bc);
#line 293
		the_env->nvalues = 1;
#line 293
		return __value0;
#line 293
	}
;
}

cl_object
si_foreign_data_p(cl_object f)
{
        {
#line 299
	const cl_env_ptr the_env = ecl_process_env();
#line 299
	#line 299
	cl_object __value0 = (ECL_FOREIGN_DATA_P(f)? ECL_T : ECL_NIL);
#line 299
	the_env->nvalues = 1;
#line 299
	return __value0;
#line 299
}

}

cl_object
si_foreign_data_address(cl_object f)
{
	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-ADDRESS*/1346), f,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	{
#line 309
		const cl_env_ptr the_env = ecl_process_env();
#line 309
		#line 309
		cl_object __value0 = ecl_make_unsigned_integer((cl_index)f->foreign.data);
#line 309
		the_env->nvalues = 1;
#line 309
		return __value0;
#line 309
	}

}

cl_object
si_foreign_data_tag(cl_object f)
{
	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-TAG*/1355), f,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	{
#line 319
		const cl_env_ptr the_env = ecl_process_env();
#line 319
		#line 319
		cl_object __value0 = f->foreign.tag;
#line 319
		the_env->nvalues = 1;
#line 319
		return __value0;
#line 319
	}
;
}

cl_object
si_foreign_data_equal(cl_object f1, cl_object f2)
{
	if (ecl_unlikely(!ECL_FOREIGN_DATA_P(f1))) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-ADDRESS*/1346), f1,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	if (ecl_unlikely(!ECL_FOREIGN_DATA_P(f2))) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-ADDRESS*/1346), f2,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	{
#line 333
		const cl_env_ptr the_env = ecl_process_env();
#line 333
		#line 333
		cl_object __value0 = ((f1->foreign.data == f2->foreign.data)? ECL_T : ECL_NIL);
#line 333
		the_env->nvalues = 1;
#line 333
		return __value0;
#line 333
	}

}

cl_object
si_foreign_data_pointer(cl_object f, cl_object andx, cl_object asize,
			cl_object tag)
{
	cl_index ndx = ecl_to_size(andx);
	cl_index size = ecl_to_size(asize);
	cl_object output;

	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-POINTER*/1349), f,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	if (ecl_unlikely(ndx >= f->foreign.size || (f->foreign.size - ndx) < size)) {
		FEerror("Out of bounds reference into foreign data type ~A.", 1, f);
	}
	output = ecl_alloc_object(t_foreign);
	output->foreign.tag = tag;
	output->foreign.size = size;
	output->foreign.data = f->foreign.data + ndx;
	{
#line 355
		const cl_env_ptr the_env = ecl_process_env();
#line 355
		#line 355
		cl_object __value0 = output;
#line 355
		the_env->nvalues = 1;
#line 355
		return __value0;
#line 355
	}

}

cl_object
si_foreign_data_ref(cl_object f, cl_object andx, cl_object asize, cl_object tag)
{
	cl_index ndx = ecl_to_size(andx);
	cl_index size = ecl_to_size(asize);
	cl_object output;

	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-REF*/1351), 1, f,
                                     ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	if (ecl_unlikely(ndx >= f->foreign.size || (f->foreign.size - ndx) < size)) {
		FEerror("Out of bounds reference into foreign data type ~A.", 1, f);
	}
	output = ecl_allocate_foreign_data(tag, size);
	memcpy(output->foreign.data, f->foreign.data + ndx, size);
	{
#line 374
		const cl_env_ptr the_env = ecl_process_env();
#line 374
		#line 374
		cl_object __value0 = output;
#line 374
		the_env->nvalues = 1;
#line 374
		return __value0;
#line 374
	}

}

cl_object
si_foreign_data_set(cl_object f, cl_object andx, cl_object value)
{
	cl_index ndx = ecl_to_size(andx);
	cl_index size, limit;

	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-SET*/1353), 1, f,
                                     ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	if (ecl_unlikely(ecl_t_of(value) != t_foreign)) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-SET*/1353), 3, value,
                                     ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	size = value->foreign.size;
	limit = f->foreign.size;
	if (ecl_unlikely(ndx >= limit || (limit - ndx) < size)) {
		FEerror("Out of bounds reference into foreign data type ~A.", 1, f);
	}
	memcpy(f->foreign.data + ndx, value->foreign.data, size);
	{
#line 397
		const cl_env_ptr the_env = ecl_process_env();
#line 397
		#line 397
		cl_object __value0 = value;
#line 397
		the_env->nvalues = 1;
#line 397
		return __value0;
#line 397
	}

}

static int
foreign_type_code(cl_object type)
{
	int i;
	for (i = 0; i <= ECL_FFI_VOID; i++) {
		if (type == ecl_foreign_type_table[i].name)
			return i;
	}
        return -1;
}

enum ecl_ffi_tag
ecl_foreign_type_code(cl_object type)
{
	int i = foreign_type_code(type);
        if (ecl_unlikely(i < 0)) {
                FEerror("~A does not denote an elementary foreign type.", 1, type);
        }
	return (enum ecl_ffi_tag)i;
}

#ifdef HAVE_LIBFFI
ffi_abi
ecl_foreign_cc_code(cl_object cc)
{
	int i;
	for (i = 0; i <= ECL_FFI_CC_STDCALL; i++) {
		if (cc == ecl_foreign_cc_table[i].symbol)
			return ecl_foreign_cc_table[i].abi;
	}
	FEerror("~A does no denote a valid calling convention.", 1, cc);
	return ECL_FFI_CC_CDECL;
}
#endif

#ifdef ECL_DYNAMIC_FFI
enum ecl_ffi_calling_convention
ecl_foreign_cc_code(cl_object cc)
{
	int i;
	for (i = 0; i <= ECL_FFI_CC_STDCALL; i++) {
		if (cc == ecl_foreign_cc_table[i])
			return (enum ecl_ffi_calling_convention)i;
	}
	FEerror("~A does no denote a valid calling convention.", 1, cc);
	return ECL_FFI_CC_CDECL;
}
#endif

static void wrong_ffi_tag(enum ecl_ffi_tag tag) ecl_attr_noreturn;

static void
wrong_ffi_tag(enum ecl_ffi_tag tag)
{
	FEerror("Invalid ecl_ffi_tag code ~D", 1, ecl_make_integer(tag));
}

cl_object
ecl_foreign_data_ref_elt(void *p, enum ecl_ffi_tag tag)
{
	switch (tag) {
	case ECL_FFI_CHAR:
		return ECL_CODE_CHAR(*(char *)p);
	case ECL_FFI_UNSIGNED_CHAR:
		return ECL_CODE_CHAR(*(unsigned char *)p);
	case ECL_FFI_BYTE:
		return ecl_make_fixnum(*(int8_t *)p);
	case ECL_FFI_UNSIGNED_BYTE:
		return ecl_make_fixnum(*(uint8_t *)p);
	case ECL_FFI_SHORT:
		return ecl_make_fixnum(*(short *)p);
	case ECL_FFI_UNSIGNED_SHORT:
		return ecl_make_fixnum(*(unsigned short *)p);
	case ECL_FFI_INT:
		return ecl_make_integer(*(int *)p);
	case ECL_FFI_UNSIGNED_INT:
		return ecl_make_unsigned_integer(*(unsigned int *)p);
	case ECL_FFI_LONG:
		return ecl_make_integer(*(long *)p);
#ifdef ecl_uint8_t
        case ECL_FFI_INT8_T:
                return ecl_make_fixnum(*(ecl_int8_t *)p);
        case ECL_FFI_UINT8_T:
                return ecl_make_fixnum(*(ecl_uint8_t *)p);
#endif
#ifdef ecl_uint16_t
        case ECL_FFI_INT16_T:
                return ecl_make_int16_t(*(ecl_int16_t *)p);
        case ECL_FFI_UINT16_T:
                return ecl_make_uint16_t(*(ecl_uint16_t *)p);
#endif
#ifdef ecl_uint32_t
        case ECL_FFI_INT32_T:
                return ecl_make_int32_t(*(ecl_int32_t *)p);
        case ECL_FFI_UINT32_T:
                return ecl_make_uint32_t(*(ecl_uint32_t *)p);
#endif
#ifdef ecl_uint64_t
        case ECL_FFI_INT64_T:
                return ecl_make_int64_t(*(ecl_int64_t *)p);
        case ECL_FFI_UINT64_T:
                return ecl_make_uint64_t(*(ecl_uint64_t *)p);
#endif
#ifdef ecl_long_long_t
        case ECL_FFI_LONG_LONG:
                return ecl_make_long_long(*(ecl_long_long_t *)p);
        case ECL_FFI_UNSIGNED_LONG_LONG:
                return ecl_make_ulong_long(*(ecl_ulong_long_t *)p);
#endif
	case ECL_FFI_UNSIGNED_LONG:
		return ecl_make_unsigned_integer(*(unsigned long *)p);
	case ECL_FFI_POINTER_VOID:
		return ecl_make_foreign_data(ECL_SYM(":POINTER-VOID",1377), 0, *(void **)p);
	case ECL_FFI_CSTRING:
		return *(char **)p ?
                        ecl_make_simple_base_string(*(char **)p, -1) : ECL_NIL;
	case ECL_FFI_OBJECT:
		return *(cl_object *)p;
	case ECL_FFI_FLOAT:
		return ecl_make_single_float(*(float *)p);
	case ECL_FFI_DOUBLE:
		return ecl_make_double_float(*(double *)p);
	case ECL_FFI_VOID:
		return ECL_NIL;
        default:
                wrong_ffi_tag(tag);
	}
}

void
ecl_foreign_data_set_elt(void *p, enum ecl_ffi_tag tag, cl_object value)
{
	switch (tag) {
	case ECL_FFI_CHAR:
		*(char *)p = (char)ecl_base_char_code(value);
		break;
	case ECL_FFI_UNSIGNED_CHAR:
		*(unsigned char*)p = (unsigned char)ecl_base_char_code(value);
		break;
	case ECL_FFI_BYTE:
		*(int8_t *)p = ecl_to_int8_t(value);
		break;
	case ECL_FFI_UNSIGNED_BYTE:
		*(uint8_t *)p = ecl_to_uint8_t(value);
		break;
	case ECL_FFI_SHORT:
		*(short *)p = ecl_to_short(value);
		break;
	case ECL_FFI_UNSIGNED_SHORT:
		*(unsigned short *)p = ecl_to_ushort(value);
		break;
	case ECL_FFI_INT:
		*(int *)p = ecl_to_int(value);
		break;
	case ECL_FFI_UNSIGNED_INT:
		*(unsigned int *)p = ecl_to_uint(value);
		break;
	case ECL_FFI_LONG:
		*(long *)p = ecl_to_long(value);
		break;
	case ECL_FFI_UNSIGNED_LONG:
		*(unsigned long *)p = ecl_to_ulong(value);
		break;
        case ECL_FFI_INT8_T:
                *(ecl_int8_t *)p = ecl_to_int8_t(value);
                break;
        case ECL_FFI_UINT8_T:
                *(ecl_uint8_t *)p = ecl_to_uint8_t(value);
                break;
#ifdef ecl_uint16_t
        case ECL_FFI_INT16_T:
                *(ecl_int16_t *)p = ecl_to_int16_t(value);
                break;
        case ECL_FFI_UINT16_T:
                *(ecl_uint16_t *)p = ecl_to_uint16_t(value);
                break;
#endif
#ifdef ecl_uint32_t
        case ECL_FFI_INT32_T:
                *(ecl_int32_t *)p = ecl_to_int32_t(value);
                break;
        case ECL_FFI_UINT32_T:
                *(ecl_uint32_t *)p = ecl_to_uint32_t(value);
                break;
#endif
#ifdef ecl_uint64_t
        case ECL_FFI_INT64_T:
                *(ecl_int64_t *)p = ecl_to_int64_t(value);
                break;
        case ECL_FFI_UINT64_T:
                *(ecl_uint64_t *)p = ecl_to_uint64_t(value);
                break;
#endif
#ifdef ecl_long_long_t
        case ECL_FFI_LONG_LONG:
                *(ecl_long_long_t *)p = ecl_to_long_long(value);
                break;
        case ECL_FFI_UNSIGNED_LONG_LONG:
                *(ecl_ulong_long_t *)p = ecl_to_ulong_long(value);
                break;
#endif
	case ECL_FFI_POINTER_VOID:
		*(void **)p = ecl_foreign_data_pointer_safe(value);
		break;
	case ECL_FFI_CSTRING:
		*(char **)p = value == ECL_NIL ? NULL : (char*)value->base_string.self;
		break;
	case ECL_FFI_OBJECT:
		*(cl_object *)p = value;
		break;
	case ECL_FFI_FLOAT:
		*(float *)p = ecl_to_float(value);
		break;
	case ECL_FFI_DOUBLE:
		*(double *)p = ecl_to_double(value);
		break;
	case ECL_FFI_VOID:
		break;
        default:
                wrong_ffi_tag(tag);
	}
}

cl_object
si_foreign_data_ref_elt(cl_object f, cl_object andx, cl_object type)
{
	cl_index ndx = ecl_to_size(andx);
	cl_index limit = f->foreign.size;
	enum ecl_ffi_tag tag = ecl_foreign_type_code(type);
	if (ecl_unlikely(ndx >= limit ||
                         (ndx + ecl_foreign_type_table[tag].size > limit))) {
		FEerror("Out of bounds reference into foreign data type ~A.", 1, f);
	}
	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-REF-ELT*/1352), 1, f,
                                     ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	{
#line 637
		const cl_env_ptr the_env = ecl_process_env();
#line 637
		#line 637
		cl_object __value0 = ecl_foreign_data_ref_elt((void*)(f->foreign.data + ndx), tag);
#line 637
		the_env->nvalues = 1;
#line 637
		return __value0;
#line 637
	}

}

cl_object
si_foreign_data_set_elt(cl_object f, cl_object andx, cl_object type, cl_object value)
{
	cl_index ndx = ecl_to_size(andx);
	cl_index limit = f->foreign.size;
	enum ecl_ffi_tag tag = ecl_foreign_type_code(type);
	if (ecl_unlikely(ndx >= limit ||
                         ndx + ecl_foreign_type_table[tag].size > limit)) {
		FEerror("Out of bounds reference into foreign data type ~A.", 1, f);
	}
	if (ecl_unlikely(ecl_t_of(f) != t_foreign)) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-SET-ELT*/1354), 1, f,
                                     ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	}
	ecl_foreign_data_set_elt((void*)(f->foreign.data + ndx), tag, value);
	{
#line 655
		const cl_env_ptr the_env = ecl_process_env();
#line 655
		#line 655
		cl_object __value0 = value;
#line 655
		the_env->nvalues = 1;
#line 655
		return __value0;
#line 655
	}

}

cl_object
si_size_of_foreign_elt_type(cl_object type)
{
	enum ecl_ffi_tag tag = ecl_foreign_type_code(type);
	{
#line 662
		const cl_env_ptr the_env = ecl_process_env();
#line 662
		#line 662
		cl_object __value0 = ecl_make_fixnum(ecl_foreign_type_table[tag].size);
#line 662
		the_env->nvalues = 1;
#line 662
		return __value0;
#line 662
	}

}

cl_object
si_alignment_of_foreign_elt_type(cl_object type)
{
	enum ecl_ffi_tag tag = ecl_foreign_type_code(type);
	{
#line 669
		const cl_env_ptr the_env = ecl_process_env();
#line 669
		#line 669
		cl_object __value0 = ecl_make_fixnum(ALIGNMENT(tag));
#line 669
		the_env->nvalues = 1;
#line 669
		return __value0;
#line 669
	}

}

cl_object
si_foreign_elt_type_p(cl_object type)
{
	{
#line 675
		const cl_env_ptr the_env = ecl_process_env();
#line 675
		#line 675
		cl_object __value0 = ((foreign_type_code(type) < 0)? ECL_NIL : ECL_T);
#line 675
		the_env->nvalues = 1;
#line 675
		return __value0;
#line 675
	}

}

cl_object
si_null_pointer_p(cl_object f)
{
	if (ecl_unlikely(ecl_t_of(f) != t_foreign))
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::NULL-POINTER-P*/1360), f,
                                      ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	{
#line 684
		const cl_env_ptr the_env = ecl_process_env();
#line 684
		#line 684
		cl_object __value0 = ((f->foreign.data == NULL)? ECL_T : ECL_NIL);
#line 684
		the_env->nvalues = 1;
#line 684
		return __value0;
#line 684
	}

}

cl_object
si_foreign_data_recast(cl_object f, cl_object size, cl_object tag)
{
	if (ecl_unlikely(ecl_t_of(f) != t_foreign))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::FOREIGN-DATA-RECAST*/1350), 1, f,
                                     ecl_make_fixnum(/*SI::FOREIGN-DATA*/1345));
	f->foreign.size = ecl_to_size(size);
	f->foreign.tag = tag;
	{
#line 695
		const cl_env_ptr the_env = ecl_process_env();
#line 695
		#line 695
		cl_object __value0 = f;
#line 695
		the_env->nvalues = 1;
#line 695
		return __value0;
#line 695
	}

}

cl_object
si_load_foreign_module(cl_object filename)
{
#if !defined(ENABLE_DLOPEN)
	FEerror("SI:LOAD-FOREIGN-MODULE does not work when ECL is statically linked", 0);
#else
	cl_object output;

# ifdef ECL_THREADS
	mp_get_lock(1, ecl_symbol_value(ECL_SYM("MP::+LOAD-COMPILE-LOCK+",1426)));
	ECL_UNWIND_PROTECT_BEGIN(ecl_process_env()) {
# endif
	output = ecl_library_open(filename, 0);
	if (output->cblock.handle == NULL) {
		cl_object aux = ecl_library_error(output);
		ecl_library_close(output);
		output = aux;
	}
# ifdef ECL_THREADS
	(void)0; /* MSVC complains about missing ';' before '}' */
	} ECL_UNWIND_PROTECT_EXIT {
	mp_giveup_lock(ecl_symbol_value(ECL_SYM("MP::+LOAD-COMPILE-LOCK+",1426)));
	} ECL_UNWIND_PROTECT_END;
# endif
	if (ecl_unlikely(ecl_t_of(output) != t_codeblock)) {
		FEerror("LOAD-FOREIGN-MODULE: Could not load "
                        "foreign module ~S (Error: ~S)", 2, filename, output);
        }
        output->cblock.locked |= 1;
        {
#line 727
	const cl_env_ptr the_env = ecl_process_env();
#line 727
	#line 727
	cl_object __value0 = output;
#line 727
	the_env->nvalues = 1;
#line 727
	return __value0;
#line 727
}

#endif
}

cl_object
si_find_foreign_symbol(cl_object var, cl_object module, cl_object type, cl_object size)
{
#if !defined(ENABLE_DLOPEN)
	FEerror("SI:FIND-FOREIGN-SYMBOL does not work when ECL is statically linked", 0);
#else
	cl_object block;
	cl_object output = ECL_NIL;
	void *sym;

	block = (module == ECL_SYM(":DEFAULT",1215) ? module : si_load_foreign_module(module));
	var = ecl_null_terminated_base_string(var);
	sym = ecl_library_symbol(block, (char*)var->base_string.self, 1);
	if (sym == NULL) {
		if (block != ECL_SYM(":DEFAULT",1215))
			output = ecl_library_error(block);
		goto OUTPUT;
	}
	output = ecl_make_foreign_data(type, ecl_to_fixnum(size), sym);
OUTPUT:
	if (ecl_unlikely(ecl_t_of(output) != t_foreign))
		FEerror("FIND-FOREIGN-SYMBOL: Could not load "
                        "foreign symbol ~S from module ~S (Error: ~S)",
                        3, var, module, output);
        {
#line 755
	const cl_env_ptr the_env = ecl_process_env();
#line 755
	#line 755
	cl_object __value0 = output;
#line 755
	the_env->nvalues = 1;
#line 755
	return __value0;
#line 755
}

#endif
}

#ifdef ECL_DYNAMIC_FFI
static void
ecl_fficall_overflow()
{
	FEerror("Stack overflow on SI:CALL-CFUN", 0);
}

void
ecl_fficall_prepare(cl_object return_type, cl_object arg_type, cl_object cc_type)
{
	struct ecl_fficall *fficall = cl_env.fficall;
	fficall->buffer_sp = fficall->buffer;
	fficall->buffer_size = 0;
	fficall->cstring = ECL_NIL;
	fficall->cc = ecl_foreign_cc_code(cc_type);
        fficall->registers = ecl_fficall_prepare_extra(fficall->registers);
}

void
ecl_fficall_push_bytes(void *data, size_t bytes)
{
	struct ecl_fficall *fficall = cl_env.fficall;
	fficall->buffer_size += bytes;
	if (fficall->buffer_size >= ECL_FFICALL_LIMIT)
		ecl_fficall_overflow();
	memcpy(fficall->buffer_sp, (char*)data, bytes);
	fficall->buffer_sp += bytes;
}

void
ecl_fficall_push_int(int data)
{
	ecl_fficall_push_bytes(&data, sizeof(int));
}

void
ecl_fficall_align(int data)
{
	struct ecl_fficall *fficall = cl_env.fficall;
	if (data == 1)
		return;
	else {
		size_t sp = fficall->buffer_sp - fficall->buffer;
		size_t mask = data - 1;
		size_t new_sp = (sp + mask) & ~mask;
		if (new_sp >= ECL_FFICALL_LIMIT)
			ecl_fficall_overflow();
		fficall->buffer_sp = fficall->buffer + new_sp;
		fficall->buffer_size = new_sp;
	}
}

#line 811
cl_object si::call-cfun(cl_narg narg, cl_object fun, cl_object return_type, cl_object arg_types, cl_object args, ...)
{
#line 811

	struct ecl_fficall *fficall = cl_env.fficall;
	void *cfun = ecl_foreign_data_pointer_safe(fun);
	cl_object object;
	enum ecl_ffi_tag return_type_tag = ecl_foreign_type_code(return_type);
#line 817
	const cl_env_ptr the_env = ecl_process_env();
#line 817
	cl_object cc_type;
#line 817
	va_list ARGS;
	va_start(ARGS, args);
#line 817
	if (ecl_unlikely(narg < 4|| narg > 5)) FEwrong_num_arguments(ecl_make_fixnum(1589));
#line 817
	if (narg > 4) {
#line 817
		cc_type = va_arg(ARGS,cl_object);
#line 817
	} else {
#line 817
		cc_type = ECL_SYM(":CDECL",1593);
#line 817
	}
#line 817

	ecl_fficall_prepare(return_type, arg_types, cc_type);
	while (CONSP(arg_types)) {
		enum ecl_ffi_tag type;
		if (!CONSP(args)) {
			FEerror("In SI:CALL-CFUN, mismatch between argument types and argument list: ~A vs ~A", 0);
		}
		type = ecl_foreign_type_code(CAR(arg_types));
		if (type == ECL_FFI_CSTRING) {
			object = ecl_null_terminated_base_string(CAR(args));
			if (CAR(args) != object)
				fficall->cstring =
					CONS(object, fficall->cstring);
		} else {
			object = CAR(args);
		}
		ecl_foreign_data_set_elt(&fficall->output, type, object);
		ecl_fficall_push_arg(&fficall->output, type);
		arg_types = CDR(arg_types);
		args = CDR(args);
	}
	ecl_fficall_execute(cfun, fficall, return_type_tag);
	object = ecl_foreign_data_ref_elt(&fficall->output, return_type_tag);

	fficall->buffer_size = 0;
	fficall->buffer_sp = fficall->buffer;
	fficall->cstring = ECL_NIL;

	{
#line 845
		#line 845
		cl_object __value0 = object;
#line 845
		the_env->nvalues = 1;
#line 845
		return __value0;
#line 845
	}

}

#line 848
cl_object si::make-dynamic-callback(cl_narg narg, cl_object fun, cl_object sym, cl_object rtype, cl_object argtypes, ...)
{
#line 848

	cl_object data;
	cl_object cbk;
#line 852
	const cl_env_ptr the_env = ecl_process_env();
#line 852
	cl_object cctype;
#line 852
	va_list ARGS;
	va_start(ARGS, argtypes);
#line 852
	if (ecl_unlikely(narg < 4|| narg > 5)) FEwrong_num_arguments(ecl_make_fixnum(1591));
#line 852
	if (narg > 4) {
#line 852
		cctype = va_arg(ARGS,cl_object);
#line 852
	} else {
#line 852
		cctype = ECL_SYM(":CDECL",1593);
#line 852
	}
#line 852
	data = cl_list(3, fun, rtype, argtypes);
	cbk  = ecl_make_foreign_data(ECL_SYM(":POINTER-VOID",1377), 0, ecl_dynamic_callback_make(data, ecl_foreign_cc_code(cctype)));

	si_put_sysprop(sym, ECL_SYM(":CALLBACK",1590), CONS(cbk, data));
	{
#line 856
		#line 856
		cl_object __value0 = cbk;
#line 856
		the_env->nvalues = 1;
#line 856
		return __value0;
#line 856
	}

}
#endif /* ECL_DYNAMIC_FFI */


#ifdef HAVE_LIBFFI
static void
resize_call_stack(cl_env_ptr env, cl_index new_size)
{
        cl_index i;
        ffi_type **types =
                ecl_alloc_atomic((new_size + 1) * sizeof(ffi_type*));
        union ecl_ffi_values *values =
                ecl_alloc_atomic((new_size + 1) * sizeof(union ecl_ffi_values));
        union ecl_ffi_values **values_ptrs =
                ecl_alloc_atomic(new_size * sizeof(union ecl_ffi_values *));
        memcpy(types, env->ffi_types, env->ffi_args_limit * sizeof(ffi_type*));
        memcpy(values, env->ffi_values, env->ffi_args_limit *
               sizeof(union ecl_ffi_values));
        for (i = 0; i < new_size; i++) {
                values_ptrs[i] = (values + i + 1);
        }
        env->ffi_args_limit = new_size;
        ecl_dealloc(env->ffi_types);
        env->ffi_types = types;
        ecl_dealloc(env->ffi_values);
        env->ffi_values = values;
        ecl_dealloc(env->ffi_values_ptrs);
        env->ffi_values_ptrs = values_ptrs;
}

static int
prepare_cif(cl_env_ptr the_env, ffi_cif *cif, cl_object return_type,
            cl_object arg_types, cl_object args,
            cl_object cc_type, ffi_type ***output_copy)
{
        int n, ok;
        ffi_type **types;
        enum ecl_ffi_tag type = ecl_foreign_type_code(return_type);
        if (!the_env->ffi_args_limit)
                resize_call_stack(the_env, 32);
        the_env->ffi_types[0] = ecl_type_to_libffi_type[type];
        for (n=0; !Null(arg_types); ) {
                if (!LISTP(arg_types)) {
                        FEerror("In CALL-CFUN, types lists is not a proper list", 0);
                }
                if (n >= the_env->ffi_args_limit) {
                        resize_call_stack(the_env, n + 32);
                }
		type = ecl_foreign_type_code(ECL_CONS_CAR(arg_types));
                arg_types = ECL_CONS_CDR(arg_types);
                the_env->ffi_types[++n] = ecl_type_to_libffi_type[type];
                if (CONSP(args)) {
                        cl_object object = ECL_CONS_CAR(args);
                        args = ECL_CONS_CDR(args);
                        if (type == ECL_FFI_CSTRING) {
                                object = ecl_null_terminated_base_string(CAR(args));
                                if (ECL_CONS_CAR(args) != object) {
                                        ECL_STACK_PUSH(the_env, object);
                                }
                        }
                        ecl_foreign_data_set_elt(the_env->ffi_values + n, type, object);
                }
        }
        if (output_copy) {
                cl_index bytes = (n + 1) * sizeof(ffi_type*);
                *output_copy = types = (ffi_type**)ecl_alloc_atomic(bytes);
                memcpy(types, the_env->ffi_types, bytes);
        } else {
                types = the_env->ffi_types;
        }
        ok = ffi_prep_cif(cif, ecl_foreign_cc_code(cc_type), n, types[0], types + 1);
        if (ok != FFI_OK) {
                if (ok == FFI_BAD_ABI) {
                        FEerror("In CALL-CFUN, not a valid ABI: ~A", 1,
                                cc_type);
                }
                if (ok == FFI_BAD_TYPEDEF) {
                        FEerror("In CALL-CFUN, wrong or malformed argument types", 0);
                }
        }
        return n;
}

#line 940
cl_object si::call-cfun(cl_narg narg, cl_object fun, cl_object return_type, cl_object arg_types, cl_object args, ...)
{
#line 940

	void *cfun = ecl_foreign_data_pointer_safe(fun);
	cl_object object;
        volatile cl_index sp;
        ffi_cif cif;
#line 946
	const cl_env_ptr the_env = ecl_process_env();
#line 946
	cl_object cc_type;
#line 946
	va_list ARGS;
	va_start(ARGS, args);
#line 946
	if (ecl_unlikely(narg < 4|| narg > 5)) FEwrong_num_arguments(ecl_make_fixnum(1589));
#line 946
	if (narg > 4) {
#line 946
		cc_type = va_arg(ARGS,cl_object);
#line 946
	} else {
#line 946
		cc_type = ECL_SYM(":DEFAULT",1215);
#line 946
	}
#line 946
{
	sp = ECL_STACK_INDEX(the_env);
	prepare_cif(the_env, &cif, return_type, arg_types, args, cc_type, NULL);
        ffi_call(&cif, cfun, the_env->ffi_values, (void **)the_env->ffi_values_ptrs);
	object = ecl_foreign_data_ref_elt(the_env->ffi_values,
                                          ecl_foreign_type_code(return_type));
	ECL_STACK_SET_INDEX(the_env, sp);
	{
#line 953
		#line 953
		cl_object __value0 = object;
#line 953
		the_env->nvalues = 1;
#line 953
		return __value0;
#line 953
	}

}
}

static void
callback_executor(ffi_cif *cif, void *result, void **args, void *userdata)
{
        cl_object data = (cl_object)userdata;
        cl_object fun = ECL_CONS_CAR(data);
        cl_object ret_type = (data = ECL_CONS_CDR(data), ECL_CONS_CAR(data));
        cl_object arg_types = (data = ECL_CONS_CDR(data), ECL_CONS_CAR(data));
        cl_env_ptr the_env = ecl_process_env();
        struct ecl_stack_frame frame_aux;
        const cl_object frame = ecl_stack_frame_open(the_env, (cl_object)&frame_aux, 0);
        cl_object x;
        while (arg_types != ECL_NIL) {
                cl_object type = ECL_CONS_CAR(arg_types);
                enum ecl_ffi_tag tag = ecl_foreign_type_code(type);
                x = ecl_foreign_data_ref_elt(*args, tag);
                ecl_stack_frame_push(frame, x);
                arg_types = ECL_CONS_CDR(arg_types);
                args++;
        }
        x = ecl_apply_from_stack_frame(frame, fun);
        ecl_stack_frame_close(frame);
        ecl_foreign_data_set_elt(result, ecl_foreign_type_code(ret_type), x);
}

cl_object
si_free_ffi_closure(cl_object closure)
{
        ffi_closure_free(ecl_foreign_data_pointer_safe(closure));
	{
#line 985
		const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 985
	}
;
}

#line 989
cl_object si::make-dynamic-callback(cl_narg narg, cl_object fun, cl_object sym, cl_object return_type, cl_object arg_types, ...)
{
#line 989

#line 991
	const cl_env_ptr the_env = ecl_process_env();
#line 991
	cl_object cc_type;
#line 991
	va_list ARGS;
	va_start(ARGS, arg_types);
#line 991
	if (ecl_unlikely(narg < 4|| narg > 5)) FEwrong_num_arguments(ecl_make_fixnum(1591));
#line 991
	if (narg > 4) {
#line 991
		cc_type = va_arg(ARGS,cl_object);
#line 991
	} else {
#line 991
		cc_type = ECL_SYM(":DEFAULT",1215);
#line 991
	}
#line 991
{
        ffi_cif *cif = ecl_alloc(sizeof(ffi_cif));
        ffi_type **types;
        int n = prepare_cif(the_env, cif, return_type, arg_types, ECL_NIL, cc_type,
                            &types);

	/* libffi allocates executable memory for us. ffi_closure_alloc()
	 * returns a pointer to memory and a pointer to the beginning of
	 * the actual executable region (executable_closure) which is
	 * where the code resides. */
        void *executable_region;
        ffi_closure *closure = ffi_closure_alloc(sizeof(ffi_closure), &executable_region);

        cl_object closure_object = ecl_make_foreign_data(ECL_SYM(":POINTER-VOID",1377),
                                                         sizeof(ffi_closure),
                                                         closure);
        si_set_finalizer(closure_object, ECL_SYM("SI::FREE-FFI-CLOSURE",1592));

        cl_object data = cl_list(6, closure_object,
                                 fun, return_type, arg_types, cc_type,
                                 ecl_make_foreign_data(ECL_SYM(":POINTER-VOID",1377),
                                                       sizeof(*cif), cif),
                                 ecl_make_foreign_data(ECL_SYM(":POINTER-VOID",1377),
                                                       (n + 1) * sizeof(ffi_type*),
                                                       types));
        int status = ffi_prep_closure_loc(closure, cif, callback_executor,
                                          ECL_CONS_CDR(data), executable_region);

        if (status != FFI_OK) {
                FEerror("Unable to build callback. libffi returns ~D", 1,
                        ecl_make_fixnum(status));
        }
	si_put_sysprop(sym, ECL_SYM(":CALLBACK",1590), data);
        {
#line 1024
	#line 1024
	cl_object __value0 = closure_object;
#line 1024
	the_env->nvalues = 1;
#line 1024
	return __value0;
#line 1024
}
;
}
}
#endif /* HAVE_LIBFFI */
