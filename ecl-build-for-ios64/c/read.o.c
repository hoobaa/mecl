#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/read.d"
/* -*- mode: c; c-basic-offset: 4 -*- */
/*
  read.d -- Read.
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

#define ECL_INCLUDE_MATH_H
#include <ecl/ecl.h>
#include <ecl/number.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include <ecl/internal.h>
#include <ecl/ecl-inl.h>
#include <ecl/bytecodes.h>

#undef _complex

static cl_object dispatch_macro_character(cl_object table, cl_object strm, int c);

#define read_suppress (ecl_symbol_value(ECL_SYM("*READ-SUPPRESS*",64)) != ECL_NIL)

#ifdef ECL_UNICODE
# define TOKEN_STRING_DIM(s) ((s)->string.dim)
# define TOKEN_STRING_FILLP(s) ((s)->string.fillp)
# define TOKEN_STRING_CHAR(s,n) ((s)->string.self[n])
# define TOKEN_STRING_CHAR_SET(s,n,c) (s)->string.self[n]=(c)
# define TOKEN_STRING_CHAR_CMP(s,n,c) ((s)->string.self[n]==(c))
#else
# define TOKEN_STRING_DIM(s) ((s)->base_string.dim)
# define TOKEN_STRING_FILLP(s) ((s)->base_string.fillp)
# define TOKEN_STRING_CHAR(s,n) ((s)->base_string.self[n])
# define TOKEN_STRING_CHAR_SET(s,n,c) ((s)->base_string.self[n]=(c))
# define TOKEN_STRING_CHAR_CMP(s,n,c) ((s)->base_string.self[n]==(c))
#endif

#define ECL_READ_ONLY_TOKEN 1
#define ECL_READ_RETURN_IGNORABLE 3
#define ECL_READ_LIST_DOT 4

cl_object
si_get_buffer_string()
{
        const cl_env_ptr env = ecl_process_env();
        cl_object pool = env->string_pool;
        cl_object output;
        if (pool == ECL_NIL) {
#ifdef ECL_UNICODE
                output = ecl_alloc_adjustable_extended_string(ECL_BUFFER_STRING_SIZE);
#else
                output = ecl_alloc_adjustable_base_string(ECL_BUFFER_STRING_SIZE);
#endif
        } else {
                output = CAR(pool);
                env->string_pool = CDR(pool);
        }
        TOKEN_STRING_FILLP(output) = 0;
        {
#line 71
	const cl_env_ptr the_env = ecl_process_env();
#line 71
	#line 71
	cl_object __value0 = output;
#line 71
	the_env->nvalues = 1;
#line 71
	return __value0;
#line 71
}

                }

cl_object
si_put_buffer_string(cl_object string)
{
        if (string != ECL_NIL) {
                const cl_env_ptr env = ecl_process_env();
                cl_object pool = env->string_pool;
                cl_index l = 0;
                if (pool != ECL_NIL) {
                        /* We store the size of the pool in the string index */
                        l = TOKEN_STRING_FILLP(ECL_CONS_CAR(pool));
                }
                if (l < ECL_MAX_STRING_POOL_SIZE) {
                        /* Ok, by ignoring the following code, here we
                         * are doing like SBCL: we simply grow the
                         * input buffer and do not care about its
                         * size. */
#if 0
                        if (TOKEN_STRING_DIM(string) > 32*ECL_BUFFER_STRING_SIZE) {
                                /* String has been enlarged. Cut it. */
#ifdef ECL_UNICODE
                                string = ecl_alloc_adjustable_extended_string(ECL_BUFFER_STRING_SIZE);
#else
                                string = ecl_alloc_adjustable_base_string(ECL_BUFFER_STRING_SIZE);
#endif
                        }
#endif
                        TOKEN_STRING_FILLP(string) = l+1;
                        env->string_pool = CONS(string, pool);
                }
        }
        {
#line 104
	const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 104
}

                }

static void extra_argument (int c, cl_object stream, cl_object d);
static cl_object patch_sharp(cl_object x);
static cl_object do_read_delimited_list(int d, cl_object strm, bool proper_list);

cl_object
ecl_read_object_non_recursive(cl_object in)
{
        cl_object x;
        const cl_env_ptr env = ecl_process_env();
        
        ecl_bds_bind(env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031), ECL_NIL);
        ecl_bds_bind(env, ECL_SYM("SI::*BACKQ-LEVEL*",1012), ecl_make_fixnum(0));
        
        nlogd(">>ecl-read-object-non-recursive from. ansi_stream_p(%d)", ECL_ANSI_STREAM_P(in));
        x = ecl_read_object(in);
        nlogd(">>ecl-read-object-non-recursive to");
        if (!Null(ECL_SYM_VAL(env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031))))
                x = patch_sharp(x);
        ecl_bds_unwind_n(env, 2);
        return x;
}

/*
 * This routine inverts the case of the characters in the buffer which
 * were not escaped. ESCAPE_LIST is a list of intevals of characters
 * that were escaped, as in ({(low-limit . high-limit)}*). The list
 * goes from the last interval to the first one, in reverse order,
 * and thus we run the buffer from the end to the beginning.
 */
static void
invert_buffer_case(cl_object x, cl_object escape_list, int sign)
{
        cl_fixnum high_limit, low_limit;
        cl_fixnum i = TOKEN_STRING_FILLP(x);
        do {
                if (escape_list != ECL_NIL) {
                        cl_object escape_interval = CAR(escape_list);
                        high_limit = ecl_fixnum(CAR(escape_interval));
                        low_limit = ecl_fixnum(CDR(escape_interval));
                        escape_list = CDR(escape_list);
                } else {
                        high_limit = low_limit = -1;
                }
                for (; i > high_limit; i--) {
                        /* The character is not escaped */
                        int c = TOKEN_STRING_CHAR(x,i);
                        if (ecl_upper_case_p(c) && (sign < 0)) {
                                c = ecl_char_downcase(c);
                        } else if (ecl_lower_case_p(c) && (sign > 0)) {
                                c = ecl_char_upcase(c);
                        }
                        TOKEN_STRING_CHAR_SET(x,i,c);
                }
                for (; i > low_limit; i--) {
                        /* The character is within an escaped interval */
                        ;
                }
        } while (i >= 0);
}

static cl_object
ecl_read_object_with_delimiter(cl_object in, int delimiter, int flags,
                               enum ecl_chattrib a)
{
        nlogd(">>ecl-read-object-with-delimiter");
        
        cl_object x, token;
        int c, base;
        cl_object p;
        cl_index length, i;
        int colon, intern_flag;
        bool external_symbol;
        cl_env_ptr the_env = ecl_process_env();
        cl_object rtbl = ecl_current_readtable();
        enum ecl_readtable_case read_case = rtbl->readtable.read_case;
        cl_object escape_list; /* intervals of escaped characters */
        cl_fixnum upcase; /* # uppercase characters - # downcase characters */
        cl_fixnum count; /* number of unescaped characters */
        bool suppress = read_suppress;
        if (a != cat_constituent) {
                c = 0;
                nlogd(">>");
                goto LOOP;
        }
 BEGIN:
        do {
                nlogd("ecl_read_objectwith_delimiter ansi_stream_p(%d)", ECL_ANSI_STREAM_P(in));
                c = ecl_read_char(in);
                nlogd(">>1.1");
                if (c == delimiter) {
                        nlogd(">>2");
                        the_env->nvalues = 0;
                        return OBJNULL;
                }
                if (c == EOF) {
                        nlogd(">>3");
                        FEend_of_file(in);
                }
                a = ecl_readtable_get(rtbl, c, &x);
                nlogd("cat(%d)", a);
        } while (a == cat_whitespace);
        
        nlogd("break");
        
        if ((a == cat_terminating || a == cat_non_terminating) &&
            (flags != ECL_READ_ONLY_TOKEN)) {
                cl_object o;
                if (ECL_HASH_TABLE_P(x)) {
                        o = dispatch_macro_character(x, in, c);
                } else {
                        o = _ecl_funcall3(x, in, ECL_CODE_CHAR(c));
                }
                if (the_env->nvalues == 0) {
                        if (flags == ECL_READ_RETURN_IGNORABLE) {
                                return ECL_NIL;
                        }
                        nlogd("goto begin");
                        goto BEGIN;
                }
                unlikely_if (the_env->nvalues > 1) {
                        FEerror("The readmacro ~S returned ~D values.", 2, x, ecl_make_fixnum(the_env->nvalues));
                }
                nlogd(">>return");
                return o;
        }
        nlogd("start loop");
        
 LOOP:
        p = escape_list = ECL_NIL;
        upcase = count = length = 0;
        external_symbol = colon = 0;
        token = si_get_buffer_string();
        for (;;) {
                nlogd(">>");
                if (c == ':' && (flags != ECL_READ_ONLY_TOKEN) &&
                    a == cat_constituent) {
                        colon++;
                        goto NEXT;
                }
                if (colon > 2) {
                        while (colon--) {
                                ecl_string_push_extend(token, ':');
                                length++;
                        }
                } else if (colon) {
                        external_symbol = (colon == 1);
                        TOKEN_STRING_CHAR_SET(token,length,'\0');
                        /* If the readtable case was :INVERT and all non-escaped characters
                         * had the same case, we revert their case. */
                        if (read_case == ecl_case_invert) {
                                if (upcase == count) {
                                        invert_buffer_case(token, escape_list, -1);
                                } else if (upcase == -count) {
                                        invert_buffer_case(token, escape_list, +1);
                                }
                        }
                        if (length == 0) {
                                p = cl_core.keyword_package;
                                external_symbol = 0;
                        } else {
                                p = ecl_find_package_nolock(token);
                        }
                        if (Null(p) && !suppress) {
                                /* When loading binary files, we sometimes must create
                                   symbols whose package has not yet been maked. We
                                   allow it, but later on in ecl_init_module we make sure that
                                   all referenced packages have been properly built.
                                */
                                cl_object name = cl_copy_seq(token);
                                unlikely_if (Null(the_env->packages_to_be_created_p)) {
                                        FEerror("There is no package with the name ~A.",
                                                1, name);
                                }
                                p = _ecl_package_to_be_created(the_env, name);
                        }
                        TOKEN_STRING_FILLP(token) = length = 0;
                        upcase = count = colon = 0;
                        escape_list = ECL_NIL;
                }
                if (a == cat_single_escape) {
                        c = ecl_read_char_noeof(in);
                        a = cat_constituent;
                        if (read_case == ecl_case_invert) {
                                escape_list = CONS(CONS(ecl_make_fixnum(length),
                                                        ecl_make_fixnum(length)),
                                                   escape_list);
                        } else {
                                escape_list = ECL_T;
                        }
                        ecl_string_push_extend(token, c);
                        length++;
                        goto NEXT;
                }
                if (a == cat_multiple_escape) {
                        cl_index begin = length;
                        for (;;) {
                                c = ecl_read_char_noeof(in);
                                a = ecl_readtable_get(rtbl, c, NULL);
                                if (a == cat_single_escape) {
                                        c = ecl_read_char_noeof(in);
                                        a = cat_constituent;
                                } else if (a == cat_multiple_escape)
                                        break;
                                ecl_string_push_extend(token, c);
                                length++;
                        }
                        if (read_case == ecl_case_invert) {
                                escape_list = CONS(CONS(ecl_make_fixnum(begin),
                                                        ecl_make_fixnum(length-1)),
                                                   escape_list);
                        } else {
                                escape_list = ECL_T;
                        }
                        goto NEXT;
                }
                if (a == cat_whitespace || a == cat_terminating) {
                        ecl_unread_char(c, in);
                        break;
                }
                unlikely_if (ecl_invalid_character_p(c)) {
                        FEreader_error("Found invalid character ~:C", in,
                                       1, ECL_CODE_CHAR(c));
                }
                if (read_case != ecl_case_preserve) {
                        if (ecl_upper_case_p(c)) {
                                upcase++;
                                count++;
                                if (read_case == ecl_case_downcase)
                                        c = ecl_char_downcase(c);
                        } else if (ecl_lower_case_p(c)) {
                                upcase--;
                                count++;
                                if (read_case == ecl_case_upcase)
                                        c = ecl_char_upcase(c);
                        }
                }
                ecl_string_push_extend(token, c);
                length++;
        NEXT:
                c = ecl_read_char(in);
                if (c == EOF)
                        break;
                a = ecl_readtable_get(rtbl, c, NULL);
        }
        
        if (suppress) {
                x = ECL_NIL;
                goto OUTPUT;
        }
        
        /* If there are some escaped characters, it must be a symbol */
        if ((flags == ECL_READ_ONLY_TOKEN) || p != ECL_NIL ||
            escape_list != ECL_NIL || length == 0)
                goto SYMBOL;
        
        /* The case in which the buffer is full of dots has to be especial cased */
        if (length == 1 && TOKEN_STRING_CHAR_CMP(token,0,'.')) {
                if (flags == ECL_READ_LIST_DOT) {
                        x = ECL_SYM("SI::.",1034);
                        goto OUTPUT;
                } else {
                        FEreader_error("Dots appeared illegally.", in, 0);
                }
        } else {
                int i;
                for (i = 0;  i < length;  i++) {
                        if (!TOKEN_STRING_CHAR_CMP(token,i,'.'))
                                goto MAYBE_NUMBER;
                }
                FEreader_error("Dots appeared illegally.", in, 0);
        }
        
 MAYBE_NUMBER:
        /* Here we try to parse a number from the content of the buffer */
        base = ecl_current_read_base();
        if ((base <= 10) && ecl_alpha_char_p(TOKEN_STRING_CHAR(token,0)))
                goto SYMBOL;
        x = ecl_parse_number(token, 0, TOKEN_STRING_FILLP(token), &i, base);
        unlikely_if (x == ECL_NIL)
                FEreader_error("Syntax error when reading number.~%Offending string: ~S.",
                               in, 1, token);
        if (x != OBJNULL && length == i)
                goto OUTPUT;
 SYMBOL:
        /*TOKEN_STRING_CHAR_SET(token,length,'\0');*/
        /* If the readtable case was :INVERT and all non-escaped characters
         * had the same case, we revert their case. */
        if (read_case == ecl_case_invert) {
                if (upcase == count) {
                        invert_buffer_case(token, escape_list, -1);
                } else if (upcase == -count) {
                        invert_buffer_case(token, escape_list, +1);
                }
        }
        if (flags == ECL_READ_ONLY_TOKEN) {
                the_env->nvalues = 1;
                return token;
        } else if (external_symbol) {
                x = ecl_find_symbol(token, p, &intern_flag);
                unlikely_if (intern_flag != ECL_EXTERNAL) {
                        FEerror("Cannot find the external symbol ~A in ~S.",
                                2, cl_copy_seq(token), p);
                }
        } else {
                if (p == ECL_NIL) {
                        p = ecl_current_package();
                }
                /* INV: cl_make_symbol() copies the string */
                x = ecl_intern(token, p, &intern_flag);
        }
 OUTPUT:
        si_put_buffer_string(token);
        the_env->nvalues = 1;
        return x;
}

