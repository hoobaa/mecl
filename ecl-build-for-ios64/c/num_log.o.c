#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/num_log.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    num_log.c  -- Logical operations on numbers.
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
#include <stdlib.h>
#include <ecl/internal.h>

/*
 * BIT OPERATIONS FOR FIXNUMS
 */

static cl_fixnum
ior_op(cl_fixnum i, cl_fixnum j)
{
	return(i | j);
}

static cl_fixnum
xor_op(cl_fixnum i, cl_fixnum j)
{
	return(i ^ j);
}

static cl_fixnum
and_op(cl_fixnum i, cl_fixnum j)
{
	return(i & j);
}

static cl_fixnum
eqv_op(cl_fixnum i, cl_fixnum j)
{
	return(~(i ^ j));
}

static cl_fixnum
nand_op(cl_fixnum i, cl_fixnum j)
{
	return(~(i & j));
}

static cl_fixnum
nor_op(cl_fixnum i, cl_fixnum j)
{
	return(~(i | j));
}

static cl_fixnum
andc1_op(cl_fixnum i, cl_fixnum j)
{
	return((~i) & j);
}

static cl_fixnum
andc2_op(cl_fixnum i, cl_fixnum j)
{
	return(i & (~j));
}

static cl_fixnum
orc1_op(cl_fixnum i, cl_fixnum j)
{
	return((~i) | j);
}

static cl_fixnum
orc2_op(cl_fixnum i, cl_fixnum j)
{
	return(i | (~j));
}

static cl_fixnum
b_clr_op(cl_fixnum i, cl_fixnum j)
{
	return(0);
}

static cl_fixnum
b_set_op(cl_fixnum i, cl_fixnum j)
{
	return(-1);
}

static cl_fixnum
b_1_op(cl_fixnum i, cl_fixnum j)
{
	return(i);
}

static cl_fixnum
b_2_op(cl_fixnum i, cl_fixnum j)
{
	return(j);
}

static cl_fixnum
b_c1_op(cl_fixnum i, cl_fixnum j)
{
	return(~i);
}

static cl_fixnum
b_c2_op(cl_fixnum i, cl_fixnum j)
{
	return(~j);
}

typedef cl_fixnum (*bit_operator)(cl_fixnum, cl_fixnum);

static bit_operator fixnum_operations[16] = {
	b_clr_op,
	and_op,
	andc2_op,
	b_1_op,
	andc1_op,
	b_2_op,
	xor_op,
	ior_op,
	nor_op,
	eqv_op,
	b_c2_op,
	orc2_op,
	b_c1_op,
	orc1_op,
	nand_op,
	b_set_op};


static cl_object
log_op(cl_narg narg, int op, ecl_va_list ARGS)
{
	cl_object x, y;
	/* FIXME! This can be optimized */
	x = ecl_va_arg(ARGS);
	if (narg-- == 1) {
		assert_type_integer(x);
	} else {
		do {
			y = ecl_va_arg(ARGS);
			x = ecl_boole(op, x, y);
		} while (--narg);
	}
	return x;
}

cl_object
ecl_boole(int op, cl_object x, cl_object y)
{
	switch (ecl_t_of(x)) {
	case t_fixnum:
		switch (ecl_t_of(y)) {
		case t_fixnum: {
			cl_fixnum z = fixnum_operations[op](ecl_fixnum(x), ecl_fixnum(y));
			return ecl_make_fixnum(z);
		}
		case t_bignum: {
                        cl_object x_copy = _ecl_big_register0();
                        _ecl_big_set_fixnum(x_copy, ecl_fixnum(x));
                        (_ecl_big_boole_operator(op))(x_copy, x_copy, y);
                        return _ecl_big_register_normalize(x_copy);
		}
		default:
                        FEwrong_type_nth_arg(ecl_make_fixnum(/*BOOLE*/138), 2, y, ecl_make_fixnum(/*INTEGER*/437));
		}
		break;
	case t_bignum: {
                cl_object x_copy = _ecl_big_register0();
		switch (ecl_t_of(y)) {
		case t_fixnum: {
			cl_object z = _ecl_big_register1();
                        _ecl_big_set_fixnum(z,ecl_fixnum(y));
                        (_ecl_big_boole_operator(op))(x_copy, x, z);
			_ecl_big_register_free(z);
			break;
		}
		case t_bignum:
			(_ecl_big_boole_operator(op))(x_copy, x, y);
			break;
		default:
                        FEwrong_type_nth_arg(ecl_make_fixnum(/*BOOLE*/138), 2, y, ecl_make_fixnum(/*INTEGER*/437));
		}
                return _ecl_big_register_normalize(x_copy);
	}
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*BOOLE*/138), 1, x, ecl_make_fixnum(/*INTEGER*/437));
	}
	return x;
}

