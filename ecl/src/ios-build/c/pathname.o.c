#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/pathname.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    pathname.d -- Pathnames.
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

/*
	O.S. DEPENDENT

	This file contains those functions that interpret namestrings.
*/

#include <ecl/ecl.h>
#include <ecl/ecl-inl.h>
#include <ecl/internal.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

typedef int (*delim_fn)(int);

/*
 * Translates a string into the host's preferred case.
 * See CLHS 19.2.2.1.2.2 Common Case in Pathname Components.
 */
/* We use UN*X conventions, so lower case is default.
 * However, this really should be conditionalised to the OS type,
 * and it should translate to _opposite_ of the local case.
 */

static cl_object
normalize_case(cl_object path, cl_object cas)
{
        if (cas == ECL_SYM(":LOCAL",1268)) {
                if (path->pathname.logical)
                        return ECL_SYM(":UPCASE",1322);
                return ECL_SYM(":DOWNCASE",1223);
        } else if (cas == ECL_SYM(":COMMON",1208) || cas == ECL_SYM(":DOWNCASE",1223) || cas == ECL_SYM(":UPCASE",1322)) {
                return cas;
        } else {
                FEerror("Not a valid pathname case :~%~A", 1, cas);
        }
}

static bool
in_local_case_p(cl_object str, cl_object cas)
{
        if (cas == ECL_SYM(":DOWNCASE",1223))
                return ecl_string_case(str) < 0;
        return 1;
}

static bool
in_antilocal_case_p(cl_object str, cl_object cas)
{
        if (cas == ECL_SYM(":DOWNCASE",1223))
                return ecl_string_case(str) > 0;
        return 0;
}

static cl_object
to_local_case(cl_object str, cl_object cas)
{
        if (cas == ECL_SYM(":DOWNCASE",1223))
                return cl_string_downcase(1, str);
        return cl_string_upcase(1, str);
}

static cl_object
host_case(cl_object host)
{
        if (Null(host))
                return ECL_SYM(":LOCAL",1268);
        if (ecl_logical_hostname_p(host))
                return ECL_SYM(":UPCASE",1322);
        return ECL_SYM(":DOWNCASE",1223);
}

static cl_object
to_antilocal_case(cl_object str, cl_object cas)
{
        if (cas == ECL_SYM(":DOWNCASE",1223))
                return cl_string_upcase(1, str);
        return cl_string_upcase(1, str);
}

static cl_object
translate_from_common(cl_object str, cl_object tocase)
{
	int string_case = ecl_string_case(str);
	if (string_case > 0) { /* ALL_UPPER */
		return to_local_case(str, tocase);
	} else if (string_case < 0) { /* ALL_LOWER */
		return to_antilocal_case(str, tocase);
	} else { /* Mixed case goes unchanged */
		return str;
	}
}

static cl_object
translate_to_common(cl_object str, cl_object fromcase)
{
	if (in_local_case_p(str, fromcase)) {
		return cl_string_upcase(1, str);
	} else if (in_antilocal_case_p(str, fromcase)) {
		return cl_string_downcase(1, str);
	} else {
		return str;
	}
}

static cl_object
translate_component_case(cl_object str, cl_object fromcase, cl_object tocase)
{
        /* Pathnames may contain some other objects, such as symbols,
         * numbers, etc, which need not be translated */
        if (str == OBJNULL) {
                return str;
        } else if (!ECL_BASE_STRING_P(str)) {
#ifdef ECL_UNICODE
                if (ECL_EXTENDED_STRING_P(str) && ecl_fits_in_base_string(str)) {
                        str = si_coerce_to_base_string(str);
                        return translate_component_case(str, fromcase, tocase);
                }
#endif
                return str;
        } else if (tocase == fromcase) {
                return str;
        } else if (tocase == ECL_SYM(":COMMON",1208)) {
		return translate_to_common(str, fromcase);
	} else if (fromcase == ECL_SYM(":COMMON",1208)) {
		return translate_from_common(str, tocase);
	} else {
                str = translate_to_common(str, fromcase);
                return translate_from_common(str, tocase);
        }
}

static cl_object
translate_list_case(cl_object list, cl_object fromcase, cl_object tocase)
{
	/* If the argument is really a list, translate all strings in it and
	 * return this new list, else assume it is a string and translate it.
	 */
	if (!CONSP(list)) {
		return translate_component_case(list, fromcase, tocase);
	} else {
		cl_object l;
		list = cl_copy_list(list);
		for (l = list; !ecl_endp(l); l = CDR(l)) {
			/* It is safe to pass anything to translate_component_case,
			 * because it will only transform strings, leaving other
			 * object (such as symbols) unchanged.*/
			cl_object name = ECL_CONS_CAR(l);
                        name = ECL_LISTP(name)?
                                translate_list_case(name, fromcase, tocase) :
                                translate_component_case(name, fromcase, tocase);
			ECL_RPLACA(l, name);
		}
		return list;
	}
}

static void
push_substring(cl_object buffer, cl_object string, cl_index start, cl_index end)
{
	string = cl_string(string);
	while (start < end) {
		ecl_string_push_extend(buffer, ecl_char(string, start));
		start++;
	}
}

static void
push_string(cl_object buffer, cl_object string)
{
	push_substring(buffer, string, 0, ecl_length(string));
}

static cl_object
destructively_check_directory(cl_object directory, bool logical, bool delete_back)
{
	/* This function performs two tasks
	 * 1) It ensures that the list is a valid directory list
	 * 2) It ensures that all strings in the list are valid C strings without fill pointer
	 *    All strings are copied, thus avoiding problems with the user modifying the
	 *    list that was passed to MAKE-PATHNAME.
         * 3) Redundant :back are removed.
	 */
	/* INV: directory is always a list */
	cl_object ptr;
	int i;

	if (!LISTP(directory))
		return ECL_SYM(":ERROR",1229);
	if (Null(directory))
		return directory;
	if (ECL_CONS_CAR(directory) != ECL_SYM(":ABSOLUTE",1196) &&
	    ECL_CONS_CAR(directory) != ECL_SYM(":RELATIVE",1299))
		return ECL_SYM(":ERROR",1229);
 BEGIN:
	for (i=0, ptr=directory; CONSP(ptr); ptr = ECL_CONS_CDR(ptr), i++) {
		cl_object item = ECL_CONS_CAR(ptr);
		if (item == ECL_SYM(":BACK",1200)) {
			if (i == 0)
				return ECL_SYM(":ERROR",1229);
			item = ecl_nth(i-1, directory);
			if (item == ECL_SYM(":ABSOLUTE",1196) || item == ECL_SYM(":WILD-INFERIORS",1328))
				return ECL_SYM(":ERROR",1229);
			if (delete_back && i >= 2) {
                                cl_object next = ECL_CONS_CDR(ptr);
                                ptr = ecl_nthcdr(i-2, directory);
				ECL_RPLACD(ptr, next);
                                i--;
                        }
		} else if (item == ECL_SYM(":UP",1321)) {
			if (i == 0)
				return ECL_SYM(":ERROR",1229);
			item = ecl_nth(i-1, directory);
			if (item == ECL_SYM(":ABSOLUTE",1196) || item == ECL_SYM(":WILD-INFERIORS",1328))
				return ECL_SYM(":ERROR",1229);
		} else if (item == ECL_SYM(":RELATIVE",1299) || item == ECL_SYM(":ABSOLUTE",1196)) {
			if (i > 0)
				return ECL_SYM(":ERROR",1229);
		} else if (ecl_stringp(item)) {
			cl_index l = ecl_length(item);
#ifdef ECL_UNICODE
			if (ecl_fits_in_base_string(item)) {
				item = si_copy_to_simple_base_string(item);
			} else
#endif
				item = cl_copy_seq(item);
			ECL_RPLACA(ptr, item);
			if (logical)
				continue;
			if (l && ecl_char(item,0) == '.') {
				if (l == 1) {
					/* Single dot */
					if (i == 0)
						return ECL_SYM(":ERROR",1229);
					ECL_RPLACD(ecl_nthcdr(--i, directory),
						   ECL_CONS_CDR(ptr));
				} else if (l == 2 && ecl_char(item,1) == '.') {
					ECL_RPLACA(ptr, ECL_SYM(":UP",1321));
					goto BEGIN;
				}
			}
		} else if (item != ECL_SYM(":WILD",1327) && item != ECL_SYM(":WILD-INFERIORS",1328)) {
			return ECL_SYM(":ERROR",1229);
		}
	}
	return directory;
}

cl_object
ecl_make_pathname(cl_object host, cl_object device, cl_object directory,
		  cl_object name, cl_object type, cl_object version,
                  cl_object fromcase)
{
	cl_object x, p, component;

	p = ecl_alloc_object(t_pathname);
	if (ecl_stringp(host))
		p->pathname.logical = ecl_logical_hostname_p(host);
	else if (host == ECL_NIL)
		p->pathname.logical = FALSE;
	else {
		x = directory;
		component = ECL_SYM(":HOST",1243);
		goto ERROR;
	}
	if (device != ECL_NIL && device != ECL_SYM(":UNSPECIFIC",1319) &&
	    !(!p->pathname.logical && ecl_stringp(device))) {
		x = device;
		component = ECL_SYM(":DEVICE",1217);
		goto ERROR;
	}
	if (name != ECL_NIL && name != ECL_SYM(":WILD",1327) && !ecl_stringp(name)) {
		x = name;
		component = ECL_SYM(":NAME",1273);
		goto ERROR;
	}
	if (type != ECL_NIL && type != ECL_SYM(":UNSPECIFIC",1319) && type != ECL_SYM(":WILD",1327) && !ecl_stringp(type)) {
		x = type;
		component = ECL_SYM(":TYPE",1318);
		goto ERROR;
	}
	if (version != ECL_SYM(":UNSPECIFIC",1319) && version != ECL_SYM(":NEWEST",1276) &&
	    version != ECL_SYM(":WILD",1327) && version != ECL_NIL && !ECL_FIXNUMP(version))
	{
		x = version;
		component = ECL_SYM(":VERSION",1326);
	ERROR:	FEerror("~s is not a valid pathname-~a component", 2, x, component);
	}
	switch (ecl_t_of(directory)) {
#ifdef ECL_UNICODE
	case t_string:
#endif
	case t_base_string:
		directory = cl_list(2, ECL_SYM(":ABSOLUTE",1196), directory);
		break;
	case t_symbol:
		if (directory == ECL_SYM(":WILD",1327)) {
			directory = cl_list(2, ECL_SYM(":ABSOLUTE",1196), ECL_SYM(":WILD-INFERIORS",1328));
			break;
		}
		x = directory;
		component = ECL_SYM(":DIRECTORY",1219);
		goto ERROR;
	case t_list:
		directory = cl_copy_list(directory);
		break;
	default:
		x = directory;
		component = ECL_SYM(":DIRECTORY",1219);
		goto ERROR;
	}
        p->pathname.host = host;
        {
                cl_object tocase = normalize_case(p, ECL_SYM(":LOCAL",1268));
                if (p->pathname.logical)
                        fromcase = ECL_SYM(":COMMON",1208);
                else
                        fromcase = normalize_case(p, fromcase);
                p->pathname.host =
                        translate_component_case(host, fromcase, tocase);
                p->pathname.device =
                        translate_component_case(device, fromcase, tocase);
                p->pathname.directory =
			directory =
                        translate_list_case(directory, fromcase, tocase);
                p->pathname.name =
                        translate_component_case(name, fromcase, tocase);
                p->pathname.type =
                        translate_component_case(type, fromcase, tocase);
                p->pathname.version = version;
        }
	directory = destructively_check_directory(directory, p->pathname.logical, 0);
        unlikely_if (directory == ECL_SYM(":ERROR",1229)) {
		cl_error(3, ECL_SYM("FILE-ERROR",353), ECL_SYM(":PATHNAME",1285), p);
	}
	p->pathname.directory = directory;
	return(p);
}

