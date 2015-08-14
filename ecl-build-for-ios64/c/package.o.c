#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/package.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/*
    package.d -- Packages.
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

#include <string.h>
#include <ecl/ecl.h>
#include <ecl/internal.h>
#include <ecl/ecl-inl.h>

/******************************* ------- ******************************/
/*
 * NOTE 1: we only need to use the package locks when reading/writing the hash
 * tables, or changing the fields of a package.  We do not need the locks to
 * read lists from the packages (i.e. list of shadowing symbols, used
 * packages, etc), or from the global environment (cl_core.packages_list) if
 * we do not destructively modify them (For instance, use ecl_remove_eq
 * instead of ecl_delete_eq).
 */
/*
 * NOTE 2: Operations between locks must be guaranteed not fail, or, if
 * they signal an error, they should undo all locks they had before.
 */

static cl_object find_symbol_inner(cl_object name, cl_object p, int *intern_flag);

static void
FEpackage_error(const char *message, cl_object package, int narg, ...)
{
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
	si_signal_simple_error(6,
			       ECL_SYM("PACKAGE-ERROR",618),
			       ECL_NIL, /* not correctable */
			       make_constant_base_string(message), /* format control */
			       narg? cl_grab_rest_args(args) : cl_list(1,package), /* format args */
			       ECL_SYM(":PACKAGE",1284), package); /* extra arguments */
}

void
CEpackage_error(const char *message, const char *continue_message, cl_object package, int narg, ...)
{
	ecl_va_list args;
	ecl_va_start(args, narg, narg, 0);
	si_signal_simple_error(6,
			       ECL_SYM("PACKAGE-ERROR",618),
			       make_constant_base_string(continue_message),
			       make_constant_base_string(message), /* format control */
			       narg? cl_grab_rest_args(args) : cl_list(1,package),
			       ECL_SYM(":PACKAGE",1284), package);
}

static bool
member_string_eq(cl_object x, cl_object l)
{
	/* INV: l is a proper list */
	loop_for_on_unsafe(l) {
		if (ecl_string_eq(x, ECL_CONS_CAR(l)))
			return TRUE;
	} end_loop_for_on_unsafe(l);
	return FALSE;
}

#if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#define INLINE inline
#else
#define INLINE
#endif

static INLINE void
symbol_remove_package(cl_object s, cl_object p)
{
	if (Null(s))
		s = ECL_NIL_SYMBOL;
	if (s->symbol.hpack == p)
		s->symbol.hpack = ECL_NIL;
}

static INLINE void
symbol_add_package(cl_object s, cl_object p)
{
	if (Null(s))
		s = ECL_NIL_SYMBOL;
	if (s->symbol.hpack == ECL_NIL)
		s->symbol.hpack = p;
}

/*
	ecl_make_package(n, ns, ul) makes a package with name n,
	which must be a string or a symbol,
	and nicknames ns, which must be a list of strings or symbols,
	and uses packages in list ul, which must be a list of packages
	or package names i.e. strings or symbols.
*/
static cl_object
make_package_hashtable()
{
	return cl__make_hash_table(ECL_SYM("PACKAGE",617), /* package hash table */
				   ecl_make_fixnum(128), /* initial size */
                                   cl_core.rehash_size,
                                   cl_core.rehash_threshold);
}

static cl_object
alloc_package(cl_object name)
{
        cl_object p = ecl_alloc_object(t_package);
        p->pack.internal = make_package_hashtable();
	p->pack.external = make_package_hashtable();
        p->pack.name = name;
	p->pack.nicknames = ECL_NIL;
	p->pack.shadowings = ECL_NIL;
	p->pack.uses = ECL_NIL;
	p->pack.usedby = ECL_NIL;
	p->pack.locked = FALSE;
        return p;
}

cl_object
_ecl_package_to_be_created(const cl_env_ptr env, cl_object name)
{
        cl_object package = ecl_assoc(name, env->packages_to_be_created);
        if (Null(package)) {
                const cl_env_ptr env = ecl_process_env();
                package = alloc_package(name);
                env->packages_to_be_created =
                        cl_acons(name, package, env->packages_to_be_created);
        } else {
                package = ECL_CONS_CDR(package);
        }
        return package;
}

static cl_object
find_pending_package(cl_env_ptr env, cl_object name, cl_object nicknames)
{
        if (ecl_option_values[ECL_OPT_BOOTED]) {
                cl_object l = env->packages_to_be_created;
		while (!Null(l)) {
			cl_object pair = ECL_CONS_CAR(l);
			cl_object other_name = ECL_CONS_CAR(pair);
			if (ecl_equal(other_name, name) ||
			    _ecl_funcall5(ECL_SYM("MEMBER",552), other_name, nicknames,
					  ECL_SYM(":TEST",1316), ECL_SYM("STRING=",822)) != ECL_NIL)
			{
				cl_object x = ECL_CONS_CDR(pair);
                                env->packages_to_be_created =
                                        ecl_remove_eq(pair,
                                                      env->packages_to_be_created);
                                return x;
			}
			l = ECL_CONS_CDR(l);
		}
        }
        return ECL_NIL;
}

static cl_object
process_nicknames(cl_object nicknames)
{
        cl_object l;
        nicknames = cl_copy_list(nicknames);
        for (l = nicknames; l != ECL_NIL; l = ECL_CONS_CDR(l))
                ECL_RPLACA(l, cl_string(ECL_CONS_CAR(l)));
        return nicknames;
}

static cl_object
process_package_list(cl_object packages)
{
        cl_object l;
        packages = cl_copy_list(packages);
        for (l = packages; l != ECL_NIL; l = ECL_CONS_CDR(l))
                ECL_RPLACA(l, si_coerce_to_package(ECL_CONS_CAR(l)));
        return packages;
}

