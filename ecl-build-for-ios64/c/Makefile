#
#			Makefile for ECL core library
#
top_srcdir= /Users/strobolights/dev/mecl/ecl/src
srcdir	= /Users/strobolights/dev/mecl/ecl/src/c
VPATH	= /Users/strobolights/dev/mecl/ecl/src/c

# Programs used by "make":
#
AR	= /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar
CC	= /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang
TRUE_CC = $(CC)
CFLAGS	= -I. -I/Users/strobolights/dev/mecl/ecl-build-for-ios64 -I$(srcdir) -I../ecl/gc -DECL_API -DECL_NO_LEGACY     -g -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -DAPPLE -I/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include -D_THREAD_SAFE -Ddarwin -c

# The following flags could be added and used by GCC
#  -Wall -W -Wfloat-equal -Wundef -Wendif-labels -Wpointer-arith -Wcast-align \
#  -Wwrite-strings -Wconversion -Wsign-compare -Wmissing-prototypes \
#  -Wredundant-decls -Wunreachable-code -Winline

SHELL	= /bin/sh
RM	= rm -f
EXE	= 
DPP	= ./dpp$(EXE)
RANLIB	= /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib

# Data for installation
#
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include

# Files

HDIR	= ../ecl
HFILES	= $(HDIR)/config.h $(HDIR)/ecl.h $(HDIR)/ecl-cmp.h\
	$(HDIR)/object.h $(HDIR)/cs.h $(HDIR)/stacks.h\
	$(HDIR)/external.h $(HDIR)/cons.h $(HDIR)/legacy.h\
	$(HDIR)/number.h $(HDIR)/page.h $(HDIR)/unify.h
OBJS	= main.o symbol.o package.o cons.o list.o\
	apply.o eval.o interpreter.o compiler.o disassembler.o \
	instance.o gfun.o clos/cache.o clos/accessor.o \
	reference.o character.o\
	file.o read.o print.o error.o string.o cfun.o\
	reader/parse_integer.o reader/parse_number.o \
	printer/float_to_digits.o printer/float_to_string.o \
	printer/integer_to_string.o printer/write_ugly.o \
	printer/write_object.o printer/write_symbol.o \
	printer/write_array.o printer/write_list.o printer/write_code.o \
	printer/write_sse.o printer/print_unreadable.o \
	ffi/libraries.o ffi/backtrace.o ffi/mmap.o ffi/cdata.o \
	numbers/cos.o numbers/sin.o numbers/tan.o numbers/atan.o \
	numbers/cosh.o numbers/sinh.o numbers/tanh.o \
	numbers/exp.o numbers/expt.o numbers/log.o \
	numbers/sqrt.o numbers/abs.o \
	numbers/zerop.o numbers/plusp.o numbers/minusp.o \
	numbers/negate.o numbers/conjugate.o \
	numbers/one_plus.o numbers/one_minus.o \
	numbers/plus.o numbers/minus.o numbers/times.o numbers/divide.o \
	numbers/number_compare.o numbers/number_equalp.o numbers/minmax.o \
	numbers/floor.o numbers/ceiling.o numbers/round.o numbers/truncate.o \
	typespec.o assignment.o \
	predicate.o number.o\
	num_pred.o num_arith.o num_co.o\
	num_log.o num_rand.o array.o vector_push.o sequence.o cmpaux.o\
	macros.o backq.o stacks.o \
	time.o unixint.o\
	mapfun.o multival.o hash.o format.o pathname.o\
	structure.o load.o unixfsys.o unixsys.o \
	serialize.o ffi.o sse2.o  big.o threads/process.o threads/queue.o threads/mutex.o threads/condition_variable.o threads/semaphore.o threads/barrier.o threads/mailbox.o threads/rwlock.o alloc_2.o tcp.o unicode/ucd.o unicode/ucd-0000.o unicode/ucd-0016.o unicode/ucd-0032.o unicode/ucd-0048.o unicode/ucd-0064.o unicode/ucd-0080.o unicode/ucd-0096.o threads/atomic.o

.SUFFIXES: .c .o .d .s
.PHONY: all

all:	$(DPP) ../libeclmin.a ../cinit.o

.d.c: $(DPP)
	if test -f ../CROSS-DPP ; then ../CROSS-DPP $< $@ ; else $(DPP) $< $@ ; fi