static cl_object
tilde_expand(cl_object pathname)
{
	/*
	 * If the pathname is a physical one, without hostname, without device
	 * and the first element is either a tilde '~' or '~' followed by
	 * a user name, we merge the user homedir pathname with this one.
	 */
	cl_object directory, head;
	if (pathname->pathname.logical || pathname->pathname.host != ECL_NIL
	    || pathname->pathname.device != ECL_NIL) {
		return pathname;
	}
	directory = pathname->pathname.directory;
	if (!CONSP(directory) || ECL_CONS_CAR(directory) != ECL_SYM(":RELATIVE",1299)
	    || ECL_CONS_CDR(directory) == ECL_NIL) {
		return pathname;
	}
	head = CADR(directory);
	if (ecl_stringp(head) && ecl_length(head) > 0 && 
	    ecl_char(head,0) == '~') {
		/* Remove the tilde component */
		ECL_RPLACD(directory, CDDR(directory));
		pathname = cl_merge_pathnames(2, pathname,
					      ecl_homedir_pathname(head));
	}
	return pathname;
}

#define WORD_INCLUDE_DELIM 1
#define WORD_ALLOW_ASTERISK  2
#define WORD_EMPTY_IS_NIL 4
#define WORD_LOGICAL 8
#define WORD_SEARCH_LAST_DOT 16
#define WORD_ALLOW_LEADING_DOT 32
#define WORD_DISALLOW_SLASH 64
#define WORD_DISALLOW_SEMICOLON 128

static cl_object
make_one(cl_object s, cl_index start, cl_index end)
{
	return cl_subseq(3, s, ecl_make_fixnum(start), ecl_make_fixnum(end));
}

static int is_colon(int c) { return c == ':'; }
static int is_slash(int c) { return IS_DIR_SEPARATOR(c); }
static int is_semicolon(int c) { return c == ';'; }
static int is_dot(int c) { return c == '.'; }
static int is_null(int c) { return c == '\0'; }

/*
 * Parses a word from string `S' until either:
 *	1) character `DELIM' is found
 *	2) end of string is reached
 *	3) a non valid character is found
 * Output is either
 *	1) :error in case (3) above
 *	2) :wild, :wild-inferiors, :up
 *	3) "" or ECL_NIL when word has no elements
 *	5) A non empty string
 */
static cl_object
parse_word(cl_object s, delim_fn delim, int flags, cl_index start,
	   cl_index end, cl_index *end_of_word)
{
	cl_index i, j, last_delim = end;
	bool wild_inferiors = FALSE;

	i = j = start;
	for (; i < end; i++) {
		bool valid_char;
		cl_index c = ecl_char(s, i);
		if (delim(c)) {
			if ((i == start) && (flags & WORD_ALLOW_LEADING_DOT)) {
				/* Leading dot is included */
				continue;
			}
			last_delim = i;
			if (!(flags & WORD_SEARCH_LAST_DOT)) {
				break;
			}
		}
		if (c == '*') {
			if (!(flags & WORD_ALLOW_ASTERISK))
				valid_char = FALSE; /* Asterisks not allowed in this word */
			else {
				wild_inferiors = (i > start && ecl_char(s, i-1) == '*');
				valid_char = TRUE; /* single "*" */
			}
		} else if (c == ';' && (flags & WORD_DISALLOW_SEMICOLON)) {
			valid_char = 0;
		} else if (c == '/' && (flags & WORD_DISALLOW_SLASH)) {
			valid_char = 0;
		} else {
			valid_char = c != 0;
		}
		if (!valid_char) {
			*end_of_word = start;
			return ECL_SYM(":ERROR",1229);
		}
	}
	if (i > last_delim) {
		/* Go back to the position of the last delimiter */
		i = last_delim;
	}
	if (i < end) {
		*end_of_word = i+1;
	} else {
		*end_of_word = end;
		/* We have reached the end of the string without finding
		   the proper delimiter */
		if (flags & WORD_INCLUDE_DELIM) {
			*end_of_word = start;
			return ECL_NIL;
		}
	}
	switch(i-j) {
	case 0:
		if (flags & WORD_EMPTY_IS_NIL)
			return ECL_NIL;
		return cl_core.null_string;
	case 1:
		if (ecl_char(s,j) == '*')
			return ECL_SYM(":WILD",1327);
		break;
	case 2: {
		cl_index c0 = ecl_char(s,j);
		cl_index c1 = ecl_char(s,j+1);
		if (c0 == '*' && c1 == '*')
			return ECL_SYM(":WILD-INFERIORS",1328);
		if (!(flags & WORD_LOGICAL) && c0 == '.' && c1 == '.')
			return ECL_SYM(":UP",1321);
		break;
	}
	default:
		if (wild_inferiors)	/* '**' surrounded by other characters */
			return ECL_SYM(":ERROR",1229);
	}
	return make_one(s, j, i);
}

/*
 * Parses a logical or physical directory tree. Output is always a
 * list of valid directory components, which may be just NIL.
 *
 * INV: When parsing of directory components has failed, a valid list
 * is also returned, and it will be later in the parsing of
 * pathname-name or pathname-type when the same error is detected.
 */

static cl_object
parse_directories(cl_object s, int flags, cl_index start, cl_index end,
		  cl_index *end_of_dir)
{
	cl_index i, j;
	cl_object path = ECL_NIL;
	delim_fn delim = (flags & WORD_LOGICAL) ? is_semicolon : is_slash;

	flags |= WORD_INCLUDE_DELIM | WORD_ALLOW_ASTERISK;
	*end_of_dir = start;
	for (i = j = start; i < end; j = i) {
		cl_object part = parse_word(s, delim, flags, j, end, &i);
		if (part == ECL_SYM(":ERROR",1229) || part == ECL_NIL)
			break;
		if (part == cl_core.null_string) {  /* "/", ";" */
			if (j != start) {
				if (flags & WORD_LOGICAL)
					return ECL_SYM(":ERROR",1229);
				*end_of_dir = i;
				continue;
			}
			part = (flags & WORD_LOGICAL) ? ECL_SYM(":RELATIVE",1299) : ECL_SYM(":ABSOLUTE",1196);
		}
		*end_of_dir = i;
		path = ecl_cons(part, path);
	}
	return cl_nreverse(path);
}

bool
ecl_logical_hostname_p(cl_object host)
{
	if (!ecl_stringp(host))
		return FALSE;
	return !Null(cl_assoc(4, host, cl_core.pathname_translations, ECL_SYM(":TEST",1316), ECL_SYM("STRING-EQUAL",808)));
}

/*
 * Parses a lisp namestring until the whole substring is parsed or an
 * error is found. It returns a valid pathname or NIL, plus the place
 * where parsing ended in *END_OF_PARSING.
 *
 * The rules are as follows:
 *
 * 1) If a hostname is supplied it determines whether the namestring
 *    will be parsed as logical or as physical.
 *
 * 2) If no hostname is supplied, first it tries parsing using logical
 *    pathname rules and, if no logical hostname is found, then it
 *    tries the physical pathname format.
 *
 * 3) Logical pathname syntax:
 *	[logical-hostname:][;][logical-directory-component;][pathname-name][.pathname-type]
 *
 * 4) Physical pathname syntax:
 *	[device:][[//hostname]/][directory-component/]*[pathname-name][.pathname-type]
 *
 *	logical-hostname, device, hostname = word
 *	logical-directory-component = word | wildcard-word
 *	directory-component = word | wildcard-word | '..' | '.'
 *	pathname-name, pathname-type = word | wildcard-word | ""
 *
 */
