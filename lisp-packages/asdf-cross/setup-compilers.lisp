(in-package :cross-cmp)

(defvar ecl-host-root (merge-pathnames "../../" (translate-logical-pathname "SYS:")))
;; (setf ecl-host-root (merge-pathnames "../../" (translate-logical-pathname "SYS:")))
;;    (or (sys:getenv "ECL_INSTALL_ROOT_DIR")
;;        (merge-pathnames "../../" (translate-logical-pathname "SYS:"))))

;; (defvar *ecl-iphonesim-root* 
;;     (or (sys:getenv "ECL_IPHONESIM_ROOT_DIR")
;;         (merge-pathnames "../iPhoneSimulator/" *ecl-host-root*)))
;; (defvar *ecl-iphoneos-armv7s-root* 
;;     (or (sys:getenv "ECL_IPHONEOS_ARMV7S_ROOT_DIR")
;;         (merge-pathnames "../iPhoneOS-armv7s/" *ecl-host-root*)))
;; (defvar *ecl-iphoneos-armv7-root* 
;;     (or (sys:getenv "ECL_IPHONEOS_ARMV7_ROOT_DIR")
;;         (merge-pathnames "../iPhoneOS-armv7/" *ecl-host-root*)))
;; (defvar *ecl-android-arm-root* 
;;     (or (sys:getenv "ECL_ANDROID_ARM_ROOT_DIR")
;;         (merge-pathnames "../android/" *ecl-host-root*)))
;; (defvar *ecl-android-x86-root*
;;     (or (sys:getenv "ECL_ANDROID_X86_ROOT_DIR")
;;         (merge-pathnames "../androidx86/" *ecl-host-root*)))
;; (defvar *ecl-nacl32-root* 
;;     (or (sys:getenv "ECL_NACL32_ROOT_DIR")
;;         (merge-pathnames "../nacl32/" *ecl-host-root*)))
;; (defvar *ecl-nacl64-root* 
;;     (or (sys:getenv "ECL_NACL64_ROOT_DIR")
;;         (merge-pathnames "../nacl64/" *ecl-host-root*)))

