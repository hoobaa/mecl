#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/hash.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    hash.d  -- Hash tables.
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

/* for ECL_MATHERR_* */
#define ECL_INCLUDE_MATH_H
#include <ecl/ecl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ecl/ecl-inl.h>
#include <ecl/internal.h>
#include "newhash.h"

#define SYMBOL_NAME(x) (Null(x)? ECL_NIL_SYMBOL->symbol.name : (x)->symbol.name)

static void ECL_INLINE
assert_type_hash_table(cl_object function, cl_narg narg, cl_object p)
{
	unlikely_if (!ECL_HASH_TABLE_P(p))
		FEwrong_type_nth_arg(function, narg, p, ecl_make_fixnum(/*HASH-TABLE*/418));
}

static cl_hashkey
_hash_eql(cl_hashkey h, cl_object x)
{
	switch (ecl_t_of(x)) {
	case t_bignum:
		return hash_string(h, (unsigned char*)ECL_BIGNUM_LIMBS(x),
				   labs(ECL_BIGNUM_SIZE(x)) *
				   sizeof(mp_limb_t));
	case t_ratio:
		h = _hash_eql(h, x->ratio.num);
		return _hash_eql(h, x->ratio.den);
	case t_singlefloat:
		return hash_string(h, (unsigned char*)&ecl_single_float(x), sizeof(ecl_single_float(x)));
	case t_doublefloat:
		return hash_string(h, (unsigned char*)&ecl_double_float(x), sizeof(ecl_double_float(x)));
#ifdef ECL_LONG_FLOAT
	case t_longfloat: {
                /* We coerce to double because long double has extra bits
                 * that give rise to different hash key and are not
                 * meaningful */
                struct { double mantissa; int exponent; int sign; } aux;
                aux.mantissa = frexpl(ecl_long_float(x), &aux.exponent);
                aux.sign = (ecl_long_float(x) < 0)? -1: 1;
		return hash_string(h, (unsigned char*)&aux, sizeof(aux));
	}
#endif
	case t_complex:
		h = _hash_eql(h, x->complex.real);
		return _hash_eql(h, x->complex.imag);
	case t_character:
		return hash_word(h, ECL_CHAR_CODE(x));
#ifdef ECL_SSE2
	case t_sse_pack:
		return hash_string(h, x->sse.data.b8, 16);
#endif
	default:
		return hash_word(h, ((cl_hashkey)x >> 2));
	}
}

static cl_hashkey
_hash_equal(int depth, cl_hashkey h, cl_object x)
{
	switch (ecl_t_of(x)) {
	case t_list:
		if (Null(x)) {
			return _hash_equal(depth, h, ECL_NIL_SYMBOL->symbol.name);
		}
		if (--depth == 0) {
			return h;
		} else {
			h = _hash_equal(depth, h, ECL_CONS_CAR(x));
			return _hash_equal(depth, h, ECL_CONS_CDR(x));
		}
	case t_symbol:
		x = x->symbol.name;
#ifdef ECL_UNICODE
	case t_base_string:
		return hash_base_string((ecl_base_char *)x->base_string.self,
					x->base_string.fillp, h);
	case t_string:
		return hash_full_string(x->string.self, x->string.fillp, h);
#else
	case t_base_string:
		return hash_string(h, (ecl_base_char *)x->base_string.self,
				   x->base_string.fillp);
#endif
	case t_pathname:
		h = _hash_equal(0, h, x->pathname.directory);
		h = _hash_equal(0, h, x->pathname.name);
		h = _hash_equal(0, h, x->pathname.type);
		h = _hash_equal(0, h, x->pathname.host);
		h = _hash_equal(0, h, x->pathname.device);
		return _hash_equal(0, h, x->pathname.version);
	case t_bitvector:
		/* Notice that we may round out some bits. We must do this
		 * because the fill pointer may be set in the middle of a byte.
		 * If so, the extra bits _must_ _not_ take part in the hash,
		 * because otherwise two bit arrays which are EQUAL might
		 * have different hash keys. */
		return hash_string(h, x->vector.self.bc, x->vector.fillp / 8);
	case t_random:
		return _hash_equal(0, h, x->random.value);
#ifdef ECL_SIGNED_ZERO
	case t_singlefloat: {
		float f = ecl_single_float(x);
		if (f == 0.0) f = 0.0;
		return hash_string(h, (unsigned char*)&f, sizeof(f));
	}
	case t_doublefloat: {
		double f = ecl_double_float(x);
		if (f == 0.0) f = 0.0;
		return hash_string(h, (unsigned char*)&f, sizeof(f));
	}
# ifdef ECL_LONG_FLOAT
	case t_longfloat: {
                /* We coerce to double because long double has extra bits
                 * that give rise to different hash key and are not
                 * meaningful */
                struct { double mantissa; int exponent; int sign; } aux;
                aux.mantissa = frexpl(ecl_long_float(x), &aux.exponent);
                aux.sign = (ecl_long_float(x) < 0)? -1: 1;
		if (aux.mantissa == 0.0) aux.mantissa = 0.0;
		return hash_string(h, (unsigned char*)&aux, sizeof(aux));
	}
# endif
	case t_complex: {
		h = _hash_equal(depth, h, x->complex.real);
		return _hash_equal(depth, h, x->complex.imag);
	}
#endif
	default:
		return _hash_eql(h, x);
	}
}