cl_object
ecl_parse_namestring(cl_object s, cl_index start, cl_index end, cl_index *ep,
		     cl_object default_host)
{
	cl_object host, device, path, name, type, aux, version;
	bool logical;

	if (start == end) {
		host = device = path = name = type = aux = version = ECL_NIL;
		logical = 0;
		goto make_it;
	}
	/* We first try parsing as logical-pathname. In case of
	 * failure, physical-pathname parsing is performed only when
	 * there is no supplied *logical* host name. All other failures
	 * result in ECL_NIL as output.
	 */
	host = parse_word(s, is_colon, WORD_LOGICAL | WORD_INCLUDE_DELIM |
			  WORD_DISALLOW_SEMICOLON, start, end, ep);
	if (default_host != ECL_NIL) {
		if (host == ECL_NIL || host == ECL_SYM(":ERROR",1229))
			host = default_host;
	}
	if (!ecl_logical_hostname_p(host))
		goto physical;
	/*
	 * Logical pathname format:
	 *	[logical-hostname:][;][logical-directory-component;][pathname-name][.pathname-type]
	 */
	logical = TRUE;
	device = ECL_SYM(":UNSPECIFIC",1319);
	path = parse_directories(s, WORD_LOGICAL, *ep, end, ep);
	if (CONSP(path)) {
		if (ECL_CONS_CAR(path) != ECL_SYM(":RELATIVE",1299) &&
		    ECL_CONS_CAR(path) != ECL_SYM(":ABSOLUTE",1196))
			path = CONS(ECL_SYM(":ABSOLUTE",1196), path);
		path = destructively_check_directory(path, TRUE, FALSE);
	} else {
		path = CONS(ECL_SYM(":ABSOLUTE",1196), path);
	}
	if (path == ECL_SYM(":ERROR",1229))
		return ECL_NIL;
	name = parse_word(s, is_dot, WORD_LOGICAL | WORD_ALLOW_ASTERISK |
			  WORD_EMPTY_IS_NIL, *ep, end, ep);
	if (name == ECL_SYM(":ERROR",1229))
		return ECL_NIL;
	type = ECL_NIL;
	version = ECL_NIL;
	if (*ep == start || ecl_char(s, *ep-1) != '.')
		goto make_it;
	type = parse_word(s, is_dot, WORD_LOGICAL | WORD_ALLOW_ASTERISK |
			  WORD_EMPTY_IS_NIL, *ep, end, ep);
	if (type == ECL_SYM(":ERROR",1229))
		return ECL_NIL;
	if (*ep == start || ecl_char(s, *ep-1) != '.')
		goto make_it;
	aux = parse_word(s, is_null, WORD_LOGICAL | WORD_ALLOW_ASTERISK |
			 WORD_EMPTY_IS_NIL, *ep, end, ep);
	if (aux == ECL_SYM(":ERROR",1229)) {
		return ECL_NIL;
	} else if (ECL_SYMBOLP(aux)) {
		version = aux;
	} else {
		const cl_env_ptr the_env = ecl_process_env();
		cl_object parsed_length;
		version = cl_parse_integer(3, aux, ECL_SYM(":JUNK-ALLOWED",1261), ECL_T);
		parsed_length = ecl_nth_value(the_env, 1);
		if (ecl_fixnum(parsed_length) == ecl_length(aux) &&
		    cl_integerp(version) != ECL_NIL && ecl_plusp(version))
			;
		else if (cl_string_equal(2, aux, ECL_SYM(":NEWEST",1276)) != ECL_NIL)
			version = ECL_SYM(":NEWEST",1276);
		else
			return ECL_NIL;
	}
	goto make_it;
 physical:
	/*
	 * Physical pathname format:
	 *	[[device:[//hostname]]/][directory-component/]*[pathname-name][.pathname-type]
	 */
	logical = FALSE;
	/* We only parse a hostname when the device was present. This
	 * requisite is a bit stupid and only applies to the Unix port,
	 * where "//home/" is equivalent to "/home" However, in Windows
	 * we need "//FOO/" to be separately handled, for it is a shared
	 * resource.
	 */
#if defined(ECL_MS_WINDOWS_HOST)
	if ((start+1 <= end) && is_slash(ecl_char(s, start))) {
		device = ECL_NIL;
		goto maybe_parse_host;
	}
#endif
	device = parse_word(s, is_colon, WORD_INCLUDE_DELIM | WORD_EMPTY_IS_NIL |
			    WORD_DISALLOW_SLASH, start, end, ep);
	if (device == ECL_SYM(":ERROR",1229) || device == ECL_NIL) {
		device = ECL_NIL;
		host = ECL_NIL;
		goto done_device_and_host;
	}
	if (!ecl_stringp(device)) {
		return ECL_NIL;
	}
 maybe_parse_host:
	/* Files have no effective device. */
	if (cl_string_equal(2, device, ECL_SYM(":FILE",1237)) == ECL_T)
		device = ECL_NIL;
	start = *ep;
	host = ECL_NIL;
	if ((start+2) <= end && is_slash(ecl_char(s, start)) &&
	    is_slash(ecl_char(s, start+1)))
	{
		host = parse_word(s, is_slash, WORD_EMPTY_IS_NIL,
				  start+2, end, ep);
		if (host == ECL_SYM(":ERROR",1229)) {
			host = ECL_NIL;
		} else if (host != ECL_NIL) {
			if (!ecl_stringp(host))
				return ECL_NIL;
			start = *ep;
			if (is_slash(ecl_char(s,--start)))
				*ep = start;
		}
	}
	if (ecl_length(device) == 0)
		device = ECL_NIL;
 done_device_and_host:
	path = parse_directories(s, 0, *ep, end, ep);
	if (CONSP(path)) {
		if (ECL_CONS_CAR(path) != ECL_SYM(":RELATIVE",1299) &&
		    ECL_CONS_CAR(path) != ECL_SYM(":ABSOLUTE",1196))
			path = CONS(ECL_SYM(":RELATIVE",1299), path);
		path = destructively_check_directory(path, FALSE, FALSE);
	}
	if (path == ECL_SYM(":ERROR",1229))
		return ECL_NIL;
	start = *ep;
	name = parse_word(s, is_dot,
			  WORD_ALLOW_LEADING_DOT | WORD_SEARCH_LAST_DOT |
			  WORD_ALLOW_ASTERISK | WORD_EMPTY_IS_NIL,
			  start, end, ep);
	if (name == ECL_SYM(":ERROR",1229))
		return ECL_NIL;
	if ((*ep - start) <= 1 || ecl_char(s, *ep-1) != '.') {
		type = ECL_NIL;
	} else {
		type = parse_word(s, is_null, WORD_ALLOW_ASTERISK, *ep, end, ep);
		if (type == ECL_SYM(":ERROR",1229))
			return ECL_NIL;
	}
	version = (name != ECL_NIL || type != ECL_NIL) ? ECL_SYM(":NEWEST",1276) : ECL_NIL;
 make_it:
	if (*ep >= end) *ep = end;
	path = ecl_make_pathname(host, device, path, name, type, version,
                                 ECL_SYM(":LOCAL",1268));
	path->pathname.logical = logical;
	return tilde_expand(path);
}

cl_object
si_default_pathname_defaults(void)
{
	/* This routine outputs the value of *default-pathname-defaults*
	 * coerced to type PATHNAME. Special care is taken so that we do
	 * not enter an infinite loop when using PARSE-NAMESTRING, because
	 * this routine might itself try to use the value of this variable. */
	cl_object path = ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32));
	unlikely_if (!ECL_PATHNAMEP(path)) {
		const cl_env_ptr the_env = ecl_process_env();
		ecl_bds_bind(the_env, ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32), si_getcwd(0));
                FEwrong_type_key_arg(ecl_make_fixnum(/*PATHNAME*/630), ecl_make_fixnum(/**DEFAULT-PATHNAME-DEFAULTS**/32),
                                     path, ECL_SYM("PATHNAME",630));
	}
	{
#line 744
		const cl_env_ptr the_env = ecl_process_env();
#line 744
		#line 744
		cl_object __value0 = path;
#line 744
		the_env->nvalues = 1;
#line 744
		return __value0;
#line 744
	}

}

cl_object
cl_pathname(cl_object x)
{
L:
	switch (ecl_t_of(x)) {
#ifdef ECL_UNICODE
	case t_string:
#endif
	case t_base_string:
		x = cl_parse_namestring(1, x);
	case t_pathname:
		break;
	case t_stream:
		switch ((enum ecl_smmode)x->stream.mode) {
		case ecl_smm_input:
		case ecl_smm_output:
		case ecl_smm_probe:
		case ecl_smm_io:
		case ecl_smm_input_file:
		case ecl_smm_output_file:
		case ecl_smm_io_file:
			x = IO_STREAM_FILENAME(x);
			goto L;
		case ecl_smm_synonym:
			x = SYNONYM_STREAM_STREAM(x);
			goto L;
		default:
			;/* Fall through to error message */
		}
	default: {
                const char *type = "(OR FILE-STREAM STRING PATHNAME)";
                FEwrong_type_only_arg(ecl_make_fixnum(/*PATHNAME*/630), x, ecl_read_from_cstring(type));
        }
	}
	{
#line 781
		const cl_env_ptr the_env = ecl_process_env();
#line 781
		#line 781
		cl_object __value0 = x;
#line 781
		the_env->nvalues = 1;
#line 781
		return __value0;
#line 781
	}

}

cl_object
cl_logical_pathname(cl_object x)
{
	x = cl_pathname(x);
	if (!x->pathname.logical) {
		cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM(":FORMAT-CONTROL",1240),
			 make_constant_base_string("~S cannot be coerced to a logical pathname."),
			 ECL_SYM(":FORMAT-ARGUMENTS",1239), cl_list(1, x),
			 ECL_SYM(":EXPECTED-TYPE",1232), ECL_SYM("LOGICAL-PATHNAME",498),
			 ECL_SYM(":DATUM",1214), x);
	}
	{
#line 795
		const cl_env_ptr the_env = ecl_process_env();
#line 795
		#line 795
		cl_object __value0 = x;
#line 795
		the_env->nvalues = 1;
#line 795
		return __value0;
#line 795
	}
;
}

/* FIXME! WILD-PATHNAME-P is missing! */
#line 799
cl_object cl_wild_pathname_p(cl_narg narg, cl_object pathname, ...)
{
#line 799

	bool checked = 0;
#line 802
	const cl_env_ptr the_env = ecl_process_env();
#line 802
	cl_object component;
#line 802
	va_list ARGS;
	va_start(ARGS, pathname);
#line 802
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(906));
#line 802
	if (narg > 1) {
#line 802
		component = va_arg(ARGS,cl_object);
#line 802
	} else {
#line 802
		component = ECL_NIL;
#line 802
	}
