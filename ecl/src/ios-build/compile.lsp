;;; compile.pre.  Generated from compile.lsp.in by configure.
;;;
;;; This is the "makefile" file for building ECL. The purpose of this file is
;;;	- Compile the core of the Common-Lisp library (lsp, clos)
;;;	- Compile the compiler (cmp)
;;;	- Build an executable
;;; This can be done in two ways:
;;;	- Using interpreted code and the ECL_MIN minimal environment.
;;;	- On a second stage, using the final ECL executable, to test it.
;;;

(progn
  (setq *package* (find-package "SYSTEM"))
  (setq *features* (cons :wants-rt (cons :wants-bytecmp (cons :wants-profile (cons :wants-defsystem (cons :wants-asdf (cons :wants-sockets (cons :wants-cmp (cons :cross *features*))))))))))

;;;
;;; * Ensure that we have the whole of Common-Lisp to compile
;;;
(load "bare.lsp" :verbose nil)

;;;
;;; * Force compiler constants only for the core library
;;;
(setf *use-static-constants-p* t)

;;;
;;; * Dump documentation
;;;
#+stage1
(progn
  (load "ext:ecl-cdb;ecl-cdb")
  (load "ext:ecl-cdb;ecl-help")
  (load "/Users/strobolights/dev/mecl/ecl/src/doc/help.lsp")
  (si::dump-documentation "/Users/strobolights/dev/mecl/ecl/src/ios-build/help.doc"))

