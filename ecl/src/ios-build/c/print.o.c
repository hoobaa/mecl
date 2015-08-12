#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/print.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    print.d -- Print.
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
#include <stdio.h>
#include <ecl/ecl.h>
#include <ecl/internal.h>

cl_object
_ecl_stream_or_default_output(cl_object stream)
{
	if (Null(stream))
		return ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
	else if (stream == ECL_T)
		return ecl_symbol_value(ECL_SYM("*TERMINAL-IO*",68));
	return stream;
}

int
ecl_print_base(void)
{
	cl_object object = ecl_symbol_value(ECL_SYM("*PRINT-BASE*",45));
	cl_fixnum base;
	unlikely_if (!ECL_FIXNUMP(object) || (base = ecl_fixnum(object)) < 2 || base > 36) {
		ECL_SETQ(ecl_process_env(), ECL_SYM("*PRINT-BASE*",45), ecl_make_fixnum(10));
		FEerror("The value of *PRINT-BASE*~%  ~S~%"
                        "is not of the expected type (INTEGER 2 36)", 1, object);
	}
	return base;
}

cl_fixnum
ecl_print_level(void)
{
	cl_object object = ecl_symbol_value(ECL_SYM("*PRINT-LEVEL*",51));
	cl_fixnum level;
	if (object == ECL_NIL) {
		level = MOST_POSITIVE_FIXNUM;
	} else if (ECL_FIXNUMP(object)) {
		level = ecl_fixnum(object);
		if (level < 0) {
		ERROR:	ECL_SETQ(ecl_process_env(), ECL_SYM("*PRINT-LEVEL*",51), ECL_NIL);
			FEerror("The value of *PRINT-LEVEL*~%  ~S~%"
                                "is not of the expected type (OR NULL (INTEGER 0 *))",
                                1, object);
		}
	} else if (ecl_unlikely(!ECL_BIGNUMP(object))) {
		goto ERROR;
	} else {
		level = MOST_POSITIVE_FIXNUM;
	}
	return level;
}

cl_fixnum
ecl_print_length(void)
{
	cl_object object = ecl_symbol_value(ECL_SYM("*PRINT-LENGTH*",50));
	cl_fixnum length;
	if (object == ECL_NIL) {
		length = MOST_POSITIVE_FIXNUM;
	} else if (ECL_FIXNUMP(object)) {
		length = ecl_fixnum(object);
		unlikely_if (length < 0) {
		ERROR:	ECL_SETQ(ecl_process_env(), ECL_SYM("*PRINT-LENGTH*",50), ECL_NIL);
			FEerror("The value of *PRINT-LENGTH*~%  ~S~%"
                                "is not of the expected type (OR NULL (INTEGER 0 *))",
                                1, object);
		}
	} else if (ecl_unlikely(!ECL_BIGNUMP(object))) {
		goto ERROR;
	} else {
		length = MOST_POSITIVE_FIXNUM;
	}
	return length;
}

bool
ecl_print_radix(void)
{
	return ecl_symbol_value(ECL_SYM("*PRINT-RADIX*",56)) != ECL_NIL;
}

cl_object
ecl_print_case(void)
{
	cl_object output = ecl_symbol_value(ECL_SYM("*PRINT-CASE*",46));
	unlikely_if (output != ECL_SYM(":UPCASE",1322) &&
                     output != ECL_SYM(":DOWNCASE",1223) &&
                     output != ECL_SYM(":CAPITALIZE",1203))
        {
		ECL_SETQ(ecl_process_env(), ECL_SYM("*PRINT-CASE*",46), ECL_SYM(":DOWNCASE",1223));
		FEerror("The value of *PRINT-CASE*~%  ~S~%"
                        "is not of the expected type "
                        "(MEMBER :UPCASE :DOWNCASE :CAPITALIZE)", 1, output);
	}
	return output;
}

bool
ecl_print_gensym(void)
{
	return ecl_symbol_value(ECL_SYM("*PRINT-GENSYM*",49)) != ECL_NIL;
}