cl_object
ecl_make_package(cl_object name, cl_object nicknames, cl_object use_list)
{
        const cl_env_ptr env = ecl_process_env();
	cl_object x, other = ECL_NIL;

        /* Type checking, coercions, and the like, happen before we
         * acquire the lock */
	name = cl_string(name);
        nicknames = process_nicknames(nicknames);
        use_list = process_package_list(use_list);

	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(env) {
                /* Find a similarly named package in the list of
                 * packages to be created and use it or try to build a
                 * new package */
                x = find_pending_package(env, name, nicknames);
                if (Null(x)) {
                        other = ecl_find_package_nolock(name);
                        if (other != ECL_NIL) {
                                goto OUTPUT;
                        } else {
                                x = alloc_package(name);
                        }
                }
                loop_for_in(nicknames) {
                        cl_object nick = ECL_CONS_CAR(nicknames);
                        other = ecl_find_package_nolock(nick);
                        if (other != ECL_NIL) {
                                name = nick;
                                goto OUTPUT;
                        }
                        x->pack.nicknames = CONS(nick, x->pack.nicknames);
                } end_loop_for_in;
                loop_for_in(use_list) {
                        cl_object y = ECL_CONS_CAR(use_list);
                        x->pack.uses = CONS(y, x->pack.uses);
                        y->pack.usedby = CONS(x, y->pack.usedby);
                } end_loop_for_in;
                /* Finally, add it to the list of packages */
                cl_core.packages = CONS(x, cl_core.packages);
        OUTPUT:
                (void)0;
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (!Null(other)) {
                CEpackage_error("A package with the name ~A already exists.",
                                "Return existing package",
                                other, 1, name);
                return other;
        }
	return x;
}

cl_object
ecl_rename_package(cl_object x, cl_object name, cl_object nicknames)
{
        bool error;

	name = cl_string(name);
        nicknames = process_nicknames(nicknames);
	x = si_coerce_to_package(x);
	if (x->pack.locked) {
		CEpackage_error("Cannot rename locked package ~S.",
				"Ignore lock and proceed", x, 0);
        }
        nicknames = ecl_cons(name, nicknames);
        error = 0;
	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                cl_object l;
                for (l = nicknames; l != ECL_NIL; l = ECL_CONS_CDR(l)) {
                        cl_object nick = ECL_CONS_CAR(l);
                        cl_object p = ecl_find_package_nolock(nick);
                        if ((p != ECL_NIL) && (p != x)) {
                                name = nick;
                                error = 1;
                                break;
                        }
                }
                if (!error) {
                        x->pack.name = name;
                        x->pack.nicknames = ECL_CONS_CDR(nicknames);
                }
	} ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (error) {
                FEpackage_error("A package with name ~S already exists.", x,
                                1, name);
        }
	return x;
}

/*
	ecl_find_package_nolock(n) seaches for a package with name n, where n is
	a valid string designator, or simply outputs n if it is a
	package.

	This is not a locking routine and someone may replace the list of
	packages while we are scanning it. Nevertheless, the list IS NOT
	be destructively modified, which means that we are on the safe side.
	Routines which need to ensure that the package list remains constant
	should enforce a global lock with PACKAGE_OP_LOCK().
*/
cl_object
ecl_find_package_nolock(cl_object name)
{
	cl_object l, p;

	if (ECL_PACKAGEP(name))
		return name;
	name = cl_string(name);
	l = cl_core.packages;
	loop_for_on_unsafe(l) {
		p = ECL_CONS_CAR(l);
		if (ecl_string_eq(name, p->pack.name))
			return p;
		if (member_string_eq(name, p->pack.nicknames))
			return p;
	} end_loop_for_on_unsafe(l);
#ifdef ECL_RELATIVE_PACKAGE_NAMES
	/* Note that this function may actually be called _before_ symbols are set up
	 * and bound! */
	if (ecl_option_values[ECL_OPT_BOOTED] &&
	    ECL_SYM_VAL(ecl_process_env(), ECL_SYM("SI::*RELATIVE-PACKAGE-NAMES*",1606)) != ECL_NIL) {
		return si_find_relative_package(1, name);
	}
#endif
	return ECL_NIL;
}

cl_object
ecl_find_package(const char *p)
{
	ecl_def_ct_base_string(pack_name,p,strlen(p),,);
	return cl_find_package(pack_name);
}

cl_object
si_coerce_to_package(cl_object p)
{
	/* INV: ecl_find_package_nolock() signals an error if "p" is neither a package
	   nor a string */
	cl_object pp = ecl_find_package_nolock(p);
	if (Null(pp)) {
		FEpackage_error("There exists no package with name ~S", p, 0);
	}
	{
#line 334
		const cl_env_ptr the_env = ecl_process_env();
#line 334
		#line 334
		cl_object __value0 = pp;
#line 334
		the_env->nvalues = 1;
#line 334
		return __value0;
#line 334
	}
;
}

cl_object
ecl_current_package(void)
{
	cl_object x = ecl_symbol_value(ECL_SYM("*PACKAGE*",43));
	unlikely_if (!ECL_PACKAGEP(x)) {
		const cl_env_ptr env = ecl_process_env();
		ECL_SETQ(env, ECL_SYM("*PACKAGE*",43), cl_core.user_package);
		FEerror("The value of *PACKAGE*, ~S, was not a package",
			1, x);
	}
	return x;
}

/*
	Ecl_Intern(st, p) interns string st in package p.
*/
cl_object
_ecl_intern(const char *s, cl_object p)
{
	int intern_flag;
	cl_object str = make_constant_base_string(s);
	return ecl_intern(str, p, &intern_flag);
}

