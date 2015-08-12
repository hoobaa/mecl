;;;;  -*- Mode: Lisp; Syntax: Common-Lisp; Package: C -*-
;;;;
;;;;  Copyright (c) 2010, Juan Jose Garcia-Ripoll
;;;;
;;;;    This program is free software; you can redistribute it and/or
;;;;    modify it under the terms of the GNU Library General Public
;;;;    License as published by the Free Software Foundation; either
;;;;    version 2 of the License, or (at your option) any later version.
;;;;
;;;;    See file '../Copyright' for full details.

;;;; CMPDEF -- Definitions created at compile / configuration time

(in-package "COMPILER")

;;; This is copied into each .h file generated, EXCEPT for system-p calls.
;;; The constant string *include-string* is the content of file "ecl.h".
;;; Here we use just a placeholder: it will be replaced with sed.
(defvar *cmpinclude* "<ecl/ecl-cmp.h>")

(defvar *cc* "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
"This variable controls how the C compiler is invoked by ECL.
The default value is \"cc -I. -I/usr/local/include/\".
The second -I option names the directory where the file ECL.h has been installed.
One can set the variable appropriately adding for instance flags which the 
C compiler may need to exploit special hardware features (e.g. a floating point
coprocessor).")

(defvar *ld* "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
"This variable controls the linker which is used by ECL.")

(defvar *ranlib* "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib"
  "Name of the `ranlib' program on the hosting platform.")

(defvar *ar* "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar"
  "Name of the `AR' program on the hosting platform.")

(defvar *cc-flags* "  -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -DAPPLE -I/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include -D_THREAD_SAFE -Ddarwin")

(defvar *cc-optimize* #-msvc "-O2"
                      #+msvc "@CFLAGS_OPTIMIZE@")

(defvar *ld-format* #-msvc "~A -o ~S -L~S ~{~S ~} ~@[~S~]~{ '~A'~} ~A"
                    #+msvc "~A -Fe~S~* ~{~S ~} ~@[~S~]~{ '~A'~} ~A")

(defvar *cc-format* (cond ((member :msvc *features*)
			   "~A -I. \"-I~A\" ~A ~:[~*~;~A~] -w -c \"~A\" -o \"~A\"~{ '~A'~}")
			  ((member :nacl *features*) ;; pnacl-clang doesn't support -w
			   "~A -I. \"-I~A\" ~A ~:[~*~;~A~] -c \"~A\" -o \"~A\"~{ '~A'~}")
			  (t
			   "~A -I. \"-I~A\" ~A ~:[~*~;~A~] -w -c \"~A\" -o \"~A\"~{ '~A'~}")))

#-dlopen
(defvar *ld-flags* " -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -lecl -latomic_ops   -lgmp -lgc -lpthread   -lm ")
#+dlopen
(defvar *ld-flags* #-msvc " -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -lecl  -lgmp -lgc -lpthread   -lm "
                   #+msvc " -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   ecl.lib @CLIBS@")
#+dlopen
(defvar *ld-shared-flags* #-msvc "-dynamiclib -flat_namespace -undefined suppress  -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -lecl  -lgmp -lgc -lpthread   -lm "
                          #+msvc "-dynamiclib -flat_namespace -undefined suppress  -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   ecl.lib @CLIBS@")
#+dlopen
(defvar *ld-bundle-flags* #-msvc "-bundle  -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -lecl  -lgmp -lgc -lpthread   -lm "
                          #+msvc "-bundle  -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib   ecl.lib @CLIBS@")

(defvar +shared-library-prefix+ "lib")
(defvar +shared-library-extension+ "dylib")
(defvar +shared-library-format+ "lib~a.dylib")
(defvar +static-library-prefix+ "lib")
(defvar +static-library-extension+ "a")
(defvar +static-library-format+ "lib~a.a")
(defvar +object-file-extension+ "o")
(defvar +executable-file-format+ "~a")

(defvar *ecl-include-directory* "/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include/")
(defvar *ecl-library-directory* "/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/")

(defvar *ld-rpath*
  (let ((x ""))
    (and (plusp (length x))
         (format nil x *ecl-library-directory*))))
