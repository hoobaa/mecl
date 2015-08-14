/* ecl/config.h.  Generated from configpre.h by configure.  */
/*
    config.h.in -- Template configuration file.
*/
/*
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECoLisp is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    See file '../Copyright' for full details.
*/

#if defined(_MSC_VER) || defined(__MINGW32__) || __WIN32__ || __WING64__
#define ECL_MS_WINDOWS_HOST
#endif

/*
 * If ECL_API has been predefined, that means we are building the core
 * library and, under windows, we must tell the compiler to export
 * extern functions from the shared library.
 * If ECL_API is not defined, we are simply building an application that
 * uses ECL and, under windows, we must tell the compiler that certain
 * will be imported from a DLL.
 */
#if defined(ECL_MS_WINDOWS_HOST) || defined(cygwin)
# define ECL_DLLEXPORT __declspec(dllexport)
# ifdef ECL_API
#  undef \
   ECL_API /* Avoid autoconf removing this */
#  define ECL_API __declspec(dllexport)
# else
#  define ECL_API __declspec(dllimport)
# endif
#else
# define ECL_DLLEXPORT
# ifdef ECL_API
#  undef \
   ECL_API /* Avoid autoconf removing this */
# endif
# define ECL_API
#endif

/* Decimal number made with the formula yymmvv */
#define ECL_VERSION_NUMBER 121201

/*
 * FEATURES LINKED IN
 */
/* Always use CLOS							*/
#define CLOS

/* Use GNU Multiple Precision library for bignums                       */
#ifndef DPP
#include "gmp.h"
#endif

/* Userland threads?							*/
#define ECL_THREADS 1
#ifdef ECL_THREADS
# if defined(ECL_MS_WINDOWS_HOST)
#  define ECL_WINDOWS_THREADS
# endif
/* # udef ECL_SEMAPHORES */
#define ECL_RWLOCK 1
#endif

/* __thread thread-local variables?                                     */
#ifndef openbsd
/* #undef WITH___THREAD */
#endif

/* Use Boehm's garbage collector					*/
#define GBC_BOEHM 1
#ifdef GBC_BOEHM
# ifdef ECL_THREADS
#   define GC_THREADS		/* For >= 7.2 */
# endif
# define ECL_DYNAMIC_VV
# include "gc.h"
/* GC >= 7.2 defines these macros to intercept thread functions, but
 * in doing so it breaks mingw. */
# if defined(ECL_MS_WINDOWS_HOST) && defined(_beginthreadex)
/* #  undef _beginthread */
/* #  undef _endthread */
/* #  undef _beginthreadex */
/* #  undef _endthreadex */
# endif
#endif
/* #undef ECL_LIBATOMIC_OPS_H */

/* Network streams							*/
#define TCP 1
#if defined(TCP) && defined(ECL_MS_WINDOWS_HOST)
# define ECL_WSOCK
#endif

/* Foreign functions interface						*/
/* #undef ECL_FFI */

/* Support for Unicode strings */
#define ECL_UNICODE 21

/* Allow STREAM operations to work on arbitrary objects			*/
#define ECL_CLOS_STREAMS 1

/* Stack grows downwards						*/
/* #undef ECL_DOWN_STACK */

/* We have libffi and can use it                                        */
/* #undef HAVE_LIBFFI */

/* We have non-portable implementation of FFI calls			*/
/* Only used as a last resort, when libffi is missin                    */
#ifndef HAVE_LIBFFI
/* #undef ECL_DYNAMIC_FFI */
#endif

/* We use hierarchical package names, like in Allegro CL                */
#define ECL_RELATIVE_PACKAGE_NAMES 1

/* Use mprotect for fast interrupt dispatch				*/
#ifndef NACL
#define ECL_USE_MPROTECT 1
#endif
#if defined(ECL_MS_WINDOWS_HOST)
# define ECL_USE_GUARD_PAGE
#endif

/* Integer types                        				*/
#include <stdint.h>
#define ecl_uint8_t uint8_t
#define ecl_int8_t int8_t
#define ecl_uint16_t uint16_t
#define ecl_int16_t int16_t
#define ecl_uint32_t uint32_t
#define ecl_int32_t int32_t
#define ecl_uint64_t uint64_t
#define ecl_int64_t int64_t
/* #undef ecl_long_long_t */
/* #undef ecl_ulong_long_t */

/*
 * C TYPES AND SYSTEM LIMITS
 */
/*
 * The integer type
 *
 * cl_fixnum must be an integer type, large enough to hold a pointer.
 * Ideally, according to the ISOC99 standard, we should use intptr_t,
 * but the required headers are not present in all systems. Hence we
 * use autoconf to guess the following values.
 */
