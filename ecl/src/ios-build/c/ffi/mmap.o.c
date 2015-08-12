#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/ffi/mmap.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    mmap.d -- Mapping of binary files.
*/
/*
    Copyright (c) 2011, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <ecl/ecl.h>
#ifdef HAVE_SYS_MMAN_H
# include <sys/mman.h>
#endif
#include <ecl/ecl-inl.h>
#include <ecl/internal.h>

#line 31
cl_object si_mmap(cl_narg narg, cl_object filename, ...)
{
#line 31

#line 33
	const cl_env_ptr the_env = ecl_process_env();
#line 33
	static cl_object KEYS[7] = {(cl_object)(cl_symbols+1263), (cl_object)(cl_symbols+1279), (cl_object)(cl_symbols+1218), (cl_object)(cl_symbols+1224), (cl_object)(cl_symbols+1245), (cl_object)(cl_symbols+1244), (cl_object)(cl_symbols+1236)};
	cl_object length;
	cl_object offset;
	cl_object direction;
	cl_object element_type;
	cl_object if_exists;
	cl_object if_does_not_exist;
	cl_object external_format;
#line 33
	cl_object KEY_VARS[14];
#line 33
	ecl_va_list ARGS;
	ecl_va_start(ARGS, filename, narg, 1);
#line 33
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(1841));
#line 33
	cl_parse_key(ARGS, 7, KEYS, KEY_VARS, NULL, 0);
#line 33
	if (KEY_VARS[7]==ECL_NIL) {
#line 33
	  length = ECL_NIL;
	} else {
#line 33
	  length = KEY_VARS[0];
	}
#line 33
	if (KEY_VARS[8]==ECL_NIL) {
#line 33
	  offset = ecl_make_fixnum(0);
	} else {
#line 33
	  offset = KEY_VARS[1];
	}
#line 33
	if (KEY_VARS[9]==ECL_NIL) {
#line 33
	  direction = ECL_SYM(":INPUT",1254);
	} else {
#line 33
	  direction = KEY_VARS[2];
	}
#line 33
	if (KEY_VARS[10]==ECL_NIL) {
#line 33
	  element_type = ECL_SYM("BASE-CHAR",120);
	} else {
#line 33
	  element_type = KEY_VARS[3];
	}
#line 33
	if (KEY_VARS[11]==ECL_NIL) {
#line 33
	  if_exists = ECL_SYM(":NEW-VERSION",1275);
	} else {
#line 33
	  if_exists = KEY_VARS[4];
	}
#line 33
	if (KEY_VARS[12]==ECL_NIL) {
#line 33
	  if_does_not_exist = ECL_SYM(":ERROR",1229);
	} else {
#line 33
	  if_does_not_exist = KEY_VARS[5];
	}
#line 33
	if (KEY_VARS[13]==ECL_NIL) {
#line 33
	  external_format = ECL_SYM(":DEFAULT",1215);
	} else {
#line 33
	  external_format = KEY_VARS[6];
	}
#line 33
#ifdef HAVE_SYS_MMAN_H
{
        cl_object output, stream;
        int c_prot, c_flags, fd;
        size_t len;
        void *pa;
        if (direction == ECL_SYM(":INPUT",1254))
                c_prot = PROT_READ;
        else if (direction == ECL_SYM(":OUTPUT",1282))
                c_prot = PROT_WRITE;
        else if (direction == ECL_SYM(":IO",1260))
                c_prot = PROT_READ | PROT_WRITE;
        else
                c_prot = PROT_NONE;
        if (Null(filename)) {
                c_flags = MAP_ANON | MAP_PRIVATE;
                fd = -1;
                len = ecl_to_unsigned_integer(length);
                stream = ECL_NIL;
        } else {
                c_flags = MAP_SHARED;
                stream = cl_open(13, filename,
                                 ECL_SYM(":DIRECTION",1218), direction,
                                 ECL_SYM(":ELEMENT-TYPE",1224), element_type,
                                 ECL_SYM(":IF-EXISTS",1245), if_exists,
                                 ECL_SYM(":IF-DOES-NOT-EXIST",1244), if_does_not_exist,
                                 ECL_SYM(":EXTERNAL-FORMAT",1236), ECL_SYM(":DEFAULT",1215),
                                 ECL_SYM(":CSTREAM",1324), ECL_NIL);
                fd = ecl_to_int(si_file_stream_fd(stream));
                if (Null(length))
                        len = ecl_to_unsigned_integer(ecl_file_length(stream));
                else
                        len = ecl_to_unsigned_integer(length);
        }
        output = si_make_vector(element_type, ecl_make_fixnum(0), ECL_NIL,
                                ECL_NIL, ECL_NIL, ECL_NIL);
        pa = mmap(0, len, c_prot, c_flags, fd,
                  ecl_integer_to_off_t(offset));
        if (pa == MAP_FAILED) {
                FElibc_error("EXT::MMAP failed.", 0);
        } else {
                output->base_string.self = pa;
                output->base_string.dim =
                        output->base_string.fillp = len;
        }
        {
#line 78
	#line 78
	cl_object __value0 = CONS(output, stream);
#line 78
	the_env->nvalues = 1;
#line 78
	return __value0;
#line 78
}

}
#else
{
        cl_object output, vector;
        if (Null(filename)) {
                output = si_make_vector(element_type, length, ECL_NIL,
                                ECL_NIL, ECL_NIL, ECL_NIL);
        } else {
                cl_object stream = cl_open(13, filename,
                                           ECL_SYM(":DIRECTION",1218), direction,
                                           ECL_SYM(":ELEMENT-TYPE",1224), element_type,
                                           ECL_SYM(":IF-EXISTS",1245), if_exists,
                                           ECL_SYM(":IF-DOES-NOT-EXIST",1244), if_does_not_exist,
                                           ECL_SYM(":EXTERNAL-FORMAT",1236), ECL_SYM(":PASS-THROUGH",1769),
                                           ECL_SYM(":CSTREAM",1324), ECL_T);
                if (Null(length))
                        length = ecl_file_length(stream);
                else
                        length = ecl_to_unsigned_integer(length);
                output = si_make_vector(element_type, length, ECL_NIL,
                                        ECL_NIL, ECL_NIL, ECL_NIL);
                cl_read_sequence(2, output, stream);
                cl_close(1, stream);
        }
        {
#line 103
	#line 103
	cl_object __value0 = output;
#line 103
	the_env->nvalues = 1;
#line 103
	return __value0;
#line 103
}

}
#endif
}

cl_object
si_mmap_array(cl_object map)
{
#ifdef HAVE_SYS_MMAN_H
        {
#line 112
	const cl_env_ptr the_env = ecl_process_env();
#line 112
	#line 112
	cl_object __value0 = cl_car(map);
#line 112
	the_env->nvalues = 1;
#line 112
	return __value0;
#line 112
}
;
#else
        {
#line 114
	const cl_env_ptr the_env = ecl_process_env();
#line 114
	#line 114
	cl_object __value0 = map;
#line 114
	the_env->nvalues = 1;
#line 114
	return __value0;
#line 114
}
;
#endif
}

cl_object
si_munmap(cl_object map)
{
#ifdef HAVE_SYS_MMAN_H
        cl_object array = cl_car(map);
        cl_object stream = cl_cdr(map);
        int code = munmap(array->base_string.self, array->base_string.dim);
        if (code < 0) {
                FElibc_error("Error when unmapping file.", 0);
        }
        cl_close(1, stream);
#endif
        {
#line 130
	const cl_env_ptr the_env = ecl_process_env();
#line 130
	#line 130
	cl_object __value0 = ECL_NIL;
#line 130
	the_env->nvalues = 1;
#line 130
	return __value0;
#line 130
}

}