cl_object
ecl_intern(cl_object name, cl_object p, int *intern_flag)
{
	cl_object s;
        bool error, ignore_error = 0;

        if (ecl_unlikely(!ECL_STRINGP(name)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*INTERN*/442), 1, name, ecl_make_fixnum(/*STRING*/805));
	p = si_coerce_to_package(p);
 AGAIN:
        ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                s = find_symbol_inner(name, p, intern_flag);
                if (*intern_flag) {
                        error = 0;
                } else if (p->pack.locked && !ignore_error) {
                        error = 1;
                } else {
                        s = cl_make_symbol(name);
                        s->symbol.hpack = p;
                        *intern_flag = 0;
                        if (p == cl_core.keyword_package) {
                                ecl_symbol_type_set(s, ecl_symbol_type(s) | ecl_stp_constant);
                                ECL_SET(s, s);
                                p->pack.external =
                                        _ecl_sethash(name, p->pack.external, s);
                        } else {
                                p->pack.internal =
                                        _ecl_sethash(name, p->pack.internal, s);
                        }
                        error = 0;
                }
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (error) {
                CEpackage_error("Cannot intern symbol ~S in locked package ~S.",
				"Ignore lock and proceed", p, 2, name, p);
                ignore_error = 1;
                goto AGAIN;
        }
	return s;
}

/*
	find_symbol_inner(st, len, p) searches for string st of length
	len in package p.
*/
static cl_object
find_symbol_inner(cl_object name, cl_object p, int *intern_flag)
{
	cl_object s, ul;

	s = ecl_gethash_safe(name, p->pack.external, OBJNULL);
	if (s != OBJNULL) {
		*intern_flag = ECL_EXTERNAL;
		goto OUTPUT;
	}
	if (p == cl_core.keyword_package)
		goto NOTHING;
	s = ecl_gethash_safe(name, p->pack.internal, OBJNULL);
	if (s != OBJNULL) {
		*intern_flag = ECL_INTERNAL;
		goto OUTPUT;
	}
	ul = p->pack.uses;
	loop_for_on_unsafe(ul) {
		s = ecl_gethash_safe(name, ECL_CONS_CAR(ul)->pack.external, OBJNULL);
		if (s != OBJNULL) {
			*intern_flag = ECL_INHERITED;
			goto OUTPUT;
		}
	} end_loop_for_on_unsafe(ul);
 NOTHING:
	*intern_flag = 0;
	s = ECL_NIL;
 OUTPUT:
	return s;
}

cl_object
ecl_find_symbol(cl_object n, cl_object p, int *intern_flag)
{
        cl_object s;
	if (ecl_unlikely(!ECL_STRINGP(n)))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*FIND-SYMBOL*/369), 1, n, ecl_make_fixnum(/*STRING*/805));
	p = si_coerce_to_package(p);
        ECL_WITH_GLOBAL_ENV_RDLOCK_BEGIN(ecl_process_env()) {
                s = find_symbol_inner(n, p, intern_flag);
        } ECL_WITH_GLOBAL_ENV_RDLOCK_END;
        return s;
}

static cl_object
potential_unintern_conflict(cl_object name, cl_object s, cl_object p)
{
        cl_object x = OBJNULL;
        cl_object l = p->pack.uses;
        loop_for_on_unsafe(l) {
                cl_object other_p = ECL_CONS_CAR(l);
                cl_object y = ecl_gethash_safe(name, other_p->pack.external, OBJNULL);
                if (y != OBJNULL) {
                        if (x == OBJNULL) {
                                x = y;
                        } else if (x != y) {
                                return ecl_cons(x, y);
                        }
                }
        } end_loop_for_on_unsafe(l);
        return ECL_NIL;
}

bool
ecl_unintern(cl_object s, cl_object p)
{
	cl_object conflict;
	bool output = FALSE;
	cl_object name = ecl_symbol_name(s);

	p = si_coerce_to_package(p);
	if (p->pack.locked) {
		CEpackage_error("Cannot unintern symbol ~S from locked package ~S.",
				"Ignore lock and proceed", p, 2, s, p);
	}
        conflict = ECL_NIL;
	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                cl_object hash = p->pack.internal;
                cl_object x = ecl_gethash_safe(name, hash, OBJNULL);
                if (x != s) {
                        hash = p->pack.external;
                        x = ecl_gethash_safe(name, hash, OBJNULL);
                        if (x != s)
                                goto OUTPUT;
                }
                if (ecl_member_eq(s, p->pack.shadowings)) {
                        conflict = potential_unintern_conflict(name, s, p);
                        if (conflict != ECL_NIL) {
                                goto OUTPUT;
                        }
                        p->pack.shadowings = ecl_remove_eq(s, p->pack.shadowings);
                }
                ecl_remhash(name, hash);
                symbol_remove_package(s, p);
                output = TRUE;
        OUTPUT:
                (void)0;
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (conflict != ECL_NIL) {
                FEpackage_error("Cannot unintern the shadowing symbol ~S~%"
                                "from ~S,~%"
                                "because ~S and ~S will cause~%"
                                "a name conflict.", p, 4, s, p,
                                ECL_CONS_CAR(conflict), ECL_CONS_CDR(conflict));
        }
	return output;
}

static cl_object
potential_export_conflict(cl_object name, cl_object s, cl_object p)
{
        cl_object l = p->pack.usedby;
        loop_for_on_unsafe(l) {
                int intern_flag;
                cl_object other_p = ECL_CONS_CAR(l);
                cl_object x = find_symbol_inner(name, other_p, &intern_flag);
                if (intern_flag && s != x &&
                    !ecl_member_eq(x, other_p->pack.shadowings)) {
                        return other_p;
                }
        } end_loop_for_on_unsafe(l);
        return ECL_NIL;
}

void
cl_export2(cl_object s, cl_object p)
{
	int intern_flag, error;
	cl_object other_p, name = ecl_symbol_name(s);
	p = si_coerce_to_package(p);
	if (p->pack.locked)
		CEpackage_error("Cannot export symbol ~S from locked package ~S.",
				"Ignore lock and proceed", p, 2, s, p);
 AGAIN:
        ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                cl_object x = find_symbol_inner(name, p, &intern_flag);
                if (!intern_flag) {
                        error = 1;
                } else if (x != s) {
                        error = 2;
                } else if (intern_flag == ECL_EXTERNAL) {
                        error = 0;
                } else if ((other_p = potential_export_conflict(name, s, p)) != ECL_NIL) {
                        error = 3;
                } else {
                        if (intern_flag == ECL_INTERNAL)
                                ecl_remhash(name, p->pack.internal);
                        p->pack.external = _ecl_sethash(name, p->pack.external, s);
                        error = 0;
                }
	} ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (error == 1) {
		CEpackage_error("The symbol ~S is not accessible from ~S "
                                "and cannot be exported.",
				"Import the symbol in the package and proceed.",
				p, 2, s, p);
                cl_import2(s, p);
                goto AGAIN;
        } else if (error == 2) {
		FEpackage_error("Cannot export the symbol ~S from ~S,~%"
				"because there is already a symbol with the same name~%"
				"in the package.", p, 2, s, p);
        } else if (error == 3) {
                FEpackage_error("Cannot export the symbol ~S~%"
                                "from ~S,~%"
                                "because it will cause a name conflict~%"
                                "in ~S.", p, 3, s, p, other_p);
        } 
}