;;;
;;; * Trick to make names shorter in C files
;;;
(si::package-lock "CL" nil)
(rename-package "CL" "CL" '("COMMON-LISP" "LISP"))

;;;
;;; * Add include path to not yet installed headers, and remove include flag
;;;   (-I) to installed directory, and Notice that we must explicitely mention
;;;   libecl.so/ecl.dll instead of using -lecl. This is to avoid interference
;;;   with an already installed copy of ECL.
;;;
(setq c::*cc-flags*
      #-msvc "   -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -DAPPLE -I/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include -D_THREAD_SAFE -Ddarwin -I\"/Users/strobolights/dev/mecl/ecl/src/c\""
      #+msvc " -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -DAPPLE -I/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include -D_THREAD_SAFE -Ddarwin"
      c::*ecl-include-directory* "/Users/strobolights/dev/mecl/ecl/src/ios-build/"
      c::*ecl-library-directory* "/Users/strobolights/dev/mecl/ecl/src/ios-build/")
#-:wants-dlopen 
(setf c::*ld-flags*
      "  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    libecl.a -latomic_ops   -lgmp -lgc -lpthread   -lm ")
#+(and :wants-dlopen (not nonstop))
(setf c::*ld-flags*
      "  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    libecl.dylib -lpthread   -lm "
      c::*ld-shared-flags*
      "-dynamiclib -flat_namespace -undefined suppress   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    libecl.dylib  -lgmp -lgc -lpthread   -lm "
      c::*ld-bundle-flags*
      "-bundle   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    libecl.dylib  -lgmp -lgc -lpthread   -lm ")
;;; FIXME: The nonstop platform does not support soname
#+(and :wants-dlopen nonstop)
(setf c::*ld-flags*
      "  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -Wld=-llibecl.dylib -lpthread   -lm "
      c::*ld-shared-flags*
      "-dynamiclib -flat_namespace -undefined suppress   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -Wld=-llibecl.dylib  -lgmp -lgc -lpthread   -lm "
      c::*ld-bundle-flags*
      "-bundle   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -Wld=-llibecl.dylib  -lgmp -lgc -lpthread   -lm ")

;;;
;;; * Avoid name clashes with user supplied code.
;;;
(setq si::*init-function-prefix* "ECL")

;;;
;;; * Clean up a little bit before moving on
;;;
(mapc #'delete-file (directory "eclinit*.*"))

;;;
;;; * Compile and link Common-Lisp base library
;;;
(setq si::*keep-documentation* nil)
(mapc #'proclaim +ecl-optimization-settings+)
(let* ((c::*cc-flags* (concatenate 'string "-DECL_API -I\"/Users/strobolights/dev/mecl/ecl/src/ios-build/c\" " c::*cc-flags*))
       (lsp-objects (compile-if-old "build:lsp;" +lisp-module-files+
				    :system-p t :c-file t :data-file t :h-file t
				    ;;:shared-data-file "build:ecl.sdat"
				    )))
  #+CLOS
  (let* ((c::*compile-to-linking-call* nil))
    (mapc #'proclaim +ecl-optimization-settings+)
    (setq lsp-objects (append lsp-objects
			      (compile-if-old "build:clos;" +clos-module-files+
					      :system-p t :c-file t :data-file t
                                              :h-file t
					      ;;:shared-data-file "build:ecl.sdat"
					      ))))
  (let ((extra-lisp-files '()))
    (when extra-lisp-files
      (setq lsp-objects (append lsp-objects
                                (compile-if-old "build:ext;" extra-lisp-files
                                                :system-p t :c-file t :data-file t
                                                :h-file t
                                                ;;:shared-data-file "build:ecl.sdat"
                                                )))))
  (c::build-static-library "lsp" :lisp-files lsp-objects
			   ;;:shared-data-file "build:ecl.sdat"
			   ))

#-:wants-dlopen
(c::safe-system
	(concatenate 'string
"sh -c 'rm -rf tmp; mkdir tmp;"
"cp libeclmin.a libecl.a;"
"cd tmp; /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar -x ../liblsp.a;"
"for i in *.o; do mv $i lsp_`basename $i`; done;"
"/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar -r ../libecl.a *.o ../c/all_symbols2.o; rm *.o;"
"/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib ../libecl.a'"))

#+:wants-dlopen
;;;
;;; We do not need the -rpath flag for the library, nor -lecl.
;;;
(let* ((c::*ld-shared-flags* #-msvc "-dynamiclib -flat_namespace -undefined suppress   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -Wl,-install_name,/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib//libecl.12.12.dylib -Wl,-compatibility_version,12.12.1 -latomic_ops   -lgmp -lgc -lpthread   -lm "
			     #+msvc "-dynamiclib -flat_namespace -undefined suppress   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    @STATICLIBS@ @CLIBS@")
       (c::*cc-flags* (concatenate 'string "-DECL_API -I/Users/strobolights/dev/mecl/ecl/src/ios-build/c " c::*cc-flags*))
       (extra-args nil))
  #+(or mingw32 cygwin)
  (progn
    ;; We need these two to force dllwrap to export the symbols
    ;; in these libraries. Otherwise it will not be possible to
    ;; call functions from GMP or GC in code that embeds ECL.
    #+thread
    (when (probe-file "libatomic_ops.a")
      (push "libatomic_ops.a" extra-args))
    (when (probe-file "libeclgc.a")
      (push "libeclgc.a" extra-args))
    (when (probe-file "libeclgmp.a")
      (push "libeclgmp.a" extra-args)))
  (print extra-args)
  (c::shared-cc (compile-file-pathname "ecl" :type :dll)
                (list* "c/main.o"
                       "c/all_symbols2.o"
                       "liblsp.a"
                       "libeclmin.a"
                       extra-args)))

;;;
;;; * Compile and link Common-Lisp to C compiler
;;;
(mapc #'proclaim +ecl-optimization-settings+)

#-mingw32
(si::pathname-translations "SYS" '(("**;*.*.*" "/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/ecl-12.12.1//**/*.*")))

#+WANTS-CMP
(build-module "cmp" +cmp-module-files+ 
              :dir "build:cmp;" :prefix "CMP"
              :builtin #+:BUILTIN-CMP t #-:BUILTIN-CMP nil)

(build-module "ecl-cdb" '("ext:ecl-cdb;ecl-cdb.lisp")
              :dir "build:ext;" :prefix "EXT"
              :builtin #+:WANTS-DLOPEN nil #-:WANTS-DLOPEN t)

(build-module "ecl-help" '("ext:ecl-cdb;ecl-cdb.lisp"
                           "ext:ecl-cdb;ecl-help.lisp")
              :dir "build:ext;" :prefix "EXT"
              :builtin #+:WANTS-DLOPEN nil #-:WANTS-DLOPEN t)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;
;;; EXTENSIONS
;;;

;;;
;;; * SSE
;;;
#+(and WANTS-CMP SSE2)
(build-module "cl-simd"
              '("ext:cl-simd;sse-package.lisp"
                "ext:cl-simd;ecl-sse-core.lisp"
                "ext:cl-simd;sse-intrinsics.lisp"
                "ext:cl-simd;sse-array-defs.lisp"
                "ext:cl-simd;ecl-sse-utils.lisp"
                "ext:cl-simd;sse-utils.lisp")
              :dir "build:ext;"
              :prefix "EXT"
              :builtin nil)

;;;
;;; * DEFSYSTEM
;;;
#+WANTS-DEFSYSTEM
(build-module "defsystem"
              '("ext:defsystem;defsystem.lisp")
              :dir "build:ext;"
              :prefix "EXT"
              :builtin #+:BUILTIN-DEFSYSTEM t #-:BUILTIN-DEFSYSTEM nil)

;;;
;;; * ASDF
;;;
#+WANTS-ASDF
(build-module "asdf"
              '("ext:asdf;asdf.lisp"
		"ext:asdf;asdf-bundle.lisp")
              :dir "build:ext;"
              :prefix "EXT"
              :builtin #+:BUILTIN-ASDF t #-:BUILTIN-ASDF nil)

;;;
;;; * PROFILE
;;;
#+(and WANTS-PROFILE (not (or cygwin mingw32)))
(build-module "profile"
              '("ext:profile;profile.lisp")
              :dir "build:ext;"
              :prefix "EXT"
              :builtin
	      #+(or (NOT :WANTS-DLOPEN) :BUILTIN-PROFILE) t
	      #-(or (NOT :WANTS-DLOPEN) :BUILTIN-PROFILE) nil)

;;;
;;; * Sockets library.
;;;

#+WANTS-SOCKETS
(build-module "sockets"
	      '("ext:sockets;package.lisp"
		"ext:sockets;sockets.lisp")
	      :dir "build:ext;"
	      :prefix "EXT"
              :builtin
	      #+(or (NOT :WANTS-DLOPEN) :BUILTIN-SOCKETS) t
	      #-(or (NOT :WANTS-DLOPEN) :BUILTIN-SOCKETS) nil)

#+WANTS-SOCKETS
(build-module "sb-bsd-sockets"
	      '("ext:sockets;sb-bsd-sockets.lisp")
              :depends-on '("sockets")
	      :dir "build:ext;"
	      :prefix "EXT"
	      :builtin nil)

#+WANTS-SERVE-EVENT
(build-module "serve-event"
	      '("ext:serve-event;serve-event.lisp")
	      :dir "build:ext;"
	      :prefix "EXT"
              :builtin
	      #+(or (NOT :WANTS-DLOPEN) :BUILTIN-SERVE-EVENT) t
	      #-(or (NOT :WANTS-DLOPEN) :BUILTIN-SERVE-EVENT) nil)

#+WANTS-SOCKETS
(build-module "ecl-curl"
	      '("ext:ecl-curl;ecl-curl.lisp")
	      :dir "build:ext;"
	      :prefix "EXT"
	      :builtin nil)

#+WANTS-SOCKETS
(build-module "ql-minitar"
	      '("ext:quicklisp;minitar.lisp")
	      :dir "build:ext;"
	      :prefix "EXT"
	      :builtin nil)

#+WANTS-SOCKETS
(build-module "deflate"
	      '("ext:deflate;deflate.lisp")
	      :dir "build:ext;"
	      :prefix "EXT"
	      :builtin nil)

#+WANTS-SOCKETS
(build-module "ecl-quicklisp"
	      '("ext:quicklisp;ecl-quicklisp.lisp")
	      :dir "build:ext;"
	      :prefix "EXT"
	      :builtin nil)

;;;
;;; * Test suite
;;;
#+WANTS-RT
(build-module "rt"
	      '("ext:rt;rt.lisp")
	      :dir "build:ext;"
	      :prefix "EXT"
              :builtin #+:BUILTIN-RT t #-:BUILTIN-RT nil)

;;;
;;; * External formats
;;;
#+UNICODE
(load "ext:encodings;generate.lisp")

;;;
;;; * Compile the portable CLX library.
;;;

#+WANTS-CLX
(let* ((*features* (cons :clx-ansi-common-lisp *features*))
       (+clx-src-files+ '("src:clx;package.lisp"
                          "src:clx;depdefs.lisp"
                          "src:clx;clx.lisp"
                          "src:clx;dependent.lisp"
                          "src:clx;macros.lisp"
                          "src:clx;bufmac.lisp"
                          "src:clx;buffer.lisp"
                          "src:clx;display.lisp"
                          "src:clx;gcontext.lisp"
                          "src:clx;input.lisp"
                          "src:clx;requests.lisp"
                          "src:clx;fonts.lisp"
                          "src:clx;graphics.lisp"
                          "src:clx;text.lisp"
                          "src:clx;attributes.lisp"
                          "src:clx;translate.lisp"
                          "src:clx;keysyms.lisp"
                          "src:clx;manager.lisp"
                          "src:clx;image.lisp"
                          "src:clx;resource.lisp"
                          "src:clx;shape.lisp"
                          "src:clx;big-requests.lisp"
                          "src:clx;xvidmode.lisp"
                          "src:clx;xrender.lisp"
                          "src:clx;glx.lisp"
                          "src:clx;gl.lisp"
                          "src:clx;dpms.lisp"
                          "src:clx;xtest.lisp"
                          "src:clx;screensaver.lisp"
                          "src:clx;xinerama.lisp"
			  "build:clx;module.lisp"))
       #+:msvc
       (c::*cc-flags* (concatenate 'string c::*cc-flags* " -Zm150")))
  (let ((filename "build:clx;module.lisp"))
    (ensure-directories-exist filename)
    (with-open-file (s filename :direction :output :if-exists :overwrite
		       :if-does-not-exist :create)
     (print '(provide :clx) s)))
  (unless (find-package "SB-BSD-SOCKETS")
    (load "ext:sockets;package.lisp"))
  (mapcar #'load +clx-src-files+)
  (build-module "clx" +clx-src-files+ :dir "build:clx;" :prefix "CLX"
		:builtin
		#+(OR (NOT :WANTS-DLOPEN) :BUILTIN-CLX) t
		#-(OR (NOT :WANTS-DLOPEN) :BUILTIN-CLX) nil))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;
;;; THE FINAL EXECUTABLE
;;;

(setq si::*init-function-prefix* NIL)

#+windows
(progn
 (with-open-file (s "ecl.rc"
                  :direction :output
                  :if-exists :supersede
                  :if-does-not-exist :create)
  (write-line "id ICON \"ecl.ico\"" s))
 (ext:copy-file #p"src:util;ecl.ico" "ecl.ico")
 #+msvc
 (ext:run-program "rc" '("/r" "ecl.rc"))
 #-msvc
 (ext:run-program "windres" '("ecl.rc" "-O" "coff" "ecl.res")))

(si::pathname-translations "SYS" '(("**;*.*.*" "/Users/strobolights/dev/mecl/ecl/src/ios-build/**/*.*")))

(compiler::build-program
 #+:msvc "ecl2"
 #+(and (or cross stage1) (not msvc)) "bin/ecl"
 #-(or cross stage1 msvc) "ecl2"
 :epilogue-code '(SI::TOP-LEVEL T)
 :lisp-files *module-symbols*
 :ld-flags
 (concatenate 'list #-msvc '("-L./") #+windows '("ecl.res" #+msvc "/F 10485760")))

(with-open-file (modules-list #P"build:MODULES" :direction :output
			      :if-exists :supersede
			      :if-does-not-exist :create)
  (print *module-files*)
  (dolist (module-file *module-files*)
    (format modules-list "~A~%" module-file)))

(quit)
