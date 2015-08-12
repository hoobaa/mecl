#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/printer/print_unreadable.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    print_unreadable.d -- helper for print-unreadable-object macro
*/
/*
    Copyright (c) 2010, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <ecl/ecl.h>
#include <ecl/internal.h>

void
_ecl_write_addr(cl_object x, cl_object stream)
{
	cl_fixnum i, j;

	i = (cl_index)x;
	for (j = sizeof(i)*8-4;  j >= 0;  j -= 4) {
		int k = (i>>j) & 0xf;
		if (k < 10)
			ecl_write_char('0' + k, stream);
		else
			ecl_write_char('a' + k - 10, stream);
	}
}

void
_ecl_write_unreadable(cl_object x, const char *prefix, cl_object name, cl_object stream)
{
        if (ecl_print_readably())
                FEprint_not_readable(x);
        ecl_write_char('#', stream);
        ecl_write_char('<', stream);
        writestr_stream(prefix, stream);
        ecl_write_char(' ', stream);
        if (!Null(name)) {
                si_write_ugly_object(name, stream);
        } else {
                _ecl_write_addr(x, stream);
        }
        ecl_write_char('>', stream);
}

cl_object
si_print_unreadable_object_function(cl_object o, cl_object stream, cl_object type, cl_object id, cl_object function)
{
	if (ecl_print_readably())
		FEprint_not_readable(o);
        stream = _ecl_stream_or_default_output(stream);
	if (ecl_print_level() == 0) {
		ecl_write_char('#', stream);
	} else {
		writestr_stream("#<", stream);
		if (!Null(type)) {
			cl_index i, l;
			type = cl_type_of(o);
			if (!ECL_SYMBOLP(type)) {
				type = ECL_SYM("STANDARD-OBJECT",976);
			}
			type = type->symbol.name;
			for (i = 0, l = ecl_length(type); i < l; i++)
				ecl_write_char(ecl_char_downcase(ecl_char(type, i)), stream);
                        ecl_write_char(' ', stream);
		}
		if (!Null(function)) {
			_ecl_funcall1(function);
		}
		if (!Null(id)) {
			ecl_write_char(' ', stream);
			_ecl_write_addr(o, stream);
		}
		ecl_write_char('>', stream);
	}
	{
#line 81
		const cl_env_ptr the_env = ecl_process_env();
#line 81
		#line 81
		cl_object __value0 = ECL_NIL;
#line 81
		the_env->nvalues = 1;
#line 81
		return __value0;
#line 81
	}

}