cl_object
cl_delete_package(cl_object p)
{
	cl_object hash, l;
	cl_index i;

	/* 1) Try to remove the package from the global list */
	p = ecl_find_package_nolock(p);
	if (Null(p)) {
		CEpackage_error("Package ~S not found. Cannot delete it.",
				"Ignore error and continue", p, 0);
		{
#line 588
			const cl_env_ptr the_env = ecl_process_env();
#line 588
			#line 588
			cl_object __value0 = ECL_NIL;
#line 588
			the_env->nvalues = 1;
#line 588
			return __value0;
#line 588
		}
;
	}
	if (p->pack.locked)
		CEpackage_error("Cannot delete locked package ~S.",
				"Ignore lock and proceed", p, 0);
	if (p == cl_core.lisp_package || p == cl_core.keyword_package) {
		FEpackage_error("Cannot remove package ~S", p, 0);
	}

	/* 2) Now remove the package from the other packages that use it
	 *    and empty the package.
	 */
	if (Null(p->pack.name)) {
		{
#line 601
			const cl_env_ptr the_env = ecl_process_env();
#line 601
			#line 601
			cl_object __value0 = ECL_NIL;
#line 601
			the_env->nvalues = 1;
#line 601
			return __value0;
#line 601
		}

	}
        while (!Null(l = p->pack.uses)) {
		ecl_unuse_package(ECL_CONS_CAR(l), p);
	}
        while (!Null(l = p->pack.usedby)) {
		ecl_unuse_package(p, ECL_CONS_CAR(l));
	}

	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                for (hash = p->pack.internal, i = 0; i < hash->hash.size; i++)
                        if (hash->hash.data[i].key != OBJNULL) {
                                cl_object s = hash->hash.data[i].value;
                                symbol_remove_package(s, p);
                        }
                cl_clrhash(p->pack.internal);
                for (hash = p->pack.external, i = 0; i < hash->hash.size; i++)
                        if (hash->hash.data[i].key != OBJNULL) {
                                cl_object s = hash->hash.data[i].value;
                                symbol_remove_package(s, p);
                        }
                cl_clrhash(p->pack.external);
                p->pack.shadowings = ECL_NIL;
                p->pack.name = ECL_NIL;
                /* 2) Only at the end, remove the package from the list of packages. */
                cl_core.packages = ecl_remove_eq(p, cl_core.packages);
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
	{
#line 628
		const cl_env_ptr the_env = ecl_process_env();
#line 628
		#line 628
		cl_object __value0 = ECL_T;
#line 628
		the_env->nvalues = 1;
#line 628
		return __value0;
#line 628
	}

}

void
cl_unexport2(cl_object s, cl_object p)
{
	cl_object name = ecl_symbol_name(s);
	bool error;
	p = si_coerce_to_package(p);
	if (p == cl_core.keyword_package) {
		FEpackage_error("Cannot unexport a symbol from the keyword package.",
				cl_core.keyword_package, 0);
        }
	if (p->pack.locked) {
		CEpackage_error("Cannot unexport symbol ~S from locked package ~S.",
				"Ignore lock and proceed", p, 2, s, p);
        }
	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                int intern_flag;
                cl_object x = find_symbol_inner(name, p, &intern_flag);
                if (intern_flag == 0 || x != s) {
                        error = 1;
                } else if (intern_flag != ECL_EXTERNAL) {
                        /* According to ANSI & Cltl, internal symbols are
                           ignored in unexport */
                        error = 0;
                } else {
                        ecl_remhash(name, p->pack.external);
                        p->pack.internal = _ecl_sethash(name, p->pack.internal, s);
                        error = 0;
                }
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (error) {
		FEpackage_error("Cannot unexport ~S because it does not "
                                "belong to package ~S.",
				p, 2, s, p);
        }
}

void
cl_import2(cl_object s, cl_object p)
{
	int intern_flag, error, ignore_error = 0;
	cl_object name = ecl_symbol_name(s);
	p = si_coerce_to_package(p);
	if (p->pack.locked) {
		CEpackage_error("Cannot import symbol ~S into locked package ~S.",
				"Ignore lock and proceed", p, 2, s, p);
        }
	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                cl_object x = find_symbol_inner(name, p, &intern_flag);
                if (intern_flag) {
                        if (x != s && !ignore_error) {
                                error = 1;
                                goto OUTPUT;
                        }
                        if (intern_flag == ECL_INTERNAL || intern_flag == ECL_EXTERNAL) {
                                error = 0;
                                goto OUTPUT;
                        }
                }
                p->pack.internal = _ecl_sethash(name, p->pack.internal, s);
                symbol_add_package(s, p);
                error = 0;
        OUTPUT:
                (void)0;
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (error) {
                CEpackage_error("Cannot import the symbol ~S "
                                "from package ~A,~%"
                                "because there is already a symbol with the same name~%"
                                "in the package.",
                                "Ignore conflict and proceed", p, 2, s, p);
                ignore_error = 1;
        }
}