bool
ecl_print_array(void)
{
	return ecl_symbol_value(ECL_SYM("*PRINT-ARRAY*",44)) != ECL_NIL;
}

bool
ecl_print_readably(void)
{
	return ecl_symbol_value(ECL_SYM("*PRINT-READABLY*",57)) != ECL_NIL;
}

bool
ecl_print_escape(void)
{
	return ecl_symbol_value(ECL_SYM("*PRINT-ESCAPE*",48)) != ECL_NIL;
}

bool
ecl_print_circle(void)
{
	return ecl_symbol_value(ECL_SYM("*PRINT-CIRCLE*",47)) != ECL_NIL;
}

#line 158
cl_object cl_write(cl_narg narg, cl_object x, ...)
{
#line 158

#line 159
	const cl_env_ptr the_env = ecl_process_env();
#line 159
	static cl_object KEYS[16] = {(cl_object)(cl_symbols+1313), (cl_object)(cl_symbols+1199), (cl_object)(cl_symbols+1201), (cl_object)(cl_symbols+1205), (cl_object)(cl_symbols+1206), (cl_object)(cl_symbols+1230), (cl_object)(cl_symbols+1242), (cl_object)(cl_symbols+1263), (cl_object)(cl_symbols+1264), (cl_object)(cl_symbols+1265), (cl_object)(cl_symbols+1272), (cl_object)(cl_symbols+1286), (cl_object)(cl_symbols+1289), (cl_object)(cl_symbols+1295), (cl_object)(cl_symbols+1296), (cl_object)(cl_symbols+1303)};
	cl_object strm;
	cl_object array;
	cl_object base;
	cl_object cas;
	cl_object circle;
	cl_object escape;
	cl_object gensym;
	cl_object length;
	cl_object level;
	cl_object lines;
	cl_object miser_width;
	cl_object pprint_dispatch;
	cl_object pretty;
	cl_object radix;
	cl_object readably;
	cl_object right_margin;
#line 159
	cl_object KEY_VARS[32];
#line 159
	ecl_va_list ARGS;
	ecl_va_start(ARGS, x, narg, 1);
#line 159
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(917));
#line 159
	cl_parse_key(ARGS, 16, KEYS, KEY_VARS, NULL, 0);
#line 159
	if (KEY_VARS[16]==ECL_NIL) {
#line 159
	  strm = ECL_NIL;
	} else {
#line 159
	  strm = KEY_VARS[0];
	}
#line 159
	if (KEY_VARS[17]==ECL_NIL) {
#line 159
	  array = ecl_symbol_value(ECL_SYM("*PRINT-ARRAY*",44));
	} else {
#line 159
	  array = KEY_VARS[1];
	}
#line 159
	if (KEY_VARS[18]==ECL_NIL) {
#line 159
	  base = ecl_symbol_value(ECL_SYM("*PRINT-BASE*",45));
	} else {
#line 159
	  base = KEY_VARS[2];
	}
#line 159
	if (KEY_VARS[19]==ECL_NIL) {
#line 159
	  cas = ecl_symbol_value(ECL_SYM("*PRINT-CASE*",46));
	} else {
#line 159
	  cas = KEY_VARS[3];
	}
#line 159
	if (KEY_VARS[20]==ECL_NIL) {
#line 159
	  circle = ecl_symbol_value(ECL_SYM("*PRINT-CIRCLE*",47));
	} else {
#line 159
	  circle = KEY_VARS[4];
	}
#line 159
	if (KEY_VARS[21]==ECL_NIL) {
#line 159
	  escape = ecl_symbol_value(ECL_SYM("*PRINT-ESCAPE*",48));
	} else {
#line 159
	  escape = KEY_VARS[5];
	}
#line 159
	if (KEY_VARS[22]==ECL_NIL) {
#line 159
	  gensym = ecl_symbol_value(ECL_SYM("*PRINT-GENSYM*",49));
	} else {
#line 159
	  gensym = KEY_VARS[6];
	}