#define ECL_INT_BITS		32
#define ECL_LONG_BITS		32
#define FIXNUM_BITS		32
#define MOST_POSITIVE_FIXNUM	((cl_fixnum)536870911L)
#define MOST_NEGATIVE_FIXNUM	((cl_fixnum)-536870912L)
#define MOST_POSITIVE_FIXNUM_VAL 536870911L
#define MOST_NEGATIVE_FIXNUM_VAL -536870912L

typedef int cl_fixnum;
typedef unsigned int cl_index;
typedef unsigned int cl_hashkey;

/*
 * The character type
 */
#define	ECL_CHAR_CODE_LIMIT	1114112 /* ASCII or unicode character code limit  */
typedef int32_t ecl_character;
typedef unsigned char ecl_base_char;

/*
 * Array limits
 */
#define	ECL_ARRAY_RANK_LIMIT 64	/*  array rank limit  		*/
#ifdef GBC_BOEHM
#define	ECL_ARRAY_DIMENSION_LIMIT 536870911L
#define	ECL_ARRAY_TOTAL_LIMIT 536870911L
#else
#define	ECL_ARRAY_DIMENSION_LIMIT 16*1024*1024
#define	ECL_ARRAY_TOTAL_LIMIT 16*1024*1024
#endif

/*
 * Function limits.
 *
 * In general, any of these limits must fit in a "signed int".
 */
/*	Maximum number of function arguments (arbitrary)		*/
#define ECL_CALL_ARGUMENTS_LIMIT 65536

/*	Maximum number of required arguments				*/
#define ECL_LAMBDA_PARAMETERS_LIMIT ECL_CALL_ARGUMENTS_LIMIT

/*	Numb. of args. which will be passed using the C stack		*/
/*	See cmplam.lsp if you change this value				*/
#define ECL_C_ARGUMENTS_LIMIT 63

/*	Maximum number of output arguments (>= ECL_C_ARGUMENTS_LIMIT)	*/
#define ECL_MULTIPLE_VALUES_LIMIT 64

/* A setjmp that does not save signals					*/
#define ecl_setjmp	_setjmp
#define ecl_longjmp	_longjmp

/*
 * Structure/Instance limits. The index to a slot must fit in the
 * "int" type. We also require ECL_SLOTS_LIMIT <= ECL_CALL_ARGUMENTS_LIMIT
 * because constructors typically require as many arguments as slots,
 * or more.
 */
#define ECL_SLOTS_LIMIT	32768

/* compiler understands long double                                     */
#define ECL_LONG_FLOAT 1
/* compiler understands complex                                         */
/* #undef HAVE_DOUBLE_COMPLEX */
/* #undef HAVE_FLOAT_COMPLEX */

/* We can use small, two-words conses, without type information		*/
#define ECL_SMALL_CONS 1

/* Use CMU Common-Lisp's FORMAT routine					*/
#define ECL_CMU_FORMAT 1

/*
 * C macros for inlining, denoting probable code paths and other stuff
 * that makes better code. Most of it is GCC specific.
 */
#if defined(__cplusplus) || \
    (defined(__GNUC__) &&   \
    (defined(__GNUC_GNU_INLINE__) || defined(__GNUC_STDC_INLINE__)))
#define ECL_INLINE inline
#define ECL_CAN_INLINE 1
#else
#define ECL_INLINE
#define ECL_CAN_INLINE 0
#endif

#if !defined(__GNUC__)
# define ecl_likely(form) (form)
# define ecl_unlikely(form) (form)
# define ecl_attr_noreturn
#else
# if (__GNUC__ < 3)
#  define ecl_likely(form) (form)
#  define ecl_unlikely(form) (form)
# else
#  define ecl_likely(form) __builtin_expect(form,1)
#  define ecl_unlikely(form) __builtin_expect(form,0)
# endif
# if (__GNUC__ < 4)
#  define ecl_attr_noreturn
# else
#  define ecl_attr_noreturn __attribute__((noreturn))
# endif
#endif

#if defined(__SSE2__) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2)
/* #undef ECL_SSE2 */
#endif

/* -CUT-: Everything below this mark will not be installed		*/
/* -------------------------------------------------------------------- *
 *	BUILD OPTIONS WHICH NEED NOT BE EXPORTED			*
 * -------------------------------------------------------------------- */
/*
 * FEATURES LINKED IN:
 */

/* CLX									*/
/* #undef CLX */
/* Locatives								*/
/* #undef LOCATIVE */
/* Use old MIT LOOP macro system					*/
/* #undef ECL_OLD_LOOP */