#line 802
	pathname = cl_pathname(pathname);
	if (component == ECL_NIL || component == ECL_SYM(":HOST",1243)) {
		if (pathname->pathname.host == ECL_SYM(":WILD",1327))
			{
#line 805
				#line 805
				cl_object __value0 = ECL_T;
#line 805
				the_env->nvalues = 1;
#line 805
				return __value0;
#line 805
			}
;
		checked = 1;
	}
	if (component == ECL_NIL || component == ECL_SYM(":DEVICE",1217)) {
		if (pathname->pathname.device == ECL_SYM(":WILD",1327))
			{
#line 810
				#line 810
				cl_object __value0 = ECL_T;
#line 810
				the_env->nvalues = 1;
#line 810
				return __value0;
#line 810
			}
;
		checked = 1;
	}
	if (component == ECL_NIL || component == ECL_SYM(":VERSION",1326)) {
		if (pathname->pathname.version == ECL_SYM(":WILD",1327))
			{
#line 815
				#line 815
				cl_object __value0 = ECL_T;
#line 815
				the_env->nvalues = 1;
#line 815
				return __value0;
#line 815
			}
;
		checked = 1;
	}
	if (component == ECL_NIL || component == ECL_SYM(":NAME",1273)) {
		cl_object name = pathname->pathname.name;
		if (name != ECL_NIL &&
		    (name == ECL_SYM(":WILD",1327) || ecl_wild_string_p(name)))
			{
#line 822
				#line 822
				cl_object __value0 = ECL_T;
#line 822
				the_env->nvalues = 1;
#line 822
				return __value0;
#line 822
			}
;
		checked = 1;
	}
	if (component == ECL_NIL || component == ECL_SYM(":TYPE",1318)) {
		cl_object name = pathname->pathname.type;
		if (name != ECL_NIL &&
		    (name == ECL_SYM(":WILD",1327) || ecl_wild_string_p(name)))
			{
#line 829
				#line 829
				cl_object __value0 = ECL_T;
#line 829
				the_env->nvalues = 1;
#line 829
				return __value0;
#line 829
			}
;
		checked = 1;
	}
	if (component == ECL_NIL || component == ECL_SYM(":DIRECTORY",1219)) {
		cl_object list = pathname->pathname.directory;
		checked = 1;
		loop_for_on_unsafe(list) {
			cl_object name = ECL_CONS_CAR(list);
			if (name != ECL_NIL &&
			    (name == ECL_SYM(":WILD",1327) || name == ECL_SYM(":WILD-INFERIORS",1328) ||
			     ecl_wild_string_p(name)))
			{
				{
#line 841
					#line 841
					cl_object __value0 = ECL_T;
#line 841
					the_env->nvalues = 1;
#line 841
					return __value0;
#line 841
				}

			}
		} end_loop_for_on_unsafe(list);
	}
	if (checked == 0) {
		FEerror("~A is not a valid pathname component", 1, component);
	}
	{
#line 848
		#line 848
		cl_object __value0 = ECL_NIL;
#line 848
		the_env->nvalues = 1;
#line 848
		return __value0;
#line 848
	}

}

/*
 * coerce_to_file_pathname(P) converts P to a physical pathname,
 * for a file which is accesible in our filesystem.
 * INV: Wildcards are allowed.
 * INV: A fresh new copy of the pathname is created.
 * INV: The pathname is absolute.
 */
cl_object
coerce_to_file_pathname(cl_object pathname)
{
	pathname = coerce_to_physical_pathname(pathname);
	pathname = cl_merge_pathnames(1, pathname);
#if 0
#if !defined(cygwin) && !defined(ECL_MS_WINDOWS_HOST)
	if (pathname->pathname.device != ECL_NIL)
		FEerror("Device ~S not yet supported.", 1,
			pathname->pathname.device);
	if (pathname->pathname.host != ECL_NIL)
		FEerror("Access to remote files not yet supported.", 0);
#endif
#endif
	if (pathname->pathname.directory == ECL_NIL ||
	    ECL_CONS_CAR(pathname->pathname.directory) == ECL_SYM(":RELATIVE",1299)) {
		pathname = cl_merge_pathnames(2, pathname, si_getcwd(0));
	}
	return pathname;
}

/*
 * coerce_to_physical_pathname(P) converts P to a physical pathname,
 * performing the appropiate transformation if P was a logical pathname.
 */
cl_object
coerce_to_physical_pathname(cl_object x)
{
	x = cl_pathname(x);
	if (x->pathname.logical)
		return cl_translate_logical_pathname(1, x);
	return x;
}

/*
 * si_coerce_to_filename(P) converts P to a physical pathname and then to
 * a namestring. The output must always be a new simple-string which can
 * be used by the C library.
 * INV: No wildcards are allowed.
 */
cl_object
si_coerce_to_filename(cl_object pathname_orig)
{
	cl_object namestring, pathname;

	/* We always go through the pathname representation and thus
	 * cl_namestring() always outputs a fresh new string */
	pathname = coerce_to_file_pathname(pathname_orig);
	if (cl_wild_pathname_p(1,pathname) != ECL_NIL)
		cl_error(3, ECL_SYM("FILE-ERROR",353), ECL_SYM(":PATHNAME",1285), pathname_orig);
	namestring = ecl_namestring(pathname,
                                    ECL_NAMESTRING_TRUNCATE_IF_ERROR |
                                    ECL_NAMESTRING_FORCE_BASE_STRING);
	if (namestring == ECL_NIL) {
		FEerror("Pathname without a physical namestring:"
                        "~% :HOST ~A"
                        "~% :DEVICE ~A"
                        "~% :DIRECTORY ~A"
                        "~% :NAME ~A"
                        "~% :TYPE ~A"
                        "~% :VERSION ~A",
			6, pathname_orig->pathname.host,
                        pathname_orig->pathname.device,
                        pathname_orig->pathname.directory,
                        pathname_orig->pathname.name,
                        pathname_orig->pathname.type,
                        pathname_orig->pathname.version);
	}
	if (cl_core.path_max != -1 &&
	    ecl_length(namestring) >= cl_core.path_max - 16)
		FEerror("Too long filename: ~S.", 1, namestring);
	return namestring;
}

#define default_device(host) ECL_NIL

cl_object
ecl_merge_pathnames(cl_object path, cl_object defaults, cl_object default_version)
{
	cl_object host, device, directory, name, type, version;
        cl_object tocase;

	defaults = cl_pathname(defaults);
	path = cl_parse_namestring(1, path, ECL_NIL, defaults);
	if (Null(host = path->pathname.host))
		host = defaults->pathname.host;
        tocase = host_case(host);
	if (Null(path->pathname.device)) {
		if (Null(path->pathname.host))
			device = cl_pathname_device(3, defaults, ECL_SYM(":CASE",1205), tocase);
		else if (path->pathname.host == defaults->pathname.host)
			device = defaults->pathname.device;
		else
			device = default_device(path->pathname.host);
	} else {
		device = path->pathname.device;
        }
	if (Null(path->pathname.directory)) {
                directory = cl_pathname_directory(3, defaults, ECL_SYM(":CASE",1205), tocase);
        } else if (ECL_CONS_CAR(path->pathname.directory) == ECL_SYM(":ABSOLUTE",1196)) {
		directory = path->pathname.directory;
        } else if (!Null(defaults->pathname.directory)) {
		directory = ecl_append(cl_pathname_directory(3, defaults,
                                                             ECL_SYM(":CASE",1205), tocase),
                                       CDR(path->pathname.directory));
                /* Eliminate redundant :back */
                directory = destructively_check_directory(directory, TRUE, TRUE);
        } else {
		directory = path->pathname.directory;
        }
	if (Null(name = path->pathname.name)) {
		name = cl_pathname_name(3, defaults, ECL_SYM(":CASE",1205), tocase);
        }
	if (Null(type = path->pathname.type)) {
		type = cl_pathname_type(3, defaults, ECL_SYM(":CASE",1205), tocase);
        }
	version = path->pathname.version;
	if (Null(path->pathname.name)) {
		if (Null(version))
			version = defaults->pathname.version;
	}
	if (Null(version)) {
		version = default_version;
	}
        if (default_version == ECL_SYM(":DEFAULT",1215)) {
                if (Null(name) && Null(type)) {
                        version = ECL_NIL;
                } else {
                        version = ECL_SYM(":NEWEST",1276);
                }
        }
	/*
		In this implementation, version is not considered
	*/
	defaults = ecl_make_pathname(host, device, directory, name,
                                     type, version, tocase);
	return defaults;
}