#line 159
	if (KEY_VARS[23]==ECL_NIL) {
#line 159
	  length = ecl_symbol_value(ECL_SYM("*PRINT-LENGTH*",50));
	} else {
#line 159
	  length = KEY_VARS[7];
	}
#line 159
	if (KEY_VARS[24]==ECL_NIL) {
#line 159
	  level = ecl_symbol_value(ECL_SYM("*PRINT-LEVEL*",51));
	} else {
#line 159
	  level = KEY_VARS[8];
	}
#line 159
	if (KEY_VARS[25]==ECL_NIL) {
#line 159
	  lines = ecl_symbol_value(ECL_SYM("*PRINT-LINES*",52));
	} else {
#line 159
	  lines = KEY_VARS[9];
	}
#line 159
	if (KEY_VARS[26]==ECL_NIL) {
#line 159
	  miser_width = ecl_symbol_value(ECL_SYM("*PRINT-MISER-WIDTH*",53));
	} else {
#line 159
	  miser_width = KEY_VARS[10];
	}
#line 159
	if (KEY_VARS[27]==ECL_NIL) {
#line 159
	  pprint_dispatch = ecl_symbol_value(ECL_SYM("*PRINT-PPRINT-DISPATCH*",54));
	} else {
#line 159
	  pprint_dispatch = KEY_VARS[11];
	}
#line 159
	if (KEY_VARS[28]==ECL_NIL) {
#line 159
	  pretty = ecl_symbol_value(ECL_SYM("*PRINT-PRETTY*",55));
	} else {
#line 159
	  pretty = KEY_VARS[12];
	}
#line 159
	if (KEY_VARS[29]==ECL_NIL) {
#line 159
	  radix = ecl_symbol_value(ECL_SYM("*PRINT-RADIX*",56));
	} else {
#line 159
	  radix = KEY_VARS[13];
	}
#line 159
	if (KEY_VARS[30]==ECL_NIL) {
#line 159
	  readably = ecl_symbol_value(ECL_SYM("*PRINT-READABLY*",57));
	} else {
#line 159
	  readably = KEY_VARS[14];
	}
#line 159
	if (KEY_VARS[31]==ECL_NIL) {
#line 159
	  right_margin = ecl_symbol_value(ECL_SYM("*PRINT-RIGHT-MARGIN*",58));
	} else {
#line 159
	  right_margin = KEY_VARS[15];
	}
#line 159

	ecl_bds_bind(the_env, ECL_SYM("*PRINT-ARRAY*",44), array);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-BASE*",45), base);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-CASE*",46), cas);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-CIRCLE*",47), circle);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-ESCAPE*",48), escape);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-GENSYM*",49), gensym);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-LEVEL*",51), level);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-LENGTH*",50), length);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-LINES*",52), lines);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-MISER-WIDTH*",53), miser_width);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-PPRINT-DISPATCH*",54), pprint_dispatch);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-PRETTY*",55), pretty);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-RADIX*",56), radix);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-READABLY*",57), readably);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-RIGHT-MARGIN*",58), right_margin);

	strm = _ecl_stream_or_default_output(strm);
	si_write_object(x, strm);
	ecl_force_output(strm);

	ecl_bds_unwind_n(the_env, 15);
	{
#line 181
		#line 181
		cl_object __value0 = x;
#line 181
		the_env->nvalues = 1;
#line 181
		return __value0;
#line 181
	}

}

#line 184
cl_object cl_prin1(cl_narg narg, cl_object obj, ...)
{
#line 184

#line 186
	const cl_env_ptr the_env = ecl_process_env();
#line 186
	cl_object strm;
#line 186
	va_list ARGS;
	va_start(ARGS, obj);
#line 186
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(658));
#line 186
	if (narg > 1) {
#line 186
		strm = va_arg(ARGS,cl_object);
#line 186
	} else {
#line 186
		strm = ECL_NIL;
#line 186
	}
#line 186
	ecl_prin1(obj, strm);
	{
#line 187
		#line 187
		cl_object __value0 = obj;
#line 187
		the_env->nvalues = 1;
#line 187
		return __value0;
#line 187
	}

}

