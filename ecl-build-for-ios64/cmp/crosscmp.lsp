;;;;  -*- Mode: Lisp; Syntax: Common-Lisp; Package: C -*-
;;;;
;;;;  Copyright (c) 2011, Sylvain Ageneau
;;;;
;;;;    This program is free software; you can redistribute it and/or
;;;;    modify it under the terms of the GNU Library General Public
;;;;    License as published by the Free Software Foundation; either
;;;;    version 2 of the License, or (at your option) any later version.
;;;;
;;;;    See file '../Copyright' for full details.

;;;; CROSSCMP -- Cross compiler

(in-package cross-cmp)

(setf (gethash  "aarch64-apple-darwin" cross-compilers)
      (make-instance 'cross-compiler
       :features (cons :wants-rt (cons :wants-bytecmp (cons :wants-profile (cons :wants-defsystem (cons :wants-asdf (cons :wants-sockets (cons :wants-cmp (cons :cross *features*))))))))
       :sys-pathname-translation '(("**;*.*.*" "/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/ecl-12.12.1//**/*.*"))
       :cmpinclude "<ecl/ecl-cmp.h>"
       :cc "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
       :ld "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
       :ranlib "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib"
       :ar "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar"
       :cc-flags "   -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -DAPPLE -I/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include -DECL_THREAD=0  -D_THREAD_SAFE -Ddarwin"
       :cc-optimize #-msvc "-O2"
       #+msvc "@CFLAGS_OPTIMIZE@"
		     
       :ld-format #-msvc "~A -o ~S -L~S ~{~S ~} ~@[~S~]~{ '~A'~} ~A"
       #+msvc "~A -Fe~S~* ~{~S ~} ~@[~S~]~{ '~A'~} ~A"
      
       :cc-format (cond ((member :msvc *features*)
                         "~A -I. \"-I~A\" ~A ~:[~*~;~A~] -w -c \"~A\" -o \"~A\"~{ '~A'~}")
                        ((member :nacl *features*) ;; pnacl-clang doesn't support -w
                         "~A -I. \"-I~A\" ~A ~:[~*~;~A~] -c \"~A\" -o \"~A\"~{ '~A'~}")
                        (t
                         "~A -I. \"-I~A\" ~A ~:[~*~;~A~] -w -c \"~A\" -o \"~A\"~{ '~A'~}"))
		      
       :ld-flags (if (member :dlopen *features*)
                     "  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/ -lecl -latomic_ops   -lgmp -lgc -lpthread   -lm "
                   (if (member :mscv *features*)
                       "  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/ -lecl  -lgmp -lgc -lpthread   -lm "
                     #+msvc "  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    ecl.lib @CLIBS@" user-ld-flags))
		      
       :ld-shared-flags #-msvc "-dynamiclib -flat_namespace -undefined suppress   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/ -lecl  -lgmp -lgc -lpthread   -lm "
       #+msvc "-dynamiclib -flat_namespace -undefined suppress   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    ecl.lib @CLIBS@"

       :ld-bundle-flags #-msvc "-bundle   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/ -lecl  -lgmp -lgc -lpthread   -lm "
       #+msvc "-bundle   -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib     -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk/ -arch arm64 -D__arm__ -L/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib    ecl.lib @CLIBS@"
		      
       :shared-library-prefix "lib"
       :shared-library-extension "dylib"
       :shared-library-format "lib~a.dylib"
       :static-library-prefix "lib"
       :static-library-extension "a"
       :static-library-format "lib~a.a"
       :object-file-extension "o"
       :executable-file-format "~a"
		      
       :ecl-include-directory "/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include/"
       :ecl-library-directory "/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/lib/"
		      
       :ld-rpath (let ((x ""))
                   (and (plusp (length x))
                        (format nil x ecl-library-directory)))
       :user-cc-flags nil
       :user-ld-flags nil))
