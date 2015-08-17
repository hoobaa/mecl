#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/load.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    load.d -- Binary loader (contains also open_fasl_data).
*/
/*
    Copyright (c) 1990, Giuseppe Attardi and William F. Schelter.
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

#ifdef ENABLE_DLOPEN
cl_object
si_load_binary(cl_object filename, cl_object verbose,
               cl_object print, cl_object external_format)
{
	const cl_env_ptr the_env = ecl_process_env();
	cl_object block, map, array;
	cl_object basename;
	cl_object init_prefix, prefix;
	cl_object output;

	/* We need the full pathname */
	filename = cl_truename(filename);

	/* Try to load shared object file */
	block = ecl_library_open(filename, 1);
	if (block->cblock.handle == NULL) {
		output = ecl_library_error(block);
		goto OUTPUT;
	}

	/* Fist try to call "init_CODE()" */
        init_prefix = _ecl_library_default_entry();
        block->cblock.entry =
                ecl_library_symbol(block, (char *)init_prefix->base_string.self, 0);
	if (block->cblock.entry != NULL)
		goto GO_ON;

	/* Next try to call "init_FILE()" where FILE is the file name */
	prefix = ecl_symbol_value(ECL_SYM("SI::*INIT-FUNCTION-PREFIX*",1022));
        init_prefix = _ecl_library_init_prefix();
	if (Null(prefix)) {
                prefix = init_prefix;
        } else {
                prefix = si_base_string_concatenate(3,
                                                      init_prefix,
                                                      prefix,
                                                      make_constant_base_string("_"));
        }
	basename = cl_pathname_name(1,filename);
	basename = si_base_string_concatenate(2, prefix, cl_string_upcase(1, funcall(4, ECL_SYM("NSUBSTITUTE",599), ECL_CODE_CHAR('_'), ECL_CODE_CHAR('-'), basename)));
	block->cblock.entry = ecl_library_symbol(block, (char*)basename->base_string.self, 0);

	if (block->cblock.entry == NULL) {
		output = ecl_library_error(block);
		ecl_library_close(block);
		goto OUTPUT;
	}

GO_ON:
        /* Try to load the compiled data */
        map = si_get_cdata(filename);
        array = ecl_nth_value(the_env, 1);

        block->cblock.data_text = (char*)array->base_string.self;
        block->cblock.data_text_size = array->base_string.dim;

	/* Finally, perform initialization */
	ecl_init_module(block, (void (*)(cl_object))(block->cblock.entry));
	output = ECL_NIL;

        si_munmap(map);
OUTPUT:
	ecl_return1(the_env, output);
}
#endif /* !ENABLE_DLOPEN */

cl_object
si_load_source(cl_object source, cl_object verbose, cl_object print, cl_object external_format)
{
	cl_env_ptr the_env = ecl_process_env();
	cl_object x, strm;

	/* Source may be either a stream or a filename */
	if (ecl_t_of(source) != t_pathname && ecl_t_of(source) != t_base_string) {
		/* INV: if "source" is not a valid stream, file.d will complain */
		strm = source;
	} else {
		strm = ecl_open_stream(source, ecl_smm_input, ECL_NIL, ECL_NIL, 8,
				       ECL_STREAM_C_STREAM, external_format);
		if (Null(strm))
			{
#line 102
				const cl_env_ptr the_env = ecl_process_env();
#line 102
				#line 102
				cl_object __value0 = ECL_NIL;
#line 102
				the_env->nvalues = 1;
#line 102
				return __value0;
#line 102
			}

	}
	ECL_UNWIND_PROTECT_BEGIN(the_env) {
		cl_object form_index = ecl_make_fixnum(0);
                cl_object pathname = ECL_SYM_VAL(the_env, ECL_SYM("*LOAD-PATHNAME*",36));
		cl_object location = CONS(pathname, form_index);
		ecl_bds_bind(the_env, ECL_SYM("EXT::*SOURCE-LOCATION*",1180), location);
		for (;;) {
                        form_index = ecl_file_position(strm);
                        ECL_RPLACD(location, form_index);
			x = si_read_object_or_ignore(strm, OBJNULL);
			if (x == OBJNULL)
				break;
                        if (the_env->nvalues) {
                                si_eval_with_env(1, x);
                                if (print != ECL_NIL) {
                                        cl_write(1, x);
                                        cl_terpri(0);
                                }
                        }
		}
		ecl_bds_unwind1(the_env);
	} ECL_UNWIND_PROTECT_EXIT {
		/* We do not want to come back here if close_stream fails,
		   therefore, first we frs_pop() current jump point, then
		   try to close the stream, and then jump to next catch
		   point */
		if (strm != source)
			cl_close(3, strm, ECL_SYM(":ABORT",1195), ECL_SYM("T",1));
	} ECL_UNWIND_PROTECT_END;
	{
#line 132
		const cl_env_ptr the_env = ecl_process_env();
#line 132
		#line 132
		cl_object __value0 = ECL_NIL;
#line 132
		the_env->nvalues = 1;
#line 132
		return __value0;
#line 132
	}

}


