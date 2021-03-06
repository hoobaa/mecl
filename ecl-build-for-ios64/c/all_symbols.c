#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/all_symbols.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
#include <ecl/ecl.h>
#include <ctype.h>
#include <limits.h>
#include <ecl/internal.h>

#define CL_PACKAGE 0
#define SI_PACKAGE 4
#define EXT_PACKAGE 64
#define GRAY_PACKAGE 32
#define FFI_PACKAGE 128
#define KEYWORD_PACKAGE 8
#define MP_PACKAGE 12
#define CLOS_PACKAGE 16
#define ORDINARY_SYMBOL 0
#define CONSTANT_SYMBOL 1
#define SPECIAL_SYMBOL 2
#define FORM_SYMBOL 3
#define PRIVATE 256

#define CL_ORDINARY	CL_PACKAGE | ORDINARY_SYMBOL
#define CL_SPECIAL	CL_PACKAGE | SPECIAL_SYMBOL
#define CL_CONSTANT	CL_PACKAGE | CONSTANT_SYMBOL
#define CL_FORM		CL_PACKAGE | ORDINARY_SYMBOL | FORM_SYMBOL
#define SI_ORDINARY	SI_PACKAGE | ORDINARY_SYMBOL
#define SI_SPECIAL	SI_PACKAGE | SPECIAL_SYMBOL
#define SI_CONSTANT	SI_PACKAGE | CONSTANT_SYMBOL
#define EXT_ORDINARY	EXT_PACKAGE | ORDINARY_SYMBOL
#define EXT_SPECIAL	EXT_PACKAGE | SPECIAL_SYMBOL
#define EXT_CONSTANT	EXT_PACKAGE | CONSTANT_SYMBOL
#define EXT_FORM	EXT_PACKAGE | ORDINARY_SYMBOL | FORM_SYMBOL
#define MP_ORDINARY	MP_PACKAGE | ORDINARY_SYMBOL
#define MP_SPECIAL	MP_PACKAGE | SPECIAL_SYMBOL
#define MP_CONSTANT	MP_PACKAGE | CONSTANT_SYMBOL
#define CLOS_ORDINARY	CLOS_PACKAGE | ORDINARY_SYMBOL
#define CLOS_SPECIAL	CLOS_PACKAGE | SPECIAL_SYMBOL
#define KEYWORD		KEYWORD_PACKAGE | CONSTANT_SYMBOL
#define GRAY_ORDINARY	GRAY_PACKAGE | ORDINARY_SYMBOL
#define FFI_ORDINARY	FFI_PACKAGE | ORDINARY_SYMBOL
#define FFI_CONSTANT	FFI_PACKAGE | CONSTANT_SYMBOL

#include "symbols_list.h"

cl_index cl_num_symbols_in_core = 0;

static unsigned char *
mangle_name(cl_object output, unsigned char *source, int l)
{
	unsigned char c;

	while (l--) {
		c = *(source++);
		if (ecl_alphanumericp(c)) {
			c = ecl_char_downcase(c);
		} else if (c == '-' || c == '_') {
			c = '_';
		} else if (c == '&') {
			c = 'A';
		} else if (c == '*') {
			c = 'X';
		} else if (c == '+') {
			c = 'P';
		} else if (c == '<') {
			c = 'L';
		} else if (c == '>') {
			c = 'G';
		} else if (c == '=') {
			c = 'E';
		} else if (c == '/') {
			c = 'N';
		} else if (c == ':') {
			c = 'X';
		} else {
			return NULL;
		}
		output->base_string.self[output->base_string.fillp++] = c;
	}
	return &output->base_string.self[output->base_string.fillp];
}

// ------------------------------1
#line 81
cl_object si_mangle_name(cl_narg narg, ...)
{
#line 81
// ------------------------------2
#line 81
	const cl_env_ptr the_env = ecl_process_env();
#line 81
	cl_object as_function;
#line 81
	va_list ARGS;
	va_start(ARGS, narg);
	cl_object symbol = va_arg(ARGS,cl_object);  
#line 81
// ------------------------------3

	cl_index l;
	unsigned char c, *source, *dest;
	cl_object output;
	cl_object package;
	cl_object found = ECL_NIL;
	cl_object maxarg = ecl_make_fixnum(ECL_CALL_ARGUMENTS_LIMIT);
	cl_object minarg = ecl_make_fixnum(0);
	bool is_symbol;
	cl_object name;
#line 92
// ------------------------------4
#line 92
#line 92
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(1107));
#line 92
	if (narg > 1) {
#line 92
		as_function = va_arg(ARGS,cl_object);  
#line 92
	} else {
#line 92
		as_function = ECL_NIL;
#line 92
	}
