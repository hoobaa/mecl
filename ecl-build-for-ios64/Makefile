#
#		Makefile for ECoLisp
#
top_srcdir= /Users/strobolights/dev/mecl/ecl/src
srcdir	= /Users/strobolights/dev/mecl/ecl/src
mandir=${prefix}/share/man
manext=1

# Programs used by "make":
#


CC	= /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang
LIBS	= -lpthread   -lm 
FASL_LIBS =  -lgmp -lgc
CORE_LIBS = -latomic_ops 
LDFLAGS	=   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   
RM	= rm -f
LN_S	= ln -s
EXE	= 
ETAGS	= etags

# ==================== Where To Install Things ====================

# The default location for installation.  Everything is placed in
# subdirectories of this directory.  The default values for many of
# the variables below are expressed in terms of this one, so you may
# not need to change them.  This defaults to /usr/local.
prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64
exec_prefix=${prefix}
bindir=${exec_prefix}/bin/
libdir=${exec_prefix}/lib/
includedir=${prefix}/include/
ecldir=${exec_prefix}/lib/ecl-12.12.1/

# Programs used by "make install":
#
SHELL = /bin/sh
INSTALL	= /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_LIBRARY = $(INSTALL_SCRIPT)
INSTALL_DATA = ${INSTALL} -m 644
mkinstalldirs = $(SHELL) $(top_srcdir)/gc/mkinstalldirs

# Files

SUBDIRS = c
LIBRARIES = 
LSP_LIBRARIES = libecl.a
TARGETS = bin/ecl$(EXE)
ECL_CMPDIR = cmp

all:	$(TARGETS) bin/ecl-config TAGS
.PHONY:	all

%Makefile: $(srcdir)/%Makefile.in config.status
	./config.status

#
# When compiling the library itself, we have to remove the dllimport
# declarations, because the variables that they mark are in the
# in the library and can be referenced without indirection.
#
c/ecl/external.h: $(top_srcdir)/h/external.h
	test -d c/ecl || mkdir c/ecl
	sed 's,__declspec(dllimport),,g' $(top_srcdir)/h/external.h > $@