/*
  ecl_read_object(in) reads an object from stream in.
  This routine corresponds to COMMON Lisp function READ.
*/
cl_object
ecl_read_object(cl_object in)
{
        return ecl_read_object_with_delimiter(in, EOF, 0, cat_constituent);
}

cl_object
si_read_object_or_ignore(cl_object in, cl_object eof)
{
        cl_object x;
        const cl_env_ptr env = ecl_process_env();
        
        ecl_bds_bind(env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031), ECL_NIL);
        ecl_bds_bind(env, ECL_SYM("SI::*BACKQ-LEVEL*",1012), ecl_make_fixnum(0));
        x = ecl_read_object_with_delimiter(in, EOF, ECL_READ_RETURN_IGNORABLE, 
                                           cat_constituent);
        if (x == OBJNULL) {
                env->nvalues = 1;
                x = eof;
        } else if (env->nvalues) {
                if (!Null(ECL_SYM_VAL(env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031))))
                        x = patch_sharp(x);
        }
        ecl_bds_unwind_n(env, 2);
        return x;
}

static cl_object
right_parenthesis_reader(cl_object in, cl_object character)
{
        FEreader_error("Unmatched right parenthesis, #\\)", in, 0);
}

static cl_object
left_parenthesis_reader(cl_object in, cl_object character)
{
        const char c = ')';
        {
#line 464
	const cl_env_ptr the_env = ecl_process_env();
#line 464
	#line 464
	cl_object __value0 = do_read_delimited_list(c, in, 0);
#line 464
	the_env->nvalues = 1;
#line 464
	return __value0;
#line 464
}

                }

/*
 * BACKQUOTE READER
 */

static
cl_object comma_reader(cl_object in, cl_object c)
{
        cl_object x, y;
        const cl_env_ptr env = ecl_process_env();
        cl_fixnum backq_level = ecl_fixnum(ECL_SYM_VAL(env, ECL_SYM("SI::*BACKQ-LEVEL*",1012)));
        
        unlikely_if (backq_level <= 0)
                FEreader_error("A comma has appeared out of a backquote.", in, 0);
        /* Read character & complain at EOF */
        c = cl_peek_char(2,ECL_NIL,in);
        if (c == ECL_CODE_CHAR('@')) {
                x = ECL_SYM("SI::UNQUOTE-SPLICE",1037);
                ecl_read_char(in);
        } else if (c == ECL_CODE_CHAR('.')) {
                x = ECL_SYM("SI::UNQUOTE-NSPLICE",1036);
                ecl_read_char(in);
        } else {
                x = ECL_SYM("SI::UNQUOTE",1035);
        }
        ECL_SETQ(env, ECL_SYM("SI::*BACKQ-LEVEL*",1012), ecl_make_fixnum(backq_level-1));
        y = ecl_read_object(in);
        ECL_SETQ(env, ECL_SYM("SI::*BACKQ-LEVEL*",1012), ecl_make_fixnum(backq_level));
        return cl_list(2, x, y);
}

static
cl_object backquote_reader(cl_object in, cl_object c)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_fixnum backq_level = ecl_fixnum(ECL_SYM_VAL(the_env, ECL_SYM("SI::*BACKQ-LEVEL*",1012)));
        ECL_SETQ(the_env, ECL_SYM("SI::*BACKQ-LEVEL*",1012), ecl_make_fixnum(backq_level+1));
        in = ecl_read_object(in);
        ECL_SETQ(the_env, ECL_SYM("SI::*BACKQ-LEVEL*",1012), ecl_make_fixnum(backq_level));
#if 0
        {
#line 506
	const cl_env_ptr the_env = ecl_process_env();
#line 506
	#line 506
	cl_object __value0 = cl_macroexpand_1(2, cl_list(2, ECL_SYM("SI::QUASIQUOTE",1471), in), ECL_NIL);
#line 506
	the_env->nvalues = 1;
#line 506
	return __value0;
#line 506
}
;
#else
        {
#line 508
	const cl_env_ptr the_env = ecl_process_env();
#line 508
	#line 508
	cl_object __value0 = cl_list(2,ECL_SYM("SI::QUASIQUOTE",1471),in);
#line 508
	the_env->nvalues = 1;
#line 508
	return __value0;
#line 508
}

#endif
                }

/*
  read_constituent(in) reads a sequence of constituent characters from
  stream in and places it in token.  As a help, it returns TRUE
  or FALSE depending on the value of *READ-SUPPRESS*.
*/
static cl_object
read_constituent(cl_object in)
{
        int store = !read_suppress;
        cl_object rtbl = ecl_current_readtable();
        bool not_first = 0;
        cl_object token = si_get_buffer_string();
        do {
                int c = ecl_read_char(in);
                enum ecl_chattrib c_cat;
                if (c == EOF) {
                        break;
                }
                c_cat = ecl_readtable_get(rtbl, c, NULL);
                if (c_cat == cat_constituent ||
                    ((c_cat == cat_non_terminating) && not_first))
                        {
                                if (store) {
                                        ecl_string_push_extend(token, c);
                                }
                        } else {
                        ecl_unread_char(c, in);
                        break;
                }
                not_first = 1;
        } while(1);
        return (read_suppress)? ECL_NIL : token;
}

static cl_object
double_quote_reader(cl_object in, cl_object c)
{
        int delim = ECL_CHAR_CODE(c);
        cl_object rtbl = ecl_current_readtable();
        cl_object token = si_get_buffer_string();
        cl_object output;
        for (;;) {
                int c = ecl_read_char_noeof(in);
                if (c == delim)
                        break;
                else if (ecl_readtable_get(rtbl, c, NULL) == cat_single_escape)
                        c = ecl_read_char_noeof(in);
                ecl_string_push_extend(token, c);
        }
#ifdef ECL_UNICODE
        if (ecl_fits_in_base_string(token))
                output = si_coerce_to_base_string(token);
        else
#endif
                output = cl_copy_seq(token);
        si_put_buffer_string(token);
        {
#line 568
	const cl_env_ptr the_env = ecl_process_env();
#line 568
	#line 568
	cl_object __value0 = output;
#line 568
	the_env->nvalues = 1;
#line 568
	return __value0;
#line 568
}

                }

static cl_object
dispatch_reader_fun(cl_object in, cl_object dc)
{
        cl_object readtable = ecl_current_readtable();
        cl_object dispatch_table;
        int c = ecl_char_code(dc);
        ecl_readtable_get(readtable, c, &dispatch_table);
        unlikely_if (!ECL_HASH_TABLE_P(dispatch_table))
                FEreader_error("~C is not a dispatching macro character",
                               in, 1, dc);
        return dispatch_macro_character(dispatch_table, in, c);
}

static cl_object
dispatch_macro_character(cl_object table, cl_object in, int c)
{
        cl_object arg;
        int d;
        c = ecl_read_char_noeof(in);
        d = ecl_digitp(c, 10);
        if (d >= 0) {
                cl_fixnum i = 0;
                do {
                        i = 10*i + d;
                        c = ecl_read_char_noeof(in);
                        d = ecl_digitp(c, 10);
                } while (d >= 0);
                arg = ecl_make_fixnum(i);
        } else {
                arg = ECL_NIL;
        }
        {
                cl_object dc = ECL_CODE_CHAR(c);
                cl_object fun = ecl_gethash_safe(dc, table, ECL_NIL);
                unlikely_if (Null(fun)) {
                        FEreader_error("No dispatch function defined "
                                       "for character ~S",
                                       in, 1, dc);
                }
                return _ecl_funcall4(fun, in, dc, arg);
        }
}

static cl_object
single_quote_reader(cl_object in, cl_object c)
{
        c = ecl_read_object(in);
        unlikely_if (c == OBJNULL)
                FEend_of_file(in);
        {
#line 620
	const cl_env_ptr the_env = ecl_process_env();
#line 620
	#line 620
	cl_object __value0 = cl_list(2, ECL_SYM("QUOTE",679), c);
#line 620
	the_env->nvalues = 1;
#line 620
	return __value0;
#line 620
}

                }

static cl_object
void_reader(cl_object in, cl_object c)
{
        /*  no result  */
        {
#line 627
	const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 627
}

                }

static cl_object
semicolon_reader(cl_object in, cl_object c)
{
        int auxc;
        
        do
                auxc = ecl_read_char(in);
        while (auxc != '\n' && auxc != EOF);
        /*  no result  */
        {
#line 639
	const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 639
}

                }

/*
  sharpmacro routines
*/

static cl_object
sharp_C_reader(cl_object in, cl_object c, cl_object d)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object x, real, imag;
        
        if (d != ECL_NIL && !read_suppress)
                extra_argument('C', in, d);
        x = ecl_read_object(in);
        unlikely_if (x == OBJNULL)
                FEend_of_file(in);
        if (read_suppress)
                {
#line 658
	const cl_env_ptr the_env = ecl_process_env();
#line 658
	#line 658
	cl_object __value0 = ECL_NIL;
#line 658
	the_env->nvalues = 1;
#line 658
	return __value0;
#line 658
}
;
        unlikely_if (!ECL_CONSP(x) || ecl_length(x) != 2)
                FEreader_error("Reader macro #C should be followed by a list",
                               in, 0);
        real = CAR(x);
        imag = CADR(x);
        /* INV: ecl_make_complex() checks its types. When reading circular
           structures, we cannot check the types of the elements, and we
           must build the complex number by hand. */
        if ((CONSP(real) || CONSP(imag)) &&
            !Null(ECL_SYM_VAL(the_env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031))))
                {
                        x = ecl_alloc_object(t_complex);
                        x->complex.real = real;
                        x->complex.imag = imag;
                } else {
                x = ecl_make_complex(real, imag);
        }
        {
#line 676
	const cl_env_ptr the_env = ecl_process_env();
#line 676
	#line 676
	cl_object __value0 = x;
#line 676
	the_env->nvalues = 1;
#line 676
	return __value0;
#line 676
}

                }

static cl_object
sharp_backslash_reader(cl_object in, cl_object c, cl_object d)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object token;
        if (d != ECL_NIL && !read_suppress) {
                unlikely_if (!ECL_FIXNUMP(d) || d != ecl_make_fixnum(0)) {
                        FEreader_error("~S is an illegal CHAR-FONT.", in, 1, d);
                }
        }
        token = ecl_read_object_with_delimiter(in, EOF, ECL_READ_ONLY_TOKEN,
                                               cat_single_escape);
        if (token == ECL_NIL) {
                c = ECL_NIL;
        } else if (TOKEN_STRING_FILLP(token) == 1) {
                c = ECL_CODE_CHAR(TOKEN_STRING_CHAR(token,0));
        } else if (TOKEN_STRING_FILLP(token) == 2 && TOKEN_STRING_CHAR_CMP(token,0,'^')) {
                /*    #\^x    */
                c = ECL_CODE_CHAR(TOKEN_STRING_CHAR(token,1) & 037);
        } else {
                cl_object nc = cl_name_char(token);
                unlikely_if (Null(nc)) {
                        FEreader_error("~S is an illegal character name.", in, 1, token);
                }
                c = nc;
        }
        si_put_buffer_string(token);
        ecl_return1(the_env, c);
}

static cl_object
sharp_single_quote_reader(cl_object in, cl_object c, cl_object d)
{
        bool suppress = read_suppress;
        if(d != ECL_NIL && !suppress)
                extra_argument('\'', in, d);
        c = ecl_read_object(in);
        unlikely_if (c == OBJNULL) {
                FEend_of_file(in);
        } else if (suppress) {
                c = ECL_NIL;
        } else {
                c = cl_list(2, ECL_SYM("FUNCTION",396), c);
        }
        {
#line 723
	const cl_env_ptr the_env = ecl_process_env();
#line 723
	#line 723
	cl_object __value0 = c;
#line 723
	the_env->nvalues = 1;
#line 723
	return __value0;
#line 723
}

                }

static cl_object
sharp_Y_reader(cl_object in, cl_object c, cl_object d)
{
        cl_index i;
        cl_object x, rv, nth, lex;
        
        if (d != ECL_NIL && !read_suppress)
                extra_argument('C', in, d);
        x = ecl_read_object(in);
        unlikely_if (x == OBJNULL) {
                FEend_of_file(in);
        }
        if (read_suppress) {
                {
#line 739
	const cl_env_ptr the_env = ecl_process_env();
#line 739
	#line 739
	cl_object __value0 = ECL_NIL;
#line 739
	the_env->nvalues = 1;
#line 739
	return __value0;
#line 739
}
;
        }
        unlikely_if (!ECL_CONSP(x) || ecl_length(x) < 5) {
                FEreader_error("Reader macro #Y should be followed by a list",
                               in, 0);
        }
        
        if (ecl_length(x) == 2) {
                rv = ecl_alloc_object(t_bclosure);
                rv->bclosure.code = ECL_CONS_CAR(x);
                x = ECL_CONS_CDR(x);
                rv->bclosure.lex = ECL_CONS_CAR(x);
                rv->bclosure.entry = _ecl_bclosure_dispatch_vararg;
                {
#line 752
	const cl_env_ptr the_env = ecl_process_env();
#line 752
	#line 752
	cl_object __value0 = rv;
#line 752
	the_env->nvalues = 1;
#line 752
	return __value0;
#line 752
}
;
        }
        
        rv = ecl_alloc_object(t_bytecodes);
        
        rv->bytecodes.name = ECL_CONS_CAR(x);
        x = ECL_CONS_CDR(x);
        
        lex = ECL_CONS_CAR(x);
        x = ECL_CONS_CDR(x);
        
        rv->bytecodes.definition = ECL_CONS_CAR(x);
        x = ECL_CONS_CDR(x);
        
        nth = ECL_CONS_CAR(x);
        x = ECL_CONS_CDR(x);
        rv->bytecodes.code_size = ecl_to_fix(cl_list_length(nth));
        rv->bytecodes.code = ecl_alloc_atomic(rv->bytecodes.code_size * sizeof(uint16_t));
        for ( i=0; !ecl_endp(nth) ; i++, nth=ECL_CONS_CDR(nth) )
                ((cl_opcode*)(rv->bytecodes.code))[i] = ecl_to_fix(ECL_CONS_CAR(nth));
        
        nth = ECL_CONS_CAR(x);
        x = ECL_CONS_CDR(x);
        rv->bytecodes.data = nth;
        
        if (ECL_ATOM(x)) {
                nth = ECL_NIL;
        } else {
                nth = ECL_CONS_CAR(x);
                x = ECL_CONS_CDR(x);
        }
        rv->bytecodes.file = nth;
        if (ECL_ATOM(x)) {
                nth = ecl_make_fixnum(0);
        } else {
                nth = ECL_CONS_CAR(x);
                x = ECL_CONS_CDR(x);
        }
        rv->bytecodes.file_position = nth;
        
        rv->bytecodes.entry = _ecl_bytecodes_dispatch_vararg;
        {
#line 793
	const cl_env_ptr the_env = ecl_process_env();
#line 793
	#line 793
	cl_object __value0 = rv;
#line 793
	the_env->nvalues = 1;
#line 793
	return __value0;
#line 793
}
;
}

