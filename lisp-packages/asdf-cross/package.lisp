(org.tfeb.conduit-packages:defpackage cross-cmp
    (:use :cl :compiler)
  (:export
   #:cross-compilers
   #:cross-compiler
   #:cross-compile
   ;;#:get-compiler
   ;;#:registered-compilers

   #:user-cc-flags
   #:user-ld-flags
   #:cc-flags
   #:ld-flags))

(org.tfeb.conduit-packages:defpackage asdf-cross
    (:use :cl :cross-cmp)
  (:clones :asdf)
  (:export 
   #:make-cross-build
   #:build-ios
   #:lipo))