cl_object
cl_lognot(cl_object x)
{
	return cl_logxor(2,x,ecl_make_fixnum(-1));
}

static cl_fixnum
count_bits(cl_object x)
{
	cl_fixnum count;

	switch (ecl_t_of(x)) {
	case t_fixnum: {
		cl_fixnum i = ecl_fixnum(x);
		cl_fixnum j = (i < 0) ? ~i : i;
		for (count=0 ; j ; j >>= 1)
			if (j & 1) count++;
		break;
	}
	case t_bignum:
		if (_ecl_big_sign(x) >= 0)
			count = mpz_popcount(x->big.big_num);
		else {
			cl_object z = _ecl_big_register0();
			mpz_com(z->big.big_num, x->big.big_num);
			count = mpz_popcount(z->big.big_num);
			_ecl_big_register_free(z);
		}
		break;
	default:
                FEwrong_type_only_arg(ecl_make_fixnum(/*LOGCOUNT*/496), x, ecl_make_fixnum(/*INTEGER*/437));
	}
	return count;
}

/*
   Left shift if w > 0, right shift if w < 0.
 */
cl_object
ecl_ash(cl_object x, cl_fixnum w)
{
	cl_object y;

	if (w == 0)
		return(x);
	y = _ecl_big_register0();
	if (w < 0) {
		cl_index bits = -w;
		if (ECL_FIXNUMP(x)) {
			/* The result of shifting a number further than the number
			 * of digits it has is unpredictable in C. For instance, GCC
			 * on intel masks out all bits of "bits" beyond the 5 and
			 * it may happen that a shift of 37 becomes a shift of 5.
			 * Furthermore, in general, shifting negative numbers leads
			 * to implementation-specific results :-/
			 */
			cl_fixnum y = ecl_fixnum(x);
			if (bits >= FIXNUM_BITS) {
				y = (y < 0)? -1 : 0;
			} else {
				y >>= bits;
			}
			return ecl_make_fixnum(y);
		}
		mpz_div_2exp(y->big.big_num, x->big.big_num, bits);
	} else {
		if (ECL_FIXNUMP(x)) {
			_ecl_big_set_fixnum(y, ecl_fixnum(x));
			x = y;
		}
		mpz_mul_2exp(y->big.big_num, x->big.big_num, (unsigned long)w);
	}
	return _ecl_big_register_normalize(y);
}

int
ecl_fixnum_bit_length(cl_fixnum i)
{
	int count;
	if (i < 0)
		i = ~i;
	for (count = 0; i && (count < FIXNUM_BITS); i >>= 1, count++)
		;
	return count;
}

// ------------------------------1
#line 290
cl_object cl_logior(cl_narg narg, ...)
{
#line 290
// ------------------------------2
#line 290
	const cl_env_ptr the_env = ecl_process_env();
#line 290
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
#line 290
// ------------------------------3

#line 292
// ------------------------------4
#line 292
#line 292
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(500));
#line 292
// ------------------------------5
	if (narg == 0)
		{
#line 293
			#line 293
			cl_object __value0 = ecl_make_fixnum(0);
#line 293
			the_env->nvalues = 1;
#line 293
			return __value0;
#line 293
		}

	/* INV: log_op() checks types and outputs first argument as default. */
	{
#line 295
		#line 295
		cl_object __value0 = log_op(narg, ECL_BOOLIOR, nums);
#line 295
		the_env->nvalues = 1;
#line 295
		return __value0;
#line 295
	}

}