cl_object
si_load_bytecodes(cl_object source, cl_object verbose, cl_object print, cl_object external_format)
{
	cl_env_ptr env = ecl_process_env();
	cl_object forms, strm;
	cl_object old_eptbc = env->packages_to_be_created;

	/* Source may be either a stream or a filename */
	if (ecl_t_of(source) != t_pathname && ecl_t_of(source) != t_base_string) {
		/* INV: if "source" is not a valid stream, file.d will complain */
		strm = source;
	} else {
		strm = ecl_open_stream(source, ecl_smm_input, ECL_NIL, ECL_NIL, 8,
				       ECL_STREAM_C_STREAM, external_format);
		if (Null(strm))
			{
#line 151
				const cl_env_ptr the_env = ecl_process_env();
#line 151
				#line 151
				cl_object __value0 = ECL_NIL;
#line 151
				the_env->nvalues = 1;
#line 151
				return __value0;
#line 151
			}

	}
	ECL_UNWIND_PROTECT_BEGIN(env) {
                {
                cl_object progv_list = ECL_SYM_VAL(env, ECL_SYM("SI::+ECL-SYNTAX-PROGV-LIST+",1721));
                cl_index bds_ndx = ecl_progv(env, ECL_CONS_CAR(progv_list),
                                             ECL_CONS_CDR(progv_list));
                env->packages_to_be_created_p = ECL_T;
                forms = cl_read(1, strm);
                env->packages_to_be_created_p = ECL_NIL;
                ecl_bds_unwind(env, bds_ndx);
                }
                while (!Null(forms)) {
                        if (ECL_LISTP(forms)) {
                                cl_object x = ECL_CONS_CAR(forms);
                                forms = ECL_CONS_CDR(forms);
                                if (ecl_t_of(x) == t_bytecodes) {
                                        _ecl_funcall1(x);
                                        continue;
                                }
                        }
                        FEerror("Corrupt bytecodes file ~S", 1, source);
                }
                {
                cl_object x;
                x = cl_set_difference(2, env->packages_to_be_created, old_eptbc);
                old_eptbc = env->packages_to_be_created;
                unlikely_if (!Null(x)) {
                        CEerror(ECL_T,
                                Null(ECL_CONS_CDR(x))?
                                "Package ~A referenced in "
				"compiled file~&  ~A~&but has not been created":
                                "The packages~&  ~A~&were referenced in "
				"compiled file~&  ~A~&but have not been created",
				2, x, source);
		}
                }
	} ECL_UNWIND_PROTECT_EXIT {
		/* We do not want to come back here if close_stream fails,
		   therefore, first we frs_pop() current jump point, then
		   try to close the stream, and then jump to next catch
		   point */
		if (strm != source)
			cl_close(3, strm, ECL_SYM(":ABORT",1195), ECL_SYM("T",1));
	} ECL_UNWIND_PROTECT_END;
	{
#line 196
		const cl_env_ptr the_env = ecl_process_env();
#line 196
		#line 196
		cl_object __value0 = ECL_NIL;
#line 196
		the_env->nvalues = 1;
#line 196
		return __value0;
#line 196
	}

}