#define    QUOTE    1
#define    EVAL    2
#define    LIST    3
#define    LISTX    4
#define    APPEND    5
#define    NCONC    6


/*
 *----------------------------------------------------------------------
 *    Stack of unknown size
 *----------------------------------------------------------------------
 */

static cl_object
sharp_left_parenthesis_reader(cl_object in, cl_object c, cl_object d)
{
        extern int _cl_backq_car(cl_object *);
        const cl_env_ptr the_env = ecl_process_env();
        cl_object v;
        if (ecl_fixnum(ECL_SYM_VAL(the_env, ECL_SYM("SI::*BACKQ-LEVEL*",1012))) > 0) {
                /* First case: ther might be unquoted elements in the vector.
                 * Then we just create a form that generates the vector.
                 */
                cl_object x = do_read_delimited_list(')', in, 1);
                cl_index a = _cl_backq_car(&x);
                unlikely_if (a == APPEND || a == NCONC) {
                        FEreader_error("A , or ,. appeared in an illegal position.",
                                       in, 0);
                }
                if (a == QUOTE) {
                        v = _ecl_funcall4(ECL_SYM("MAKE-ARRAY",522), cl_list(1, cl_length(x)),
                                          ECL_SYM(":INITIAL-CONTENTS",1252), x);
                } else {
                        v = cl_list(2, ECL_SYM("SI::UNQUOTE",1035), 
                                    cl_list(3, ECL_SYM("APPLY",89),
                                            cl_list(2, ECL_SYM("QUOTE",679), ECL_SYM("VECTOR",898)), x));
                }
        } else if (read_suppress) {
                /* Second case: *read-suppress* = t, we ignore the data */
                do_read_delimited_list(')', in, 1);
                v = ECL_NIL;
        } else if (Null(d)) {
                /* Third case: no dimension provided. Read a list and
                   coerce it to vector. */
                cl_object x = do_read_delimited_list(')', in, 1);
                v = _ecl_funcall4(ECL_SYM("MAKE-ARRAY",522), cl_list(1, cl_length(x)),
                                  ECL_SYM(":INITIAL-CONTENTS",1252), x);
        } else {
                /* Finally: Both dimension and data are provided. The
                   amount of data cannot exceed the length, but it may
                   be smaller, and in that case...*/
                cl_object last;
                cl_index dim, i;
                unlikely_if (!ECL_FIXNUMP(d) || ((dim = ecl_fixnum(d)) < 0) ||
                             (dim > ECL_ARRAY_DIMENSION_LIMIT)) {
                        FEreader_error("Invalid dimension size ~D in #()", in, 1, d);
                }
                v = ecl_alloc_simple_vector(dim, ecl_aet_object);
                for (i = 0, last = ECL_NIL;; i++) {
                        cl_object aux = ecl_read_object_with_delimiter(in, ')', 0,
                                                                       cat_constituent);
                        if (aux == OBJNULL)
                                break;
                        unlikely_if (i >= dim) {
                                FEreader_error("Vector larger than specified length,"
                                               "~D.", in, 1, d);
                        }
                        ecl_aset_unsafe(v, i, last = aux);
                }
                /* ... we fill the vector with the last element read (or NIL). */
                for (; i < dim; i++) {
                        ecl_aset_unsafe(v, i, last);
                }
        }
        {
#line 871
	const cl_env_ptr the_env = ecl_process_env();
#line 871
	#line 871
	cl_object __value0 = v;
#line 871
	the_env->nvalues = 1;
#line 871
	return __value0;
#line 871
}

                }

static cl_object
sharp_asterisk_reader(cl_object in, cl_object c, cl_object d)
{
        cl_env_ptr env = ecl_process_env();
        cl_index sp = ECL_STACK_INDEX(env);
        cl_object last, elt, x;
        cl_index dim, dimcount, i;
        cl_object rtbl = ecl_current_readtable();
        enum ecl_chattrib a;
        
        if (read_suppress) {
                read_constituent(in);
                {
#line 886
	const cl_env_ptr the_env = ecl_process_env();
#line 886
	#line 886
	cl_object __value0 = ECL_NIL;
#line 886
	the_env->nvalues = 1;
#line 886
	return __value0;
#line 886
}

                        }
        for (dimcount = 0 ;; dimcount++) {
                int x = ecl_read_char(in);
                if (x == EOF)
                        break;
                a = ecl_readtable_get(rtbl, x, NULL);
                if (a == cat_terminating || a == cat_whitespace) {
                        ecl_unread_char(x, in);
                        break;
                }
                unlikely_if (a == cat_single_escape || a == cat_multiple_escape ||
                             (x != '0' && x != '1'))
                        {
                                FEreader_error("Character ~:C is not allowed after #*",
                                               in, 1, ECL_CODE_CHAR(x));
                        }
                ECL_STACK_PUSH(env, ecl_make_fixnum(x == '1'));
        }
        if (Null(d)) {
                dim = dimcount;
        } else {
                unlikely_if (!ECL_FIXNUMP(d) || ((dim = ecl_fixnum(d)) < 0) ||
                             (dim > ECL_ARRAY_DIMENSION_LIMIT))
                        {
                                FEreader_error("Wrong vector dimension size ~D in #*.",
                                               in, 1, d);
                        }
                unlikely_if (dimcount > dim)
                        FEreader_error("Too many elements in #*.", in, 0);
                unlikely_if (dim && (dimcount == 0))
                        FEreader_error("Cannot fill the bit-vector #*.", in, 0);
        }
        last = ECL_STACK_REF(env,-1);
        x = ecl_alloc_simple_vector(dim, ecl_aet_bit);
        for (i = 0; i < dim; i++) {
                elt = (i < dimcount) ? env->stack[sp+i] : last;
                if (elt == ecl_make_fixnum(0))
                        x->vector.self.bit[i/CHAR_BIT] &= ~(0200 >> i%CHAR_BIT);
                else
                        x->vector.self.bit[i/CHAR_BIT] |= 0200 >> i%CHAR_BIT;
        }
        ECL_STACK_POP_N_UNSAFE(env, dimcount);
        {
#line 929
	const cl_env_ptr the_env = ecl_process_env();
#line 929
	#line 929
	cl_object __value0 = x;
#line 929
	the_env->nvalues = 1;
#line 929
	return __value0;
#line 929
}

                }

static cl_object
sharp_colon_reader(cl_object in, cl_object ch, cl_object d)
{
        cl_object rtbl = ecl_current_readtable();
        enum ecl_chattrib a;
        bool escape_flag;
        int c;
        cl_object output, token;
        
        if (d != ECL_NIL && !read_suppress)
                extra_argument(':', in, d);
        c = ecl_read_char_noeof(in);
        a = ecl_readtable_get(rtbl, c, NULL);
        escape_flag = FALSE;
        token = si_get_buffer_string();
        goto L;
        for (;;) {
                ecl_string_push_extend(token, c);
        K:
                c = ecl_read_char(in);
                if (c == EOF)
                        goto M;
                a = ecl_readtable_get(rtbl, c, NULL);
        L:
                if (a == cat_single_escape) {
                        c = ecl_read_char_noeof(in);
                        a = cat_constituent;
                        escape_flag = TRUE;
                } else if (a == cat_multiple_escape) {
                        escape_flag = TRUE;
                        for (;;) {
                                c = ecl_read_char_noeof(in);
                                a = ecl_readtable_get(rtbl, c, NULL);
                                if (a == cat_single_escape) {
                                        c = ecl_read_char_noeof(in);
                                        a = cat_constituent;
                                } else if (a == cat_multiple_escape)
                                        break;
                                ecl_string_push_extend(token, c);
                        }
                        goto K;
                } else if (ecl_lower_case_p(c))
                        c = ecl_char_upcase(c);
                if (a == cat_whitespace || a == cat_terminating)
                        break;
        }
        ecl_unread_char(c, in);
        
 M:
        if (read_suppress) {
                output = ECL_NIL;
        } else {
                output = cl_make_symbol(token);
        }
        si_put_buffer_string(token);
        {
#line 987
	const cl_env_ptr the_env = ecl_process_env();
#line 987
	#line 987
	cl_object __value0 = output;
#line 987
	the_env->nvalues = 1;
#line 987
	return __value0;
#line 987
}

                }

static cl_object
sharp_dot_reader(cl_object in, cl_object c, cl_object d)
{
        if (d != ECL_NIL && !read_suppress)
                extra_argument('.', in, d);
        c = ecl_read_object(in);
        unlikely_if (c == OBJNULL)
                FEend_of_file(in);
        if (read_suppress)
                {
#line 999
	const cl_env_ptr the_env = ecl_process_env();
#line 999
	#line 999
	cl_object __value0 = ECL_NIL;
#line 999
	the_env->nvalues = 1;
#line 999
	return __value0;
#line 999
}
;
        unlikely_if (ecl_symbol_value(ECL_SYM("*READ-EVAL*",63)) == ECL_NIL)
                FEreader_error("Cannot evaluate the form #.~A", in, 1, c);
        /* FIXME! We should do something here to ensure that the #.
         * only uses the #n# that have been defined */
        c = patch_sharp(c);
        c = si_eval_with_env(1, c);
        {
#line 1006
	const cl_env_ptr the_env = ecl_process_env();
#line 1006
	#line 1006
	cl_object __value0 = c;
#line 1006
	the_env->nvalues = 1;
#line 1006
	return __value0;
#line 1006
}

                }

static cl_object
read_number(cl_object in, int radix, cl_object macro_char)
{
        cl_index i;
        cl_object x;
        cl_object token = read_constituent(in);
        if (token == ECL_NIL) {
                x = ECL_NIL;
        } else {
                x = ecl_parse_number(token, 0, TOKEN_STRING_FILLP(token), &i, radix);
                unlikely_if (x == OBJNULL || x == ECL_NIL ||
                             i != TOKEN_STRING_FILLP(token))
                        {
                                FEreader_error("Cannot parse the #~A readmacro.", in, 1,
                                               macro_char);
                        }
                unlikely_if (cl_rationalp(x) == ECL_NIL) {
                        FEreader_error("The float ~S appeared after the #~A readmacro.",
                                       in, 2, x, macro_char);
                }
                si_put_buffer_string(token);
        }
        return x;
}

static cl_object
sharp_B_reader(cl_object in, cl_object c, cl_object d)
{
        if(d != ECL_NIL && !read_suppress)
                extra_argument('B', in, d);
        {
#line 1039
	const cl_env_ptr the_env = ecl_process_env();
#line 1039
	#line 1039
	cl_object __value0 = (read_number(in, 2, ECL_CODE_CHAR('B')));
#line 1039
	the_env->nvalues = 1;
#line 1039
	return __value0;
#line 1039
}

                }

static cl_object
sharp_O_reader(cl_object in, cl_object c, cl_object d)
{
        if(d != ECL_NIL && !read_suppress)
                extra_argument('O', in, d);
        {
#line 1047
	const cl_env_ptr the_env = ecl_process_env();
#line 1047
	#line 1047
	cl_object __value0 = (read_number(in, 8, ECL_CODE_CHAR('O')));
#line 1047
	the_env->nvalues = 1;
#line 1047
	return __value0;
#line 1047
}

                }

static cl_object
sharp_X_reader(cl_object in, cl_object c, cl_object d)
{
        if(d != ECL_NIL && !read_suppress)
                extra_argument('X', in, d);
        {
#line 1055
	const cl_env_ptr the_env = ecl_process_env();
#line 1055
	#line 1055
	cl_object __value0 = (read_number(in, 16, ECL_CODE_CHAR('X')));
#line 1055
	the_env->nvalues = 1;
#line 1055
	return __value0;
#line 1055
}

                }

static cl_object
sharp_R_reader(cl_object in, cl_object c, cl_object d)
{
        int radix;
        if (read_suppress) {
                radix = 10;
        } else unlikely_if (!ECL_FIXNUMP(d)) {
                        FEreader_error("No radix was supplied in the #R readmacro.", in, 0);
                } else {
                radix = ecl_fixnum(d);
                unlikely_if (radix > 36 || radix < 2) {
                        FEreader_error("~S is an illegal radix.", in, 1, d);
                }
        }
        {
#line 1072
	const cl_env_ptr the_env = ecl_process_env();
#line 1072
	#line 1072
	cl_object __value0 = (read_number(in, radix, ECL_CODE_CHAR('R')));
#line 1072
	the_env->nvalues = 1;
#line 1072
	return __value0;
#line 1072
}

                }

#define sharp_A_reader void_reader
#define sharp_S_reader void_reader

static cl_object
sharp_eq_reader(cl_object in, cl_object c, cl_object d)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object pair, value;
        cl_object sharp_eq_context = ECL_SYM_VAL(the_env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031));
        
        if (read_suppress) {
#line 1085
	const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 1085
}
;
        unlikely_if (Null(d)) {
                FEreader_error("The #= readmacro requires an argument.", in, 0);
        }
        unlikely_if (ecl_assq(d, sharp_eq_context) != ECL_NIL) {
                FEreader_error("Duplicate definitions for #~D=.", in, 1, d);
        }
        pair = CONS(d, ECL_NIL);
        ECL_SETQ(the_env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031), CONS(pair, sharp_eq_context));
        value = ecl_read_object(in);
        unlikely_if (value == pair) {
                FEreader_error("#~D# is defined by itself.", in, 1, d);
        }
        ECL_RPLACD(pair, value);
        ecl_return1(the_env, value);
}