#line 190
cl_object cl_print(cl_narg narg, cl_object obj, ...)
{
#line 190

#line 192
	const cl_env_ptr the_env = ecl_process_env();
#line 192
	cl_object strm;
#line 192
	va_list ARGS;
	va_start(ARGS, obj);
#line 192
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(662));
#line 192
	if (narg > 1) {
#line 192
		strm = va_arg(ARGS,cl_object);
#line 192
	} else {
#line 192
		strm = ECL_NIL;
#line 192
	}
#line 192
	ecl_print(obj, strm);
	{
#line 193
		#line 193
		cl_object __value0 = obj;
#line 193
		the_env->nvalues = 1;
#line 193
		return __value0;
#line 193
	}

}

#line 196
cl_object cl_pprint(cl_narg narg, cl_object obj, ...)
{
#line 196

#line 198
	const cl_env_ptr the_env = ecl_process_env();
#line 198
	cl_object strm;
#line 198
	va_list ARGS;
	va_start(ARGS, obj);
#line 198
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(647));
#line 198
	if (narg > 1) {
#line 198
		strm = va_arg(ARGS,cl_object);
#line 198
	} else {
#line 198
		strm = ECL_NIL;
#line 198
	}
#line 198
	strm = _ecl_stream_or_default_output(strm);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-ESCAPE*",48), ECL_T);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-PRETTY*",55), ECL_T);
	ecl_write_char('\n', strm);
	si_write_object(obj, strm);
	ecl_force_output(strm);
	ecl_bds_unwind_n(the_env, 2);
	{
the_env->nvalues = 0; return ECL_NIL;
#line 205
	}

}

#line 208
cl_object cl_princ(cl_narg narg, cl_object obj, ...)
{
#line 208

#line 210
	const cl_env_ptr the_env = ecl_process_env();
#line 210
	cl_object strm;
#line 210
	va_list ARGS;
	va_start(ARGS, obj);
#line 210
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(660));
#line 210
	if (narg > 1) {
#line 210
		strm = va_arg(ARGS,cl_object);
#line 210
	} else {
#line 210
		strm = ECL_NIL;
#line 210
	}
#line 210
	ecl_princ(obj, strm);
	{
#line 211
		#line 211
		cl_object __value0 = obj;
#line 211
		the_env->nvalues = 1;
#line 211
		return __value0;
#line 211
	}

}

#line 214
cl_object cl_write_char(cl_narg narg, cl_object c, ...)
{
#line 214

#line 216
	const cl_env_ptr the_env = ecl_process_env();
#line 216
	cl_object strm;
#line 216
	va_list ARGS;
	va_start(ARGS, c);
#line 216
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(919));
#line 216
	if (narg > 1) {
#line 216
		strm = va_arg(ARGS,cl_object);
#line 216
	} else {
#line 216
		strm = ECL_NIL;
#line 216
	}
#line 216
	/* INV: ecl_char_code() checks the type of `c' */
 	strm = _ecl_stream_or_default_output(strm);
	c = ECL_CODE_CHAR(ecl_write_char(ecl_char_code(c), strm));
	{
#line 219
		#line 219
		cl_object __value0 = c;
#line 219
		the_env->nvalues = 1;
#line 219
		return __value0;
#line 219
	}

}

#line 222
cl_object cl_write_string(cl_narg narg, cl_object strng, ...)
{
#line 222

#line 224
	const cl_env_ptr the_env = ecl_process_env();
#line 224
	cl_object strm;
#line 224
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1310), (cl_object)(cl_symbols+1225)};
	cl_object start;
	cl_object end;
#line 224
	cl_object KEY_VARS[4];
#line 224
	ecl_va_list ARGS;
	ecl_va_start(ARGS, strng, narg, 1);
#line 224
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(922));
#line 224
	if (narg > 1) {
#line 224
		strm = ecl_va_arg(ARGS);
#line 224
	} else {
#line 224
		strm = ECL_NIL;
#line 224
	}