/*
	ecl_namestring(x, flag) converts a pathname to a namestring.
	if flag is true, then the pathname may be coerced to the requirements
	of the filesystem, removing fields that have no meaning (such as
	version, or type, etc); otherwise, when it is not possible to
	produce a readable representation of the pathname, NIL is returned.
*/
cl_object
ecl_namestring(cl_object x, int flags)
{
	bool logical;
	cl_object l, y;
	cl_object buffer, host;
        bool truncate_if_unreadable = flags & ECL_NAMESTRING_TRUNCATE_IF_ERROR;

	x = cl_pathname(x);

	/* INV: Pathnames can only be created by mergin, parsing namestrings
	 * or using ecl_make_pathname(). In all of these cases ECL will complain
	 * at creation time if the pathname has wrong components.
	 */
	buffer = ecl_make_string_output_stream(128, 1);
	logical = x->pathname.logical;
	host = x->pathname.host;
	if (logical) {
		if ((y = x->pathname.device) != ECL_SYM(":UNSPECIFIC",1319) &&
		    truncate_if_unreadable)
			return ECL_NIL;
		if (host != ECL_NIL) {
			si_do_write_sequence(host, buffer, ecl_make_fixnum(0), ECL_NIL);
			writestr_stream(":", buffer);
		}
	} else {
		if ((y = x->pathname.device) != ECL_NIL) {
			si_do_write_sequence(y, buffer, ecl_make_fixnum(0), ECL_NIL);
			writestr_stream(":", buffer);
		}
		if (host != ECL_NIL) {
#if !defined(ECL_MS_WINDOWS_HOST)
			if (y == ECL_NIL) {
				writestr_stream("file:", buffer);
			}
#endif
			writestr_stream("//", buffer);
			si_do_write_sequence(host, buffer, ecl_make_fixnum(0), ECL_NIL);
		}
	}
	l = x->pathname.directory;
	if (ecl_endp(l))
		goto NO_DIRECTORY;
	y = ECL_CONS_CAR(l);
	if (y == ECL_SYM(":RELATIVE",1299)) {
		if (logical)
			ecl_write_char(';', buffer);
	} else {
		if (!logical)
			ecl_write_char(DIR_SEPARATOR, buffer);
	}
	l = ECL_CONS_CDR(l);
	loop_for_in(l) {
		y = ECL_CONS_CAR(l);
		if (y == ECL_SYM(":UP",1321)) {
			writestr_stream("..", buffer);
		} else if (y == ECL_SYM(":WILD",1327)) {
			writestr_stream("*", buffer);
		} else if (y == ECL_SYM(":WILD-INFERIORS",1328)) {
			writestr_stream("**", buffer);
		} else if (y != ECL_SYM(":BACK",1200)) {
			si_do_write_sequence(y, buffer, ecl_make_fixnum(0), ECL_NIL);
		} else {
			/* Directory :back has no namestring representation */
			return ECL_NIL;
		}
		ecl_write_char(logical? ';' : DIR_SEPARATOR, buffer);
	} end_loop_for_in;
NO_DIRECTORY:
	if (ecl_file_position(buffer) == ecl_make_fixnum(0)) {
		if ((ecl_stringp(x->pathname.name) &&
		     ecl_member_char(':', x->pathname.name)) ||
		    (ecl_stringp(x->pathname.type) &&
		     ecl_member_char(':', x->pathname.type)))
			writestr_stream(":", buffer);
	}
	y = x->pathname.name;
	if (y != ECL_NIL) {
		if (y == ECL_SYM(":WILD",1327)) {
			writestr_stream("*", buffer);
		} else {
			si_do_write_sequence(y, buffer, ecl_make_fixnum(0), ECL_NIL);
		}
	} else if (!logical && !Null(x->pathname.type)) {
                /* #P".txt" is :NAME = ".txt" :TYPE = NIL and
                   hence :NAME = NIL and :TYPE != NIL does not have
                   a printed representation */
                return ECL_NIL;
        }
	y = x->pathname.type;
        if (y == ECL_SYM(":UNSPECIFIC",1319)) {
                return ECL_NIL;
        } else if (y != ECL_NIL) {
		if (y == ECL_SYM(":WILD",1327)) {
			writestr_stream(".*", buffer);
		} else {
			writestr_stream(".", buffer);
			si_do_write_sequence(y, buffer, ecl_make_fixnum(0), ECL_NIL);
		}
	}
	y = x->pathname.version;
	if (logical) {
		if (y != ECL_NIL) {
			writestr_stream(".", buffer);
			if (y == ECL_SYM(":WILD",1327)) {
				writestr_stream("*", buffer);
			} else if (y == ECL_SYM(":NEWEST",1276)) {
				si_do_write_sequence(ecl_symbol_name(y), buffer,
						     ecl_make_fixnum(0), ECL_NIL);
			} else {
				/* Since the printer is not reentrant,
				 * we cannot use cl_write and friends.
				 */
				int n = ecl_fixnum(y), i;
				char b[FIXNUM_BITS/2];
				for (i = 0; n; i++) {
					b[i] = n%10 + '0';
					n = n/10;
				}
				if (i == 0)
					b[i++] = '0';
				while (i--) {
					ecl_write_char(b[i], buffer);
				}
			}
		}
	} else if (!truncate_if_unreadable) {
		/* Namestrings of physical pathnames have restrictions... */
		if (Null(x->pathname.name) && Null(x->pathname.type)) {
			/* Directories cannot have a version number */
			if (y != ECL_NIL)
				return ECL_NIL;
		} else if (y != ECL_SYM(":NEWEST",1276)) {
			/* Filenames have an implicit version :newest */
			return ECL_NIL;
		}
	}
        buffer = cl_get_output_stream_string(buffer);
#ifdef ECL_UNICODE
	if (ECL_EXTENDED_STRING_P(buffer) &&
            (flags & ECL_NAMESTRING_FORCE_BASE_STRING)) {
		unlikely_if (!ecl_fits_in_base_string(buffer))
			FEerror("The filesystem does not accept filenames "
                                "with extended characters: ~S",
				1, buffer);
		buffer = si_copy_to_simple_base_string(buffer);
	}
#endif
	return buffer;
}

cl_object
cl_namestring(cl_object x)
{
	{
#line 1158
		const cl_env_ptr the_env = ecl_process_env();
#line 1158
		#line 1158
		cl_object __value0 = ecl_namestring(x, ECL_NAMESTRING_TRUNCATE_IF_ERROR);
#line 1158
		the_env->nvalues = 1;
#line 1158
		return __value0;
#line 1158
	}

}

#line 1164
cl_object cl_parse_namestring(cl_narg narg, cl_object thing, ...)
{
#line 1164

#line 1166
	const cl_env_ptr the_env = ecl_process_env();
#line 1166
	cl_object host;
#line 1166
	cl_object defaults;
#line 1166
	static cl_object KEYS[3] = {(cl_object)(cl_symbols+1310), (cl_object)(cl_symbols+1225), (cl_object)(cl_symbols+1261)};
	cl_object start;
	cl_object end;
	cl_object junk_allowed;
#line 1166
	cl_object output;
#line 1166
	cl_object KEY_VARS[6];
#line 1166
	ecl_va_list ARGS;
	ecl_va_start(ARGS, thing, narg, 1);
#line 1166
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(629));
#line 1166
	if (narg > 1) {
#line 1166
		host = ecl_va_arg(ARGS);
#line 1166
	} else {
#line 1166
		host = ECL_NIL;
#line 1166
	}
#line 1166
	if (narg > 2) {
#line 1166
		defaults = ecl_va_arg(ARGS);
#line 1166
	} else {
#line 1166
		defaults = si_default_pathname_defaults();
#line 1166
	}
#line 1166
	cl_parse_key(ARGS, 3, KEYS, KEY_VARS, NULL, 0);
#line 1166
	if (KEY_VARS[3]==ECL_NIL) {
#line 1166
	  start = ecl_make_fixnum(0);
	} else {
#line 1166
	  start = KEY_VARS[0];
	}
#line 1166
	if (KEY_VARS[4]==ECL_NIL) {
#line 1166
	  end = ECL_NIL;
	} else {
#line 1166
	  end = KEY_VARS[1];
	}
#line 1166
	if (KEY_VARS[5]==ECL_NIL) {
#line 1166
	  junk_allowed = ECL_NIL;
	} else {
#line 1166
	  junk_allowed = KEY_VARS[2];
	}
#line 1166
	output = ECL_NIL;
#line 1166
	if (host != ECL_NIL) {
		host = cl_string(host);
	}
	if (!ecl_stringp(thing)) {
		output = cl_pathname(thing);
	} else {
		cl_object default_host = host;
                cl_index_pair p;
                cl_index ee;
		if (default_host == ECL_NIL && defaults != ECL_NIL) {
			defaults = cl_pathname(defaults);
			default_host = defaults->pathname.host;
		}
#ifdef ECL_UNICODE
		thing = si_coerce_to_base_string(thing);
#endif
		p = ecl_vector_start_end(ecl_make_fixnum(/*PARSE-NAMESTRING*/629), thing, start, end);
		output = ecl_parse_namestring(thing, p.start, p.end, &ee, default_host);
		start = ecl_make_fixnum(ee);
		if (output == ECL_NIL || ee != p.end) {
			if (Null(junk_allowed)) {
				FEparse_error("Cannot parse the namestring ~S~%"
					      "from ~S to ~S.", ECL_NIL,
					      3, thing, start, end);
			}
			goto OUTPUT;
		}
	}
	if (host != ECL_NIL && !ecl_equal(output->pathname.host, host)) {
		FEerror("The pathname ~S does not contain the required host ~S.",
			2, thing, host);
	}
  OUTPUT:
	{
#line 1199
		#line 1199
		cl_object __value0 = output;
#line 1199
		cl_object __value1 = start;
#line 1199
		the_env->nvalues = 2;
#line 1199
		the_env->values[1] = __value1;
#line 1199
		return __value0;
#line 1199
	}

}

#line 1204
cl_object cl_merge_pathnames(cl_narg narg, cl_object path, ...)
{
#line 1204

#line 1206
	const cl_env_ptr the_env = ecl_process_env();
#line 1206
	cl_object defaults;
#line 1206
	cl_object default_version;
#line 1206
	va_list ARGS;
	va_start(ARGS, path);
#line 1206
	if (ecl_unlikely(narg < 1|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(556));
#line 1206
	if (narg > 1) {
#line 1206
		defaults = va_arg(ARGS,cl_object);
#line 1206
	} else {
#line 1206
		defaults = si_default_pathname_defaults();
#line 1206
	}
#line 1206
	if (narg > 2) {
#line 1206
		default_version = va_arg(ARGS,cl_object);
#line 1206
	} else {
#line 1206
		default_version = ECL_SYM(":NEWEST",1276);
#line 1206
	}
#line 1206
	path = cl_pathname(path);
	defaults = cl_pathname(defaults);
	{
#line 1208
		#line 1208
		cl_object __value0 = ecl_merge_pathnames(path, defaults, default_version);
#line 1208
		the_env->nvalues = 1;
#line 1208
		return __value0;
#line 1208
	}

}

#line 1216
cl_object cl_make_pathname(cl_narg narg, ...)
{
#line 1216

#line 1218
	const cl_env_ptr the_env = ecl_process_env();
#line 1218
	static cl_object KEYS[8] = {(cl_object)(cl_symbols+1243), (cl_object)(cl_symbols+1217), (cl_object)(cl_symbols+1219), (cl_object)(cl_symbols+1273), (cl_object)(cl_symbols+1318), (cl_object)(cl_symbols+1326), (cl_object)(cl_symbols+1205), (cl_object)(cl_symbols+1216)};
	cl_object host;
	bool hostp;
	cl_object device;
	bool devicep;
	cl_object directory;
	bool directoryp;
	cl_object name;
	bool namep;
	cl_object type;
	bool typep;
	cl_object version;
	bool versionp;
	cl_object scase;
	cl_object defaults;
#line 1218
	cl_object x;
#line 1218
	cl_object KEY_VARS[16];
#line 1218
	ecl_va_list ARGS;
	ecl_va_start(ARGS, narg, narg, 0);
#line 1218
	if (ecl_unlikely(narg < 0)) FEwrong_num_arguments(ecl_make_fixnum(531));
#line 1218
	cl_parse_key(ARGS, 8, KEYS, KEY_VARS, NULL, 0);
#line 1218
	if (KEY_VARS[8]==ECL_NIL) {
#line 1218
	  host = ECL_NIL;
#line 1218
	  hostp = FALSE;
	} else {
#line 1218
	  hostp = TRUE;
#line 1218
	  host = KEY_VARS[0];
	}
#line 1218
	if (KEY_VARS[9]==ECL_NIL) {
#line 1218
	  device = ECL_NIL;
#line 1218
	  devicep = FALSE;
	} else {
#line 1218
	  devicep = TRUE;
#line 1218
	  device = KEY_VARS[1];
	}
#line 1218
	if (KEY_VARS[10]==ECL_NIL) {
#line 1218
	  directory = ECL_NIL;
#line 1218
	  directoryp = FALSE;
	} else {
#line 1218
	  directoryp = TRUE;
#line 1218
	  directory = KEY_VARS[2];
	}
#line 1218
	if (KEY_VARS[11]==ECL_NIL) {
#line 1218
	  name = ECL_NIL;
#line 1218
	  namep = FALSE;
	} else {
#line 1218
	  namep = TRUE;
#line 1218
	  name = KEY_VARS[3];
	}
#line 1218
	if (KEY_VARS[12]==ECL_NIL) {
#line 1218
	  type = ECL_NIL;
#line 1218
	  typep = FALSE;
	} else {
#line 1218
	  typep = TRUE;
#line 1218
	  type = KEY_VARS[4];
	}
#line 1218
	if (KEY_VARS[13]==ECL_NIL) {
#line 1218
	  version = ECL_NIL;
#line 1218
	  versionp = FALSE;
	} else {
#line 1218
	  versionp = TRUE;
#line 1218
	  version = KEY_VARS[5];
	}
#line 1218
	if (KEY_VARS[14]==ECL_NIL) {
#line 1218
	  scase = ECL_SYM(":LOCAL",1268);
	} else {
#line 1218
	  scase = KEY_VARS[6];
	}
#line 1218
	if (KEY_VARS[15]==ECL_NIL) {
#line 1218
	  defaults = ECL_NIL;
	} else {
#line 1218
	  defaults = KEY_VARS[7];
	}
#line 1218
	x = ECL_NIL;
#line 1218
	if (Null(defaults)) {
		defaults = si_default_pathname_defaults();
		defaults = ecl_make_pathname(defaults->pathname.host,
					     ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL,
                                             ECL_SYM(":LOCAL",1268));
	} else {
		defaults = cl_pathname(defaults);
	}
	if (!hostp) host = defaults->pathname.host;
	x = ecl_make_pathname(host, device, directory, name, type, version, scase);
	if (!devicep) x->pathname.device = defaults->pathname.device;
	if (!directoryp) x->pathname.directory = defaults->pathname.directory;
	if (!namep) x->pathname.name = defaults->pathname.name;
	if (!typep) x->pathname.type = defaults->pathname.type;
	if (!versionp) x->pathname.version = defaults->pathname.version;

	{
#line 1234
		#line 1234
		cl_object __value0 = x;
#line 1234
		the_env->nvalues = 1;
#line 1234
		return __value0;
#line 1234
	}

}

cl_object
cl_pathnamep(cl_object pname)
{
	{
#line 1240
		const cl_env_ptr the_env = ecl_process_env();
#line 1240
		#line 1240
		cl_object __value0 = (ECL_PATHNAMEP(pname) ? ECL_T : ECL_NIL);
#line 1240
		the_env->nvalues = 1;
#line 1240
		return __value0;
#line 1240
	}

}

cl_object
si_logical_pathname_p(cl_object pname)
{
	{
#line 1247
		const cl_env_ptr the_env = ecl_process_env();
#line 1247
		#line 1247
		cl_object __value0 = ((ECL_PATHNAMEP(pname) && pname->pathname.logical)?
		  ECL_T : ECL_NIL);
#line 1247
		the_env->nvalues = 1;
#line 1247
		return __value0;
#line 1247
	}

}

#line 1250
cl_object cl_pathname_host(cl_narg narg, cl_object pname, ...)
{
#line 1250

#line 1252
	const cl_env_ptr the_env = ecl_process_env();
#line 1252
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1205)};
	cl_object scase;