static cl_object
sharp_sharp_reader(cl_object in, cl_object c, cl_object d)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object pair;
        
        if (read_suppress)
                {
#line 1109
	const cl_env_ptr the_env = ecl_process_env();
#line 1109
	#line 1109
	cl_object __value0 = ECL_NIL;
#line 1109
	the_env->nvalues = 1;
#line 1109
	return __value0;
#line 1109
}
;
        unlikely_if (Null(d)) {
                FEreader_error("The ## readmacro requires an argument.", in, 0);
        }
        pair = ecl_assq(d, ECL_SYM_VAL(the_env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031)));
        unlikely_if (pair == ECL_NIL) {
                FEreader_error("#~D# is undefined.", in, 1, d);
        }
        {
#line 1117
	const cl_env_ptr the_env = ecl_process_env();
#line 1117
	#line 1117
	cl_object __value0 = pair;
#line 1117
	the_env->nvalues = 1;
#line 1117
	return __value0;
#line 1117
}

                }

static cl_object
do_patch_sharp(cl_object x, cl_object table)
#if 1
{
        /* The hash table maintains an association as follows:
         *
         * [1] object -> itself
         *    The object has been processed by patch_sharp, us as it is.
         * [2] object -> nothing
         *    The object has to be processed by do_patch_sharp.
         * [3] (# . object) -> object
         *    This is the value of a #n# statement. The object migt
         *    or might not yet be processed by do_patch_sharp().
         */
 AGAIN:
        switch (ecl_t_of(x)) {
                case t_list: {
                        cl_object y;
                        if (Null(x))
                                return x;
                        y = ecl_gethash_safe(x, table, table);
                        if (y == table) {
                                /* case [2] */
                                break;
                        } else if (y == x) {
                                /* case [1] */
                                return x;
                        } else {
                                /* case [3] */
                                x = y;
                                goto AGAIN;
                        }
                }
                case t_vector:
                case t_array:
                case t_complex:
                case t_bclosure:
                case t_bytecodes: {
                        cl_object y = ecl_gethash_safe(x, table, table);
                        if (y == table) {
                                /* case [2] */
                                break;
                        }
                        /* it can only be case [1] */
                }
                default:
                        return x;
        }
        /* We eagerly mark the object as processed, to avoid infinite
         * recursion. */
        _ecl_sethash(x, table, x);
        switch (ecl_t_of(x)) {
                case t_list:
                        ECL_RPLACA(x, do_patch_sharp(ECL_CONS_CAR(x), table));
                        ECL_RPLACD(x, do_patch_sharp(ECL_CONS_CDR(x), table));
                        break;
                case t_vector:
                        if (x->vector.elttype == ecl_aet_object) {
                                cl_index i;
                                for (i = 0;  i < x->vector.fillp;  i++)
                                        x->vector.self.t[i] =
                                                do_patch_sharp(x->vector.self.t[i], table);
                        }
                        break;
                case t_array:
                        if (x->vector.elttype == ecl_aet_object) {
                                cl_index i, j = x->array.dim;
                                for (i = 0;  i < j;  i++)
                                        x->array.self.t[i] =
                                                do_patch_sharp(x->array.self.t[i], table);
                        }
                        break;
                case t_complex: {
                        cl_object r = do_patch_sharp(x->complex.real, table);
                        cl_object i = do_patch_sharp(x->complex.imag, table);
                        if (r != x->complex.real || i != x->complex.imag) {
                                cl_object c = ecl_make_complex(r, i);
                                x->complex = c->complex;
                        }
                        break;
                }
                case t_bclosure: {
                        x->bclosure.lex = do_patch_sharp(x->bclosure.lex, table);
                        x = x->bclosure.code = do_patch_sharp(x->bclosure.code, table);
                        break;
                }
                case t_bytecodes: {
                        x->bytecodes.name = do_patch_sharp(x->bytecodes.name, table);
                        x->bytecodes.definition = do_patch_sharp(x->bytecodes.definition, table);
                        x->bytecodes.data = do_patch_sharp(x->bytecodes.data, table);
                        break;
                }
                default:;
        }
        return x;
}
#else
{
        switch (ecl_t_of(x)) {
                case t_list:
                        if (Null(x))
                                return x;
                case t_vector:
                case t_array:
                case t_complex:
                case t_bclosure:
                case t_bytecodes: {
                        cl_object y = ecl_gethash_safe(x, table, table);
                        if (y == table)
                                break;
                        x = y;
                }
                default:
                        return x;
        }
        switch (ecl_t_of(x)) {
                case t_list:
                        ECL_RPLACA(x, do_patch_sharp(ECL_CONS_CAR(x), table));
                        ECL_RPLACD(x, do_patch_sharp(ECL_CONS_CDR(x), table));
                        break;
                case t_vector:
                        if (x->vector.elttype == ecl_aet_object) {
                                cl_index i;
                                for (i = 0;  i < x->vector.fillp;  i++)
                                        x->vector.self.t[i] =
                                                do_patch_sharp(x->vector.self.t[i], table);
                        }
                        break;
                case t_array:
                        if (x->vector.elttype == ecl_aet_object) {
                                cl_index i, j = x->array.dim;
                                for (i = 0;  i < j;  i++)
                                        x->array.self.t[i] =
                                                do_patch_sharp(x->array.self.t[i], table);
                        }
                        break;
                case t_complex: {
                        cl_object r = do_patch_sharp(x->complex.real, table);
                        cl_object i = do_patch_sharp(x->complex.imag, table);
                        if (r != x->complex.real || i != x->complex.imag) {
                                cl_object c = ecl_make_complex(r, i);
                                x->complex = c->complex;
                        }
                        break;
                }
                case t_bclosure: {
                        x->bclosure.lex = do_patch_sharp(x->bclosure.lex, table);
                        x = x->bclosure.code = do_patch_sharp(x->bclosure.code, table);
                        break;
                }
                case t_bytecodes: {
                        x->bytecodes.name = do_patch_sharp(x->bytecodes.name, table);
                        x->bytecodes.definition = do_patch_sharp(x->bytecodes.definition, table);
                        x->bytecodes.data = do_patch_sharp(x->bytecodes.data, table);
                        break;
                }
                default:;
        }
        _ecl_sethash(x, table, x);
        return x;
}
#endif

static cl_object
patch_sharp(cl_object x)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object pairs;
        cl_object table = 
                cl__make_hash_table(ECL_SYM("EQ",333), ecl_make_fixnum(20), /* size */
                                    cl_core.rehash_size,
                                    cl_core.rehash_threshold);
        
        pairs = ECL_SYM_VAL(the_env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031));
        loop_for_in(pairs) {
                cl_object pair = ECL_CONS_CAR(pairs);
                _ecl_sethash(pair, table, ECL_CONS_CDR(pair));
        } end_loop_for_in;
        x = do_patch_sharp(x, table);
        return x;
}

#define sharp_plus_reader void_reader
#define sharp_minus_reader void_reader
#define sharp_less_than_reader void_reader
#define sharp_whitespace_reader void_reader
#define sharp_right_parenthesis_reader void_reader

static cl_object
sharp_vertical_bar_reader(cl_object in, cl_object ch, cl_object d)
{
        int c;
        int level = 0;
        
        if (d != ECL_NIL && !read_suppress)
                extra_argument('|', in, d);
        for (;;) {
                c = ecl_read_char_noeof(in);
        L:
                if (c == '#') {
                        c = ecl_read_char_noeof(in);
                        if (c == '|')
                                level++;
                } else if (c == '|') {
                        c = ecl_read_char_noeof(in);
                        if (c == '#') {
                                if (level == 0)
                                        break;
                                else
                                        --level;
                        } else
                                goto L;
                }
        }
        {
#line 1334
	const cl_env_ptr the_env = ecl_process_env();
the_env->nvalues = 0; return ECL_NIL;
#line 1334
}

                /*  no result  */
                }

static cl_object
default_dispatch_macro_fun(cl_object in, cl_object c, cl_object d)
{
        FEreader_error("No dispatch function defined for character ~s.", in, 1, c);
}

/*
  #P" ... " returns the pathname with namestring ... .
*/
static cl_object
sharp_P_reader(cl_object in, cl_object c, cl_object d)
{
        bool suppress = read_suppress;
        if (d != ECL_NIL && !suppress)
                extra_argument('P', in, d);
        d = ecl_read_object(in);
        if (suppress) {
                d = ECL_NIL;
        } else {
                d = cl_parse_namestring(3, d, ECL_NIL, ECL_NIL);
        }
        {
#line 1359
	const cl_env_ptr the_env = ecl_process_env();
#line 1359
	#line 1359
	cl_object __value0 = d;
#line 1359
	the_env->nvalues = 1;
#line 1359
	return __value0;
#line 1359
}

                }

/*
  #$ fixnum returns a random-state with the fixnum
  as its content.
*/
static cl_object
sharp_dollar_reader(cl_object in, cl_object c, cl_object d)
{
        cl_object rs;
        if (d != ECL_NIL && !read_suppress)
                extra_argument('$', in, d);
        c = ecl_read_object(in);
        rs = ecl_alloc_object(t_random);
        rs->random.value = c;
        {
#line 1375
	const cl_env_ptr the_env = ecl_process_env();
#line 1375
	#line 1375
	cl_object __value0 = rs;
#line 1375
	the_env->nvalues = 1;
#line 1375
	return __value0;
#line 1375
}

                }

/*
  readtable routines
*/

static void ECL_INLINE
assert_type_readtable(cl_object function, cl_narg narg, cl_object p)
{
        unlikely_if (!ECL_READTABLEP(p)) {
                FEwrong_type_nth_arg(function, narg, p, ecl_make_fixnum(/*READTABLE*/700));
        }
}


cl_object
ecl_copy_readtable(cl_object from, cl_object to)
{
        struct ecl_readtable_entry *from_rtab, *to_rtab;
        cl_index i;
        size_t entry_bytes = sizeof(struct ecl_readtable_entry);
        size_t total_bytes = entry_bytes * RTABSIZE;
        cl_object output;
        
        assert_type_readtable(ecl_make_fixnum(/*COPY-READTABLE*/259), 1, from);
        /* For the sake of garbage collector and thread safety we
         * create an incomplete object and only copy to the destination
         * at the end in a more or less "atomic" (meaning "fast") way.
         */
        output = ecl_alloc_object(t_readtable);
        output->readtable.locked = 0;
        output->readtable.table = to_rtab = (struct ecl_readtable_entry *)
                ecl_alloc_align(total_bytes, entry_bytes);
        from_rtab = from->readtable.table;
        memcpy(to_rtab, from_rtab, total_bytes);
        for (i = 0;  i < RTABSIZE;  i++) {
                cl_object d = from_rtab[i].dispatch;
                if (ECL_HASH_TABLE_P(d)) {
                        d = si_copy_hash_table(d);
                }
                to_rtab[i].dispatch = d;
        }
        output->readtable.read_case = from->readtable.read_case;
#ifdef ECL_UNICODE
        if (!Null(from->readtable.hash)) {
                output->readtable.hash = si_copy_hash_table(from->readtable.hash);
        } else {
                output->readtable.hash = ECL_NIL;
        }
#endif
        if (!Null(to)) {
                assert_type_readtable(ecl_make_fixnum(/*COPY-READTABLE*/259), 2, to);
                to->readtable = output->readtable;
                output = to;
        }
        return output;
}

cl_object
ecl_current_readtable(void)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object r;
        
        /* INV: *readtable* always has a value */
        r = ECL_SYM_VAL(the_env, ECL_SYM("*READTABLE*",65));
        unlikely_if (!ECL_READTABLEP(r)) {
                ECL_SETQ(the_env, ECL_SYM("*READTABLE*",65), cl_core.standard_readtable);
                FEerror("The value of *READTABLE*, ~S, was not a readtable.",
                        1, r);
        }
        return r;
}

int
ecl_current_read_base(void)
{
        const cl_env_ptr the_env = ecl_process_env();
        /* INV: *READ-BASE* always has a value */
        cl_object x = ECL_SYM_VAL(the_env, ECL_SYM("*READ-BASE*",61));
        cl_fixnum b;
        
        unlikely_if (!ECL_FIXNUMP(x) || ((b = ecl_fixnum(x)) < 2) || (b > 36))
                {
                        ECL_SETQ(the_env, ECL_SYM("*READ-BASE*",61), ecl_make_fixnum(10));
                        FEerror("The value of *READ-BASE*~&  ~S~%"
                                "is not in the range (INTEGER 2 36)", 1, x);
                }
        return b;
}

char
ecl_current_read_default_float_format(void)
{
        const cl_env_ptr the_env = ecl_process_env();
        cl_object x;
        
        /* INV: *READ-DEFAULT-FLOAT-FORMAT* is always bound to something */
        x = ECL_SYM_VAL(the_env, ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62));
        if (x == ECL_SYM("SINGLE-FLOAT",778) || x == ECL_SYM("SHORT-FLOAT",756))
                return 'F';
        if (x == ECL_SYM("DOUBLE-FLOAT",315))
                return 'D';
        if (x == ECL_SYM("LONG-FLOAT",508)) {
#ifdef ECL_LONG_FLOAT
                return 'L';
#else
                return 'D';
#endif
        }
        ECL_SETQ(the_env, ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62), ECL_SYM("SINGLE-FLOAT",778));
        FEerror("The value of *READ-DEFAULT-FLOAT-FORMAT*~& ~S~%"
                "is not one of (SINGLE-FLOAT SHORT-FLOAT DOUBLE-FLOAT LONG-FLOAT)",
                1, x);
}

static cl_object
stream_or_default_input(cl_object stream)
{
        const cl_env_ptr the_env = ecl_process_env();
        if (Null(stream))
                return ECL_SYM_VAL(the_env, ECL_SYM("*STANDARD-INPUT*",66));
        if (stream == ECL_T)
                return ECL_SYM_VAL(the_env, ECL_SYM("*TERMINAL-IO*",68));
        return stream;
}