#line 224
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 224
	if (KEY_VARS[2]==ECL_NIL) {
#line 224
	  start = ecl_make_fixnum(0);
	} else {
#line 224
	  start = KEY_VARS[0];
	}
#line 224
	if (KEY_VARS[3]==ECL_NIL) {
#line 224
	  end = ECL_NIL;
	} else {
#line 224
	  end = KEY_VARS[1];
	}
#line 224
        unlikely_if (!ECL_STRINGP(strng))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*WRITE-STRING*/922), 1, strng, ecl_make_fixnum(/*STRING*/805));
	strm = _ecl_stream_or_default_output(strm);
#ifdef ECL_CLOS_STREAMS
        if (!ECL_ANSI_STREAM_P(strm))
		_ecl_funcall5(ECL_SYM("GRAY::STREAM-WRITE-STRING",1647), strm, strng, start, end);
	else
#endif
		si_do_write_sequence(strng, strm, start, end);
	{
#line 233
		#line 233
		cl_object __value0 = strng;
#line 233
		the_env->nvalues = 1;
#line 233
		return __value0;
#line 233
	}

}

#line 236
cl_object cl_write_line(cl_narg narg, cl_object strng, ...)
{
#line 236

#line 238
	const cl_env_ptr the_env = ecl_process_env();
#line 238
	cl_object strm;
#line 238
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1310), (cl_object)(cl_symbols+1225)};
	cl_object start;
	cl_object end;
#line 238
	cl_object KEY_VARS[4];
#line 238
	ecl_va_list ARGS;
	ecl_va_start(ARGS, strng, narg, 1);
#line 238
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(920));
#line 238
	if (narg > 1) {
#line 238
		strm = ecl_va_arg(ARGS);
#line 238
	} else {
#line 238
		strm = ECL_NIL;
#line 238
	}
#line 238
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 238
	if (KEY_VARS[2]==ECL_NIL) {
#line 238
	  start = ecl_make_fixnum(0);
	} else {
#line 238
	  start = KEY_VARS[0];
	}
#line 238
	if (KEY_VARS[3]==ECL_NIL) {
#line 238
	  end = ECL_NIL;
	} else {
#line 238
	  end = KEY_VARS[1];
	}
#line 238
        unlikely_if (!ECL_STRINGP(strng))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*WRITE-LINE*/920), 1, strng, ecl_make_fixnum(/*STRING*/805));
	strm = _ecl_stream_or_default_output(strm);
#ifdef ECL_CLOS_STREAMS
	if (!ECL_ANSI_STREAM_P(strm))
		_ecl_funcall5(ECL_SYM("GRAY::STREAM-WRITE-STRING",1647), strm, strng,
			      start, end);
	else
#endif
		si_do_write_sequence(strng, strm, start, end);
	ecl_terpri(strm);
	{
#line 249
		#line 249
		cl_object __value0 = strng;
#line 249
		the_env->nvalues = 1;
#line 249
		return __value0;
#line 249
	}

}

#line 252
cl_object cl_terpri(cl_narg narg, ...)
{
#line 252

#line 254
	const cl_env_ptr the_env = ecl_process_env();
#line 254
	cl_object strm;
#line 254
	va_list ARGS;
	va_start(ARGS, narg);
#line 254
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(855));
#line 254
	if (narg > 0) {
#line 254
		strm = va_arg(ARGS,cl_object);
#line 254
	} else {
#line 254
		strm = ECL_NIL;
#line 254
	}
#line 254
	ecl_terpri(strm);
	{
#line 255
		#line 255
		cl_object __value0 = ECL_NIL;
#line 255
		the_env->nvalues = 1;
#line 255
		return __value0;
#line 255
	}

}

#line 258
cl_object cl_fresh_line(cl_narg narg, ...)
{
#line 258

#line 260
	const cl_env_ptr the_env = ecl_process_env();
#line 260
	cl_object strm;
#line 260
	va_list ARGS;
	va_start(ARGS, narg);
#line 260
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(390));
#line 260
	if (narg > 0) {
#line 260
		strm = va_arg(ARGS,cl_object);
#line 260
	} else {
#line 260
		strm = ECL_NIL;
#line 260
	}