#line 1252
	cl_object KEY_VARS[2];
#line 1252
	ecl_va_list ARGS;
	ecl_va_start(ARGS, pname, narg, 1);
#line 1252
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(633));
#line 1252
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 1252
	if (KEY_VARS[1]==ECL_NIL) {
#line 1252
	  scase = ECL_SYM(":LOCAL",1268);
	} else {
#line 1252
	  scase = KEY_VARS[0];
	}
#line 1252
	pname = cl_pathname(pname);
	{
#line 1255
		#line 1255
		cl_object __value0 = translate_component_case(pname->pathname.host,
                                          normalize_case(pname, ECL_SYM(":LOCAL",1268)),
                                          normalize_case(pname, scase));
#line 1255
		the_env->nvalues = 1;
#line 1255
		return __value0;
#line 1255
	}

}

#line 1258
cl_object cl_pathname_device(cl_narg narg, cl_object pname, ...)
{
#line 1258

#line 1260
	const cl_env_ptr the_env = ecl_process_env();
#line 1260
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1205)};
	cl_object scase;
#line 1260
	cl_object KEY_VARS[2];
#line 1260
	ecl_va_list ARGS;
	ecl_va_start(ARGS, pname, narg, 1);
#line 1260
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(631));
#line 1260
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 1260
	if (KEY_VARS[1]==ECL_NIL) {
#line 1260
	  scase = ECL_SYM(":LOCAL",1268);
	} else {
#line 1260
	  scase = KEY_VARS[0];
	}
#line 1260
	pname = cl_pathname(pname);
	{
#line 1263
		#line 1263
		cl_object __value0 = translate_component_case(pname->pathname.device,
                                          normalize_case(pname, ECL_SYM(":LOCAL",1268)),
                                          normalize_case(pname, scase));
#line 1263
		the_env->nvalues = 1;
#line 1263
		return __value0;
#line 1263
	}

}

#line 1266
cl_object cl_pathname_directory(cl_narg narg, cl_object pname, ...)
{
#line 1266

#line 1268
	const cl_env_ptr the_env = ecl_process_env();
#line 1268
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1205)};
	cl_object scase;
#line 1268
	cl_object KEY_VARS[2];
#line 1268
	ecl_va_list ARGS;
	ecl_va_start(ARGS, pname, narg, 1);
#line 1268
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(632));
#line 1268
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 1268
	if (KEY_VARS[1]==ECL_NIL) {
#line 1268
	  scase = ECL_SYM(":LOCAL",1268);
	} else {
#line 1268
	  scase = KEY_VARS[0];
	}
#line 1268
	pname = cl_pathname(pname);
        {
#line 1271
	#line 1271
	cl_object __value0 = translate_list_case(pname->pathname.directory,
                                     normalize_case(pname, ECL_SYM(":LOCAL",1268)),
                                     normalize_case(pname, scase));
#line 1271
	the_env->nvalues = 1;
#line 1271
	return __value0;
#line 1271
}

}

#line 1274
cl_object cl_pathname_name(cl_narg narg, cl_object pname, ...)
{
#line 1274

#line 1276
	const cl_env_ptr the_env = ecl_process_env();
#line 1276
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1205)};
	cl_object scase;
#line 1276
	cl_object KEY_VARS[2];
#line 1276
	ecl_va_list ARGS;
	ecl_va_start(ARGS, pname, narg, 1);
#line 1276
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(635));
#line 1276
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 1276
	if (KEY_VARS[1]==ECL_NIL) {
#line 1276
	  scase = ECL_SYM(":LOCAL",1268);
	} else {
#line 1276
	  scase = KEY_VARS[0];
	}
#line 1276
	pname = cl_pathname(pname);
	{
#line 1279
		#line 1279
		cl_object __value0 = translate_component_case(pname->pathname.name,
                                          normalize_case(pname, ECL_SYM(":LOCAL",1268)),
                                          normalize_case(pname, scase));
#line 1279
		the_env->nvalues = 1;
#line 1279
		return __value0;
#line 1279
	}

}

#line 1282
cl_object cl_pathname_type(cl_narg narg, cl_object pname, ...)
{
#line 1282

#line 1284
	const cl_env_ptr the_env = ecl_process_env();
#line 1284
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1205)};
	cl_object scase;
#line 1284
	cl_object KEY_VARS[2];
#line 1284
	ecl_va_list ARGS;
	ecl_va_start(ARGS, pname, narg, 1);
#line 1284
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(636));
#line 1284
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 1284
	if (KEY_VARS[1]==ECL_NIL) {
#line 1284
	  scase = ECL_SYM(":LOCAL",1268);
	} else {
#line 1284
	  scase = KEY_VARS[0];
	}
#line 1284
	pname = cl_pathname(pname);
        {
#line 1287
	#line 1287
	cl_object __value0 = translate_component_case(pname->pathname.type,
                                          normalize_case(pname, ECL_SYM(":LOCAL",1268)),
                                          normalize_case(pname, scase));
#line 1287
	the_env->nvalues = 1;
#line 1287
	return __value0;
#line 1287
}

}

cl_object
cl_pathname_version(cl_object pname)
{
	pname = cl_pathname(pname);
	{
#line 1294
		const cl_env_ptr the_env = ecl_process_env();
#line 1294
		#line 1294
		cl_object __value0 = pname->pathname.version;
#line 1294
		the_env->nvalues = 1;
#line 1294
		return __value0;
#line 1294
	}

}

cl_object
cl_file_namestring(cl_object pname)
{
	pname = cl_pathname(pname);
	{
#line 1306
		const cl_env_ptr the_env = ecl_process_env();
#line 1306
		#line 1306
		cl_object __value0 = ecl_namestring(ecl_make_pathname(ECL_NIL, ECL_NIL, ECL_NIL,
						  pname->pathname.name,
						  pname->pathname.type,
						  pname->pathname.version,
                                                  ECL_SYM(":LOCAL",1268)),
				ECL_NAMESTRING_TRUNCATE_IF_ERROR);
#line 1306
		the_env->nvalues = 1;
#line 1306
		return __value0;
#line 1306
	}

}

cl_object
cl_directory_namestring(cl_object pname)
{
	pname = cl_pathname(pname);
	{
#line 1317
		const cl_env_ptr the_env = ecl_process_env();
#line 1317
		#line 1317
		cl_object __value0 = ecl_namestring(ecl_make_pathname(ECL_NIL, ECL_NIL,
						  pname->pathname.directory,
						  ECL_NIL, ECL_NIL, ECL_NIL,
                                                  ECL_SYM(":LOCAL",1268)),
				ECL_NAMESTRING_TRUNCATE_IF_ERROR);
#line 1317
		the_env->nvalues = 1;
#line 1317
		return __value0;
#line 1317
	}

}

cl_object
cl_host_namestring(cl_object pname)
{
	pname = cl_pathname(pname);
	pname = pname->pathname.host;
	if (Null(pname) || pname == ECL_SYM(":WILD",1327))
		pname = cl_core.null_string;
	{
#line 1327
		const cl_env_ptr the_env = ecl_process_env();
#line 1327
		#line 1327
		cl_object __value0 = pname;
#line 1327
		the_env->nvalues = 1;
#line 1327
		return __value0;
#line 1327
	}

}