#line 1503
cl_object cl_read(cl_narg narg, ...)
{
#line 1503

  cl_object x;
  #line 1506
	const cl_env_ptr the_env = ecl_process_env();
#line 1506
	cl_object strm;
#line 1506
	cl_object eof_errorp;
#line 1506
	cl_object eof_value;
#line 1506
	cl_object recursivep;
#line 1506
	va_list ARGS;
	va_start(ARGS, narg);
#line 1506
	if (ecl_unlikely(narg < 0|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(690));
#line 1506
	if (narg > 0) {
#line 1506
		strm = va_arg(ARGS,cl_object);
#line 1506
	} else {
#line 1506
		strm = ECL_NIL;
#line 1506
	}
#line 1506
	if (narg > 1) {
#line 1506
		eof_errorp = va_arg(ARGS,cl_object);
#line 1506
	} else {
#line 1506
		eof_errorp = ECL_T;
#line 1506
	}
#line 1506
	if (narg > 2) {
#line 1506
		eof_value = va_arg(ARGS,cl_object);
#line 1506
	} else {
#line 1506
		eof_value = ECL_NIL;
#line 1506
	}
#line 1506
	if (narg > 3) {
#line 1506
		recursivep = va_arg(ARGS,cl_object);
#line 1506
	} else {
#line 1506
		recursivep = ECL_NIL;
#line 1506
	}
#line 1506
  strm = stream_or_default_input(strm);
  if (Null(recursivep)) {
          nlogd(">>read non-recursive. ansi_stream_p(%d)", ECL_ANSI_STREAM_P(strm));
          x = ecl_read_object_non_recursive(strm);
          nlogd(">>read non-recursive. to");
  } else {
          nlogd(">>read recursive");
          x = ecl_read_object(strm);
  }
  if (x == OBJNULL) {
          if (Null(eof_errorp))
                  {
#line 1517
	#line 1517
	cl_object __value0 = eof_value;
#line 1517
	the_env->nvalues = 1;
#line 1517
	return __value0;
#line 1517
}

                          FEend_of_file(strm);
  }
  /* Skip whitespace characters, but stop at beginning of new line or token */
  if (Null(recursivep)) {
          cl_object rtbl = ecl_current_readtable();
          nlogd(">>>>>>>>>read-char from");
          int c = ecl_read_char(strm);
          nlogd(">>>>>>>>>read-char to(%d)", c);
          if (c != EOF && (ecl_readtable_get(rtbl, c, NULL) != cat_whitespace)) {
                  ecl_unread_char(c, strm);
          }
  }
  {
#line 1530
	#line 1530
	cl_object __value0 = x;
#line 1530
	the_env->nvalues = 1;
#line 1530
	return __value0;
#line 1530
}

  }

#line 1537
cl_object cl_read_preserving_whitespace(cl_narg narg, ...)
{
#line 1537

  cl_object x;
  #line 1540
	const cl_env_ptr the_env = ecl_process_env();
#line 1540
	cl_object strm;
#line 1540
	cl_object eof_errorp;
#line 1540
	cl_object eof_value;
#line 1540
	cl_object recursivep;
#line 1540
	va_list ARGS;
	va_start(ARGS, narg);
#line 1540
	if (ecl_unlikely(narg < 0|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(697));
#line 1540
	if (narg > 0) {
#line 1540
		strm = va_arg(ARGS,cl_object);
#line 1540
	} else {
#line 1540
		strm = ECL_NIL;
#line 1540
	}
#line 1540
	if (narg > 1) {
#line 1540
		eof_errorp = va_arg(ARGS,cl_object);
#line 1540
	} else {
#line 1540
		eof_errorp = ECL_T;
#line 1540
	}
#line 1540
	if (narg > 2) {
#line 1540
		eof_value = va_arg(ARGS,cl_object);
#line 1540
	} else {
#line 1540
		eof_value = ECL_NIL;
#line 1540
	}
#line 1540
	if (narg > 3) {
#line 1540
		recursivep = va_arg(ARGS,cl_object);
#line 1540
	} else {
#line 1540
		recursivep = ECL_NIL;
#line 1540
	}
#line 1540
  strm = stream_or_default_input(strm);
  if (Null(recursivep)) {
          x = ecl_read_object_non_recursive(strm);
  } else {
          x = ecl_read_object(strm);
  }
  if (x == OBJNULL) {
          if (Null(eof_errorp))
                  {
#line 1548
	#line 1548
	cl_object __value0 = eof_value;
#line 1548
	the_env->nvalues = 1;
#line 1548
	return __value0;
#line 1548
}

                          FEend_of_file(strm);
  }
  {
#line 1551
	#line 1551
	cl_object __value0 = x;
#line 1551
	the_env->nvalues = 1;
#line 1551
	return __value0;
#line 1551
}

  }

static cl_object
do_read_delimited_list(int d, cl_object in, bool proper_list)
{
        nlogd(">>FUCK");
        int after_dot = 0;
        bool suppress = read_suppress;
        cl_object x, y = ECL_NIL;
        cl_object *p = &y;
        do {
                x = ecl_read_object_with_delimiter(in, d, ECL_READ_LIST_DOT,
                                                   cat_constituent);
                if (x == OBJNULL) {
                        /* End of the list. */
                        unlikely_if (after_dot == 1) {
                                /* Something like (1 . ) */
                                FEreader_error("Object missing after a list dot", in, 0);
                        }
                        return y;
                } else if (x == ECL_SYM("SI::.",1034)) {
                        unlikely_if (proper_list) {
                                FEreader_error("A dotted list was found where a proper list was expected.", in, 0);
                        }
                        unlikely_if (p == &y) {
                                /* Something like (. 2) */
                                FEreader_error("A dot appeared after a left parenthesis.", in, 0);
                        }
                        unlikely_if (after_dot) {
                                /* Something like (1 . . 2) */
                                FEreader_error("Two dots appeared consecutively.", in, 0);
                        }
                        after_dot = 1;
                } else if (after_dot) {
                        unlikely_if (after_dot++ > 1) {
                                /* Something like (1 . 2 3) */
                                FEreader_error("Too many objects after a list dot", in, 0);
                        }
                        *p = x;
                } else if (!suppress) {
                        *p = ecl_list1(x);
                        p = &ECL_CONS_CDR(*p);
                }
        } while (1);
}

#line 1598
cl_object cl_read_delimited_list(cl_narg narg, cl_object d, ...)
{
#line 1598

  cl_object l;
  int delimiter;
  #line 1602
	const cl_env_ptr the_env = ecl_process_env();
#line 1602
	cl_object strm;
#line 1602
	cl_object recursivep;
#line 1602
	va_list ARGS;
	va_start(ARGS, d);
#line 1602
	if (ecl_unlikely(narg < 1|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(694));
#line 1602
	if (narg > 1) {
#line 1602
		strm = va_arg(ARGS,cl_object);
#line 1602
	} else {
#line 1602
		strm = ECL_NIL;
#line 1602
	}
#line 1602
	if (narg > 2) {
#line 1602
		recursivep = va_arg(ARGS,cl_object);
#line 1602
	} else {
#line 1602
		recursivep = ECL_NIL;
#line 1602
	}
#line 1602
  delimiter = ecl_char_code(d);
  strm = stream_or_default_input(strm);
  if (!Null(recursivep)) {
          l = do_read_delimited_list(delimiter, strm, 1);
  } else {
          ecl_bds_bind(the_env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031), ECL_NIL);
          ecl_bds_bind(the_env, ECL_SYM("SI::*BACKQ-LEVEL*",1012), ecl_make_fixnum(0));
          l = do_read_delimited_list(delimiter, strm, 1);
          if (!Null(ECL_SYM_VAL(the_env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031))))
                  l = patch_sharp(l);
          ecl_bds_unwind_n(the_env, 2);
  }
  {
#line 1614
	#line 1614
	cl_object __value0 = l;
#line 1614
	the_env->nvalues = 1;
#line 1614
	return __value0;
#line 1614
}

  }

#line 1617
cl_object cl_read_line(cl_narg narg, ...)
{
#line 1617

  int c;
  cl_object token, value0, value1;
  #line 1621
	const cl_env_ptr the_env = ecl_process_env();
#line 1621
	cl_object strm;
#line 1621
	cl_object eof_errorp;
#line 1621
	cl_object eof_value;
#line 1621
	cl_object recursivep;
#line 1621
	va_list ARGS;
	va_start(ARGS, narg);
#line 1621
	if (ecl_unlikely(narg < 0|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(696));
#line 1621
	if (narg > 0) {
#line 1621
		strm = va_arg(ARGS,cl_object);
#line 1621
	} else {
#line 1621
		strm = ECL_NIL;
#line 1621
	}
#line 1621
	if (narg > 1) {
#line 1621
		eof_errorp = va_arg(ARGS,cl_object);
#line 1621
	} else {
#line 1621
		eof_errorp = ECL_T;
#line 1621
	}
#line 1621
	if (narg > 2) {
#line 1621
		eof_value = va_arg(ARGS,cl_object);
#line 1621
	} else {
#line 1621
		eof_value = ECL_NIL;
#line 1621
	}
#line 1621
	if (narg > 3) {
#line 1621
		recursivep = va_arg(ARGS,cl_object);
#line 1621
	} else {
#line 1621
		recursivep = ECL_NIL;
#line 1621
	}
#line 1621
  strm = stream_or_default_input(strm);
#ifdef ECL_CLOS_STREAMS
  if (!ECL_ANSI_STREAM_P(strm)) {
          value0 = _ecl_funcall2(ECL_SYM("GRAY::STREAM-READ-LINE",1637), strm);
          value1 = ecl_nth_value(the_env, 1);
          if (!Null(value1)) {
                  if (!Null(eof_errorp))
                          FEend_of_file(strm);
                  value0 = eof_value;
                  value1 = ECL_T;
          }
          goto OUTPUT;
  }
#endif
  token = si_get_buffer_string();
  do {
          c = ecl_read_char(strm);
          if (c == EOF || c == '\n')
                  break;
          ecl_string_push_extend(token, c);
  } while(1);
  if (c == EOF && TOKEN_STRING_FILLP(token) == 0) {
          if (!Null(eof_errorp))
                  FEend_of_file(strm);
          value0 = eof_value;
          value1 = ECL_T;
  } else {
#ifdef ECL_NEWLINE_IS_CRLF    /* From \r\n, ignore \r */
          if (TOKEN_STRING_FILLP(token) > 0 &&
              TOKEN_STRING_CHAR_CMP(token,TOKEN_STRING_FILLP(token)-1,'\r'))
                  TOKEN_STRING_FILLP(token)--;
#endif
#ifdef ECL_NEWLINE_IS_LFCR    /* From \n\r, ignore \r */
          ecl_read_char(strm);
#endif
          value0 = cl_copy_seq(token);
          value1 = (c == EOF? ECL_T : ECL_NIL);
  }
  si_put_buffer_string(token);
 OUTPUT:
  {
#line 1661
	#line 1661
	cl_object __value0 = value0;
#line 1661
	cl_object __value1 = value1;
#line 1661
	the_env->nvalues = 2;
#line 1661
	the_env->values[1] = __value1;
#line 1661
	return __value0;
#line 1661
}

  }

#line 1664
cl_object cl_read_char(cl_narg narg, ...)
{
#line 1664

  int c;
  cl_object output;
  #line 1668
	const cl_env_ptr the_env = ecl_process_env();
#line 1668
	cl_object strm;
#line 1668
	cl_object eof_errorp;
#line 1668
	cl_object eof_value;
#line 1668
	cl_object recursivep;
#line 1668
	va_list ARGS;
	va_start(ARGS, narg);
#line 1668
	if (ecl_unlikely(narg < 0|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(692));
#line 1668
	if (narg > 0) {
#line 1668
		strm = va_arg(ARGS,cl_object);
#line 1668
	} else {
#line 1668
		strm = ECL_NIL;
#line 1668
	}
#line 1668
	if (narg > 1) {
#line 1668
		eof_errorp = va_arg(ARGS,cl_object);
#line 1668
	} else {
#line 1668
		eof_errorp = ECL_T;
#line 1668
	}
#line 1668
	if (narg > 2) {
#line 1668
		eof_value = va_arg(ARGS,cl_object);
#line 1668
	} else {
#line 1668
		eof_value = ECL_NIL;
#line 1668
	}
#line 1668
	if (narg > 3) {
#line 1668
		recursivep = va_arg(ARGS,cl_object);
#line 1668
	} else {
#line 1668
		recursivep = ECL_NIL;
#line 1668
	}
#line 1668
  strm = stream_or_default_input(strm);
  c = ecl_read_char(strm);
  if (c != EOF)
          output = ECL_CODE_CHAR(c);
  else if (Null(eof_errorp))
          output = eof_value;
  else
          FEend_of_file(strm);
  {
#line 1676
	#line 1676
	cl_object __value0 = output;
#line 1676
	the_env->nvalues = 1;
#line 1676
	return __value0;
#line 1676
}

  }

#line 1679
cl_object cl_unread_char(cl_narg narg, cl_object c, ...)
{
#line 1679

  #line 1681
	const cl_env_ptr the_env = ecl_process_env();
#line 1681
	cl_object strm;
#line 1681
	va_list ARGS;
	va_start(ARGS, c);
#line 1681
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(884));
#line 1681
	if (narg > 1) {
#line 1681
		strm = va_arg(ARGS,cl_object);
#line 1681
	} else {
#line 1681
		strm = ECL_NIL;
#line 1681
	}
#line 1681
  /* INV: unread_char() checks the type `c' */
  strm = stream_or_default_input(strm);
  ecl_unread_char(ecl_char_code(c), strm);
  {
#line 1684
	#line 1684
	cl_object __value0 = ECL_NIL;
#line 1684
	the_env->nvalues = 1;
#line 1684
	return __value0;
#line 1684
}

  }

#line 1687
cl_object cl_peek_char(cl_narg narg, ...)
{
#line 1687

  int c;
  cl_object rtbl = ecl_current_readtable();
  #line 1691
	const cl_env_ptr the_env = ecl_process_env();
#line 1691
	cl_object peek_type;
#line 1691
	cl_object strm;
#line 1691
	cl_object eof_errorp;
#line 1691
	cl_object eof_value;
#line 1691
	cl_object recursivep;
#line 1691
	va_list ARGS;
	va_start(ARGS, narg);
#line 1691
	if (ecl_unlikely(narg < 0|| narg > 5)) FEwrong_num_arguments(ecl_make_fixnum(639));
#line 1691
	if (narg > 0) {
#line 1691
		peek_type = va_arg(ARGS,cl_object);
#line 1691
	} else {
#line 1691
		peek_type = ECL_NIL;
#line 1691
	}
#line 1691
	if (narg > 1) {
#line 1691
		strm = va_arg(ARGS,cl_object);
#line 1691
	} else {
#line 1691
		strm = ECL_NIL;
#line 1691
	}
#line 1691
	if (narg > 2) {
#line 1691
		eof_errorp = va_arg(ARGS,cl_object);
#line 1691
	} else {
#line 1691
		eof_errorp = ECL_T;
#line 1691
	}
#line 1691
	if (narg > 3) {
#line 1691
		eof_value = va_arg(ARGS,cl_object);
#line 1691
	} else {
#line 1691
		eof_value = ECL_NIL;
#line 1691
	}
#line 1691
	if (narg > 4) {
#line 1691
		recursivep = va_arg(ARGS,cl_object);
#line 1691
	} else {
#line 1691
		recursivep = ECL_NIL;
#line 1691
	}
#line 1691
  strm = stream_or_default_input(strm);
  c = ecl_peek_char(strm);
  if (c != EOF && !Null(peek_type)) {
          if (peek_type == ECL_T) {
                  do {
                          /* If the character is not a whitespace, output */
                          if (ecl_readtable_get(rtbl, c, NULL) != cat_whitespace)
                                  break;
                          /* Otherwise, read the whitespace and peek the
                           * next character */
                          ecl_read_char(strm);
                          c = ecl_peek_char(strm);
                  } while (c != EOF);
          } else {
                  do {
                          /* If the character belongs to the given class,
                           * we're done. */
                          if (ecl_char_eq(ECL_CODE_CHAR(c), peek_type))
                                  break;
                          /* Otherwise, consume the character and
                           * peek the next one. */
                          ecl_read_char(strm);
                          c = ecl_peek_char(strm);
                  } while (c != EOF);
          }
  }
  if (c != EOF) {
          eof_value = ECL_CODE_CHAR(c);
  } else if (!Null(eof_errorp)) {
          FEend_of_file(strm);
  }
  {
#line 1722
	#line 1722
	cl_object __value0 = eof_value;
#line 1722
	the_env->nvalues = 1;
#line 1722
	return __value0;
#line 1722
}

  }

#line 1725
cl_object cl_listen(cl_narg narg, ...)
{
#line 1725

  #line 1727
	const cl_env_ptr the_env = ecl_process_env();
#line 1727
	cl_object strm;
#line 1727
	va_list ARGS;
	va_start(ARGS, narg);
#line 1727
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(485));
#line 1727
	if (narg > 0) {
#line 1727
		strm = va_arg(ARGS,cl_object);
#line 1727
	} else {
#line 1727
		strm = ECL_NIL;
#line 1727
	}
#line 1727
  strm = stream_or_default_input(strm);
  {
#line 1728
	#line 1728
	cl_object __value0 = ((ecl_listen_stream(strm) == ECL_LISTEN_AVAILABLE)? ECL_T : ECL_NIL);
#line 1728
	the_env->nvalues = 1;
#line 1728
	return __value0;
#line 1728
}

  }

#line 1731
cl_object cl_read_char_no_hang(cl_narg narg, ...)
{
#line 1731

  int f;
  #line 1734
	const cl_env_ptr the_env = ecl_process_env();
#line 1734
	cl_object strm;
#line 1734
	cl_object eof_errorp;
#line 1734
	cl_object eof_value;
#line 1734
	cl_object recursivep;
#line 1734
	va_list ARGS;
	va_start(ARGS, narg);
#line 1734
	if (ecl_unlikely(narg < 0|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(693));
#line 1734
	if (narg > 0) {
#line 1734
		strm = va_arg(ARGS,cl_object);
#line 1734
	} else {
#line 1734
		strm = ECL_NIL;
#line 1734
	}
#line 1734
	if (narg > 1) {
#line 1734
		eof_errorp = va_arg(ARGS,cl_object);
#line 1734
	} else {
#line 1734
		eof_errorp = ECL_T;
#line 1734
	}
#line 1734
	if (narg > 2) {
#line 1734
		eof_value = va_arg(ARGS,cl_object);
#line 1734
	} else {
#line 1734
		eof_value = ECL_NIL;
#line 1734
	}
#line 1734
	if (narg > 3) {
#line 1734
		recursivep = va_arg(ARGS,cl_object);
#line 1734
	} else {
#line 1734
		recursivep = ECL_NIL;
#line 1734
	}
#line 1734
  strm = stream_or_default_input(strm);
#ifdef ECL_CLOS_STREAMS
  if (!ECL_ANSI_STREAM_P(strm)) {
          cl_object output =
                  _ecl_funcall2(ECL_SYM("GRAY::STREAM-READ-CHAR-NO-HANG",1636), strm);
          if (output == ECL_SYM(":EOF",1228))
                  goto END_OF_FILE;
          {
#line 1741
	#line 1741
	cl_object __value0 = output;
#line 1741
	the_env->nvalues = 1;
#line 1741
	return __value0;
#line 1741
}
;
  }
#endif
  f = ecl_listen_stream(strm);
  if (f == ECL_LISTEN_AVAILABLE) {
          int c = ecl_read_char(strm);
          if (c != EOF) {
                  {
#line 1748
	#line 1748
	cl_object __value0 = ECL_CODE_CHAR(c);
#line 1748
	the_env->nvalues = 1;
#line 1748
	return __value0;
#line 1748
}
;
          }
  } else if (f == ECL_LISTEN_NO_CHAR) {
          {
#line 1751
	#line 1751
	cl_object __value0 = ECL_NIL;
#line 1751
	the_env->nvalues = 1;
#line 1751
	return __value0;
#line 1751
}
;
  }
  /* We reach here if there was an EOF */
 END_OF_FILE:
  if (Null(eof_errorp))
          {
#line 1756
	#line 1756
	cl_object __value0 = eof_value;
#line 1756
	the_env->nvalues = 1;
#line 1756
	return __value0;
#line 1756
}

          else
                  FEend_of_file(strm);
  }

#line 1761
cl_object cl_clear_input(cl_narg narg, ...)
{
#line 1761

  #line 1763
	const cl_env_ptr the_env = ecl_process_env();
#line 1763
	cl_object strm;
#line 1763
	va_list ARGS;
	va_start(ARGS, narg);
#line 1763
	if (ecl_unlikely(narg < 0|| narg > 1)) FEwrong_num_arguments(ecl_make_fixnum(226));
#line 1763
	if (narg > 0) {
#line 1763
		strm = va_arg(ARGS,cl_object);
#line 1763
	} else {
#line 1763
		strm = ECL_NIL;
#line 1763
	}
#line 1763
  strm = stream_or_default_input(strm);
  ecl_clear_input(strm);
  {
#line 1765
	#line 1765
	cl_object __value0 = ECL_NIL;
#line 1765
	the_env->nvalues = 1;
#line 1765
	return __value0;
#line 1765
}

  }

#line 1768
cl_object cl_read_byte(cl_narg narg, cl_object binary_input_stream, ...)
{
#line 1768

  cl_object c;
  #line 1771
	const cl_env_ptr the_env = ecl_process_env();
#line 1771
	cl_object eof_errorp;
#line 1771
	cl_object eof_value;
#line 1771
	va_list ARGS;
	va_start(ARGS, binary_input_stream);
#line 1771
	if (ecl_unlikely(narg < 1|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(691));
#line 1771
	if (narg > 1) {
#line 1771
		eof_errorp = va_arg(ARGS,cl_object);
#line 1771
	} else {
#line 1771
		eof_errorp = ECL_T;
#line 1771
	}
#line 1771
	if (narg > 2) {
#line 1771
		eof_value = va_arg(ARGS,cl_object);
#line 1771
	} else {
#line 1771
		eof_value = ECL_NIL;
#line 1771
	}
#line 1771
  c = ecl_read_byte(binary_input_stream);
  if (c == ECL_NIL) {
          if (Null(eof_errorp))
                  {
#line 1774
	#line 1774
	cl_object __value0 = eof_value;
#line 1774
	the_env->nvalues = 1;
#line 1774
	return __value0;
#line 1774
}

                  else
                          FEend_of_file(binary_input_stream);
  }
  {
#line 1778
	#line 1778
	cl_object __value0 = c;
#line 1778
	the_env->nvalues = 1;
#line 1778
	return __value0;
#line 1778
}

  }

#line 1781
cl_object cl_read_sequence(cl_narg narg, cl_object sequence, cl_object stream, ...)
{
#line 1781

  #line 1783
	const cl_env_ptr the_env = ecl_process_env();
#line 1783
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1310), (cl_object)(cl_symbols+1225)};
	cl_object start;
	cl_object end;
#line 1783
	cl_object KEY_VARS[4];
#line 1783
	ecl_va_list ARGS;
	ecl_va_start(ARGS, stream, narg, 2);
#line 1783
	if (ecl_unlikely(narg < 2)) FEwrong_num_arguments(ecl_make_fixnum(698));
#line 1783
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 1783
	if (KEY_VARS[2]==ECL_NIL) {
#line 1783
	  start = ecl_make_fixnum(0);
	} else {
#line 1783
	  start = KEY_VARS[0];
	}
#line 1783
	if (KEY_VARS[3]==ECL_NIL) {
#line 1783
	  end = ECL_NIL;
	} else {
#line 1783
	  end = KEY_VARS[1];
	}
#line 1783
#ifdef ECL_CLOS_STREAMS
  if (!ECL_ANSI_STREAM_P(stream))
  return funcall(5, ECL_SYM("GRAY::STREAM-READ-SEQUENCE",1638), stream, sequence, start, end);
  else
#endif
          return si_do_read_sequence(sequence, stream, start, end);
  }


#line 1792
cl_object cl_copy_readtable(cl_narg narg, ...)
{
#line 1792

  #line 1794
	const cl_env_ptr the_env = ecl_process_env();
#line 1794
	cl_object from;
#line 1794
	cl_object to;
#line 1794
	va_list ARGS;
	va_start(ARGS, narg);
#line 1794
	if (ecl_unlikely(narg < 0|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(259));
#line 1794
	if (narg > 0) {
#line 1794
		from = va_arg(ARGS,cl_object);
#line 1794
	} else {
#line 1794
		from = ecl_current_readtable();
#line 1794
	}
#line 1794
	if (narg > 1) {
#line 1794
		to = va_arg(ARGS,cl_object);
#line 1794
	} else {
#line 1794
		to = ECL_NIL;
#line 1794
	}
#line 1794
  if (Null(from)) {
          to = ecl_copy_readtable(cl_core.standard_readtable, to);
  } else {
          to = ecl_copy_readtable(from, to);
  }
  {
#line 1799
	#line 1799
	cl_object __value0 = to;
#line 1799
	the_env->nvalues = 1;
#line 1799
	return __value0;
#line 1799
}

  }

cl_object
cl_readtable_case(cl_object r)
{
        assert_type_readtable(ecl_make_fixnum(/*READTABLE-CASE*/701), 1, r);
        switch (r->readtable.read_case) {
                case ecl_case_upcase: r = ECL_SYM(":UPCASE",1322); break;
                case ecl_case_downcase: r = ECL_SYM(":DOWNCASE",1223); break;
                case ecl_case_invert: r = ECL_SYM(":INVERT",1259); break;
                case ecl_case_preserve: r = ECL_SYM(":PRESERVE",1288);
        }
        {
#line 1812
	const cl_env_ptr the_env = ecl_process_env();
#line 1812
	#line 1812
	cl_object __value0 = r;
#line 1812
	the_env->nvalues = 1;
#line 1812
	return __value0;
#line 1812
}

                }

static void
error_locked_readtable(cl_object r)
{
        cl_error(3,
                 make_constant_base_string("Change readtable"),
                 make_constant_base_string("Cannot modify locked readtable ~A."),
                 r);
}

cl_object
si_readtable_case_set(cl_object r, cl_object mode)
{
        assert_type_readtable(ecl_make_fixnum(/*READTABLE-CASE*/701), 1, r);
        if (r->readtable.locked) {
                error_locked_readtable(r);
        }
        if (mode == ECL_SYM(":UPCASE",1322)) {
                r->readtable.read_case = ecl_case_upcase;
        } else if (mode == ECL_SYM(":DOWNCASE",1223)) {
                r->readtable.read_case = ecl_case_downcase;
        } else if (mode == ECL_SYM(":PRESERVE",1288)) {
                r->readtable.read_case = ecl_case_preserve;
        } else if (mode == ECL_SYM(":INVERT",1259)) {
                r->readtable.read_case = ecl_case_invert;
        } else {
                const char *type = "(member :upcase :downcase :preserve :invert)";
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::READTABLE-CASE-SET*/1126), 2,
                                     mode, ecl_read_from_cstring(type));
        }
        {
#line 1844
	const cl_env_ptr the_env = ecl_process_env();
#line 1844
	#line 1844
	cl_object __value0 = mode;
#line 1844
	the_env->nvalues = 1;
#line 1844
	return __value0;
#line 1844
}

                }