#line 260
 	strm = _ecl_stream_or_default_output(strm);
#ifdef ECL_CLOS_STREAMS
	if (!ECL_ANSI_STREAM_P(strm)) {
		return _ecl_funcall2(ECL_SYM("GRAY::STREAM-FRESH-LINE",1631), strm);
	}
#endif
	if (ecl_file_column(strm) == 0)
		{
#line 267
			#line 267
			cl_object __value0 = ECL_NIL;
#line 267
			the_env->nvalues = 1;
#line 267
			return __value0;
#line 267
		}

	ecl_write_char('\n', strm);
	ecl_force_output(strm);
	{
#line 270
		#line 270
		cl_object __value0 = ECL_T;
#line 270
		the_env->nvalues = 1;
#line 270
		return __value0;
#line 270
	}

}

#line 273
cl_object cl_finish_output(cl_narg narg, ...)
{
#line 273

#line 275
	const cl_env_ptr the_env = ecl_process_env();
#line 275
	cl_object strm;
#line 275
	va_list ARGS;
	va_start(ARGS, narg);
#line 275
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(370));
#line 275
	if (narg > 0) {
#line 275
		strm = va_arg(ARGS,cl_object);
#line 275
	} else {
#line 275
		strm = ECL_NIL;
#line 275
	}
#line 275
 	strm = _ecl_stream_or_default_output(strm);
#ifdef ECL_CLOS_STREAMS
        if (!ECL_ANSI_STREAM_P(strm)) {
		return _ecl_funcall2(ECL_SYM("GRAY::STREAM-FINISH-OUTPUT",1629), strm);
	}
#endif
	ecl_force_output(strm);
	{
#line 282
		#line 282
		cl_object __value0 = ECL_NIL;
#line 282
		the_env->nvalues = 1;
#line 282
		return __value0;
#line 282
	}

}

#line 285
cl_object cl_force_output(cl_narg narg, ...)
{
#line 285

#line 287
	const cl_env_ptr the_env = ecl_process_env();
#line 287
	cl_object strm;
#line 287
	va_list ARGS;
	va_start(ARGS, narg);
#line 287
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(386));
#line 287
	if (narg > 0) {
#line 287
		strm = va_arg(ARGS,cl_object);
#line 287
	} else {
#line 287
		strm = ECL_NIL;
#line 287
	}
#line 287
 	strm = _ecl_stream_or_default_output(strm);
	ecl_force_output(strm);
	{
#line 289
		#line 289
		cl_object __value0 = ECL_NIL;
#line 289
		the_env->nvalues = 1;
#line 289
		return __value0;
#line 289
	}

}

#line 292
cl_object cl_clear_output(cl_narg narg, ...)
{
#line 292

#line 294
	const cl_env_ptr the_env = ecl_process_env();
#line 294
	cl_object strm;
#line 294
	va_list ARGS;
	va_start(ARGS, narg);
#line 294
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(227));
#line 294
	if (narg > 0) {
#line 294
		strm = va_arg(ARGS,cl_object);
#line 294
	} else {
#line 294
		strm = ECL_NIL;
#line 294
	}
#line 294
 	strm = _ecl_stream_or_default_output(strm);
	ecl_clear_output(strm);
	{
#line 296
		#line 296
		cl_object __value0 = ECL_NIL;
#line 296
		the_env->nvalues = 1;
#line 296
		return __value0;
#line 296
	}

}

cl_object
cl_write_byte(cl_object integer, cl_object binary_output_stream)
{
	ecl_write_byte(integer, binary_output_stream);
	{
#line 303
		const cl_env_ptr the_env = ecl_process_env();
#line 303
		#line 303
		cl_object __value0 = integer;
#line 303
		the_env->nvalues = 1;
#line 303
		return __value0;
#line 303
	}

}