static cl_hashkey
_hash_equalp(int depth, cl_hashkey h, cl_object x)
{
	cl_index i, len;
	switch (ecl_t_of(x)) {
	case t_character:
		return hash_word(h, ecl_char_upcase(ECL_CHAR_CODE(x)));
	case t_list:
		if (Null(x)) {
			return _hash_equalp(depth, h, ECL_NIL_SYMBOL->symbol.name);
		}
		if (--depth == 0) {
			return h;
		} else {
			h = _hash_equalp(depth, h, ECL_CONS_CAR(x));
			return _hash_equalp(depth, h, ECL_CONS_CDR(x));
		}
#ifdef ECL_UNICODE
	case t_string:
#endif
	case t_base_string:
	case t_vector:
	case t_bitvector:
		len = x->vector.fillp;
		goto SCAN;
	case t_array:
		len = x->vector.dim;
	SCAN:	if (--depth) {
			for (i = 0; i < len; i++) {
				h = _hash_equalp(depth, h, ecl_aref_unsafe(x, i));
			}
		}
		return h;
	case t_fixnum:
		return hash_word(h, ecl_fixnum(x));
	case t_singlefloat:
		/* FIXME! We should be more precise here! */
		return hash_word(h, (cl_index)ecl_single_float(x));
	case t_doublefloat:
		/* FIXME! We should be more precise here! */
		return hash_word(h, (cl_index)ecl_double_float(x));
	case t_bignum:
		/* FIXME! We should be more precise here! */
	case t_ratio:
		h = _hash_equalp(0, h, x->ratio.num);
		return _hash_equalp(0, h, x->ratio.den);
	case t_complex:
		h = _hash_equalp(0, h, x->complex.real);
		return _hash_equalp(0, h, x->complex.imag);
	case t_instance:
	case t_hashtable:
		/* FIXME! We should be more precise here! */
		return hash_word(h, 42);
	default:
		return _hash_equal(depth, h, x);
	}
}

#define HASH_TABLE_LOOP(hkey,hvalue,h,HASH_TABLE_LOOP_TEST) {   \
	cl_index hsize = hashtable->hash.size; \
        cl_index i = h % hsize, j = hsize, k; \
	for (k = 0; k < hsize;  i = (i + 1) % hsize, k++) { \
		struct ecl_hashtable_entry *e = hashtable->hash.data + i; \
		cl_object hkey = e->key, hvalue = e->value; \
		if (hkey == OBJNULL) { \
			if (e->value == OBJNULL) { \
				if (j == hsize) \
					return e; \
				else \
					return hashtable->hash.data + j; \
			} else { \
				if (j == hsize) \
					j = i; \
				else if (j == i) \
                                        return e; \
                        } \
			continue; \
		} \
		if (HASH_TABLE_LOOP_TEST) return hashtable->hash.data + i; \
	} \
	return hashtable->hash.data + j; \
}

#if 0
#define HASH_TABLE_SET(h,loop,compute_key,store_key)
#else
#define HASH_TABLE_SET(h,loop,compute_key,store_key) {			\
		cl_hashkey h = compute_key;				\
		struct ecl_hashtable_entry *e;				\
	AGAIN:								\
		e = loop(h, key, hashtable);				\
		if (e->key == OBJNULL) {				\
			cl_index i = hashtable->hash.entries + 1;	\
			if (i >= hashtable->hash.limit) {		\
				hashtable = ecl_extend_hashtable(hashtable); \
				goto AGAIN;				\
			}						\
			hashtable->hash.entries = i;			\
			e->key = store_key;				\
		}							\
		e->value = value;					\
		return hashtable;					\
	}
#endif

/*
 * EQ HASHTABLES
 */

#if 0
#define _hash_eq(k) ((cl_hashkey)(k) ^ ((cl_hashkey)(k) >> 16))
#else
#define _hash_eq(k) ((cl_hashkey)(k) >> 2)
#endif

static struct ecl_hashtable_entry *
_ecl_hash_loop_eq(cl_hashkey h, cl_object key, cl_object hashtable)
{
        HASH_TABLE_LOOP(hkey, hvalue, h, key == hkey);
}

