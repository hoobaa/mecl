top_srcdir= /Users/strobolights/dev/mecl/ecl/src
srcdir	= /Users/strobolights/dev/mecl/ecl/src/doc

prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64
exec_prefix=${prefix}
infodir = ${prefix}/share/info
mandir=${prefix}/share/man
docdir=${prefix}/share/doc/${PACKAGE_TARNAME}
manext=1

INFOEXT = info
SHELL = /bin/sh
INSTALL	= /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_INFO = /opt/local/bin/install-info
mkinstalldirs = $(SHELL) $(top_srcdir)/gc/mkinstalldirs
INFO_FILES = ecl.$(INFOEXT) ecldev.$(INFOEXT) 
HTML_FILES = index.html license.html lgpl.html news.html benchmark.html \
	install.html download.html cvs.html

VERSION=12.12.1

FILTER = sed 's,@VERSION@,$(VERSION),g'

ECL = ../ecl

all: $(INFO_FILES)

html: $(HTML_FILES)

ecl.dvi: $(srcdir)/user.txi $(srcdir)/macros.txi clisp.sty ecl.sty
	tex $(srcdir)/user.txi
ecldev.dvi: $(srcdir)/devel.txi $(srcdir)/macros.txi clisp.sty ecl.sty
	tex $(srcdir)/devel.txi
clx.dvi: clx.texinfo
	tex clx.texinfo

ecl.ps: ecl.dvi $(srcdir)/macros.txi
	dvips -o $@ ecl.dvi
ecldev.ps: ecldev.dvi $(srcdir)/macros.txi
	dvips -o $@ ecldev.dvi
clx.ps: clx.dvi
	dvips -o $@ clx.dvi

install: all
	$(mkinstalldirs) $(DESTDIR)$(infodir)
	for k in $(INFO_FILES); do \
	  $(INSTALL_DATA) $$k $(DESTDIR)$(infodir); \
	  if [ -x $(INSTALL_INFO) ]; then \
	    $(INSTALL_INFO) --info-dir=$(DESTDIR)$(infodir) $$k; \
	  fi; \
	done
	$(mkinstalldirs) $(DESTDIR)$(docdir)
	for i in Copyright LGPL; do \
	  $(INSTALL_DATA) $(top_srcdir)/../$$i $(DESTDIR)$(docdir); \
	done
	$(mkinstalldirs) $(DESTDIR)$(mandir)/man$(manext)
	$(INSTALL_DATA) ecl.man $(DESTDIR)$(mandir)/man$(manext)/ecl.$(manext)
	$(INSTALL_DATA) ecl-config.man $(DESTDIR)$(mandir)/man$(manext)/ecl-config.$(manext)