void
ecl_shadowing_import(cl_object s, cl_object p)
{
	int intern_flag;
	cl_object x;
	cl_object name = ecl_symbol_name(s);
	p = si_coerce_to_package(p);
	if (p->pack.locked)
		CEpackage_error("Cannot shadowing-import symbol ~S into "
                                "locked package ~S.",
				"Ignore lock and proceed", p, 2, s, p);

	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                x = find_symbol_inner(name, p, &intern_flag);
                if (intern_flag && intern_flag != ECL_INHERITED) {
                        if (x == s) {
                                if (!ecl_member_eq(x, p->pack.shadowings))
                                        p->pack.shadowings
                                                = CONS(x, p->pack.shadowings);
                                goto OUTPUT;
                        }
                        if(ecl_member_eq(x, p->pack.shadowings))
                                p->pack.shadowings =
                                        ecl_remove_eq(x, p->pack.shadowings);
                        if (intern_flag == ECL_INTERNAL)
                                ecl_remhash(name, p->pack.internal);
                        else
                                ecl_remhash(name, p->pack.external);
                        symbol_remove_package(x, p);
                }
                p->pack.shadowings = CONS(s, p->pack.shadowings);
                p->pack.internal = _ecl_sethash(name, p->pack.internal, s);
        OUTPUT:
                (void)0;
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
}

void
ecl_shadow(cl_object s, cl_object p)
{
	int intern_flag;
	cl_object x;

	/* Contrary to CLTL, in ANSI CL, SHADOW operates on strings. */
	s = cl_string(s);
	p = si_coerce_to_package(p);
	if (p->pack.locked)
		CEpackage_error("Cannot shadow symbol ~S in locked package ~S.",
				"Ignore lock and proceed", p, 2, s, p);
	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                x = find_symbol_inner(s, p, &intern_flag);
                if (intern_flag != ECL_INTERNAL && intern_flag != ECL_EXTERNAL) {
                        x = cl_make_symbol(s);
                        p->pack.internal = _ecl_sethash(s, p->pack.internal, x);
                        x->symbol.hpack = p;
                }
                p->pack.shadowings = CONS(x, p->pack.shadowings);
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
}

void
ecl_use_package(cl_object x, cl_object p)
{
	struct ecl_hashtable_entry *hash_entries;
	cl_index i, hash_length;
        cl_object here, there, name;
	int intern_flag, error = 0;

	x = si_coerce_to_package(x);
	if (x == cl_core.keyword_package)
		FEpackage_error("Cannot use keyword package.",
                                cl_core.keyword_package, 0);
	p = si_coerce_to_package(p);
	if (p == x)
		return;
	if (ecl_member_eq(x, p->pack.uses))
		return;
	if (p == cl_core.keyword_package)
		FEpackage_error("Cannot apply USE-PACKAGE on keyword package.",
                                cl_core.keyword_package, 0);
	if (p->pack.locked)
		CEpackage_error("Cannot use package ~S in locked package ~S.",
				"Ignore lock and proceed",
				p, 2, x, p);

	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                hash_entries = x->pack.external->hash.data;
                hash_length = x->pack.external->hash.size;
                for (i = 0, error = 0;  i < hash_length;  i++) {
                        if (hash_entries[i].key != OBJNULL) {
                                here = hash_entries[i].value;
                                name = ecl_symbol_name(here);
                                there = find_symbol_inner(name, p, &intern_flag);
                                if (intern_flag && here != there
                                    && ! ecl_member_eq(there, p->pack.shadowings)) {
                                        error = 1;
                                        break;
                                }
                        }
                }
                if (!error) {
                        p->pack.uses = CONS(x, p->pack.uses);
                        x->pack.usedby = CONS(p, x->pack.usedby);
                }
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
        if (error) {
                FEpackage_error("Cannot use ~S~%"
                                "from ~S,~%"
                                "because ~S and ~S will cause~%"
                                "a name conflict.", p, 4, x, p, here, there);
        }
}