// ------------------------------1
#line 298
cl_object cl_logxor(cl_narg narg, ...)
{
#line 298
// ------------------------------2
#line 298
	const cl_env_ptr the_env = ecl_process_env();
#line 298
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
#line 298
// ------------------------------3

#line 300
// ------------------------------4
#line 300
#line 300
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(507));
#line 300
// ------------------------------5
	if (narg == 0)
		{
#line 301
			#line 301
			cl_object __value0 = ecl_make_fixnum(0);
#line 301
			the_env->nvalues = 1;
#line 301
			return __value0;
#line 301
		}

	/* INV: log_op() checks types and outputs first argument as default. */
	{
#line 303
		#line 303
		cl_object __value0 = log_op(narg, ECL_BOOLXOR, nums);
#line 303
		the_env->nvalues = 1;
#line 303
		return __value0;
#line 303
	}

}

// ------------------------------1
#line 306
cl_object cl_logand(cl_narg narg, ...)
{
#line 306
// ------------------------------2
#line 306
	const cl_env_ptr the_env = ecl_process_env();
#line 306
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
#line 306
// ------------------------------3

#line 308
// ------------------------------4
#line 308
#line 308
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(492));
#line 308
// ------------------------------5
	if (narg == 0)
		{
#line 309
			#line 309
			cl_object __value0 = ecl_make_fixnum(-1);
#line 309
			the_env->nvalues = 1;
#line 309
			return __value0;
#line 309
		}

	/* INV: log_op() checks types and outputs first argument as default. */
	{
#line 311
		#line 311
		cl_object __value0 = log_op(narg, ECL_BOOLAND, nums);
#line 311
		the_env->nvalues = 1;
#line 311
		return __value0;
#line 311
	}

}

// ------------------------------1
#line 314
cl_object cl_logeqv(cl_narg narg, ...)
{
#line 314
// ------------------------------2
#line 314
	const cl_env_ptr the_env = ecl_process_env();
#line 314
	ecl_va_list nums;
	ecl_va_start(nums, narg, narg, 0);
#line 314
// ------------------------------3

#line 316
// ------------------------------4
#line 316
#line 316
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(497));
#line 316
// ------------------------------5
	if (narg == 0)
		{
#line 317
			#line 317
			cl_object __value0 = ecl_make_fixnum(-1);
#line 317
			the_env->nvalues = 1;
#line 317
			return __value0;
#line 317
		}

	/* INV: log_op() checks types and outputs first argument as default. */
	{
#line 319
		#line 319
		cl_object __value0 = log_op(narg, ECL_BOOLEQV, nums);
#line 319
		the_env->nvalues = 1;
#line 319
		return __value0;
#line 319
	}

}

cl_object
cl_lognand(cl_object x, cl_object y)
{
	{
#line 325
		const cl_env_ptr the_env = ecl_process_env();
#line 325
		#line 325
		cl_object __value0 = ecl_boole(ECL_BOOLNAND, x, y);
#line 325
		the_env->nvalues = 1;
#line 325
		return __value0;
#line 325
	}

}

cl_object
cl_lognor(cl_object x, cl_object y)
{
	{
#line 331
		const cl_env_ptr the_env = ecl_process_env();
#line 331
		#line 331
		cl_object __value0 = ecl_boole(ECL_BOOLNOR, x, y);
#line 331
		the_env->nvalues = 1;
#line 331
		return __value0;
#line 331
	}

}

cl_object
cl_logandc1(cl_object x, cl_object y)
{
	{
#line 337
		const cl_env_ptr the_env = ecl_process_env();
#line 337
		#line 337
		cl_object __value0 = ecl_boole(ECL_BOOLANDC1, x, y);
#line 337
		the_env->nvalues = 1;
#line 337
		return __value0;
#line 337
	}

}