#define EN_MATCH(p1,p2,el) (ecl_equalp(p1->pathname.el, p2->pathname.el)? ECL_NIL : p1->pathname.el)

#line 1333
cl_object cl_enough_namestring(cl_narg narg, cl_object path, ...)
{
#line 1333

	cl_object newpath, pathdir, defaultdir, fname;
#line 1336
	const cl_env_ptr the_env = ecl_process_env();
#line 1336
	cl_object defaults;
#line 1336
	va_list ARGS;
	va_start(ARGS, path);
#line 1336
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(331));
#line 1336
	if (narg > 1) {
#line 1336
		defaults = va_arg(ARGS,cl_object);
#line 1336
	} else {
#line 1336
		defaults = si_default_pathname_defaults();
#line 1336
	}
#line 1336
	defaults = cl_pathname(defaults);
	path = cl_pathname(path);
	pathdir = path->pathname.directory;
	defaultdir = defaults->pathname.directory;
	if (Null(pathdir)) {
		pathdir = ecl_list1(ECL_SYM(":RELATIVE",1299));
	} else if (Null(defaultdir)) {
		/* The defaults pathname does not have a directory. */
	} else if (ECL_CONS_CAR(pathdir) == ECL_SYM(":RELATIVE",1299)) {
		/* The pathname is relative to the default one one, so we just output the
		   original one */
	} else {
		/* The new pathname is an absolute one. We compare it with the defaults
		   and if they have some common elements, we just output the remaining ones. */
		cl_object dir_begin = funcall(5, ECL_SYM("MISMATCH",559), pathdir, defaultdir,
					      ECL_SYM(":TEST",1316), ECL_SYM("EQUAL",335));
		if (dir_begin == ECL_NIL) {
			pathdir = ECL_NIL;
		} else if (dir_begin == cl_length(defaultdir)) {
			pathdir = funcall(3, ECL_SYM("SUBSEQ",829), pathdir, dir_begin);
			pathdir = CONS(ECL_SYM(":RELATIVE",1299), pathdir);
		}
	}
	fname = EN_MATCH(path, defaults, name);
	if (fname == ECL_NIL) fname = path->pathname.name;
	/* Create a path with all elements that do not match the default */
	newpath
	= ecl_make_pathname(EN_MATCH(path, defaults, host),
			    EN_MATCH(path, defaults, device),
			    pathdir, fname,
			    EN_MATCH(path, defaults, type),
			    EN_MATCH(path, defaults, version),
                            ECL_SYM(":LOCAL",1268));
	newpath->pathname.logical = path->pathname.logical;
	{
#line 1370
		#line 1370
		cl_object __value0 = ecl_namestring(newpath, ECL_NAMESTRING_TRUNCATE_IF_ERROR);
#line 1370
		the_env->nvalues = 1;
#line 1370
		return __value0;
#line 1370
	}

}
#undef EN_MATCH

/* --------------- PATHNAME MATCHING ------------------ */

bool
ecl_wild_string_p(cl_object item)
{
	if (ECL_STRINGP(item)) {
		cl_index i, l = ecl_length(item);
		for (i = 0; i < l; i++) {
			ecl_character c = ecl_char(item, i);
			if (c == '\\' || c == '*' || c == '?')
				return 1;
		}
	}
	return 0;
}

/*
 * Take two C strings and check if the first (s) one matches against
 * the pattern given by the second one (p). The pattern is that of a
 * Unix shell except for brackets and curly braces
 */
bool
ecl_string_match(cl_object s, cl_index j, cl_index ls,
                 cl_object p, cl_index i, cl_index lp)
{
	while (i < lp) {
		cl_index cp = ecl_char(p, i);
                switch (cp) {
                case '*': {
			/* An asterisk in the pattern matches any
			 * number of characters. We try the shortest
			 * sequence that matches. */
			cl_index cn = 0, next;
			for (next = i+1;
			     next < lp && ((cn = ecl_char(p, next)) == '*');
			     next++)
				;
			if (next == lp) {
				return TRUE;
			}
			while (j < ls) {
				if (ecl_string_match(s, j, ls, p, next, lp)) {
					return TRUE;
				}
				j++;
			}
			return FALSE;
                        break;
		}
                case '?':
                        /* Match any character */
                        if (j > ls) return FALSE;
                        i++; j++;
                        break;
                case '\\':
                        /* Interpret a pattern character literally.
                           Trailing slash is interpreted as a slash. */
                        if (++i >= lp) i--;
                default:
                        if ((j >= ls) || (cp != ecl_char(s, j))) {
                                /* Either there are no characters left in "s"
                                 * or the next character does not match. */
                                return FALSE;
                        }
                        i++; j++;
                }
	}
        /* At the end all characters should have been matched */
	return (j >= ls);
}

static bool
path_item_match(cl_object a, cl_object mask) {
	if (mask == ECL_SYM(":WILD",1327))
		return TRUE;
	/* If a component in the tested path is a wildcard field, this
	   can only be matched by the same wildcard field in the mask */
	if (!ecl_stringp(a) || mask == ECL_NIL)
		return (a == mask);
	if (!ecl_stringp(mask))
		FEerror("~S is not supported as mask for pathname-match-p", 1, mask);
	return ecl_string_match(a, 0, ecl_length(a),
                                mask, 0, ecl_length(mask));
}

static bool
path_list_match(cl_object a, cl_object mask) {
	cl_object item_mask;
	while (!ecl_endp(mask)) {
		item_mask = CAR(mask);
		mask = CDR(mask);
		if (item_mask == ECL_SYM(":WILD-INFERIORS",1328)) {
			if (ecl_endp(mask))
				return TRUE;
			while (!ecl_endp(a)) {
				if (path_list_match(a, mask))
					return TRUE;
				a = CDR(a);
			}
			return FALSE;
		} else if (ecl_endp(a)) {
			/* A NIL directory should match against :absolute
			   or :relative, in order to perform suitable translations. */
			if (item_mask != ECL_SYM(":ABSOLUTE",1196) && item_mask != ECL_SYM(":RELATIVE",1299))
				return FALSE;
		} else if (!path_item_match(CAR(a), item_mask)) {
			return FALSE;
		} else {
			a = CDR(a);
		}
	}
	if (!ecl_endp(a))
		return FALSE;
	return TRUE;
}

cl_object
cl_pathname_match_p(cl_object path, cl_object mask)
{
	cl_object output = ECL_NIL;
	path = cl_pathname(path);
	mask = cl_pathname(mask);
	if (path->pathname.logical != mask->pathname.logical)
		goto OUTPUT;
#if 0
	/* INV: This was checked in the calling routine */
	if (!path_item_match(path->pathname.host, mask->pathname.host))
		goto OUTPUT;
#endif
	/* Missing components default to :WILD */
	if (!Null(mask->pathname.directory) &&
	    !path_list_match(path->pathname.directory, mask->pathname.directory))
		goto OUTPUT;
	if (!path_item_match(path->pathname.name, mask->pathname.name))
		goto OUTPUT;
	if (!path_item_match(path->pathname.type, mask->pathname.type))
		goto OUTPUT;
	if (Null(mask->pathname.version) ||
	    path_item_match(path->pathname.version, mask->pathname.version))
		output = ECL_T;
 OUTPUT:
	{
#line 1515
		const cl_env_ptr the_env = ecl_process_env();
#line 1515
		#line 1515
		cl_object __value0 = output;
#line 1515
		the_env->nvalues = 1;
#line 1515
		return __value0;
#line 1515
	}

}

/* --------------- PATHNAME TRANSLATIONS ------------------ */

static cl_object
coerce_to_from_pathname(cl_object x, cl_object host)
{
	switch (ecl_t_of(x)) {
#ifdef ECL_UNICODE
	case t_string:
#endif
	case t_base_string:
		x = cl_parse_namestring(2, x, host);
	case t_pathname:
		if (x->pathname.logical)
			return x;
	default:
		FEerror("~S is not a valid from-pathname translation", 1, x);
	}
}

#line 1537
cl_object si_pathname_translations(cl_narg narg, cl_object host, ...)
{
#line 1537

	cl_index parsed_len, len;
	cl_object pair, l;
#line 1541
	const cl_env_ptr the_env = ecl_process_env();
#line 1541
	cl_object set;
#line 1541
	va_list ARGS;
	va_start(ARGS, host);
#line 1541
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(1116));
#line 1541
	if (narg > 1) {
#line 1541
		set = va_arg(ARGS,cl_object);
#line 1541
	} else {
#line 1541
		set = OBJNULL;
#line 1541
	}
#line 1541
	/* Check that host is a valid host name */
        if (ecl_unlikely(!ECL_STRINGP(host)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::PATHNAME-TRANSLATIONS*/1116), 1, host, ecl_make_fixnum(/*STRING*/805));
	host = cl_string_upcase(1, host);
	len = ecl_length(host);
	parse_word(host, is_null, WORD_LOGICAL, 0, len, &parsed_len);
	if (parsed_len < len) {
		FEerror("Wrong host syntax ~S", 1, host);
	}
	/* Find its translation list */
	pair = cl_assoc(4, host, cl_core.pathname_translations, ECL_SYM(":TEST",1316), ECL_SYM("STRING-EQUAL",808));
	if (set == OBJNULL) {
		{
#line 1553
			#line 1553
			cl_object __value0 = ((pair == ECL_NIL)? ECL_NIL : CADR(pair));
#line 1553
			the_env->nvalues = 1;
#line 1553
			return __value0;
#line 1553
		}
;
	}
	/* Set the new translation list */
        if (ecl_unlikely(!LISTP(set))) {
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::PATHNAME-TRANSLATIONS*/1116), 2, set, ecl_make_fixnum(/*LIST*/481));
        }
	if (pair == ECL_NIL) {
		pair = CONS(host, CONS(ECL_NIL, ECL_NIL));
		cl_core.pathname_translations = CONS(pair, cl_core.pathname_translations);
	}
	for (l = set, set = ECL_NIL; !ecl_endp(l); l = CDR(l)) {
		cl_object item = CAR(l);
		cl_object from = coerce_to_from_pathname(cl_car(item), host);
		cl_object to = cl_pathname(cl_cadr(item));
		set = CONS(CONS(from, CONS(to, ECL_NIL)), set);
	}
	set = cl_nreverse(set);
	ECL_RPLACA(ECL_CONS_CDR(pair), set);
	{
#line 1571
		#line 1571
		cl_object __value0 = set;
#line 1571
		the_env->nvalues = 1;
#line 1571
		return __value0;
#line 1571
	}

}