#line 92
// ------------------------------5
	name = ecl_symbol_name(symbol);
	is_symbol = Null(as_function);
	if (is_symbol) {
		cl_fixnum p;
		if (symbol == ECL_NIL)
			{
#line 97
				#line 97
				cl_object __value0 = ECL_T;
#line 97
				cl_object __value1 = make_constant_base_string("ECL_NIL");
#line 97
				the_env->nvalues = 2;
#line 97
				the_env->values[1] = __value1;
#line 97
				return __value0;
#line 97
			}

		else if (symbol == ECL_T)
			{
#line 99
				#line 99
				cl_object __value0 = ECL_T;
#line 99
				cl_object __value1 = make_constant_base_string("ECL_T");
#line 99
				the_env->nvalues = 2;
#line 99
				the_env->values[1] = __value1;
#line 99
				return __value0;
#line 99
			}

		p  = (cl_symbol_initializer*)symbol - cl_symbols;
		if (p >= 0 && p <= cl_num_symbols_in_core) {
			found = ECL_T;
			output = cl_format(4, ECL_NIL,
					   make_constant_base_string("ECL_SYM(~S,~D)"),
					   name, ecl_make_fixnum(p));
			{
#line 106
				#line 106
				cl_object __value0 = found;
#line 106
				cl_object __value1 = output;
#line 106
				cl_object __value2 = maxarg;
#line 106
				the_env->nvalues = 3;
#line 106
				the_env->values[2] = __value2;
#line 106
				the_env->values[1] = __value1;
#line 106
				return __value0;
#line 106
			}

		}
	} else if (!Null(symbol)) {
		cl_object fun = symbol->symbol.gfdef;
		cl_type t = (fun == OBJNULL)? t_other : type_of(fun);
		if ((t == t_cfun || t == t_cfunfixed) && fun->cfun.block == OBJNULL) {
			for (l = 0; l <= cl_num_symbols_in_core; l++) {
				cl_object s = (cl_object)(cl_symbols + l);
				if (fun == ECL_SYM_FUN(s)) {
					symbol = s;
					found = ECL_T;
					if (fun->cfun.narg >= 0) {
					    minarg =
					    maxarg = ecl_make_fixnum(fun->cfun.narg);
					}
					break;
				}
			}
		}
	}
	package = ecl_symbol_package(symbol);
	if (Null(package))
		;
	else if (package == cl_core.lisp_package)
		package = make_constant_base_string("cl");
	else if (package == cl_core.system_package)
		package = make_constant_base_string("si");
	else if (package == cl_core.ext_package)
		package = make_constant_base_string("si");
	else if (package == cl_core.keyword_package)
		package = ECL_NIL;
	else
		package = package->pack.name;
	symbol = ecl_symbol_name(symbol);
	l      = symbol->base_string.fillp;
	source = symbol->base_string.self;
	output = ecl_alloc_simple_base_string(ecl_length(package) + l + 1);
	if (is_symbol && source[0] == '*') {
		if (l > 2 && source[l-1] == '*') l--;
		c = 'V';
		l--;
		source++;
	} else if (is_symbol && l > 2 && source[0] == '+' && source[l-1] == '+') {
		c = 'C';
		l-= 2;
		source++;
	} else if (!is_symbol) {
		c = '_';
	} else if (package == cl_core.keyword_package) {
		c = 'K';
	} else {
		c = 'S';
	}
	output->base_string.fillp = 0;
	if (!Null(package))
		if (!mangle_name(output, package->base_string.self, package->base_string.fillp))
			{
#line 162
				#line 162
				cl_object __value0 = ECL_NIL;
#line 162
				cl_object __value1 = ECL_NIL;
#line 162
				cl_object __value2 = maxarg;
#line 162
				the_env->nvalues = 3;
#line 162
				the_env->values[2] = __value2;
#line 162
				the_env->values[1] = __value1;
#line 162
				return __value0;
#line 162
			}

	output->base_string.self[output->base_string.fillp++] = c;
	if (!(dest = mangle_name(output, source, l)))
		{
#line 165
			#line 165
			cl_object __value0 = ECL_NIL;
#line 165
			cl_object __value1 = ECL_NIL;
#line 165
			cl_object __value2 = maxarg;
#line 165
			the_env->nvalues = 3;
#line 165
			the_env->values[2] = __value2;
#line 165
			the_env->values[1] = __value1;
#line 165
			return __value0;
#line 165
		}

	if (dest[-1] == '_')
		dest[-1] = 'M';
	*(dest++) = '\0';
	{
#line 169
		#line 169
		cl_object __value0 = found;
#line 169
		cl_object __value1 = output;
#line 169
		cl_object __value2 = minarg;
#line 169
		cl_object __value3 = maxarg;
#line 169
		the_env->nvalues = 4;
#line 169
		the_env->values[3] = __value3;
#line 169
		the_env->values[2] = __value2;
#line 169
		the_env->values[1] = __value1;
#line 169
		return __value0;
#line 169
	}

}