// ------------------------------1
#line 205
cl_object cl_load(cl_narg narg, ...)
{
#line 205
// ------------------------------2
#line 205
	const cl_env_ptr the_env = ecl_process_env();
#line 205
	static cl_object KEYS[5] = {(cl_object)(cl_symbols+1325), (cl_object)(cl_symbols+1290), (cl_object)(cl_symbols+1244), (cl_object)(cl_symbols+1236), (cl_object)(cl_symbols+1305)};
	cl_object verbose;
	cl_object print;
	cl_object if_does_not_exist;
	cl_object external_format;
	cl_object search_list;
#line 205
	cl_object pathname;
#line 205
	cl_object pntype;
#line 205
	cl_object hooks;
#line 205
	cl_object filename;
#line 205
	cl_object function;
#line 205
	cl_object ok;
#line 205
	cl_object KEY_VARS[10];
#line 205
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
	cl_object source = ecl_va_arg(ARGS);  
#line 205
// ------------------------------3

	bool not_a_filename = 0;
#line 208
// ------------------------------4
#line 208
#line 208
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(487));
#line 208
	cl_parse_key(ARGS, 5, KEYS, KEY_VARS, NULL, 0);
#line 208
	if (KEY_VARS[5]==ECL_NIL) {
#line 208
	  verbose = ecl_symbol_value(ECL_SYM("*LOAD-VERBOSE*",39));
	} else {
#line 208
	  verbose = KEY_VARS[0];
	}
#line 208
	if (KEY_VARS[6]==ECL_NIL) {
#line 208
	  print = ecl_symbol_value(ECL_SYM("*LOAD-PRINT*",37));
	} else {
#line 208
	  print = KEY_VARS[1];
	}
#line 208
	if (KEY_VARS[7]==ECL_NIL) {
#line 208
	  if_does_not_exist = ECL_SYM(":ERROR",1229);
	} else {
#line 208
	  if_does_not_exist = KEY_VARS[2];
	}
#line 208
	if (KEY_VARS[8]==ECL_NIL) {
#line 208
	  external_format = ECL_SYM(":DEFAULT",1215);
	} else {
#line 208
	  external_format = KEY_VARS[3];
	}
#line 208
	if (KEY_VARS[9]==ECL_NIL) {
#line 208
	  search_list = ecl_symbol_value(ECL_SYM("SI::*LOAD-SEARCH-LIST*",1026));
	} else {
#line 208
	  search_list = KEY_VARS[4];
	}
#line 208
	pathname = ECL_NIL;
#line 208
	pntype = ECL_NIL;
#line 208
	hooks = ECL_NIL;
#line 208
	filename = ECL_NIL;
#line 208
	function = ECL_NIL;
#line 208
	ok = ECL_NIL;