cl_object
cl_readtablep(cl_object readtable)
{
        {
#line 1850
	const cl_env_ptr the_env = ecl_process_env();
#line 1850
	#line 1850
	cl_object __value0 = (ECL_READTABLEP(readtable) ? ECL_T : ECL_NIL);
#line 1850
	the_env->nvalues = 1;
#line 1850
	return __value0;
#line 1850
}

                }

int
ecl_readtable_get(cl_object readtable, int c, cl_object *macro_or_table)
{
        cl_object m;
        enum ecl_chattrib cat;
#ifdef ECL_UNICODE
        if (c >= RTABSIZE) {
                cl_object hash = readtable->readtable.hash;
                cat = cat_constituent;
                m = ECL_NIL;
                if (!Null(hash)) {
                        cl_object pair = ecl_gethash_safe(ECL_CODE_CHAR(c), hash, ECL_NIL);
                        if (!Null(pair)) {
                                cat = ecl_fixnum(ECL_CONS_CAR(pair));
                                m = ECL_CONS_CDR(pair);
                        }
                }
        } else
#endif
                {
                        m = readtable->readtable.table[c].dispatch;
                        cat = readtable->readtable.table[c].syntax_type;
                }
        if (macro_or_table) *macro_or_table = m;
        return cat;
}

void
ecl_readtable_set(cl_object readtable, int c, enum ecl_chattrib cat,
                  cl_object macro_or_table)
{
        if (readtable->readtable.locked) {
                error_locked_readtable(readtable);
        }
#ifdef ECL_UNICODE
        if (c >= RTABSIZE) {
                cl_object hash = readtable->readtable.hash;
                if (Null(hash)) {
                        hash = cl__make_hash_table(ECL_SYM("EQL",334), ecl_make_fixnum(128),
                                                   cl_core.rehash_size,
                                                   cl_core.rehash_threshold);
                        readtable->readtable.hash = hash;
                }
                _ecl_sethash(ECL_CODE_CHAR(c), hash,
                             CONS(ecl_make_fixnum(cat), macro_or_table));
        } else
#endif
                {
                        readtable->readtable.table[c].dispatch = macro_or_table;
                        readtable->readtable.table[c].syntax_type = cat;
                }
}