ecl/external.h: c/ecl/external.h c/ecl/external.h
	cp -rf $(srcdir)/h/*.h $(srcdir)/h/impl ecl/

bin/ecl$(EXE): ecl_min$(EXE) compile.lsp ecl/external.h build-stamp $(top_srcdir)/lsp/*.lsp
	if [ -f CROSS-COMPILER ]; then \
		./CROSS-COMPILER compile; \
	else \
		ECLDIR=`pwd`/ ./ecl_min$(EXE) compile; \
	fi

ecl_min$(EXE): $(LIBRARIES) .gdbinit libeclmin.a
	$(CC) $(LDFLAGS) -o $@ cinit.o c/all_symbols.o -L./ libeclmin.a $(CORE_LIBS) $(FASL_LIBS) $(LIBS);

mini_ecl: ecl_min$(EXE) bare2.lsp
	(echo '#!/bin/sh'; echo './ecl_min bare2.lsp') > $@
	chmod +x $@
bare2.lsp:
	echo '(load "bare")(si::top-level)' > $@

.gdbinit: $(srcdir)/util/gdbinit
	cp $(srcdir)/util/gdbinit $@

lsp/config.lsp: lsp/config.pre
	sed -e 's,@ecldir\\@,$(ecldir),g' < lsp/config.pre > lsp/config.lsp
$(ECL_CMPDIR)/cmpdefs.lsp: $(ECL_CMPDIR)/cmpdefs.pre
	sed -e 's,@ecldir\\@,"$(ecldir)",g' \
	    -e 's,@libdir\\@,"$(libdir)",g' \
	    -e 's,@includedir\\@,"$(includedir)",g' < $(ECL_CMPDIR)/cmpdefs.pre > $@
$(ECL_CMPDIR)/crosscmp.lsp: $(ECL_CMPDIR)/crosscmp.pre
	sed -e 's,@ecldir\\@,$(ecldir),g' \
	    -e 's,@libdir\\@,$(libdir),g' \
	    -e 's,@includedir\\@,$(includedir),g' < $(ECL_CMPDIR)/crosscmp.pre > $@
compile.lsp: compile.pre
	sed -e 's,@ecldir\\@,$(ecldir),g' \
	    -e 's,@libdir\\@,$(libdir),g' < compile.pre > compile.lsp
bin/ecl-config: bin/ecl-config.pre
	sed -e 's,@libdir\\@,$(libdir),' \
	    -e 's,@includedir\\@,$(includedir),' \
	    -e 's,~A,$(libdir),' bin/ecl-config.pre > bin/ecl-config


libeclmin.a: libeclgmp.a libeclatomic.a libeclgc.a libeclffi.a lsp/config.lsp $(ECL_CMPDIR)/cmpdefs.lsp $(ECL_CMPDIR)/crosscmp.lsp ecl/external.h $(top_srcdir)/c/*.d
	cd c; $(MAKE)
libeclgc.a:
	test -d ecl/gc || mkdir ecl/gc
	test -d ecl/gc/private || mkdir ecl/gc/private
	if (echo $(SUBDIRS) | grep gc); then \
	  cd gc && $(MAKE) install && cd .. && \
	  cp -rf $(srcdir)/gc-unstable/include/private/*.h ecl/gc/private/ && \
	  mv libgc.a libeclgc.a; \
	fi
libeclffi.a:
	if (echo $(SUBDIRS) | grep libffi); then \
	  cd libffi && $(MAKE) install && cd .. && \
	  sed -e 's,<ffitarget,<ecl/ffitarget,' ecl/ffi.h > ecl/foo.h && \
	  rm ecl/ffi.h && mv ecl/foo.h ecl/ffi.h && \
	  mv libffi.a libeclffi.a; \
	fi
libeclatomic.a:
	if (echo $(SUBDIRS) | grep atomic); then \
	  cd atomic && $(MAKE) && $(MAKE) install && cd .. && \
	  $(RM) -rf share ecl/atomic_ops_stack.h ecl/atomic_ops_malloc.h *atomic*gpl* && \
	  mv libatomic_ops.a libeclatomic.a; \
	fi
libeclgmp.a:
	if (echo $(SUBDIRS) | grep gmp); then \
	  cd gmp && $(MAKE) install && \
	  cd .. && mv include/gmp.h ecl/ && rmdir include &&  \
	  mv ./libgmp.a ./libeclgmp.a; \
	fi

rt.lisp:
	cp $(srcdir)/../contrib/rt/rt.lisp ./

build-stamp: config.status
	echo "#" `uname -a` > $@
	head -8 config.log | tail -6 >> $@
install:
	# Here we would use the option -s but the install program in sourceforge-solaris
	# is broken.
	$(mkinstalldirs) $(DESTDIR)$(bindir) $(DESTDIR)$(libdir) \
	  $(DESTDIR)$(ecldir) $(DESTDIR)$(includedir) $(DESTDIR)$(includedir)/ecl
	for i in $(TARGETS); do \
	  $(INSTALL_PROGRAM) $$i $(DESTDIR)$(bindir); \
	done
	if [ -d encodings ]; then \
	  $(mkinstalldirs) $(DESTDIR)$(ecldir)/encodings; \
	  for i in ./encodings/*; do \
	    $(INSTALL_DATA) $$i $(DESTDIR)$(ecldir)/encodings; \
	  done \
	fi
	sed '/-CUT-/,$$d' ./ecl/config.h > ./ecl/config-install.h
	$(mkinstalldirs) $(DESTDIR)$(includedir)/ecl
	for i in `(cd ecl && find . -type d)`; do \
	  k="$(DESTDIR)$(includedir)/ecl/$$i"; \
	  test -d "$$k" || $(mkinstalldirs) $$k; \
	done
	for i in `(cd ecl && find . -name '*.h')`; do echo $$i; \
	  $(INSTALL_DATA) ecl/$$i $(DESTDIR)$(includedir)/ecl/$$i; \
	done
	$(RM) -f $(DESTDIR)$(includedir)/ecl/config.h
	mv $(DESTDIR)$(includedir)/ecl/config-install.h $(DESTDIR)$(includedir)/ecl/config.h
	$(INSTALL_SCRIPT) bin/ecl-config $(DESTDIR)$(bindir)
	for i in build-stamp help.doc TAGS ; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(ecldir); \
	done
	for i in $(LSP_LIBRARIES) $(LIBRARIES); do \
	  if test -s $$i ; then \
	   if echo $$i | grep dll; then \
	    $(INSTALL_LIBRARY) $$i $(DESTDIR)$(bindir); \
	   fi; \
	   $(INSTALL_LIBRARY) $$i $(DESTDIR)$(libdir); \
	  fi \
	done
	if [ "xlibecl.dylib" != "x" -a -f "libecl.dylib" ]; then \
	  ( cd $(DESTDIR)$(libdir) && $(RM) -f libecl.12.12.1.dylib libecl.12.12.dylib libecl.12.dylib && \
	    mv libecl.dylib libecl.12.12.1.dylib && \
	    $(LN_S) libecl.12.12.1.dylib libecl.12.12.dylib && \
	    $(LN_S) libecl.12.12.1.dylib libecl.12.dylib && \
	    $(LN_S) libecl.12.12.1.dylib libecl.dylib ) \
	fi
	$(INSTALL_PROGRAM) c/dpp$(EXE) $(DESTDIR)$(ecldir)
	$(INSTALL_PROGRAM) ecl_min$(EXE) $(DESTDIR)$(ecldir)
	for i in `cat modules`; do \
	  case $$i in \
	    *.fas) $(INSTALL_PROGRAM) $$i $(DESTDIR)$(ecldir);; \
	    *) $(INSTALL_DATA) $$i $(DESTDIR)$(ecldir);; \
	  esac \
	done
	for i in Copyright LGPL; do \
	  $(INSTALL_DATA) $(top_srcdir)/../$$i $(DESTDIR)$(ecldir); \
	done
	$(mkinstalldirs) $(DESTDIR)$(mandir)/man$(manext)
	$(INSTALL_DATA) doc/ecl.man $(DESTDIR)$(mandir)/man$(manext)/ecl.$(manext)
	$(INSTALL_DATA) doc/ecl-config.man $(DESTDIR)$(mandir)/man$(manext)/ecl-config.$(manext)
	$(INSTALL_DATA) cmp/crosscmp.lsp $(DESTDIR)$(ecldir)

flatinstall: build-stamp
	$(MAKE) DESTDIR=$(DESTDIR) bindir=$(prefix) libdir=$(prefix) \
	  includedir=$(prefix) ecldir=$(prefix) install

uninstall:
	for i in $(TARGETS) ecl-config; do $(RM) $(DESTDIR)$(bindir)/$$i; done
	$(RM) -r $(DESTDIR)$(includedir)/ecl $(DESTDIR)$(ecldir)
	for i in $(LSP_LIBRARIES) $(LIBRARIES) Copyright LGPL; do \
	  $(RM) $(DESTDIR)$(libdir)/$$i || : ; \
	done
	$(RM) -f $(DESTDIR)$(mandir)/man$(manext)/ecl.$(manext)
	$(RM) -f $(DESTDIR)$(mandir)/man$(manext)/ecl-config.$(manext)

clean: mostlyclean
	# $(RM) -r *

mostlyclean: clean_lisp
	(cd tests && $(MAKE) clean)
	for i in $(SUBDIRS); do (test -d $$i && cd $$i && $(MAKE) clean); done
	$(RM) ecl_min$(EXE) bin/ecl$(EXE) help.doc core a.out TAGS
	$(RM) config.version config.log config.cache
	$(RM) *.c *.o *.a *.eclh *.h *.data *.fas *.dat *.la *.so *.dylib
clean_lisp:
	-$(RM) help.doc $(TARGETS)
	-for i in lsp cmp clos clx tk ext; do $(RM) lib$$i.a $$i/?*.{o,eclh,data,c,sdat,h,fas}; done
distclean: clean
realclean: distclean
#
# Rebuild ECL using recent changes and compare
#
test_changes:
	test -d old || mkdir old
	cp -rf lsp clos cmp old/
	$(MAKE) clean_lisp; $(MAKE) -C c clean; $(RM) -f bin/ecl$(EXE)
	$(MAKE)
	for i in lsp clos cmp; do diff --exclude=\*.o $$i old/$$i; done
#
# Run test suite
#
check:
	cd tests && $(MAKE)
recheck:
	cd tests && $(MAKE) clean && $(MAKE)
#
# Rebuild ECL using its own image and compare. Does not work
# right now.
#
selfbuild:
	exit 2
	test -d stage2 || mkdir stage2
	cp -rf lsp clos cmp stage2
	-for i in lsp cmp clos clx tk; do test -f lib$$i.a && mv lib$$i.a stage2; done
	$(MAKE) clean_lisp
	./ecl compile
	-for i in lsp clos cmp clx tk; do test -d $$i && diff --exclude=\*.o $$i stage2/$$i; done | less

# Make sure to also include *.d files; and match DPP's idiosyncracies
# like "@si::foo" and "@(defun si::foo".
# This rule is allowed to fail when etags does not exist.
TAGS:
	-if test "x$(ETAGS)" != "x"; then \
	srcfiles=`find $(srcdir)/c $(srcdir)/h -name '*.[chd]'` && \
	$(ETAGS) --language=c    -o $@ $$srcfiles && \
	$(ETAGS) --language=none -o $@ --append \
	      --regex='/@\([-:*a-zA-z]+\)/\1/' \
	      --regex='/@(defun \([-:*a-zA-z]+\)/\1/' \
	      $$srcfiles; \
	fi
	touch $@