cl_object
cl_logandc2(cl_object x, cl_object y)
{
	{
#line 343
		const cl_env_ptr the_env = ecl_process_env();
#line 343
		#line 343
		cl_object __value0 = ecl_boole(ECL_BOOLANDC2, x, y);
#line 343
		the_env->nvalues = 1;
#line 343
		return __value0;
#line 343
	}

}

cl_object
cl_logorc1(cl_object x, cl_object y)
{
	{
#line 349
		const cl_env_ptr the_env = ecl_process_env();
#line 349
		#line 349
		cl_object __value0 = ecl_boole(ECL_BOOLORC1, x, y);
#line 349
		the_env->nvalues = 1;
#line 349
		return __value0;
#line 349
	}

}

cl_object
cl_logorc2(cl_object x, cl_object y)
{
	{
#line 355
		const cl_env_ptr the_env = ecl_process_env();
#line 355
		#line 355
		cl_object __value0 = ecl_boole(ECL_BOOLORC2, x, y);
#line 355
		the_env->nvalues = 1;
#line 355
		return __value0;
#line 355
	}

}

static int
coerce_to_logical_operator(cl_object o)
{
	cl_fixnum op;
	op = ecl_to_fix(o);
	if (op < 0 || op > ECL_BOOLSET)
		FEerror("~S is an invalid logical operator.", 1, o);
	return op;
}

cl_object
cl_boole(cl_object o, cl_object x, cl_object y)
{
	/* INV: log_op2() checks types */
	{
#line 372
		const cl_env_ptr the_env = ecl_process_env();
#line 372
		#line 372
		cl_object __value0 = ecl_boole(coerce_to_logical_operator(o), x, y);
#line 372
		the_env->nvalues = 1;
#line 372
		return __value0;
#line 372
	}

}

cl_object
cl_logbitp(cl_object p, cl_object x)
{
	bool i;

	assert_type_integer(x);
	if (ECL_FIXNUMP(p)) {
		cl_index n = ecl_to_size(p);
		if (ECL_FIXNUMP(x)) {
			cl_fixnum y = ecl_fixnum(x);
			if (n >= FIXNUM_BITS) {
				i = (y < 0);
			} else {
				i = ((y >> n) & 1);
			}
		} else {
			i = mpz_tstbit(x->big.big_num, n);
		}
	} else {
		assert_type_non_negative_integer(p);
		if (ECL_FIXNUMP(x))
			i = (ecl_fixnum(x) < 0);
		else
			i = (_ecl_big_sign(x) < 0);
	}
	{
#line 400
		const cl_env_ptr the_env = ecl_process_env();
#line 400
		#line 400
		cl_object __value0 = (i ? ECL_T : ECL_NIL);
#line 400
		the_env->nvalues = 1;
#line 400
		return __value0;
#line 400
	}

}

cl_object
cl_ash(cl_object x, cl_object y)
{
	cl_object r;
	int sign_x;

        assert_type_integer(x);
	assert_type_integer(y);
	if (ECL_FIXNUMP(y))
	  r = ecl_ash(x, ecl_fixnum(y));
	else {
	  /*
	    bit position represented by bignum is probably
	    out of our address space. So, result is returned
	    according to sign of integer.
	    */
	  if (ECL_FIXNUMP(x))
	    if (ecl_fixnum_minusp(x))
	      sign_x = -1;
	    else if (x == ecl_make_fixnum(0))
	      sign_x = 0;
	    else
	      sign_x = 1;
	  else
	    sign_x = _ecl_big_sign(x);
	  if (_ecl_big_sign(y) < 0)
	    if (sign_x < 0)
	      r = ecl_make_fixnum(-1);
	    else
	      r = ecl_make_fixnum(0);
	  else if (sign_x == 0)
	    r = x;
	  else
	    FEerror("Insufficient memory.", 0);
	}
	{
#line 438
		const cl_env_ptr the_env = ecl_process_env();
#line 438
		#line 438
		cl_object __value0 = r;
#line 438
		the_env->nvalues = 1;
#line 438
		return __value0;
#line 438
	}

}