bool
ecl_invalid_character_p(int c)
{
        return (c <= 32) || (c == 127);
}

#line 1914
cl_object cl_set_syntax_from_char(cl_narg narg, cl_object tochr, cl_object fromchr, ...)
{
#line 1914

  enum ecl_chattrib cat;
  cl_object dispatch;
  cl_fixnum fc, tc;
  #line 1919
	const cl_env_ptr the_env = ecl_process_env();
#line 1919
	cl_object tordtbl;
#line 1919
	cl_object fromrdtbl;
#line 1919
	va_list ARGS;
	va_start(ARGS, fromchr);
#line 1919
	if (ecl_unlikely(narg < 2|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(749));
#line 1919
	if (narg > 2) {
#line 1919
		tordtbl = va_arg(ARGS,cl_object);
#line 1919
	} else {
#line 1919
		tordtbl = ecl_current_readtable();
#line 1919
	}
#line 1919
	if (narg > 3) {
#line 1919
		fromrdtbl = va_arg(ARGS,cl_object);
#line 1919
	} else {
#line 1919
		fromrdtbl = ECL_NIL;
#line 1919
	}
#line 1919
  if (tordtbl->readtable.locked) {
          error_locked_readtable(tordtbl);
  }
  if (Null(fromrdtbl))
          fromrdtbl = cl_core.standard_readtable;
  assert_type_readtable(ecl_make_fixnum(/*READTABLE-CASE*/701), 1, tordtbl);
  assert_type_readtable(ecl_make_fixnum(/*READTABLE-CASE*/701), 2, fromrdtbl);
  fc = ecl_char_code(fromchr);
  tc = ecl_char_code(tochr);
  
  cat = ecl_readtable_get(fromrdtbl, fc, &dispatch);
  if (ECL_READTABLEP(dispatch)) {
          dispatch = si_copy_hash_table(dispatch);
  }
  ecl_readtable_set(tordtbl, tc, cat, dispatch);
  {
#line 1934
	#line 1934
	cl_object __value0 = ECL_T;
#line 1934
	the_env->nvalues = 1;
#line 1934
	return __value0;
#line 1934
}

  }

#line 1938
cl_object cl_set_macro_character(cl_narg narg, cl_object c, cl_object function, ...)
{
#line 1938

  #line 1940
	const cl_env_ptr the_env = ecl_process_env();
#line 1940
	cl_object non_terminating_p;
#line 1940
	cl_object readtable;
#line 1940
	va_list ARGS;
	va_start(ARGS, function);
#line 1940
	if (ecl_unlikely(narg < 2|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(747));
#line 1940
	if (narg > 2) {
#line 1940
		non_terminating_p = va_arg(ARGS,cl_object);
#line 1940
	} else {
#line 1940
		non_terminating_p = ECL_NIL;
#line 1940
	}
#line 1940
	if (narg > 3) {
#line 1940
		readtable = va_arg(ARGS,cl_object);
#line 1940
	} else {
#line 1940
		readtable = ecl_current_readtable();
#line 1940
	}
#line 1940
  ecl_readtable_set(readtable, ecl_char_code(c),
                    Null(non_terminating_p)?
                    cat_terminating :
                    cat_non_terminating,
                    function);
  {
#line 1945
	#line 1945
	cl_object __value0 = ECL_T;
#line 1945
	the_env->nvalues = 1;
#line 1945
	return __value0;
#line 1945
}

  }

#line 1948
cl_object cl_get_macro_character(cl_narg narg, cl_object c, ...)
{
#line 1948

  enum ecl_chattrib cat;
  cl_object dispatch;
  #line 1952
	const cl_env_ptr the_env = ecl_process_env();
#line 1952
	cl_object readtable;
#line 1952
	va_list ARGS;
	va_start(ARGS, c);
#line 1952
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(407));
#line 1952
	if (narg > 1) {
#line 1952
		readtable = va_arg(ARGS,cl_object);
#line 1952
	} else {
#line 1952
		readtable = ecl_current_readtable();
#line 1952
	}
#line 1952
  if (Null(readtable))
  readtable = cl_core.standard_readtable;
  cat = ecl_readtable_get(readtable, ecl_char_code(c), &dispatch);
  if (ECL_HASH_TABLE_P(dispatch))
          dispatch = cl_core.dispatch_reader;
  {
#line 1957
	#line 1957
	cl_object __value0 = dispatch;
#line 1957
	cl_object __value1 = ((cat == cat_non_terminating)? ECL_T : ECL_NIL);
#line 1957
	the_env->nvalues = 2;
#line 1957
	the_env->values[1] = __value1;
#line 1957
	return __value0;
#line 1957
}

  }

#line 1961
cl_object cl_make_dispatch_macro_character(cl_narg narg, cl_object chr, ...)
{
#line 1961

  enum ecl_chattrib cat;
  cl_object table;
  int c;
  #line 1966
	const cl_env_ptr the_env = ecl_process_env();
#line 1966
	cl_object non_terminating_p;
#line 1966
	cl_object readtable;
#line 1966
	va_list ARGS;
	va_start(ARGS, chr);
#line 1966
	if (ecl_unlikely(narg < 1|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(526));
#line 1966
	if (narg > 1) {
#line 1966
		non_terminating_p = va_arg(ARGS,cl_object);
#line 1966
	} else {
#line 1966
		non_terminating_p = ECL_NIL;
#line 1966
	}
#line 1966
	if (narg > 2) {
#line 1966
		readtable = va_arg(ARGS,cl_object);
#line 1966
	} else {
#line 1966
		readtable = ecl_current_readtable();
#line 1966
	}
#line 1966
  assert_type_readtable(ecl_make_fixnum(/*MAKE-DISPATCH-MACRO-CHARACTER*/526), 3, readtable);
  c = ecl_char_code(chr);
  cat = Null(non_terminating_p)? cat_terminating : cat_non_terminating;
  table = cl__make_hash_table(ECL_SYM("EQL",334), ecl_make_fixnum(128),
                              cl_core.rehash_size,
                              cl_core.rehash_threshold);
  ecl_readtable_set(readtable, c, cat, table);
  {
#line 1973
	#line 1973
	cl_object __value0 = ECL_T;
#line 1973
	the_env->nvalues = 1;
#line 1973
	return __value0;
#line 1973
}

  }

#line 1977
cl_object cl_set_dispatch_macro_character(cl_narg narg, cl_object dspchr, cl_object subchr, cl_object fnc, ...)
{
#line 1977

  cl_object table;
  cl_fixnum subcode;
  #line 1981
	const cl_env_ptr the_env = ecl_process_env();
#line 1981
	cl_object readtable;
#line 1981
	va_list ARGS;
	va_start(ARGS, fnc);
#line 1981
	if (ecl_unlikely(narg < 3|| narg > 4)) FEwrong_num_arguments(ecl_make_fixnum(745));
#line 1981
	if (narg > 3) {
#line 1981
		readtable = va_arg(ARGS,cl_object);
#line 1981
	} else {
#line 1981
		readtable = ecl_current_readtable();
#line 1981
	}
#line 1981
  assert_type_readtable(ecl_make_fixnum(/*SET-DISPATCH-MACRO-CHARACTER*/745), 4, readtable);
  ecl_readtable_get(readtable, ecl_char_code(dspchr), &table);
  unlikely_if (readtable->readtable.locked) {
          error_locked_readtable(readtable);
  }
  unlikely_if (!ECL_HASH_TABLE_P(table)) {
          FEerror("~S is not a dispatch character.", 1, dspchr);
  }
  subcode = ecl_char_code(subchr);
  if (Null(fnc)) {
          ecl_remhash(ECL_CODE_CHAR(subcode), table);
  } else {
          _ecl_sethash(ECL_CODE_CHAR(subcode), table, fnc);
  }
  if (ecl_lower_case_p(subcode)) {
          subcode = ecl_char_upcase(subcode);
  } else if (ecl_upper_case_p(subcode)) {
          subcode = ecl_char_downcase(subcode);
  }
  if (Null(fnc)) {
          ecl_remhash(ECL_CODE_CHAR(subcode), table);
  } else {
          _ecl_sethash(ECL_CODE_CHAR(subcode), table, fnc);
  }
  {
#line 2005
	#line 2005
	cl_object __value0 = ECL_T;
#line 2005
	the_env->nvalues = 1;
#line 2005
	return __value0;
#line 2005
}

  }

#line 2009
cl_object cl_get_dispatch_macro_character(cl_narg narg, cl_object dspchr, cl_object subchr, ...)
{
#line 2009

  cl_object table;
  cl_fixnum c;
  #line 2013
	const cl_env_ptr the_env = ecl_process_env();
#line 2013
	cl_object readtable;
#line 2013
	va_list ARGS;
	va_start(ARGS, subchr);
#line 2013
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(404));
#line 2013
	if (narg > 2) {
#line 2013
		readtable = va_arg(ARGS,cl_object);
#line 2013
	} else {
#line 2013
		readtable = ecl_current_readtable();
#line 2013
	}
#line 2013
  if (Null(readtable)) {
          readtable = cl_core.standard_readtable;
  }
  assert_type_readtable(ecl_make_fixnum(/*GET-DISPATCH-MACRO-CHARACTER*/404), 3, readtable);
  c = ecl_char_code(dspchr);
  ecl_readtable_get(readtable, c, &table);
  unlikely_if (!ECL_HASH_TABLE_P(table)) {
          FEerror("~S is not a dispatch character.", 1, dspchr);
  }
  c = ecl_char_code(subchr);
  
  /* Since macro characters may take a number as argument, it is
     not allowed to turn digits into dispatch macro characters */
  if (ecl_digitp(c, 10) >= 0)
          {
#line 2027
	#line 2027
	cl_object __value0 = ECL_NIL;
#line 2027
	the_env->nvalues = 1;
#line 2027
	return __value0;
#line 2027
}

                  {
#line 2028
	#line 2028
	cl_object __value0 = ecl_gethash_safe(subchr, table, ECL_NIL);
#line 2028
	the_env->nvalues = 1;
#line 2028
	return __value0;
#line 2028
}

                  }

cl_object
si_standard_readtable()
{
        {
#line 2034
	const cl_env_ptr the_env = ecl_process_env();
#line 2034
	#line 2034
	cl_object __value0 = cl_core.standard_readtable;
#line 2034
	the_env->nvalues = 1;
#line 2034
	return __value0;
#line 2034
}

                }

#line 2037
cl_object si_readtable_lock(cl_narg narg, cl_object r, ...)
{
#line 2037

  cl_object output;
  #line 2040
	const cl_env_ptr the_env = ecl_process_env();
#line 2040
	cl_object yesno;
#line 2040
	va_list ARGS;
	va_start(ARGS, r);
#line 2040
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(1719));
#line 2040
	if (narg > 1) {
#line 2040
		yesno = va_arg(ARGS,cl_object);
#line 2040
	} else {
#line 2040
		yesno = ECL_NIL;
#line 2040
	}
#line 2040
  assert_type_readtable(ecl_make_fixnum(/*EXT::READTABLE-LOCK*/1719), 1, r);
  output = (r->readtable.locked)? ECL_T : ECL_NIL;
  if (narg > 1) {
          r->readtable.locked = !Null(yesno);
  }
  {
#line 2045
	#line 2045
	cl_object __value0 = output;
#line 2045
	the_env->nvalues = 1;
#line 2045
	return __value0;
#line 2045
}

  }

static void
extra_argument(int c, cl_object stream, cl_object d)
{
        FEreader_error("~S is an extra argument for the #~C readmacro.",
                       stream, 2, d, ECL_CODE_CHAR(c));
}


#define    make_cf2(f)    ecl_make_cfun((f), ECL_NIL, NULL, 2)
#define    make_cf3(f)    ecl_make_cfun((f), ECL_NIL, NULL, 3)