void
ecl_unuse_package(cl_object x, cl_object p)
{
	x = si_coerce_to_package(x);
	p = si_coerce_to_package(p);
	if (p->pack.locked)
		CEpackage_error("Cannot unuse package ~S from locked package ~S.",
				"Ignore lock and proceed",
				p, 2, x, p);
        ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(ecl_process_env()) {
                p->pack.uses = ecl_remove_eq(x, p->pack.uses);
                x->pack.usedby = ecl_remove_eq(p, x->pack.usedby);
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
}

#line 833
cl_object cl_make_package(cl_narg narg, cl_object pack_name, ...)
{
#line 833

#line 835
	const cl_env_ptr the_env = ecl_process_env();
#line 835
	static cl_object KEYS[2] = {(cl_object)(cl_symbols+1277), (cl_object)(cl_symbols+1323)};
	cl_object nicknames;
	cl_object use;
#line 835
	cl_object KEY_VARS[4];
#line 835
	ecl_va_list ARGS;
	ecl_va_start(ARGS, pack_name, narg, 1);
#line 835
	if (ecl_unlikely(narg < 1)) FEwrong_num_arguments(ecl_make_fixnum(530));
#line 835
	cl_parse_key(ARGS, 2, KEYS, KEY_VARS, NULL, 0);
#line 835
	if (KEY_VARS[2]==ECL_NIL) {
#line 835
	  nicknames = ECL_NIL;
	} else {
#line 835
	  nicknames = KEY_VARS[0];
	}
#line 835
	if (KEY_VARS[3]==ECL_NIL) {
#line 835
	  use = CONS(cl_core.lisp_package, ECL_NIL);
	} else {
#line 835
	  use = KEY_VARS[1];
	}
#line 835
	/* INV: ecl_make_package() performs type checking */
	{
#line 836
		#line 836
		cl_object __value0 = ecl_make_package(pack_name, nicknames, use);
#line 836
		the_env->nvalues = 1;
#line 836
		return __value0;
#line 836
	}

}

cl_object
si_select_package(cl_object pack_name)
{
	const cl_env_ptr the_env = ecl_process_env();
	cl_object p = si_coerce_to_package(pack_name);
	ecl_return1(the_env, ECL_SETQ(the_env, ECL_SYM("*PACKAGE*",43), p));
}

cl_object
cl_find_package(cl_object p)
{
	{
#line 850
		const cl_env_ptr the_env = ecl_process_env();
#line 850
		#line 850
		cl_object __value0 = ecl_find_package_nolock(p);
#line 850
		the_env->nvalues = 1;
#line 850
		return __value0;
#line 850
	}

}

cl_object
cl_package_name(cl_object p)
{
	/* FIXME: name should be a fresh one */
	p = si_coerce_to_package(p);
	{
#line 858
		const cl_env_ptr the_env = ecl_process_env();
#line 858
		#line 858
		cl_object __value0 = p->pack.name;
#line 858
		the_env->nvalues = 1;
#line 858
		return __value0;
#line 858
	}

}

cl_object
cl_package_nicknames(cl_object p)
{
	/* FIXME: list should be a fresh one */
	p = si_coerce_to_package(p);
	{
#line 866
		const cl_env_ptr the_env = ecl_process_env();
#line 866
		#line 866
		cl_object __value0 = p->pack.nicknames;
#line 866
		the_env->nvalues = 1;
#line 866
		return __value0;
#line 866
	}

}

#line 869
cl_object cl_rename_package(cl_narg narg, cl_object pack, cl_object new_name, ...)
{
#line 869

#line 871
	const cl_env_ptr the_env = ecl_process_env();
#line 871
	cl_object new_nicknames;
#line 871
	va_list ARGS;
	va_start(ARGS, new_name);
#line 871
	if (ecl_unlikely(narg < 2|| narg > 3)) FEwrong_num_arguments(ecl_make_fixnum(716));
#line 871
	if (narg > 2) {
#line 871
		new_nicknames = va_arg(ARGS,cl_object);
#line 871
	} else {
#line 871
		new_nicknames = ECL_NIL;
#line 871
	}
#line 871
	/* INV: ecl_rename_package() type checks and coerces pack to package */
	{
#line 872
		#line 872
		cl_object __value0 = ecl_rename_package(pack, new_name, new_nicknames);
#line 872
		the_env->nvalues = 1;
#line 872
		return __value0;
#line 872
	}

}

cl_object
cl_package_use_list(cl_object p)
{
	return cl_copy_list(si_coerce_to_package(p)->pack.uses);
}

cl_object
cl_package_used_by_list(cl_object p)
{
	return cl_copy_list(si_coerce_to_package(p)->pack.usedby);
}

cl_object
cl_package_shadowing_symbols(cl_object p)
{
	return cl_copy_list(si_coerce_to_package(p)->pack.shadowings);
}

cl_object
si_package_lock(cl_object p, cl_object t)
{
	bool previous = p->pack.locked;
	p = si_coerce_to_package(p);
	p->pack.locked = (t != ECL_NIL);
	{
#line 899
		const cl_env_ptr the_env = ecl_process_env();
#line 899
		#line 899
		cl_object __value0 = (previous? ECL_T : ECL_NIL);
#line 899
		the_env->nvalues = 1;
#line 899
		return __value0;
#line 899
	}

}

cl_object
cl_list_all_packages()
{
	return cl_copy_list(cl_core.packages);
}

#line 908
cl_object cl_intern(cl_narg narg, cl_object strng, ...)
{
#line 908

	int intern_flag;
#line 911
	const cl_env_ptr the_env = ecl_process_env();
#line 911
	cl_object p;
#line 911
	cl_object sym;
#line 911
	va_list ARGS;
	va_start(ARGS, strng);
#line 911
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(442));
#line 911
	if (narg > 1) {
#line 911
		p = va_arg(ARGS,cl_object);
#line 911
	} else {
#line 911
		p = ecl_current_package();
#line 911
	}
#line 911
	sym = ECL_NIL;
#line 911
	sym = ecl_intern(strng, p, &intern_flag);
	if (intern_flag == ECL_INTERNAL)
		{
#line 913
			#line 913
			cl_object __value0 = sym;
#line 913
			cl_object __value1 = ECL_SYM(":INTERNAL",1258);
#line 913
			the_env->nvalues = 2;
#line 913
			the_env->values[1] = __value1;
#line 913
			return __value0;
#line 913
		}

	if (intern_flag == ECL_EXTERNAL)
		{
#line 915
			#line 915
			cl_object __value0 = sym;
#line 915
			cl_object __value1 = ECL_SYM(":EXTERNAL",1235);
#line 915
			the_env->nvalues = 2;
#line 915
			the_env->values[1] = __value1;
#line 915
			return __value0;
#line 915
		}

	if (intern_flag == ECL_INHERITED)
		{
#line 917
			#line 917
			cl_object __value0 = sym;
#line 917
			cl_object __value1 = ECL_SYM(":INHERITED",1250);
#line 917
			the_env->nvalues = 2;
#line 917
			the_env->values[1] = __value1;
#line 917
			return __value0;
#line 917
		}

	{
#line 918
		#line 918
		cl_object __value0 = sym;
#line 918
		cl_object __value1 = ECL_NIL;
#line 918
		the_env->nvalues = 2;
#line 918
		the_env->values[1] = __value1;
#line 918
		return __value0;
#line 918
	}

}

#line 921
cl_object cl_find_symbol(cl_narg narg, cl_object strng, ...)
{
#line 921

	cl_object x;
	int intern_flag;
#line 925
	const cl_env_ptr the_env = ecl_process_env();
#line 925
	cl_object p;
#line 925
	va_list ARGS;
	va_start(ARGS, strng);
#line 925
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(369));
#line 925
	if (narg > 1) {
#line 925
		p = va_arg(ARGS,cl_object);
#line 925
	} else {
#line 925
		p = ecl_current_package();
#line 925
	}