cl_object
cl_logcount(cl_object x)
{
	{
#line 444
		const cl_env_ptr the_env = ecl_process_env();
#line 444
		#line 444
		cl_object __value0 = ecl_make_fixnum(count_bits(x));
#line 444
		the_env->nvalues = 1;
#line 444
		return __value0;
#line 444
	}

}

cl_index
ecl_integer_length(cl_object x)
{
	int count;
	cl_fixnum i;

	switch (ecl_t_of(x)) {
	case t_fixnum:
		i = ecl_fixnum(x);
		count = ecl_fixnum_bit_length(i);
		break;
	case t_bignum:
		if (_ecl_big_sign(x) < 0)
			x = cl_lognot(x);
		count = mpz_sizeinbase(x->big.big_num, 2);
		break;
	default:
                FEwrong_type_only_arg(ecl_make_fixnum(/*INTEGER-LENGTH*/439), x, ecl_make_fixnum(/*INTEGER*/437));
	}
	return count;
}

cl_object
cl_integer_length(cl_object x)
{
	{
#line 472
		const cl_env_ptr the_env = ecl_process_env();
#line 472
		#line 472
		cl_object __value0 = ecl_make_fixnum(ecl_integer_length(x));
#line 472
		the_env->nvalues = 1;
#line 472
		return __value0;
#line 472
	}

}