/* Define this if you want a runtime version only without compiler	*/
/* #undef RUNTIME */
/* Profile tool								*/
/* #undef PROFILE */
/* Program Development Environment					*/
/* #undef PDE */

/* Allow loading dynamically linked code				*/
/* #undef ENABLE_DLOPEN */

/* Undefine this if you do not want ECL to check for circular lists	*/
#define ECL_SAFE

/* Bytecodes and arguments are 8 and 16 bits large, respectively	*/
/* #undef ECL_SMALL_BYTECODES */

/* Assembler implementation of APPLY and friends			*/
/* #undef ECL_ASM_APPLY */

/* Activate Boehm-Weiser incremental garbage collector			*/
/* #undef GBC_BOEHM_GENGC */

/* Activate Boehm-Weiser precise garbage collector			*/
/* #undef GBC_BOEHM_PRECISE */

/* Weak hash tables need the garbage collector and weak	pointers	*/
#ifdef GBC_BOEHM
#define ECL_WEAK_HASH
#endif

/*
 * SYSTEM FEATURES:
 */

/* Argument list can be access as an array				*/
/* #undef ECL_USE_VARARG_AS_POINTER */
/* Most significant byte first						*/
/* #undef WORDS_BIGENDIAN */
/* Has <sys/resource.h>							*/
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_ULIMIT_H 1
/* High precision timer							*/
#define HAVE_NANOSLEEP 1
/* Float version if isnan()						*/
/* #undef HAVE_ISNANF */
/* float.h for epsilons, maximum real numbers, etc			*/
#define HAVE_FLOAT_H 1
/* select()								*/
#ifndef NACL
#define HAVE_SELECT 1
#endif
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_IOCTL_H 1
/* putenv() or setenv()							*/
#define HAVE_SETENV 1
#define HAVE_PUTENV 1
/* times() and sys/times.h						*/
#ifndef NACL
#define HAVE_TIMES 1
#endif
/* gettimeofday() and sys/time.h					*/
#define HAVE_GETTIMEOFDAY 1
/* getrusage() and sys/resource.h					*/
#ifndef NACL
#define HAVE_GETRUSAGE 1
#endif
/* user home directory, user name, etc...				*/
/* #undef HAVE_PW_H */
/* symbolic links and checking their existence				*/
#ifndef NACL
#define HAVE_LSTAT 1
#endif
/* safe creation of temporary files					*/
#define HAVE_MKSTEMP 1
/* timer for userland threads						*/
#define HAVE_ALARM 1
/* filesytem								*/
#define HAVE_DIRENT_H 1
/* dynamic linking of libraries						*/
#define HAVE_DLFCN_H 1
/* #undef HAVE_LINK_H */
#define HAVE_MACH_O_DYLD_H 1
/* POSIX signals							*/
#ifndef NACL
#define HAVE_SIGPROCMASK 1
#endif
/* isatty() checks whether a file is connected to a			*/
#define HAVE_ISATTY 1
/* can manipulate floating point environment				*/
#define HAVE_FENV_H 1
/* can activate individual traps in floating point environment		*/
/* this flag has to be deactivated for the Itanium architecture, where  */
/* the GNU libc functions are broken                                    */
#if !defined(__ia64__) && !defined(PPC)
/* #undef HAVE_FEENABLEEXCEPT */
#endif
/* do we want to deactivate all support for floating point exceptions   */
/* #undef ECL_AVOID_FPE_H */
/* do we want to have signed zeros					*/
#define ECL_SIGNED_ZERO 1
/* do we want NaNs and Infs						*/
#define ECL_IEEE_FP 1
/* has support for large files						*/
#define HAVE_FSEEKO 1
/* the tzset() function gets the current time zone			*/
#define HAVE_TZSET 1
/* several floating point functions (ISO C99)				*/
#if 0
#define HAVE_EXPF 1
#define HAVE_LOGF 1
#define HAVE_SQRTF 1
#define HAVE_COSF 1
#define HAVE_SINF 1
#define HAVE_TANF 1
#define HAVE_SINHF 1
#define HAVE_COSHF 1
#define HAVE_TANHF 1
#endif
#define HAVE_FLOORF 1
#define HAVE_CEILF 1
#define HAVE_FABSF 1
#define HAVE_FREXPF 1
#define HAVE_LDEXPF 1
#define HAVE_LOG1P 1
#define HAVE_LOG1PF 1
#define HAVE_LOG1PL 1
/* #undef HAVE_COPYSIGNF */
#define HAVE_COPYSIGN 1
/* #undef HAVE_COPYSIGNL */
/* whether we have sched_yield() that gives priority to other threads	*/
#define HAVE_SCHED_YIELD 1
/* whether we have a working sem_init()                                 */
/* #undef HAVE_SEM_INIT */
/* whether we have read/write locks                                     */
#define HAVE_POSIX_RWLOCK 1
/* uname() for system identification					*/
#define HAVE_UNAME 1
#define HAVE_UNISTD_H 1
#define HAVE_SYS_WAIT_H 1
#define HAVE_SYS_MMAN_H 1
/* size of long long            					*/
/* #undef ECL_LONG_LONG_BITS */
/* existence of char **environ         					*/
#define HAVE_ENVIRON 1
/* existence of pointer -> function name functions                      */
#define HAVE_DLADDR 1
#define HAVE_BACKTRACE 1
#define HAVE_BACKTRACE_SYMBOLS 1
/* #undef HAVE___BUILTIN_RETURN_ADDRESS */
#define HAVE_SCHED_H 1