flatinstall: all $(HTML_FILES)
	$(mkinstalldirs) $(DESTDIR)$(docdir)
	for k in $(INFO_FILES); do $(INSTALL_DATA) $$k $(DESTDIR)$(docdir); done
	if [ -f user.html ]; then \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(docdir)/; \
	else \
	  $(mkinstalldirs) $(DESTDIR)$(docdir)/ecl; \
	  for i in ecl/*; do $(INSTALL_DATA) $$i $(DESTDIR)$(docdir)/ecl/; done; \
	fi
	if [ -f devel.html ]; then \
	  $(INSTALL_DATA) devel.html $(DESTDIR)$(docdir)/; \
	else \
	  $(mkinstalldirs) $(DESTDIR)$(docdir)/ecldev; \
	  for i in ecldev/*; do $(INSTALL_DATA) $$i $(DESTDIR)$(docdir)/ecldev/; done; \
	fi
	for i in Copyright LGPL; do \
	  $(INSTALL_DATA) $(top_srcdir)/../$$i $(DESTDIR)$(docdir); \
	done
	for i in *.html; do $(INSTALL_DATA) $$i $(DESTDIR)$(docdir)/; done

uninstall:
	-for k in $(INFO_FILES); do \
	  rm $$k; \
	  if [ -x $(INSTALL_INFO) ]; then \
	    $(INSTALL_INFO) --remove $$k; \
	  fi; \
	done
	rm -r $(DESTDIR)$(infodir)/ecl.$(INFOEXT) $(DESTDIR)$(infodir)/ecldev.$(INFOEXT); \
	rm $(DESTDIR)$(mandir)/man$(manext)/ecl.$(manext)

head: developers_manual user_manual $(srcdir)/head
	if [ -f ecl/index.html ]; then \
	  sed -e 's,ecl/user.html,ecl/index.html,g' \
	      -e 's,ecldev/devel.html,ecldev/index.html,g' $(srcdir)/head > head; \
	else \
	  cp $(srcdir)/head head; \
	fi
ecl.info.gz: ecl.info
	gzip < ecl.info > ecl.info.gz
ecldev.info.gz: ecldev.info
	gzip < ecldev.info > ecldev.info.gz
clx.info.gz: clx.info
	gzip < clx.info > clx.info.gz
ecl.info: $(srcdir)/user.txi $(srcdir)/macros.txi
	makeinfo -I $(srcdir) --no-split $(srcdir)/user.txi
ecldev.info: $(srcdir)/devel.txi $(srcdir)/macros.txi
	makeinfo -I $(srcdir) --no-split $(srcdir)/devel.txi
clx.info: clx.texinfo
	-makeinfo --no-split clx.texinfo
clx.texinfo: $(top_srcdir)/clx/manual/clx.texinfo
	cp $(top_srcdir)/clx/manual/clx.texinfo .

download.html: $(srcdir)/download.in.html head
	cat head $(srcdir)/download.in.html $(srcdir)/end | $(FILTER) > $@
index.html: $(srcdir)/index.in.html head
	cat head $(srcdir)/index.in.html $(srcdir)/end | $(FILTER) > $@
cvs.html: $(srcdir)/cvs.in.html head
	cat head $(srcdir)/cvs.in.html $(srcdir)/end | $(FILTER) > $@
install.html: $(srcdir)/install.in.html head
	cat head $(srcdir)/install.in.html $(srcdir)/end | $(FILTER) > $@
news.html: head $(srcdir)/../..ANNOUNCEMENT
	(cat head; echo '<pre>'; cat $(srcdir)/../../ANNOUNCEMENT; echo '</pre>';\
	 cat $(srcdir)/end) | $(FILTER) > $@
benchmark.html: $(srcdir)/benchmark.in.html BENCHMARK head
	(cat head; cat $(srcdir)/benchmark.in.html; \
	 echo '<pre>'; cat BENCHMARK; echo '</pre>'; \
	 cat $(srcdir)/end) | $(FILTER) > $@
BENCHMARK:
	echo "No benchmarks available" > $@
license.html: $(top_srcdir)/../Copyright head
	(cat head; \
	 echo '<pre>'; cat $(top_srcdir)/../Copyright; echo '</pre>'; \
	 cat $(srcdir)/end) | $(FILTER) > $@
lgpl.html: $(top_srcdir)/../LGPL head
	(cat head; \
	 echo '<pre>'; cat $(top_srcdir)/../LGPL; echo '</pre>'; \
	 cat $(srcdir)/end) | $(FILTER) > $@
user_manual: $(srcdir)/user.txi $(srcdir)/macros.txi
	echo "Producing ecl.html; ignore error messages."
	test -d ecl || mkdir ecl; \
	(makeinfo --output-indent=0 -I $(srcdir) --css-include=$(srcdir)/basic.css --html $(srcdir)/user.txi || \
	 texi2html -I=$(srcdir) -subdir=ecl -split=chapter $(srcdir)/user.txi)  \
	&& touch user_manual
developers_manual: $(srcdir)/devel.txi $(srcdir)/macros.txi
	echo "Producing ecldev.html; ignore error messages."
	test -d ecldev || mkdir ecldev; \
	(makeinfo --output-indent=0 -I $(srcdir) --css-include=$(srcdir)/basic.css --html $(srcdir)/devel.txi || \
	 texi2html -I=$(srcdir) -subdir=ecldev -split=chapter $(srcdir)/devel.txi) \
	&& touch developers_manual
clean:
	rm -r -f ecl ecldev ecl.info* ecldev.info* *.html user_manual developers_manual