cl_object
si_bit_array_op(cl_object o, cl_object x, cl_object y, cl_object r)
{
	cl_fixnum i, j, n, d;
	cl_object r0;
	bit_operator op;
	bool replace = FALSE;
	int xi, yi, ri;
	byte *xp, *yp, *rp;
	int xo, yo, ro;

	if (ecl_t_of(x) == t_bitvector) {
		d = x->vector.dim;
		xp = x->vector.self.bit;
		xo = x->vector.offset;
		if (ecl_t_of(y) != t_bitvector)
			goto ERROR;
		if (d != y->vector.dim)
			goto ERROR;
		yp = y->vector.self.bit;
		yo = y->vector.offset;
		if (r == ECL_T)
			r = x;
		if (r != ECL_NIL) {
			if (ecl_t_of(r) != t_bitvector)
				goto ERROR;
			if (r->vector.dim != d)
				goto ERROR;
			i = (r->vector.self.bit - xp)*8 + (r->vector.offset - xo);
			if ((i > 0 && i < d) || (i < 0 && -i < d)) {
				r0 = r;
				r = ECL_NIL;
				replace = TRUE;
				goto L1;
			}
			i = (r->vector.self.bit - yp)*8 + (r->vector.offset - yo);
			if ((i > 0 && i < d) || (i < 0 && -i < d)) {
				r0 = r;
				r = ECL_NIL;
				replace = TRUE;
			}
		}
	L1:
		if (Null(r)) {
			r = ecl_alloc_simple_vector(d, ecl_aet_bit);
		}
	} else {
		if (ecl_t_of(x) != t_array)
			goto ERROR;
		if ((cl_elttype)x->array.elttype != ecl_aet_bit)
			goto ERROR;
		d = x->array.dim;
		xp = x->vector.self.bit;
		xo = x->vector.offset;
		if (ecl_t_of(y) != t_array)
			goto ERROR;
		if ((cl_elttype)y->array.elttype != ecl_aet_bit)
			goto ERROR;
		if (x->array.rank != y->array.rank)
			goto ERROR;
		yp = y->vector.self.bit;
		yo = y->vector.offset;
		for (i = 0;  i < x->array.rank;  i++)
			if (x->array.dims[i] != y->array.dims[i])
				goto ERROR;
		if (r == ECL_T)
			r = x;
		if (r != ECL_NIL) {
			if (ecl_t_of(r) != t_array)
				goto ERROR;
			if ((cl_elttype)r->array.elttype != ecl_aet_bit)
				goto ERROR;
			if (r->array.rank != x->array.rank)
				goto ERROR;
			for (i = 0;  i < x->array.rank;  i++)
				if (r->array.dims[i] != x->array.dims[i])
					goto ERROR;
			i = (r->vector.self.bit - xp)*8 + (r->vector.offset - xo);
			if ((i > 0 && i < d) || (i < 0 && -i < d)) {
				r0 = r;
				r = ECL_NIL;
				replace = TRUE;
				goto L2;
			} 
			i = (r->vector.self.bit - yp)*8 + (r->vector.offset - yo);
			if ((i > 0 && i < d) || (i < 0 && -i < d)) {
				r0 = r;
				r = ECL_NIL;
				replace = TRUE;
			}
		}
	L2:
		if (Null(r)) {
		  r = ecl_alloc_object(t_array);
		  r->array.self.t = NULL;
		  r->array.displaced = ECL_NIL;
		  r->array.rank = x->array.rank;
		  r->array.dims = x->array.dims;
		  r->array.elttype = ecl_aet_bit;
		  r->array.dim = x->array.dim;
		  r->array.flags = 0; /* no fill pointer, not adjustable */
		  ecl_array_allocself(r);
		}
	}
	rp = r->vector.self.bit;
	ro = r->vector.offset;
	op = fixnum_operations[coerce_to_logical_operator(o)];

#define	set_high(place, nbits, value) \
	(place)=((place)&~(-0400>>(nbits)))|((value)&(-0400>>(nbits)))

#define	set_low(place, nbits, value) \
	(place)=((place)&(-0400>>(8-(nbits))))|((value)&~(-0400>>(8-(nbits))))

#define	extract_byte(integer, pointer, index, offset) \
	(integer) = (pointer)[(index)+1] & 0377; \
	(integer) = ((pointer)[index]<<(offset))|((integer)>>(8-(offset)))

#define	store_byte(pointer, index, offset, value) \
	set_low((pointer)[index], 8-(offset), (value)>>(offset)); \
	set_high((pointer)[(index)+1], offset, (value)<<(8-(offset)))

	if (xo == 0 && yo == 0 && ro == 0) {
		for (n = d/8, i = 0;  i < n;  i++)
			rp[i] = (*op)(xp[i], yp[i]);
		if ((j = d%8) > 0)
			set_high(rp[n], j, (*op)(xp[n], yp[n]));
		if (!replace)
			{
#line 603
				const cl_env_ptr the_env = ecl_process_env();
#line 603
				#line 603
				cl_object __value0 = r;
#line 603
				the_env->nvalues = 1;
#line 603
				return __value0;
#line 603
			}

	} else {
		for (n = d/8, i = 0;  i <= n;  i++) {
			extract_byte(xi, xp, i, xo);
			extract_byte(yi, yp, i, yo);
			if (i == n) {
				if ((j = d%8) == 0)
					break;
				extract_byte(ri, rp, n, ro);
				set_high(ri, j, (*op)(xi, yi));
			} else
				ri = (*op)(xi, yi);
			store_byte(rp, i, ro, ri);
		}
		if (!replace)
			{
#line 618
				const cl_env_ptr the_env = ecl_process_env();
#line 618
				#line 618
				cl_object __value0 = r;
#line 618
				the_env->nvalues = 1;
#line 618
				return __value0;
#line 618
			}

	}
	rp = r0->vector.self.bit;
	ro = r0->vector.offset;
	for (n = d/8, i = 0;  i <= n;  i++) {
		if (i == n) {
			if ((j = d%8) == 0)
				break;
			extract_byte(ri, rp, n, ro);
			set_high(ri, j, r->vector.self.bit[n]);
		} else
			ri = r->vector.self.bit[i];
		store_byte(rp, i, ro, ri);
	}
	{
#line 632
		const cl_env_ptr the_env = ecl_process_env();
#line 632
		#line 632
		cl_object __value0 = r0;
#line 632
		the_env->nvalues = 1;
#line 632
		return __value0;
#line 632
	}

ERROR:
	FEerror("Illegal arguments for bit-array operation.", 0);
}