(defvar cross-compilers (make-hash-table :test #'equalp))

;;(defun get-compiler (arch)
;;  (gethash arch *cross-compilers*))

;;(defun registered-compilers ()
;;  *cross-compilers*)

(defclass cross-compiler ()
    ((features :accessor features :initarg :features)
     (sys-pathname-translation :accessor sys-pathname-translation :initarg :sys-pathname-translation)
     (cmpinclude :accessor cmpinclude :initarg :cmpinclude)
     (cc :accessor cc :initarg :cc)
     (ld :accessor ld :initarg :ld)
     (ranlib :accessor ranlib :initarg :ranlib)
     (ar :accessor ar :initarg :ar)
     (cc-flags :accessor cc-flags :initarg :cc-flags)
     (cc-optimize :accessor cc-optimize :initarg :cc-optimize)
     (ld-format :accessor ld-format :initarg :ld-format)
     (cc-format :accessor cc-format :initarg :cc-format)
     (ld-flags :accessor ld-flags :initarg :ld-flags)
   
     (ld-shared-flags :accessor ld-shared-flags :initarg :ld-shared-flags)
     (ld-bundle-flags :accessor ld-bundle-flags :initarg :ld-bundle-flags)
   
     (shared-library-prefix :accessor shared-library-prefix :initarg :shared-library-prefix)
     (shared-library-extension :accessor shared-library-extension :initarg :shared-library-extension)
     (shared-library-format :accessor shared-library-format :initarg :shared-library-format)
     (static-library-prefix :accessor static-library-prefix :initarg :static-library-prefix)
     (static-library-extension :accessor static-library-extension :initarg :static-library-extension)
     (static-library-format :accessor static-library-format :initarg :static-library-format)
     (object-file-extension :accessor object-file-extension :initarg :object-file-extension)
     (executable-file-format :accessor executable-file-format :initarg :executable-file-format)
   
     (ecl-include-directory :accessor ecl-include-directory :initarg :ecl-include-directory)
     (ecl-library-directory :accessor ecl-library-directory :initarg :ecl-library-directory)
   
     (ld-rpath :accessor ld-rpath :initarg :ld-rpath)
     (user-cc-flags :accessor user-cc-flags :initarg :user-cc-flags)
     (user-ld-flags :accessor user-ld-flags :initarg :user-ld-flags)))

(defmethod cross-compile ((compiler cross-compiler) func)
  (let ((old-translation (si::pathname-translations "SYS")))
    (unwind-protect
         (progn
           (si::pathname-translations "SYS" (slot-value compiler 'sys-pathname-translation))
           (let ((common-lisp:*features* (slot-value compiler 'features))
                 (c::*user-cc-flags* (slot-value compiler 'user-cc-flags))
                 (c::*user-ld-flags* (slot-value compiler 'user-ld-flags))
                 (c::*cmpinclude* (slot-value compiler 'cmpinclude))
                 (c::*cc* (slot-value compiler 'cc))
                 (c::*ld* (slot-value compiler 'ld))
                 (c::*ranlib* (slot-value compiler 'ranlib))
                 (c::*ar* (slot-value compiler 'ar))
                 (c::*cc-flags* (slot-value compiler 'cc-flags))
                 (c::*cc-optimize* (slot-value compiler 'cc-optimize))
                 (c::*ld-format* (slot-value compiler 'ld-format))
                 (c::*cc-format* (slot-value compiler 'cc-format))
		 
                 (c::*ld-flags* (slot-value compiler 'ld-flags))
		 
                 (c::*ld-shared-flags* (slot-value compiler 'ld-shared-flags))
                 (c::*ld-bundle-flags* (slot-value compiler 'ld-bundle-flags))
		 
                 (c::+shared-library-prefix+ (slot-value compiler 'shared-library-prefix))
                 (c::+shared-library-extension+ (slot-value compiler 'shared-library-extension))
                 (c::+shared-library-format+ (slot-value compiler 'shared-library-format))
                 (c::+static-library-prefix+ (slot-value compiler 'static-library-prefix))
                 (c::+static-library-extension+ (slot-value compiler 'static-library-extension))
                 (c::+static-library-format+ (slot-value compiler 'static-library-format))
                 (c::+object-file-extension+ (slot-value compiler 'object-file-extension))
                 (c::+executable-file-format+ (slot-value compiler 'executable-file-format))
		 
                 (c::*ecl-include-directory* (slot-value compiler 'ecl-include-directory))
                 (c::*ecl-library-directory* (slot-value compiler 'ecl-library-directory))
		 
                 (c::*ld-rpath* (slot-value compiler 'ld-rpath)))
             (funcall func)))
      (si::pathname-translations "SYS" old-translation))))

(defun add-compiler (dir 
                     &aux 
                     (dir (merge-pathnames (format nil "../~a/" dir)
                           ecl-host-root))
                     (dir-name (namestring dir)))
  (if (probe-file dir)
      (let* ((crosscmp-host (enough-namestring
                             (truename (translate-logical-pathname "SYS:crosscmp.lsp"))
                             (truename ecl-host-root)))
             (crosscmp (merge-pathnames crosscmp-host dir-name)))
        (if (probe-file crosscmp)
            (load crosscmp)
          (warn "No cross-compiler found at ~a" cross-comp)))
    (warn "Directory not found ~a" dir))

  ;; patch
  (loop
    for arch being the hash-key of cross-compilers using (hash-value compiler)
    do (cond ((search "apple-darwin" arch)
              (progn
                (setf (cc-flags compiler)
                      (concatenate 'string "-x objective-c -fobjc-abi-version=2 -fobjc-legacy-dispatch " (cc-flags compiler)))
                (setf (ld-flags compiler)
                      (concatenate 'string "-x objective-c -fobjc-abi-version=2 -fobjc-legacy-dispatch " (ld-flags compiler))))
              ))))


(dolist (dir (list "iPhoneSimulator" "iPhoneOS-armv7" "iPhoneOS-armv7s" "android" "host64"))
  (add-compiler dir))

;; (defun setup-compilers ()
;;   (loop
;;     for dir in (list 
;;                 (merge-pathnames "../iPhoneSimulator/" ecl-host-root)
;;                 (merge-pathnames "../iPhoneOS-armv7/" ecl-host-root)
;;                 (merge-pathnames "../iPhoneOS-armv7s/" ecl-host-root)
;;                 (merge-pathnames "../android/" ecl-host-root)
;;                 )
;;     for dir-name = (namestring dir)
;;     do (if (probe-file dir)
;;            (let* ((crosscmp-host (enough-namestring
;;                                   (truename (translate-logical-pathname "SYS:crosscmp.lsp"))
;;                                   (truename ecl-host-root)))
;;                   (crosscmp (merge-pathnames crosscmp-host dir-name)))
;;              (if (probe-file crosscmp)
;;                  (load crosscmp)
;;                (warn "No cross-compiler found at ~a" cross-comp)))
;;          (warn "Directory not found ~a" dir)))
;; 
;;   (loop
;;     for arch being the hash-key of cross-compilers using (hash-value compiler)
;;     do (cond ((search "apple-darwin" arch)
;;               (progn
;;                 (setf (cc-flags compiler)
;;                       (concatenate 'string "-x objective-c -fobjc-abi-version=2 -fobjc-legacy-dispatch " (cc-flags compiler)))
;;                 (setf (ld-flags compiler)
;;                       (concatenate 'string "-x objective-c -fobjc-abi-version=2 -fobjc-legacy-dispatch " (ld-flags compiler))))
;;               ))))

;; => #P"/Users/strobolights/gitrep/ecl-android/local-install/host/lib/ecl-12.12.1/crosscmp.lsp"
;;(setf a (make-hash-table))
;;(setf (gethash :c a) :d)
;;(loop for k being the hash-key of a using (hash-value v)
;;      collect (list k v))