void
init_read(void)
{
        struct ecl_readtable_entry *rtab;
        cl_object r;
        int i;
        
        cl_core.standard_readtable = r = ecl_alloc_object(t_readtable);
        r->readtable.locked = 0;
        r->readtable.read_case = ecl_case_upcase;
        r->readtable.table = rtab
                = (struct ecl_readtable_entry *)
                ecl_alloc(RTABSIZE * sizeof(struct ecl_readtable_entry));
        for (i = 0;  i < RTABSIZE;  i++) {
                rtab[i].syntax_type = cat_constituent;
                rtab[i].dispatch = ECL_NIL;
        }
#ifdef ECL_UNICODE
        r->readtable.hash = ECL_NIL;
#endif
        
        cl_core.dispatch_reader = make_cf2(dispatch_reader_fun);
        
        ecl_readtable_set(r, '\t', cat_whitespace, ECL_NIL);
        ecl_readtable_set(r, '\n', cat_whitespace, ECL_NIL);
        ecl_readtable_set(r, '\f', cat_whitespace, ECL_NIL);
        ecl_readtable_set(r, '\r', cat_whitespace, ECL_NIL);
        ecl_readtable_set(r, ' ', cat_whitespace, ECL_NIL);
        
        ecl_readtable_set(r, '"', cat_terminating,
                          make_cf2(double_quote_reader));
        
        ecl_readtable_set(r, '\'', cat_terminating,
                          make_cf2(single_quote_reader));
        ecl_readtable_set(r, '(', cat_terminating,
                          make_cf2(left_parenthesis_reader));
        ecl_readtable_set(r, ')', cat_terminating,
                          make_cf2(right_parenthesis_reader));
        ecl_readtable_set(r, ',', cat_terminating,
                          make_cf2(comma_reader));
        ecl_readtable_set(r, ';', cat_terminating,
                          make_cf2(semicolon_reader));
        ecl_readtable_set(r, '\\', cat_single_escape, ECL_NIL);
        ecl_readtable_set(r, '`', cat_terminating,
                          make_cf2(backquote_reader));
        ecl_readtable_set(r, '|', cat_multiple_escape, ECL_NIL);
        
        cl_core.default_dispatch_macro = make_cf3(default_dispatch_macro_fun);
        
        cl_make_dispatch_macro_character(3, ECL_CODE_CHAR('#'),
                                         ECL_T /* non terminating */, r);
        
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('C'),
                                        make_cf3(sharp_C_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('\\'),
                                        make_cf3(sharp_backslash_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('\''),
                                        make_cf3(sharp_single_quote_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('('),
                                        make_cf3(sharp_left_parenthesis_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('*'),
                                        make_cf3(sharp_asterisk_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR(':'),
                                        make_cf3(sharp_colon_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('.'),
                                        make_cf3(sharp_dot_reader), r);
        /*  Used for fasload only. */
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('B'),
                                        make_cf3(sharp_B_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('O'),
                                        make_cf3(sharp_O_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('X'),
                                        make_cf3(sharp_X_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('R'),
                                        make_cf3(sharp_R_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('A'),
                                        ECL_SYM("SI::SHARP-A-READER",1136), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('S'),
                                        ECL_SYM("SI::SHARP-S-READER",1137), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('P'),
                                        make_cf3(sharp_P_reader), r);
        
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('='),
                                        make_cf3(sharp_eq_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('#'),
                                        make_cf3(sharp_sharp_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('+'),
                                        make_cf3(sharp_plus_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('-'),
                                        make_cf3(sharp_minus_reader), r);
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('|'),
                                        make_cf3(sharp_vertical_bar_reader), r);
        /*  This is specific to this implementation  */
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('$'),
                                        make_cf3(sharp_dollar_reader), r);
        /*  This is specific to this implementation  */
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('Y'),
                                        make_cf3(sharp_Y_reader), r);
        /*  This is specific to this implementation: ignore BOM  */
#ifdef ECL_UNICODE
        ecl_readtable_set(r, 0xfeff, cat_whitespace, ECL_NIL);
#endif
        
        /* Lock the standard read table so that we do not have to make copies
         * to keep it unchanged */
        r->readtable.locked = 1;
        
        init_backq();
        
        ECL_SET(ECL_SYM("*READTABLE*",65),
                r=ecl_copy_readtable(cl_core.standard_readtable, ECL_NIL));
        cl_set_dispatch_macro_character(4, ECL_CODE_CHAR('#'), ECL_CODE_CHAR('!'),
                                        ECL_NIL, r);
        ECL_SET(ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62), ECL_SYM("SINGLE-FLOAT",778));
        
        {
                cl_object var, val;
                var = cl_list(24,
                              ECL_SYM("*PRINT-PPRINT-DISPATCH*",54), /* See end of pprint.lsp */
                              ECL_SYM("*PRINT-ARRAY*",44),
                              ECL_SYM("*PRINT-BASE*",45),
                              ECL_SYM("*PRINT-CASE*",46),
                              ECL_SYM("*PRINT-CIRCLE*",47),
                              ECL_SYM("*PRINT-ESCAPE*",48),
                              ECL_SYM("*PRINT-GENSYM*",49),
                              ECL_SYM("*PRINT-LENGTH*",50),
                              ECL_SYM("*PRINT-LEVEL*",51),
                              ECL_SYM("*PRINT-LINES*",52),
                              ECL_SYM("*PRINT-MISER-WIDTH*",53),
                              ECL_SYM("*PRINT-PRETTY*",55),
                              ECL_SYM("*PRINT-RADIX*",56),
                              ECL_SYM("*PRINT-READABLY*",57),
                              ECL_SYM("*PRINT-RIGHT-MARGIN*",58),
                              ECL_SYM("*READ-BASE*",61),
                              ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62),
                              ECL_SYM("*READ-EVAL*",63),
                              ECL_SYM("*READ-SUPPRESS*",64),
                              ECL_SYM("*READTABLE*",65),
                              ECL_SYM("SI::*PRINT-PACKAGE*",1029),
                              ECL_SYM("SI::*PRINT-STRUCTURE*",1030),
                              ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031),
                              ECL_SYM("SI::*CIRCLE-COUNTER*",1014));
                val = cl_list(24,
                              /**pprint-dispatch-table**/ ECL_NIL,
                              /**print-array**/ ECL_T,
                              /**print-base**/ ecl_make_fixnum(10),
                              /**print-case**/ ECL_SYM(":DOWNCASE",1223),
                              /**print-circle**/ ECL_T,
                              /**print-escape**/ ECL_T,
                              /**print-gensym**/ ECL_T,
                              /**print-length**/ ECL_NIL,
                              /**print-level**/ ECL_NIL,
                              /**print-lines**/ ECL_NIL,
                              /**print-miser-width**/ ECL_NIL,
                              /**print-pretty**/ ECL_NIL,
                              /**print-radix**/ ECL_NIL,
                              /**print-readably**/ ECL_T,
                              /**print-right-margin**/ ECL_NIL,
                              /**read-base**/ ecl_make_fixnum(10),
                              /**read-default-float-format**/ ECL_SYM("SINGLE-FLOAT",778),
                              /**read-eval**/ ECL_T,
                              /**read-suppress**/ ECL_NIL,
                              /**readtable**/ cl_core.standard_readtable,
                              /*si::*print-package**/ cl_core.lisp_package,
                              /*si::*print-structure**/ ECL_T,
                              /*si::*sharp-eq-context**/ ECL_NIL,
                              /*si::*cicle-counter**/ ECL_NIL);
                ECL_SET(ECL_SYM("SI::+ECL-SYNTAX-PROGV-LIST+",1721), CONS(var,val));
                var = cl_list(23,
                              ECL_SYM("*PRINT-PPRINT-DISPATCH*",54), /* See end of pprint.lsp */
                              ECL_SYM("*PRINT-ARRAY*",44),
                              ECL_SYM("*PRINT-BASE*",45),
                              ECL_SYM("*PRINT-CASE*",46),
                              ECL_SYM("*PRINT-CIRCLE*",47),
                              ECL_SYM("*PRINT-ESCAPE*",48),
                              ECL_SYM("*PRINT-GENSYM*",49),
                              ECL_SYM("*PRINT-LENGTH*",50),
                              ECL_SYM("*PRINT-LEVEL*",51),
                              ECL_SYM("*PRINT-LINES*",52),
                              ECL_SYM("*PRINT-MISER-WIDTH*",53),
                              ECL_SYM("*PRINT-PRETTY*",55),
                              ECL_SYM("*PRINT-RADIX*",56),
                              ECL_SYM("*PRINT-READABLY*",57),
                              ECL_SYM("*PRINT-RIGHT-MARGIN*",58),
                              ECL_SYM("*READ-BASE*",61),
                              ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62),
                              ECL_SYM("*READ-EVAL*",63),
                              ECL_SYM("*READ-SUPPRESS*",64),
                              ECL_SYM("*READTABLE*",65),
                              ECL_SYM("*PACKAGE*",43),
                              ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031),
                              ECL_SYM("SI::*CIRCLE-COUNTER*",1014));
                val = cl_list(23,
                              /**pprint-dispatch-table**/ ECL_NIL,
                              /**print-array**/ ECL_T,
                              /**print-base**/ ecl_make_fixnum(10),
                              /**print-case**/ ECL_SYM(":UPCASE",1322),
                              /**print-circle**/ ECL_NIL,
                              /**print-escape**/ ECL_T,
                              /**print-gensym**/ ECL_T,
                              /**print-length**/ ECL_NIL,
                              /**print-level**/ ECL_NIL,
                              /**print-lines**/ ECL_NIL,
                              /**print-miser-width**/ ECL_NIL,
                              /**print-pretty**/ ECL_NIL,
                              /**print-radix**/ ECL_NIL,
                              /**print-readably**/ ECL_T,
                              /**print-right-margin**/ ECL_NIL,
                              /**read-base**/ ecl_make_fixnum(10),
                              /**read-default-float-format**/ ECL_SYM("SINGLE-FLOAT",778),
                              /**read-eval**/ ECL_T,
                              /**read-suppress**/ ECL_NIL,
                              /**readtable**/ cl_core.standard_readtable,
                              /**package**/ cl_core.user_package,
                              /*si::*sharp-eq-context**/ ECL_NIL,
                              /*si::*cicle-counter**/ ECL_NIL);
                ECL_SET(ECL_SYM("SI::+IO-SYNTAX-PROGV-LIST+",1720), CONS(var,val));
        }
}

/*
 *----------------------------------------------------------------------
 *
 * ecl_init_module --
 *     reads the data vector from stream into vector VV
 *
 * Results:
 *    a vector.
 *
 *----------------------------------------------------------------------
 */
cl_object
ecl_init_module(cl_object block, void (*entry_point)(cl_object))
{
        const cl_env_ptr env = ecl_process_env();
        volatile cl_object old_eptbc = env->packages_to_be_created;
        volatile cl_object x;
        cl_index i, len, perm_len, temp_len;
        cl_object in;
        cl_object *VV, *VVtemp = 0;
        
        if (block == NULL)
                block = ecl_make_codeblock();
        block->cblock.entry = entry_point;
        
        in = OBJNULL;
        ECL_UNWIND_PROTECT_BEGIN(env) {
                cl_index bds_ndx;
                cl_object progv_list;
                
                ecl_bds_bind(env, ECL_SYM("SI::*CBLOCK*",1013), block);
                env->packages_to_be_created_p = ECL_T;
                
                /* Communicate the library which Cblock we are using, and get
                 * back the amount of data to be processed.
                 */
                (*entry_point)(block);
                perm_len = block->cblock.data_size;
                temp_len = block->cblock.temp_data_size;
                len = perm_len + temp_len;
                
                if (block->cblock.data_text == 0 || block->cblock.data_text_size == 0) {
                        if (len) {
                                /* Code from COMPILE uses data in *compiler-constants* */
                                cl_object v = ECL_SYM_VAL(env,ECL_SYM("SI::*COMPILER-CONSTANTS*",1017));
                                unlikely_if (ecl_t_of(v) != t_vector ||
                                             v->vector.dim != len ||
                                             v->vector.elttype != ecl_aet_object)
                                        FEerror("Internal error: corrupted data in "
                                                "si::*compiler-constants*", 0);
                                VV = block->cblock.data = v->vector.self.t;
                                VVtemp = block->cblock.temp_data = 0;
                        }
                        goto NO_DATA_LABEL;
                }
                if (len == 0) {
                        VV = VVtemp = 0;
                        goto NO_DATA_LABEL;
                }
#ifdef ECL_DYNAMIC_VV
                VV = block->cblock.data = perm_len? (cl_object *)ecl_alloc(perm_len * sizeof(cl_object)) : NULL;
#else
                VV = block->cblock.data;
#endif
                memset(VV, 0, perm_len * sizeof(*VV));
                
                VVtemp = block->cblock.temp_data = temp_len? (cl_object *)ecl_alloc(temp_len * sizeof(cl_object)) : NULL;
                memset(VVtemp, 0, temp_len * sizeof(*VVtemp));
                
                /* Read all data for the library */
#ifdef ECL_EXTERNALIZABLE
                {
                        cl_object v = ecl_deserialize(block->cblock.data_text);
                        unlikely_if (v->vector.dim < len)
                                FEreader_error("Not enough data while loading"
                                               "binary file", in, 0);
                        memcpy(VV, v->vector.self.t, len * sizeof(cl_object));
                }
#else
                in = ecl_make_simple_base_string((char *)block->cblock.data_text,
                                                 block->cblock.data_text_size);
# ifdef ECL_UNICODE
                in = si_make_sequence_input_stream(3, in, ECL_SYM(":EXTERNAL-FORMAT",1236),
                                                   ECL_SYM(":UTF-8",1681));
# else
                in=ecl_make_string_input_stream(in, 0, block->cblock.data_text_size);
# endif
                progv_list = ECL_SYM_VAL(env, ECL_SYM("SI::+ECL-SYNTAX-PROGV-LIST+",1721));
                bds_ndx = ecl_progv(env, ECL_CONS_CAR(progv_list),
                                    ECL_CONS_CDR(progv_list));
                for (i = 0 ; i < len; i++) {
                        x = ecl_read_object(in);
                        if (x == OBJNULL)
                                break;
                        if (i < perm_len)
                                VV[i] = x;
                        else
                                VVtemp[i-perm_len] = x;
                }
                if (!Null(ECL_SYM_VAL(env, ECL_SYM("SI::*SHARP-EQ-CONTEXT*",1031)))) {
                        while (i--) {
                                if (i < perm_len) {
                                        VV[i] = patch_sharp(VV[i]);
                                } else {
                                        VVtemp[i-perm_len] = patch_sharp(VVtemp[i-perm_len]);
                                }
                        }
                }
                ecl_bds_unwind(env, bds_ndx);
                unlikely_if (i < len)
                        FEreader_error("Not enough data while loading"
                                       "binary file", in, 0);
                cl_close(1,in);
                in = OBJNULL;
#endif
        NO_DATA_LABEL:
                env->packages_to_be_created_p = ECL_NIL;
                
                for (i = 0; i < block->cblock.cfuns_size; i++) {
                        const struct ecl_cfun *prototype = block->cblock.cfuns+i;
                        cl_index fname_location = ecl_fixnum(prototype->block);
                        cl_object fname = VV[fname_location];
                        cl_index location = ecl_fixnum(prototype->name);
                        cl_object position = prototype->file_position;
                        int narg = prototype->narg;
                        VV[location] = narg<0?
                                ecl_make_cfun_va((cl_objectfn)prototype->entry,
                                                 fname, block) :
                                ecl_make_cfun((cl_objectfn_fixed)prototype->entry,
                                              fname, block, narg);
                        /* Add source file info */
                        if (position != ecl_make_fixnum(-1)) {
                                ecl_set_function_source_file_info(VV[location],
                                                                  block->cblock.source,
                                                                  position);
                        }
                }
                /* Execute top-level code */
                (*entry_point)(OBJNULL);
                x = cl_set_difference(2, env->packages_to_be_created, old_eptbc);
                old_eptbc = env->packages_to_be_created;
                unlikely_if (!Null(x)) {
                        CEerror(ECL_T,
                                Null(ECL_CONS_CDR(x))?
                                "Package ~A referenced in "
                                "compiled file~&  ~A~&but has not been created":
                                "The packages~&  ~A~&were referenced in "
                                "compiled file~&  ~A~&but have not been created",
                                2, x, block->cblock.name);
                }
                if (VVtemp) {
                        block->cblock.temp_data = NULL;
                        block->cblock.temp_data_size = 0;
                        ecl_dealloc(VVtemp);
                }
                ecl_bds_unwind1(env);
        } ECL_UNWIND_PROTECT_EXIT {
                if (in != OBJNULL)
                        cl_close(1,in);
                env->packages_to_be_created = old_eptbc;
                env->packages_to_be_created_p = ECL_NIL;
        } ECL_UNWIND_PROTECT_END;
        
        return block;
}