/*
 * we do not manage to get proper signal handling of floating point
 * arithmetics in the Alpha chips.
 */
#if defined(__alpha__)
# ifdef HAVE_FENV_H
#  define HAVE_FENV_H 1
# endif
# ifdef HAVE_FEENABLEEXCEPT
/* #  undef HAVE_FEENABLEEXCEPT */
# endif
#endif

/* what characters are used to mark beginning of new line		*/
/* #undef ECL_NEWLINE_IS_CRLF */
/* #undef ECL_NEWLINE_IS_LFCR */

/*
 * PARAMETERS:
 */

/*
 * Memory limits for the old garbage collector.
 */
#define	LISP_PAGESIZE	2048	/* Page size in bytes			*/
#define MAXPAGE	65536		/* Maximum Memory Size			*/

/* We allocate a number of strings in a pool which is used to speed up reading */
#define ECL_MAX_STRING_POOL_SIZE	10
#define ECL_BUFFER_STRING_SIZE		4192

/*
 * Macros that depend on these system features.
 */
#if defined(sparc) || defined(i386) || defined(mips)
#  define	stack_align(n)	(((n) + 0x7) & ~0x7)
#else
#  define	stack_align(n)	(((n) + 03) & ~03)
#endif

/* #undef FILE_CNT */
#if 0 == 1
#  define FILE_CNT(fp)	((fp)->_IO_read_end - (fp)->_IO_read_ptr)
#endif
#if 0 == 2
#  define FILE_CNT(fp)	((fp)->_r)
#endif
#if 0 == 3
#  define FILE_CNT(fp)	((fp)->_cnt)
#endif

#if defined(cygwin) || defined(ECL_MS_WINDOWS_HOST)
#  define IS_DIR_SEPARATOR(x) ((x=='/')||(x=='\\'))
#  define DIR_SEPARATOR		'/'
#  define PATH_SEPARATOR	';'
#else
#  define IS_DIR_SEPARATOR(x) (x=='/')
#  define DIR_SEPARATOR	'/'
#  define PATH_SEPARATOR	':'
#endif

#define ECL_ARCHITECTURE "AARCH64"

#ifdef ECL_AVOID_FPE_H
# define ecl_detect_fpe()
#else
# include "arch/fpe_none.c"
#endif

#ifdef ECL_INCLUDE_MATH_H
# include <math.h>
# ifdef _MSC_VER
/* #  undef complex */
#  define signbit(x) (copysign(1.0,(x)))
# endif
# ifndef isfinite
#  ifdef __sun__
#   ifndef ECL_LONG_FLOAT
#    include <ieeefp.h>
#    define isfinite(x) finite(x)
#   else
#    error "Function isfinite() is missing"
#   endif
#  else
#   define isfinite(x) finite(x)
#  endif
# endif
# ifndef signbit
#  ifndef ECL_SIGNED_ZERO
#   define signbit(x) ((x) < 0)
#  else
#   ifdef HAVE_COPYSIGN
#    define signbit(x) (copysign(1.0,(x)) < 0)
#   else 
     /* Fall back to no signed zero */
#    undef \
     ECL_SIGNED_ZERO
#    define signbit(x) ((x) < 0)
#   endif
#  endif
# endif
/*
 * GCC fails to compile the following code
 * if (f == 0.0) { if (signbit(f)) ... }
 */
# if defined(__sun__) && defined(__GNUC__)
#  undef \
   signbit /* Avoid autoconf removing this */
#  define signbit(x) (copysign(1.0,(x)) < 0)
# endif
#endif

#if defined(HAVE_LIBFFI) && defined(ECL_INCLUDE_FFI_H)
#include ""
#endif