#line 925
	x = ecl_find_symbol(strng, p, &intern_flag);
	if (intern_flag == ECL_INTERNAL)
		{
#line 927
			#line 927
			cl_object __value0 = x;
#line 927
			cl_object __value1 = ECL_SYM(":INTERNAL",1258);
#line 927
			the_env->nvalues = 2;
#line 927
			the_env->values[1] = __value1;
#line 927
			return __value0;
#line 927
		}

	if (intern_flag == ECL_EXTERNAL)
		{
#line 929
			#line 929
			cl_object __value0 = x;
#line 929
			cl_object __value1 = ECL_SYM(":EXTERNAL",1235);
#line 929
			the_env->nvalues = 2;
#line 929
			the_env->values[1] = __value1;
#line 929
			return __value0;
#line 929
		}

	if (intern_flag == ECL_INHERITED)
		{
#line 931
			#line 931
			cl_object __value0 = x;
#line 931
			cl_object __value1 = ECL_SYM(":INHERITED",1250);
#line 931
			the_env->nvalues = 2;
#line 931
			the_env->values[1] = __value1;
#line 931
			return __value0;
#line 931
		}

	{
#line 932
		#line 932
		cl_object __value0 = ECL_NIL;
#line 932
		cl_object __value1 = ECL_NIL;
#line 932
		the_env->nvalues = 2;
#line 932
		the_env->values[1] = __value1;
#line 932
		return __value0;
#line 932
	}

}

#line 935
cl_object cl_unintern(cl_narg narg, cl_object symbl, ...)
{
#line 935

#line 937
	const cl_env_ptr the_env = ecl_process_env();
#line 937
	cl_object p;
#line 937
	va_list ARGS;
	va_start(ARGS, symbl);
#line 937
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(881));
#line 937
	if (narg > 1) {
#line 937
		p = va_arg(ARGS,cl_object);
#line 937
	} else {
#line 937
		p = ecl_current_package();
#line 937
	}
#line 937
	{
#line 937
		#line 937
		cl_object __value0 = (ecl_unintern(symbl, p) ? ECL_T : ECL_NIL);
#line 937
		the_env->nvalues = 1;
#line 937
		return __value0;
#line 937
	}

}

#line 940
cl_object cl_export(cl_narg narg, cl_object symbols, ...)
{
#line 940

#line 942
	const cl_env_ptr the_env = ecl_process_env();
#line 942
	cl_object pack;
#line 942
	va_list ARGS;
	va_start(ARGS, symbols);
#line 942
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(344));
#line 942
	if (narg > 1) {
#line 942
		pack = va_arg(ARGS,cl_object);
#line 942
	} else {
#line 942
		pack = ecl_current_package();
#line 942
	}
#line 942
	switch (ecl_t_of(symbols)) {
	case t_symbol:
		cl_export2(symbols, pack);
		break;
	case t_list:
		pack = si_coerce_to_package(pack);
		loop_for_in(symbols) {
			cl_export2(ECL_CONS_CAR(symbols), pack);
		} end_loop_for_in;
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*EXPORT*/344),1,symbols,
                                     cl_list(3,ECL_SYM("OR",614),ECL_SYM("SYMBOL",840),ECL_SYM("LIST",481)));
	}
	{
#line 956
		#line 956
		cl_object __value0 = ECL_T;
#line 956
		the_env->nvalues = 1;
#line 956
		return __value0;
#line 956
	}

}

#line 959
cl_object cl_unexport(cl_narg narg, cl_object symbols, ...)
{
#line 959

#line 961
	const cl_env_ptr the_env = ecl_process_env();
#line 961
	cl_object pack;
#line 961
	va_list ARGS;
	va_start(ARGS, symbols);
#line 961
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(880));
#line 961
	if (narg > 1) {
#line 961
		pack = va_arg(ARGS,cl_object);
#line 961
	} else {
#line 961
		pack = ecl_current_package();
#line 961
	}
#line 961
	switch (ecl_t_of(symbols)) {
	case t_symbol:
		cl_unexport2(symbols, pack);
		break;
	case t_list:
		pack = si_coerce_to_package(pack);
		loop_for_in(symbols) {
			cl_unexport2(ECL_CONS_CAR(symbols), pack);
		} end_loop_for_in;
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*UNEXPORT*/880),1,symbols,
                                     cl_list(3,ECL_SYM("OR",614),ECL_SYM("SYMBOL",840),ECL_SYM("LIST",481)));
	}
	{
#line 975
		#line 975
		cl_object __value0 = ECL_T;
#line 975
		the_env->nvalues = 1;
#line 975
		return __value0;
#line 975
	}

}

#line 978
cl_object cl_import(cl_narg narg, cl_object symbols, ...)
{
#line 978

#line 980
	const cl_env_ptr the_env = ecl_process_env();
#line 980
	cl_object pack;
#line 980
	va_list ARGS;
	va_start(ARGS, symbols);
#line 980
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(431));
#line 980
	if (narg > 1) {
#line 980
		pack = va_arg(ARGS,cl_object);
#line 980
	} else {
#line 980
		pack = ecl_current_package();
#line 980
	}
#line 980
	switch (ecl_t_of(symbols)) {
	case t_symbol:
		cl_import2(symbols, pack);
		break;
	case t_list:
		pack = si_coerce_to_package(pack);
		loop_for_in(symbols) {
			cl_import2(ECL_CONS_CAR(symbols), pack);
		} end_loop_for_in;
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*IMPORT*/431),1,symbols,
                                     cl_list(3,ECL_SYM("OR",614),ECL_SYM("SYMBOL",840),ECL_SYM("LIST",481)));
	}
	{
#line 994
		#line 994
		cl_object __value0 = ECL_T;
#line 994
		the_env->nvalues = 1;
#line 994
		return __value0;
#line 994
	}

}

#line 997
cl_object cl_shadowing_import(cl_narg narg, cl_object symbols, ...)
{
#line 997

#line 999
	const cl_env_ptr the_env = ecl_process_env();
#line 999
	cl_object pack;
#line 999
	va_list ARGS;
	va_start(ARGS, symbols);
#line 999
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(754));
#line 999
	if (narg > 1) {
#line 999
		pack = va_arg(ARGS,cl_object);
#line 999
	} else {
#line 999
		pack = ecl_current_package();
#line 999
	}