#line 306
cl_object cl_write_sequence(cl_narg narg, cl_object sequence, cl_object stream, ...)
{
#line 306

#line 308
	const cl_env_ptr the_env = ecl_process_env();
#line 308
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1310), (cl_object)(cl_symbols+1225)};
	cl_object start;
	cl_object end;
#line 308
	cl_object KEY_VARS[4];
#line 308
	ecl_va_list ARGS;
	ecl_va_start(ARGS, stream, narg, 2);
#line 308
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(921));
#line 308
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 308
	if (KEY_VARS[2]==ECL_NIL) {
#line 308
	  start = ecl_make_fixnum(0);
	} else {
#line 308
	  start = KEY_VARS[0];
	}
#line 308
	if (KEY_VARS[3]==ECL_NIL) {
#line 308
	  end = ECL_NIL;
	} else {
#line 308
	  end = KEY_VARS[1];
	}
#line 308
#ifdef ECL_CLOS_STREAMS
	if (!ECL_ANSI_STREAM_P(stream)) {
		return _ecl_funcall5(ECL_SYM("GRAY::STREAM-WRITE-SEQUENCE",1646),
				     stream, sequence, start, end);
	} else
#endif
		return si_do_write_sequence(sequence, stream, start, end);
}

cl_object
ecl_princ(cl_object obj, cl_object strm)
{
	const cl_env_ptr the_env = ecl_process_env();
	strm = _ecl_stream_or_default_output(strm);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-ESCAPE*",48), ECL_NIL);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-READABLY*",57), ECL_NIL);
	si_write_object(obj, strm);
	ecl_bds_unwind_n(the_env, 2);
	return obj;
}

cl_object
ecl_prin1(cl_object obj, cl_object strm)
{
	const cl_env_ptr the_env = ecl_process_env();
	strm = _ecl_stream_or_default_output(strm);
	ecl_bds_bind(the_env, ECL_SYM("*PRINT-ESCAPE*",48), ECL_T);
	si_write_object(obj, strm);
	ecl_force_output(strm);
	ecl_bds_unwind1(the_env);
	return obj;
}

cl_object
ecl_print(cl_object obj, cl_object strm)
{
	strm = _ecl_stream_or_default_output(strm);
	ecl_terpri(strm);
	ecl_prin1(obj, strm);
	ecl_princ_char(' ', strm);
	return obj;
}

cl_object
ecl_terpri(cl_object strm)
{
	strm = _ecl_stream_or_default_output(strm);
#ifdef ECL_CLOS_STREAMS
	if (!ECL_ANSI_STREAM_P(strm)) {
		return _ecl_funcall2(ECL_SYM("GRAY::STREAM-TERPRI",1642), strm);
	}
#endif
	ecl_write_char('\n', strm);
	ecl_force_output(strm);
	return(ECL_NIL);
}

void
ecl_write_string(cl_object strng, cl_object strm)
{
	cl_index i;

	strm = _ecl_stream_or_default_output(strm);
	switch(ecl_t_of(strng)) {
#ifdef ECL_UNICODE
	case t_string:
		for (i = 0;  i < strng->string.fillp;  i++)
			ecl_write_char(strng->string.self[i], strm);
		break;
#endif
	case t_base_string:
		for (i = 0;  i < strng->base_string.fillp;  i++)
			ecl_write_char(strng->base_string.self[i], strm);
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*WRITE-STRING*/922), 1, strng, ecl_make_fixnum(/*STRING*/805));
	}
		
	ecl_force_output(strm);
}

/*
	THE ULTRA-SPECIAL-DINNER-SERVICE OPTIMIZATION
*/
void
ecl_princ_str(const char *s, cl_object strm)
{
	strm = _ecl_stream_or_default_output(strm);
	writestr_stream(s, strm);
}

int
ecl_princ_char(int c, cl_object strm)
{
	strm = _ecl_stream_or_default_output(strm);
	ecl_write_char(c, strm);
	if (c == '\n') {
		ecl_force_output(strm);
	}
        return c;
}
