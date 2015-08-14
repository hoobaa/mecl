# DIST: This is the distribution Makefile for ECL.  configure can
# DIST: make most of the changes to this file you might want, so try
# DIST: that first.

# make all	to compile and build Emacs.
# make install	to install it.
# make TAGS	to update tags tables.
#
# make clean  or  make mostlyclean
#      Delete all files from the current directory that are normally
#      created by building the program.	 Don't delete the files that
#      record the configuration.  Also preserve files that could be made
#      by building, but normally aren't because the distribution comes
#      with them.
#
#      Delete `.dvi' files here if they are not part of the distribution.
# 
# make distclean
#      Delete all files from the current directory that are created by
#      configuring or building the program.  If you have unpacked the
#      source and built the program without creating any other files,
#      `make distclean' should leave only the files that were in the
#      distribution.
# 
# make realclean
#      Delete everything from the current directory that can be
#      reconstructed with this Makefile.  This typically includes
#      everything deleted by distclean.

SHELL = /bin/sh
MACHINE = 

# ========================= Last release ================================

VERSION=12.12.1
WWW=http://ecls.sourceforge.net/
ADDRESS=anonymous@ecls.cvs.sourceforge.net:/cvsroot/ecls

# ==================== Things `configure' Might Edit ====================

#  Where to find the source code.
#  This is set by the configure script's `--srcdir' option.
srcdir=/Users/strobolights/dev/mecl/ecl/src/..

prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
infodir=${prefix}/share/info
mandir=${prefix}/share/man
libdir=${exec_prefix}/lib

#  What to release
TAR_CONTENTS=Makefile.in README.1st LGPL ANNOUNCEMENT Copyright doc \
	configure src/c src/cmp src/clos src/CHANGELOG src/lsp src/doc \
	src/h  src/gmp src/config* src/install.sh src/Makefile.in \
	src/util contrib/ src/clx src/gc src/*.in src/*.m4 src/gabriel \
	src/tests/Makefile.in src/ansi-tests/Makefile.in msvc examples

# ==================== Utility Programs for the Build ====================

#  Allow the user to specify the install program.

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644

# ============================= Build ==============================

all: build/Makefile
	cd build; $(MAKE)
.PHONY:	all

Makefile: Makefile.in build/config.status
	(cd build; ./config.status)

# ==================== Installation ====================

INSTALL_TARGET = install

install: build/Makefile
	cd build; $(MAKE) $(INSTALL_TARGET)
uninstall:
	cd build; $(MAKE) uninstall

# ==================== Cleaning up and miscellanea ====================

#   `clean'
#        Delete all files from the current directory that are normally
#        created by building the program.  Don't delete the files that
#        record the configuration.  Also preserve files that could be made
#        by building, but normally aren't because the distribution comes
#        with them.
#
clean:
	cd build; $(MAKE) clean

#   `distclean'
#        Delete all files from the current directory that are created by
#        configuring or building the program.  If you have unpacked the
#        source and built the program without creating any other files,
#        `make distclean' should leave only the files that were in the
#        distribution.

distclean: clean
	rm -rf build Makefile

#   `realclean'
#        Delete everything from the current directory that can be
#        reconstructed with this Makefile.
#        One exception, however: `make realclean' should not delete
#        `configure' even if `configure' can be remade using a rule in the
#        Makefile.  More generally, `make realclean' should not delete
#        anything that needs to exist in order to run `configure' and then
#        begin to build the program.
realclean: distclean

check:
	cd build && $(MAKE) check
recheck:
	cd build && $(MAKE) recheck

# ==================== Various means of distribution ====================

TAR_DIR=ecl-$(VERSION)

doc: build/doc/index.html
	-mkdir doc
	(cd build/doc; make html); cp build/doc/*.html doc
build/doc/index.html:
	cd build/doc; $(MAKE)

source-dist: $(TAR_DIR).tgz

rpmdir=$(shell rpm --showrc | grep '^-[0-9]*:.*[^{]_topdir' | sed 's,^.*topdir[ 	]*\(.*\)[ 	]*,\1,')
rpmbuild=$(shell if [ -z `which rpmbuild` ]; then echo "rpm"; else echo "rpmbuild"; fi)

# OBSOLETE!!!
# rpm: doc
# 	-rm -rf $(TAR_DIR)
# 	mkdir $(TAR_DIR) $(TAR_DIR)/src \
# 	$(TAR_DIR)/src/tests $(TAR_DIR)/src/ansi-tests && \
# 	for i in $(TAR_CONTENTS); do cp -rf $$i $(TAR_DIR)/$$i; done && \
# 	tar -cz --exclude '*~' --exclude '#*' --exclude 'CVS' -f $(rpmdir)/SOURCES/$(TAR_DIR).tgz $(TAR_DIR)
# 	if [ -f /etc/SuSE-release ]; then HOST=SUSE; else HOST=REDHAT; fi; \
# 	cat src/util/ecl.spec |\
# 	sed 's,ECL_VERSION,$(VERSION),;s,^#% '$${HOST}' ,,g;'|\
# 	grep -v '^#% ' > $(rpmdir)/SPECS/ecl.spec;
# 	rpm -ba $(rpmdir)/SPECS/ecl.spec

$(TAR_DIR).tgz:
	git archive --format=tar.gz --prefix=$(TAR_DIR)/ HEAD > $@

binary-dist: all
	su -c "rm -rf tmp"
	mkdir tmp
	for i in tmp$(bindir) tmp$(infodir) tmp$(mandir) tmp$(libdir); do \
	(echo $$i; IFS="/"; \for k in $$i; do echo $$k; (test -d $$k || mkdir $$k); chmod 755 $$k; cd $$k; done); \
	done
	prefix=`pwd`/tmp; cd build; $(MAKE) install prefix=$(prefix)
	su -c "chown -R root.root tmp && cd tmp; tar czf ../ecl-$(VERSION)-$(MACHINE).tgz * && cd .. && rm -rf tmp"

# This creates a ZIP file with a flattened directory structure
windows-dist: all
	cd build; rm -rf $(TAR_DIR); mkdir $(TAR_DIR); \
	$(MAKE) flatinstall prefix=`pwd`/$(TAR_DIR); \
	zip -r $(TAR_DIR).zip $(TAR_DIR)
windows-nsi: all
	cd build; rm -rf $(TAR_DIR); mkdir $(TAR_DIR); \
	$(MAKE) flatinstall prefix=`pwd`/$(TAR_DIR)
	`pwd`/src/util/ecl_nsi.sh `pwd`/src/util/ecl.nsi build/$(TAR_DIR)
	makensis.exe build/$(TAR_DIR)/ecl.nsi
	mv build/$(TAR_DIR)/Setup.exe ecl-$(VERSION).exe

upload-frs:
	ecldir=`echo $(VERSION) | sed -e 's,\([0-9]*\.[0-9]*\)\.[0-9]*,\1,'` && \
	destdir=jjgarcia,ecls@frs.sourceforge.net:/home/frs/project/e/ec/ecls/ecls/ && \
	test -d frs || mkdir frs && \
	test -d frs/$$ecldir || mkdir frs/$$ecldir && \
	cp $(TAR_DIR).tgz src/CHANGELOG frs/$$ecldir && \
	cd frs && scp -rC $$ecldir $$destdir
	rm -rf frs