#line 999
	switch (ecl_t_of(symbols)) {
	case t_symbol:
		ecl_shadowing_import(symbols, pack);
		break;
	case t_list:
		pack = si_coerce_to_package(pack);
		loop_for_in(symbols) {
			ecl_shadowing_import(ECL_CONS_CAR(symbols), pack);
		} end_loop_for_in;
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SHADOWING-IMPORT*/754),1,symbols,
                                     cl_list(3,ECL_SYM("OR",614),ECL_SYM("SYMBOL",840),ECL_SYM("LIST",481)));
	}
	{
#line 1013
		#line 1013
		cl_object __value0 = ECL_T;
#line 1013
		the_env->nvalues = 1;
#line 1013
		return __value0;
#line 1013
	}

}

#line 1016
cl_object cl_shadow(cl_narg narg, cl_object symbols, ...)
{
#line 1016

#line 1018
	const cl_env_ptr the_env = ecl_process_env();
#line 1018
	cl_object pack;
#line 1018
	va_list ARGS;
	va_start(ARGS, symbols);
#line 1018
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(753));
#line 1018
	if (narg > 1) {
#line 1018
		pack = va_arg(ARGS,cl_object);
#line 1018
	} else {
#line 1018
		pack = ecl_current_package();
#line 1018
	}
#line 1018
	switch (ecl_t_of(symbols)) {
#ifdef ECL_UNICODE
	case t_string:
#endif
	case t_base_string:
	case t_symbol:
	case t_character:
		/* Arguments to SHADOW may be: string designators ... */
		ecl_shadow(symbols, pack);
		break;
	case t_list:
		/* ... or lists of string designators */
		pack = si_coerce_to_package(pack);
		loop_for_in(symbols) {
			ecl_shadow(ECL_CONS_CAR(symbols), pack);
		} end_loop_for_in;
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SHADOW*/753),1,symbols,
                                     cl_list(3,ECL_SYM("OR",614),ECL_SYM("SYMBOL",840),ECL_SYM("LIST",481)));
	}
	{
#line 1039
		#line 1039
		cl_object __value0 = ECL_T;
#line 1039
		the_env->nvalues = 1;
#line 1039
		return __value0;
#line 1039
	}

}

#line 1042
cl_object cl_use_package(cl_narg narg, cl_object pack, ...)
{
#line 1042

#line 1044
	const cl_env_ptr the_env = ecl_process_env();
#line 1044
	cl_object pa;
#line 1044
	va_list ARGS;
	va_start(ARGS, pack);
#line 1044
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(892));
#line 1044
	if (narg > 1) {
#line 1044
		pa = va_arg(ARGS,cl_object);
#line 1044
	} else {
#line 1044
		pa = ecl_current_package();
#line 1044
	}
#line 1044
	switch (ecl_t_of(pack)) {
	case t_symbol:
	case t_character:
	case t_base_string:
	case t_package:
		ecl_use_package(pack, pa);
		break;
	case t_list:
		pa = si_coerce_to_package(pa);
		loop_for_in(pack) {
			ecl_use_package(ECL_CONS_CAR(pack), pa);
		} end_loop_for_in;
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*USE-PACKAGE*/892), 1, pack,
                                     ecl_read_from_cstring("(OR SYMBOL CHARACTER STRING LIST PACKAGE)"));
	}
	{
#line 1061
		#line 1061
		cl_object __value0 = ECL_T;
#line 1061
		the_env->nvalues = 1;
#line 1061
		return __value0;
#line 1061
	}

}

#line 1064
cl_object cl_unuse_package(cl_narg narg, cl_object pack, ...)
{
#line 1064

#line 1066
	const cl_env_ptr the_env = ecl_process_env();
#line 1066
	cl_object pa;
#line 1066
	va_list ARGS;
	va_start(ARGS, pack);
#line 1066
	if (ecl_unlikely(narg < 1|| narg > 2)) FEwrong_num_arguments(ecl_make_fixnum(887));
#line 1066
	if (narg > 1) {
#line 1066
		pa = va_arg(ARGS,cl_object);
#line 1066
	} else {
#line 1066
		pa = ecl_current_package();
#line 1066
	}
#line 1066
	switch (ecl_t_of(pack)) {
	case t_symbol:
	case t_character:
	case t_base_string:
	case t_package:
		ecl_unuse_package(pack, pa);
		break;
	case t_list:
		pa = si_coerce_to_package(pa);
		loop_for_in(pack) {
			ecl_unuse_package(ECL_CONS_CAR(pack), pa);
		} end_loop_for_in;
		break;
	default:
                FEwrong_type_nth_arg(ecl_make_fixnum(/*UNUSE-PACKAGE*/887), 1, pack,
                                     ecl_read_from_cstring("(OR SYMBOL CHARACTER STRING LIST PACKAGE)"));
	}
	{
#line 1083
		#line 1083
		cl_object __value0 = ECL_T;
#line 1083
		the_env->nvalues = 1;
#line 1083
		return __value0;
#line 1083
	}

}

cl_object
si_package_hash_tables(cl_object p)
{
	const cl_env_ptr the_env = ecl_process_env();
	cl_object he, hi, u;
        unlikely_if (!ECL_PACKAGEP(p))
                FEwrong_type_only_arg(ecl_make_fixnum(/*SI::PACKAGE-HASH-TABLES*/1115), p, ecl_make_fixnum(/*PACKAGE*/617));
	ECL_WITH_GLOBAL_ENV_WRLOCK_BEGIN(the_env) {
                he = si_copy_hash_table(p->pack.external);
                hi = si_copy_hash_table(p->pack.internal);
                u = cl_copy_list(p->pack.uses);
        } ECL_WITH_GLOBAL_ENV_WRLOCK_END;
	{
#line 1098
		const cl_env_ptr the_env = ecl_process_env();
#line 1098
		#line 1098
		cl_object __value0 = he;
#line 1098
		cl_object __value1 = hi;
#line 1098
		cl_object __value2 = u;
#line 1098
		the_env->nvalues = 3;
#line 1098
		the_env->values[2] = __value2;
#line 1098
		the_env->values[1] = __value1;
#line 1098
		return __value0;
#line 1098
	}

}