static cl_object
find_wilds(cl_object l, cl_object source, cl_object match)
{
	cl_index i, j, k, ls, lm;

	if (match == ECL_SYM(":WILD",1327))
		return ecl_list1(source);
	if (!ecl_stringp(match) || !ecl_stringp(source)) {
		if (match != source)
			return ECL_SYM(":ERROR",1229);
		return l;
	}
	ls = ecl_length(source);
	lm = ecl_length(match);
	for(i = j = 0; i < ls && j < lm; ) {
		cl_index pattern_char = ecl_char(match,j);
		if (pattern_char == '*') {
			for (j++, k = i;
			     k < ls && ecl_char(source,k) != pattern_char;
			     k++)
				;
			l = CONS(make_one(source, i, k), l);
			i = k;
			continue;
		}
		if (ecl_char(source,i) != pattern_char)
			return ECL_SYM(":ERROR",1229);
		i++, j++;
	}
	if (i < ls || j < lm)
		return ECL_SYM(":ERROR",1229);
	return l;
}

static cl_object
find_list_wilds(cl_object a, cl_object mask)
{
	cl_object l = ECL_NIL, l2;

	while (!ecl_endp(mask)) {
		cl_object item_mask = CAR(mask);
		mask = CDR(mask);
		if (item_mask == ECL_SYM(":WILD-INFERIORS",1328)) {
			l2 = ECL_NIL;
			while (!path_list_match(a, mask)) {
				if (ecl_endp(a))
					return ECL_SYM(":ERROR",1229);
				l2 = CONS(CAR(a),l2);
				a = CDR(a);
			}
			l = CONS(l2, l);
		} else if (ecl_endp(a)) {
			/* A NIL directory should match against :absolute
			   or :relative, in order to perform suitable translations. */
			if (item_mask != ECL_SYM(":ABSOLUTE",1196) && item_mask != ECL_SYM(":RELATIVE",1299))
				return ECL_SYM(":ERROR",1229);
		} else {
			l2 = find_wilds(l, CAR(a), item_mask);
			if (l == ECL_SYM(":ERROR",1229))
				return ECL_SYM(":ERROR",1229);
			if (!Null(l2))
				l = CONS(l2, l);
			a = CDR(a);
		}
	}
	return cl_nreverse(l);
}

static cl_object
copy_wildcards(cl_object *wilds_list, cl_object pattern)
{
	cl_index i, l, j;
	bool new_string;
	cl_object wilds = *wilds_list, token;

	if (pattern == ECL_SYM(":WILD",1327)) {
		if (ecl_endp(wilds))
			return ECL_SYM(":ERROR",1229);
		pattern = CAR(wilds);
		*wilds_list = CDR(wilds);
		return pattern;
	}
	if (pattern == ECL_SYM(":WILD-INFERIORS",1328))
		return ECL_SYM(":ERROR",1229);
	if (!ecl_stringp(pattern))
		return pattern;

	new_string = FALSE;
	l = ecl_length(pattern);
	token = si_get_buffer_string();
	for (j = i = 0; i < l; ) {
		cl_index c = ecl_char(pattern, i);
		if (c != '*') {
			i++;
			continue;
		}
		if (i != j) {
			push_substring(token, pattern, j, i);
		}
		new_string = TRUE;
		if (ecl_endp(wilds)) {
			return ECL_SYM(":ERROR",1229);
		}
		push_string(token, CAR(wilds));
		wilds = CDR(wilds);
		j = i++;
	}
	/* Only create a new string when needed */
	if (new_string) {
		if (ecl_fits_in_base_string(token)) {
			pattern = si_copy_to_simple_base_string(token);
		} else {
			pattern = cl_copy_seq(token);
		}
	}
	si_put_buffer_string(token);
	*wilds_list = wilds;
	return pattern;
}

static cl_object
copy_list_wildcards(cl_object *wilds, cl_object to)
{
	cl_object l = ECL_NIL;

	while (!ecl_endp(to)) {
		cl_object d, mask = CAR(to);
		if (mask == ECL_SYM(":WILD-INFERIORS",1328)) {
			cl_object list = *wilds;
			if (ecl_endp(list))
				return ECL_SYM(":ERROR",1229);
			else {
				cl_object dirlist = CAR(list);
				if (CONSP(dirlist))
					l = ecl_append(CAR(list), l);
				else if (!Null(CAR(list)))
					return ECL_SYM(":ERROR",1229);
			}
			*wilds = CDR(list);
		} else {
			d = copy_wildcards(wilds, CAR(to));
			if (d == ECL_SYM(":ERROR",1229))
				return d;
			l = CONS(d, l);
		}
		to = CDR(to);
	}
	if (CONSP(l))
		l = cl_nreverse(l);
	return l;
}

#line 1726
cl_object cl_translate_pathname(cl_narg narg, cl_object source, cl_object from, cl_object to, ...)
{
#line 1726

	cl_object wilds, d;
	cl_object host, device, directory, name, type, version;
	cl_object fromcase, tocase;
#line 1731
	const cl_env_ptr the_env = ecl_process_env();
#line 1731
	static cl_object KEYS[1] = {(cl_object)(cl_symbols+1205)};
	cl_object scase;
#line 1731
	cl_object KEY_VARS[2];
#line 1731
	ecl_va_list ARGS;
	ecl_va_start(ARGS, to, narg, 3);
#line 1731
	if (ecl_unlikely(narg < 3)) FEwrong_num_arguments(ecl_make_fixnum(862));
#line 1731
	cl_parse_key(ARGS, 1, KEYS, KEY_VARS, NULL, 0);
#line 1731
	if (KEY_VARS[1]==ECL_NIL) {
#line 1731
	  scase = ECL_SYM(":LOCAL",1268);
	} else {
#line 1731
	  scase = KEY_VARS[0];
	}
#line 1731
	/* The pathname from which we get the data */
	source = cl_pathname(source);
	/* The mask applied to the source pathname */
	from = cl_pathname(from);
	fromcase = normalize_case(from, ECL_SYM(":LOCAL",1268));
	/* The pattern which says what the output should look like */
	to = cl_pathname(to);
	tocase = normalize_case(to, ECL_SYM(":LOCAL",1268));

	if (source->pathname.logical != from->pathname.logical)
		goto error;

	/* Match host names */
	if (cl_string_equal(2, source->pathname.host, from->pathname.host) == ECL_NIL)
		goto error;
	host = to->pathname.host;

	/* Logical pathnames do not have devices. We just overwrite it. */
	device = to->pathname.device;

	/* Match directories */
	wilds = find_list_wilds(source->pathname.directory,
				from->pathname.directory);
	if (wilds == ECL_SYM(":ERROR",1229))	goto error;
	if (Null(to->pathname.directory)) {
                /* Missing components are replaced */
                d = translate_list_case(from->pathname.directory, fromcase, tocase);
        } else {
                wilds = translate_list_case(wilds, fromcase, tocase);
                d = copy_list_wildcards(&wilds, to->pathname.directory);
                if (d == ECL_SYM(":ERROR",1229)) goto error;
                if (wilds != ECL_NIL) goto error2;
        }
	directory = d;

	/* Match name */
	wilds = find_wilds(ECL_NIL, source->pathname.name, from->pathname.name);
	if (wilds == ECL_SYM(":ERROR",1229)) goto error2;
	if (Null(to->pathname.name)) {
                d = translate_component_case(from->pathname.name, fromcase, tocase);
        } else {
                wilds = translate_list_case(wilds, fromcase, tocase);
                d = copy_wildcards(&wilds, to->pathname.name);
                if (d == ECL_SYM(":ERROR",1229)) goto error;
                if (wilds != ECL_NIL) goto error2;
        }
	name = d;

	/* Match type */
	wilds = find_wilds(ECL_NIL, source->pathname.type, from->pathname.type);
	if (wilds == ECL_SYM(":ERROR",1229)) goto error2;
	if (Null(to->pathname.type)) {
                d = translate_component_case(from->pathname.type, fromcase, tocase);
        } else {
                wilds = translate_list_case(wilds, fromcase, tocase);
                d = copy_wildcards(&wilds, to->pathname.type);
                if (d == ECL_SYM(":ERROR",1229)) goto error;
                if (wilds != ECL_NIL) goto error2;
        }
	type = d;

	/* Match version */
	version = to->pathname.version;
	if (from->pathname.version == ECL_SYM(":WILD",1327)) {
		if (to->pathname.version == ECL_SYM(":WILD",1327)) {
			version = source->pathname.version;
		}
	}
	{
#line 1800
		#line 1800
		cl_object __value0 = ecl_make_pathname(host, device, directory, name, type,
				   version, tocase);
#line 1800
		the_env->nvalues = 1;
#line 1800
		return __value0;
#line 1800
	}
;
 error:
	FEerror("~S is not a specialization of path ~S", 2, source, from);
 error2:
	FEerror("Number of wildcards in ~S do not match  ~S", 2, from, to);
}

#line 1807
cl_object cl_translate_logical_pathname(cl_narg narg, cl_object source, ...)
{
#line 1807

	cl_object l, pair;
	cl_object pathname;
#line 1811
	const cl_env_ptr the_env = ecl_process_env();
#line 1811
	cl_object *KEYS = NULL;
#line 1811
	cl_object *KEY_VARS = NULL;
#line 1811
	ecl_va_list ARGS;
	ecl_va_start(ARGS, source, narg, 1);
#line 1811
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(861));
#line 1811
	cl_parse_key(ARGS, 0, KEYS, KEY_VARS, NULL, 0);
#line 1811
	pathname = cl_pathname(source);
 begin:
	if (!pathname->pathname.logical) {
		{
#line 1814
			#line 1814
			cl_object __value0 = pathname;
#line 1814
			the_env->nvalues = 1;
#line 1814
			return __value0;
#line 1814
		}

	}
	l = si_pathname_translations(1, pathname->pathname.host);
	for(; !ecl_endp(l); l = CDR(l)) {
		pair = CAR(l);
		if (!Null(cl_pathname_match_p(pathname, CAR(pair)))) {
			pathname = cl_translate_pathname(3, pathname,
                                                         CAR(pair),
							 CADR(pair));
			goto begin;
		}
	}
	FEerror("~S admits no logical pathname translations", 1, pathname);
}