static void
make_this_symbol(int i, cl_object s, int code, const char *name,
		 cl_objectfn fun, int narg, cl_object value)
{
	enum ecl_stype stp;
	cl_object package;
	bool form = 0;

	switch (code & 3) {
	case ORDINARY_SYMBOL: stp = ecl_stp_ordinary; break;
	case SPECIAL_SYMBOL: stp = ecl_stp_special; break;
	case CONSTANT_SYMBOL: stp = ecl_stp_constant; break;
	case FORM_SYMBOL: form = 1; stp = ecl_stp_ordinary;
	}
	switch (code & 0xfc) {
	case CL_PACKAGE: package = cl_core.lisp_package; break;
	case SI_PACKAGE: package = cl_core.system_package; break;
	case EXT_PACKAGE: package = cl_core.ext_package; break;
	case KEYWORD_PACKAGE: package = cl_core.keyword_package; break;
	case MP_PACKAGE: package = cl_core.mp_package; break;
#ifdef CLOS
	case CLOS_PACKAGE: package = cl_core.clos_package; break;
#endif
#ifdef ECL_CLOS_STREAMS
	case GRAY_PACKAGE: package = cl_core.gray_package; break;
#endif
	case FFI_PACKAGE: package = cl_core.ffi_package; break;
	default: printf("%d\n", code & ~(int)3); ecl_internal_error("Unknown package code in init_all_symbols()");
	}
	s->symbol.t = t_symbol;
	s->symbol.dynamic = 0;
#ifdef ECL_THREADS
	s->symbol.binding = ECL_MISSING_SPECIAL_BINDING;
#endif
	ECL_SET(s, OBJNULL);
	ECL_SYM_FUN(s) = ECL_NIL;
	s->symbol.plist = ECL_NIL;
	s->symbol.hpack = ECL_NIL;
	s->symbol.stype = stp;
	s->symbol.hpack = package;
	s->symbol.name = make_constant_base_string(name);
	if (package == cl_core.keyword_package) {
		package->pack.external =
                        _ecl_sethash(s->symbol.name, package->pack.external, s);
		ECL_SET(s, s);
	} else {
		int intern_flag;
		ECL_SET(s, value);
		if (ecl_find_symbol(s->symbol.name, package, &intern_flag) != ECL_NIL
		    && intern_flag == ECL_INHERITED) {
			ecl_shadowing_import(s, package);
		} else {
			cl_import2(s, package);
		}
		if (!(code & PRIVATE)) {
			cl_export2(s, package);
			if (package == cl_core.ext_package)
				cl_export2(s, cl_core.system_package);
		}
	}
	if (form) {
		s->symbol.stype |= ecl_stp_special_form;
	} else if (fun) {
		cl_object f;
		if (narg >= 0) {
			f = ecl_make_cfun((cl_objectfn_fixed)fun, s, NULL, narg);
		} else {
			f = ecl_make_cfun_va(fun, s, NULL);
		}
		ECL_SYM_FUN(s) = f;
	}
	cl_num_symbols_in_core = i + 1;
}

void
init_all_symbols(void)
{
	int i, code, narg;
	const char *name;
	cl_object s, value;
	cl_objectfn fun;

	/* We skip NIL and T */
	for (i = 2; cl_symbols[i].init.name != NULL; i++) {
		s = (cl_object)(cl_symbols + i);
		code = cl_symbols[i].init.type;
		name = cl_symbols[i].init.name;
		fun = (cl_objectfn)cl_symbols[i].init.fun;
		narg = cl_symbols[i].init.narg;
		value = cl_symbols[i].init.value;
		make_this_symbol(i, s, code, name, fun, narg, value);
	}
}