.d.o: $(DPP)
	if test -f ../CROSS-DPP ; then ../CROSS-DPP $< $@.c ; else $(DPP) $< $@.c ; fi
	$(CC) -DECLDIR="\"${exec_prefix}/lib/ecl-12.12.1\"" $(CFLAGS) -o $@ $@.c
.c.o:
	$(CC) -DECLDIR="\"${exec_prefix}/lib/ecl-12.12.1\"" $(CFLAGS) -o $@ $<
.d.s: $(HFILES)
	if test -f ../CROSS-DPP ; then ../CROSS-DPP $< $@.c ; else $(DPP) $< $@.c ; fi
	$(CC) -DECLDIR="\"${exec_prefix}/lib/ecl-12.12.1\"" $(CFLAGS) -S -o $@ $@.c
#.c.o: $(HFILES)
#	$(CC) -DECLDIR="\"${exec_prefix}/lib/ecl-12.12.1\"" $(CFLAGS) -o $@ $<
apply_x86.c: $(srcdir)/arch/apply_x86.d $(DPP) $(HFILES)
	if test -f ../CROSS-DPP ; then \
	  ../CROSS-DPP $(srcdir)/arch/apply_x86.d $@ ; \
	else $(DPP) $(srcdir)/arch/apply_x86.d  $@ ; \
	fi
ffi_x86.c: $(srcdir)/arch/ffi_x86.d $(DPP) $(HFILES)
	if test -f ../CROSS-DPP ; then \
	  ../CROSS-DPP $(srcdir)/arch/ffi_x86.d $@ ; \
	else $(DPP) $(srcdir)/arch/ffi_x86.d  $@ ; \
	fi
ffi_x86_64.c: $(srcdir)/arch/ffi_x86_64.d $(DPP) $(HFILES)
	if test -f ../CROSS-DPP ; then \
	  ../CROSS-DPP $(srcdir)/arch/ffi_x86_64.d $@ ; \
	else $(DPP) $(srcdir)/arch/ffi_x86_64.d  $@ ; \
	fi

../libeclmin.a: $(OBJS) all_symbols.o all_symbols2.o
	$(RM) $@
	$(AR) cr $@ $(OBJS)
	$(RANLIB) $@

clean:
	$(RM) $(DPP) *.c *.h $(OBJS) all_symbols.o all_symbols2.o ../libecl.a cinit.o core a.out tmp.c

# Build rules

$(DPP): $(srcdir)/dpp.c $(srcdir)/symbols_list2.h
	if test -f ../CROSS-DPP; then touch dpp; else \
	$(TRUE_CC) -I$(srcdir) -I/Users/strobolights/dev/mecl/ecl-build-for-ios64 -I./ $(srcdir)/dpp.c    -g -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -DAPPLE -I/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include -D_THREAD_SAFE -Ddarwin -o $@ ; \
	fi

#
# symbols_list2.h is built this way to allow for an atomic replacement of
# the file. Otherwise we have problem when doing concurrent builds with
# rsync updates of the source tree.
#
$(srcdir)/symbols_list2.h: $(srcdir)/symbols_list.h Makefile
	cat $(srcdir)/symbols_list.h | \
	sed -e 's%{\([A-Z ]*.*".*"\),[^,]*,[ ]*NULL,.*}%{\1,NULL}%g' \
	    -e 's%{\([A-Z ]*.*".*"\),[^,]*,[ ]*\([^,]*\),.*}%{\1,"\2"}%g' \
	    -e 's%{NULL.*%{NULL,NULL}};%' | \
	sed -e 's%"\(IF_[A-Z0-9]*\)(\([^)]*\))"%\1("\2")%g' > tmp.h
	mv tmp.h $@

#
# GCC might break this code
#
gbc.o: gbc.c $(HFILES)
	$(CC) $(CFLAGS) -O0 gbc.c -o $@
#
# This reduces the overhead of jumping to other functions
#
apply.o: apply.c $(HFILES) $(HDIR)/cs.h
	$(CC) $(CFLAGS) apply.c -o $@
#
# These files are interrelated
#
all_symbols.o: all_symbols.c
	$(CC) $(CFLAGS) -I./ all_symbols.c -o $@
all_symbols2.o: all_symbols.c
	$(CC) $(CFLAGS) -DECL_FINAL -I./ all_symbols.c -o $@

#
# This is in another directory
#
../cinit.o: cinit.c $(HFILES)
	$(CC) $(CFLAGS) -I./ cinit.c -o $@