#line 208
// ------------------------------5
	/* If source is a stream, read conventional lisp code from it */
	if (ecl_t_of(source) != t_pathname && !ecl_stringp(source)) {
		/* INV: if "source" is not a valid stream, file.d will complain */
		filename = source;
		function = ECL_NIL;
		not_a_filename = 1;
		goto NOT_A_FILENAME;
	}
	/* INV: coerce_to_file_pathname() creates a fresh new pathname object */
	source   = cl_merge_pathnames(1, source);
	pathname = coerce_to_file_pathname(source);
	pntype   = pathname->pathname.type;

	filename = ECL_NIL;
	hooks = ecl_symbol_value(ECL_SYM("EXT::*LOAD-HOOKS*",1025));
	if (Null(pathname->pathname.directory) &&
	    Null(pathname->pathname.host) &&
	    Null(pathname->pathname.device) &&
	    !Null(search_list))
	{
		loop_for_in(search_list) {
			cl_object d = CAR(search_list);
			cl_object f = cl_merge_pathnames(2, pathname, d);
			cl_object ok = cl_load(11, f, ECL_SYM(":VERBOSE",1325), verbose,
					       ECL_SYM(":PRINT",1290), print,
					       ECL_SYM(":IF-DOES-NOT-EXIST",1244), ECL_NIL,
                                               ECL_SYM(":EXTERNAL-FORMAT",1236), external_format,
					       ECL_SYM(":SEARCH-LIST",1305), ECL_NIL);
			if (!Null(ok)) {
				{
#line 237
					#line 237
					cl_object __value0 = ok;
#line 237
					the_env->nvalues = 1;
#line 237
					return __value0;
#line 237
				}
;
			}
		} end_loop_for_in;
	}
	if (!Null(pntype) && (pntype != ECL_SYM(":WILD",1327))) {
		/* If filename already has an extension, make sure
		   that the file exists */
                cl_object kind;
		filename = si_coerce_to_filename(pathname);
                kind = si_file_kind(filename, ECL_T);
		if (kind != ECL_SYM(":FILE",1237) && kind != ECL_SYM(":SPECIAL",1309)) {
			filename = ECL_NIL;
		} else {
			function = cl_cdr(ecl_assoc(pathname->pathname.type, hooks));
		}
	} else loop_for_in(hooks) {
		/* Otherwise try with known extensions until a matching
		   file is found */
                cl_object kind;
		filename = pathname;
		filename->pathname.type = CAAR(hooks);
		function = CDAR(hooks);
                kind = si_file_kind(filename, ECL_T);
		if (kind == ECL_SYM(":FILE",1237) || kind == ECL_SYM(":SPECIAL",1309))
			break;
		else
			filename = ECL_NIL;
	} end_loop_for_in;
	if (Null(filename)) {
		if (Null(if_does_not_exist))
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

		else
			FEcannot_open(source);
	}
NOT_A_FILENAME:
	if (verbose != ECL_NIL) {
		cl_format(3, ECL_T, make_constant_base_string("~&;;; Loading ~s~%"),
			  filename);
	}
	ecl_bds_bind(the_env, ECL_SYM("*PACKAGE*",43), ecl_symbol_value(ECL_SYM("*PACKAGE*",43)));
	ecl_bds_bind(the_env, ECL_SYM("*READTABLE*",65), ecl_symbol_value(ECL_SYM("*READTABLE*",65)));
	ecl_bds_bind(the_env, ECL_SYM("*LOAD-PATHNAME*",36), not_a_filename? ECL_NIL : source);
	ecl_bds_bind(the_env, ECL_SYM("*LOAD-TRUENAME*",38),
		     not_a_filename? ECL_NIL : (filename = cl_truename(filename)));
	if (!Null(function)) {
		ok = funcall(5, function, filename, verbose, print, external_format);
	} else {
#if 0 /* defined(ENABLE_DLOPEN) && !defined(ECL_MS_WINDOWS_HOST)*/
		/*
		 * DISABLED BECAUSE OF SECURITY ISSUES!
		 * In systems where we can do this, we try to load the file
		 * as a binary. When it fails, we will revert to source
		 * loading below. Is this safe? Well, it depends on whether
		 * your op.sys. checks integrity of binary exectables or
		 * just loads _anything_.
		 */
		if (not_a_filename) {
			ok = ECL_T;
		} else {
			ok = si_load_binary(filename, verbose, print);
		}
		if (!Null(ok))
#endif
		ok = si_load_source(filename, verbose, print, external_format);
	}
	ecl_bds_unwind_n(the_env, 4);
	if (!Null(ok))
		FEerror("LOAD: Could not load file ~S (Error: ~S)",
			2, filename, ok);
	if (print != ECL_NIL) {
		cl_format(3, ECL_T, make_constant_base_string("~&;;; Loading ~s~%"),
			  filename);
	}
	{
#line 310
		#line 310
		cl_object __value0 = filename;
#line 310
		the_env->nvalues = 1;
#line 310
		return __value0;
#line 310
	}

}