static cl_object
_ecl_gethash_eq(cl_object key, cl_object hashtable, cl_object def)
{
	cl_hashkey h = _hash_eq(key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_eq(h, key, hashtable);
	return (e->key == OBJNULL)? def : e->value;
}

static bool
_ecl_remhash_eq(cl_object key, cl_object hashtable)
{
	cl_hashkey h = _hash_eq(key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_eq(h, key, hashtable);
	if (e->key == OBJNULL) {
		return 0;
	} else {
		e->key = OBJNULL;
		e->value = ECL_NIL;
		hashtable->hash.entries--;
		return 1;
	}
}

static cl_object
_ecl_sethash_eq(cl_object key, cl_object hashtable, cl_object value)
{
	HASH_TABLE_SET(h, _ecl_hash_loop_eq, _hash_eq(key), key);
}

/*
 * EQL HASHTABLES
 */

static struct ecl_hashtable_entry *
_ecl_hash_loop_eql(cl_hashkey h, cl_object key, cl_object hashtable)
{
        HASH_TABLE_LOOP(hkey, hvalue, h, ecl_eql(key, hkey));
}

static cl_object
_ecl_gethash_eql(cl_object key, cl_object hashtable, cl_object def)
{
	cl_hashkey h = _hash_eql(0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_eql(h, key, hashtable);
	return (e->key == OBJNULL)? def : e->value;
}

static cl_object
_ecl_sethash_eql(cl_object key, cl_object hashtable, cl_object value)
{
	HASH_TABLE_SET(h, _ecl_hash_loop_eql, _hash_eql(0, key), key);
}

static bool
_ecl_remhash_eql(cl_object key, cl_object hashtable)
{
	cl_hashkey h = _hash_eql(0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_eql(h, key, hashtable);
	if (e->key == OBJNULL) {
		return 0;
	} else {
		e->key = OBJNULL;
		e->value = ECL_NIL;
		hashtable->hash.entries--;
		return 1;
	}
}

/*
 * EQUAL HASHTABLES
 */

static struct ecl_hashtable_entry *
_ecl_hash_loop_equal(cl_hashkey h, cl_object key, cl_object hashtable)
{
        HASH_TABLE_LOOP(hkey, hvalue, h, ecl_equal(key, hkey));
}

static cl_object
_ecl_gethash_equal(cl_object key, cl_object hashtable, cl_object def)
{
	cl_hashkey h = _hash_equal(3, 0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_equal(h, key, hashtable);
	return (e->key == OBJNULL)? def : e->value;
}

static cl_object
_ecl_sethash_equal(cl_object key, cl_object hashtable, cl_object value)
{
	HASH_TABLE_SET(h, _ecl_hash_loop_equal, _hash_equal(3, 0, key), key);
}

static bool
_ecl_remhash_equal(cl_object key, cl_object hashtable)
{
	cl_hashkey h = _hash_equal(3, 0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_equal(h, key, hashtable);
	if (e->key == OBJNULL) {
		return 0;
	} else {
		e->key = OBJNULL;
		e->value = ECL_NIL;
		hashtable->hash.entries--;
		return 1;
	}
}

/*
 * EQUALP HASHTABLES
 */

static struct ecl_hashtable_entry *
_ecl_hash_loop_equalp(cl_hashkey h, cl_object key, cl_object hashtable)
{
        HASH_TABLE_LOOP(hkey, hvalue, h, ecl_equalp(key, hkey));
}

static cl_object
_ecl_gethash_equalp(cl_object key, cl_object hashtable, cl_object def)
{
	cl_hashkey h = _hash_equalp(3, 0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_equalp(h, key, hashtable);
	return (e->key == OBJNULL)? def : e->value;
}

static cl_object
_ecl_sethash_equalp(cl_object key, cl_object hashtable, cl_object value)
{
	HASH_TABLE_SET(h, _ecl_hash_loop_equalp, _hash_equalp(3, 0, key), key);
}

static bool
_ecl_remhash_equalp(cl_object key, cl_object hashtable)
{
	cl_hashkey h = _hash_equalp(3, 0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_equalp(h, key, hashtable);
	if (e->key == OBJNULL) {
		return 0;
	} else {
		e->key = OBJNULL;
		e->value = ECL_NIL;
		hashtable->hash.entries--;
		return 1;
	}
}

/*
 * PACKAGE HASHTABLES
 */

static struct ecl_hashtable_entry *
_ecl_hash_loop_pack(cl_hashkey h, cl_object key, cl_object hashtable)
{
        cl_object ho = ecl_make_fixnum(h & 0xFFFFFFF);
        HASH_TABLE_LOOP(hkey, hvalue, h, (ho==hkey) && ecl_string_eq(key,SYMBOL_NAME(hvalue)));
}

static cl_object
_ecl_gethash_pack(cl_object key, cl_object hashtable, cl_object def)
{
	cl_hashkey h = _hash_equal(3, 0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_pack(h, key, hashtable);
	return (e->key == OBJNULL)? def : e->value;
}

static cl_object
_ecl_sethash_pack(cl_object key, cl_object hashtable, cl_object value)
{
	HASH_TABLE_SET(h, _ecl_hash_loop_pack, _hash_equal(3, 0, key), ecl_make_fixnum(h & 0xFFFFFFF));
}

static bool
_ecl_remhash_pack(cl_object key, cl_object hashtable)
{
	cl_hashkey h = _hash_equal(3, 0, key);
	struct ecl_hashtable_entry *e = _ecl_hash_loop_pack(h, key, hashtable);
	if (e->key == OBJNULL) {
		return 0;
	} else {
		e->key = OBJNULL;
		e->value = ECL_NIL;
		hashtable->hash.entries--;
		return 1;
	}
}

/*
 * WEAK HASH TABLES
 */
#ifndef ECL_WEAK_HASH
#define copy_entry(e,h) *(e)
#endif

#ifdef ECL_WEAK_HASH
static cl_hashkey
_ecl_hash_key(cl_object h, cl_object o) {
	switch (h->hash.test) {
	case ecl_htt_eq: return _hash_eq(o);
	case ecl_htt_eql: return _hash_eql(0, o);
	case ecl_htt_equal: return _hash_equal(3, 0, o);
	case ecl_htt_equalp:
	default: return _hash_equalp(3, 0, o);
	}
}

static void *
normalize_weak_key_entry(struct ecl_hashtable_entry *e) {
	return (void*)(e->key = e->key->weak.value);
}

static void *
normalize_weak_value_entry(struct ecl_hashtable_entry *e) {
	return (void*)(e->value = e->value->weak.value);
}

static void *
normalize_weak_key_and_value_entry(struct ecl_hashtable_entry *e) {
	if ((e->key = e->key->weak.value) && (e->value = e->value->weak.value))
		return (void*)e;
	else
		return 0;
}

static struct ecl_hashtable_entry
copy_entry(struct ecl_hashtable_entry *e, cl_object h)
{
	if (e->key == OBJNULL) {
		return *e;
	} else {
		struct ecl_hashtable_entry output = *e;
		switch (h->hash.weak) {
		case ecl_htt_weak_key:
			if (GC_call_with_alloc_lock(normalize_weak_key_entry,
						    &output)) {
				return output;
			}
			break;
		case ecl_htt_weak_value:
			if (GC_call_with_alloc_lock(normalize_weak_value_entry,
						    &output)) {
				return output;
			}
			break;
		case ecl_htt_weak_key_and_value:
			if (GC_call_with_alloc_lock(normalize_weak_key_and_value_entry,
						    &output)) {
				return output;
			}
			break;
		case ecl_htt_not_weak:
		default:
			return output;
		}
		h->hash.entries--;
		output.key = OBJNULL;
		output.value = ECL_NIL;
		return *e = output;
	}
}

static struct ecl_hashtable_entry *
_ecl_weak_hash_loop(cl_hashkey h, cl_object key, cl_object hashtable,
		    struct ecl_hashtable_entry *aux)
{
	cl_index hsize = hashtable->hash.size;
        cl_index i = h % hsize, j = hsize, k;
	for (k = 0; k < hsize;  i = (i + 1) % hsize, k++) {
		struct ecl_hashtable_entry *p = hashtable->hash.data + i;
		struct ecl_hashtable_entry e = *aux = copy_entry(p, hashtable);
		if (e.key == OBJNULL) {
			if (e.value == OBJNULL) {
				if (j == hsize) {
					return p;
				} else {
					return hashtable->hash.data + j;
				}
			} else {
				if (j == hsize) {
					j = i;
				} else if (j == i) {
                                        return p;
				}
                        }
			continue;
		}
		switch (hashtable->hash.test) {
		case ecl_htt_eq:
			if (e.key == key) return p;
		case ecl_htt_eql:
			if (ecl_eql(e.key, key)) return p;
		case ecl_htt_equal:
			if (ecl_equal(e.key, key)) return p;
		case ecl_htt_equalp:
			if (ecl_equalp(e.key, key)) return p;
		}
	}
	return hashtable->hash.data + j;
}

static cl_object
_ecl_gethash_weak(cl_object key, cl_object hashtable, cl_object def)
{
	cl_hashkey h = _ecl_hash_key(hashtable, key);
	struct ecl_hashtable_entry aux[1];
	_ecl_weak_hash_loop(h, key, hashtable, aux);
	if (aux->key != OBJNULL) {
		return aux->value;
	} else {
		return def;
	}
}

static cl_object
_ecl_sethash_weak(cl_object key, cl_object hashtable, cl_object value)
{
	cl_hashkey h = _ecl_hash_key(hashtable, key);
	struct ecl_hashtable_entry aux[1];
	struct ecl_hashtable_entry *e;
 AGAIN:
	e = _ecl_weak_hash_loop(h, key, hashtable, aux);
	if (aux->key == OBJNULL) {
		cl_index i = hashtable->hash.entries + 1;
		if (i >= hashtable->hash.limit) {
			hashtable = ecl_extend_hashtable(hashtable);
			goto AGAIN;
		}
		hashtable->hash.entries = i;
		switch (hashtable->hash.weak) {
		case ecl_htt_weak_key:
			key = si_make_weak_pointer(key);
			break;
		case ecl_htt_weak_value:
			value = si_make_weak_pointer(value);
			break;
		case ecl_htt_weak_key_and_value:
		default:
			key = si_make_weak_pointer(key);
			value = si_make_weak_pointer(value);
			break;
		}
		e->key = key;
	}
	e->value = value;
	return hashtable;
}


static bool
_ecl_remhash_weak(cl_object key, cl_object hashtable)
{
	cl_hashkey h = _ecl_hash_key(hashtable, key);
	struct ecl_hashtable_entry aux[1];
	struct ecl_hashtable_entry *e =
		_ecl_weak_hash_loop(h, key, hashtable, aux);
	if (aux->key != OBJNULL) {
		hashtable->hash.entries--;
		e->key = OBJNULL;
		e->value = ECL_NIL;
		return 1;
	} else {
		return 0;
	}
}

#endif

/*
 * HIGHER LEVEL INTERFACE
 */

cl_object
ecl_gethash(cl_object key, cl_object hashtable)
{
	assert_type_hash_table(ecl_make_fixnum(/*GETHASH*/413), 2, hashtable);
	return hashtable->hash.get(key, hashtable, OBJNULL);
}

cl_object
ecl_gethash_safe(cl_object key, cl_object hashtable, cl_object def)
{
	assert_type_hash_table(ecl_make_fixnum(/*GETHASH*/413), 2, hashtable);
	return hashtable->hash.get(key, hashtable, def);
}

cl_object
_ecl_sethash(cl_object key, cl_object hashtable, cl_object value)
{
	return hashtable->hash.set(key, hashtable, value);
}

cl_object
ecl_sethash(cl_object key, cl_object hashtable, cl_object value)
{
	assert_type_hash_table(ecl_make_fixnum(/*SI::HASH-SET*/1088), 2, hashtable);
	hashtable = hashtable->hash.set(key, hashtable, value);
	return hashtable;
}

cl_object
ecl_extend_hashtable(cl_object hashtable)
{
	cl_object old, new;
	cl_index old_size, new_size, i;
	cl_object new_size_obj;

	assert_type_hash_table(ecl_make_fixnum(/*SI::HASH-SET*/1088), 2, hashtable);
	old_size = hashtable->hash.size;
	/* We do the computation with lisp datatypes, just in case the sizes contain
	 * weird numbers */
	if (ECL_FIXNUMP(hashtable->hash.rehash_size)) {
		new_size_obj = ecl_plus(hashtable->hash.rehash_size,
					ecl_make_fixnum(old_size));
	} else {
		new_size_obj = ecl_times(hashtable->hash.rehash_size,
					 ecl_make_fixnum(old_size));
		new_size_obj = ecl_ceiling1(new_size_obj);
	}
	if (!ECL_FIXNUMP(new_size_obj)) {
		/* New size is too large */
		new_size = old_size * 2;
	} else {
		new_size = ecl_fixnum(new_size_obj);
	}
        if (hashtable->hash.test == ecl_htt_pack) {
                new = ecl_alloc_object(t_hashtable);
                new->hash = hashtable->hash;
                old = hashtable;
        } else {
                old = ecl_alloc_object(t_hashtable);
                old->hash = hashtable->hash;
                new = hashtable;
        }
	new->hash.data = NULL; /* for GC sake */
	new->hash.entries = 0;
	new->hash.size = new_size;
	new->hash.limit = new->hash.size * new->hash.factor;
	new->hash.data = (struct ecl_hashtable_entry *)
	  ecl_alloc(new_size * sizeof(struct ecl_hashtable_entry));
	for (i = 0;  i < new_size;  i++) {
		new->hash.data[i].key = OBJNULL;
		new->hash.data[i].value = OBJNULL;
	}
	for (i = 0;  i < old_size;  i++) {
		struct ecl_hashtable_entry e =
			copy_entry(old->hash.data + i, old);
		if (e.key != OBJNULL) {
			new = new->hash.set(new->hash.test == ecl_htt_pack?
					    SYMBOL_NAME(e.value) : e.key,
					    new, e.value);
		}
	}
        return new;
}

#line 732
cl_object cl_make_hash_table(cl_narg narg, ...)
{
#line 732

#line 734
	const cl_env_ptr the_env = ecl_process_env();
#line 734
	static cl_object KEYS[5] = {(cl_object)(cl_symbols+1316), (cl_object)(cl_symbols+1949), (cl_object)(cl_symbols+1308), (cl_object)(cl_symbols+1297), (cl_object)(cl_symbols+1298)};
	cl_object test;
	cl_object weakness;
	cl_object size;
	cl_object rehash_size;
	cl_object rehash_threshold;
#line 734
	cl_object KEY_VARS[10];
#line 734
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
#line 734
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(528));
#line 734
	cl_parse_key(ARGS, 5, KEYS, KEY_VARS, NULL, 0);
#line 734
	if (KEY_VARS[5]==ECL_NIL) {
#line 734
	  test = ECL_SYM("EQL",334);
	} else {
#line 734
	  test = KEY_VARS[0];
	}
#line 734
	if (KEY_VARS[6]==ECL_NIL) {
#line 734
	  weakness = ECL_NIL;
	} else {
#line 734
	  weakness = KEY_VARS[1];
	}
#line 734
	if (KEY_VARS[7]==ECL_NIL) {
#line 734
	  size = ecl_make_fixnum(1024);
	} else {
#line 734
	  size = KEY_VARS[2];
	}
#line 734
	if (KEY_VARS[8]==ECL_NIL) {
#line 734
	  rehash_size = cl_core.rehash_size;
	} else {
#line 734
	  rehash_size = KEY_VARS[3];
	}
#line 734
	if (KEY_VARS[9]==ECL_NIL) {
#line 734
	  rehash_threshold = cl_core.rehash_threshold;
	} else {
#line 734
	  rehash_threshold = KEY_VARS[4];
	}
#line 734
{
	cl_object hash = cl__make_hash_table(test, size, rehash_size, rehash_threshold);
#ifdef ECL_WEAK_HASH
	if (!Null(weakness)) {
		if (weakness == ECL_SYM(":KEY",1262)) {
			hash->hash.weak = ecl_htt_weak_key;
		} else if (weakness == ECL_SYM(":VALUE",1947)) {
			hash->hash.weak = ecl_htt_weak_value;
		} else if (weakness == ECL_SYM(":KEY-AND-VALUE",1948)) {
			hash->hash.weak = ecl_htt_weak_key_and_value;
		} else {
			FEwrong_type_key_arg(ecl_make_fixnum(/*MAKE-HASH-TABLE*/528),
					     ecl_make_fixnum(/*:WEAKNESS*/1949),
					     cl_list(5, ECL_SYM("MEMBER",552),
						     ECL_NIL, ECL_SYM(":KEY",1262), ECL_SYM(":VALUE",1947),
						     ECL_SYM(":KEY-AND-VALUE",1948)),
					     weakness);
		}
		hash->hash.get = _ecl_gethash_weak;
		hash->hash.set = _ecl_sethash_weak;
		hash->hash.rem = _ecl_remhash_weak;
	}
#endif
	{
#line 757
		#line 757
		cl_object __value0 = hash;
#line 757
		the_env->nvalues = 1;
#line 757
		return __value0;
#line 757
	}

}
}

static void
do_clrhash(cl_object ht)
{
	/*
	 * Fill a hash with null pointers and ensure it does not have
	 * any entry. We separate this routine because it is needed
	 * both by clrhash and hash table initialization.
	 */
	cl_index i;
	ht->hash.entries = 0;
	for(i = 0; i < ht->hash.size; i++) {
		ht->hash.data[i].key = OBJNULL;
		ht->hash.data[i].value = OBJNULL;
	}
}

ecl_def_ct_single_float(min_threshold, 0.1, static, const);

cl_object
cl__make_hash_table(cl_object test, cl_object size, cl_object rehash_size,
		    cl_object rehash_threshold)
{
	int htt;
	cl_index hsize;
	cl_object h;
	cl_object (*get)(cl_object, cl_object, cl_object);
	cl_object (*set)(cl_object, cl_object, cl_object);
	bool (*rem)(cl_object, cl_object);
	/*
	 * Argument checking
	 */
	if (test == ECL_SYM("EQ",333) || test == ECL_SYM_FUN(ECL_SYM("EQ",333))) {
		htt = ecl_htt_eq;
		get = _ecl_gethash_eq;
		set = _ecl_sethash_eq;
		rem = _ecl_remhash_eq;
	} else if (test == ECL_SYM("EQL",334) || test == ECL_SYM_FUN(ECL_SYM("EQL",334))) {
		htt = ecl_htt_eql;
		get = _ecl_gethash_eql;
		set = _ecl_sethash_eql;
		rem = _ecl_remhash_eql;
	} else if (test == ECL_SYM("EQUAL",335) || test == ECL_SYM_FUN(ECL_SYM("EQUAL",335))) {
		htt = ecl_htt_equal;
		get = _ecl_gethash_equal;
		set = _ecl_sethash_equal;
		rem = _ecl_remhash_equal;
	} else if (test == ECL_SYM("EQUALP",336) || test == ECL_SYM_FUN(ECL_SYM("EQUALP",336))) {
		htt = ecl_htt_equalp;
		get = _ecl_gethash_equalp;
		set = _ecl_sethash_equalp;
		rem = _ecl_remhash_equalp;
	} else if (test == ECL_SYM("PACKAGE",617)) {
		htt = ecl_htt_pack;
		get = _ecl_gethash_pack;
		set = _ecl_sethash_pack;
		rem = _ecl_remhash_pack;
	} else {
		FEerror("~S is an illegal hash-table test function.",
			1, test);
	}
        if (ecl_unlikely(!ECL_FIXNUMP(size) ||
                         ecl_fixnum_minusp(size) ||
                         ecl_fixnum_geq(size,ecl_make_fixnum(ECL_ARRAY_TOTAL_LIMIT)))) {
            FEwrong_type_key_arg(ecl_make_fixnum(/*MAKE-HASH-TABLE*/528), ecl_make_fixnum(/*:SIZE*/1308), size,
                                 ecl_make_integer_type(ecl_make_fixnum(0),
                                                       ecl_make_fixnum(ECL_ARRAY_TOTAL_LIMIT)));
        }
        hsize = ecl_fixnum(size);
	if (hsize < 16) {
		hsize = 16;
	}
 AGAIN:
	if (ecl_minusp(rehash_size)) {
	ERROR1:
		rehash_size =
			ecl_type_error(ECL_SYM("MAKE-HASH-TABLE",528),"rehash-size",
				       rehash_size,
				       ecl_read_from_cstring("(OR (INTEGER 1 *) (FLOAT 0 (1)))"));
		goto AGAIN;
	}
	if (floatp(rehash_size)) {
		if (ecl_number_compare(rehash_size, ecl_make_fixnum(1)) < 0 ||
		    ecl_minusp(rehash_size)) {
			goto ERROR1;
		}
		rehash_size = ecl_make_double_float(ecl_to_double(rehash_size));
	} else if (!ECL_FIXNUMP(rehash_size)) {
		goto ERROR1;
	}
	while (!ecl_numberp(rehash_threshold) ||
	       ecl_minusp(rehash_threshold) ||
	       ecl_number_compare(rehash_threshold, ecl_make_fixnum(1)) > 0)
	{
		rehash_threshold =
			ecl_type_error(ECL_SYM("MAKE-HASH-TABLE",528),"rehash-threshold",
				       rehash_threshold,
				       ecl_read_from_cstring("(REAL 0 1)"));
	}
	/*
	 * Build actual hash.
	 */
	h = ecl_alloc_object(t_hashtable);
	h->hash.test = htt;
	h->hash.weak = ecl_htt_not_weak;
	h->hash.get = get;
	h->hash.set = set;
	h->hash.rem = rem;
	h->hash.size = hsize;
        h->hash.entries = 0;
	h->hash.rehash_size = rehash_size;
	h->hash.threshold = rehash_threshold;
        rehash_threshold = cl_max(2, min_threshold, rehash_threshold);
	h->hash.factor = ecl_to_double(rehash_threshold);
	h->hash.limit = h->hash.size * h->hash.factor;
	h->hash.data = NULL;	/* for GC sake */
	h->hash.data = (struct ecl_hashtable_entry *)
		ecl_alloc(hsize * sizeof(struct ecl_hashtable_entry));
	do_clrhash(h);
	return h;
}

cl_object
cl_hash_table_p(cl_object ht)
{
	{
#line 885
		const cl_env_ptr the_env = ecl_process_env();
#line 885
		#line 885
		cl_object __value0 = (ECL_HASH_TABLE_P(ht) ? ECL_T : ECL_NIL);
#line 885
		the_env->nvalues = 1;
#line 885
		return __value0;
#line 885
	}

}

cl_object
si_hash_table_weakness(cl_object ht)
{
	cl_object output = ECL_NIL;
#ifdef ECL_WEAK_HASH
	switch (ht->hash.weak) {
	case ecl_htt_weak_key: output = ECL_SYM(":KEY",1262); break;
	case ecl_htt_weak_value: output = ECL_SYM(":VALUE",1947); break;
	case ecl_htt_weak_key_and_value: output = ECL_SYM(":KEY-AND-VALUE",1948); break;
	case ecl_htt_not_weak: default: output = ECL_NIL; break;
	}
#endif
	{
#line 900
		const cl_env_ptr the_env = ecl_process_env();
#line 900
		#line 900
		cl_object __value0 = output;
#line 900
		the_env->nvalues = 1;
#line 900
		return __value0;
#line 900
	}

}

#line 903
cl_object cl_gethash(cl_narg narg, cl_object key, cl_object ht, ...)
{
#line 903

#line 905
	const cl_env_ptr the_env = ecl_process_env();
#line 905
	cl_object no_value;
#line 905
	va_list ARGS;
	va_start(ARGS, ht);
#line 905
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(413));
#line 905
	if (narg > 2) {
#line 905
		no_value = va_arg(ARGS,cl_object);
#line 905
	} else {
#line 905
		no_value = ECL_NIL;
#line 905
	}
#line 905
{
	assert_type_hash_table(ecl_make_fixnum(/*GETHASH*/413), 2, ht);
	{
		cl_object v = ht->hash.get(key, ht, OBJNULL);
		if (v != OBJNULL) {
			{
#line 910
				#line 910
				cl_object __value0 = v;
#line 910
				cl_object __value1 = ECL_T;
#line 910
				the_env->nvalues = 2;
#line 910
				the_env->values[1] = __value1;
#line 910
				return __value0;
#line 910
			}
;
		} else {
			{
#line 912
				#line 912
				cl_object __value0 = no_value;
#line 912
				cl_object __value1 = ECL_NIL;
#line 912
				the_env->nvalues = 2;
#line 912
				the_env->values[1] = __value1;
#line 912
				return __value0;
#line 912
			}
;
		}
	}
}
}

cl_object
si_hash_set(cl_object key, cl_object ht, cl_object val)
{
	/* INV: ecl_sethash() checks the type of hashtable */
	ecl_sethash(key, ht, val);
	{
#line 923
		const cl_env_ptr the_env = ecl_process_env();
#line 923
		#line 923
		cl_object __value0 = val;
#line 923
		the_env->nvalues = 1;
#line 923
		return __value0;
#line 923
	}

}

bool
ecl_remhash(cl_object key, cl_object hashtable)
{
	assert_type_hash_table(ecl_make_fixnum(/*REMHASH*/709), 2, hashtable);
	return hashtable->hash.rem(key, hashtable);
}

cl_object
cl_remhash(cl_object key, cl_object ht)
{
	/* INV: _ecl_remhash() checks the type of hashtable */
	{
#line 937
		const cl_env_ptr the_env = ecl_process_env();
#line 937
		#line 937
		cl_object __value0 = (ecl_remhash(key, ht)? ECL_T : ECL_NIL);
#line 937
		the_env->nvalues = 1;
#line 937
		return __value0;
#line 937
	}
;
}

cl_object
cl_clrhash(cl_object ht)
{
	assert_type_hash_table(ecl_make_fixnum(/*CLRHASH*/229), 1, ht);
	if (ht->hash.entries) {
		do_clrhash(ht);
	}
	{
#line 947
		const cl_env_ptr the_env = ecl_process_env();
#line 947
		#line 947
		cl_object __value0 = ht;
#line 947
		the_env->nvalues = 1;
#line 947
		return __value0;
#line 947
	}

}

cl_object
cl_hash_table_test(cl_object ht)
{
	cl_object output;
	assert_type_hash_table(ecl_make_fixnum(/*HASH-TABLE-TEST*/424), 1, ht);
	switch(ht->hash.test) {
	    case ecl_htt_eq: output = ECL_SYM("EQ",333); break;
	    case ecl_htt_eql: output = ECL_SYM("EQL",334); break;
	    case ecl_htt_equal: output = ECL_SYM("EQUAL",335); break;
	    case ecl_htt_equalp: output = ECL_SYM("EQUALP",336); break;
	    case ecl_htt_pack:
	    default: output = ECL_SYM("EQUAL",335);
	}
	{
#line 963
		const cl_env_ptr the_env = ecl_process_env();
#line 963
		#line 963
		cl_object __value0 = output;
#line 963
		the_env->nvalues = 1;
#line 963
		return __value0;
#line 963
	}

}

cl_object
cl_hash_table_size(cl_object ht)
{
	assert_type_hash_table(ecl_make_fixnum(/*HASH-TABLE-SIZE*/423), 1, ht);
	{
#line 970
		const cl_env_ptr the_env = ecl_process_env();
#line 970
		#line 970
		cl_object __value0 = ecl_make_fixnum(ht->hash.size);
#line 970
		the_env->nvalues = 1;
#line 970
		return __value0;
#line 970
	}

}

cl_object
cl_hash_table_count(cl_object ht)
{
	assert_type_hash_table(ecl_make_fixnum(/*HASH-TABLE-COUNT*/419), 1, ht);
	{
#line 977
		const cl_env_ptr the_env = ecl_process_env();
#line 977
		#line 977
		cl_object __value0 = (ecl_make_fixnum(ht->hash.entries));
#line 977
		the_env->nvalues = 1;
#line 977
		return __value0;
#line 977
	}

}

static cl_object
si_hash_table_iterate(cl_narg narg)
{
	const cl_env_ptr the_env = ecl_process_env();
        cl_object env = the_env->function->cclosure.env;
	cl_object index = CAR(env);
	cl_object ht = CADR(env);
	cl_fixnum i;
	if (!Null(index)) {
		i = ecl_fixnum(index);
		if (i < 0)
			i = -1;
		for (; ++i < ht->hash.size; ) {
			struct ecl_hashtable_entry e =
				copy_entry(ht->hash.data + i, ht);
			if (e.key != OBJNULL) {
				cl_object ndx = ecl_make_fixnum(i);
				ECL_RPLACA(env, ndx);
				{
#line 998
					const cl_env_ptr the_env = ecl_process_env();
#line 998
					#line 998
					cl_object __value0 = ndx;
#line 998
					cl_object __value1 = e.key;
#line 998
					cl_object __value2 = e.value;
#line 998
					the_env->nvalues = 3;
#line 998
					the_env->values[2] = __value2;
#line 998
					the_env->values[1] = __value1;
#line 998
					return __value0;
#line 998
				}

			}
		}
		ECL_RPLACA(env, ECL_NIL);
	}
	{
#line 1003
		const cl_env_ptr the_env = ecl_process_env();
#line 1003
		#line 1003
		cl_object __value0 = ECL_NIL;
#line 1003
		the_env->nvalues = 1;
#line 1003
		return __value0;
#line 1003
	}

}

cl_object
si_hash_table_iterator(cl_object ht)
{
	assert_type_hash_table(ecl_make_fixnum(/*SI::HASH-TABLE-ITERATOR*/1089), 1, ht);
	{
#line 1012
		const cl_env_ptr the_env = ecl_process_env();
#line 1012
		#line 1012
		cl_object __value0 = ecl_make_cclosure_va((cl_objectfn)si_hash_table_iterate,
                                      cl_list(2, ecl_make_fixnum(-1), ht),
                                      ECL_SYM("SI::HASH-TABLE-ITERATOR",1089));
#line 1012
		the_env->nvalues = 1;
#line 1012
		return __value0;
#line 1012
	}

}

cl_object
cl_hash_table_rehash_size(cl_object ht)
{
	assert_type_hash_table(ecl_make_fixnum(/*HASH-TABLE-REHASH-SIZE*/421), 1, ht);
	{
#line 1019
		const cl_env_ptr the_env = ecl_process_env();
#line 1019
		#line 1019
		cl_object __value0 = ht->hash.rehash_size;
#line 1019
		the_env->nvalues = 1;
#line 1019
		return __value0;
#line 1019
	}

}

cl_object
cl_hash_table_rehash_threshold(cl_object ht)
{
	assert_type_hash_table(ecl_make_fixnum(/*HASH-TABLE-REHASH-THRESHOLD*/422), 1, ht);
	{
#line 1026
		const cl_env_ptr the_env = ecl_process_env();
#line 1026
		#line 1026
		cl_object __value0 = ht->hash.threshold;
#line 1026
		the_env->nvalues = 1;
#line 1026
		return __value0;
#line 1026
	}

}

cl_object
cl_sxhash(cl_object key)
{
	cl_index output = _hash_equal(3, 0, key);
	const cl_index mask = ((cl_index)1 << (FIXNUM_BITS - 3)) - 1;
	{
#line 1034
		const cl_env_ptr the_env = ecl_process_env();
#line 1034
		#line 1034
		cl_object __value0 = ecl_make_fixnum(output & mask);
#line 1034
		the_env->nvalues = 1;
#line 1034
		return __value0;
#line 1034
	}

}

#line 1037
cl_object si_hash_eql(cl_narg narg, ...)
{
#line 1037

	cl_index h;
#line 1040
	const cl_env_ptr the_env = ecl_process_env();
#line 1040
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 1040
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(1662));
#line 1040
	for (h = 0; narg; narg--) {
		cl_object o = ecl_va_arg(args);
		h = _hash_eql(h, o);
	}
	{
#line 1044
		#line 1044
		cl_object __value0 = ecl_make_fixnum(h);
#line 1044
		the_env->nvalues = 1;
#line 1044
		return __value0;
#line 1044
	}

}

#line 1047
cl_object si_hash_equal(cl_narg narg, ...)
{
#line 1047

	cl_index h;
#line 1050
	const cl_env_ptr the_env = ecl_process_env();
#line 1050
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 1050
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(1663));
#line 1050
	for (h = 0; narg; narg--) {
		cl_object o = ecl_va_arg(args);
		h = _hash_equal(3, h, o);
	}
	{
#line 1054
		#line 1054
		cl_object __value0 = ecl_make_fixnum(h);
#line 1054
		the_env->nvalues = 1;
#line 1054
		return __value0;
#line 1054
	}

}

#line 1057
cl_object si_hash_equalp(cl_narg narg, ...)
{
#line 1057

	cl_index h;
#line 1060
	const cl_env_ptr the_env = ecl_process_env();
#line 1060
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
#line 1060
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(1664));
#line 1060
	for (h = 0; narg; narg--) {
		cl_object o = ecl_va_arg(args);
		h = _hash_equalp(3, h, o);
	}
	{
#line 1064
		#line 1064
		cl_object __value0 = ecl_make_fixnum(h);
#line 1064
		the_env->nvalues = 1;
#line 1064
		return __value0;
#line 1064
	}

}

cl_object
cl_maphash(cl_object fun, cl_object ht)
{
	cl_index i;

	assert_type_hash_table(ecl_make_fixnum(/*MAPHASH*/547), 2, ht);
	for (i = 0;  i < ht->hash.size;  i++) {
		struct ecl_hashtable_entry e = ht->hash.data[i];
		if(e.key != OBJNULL)
			funcall(3, fun, e.key, e.value);
	}
	{
#line 1078
		const cl_env_ptr the_env = ecl_process_env();
#line 1078
		#line 1078
		cl_object __value0 = ECL_NIL;
#line 1078
		the_env->nvalues = 1;
#line 1078
		return __value0;
#line 1078
	}

}

cl_object
si_hash_table_content(cl_object ht)
{
	cl_index i;
	cl_object output = ECL_NIL;
	assert_type_hash_table(ecl_make_fixnum(/*EXT::HASH-TABLE-CONTENT*/1932), 2, ht);
	for (i = 0;  i < ht->hash.size;  i++) {
		struct ecl_hashtable_entry e = ht->hash.data[i];
		if (e.key != OBJNULL)
			output = ecl_cons(ecl_cons(e.key, e.value), output);
	}
	{
#line 1092
		const cl_env_ptr the_env = ecl_process_env();
#line 1092
		#line 1092
		cl_object __value0 = output;
#line 1092
		the_env->nvalues = 1;
#line 1092
		return __value0;
#line 1092
	}

}

cl_object
si_hash_table_fill(cl_object ht, cl_object values)
{
	assert_type_hash_table(ecl_make_fixnum(/*EXT::HASH-TABLE-FILL*/1933), 2, ht);
	while (!Null(values)) {
		cl_object pair = ecl_car(values);
		cl_object key = ecl_car(pair);
		cl_object value = ECL_CONS_CDR(pair);
		values = ECL_CONS_CDR(values);
		ecl_sethash(key, ht, value);
	}
	{
#line 1106
		const cl_env_ptr the_env = ecl_process_env();
#line 1106
		#line 1106
		cl_object __value0 = ht;
#line 1106
		the_env->nvalues = 1;
#line 1106
		return __value0;
#line 1106
	}

}

cl_object
si_copy_hash_table(cl_object orig)
{
	cl_object hash;
	hash = cl__make_hash_table(cl_hash_table_test(orig),
				   cl_hash_table_size(orig),
				   cl_hash_table_rehash_size(orig),
				   cl_hash_table_rehash_threshold(orig));
	memcpy(hash->hash.data, orig->hash.data,
	       orig->hash.size * sizeof(*orig->hash.data));
	hash->hash.entries = orig->hash.entries;
	{
#line 1120
		const cl_env_ptr the_env = ecl_process_env();
#line 1120
		#line 1120
		cl_object __value0 = hash;
#line 1120
		the_env->nvalues = 1;
#line 1120
		return __value0;
#line 1120
	}

}
