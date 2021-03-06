;;; -*- Mode:Lisp -*-
;;; bare.lsp.  Generated from bare.lsp.in by configure.
;;;
;;; This file can be loaded either in ECL_MIN or in the final executable
;;; ECL. In both cases, it ensures that we have a working Common-Lisp
;;; environment (either interpreted, as in ECL_MIN, or compiled, as in ECL),
;;; that the compiler is loaded, that we use the headers in this directory,
;;; etc.
;;;
;;; * By redefining "SYS:" ECL will be able to
;;;   find headers and libraries in the build directory.
;;;
(princ "
;;;
;;; Welcome to bare.lsp. Let's bring this instance up!
;;;")

(sys:*make-constant '+ecl-optimization-settings+ 
  '((optimize (safety 2) (speed 1) (debug 1) (space 1))
    (ext:check-arguments-type nil)))
(sys:*make-constant '+ecl-unsafe-declarations+
  '(optimize (safety 0) (speed 3) (debug 0) (space 0)))
(sys:*make-constant '+ecl-safe-declarations+
  '(optimize (safety 2) (speed 1) (debug 1) (space 1)))

(si::pathname-translations "SRC" `(("**;*.*.*" "/Users/strobolights/dev/mecl/ecl/src/**/*.*")))
(si::pathname-translations "EXT" `(("**;*.*.*" "/Users/strobolights/dev/mecl/ecl/src/../contrib/**/*.*")))
(si::pathname-translations "BUILD" `(("**;*.*.*" "/Users/strobolights/dev/mecl/ecl-build-for-ios64/**/*.*")))
(si::pathname-translations "SYS" '(("**;*.*.*" "/Users/strobolights/dev/mecl/ecl-build-for-ios64/**/*.*")))

;;;
;;; * Set ourselves in the 'SYSTEM package
;;;
(setq *package* (find-package "SYSTEM"))
(setq si::*keep-definitions* nil)

;;;
;;; * Create bogus commit version number
;;;

(setq si::+commit-id+ "UNKNOWN")

;;;
;;; * Load Common-Lisp base library
;;;
(princ "
;;;
;;; About to load lsp/load.lsp
;;; ")

(if (or (member "ECL-MIN" *features* :test #'string-equal)
	(member "CROSS" *features* :test #'string-equal))
  (load "lsp/load.lsp" :verbose nil))

(defun si::process-command-args () )

;;;
;;; * Load PCL-based Common-Lisp Object System
;;;
(setf sys::*gc-verbose* nil)
#+(or ecl-min cross)
(progn
 (terpri)
 (princ ";;; Loading clos/load.lsp")
 (load "clos/load.lsp" :verbose nil))

#+cmu-format
(progn
 (terpri)
 (princ ";;; Loading lsp/format.lsp")
 (load "src:lsp;format.lsp" :verbose nil))

;;;
;;; * Load the compiler.
;;;

;; Make sure compiler sees what it should see.
#-:wants-dlopen (setq *features* (delete :dlopen *features*))
#+:wants-dlopen (push :dlopen *features*)

(terpri)
(princ #+(or cross ecl-min) ";;; About to load cmp/load.lsp"
       #-(or cross ecl-min) ";;; About to load cmp.so")

(load #+(or cross ecl-min) "cmp/load.lsp"
      #-(or cross ecl-min) "cmp.so")

;;;
;;; * Change the place where temporary files go to
;;;
(si::pathname-translations "TMP" '(("**;*.*.*" "/Users/strobolights/dev/mecl/ecl-build-for-ios64/**/*.*")))

;;;
;;; * Remove documentation from compiled files
;;;
(setq si::*keep-documentation* nil)

;;;
;;; * Timed compilation facility.
;;;
(defun compile-if-old (destdir sources &rest options)
  (ensure-directories-exist destdir :mode #o0777)
  (mapcar #'(lambda (source)
	      (let ((object (merge-pathnames destdir (compile-file-pathname source :type :object))))
		(unless (and (probe-file object)
			     (>= (file-write-date object) (file-write-date source)))
		  (format t "~&(compile-file ~S :output-file ~S~{ ~S~})~%"
			  source object options)
		  (apply #'compile-file source :output-file object options))
		object))
	  sources))

(defvar *module-symbols* nil)
(defvar *module-files* nil)

(defun build-fake-module (name lisp-files)
  (let* ((output (make-pathname :type "fasc" :defaults name))
         (files '()))
    (unwind-protect
         (let ((ext:*source-location* nil))
           (loop for i in lisp-files do (push (open i :direction :input) files))
           (setf files (nreverse files))
           (let ((joined (apply #'make-concatenated-stream files)))
             (ext::bc-compile-file joined :output-file output)))
      (mapc #'close files))
    output))

(make-package "ASDF")

(defun build-fake-asdf (name static-library compiled-filename &key depends-on)
  (let ((path (make-pathname :name name :type "asd"))
	(compiled (make-pathname :host "SYS"
				 :name (pathname-name compiled-filename)
				 :type (pathname-type compiled-filename)))
	(library (make-pathname :host "SYS"
				:name (pathname-name static-library)
				:type (pathname-type static-library))))
    (with-open-file (*standard-output* path
                     :direction :output :if-exists :supersede
                     :if-does-not-exist :create)
      (print `(defsystem ,name :class asdf::prebuilt-system
                         :lib ,library
			 :depends-on ,depends-on
                         :components ((:compiled-file ,(string name)
				       :pathname ,compiled)))))
    path))

(defun build-module (name sources &key additional-files depends-on
                     (builtin nil) (dir "build:")
                     ((:prefix si::*init-function-prefix*) "EXT"))
  (mapc #'proclaim +ecl-optimization-settings+)
  (let* ((name (string-downcase name)))
    (when additional-files
      (setf *module-files* (append additional-files *module-files*)))
    (let* ((objects (compile-if-old dir sources :system-p t :c-file t
                                    :data-file t :h-file t))
	   (compiled-file-name (string name))
	   (static-library (c::build-static-library name :lisp-files objects)))
      (push static-library *module-files*)
      (when builtin
        (push (intern name) *module-symbols*))
      #-:wants-dlopen
      (push (build-fake-module name sources) *module-files*)
      #+:wants-dlopen
      (push (setf compiled-file-name (c::build-fasl name :lisp-files objects))
	    *module-files*)
      (push (if (equalp name "asdf")
		(build-fake-asdf "prebuilt-asdf" static-library compiled-file-name :depends-on '("cmp"))
		(build-fake-asdf name static-library compiled-file-name :depends-on depends-on))
	    *module-files*)
      )))

;;;
;;; * Update version number now that SI:SYSTEM is available
;;;

(let ((commit-id (probe-file "/Users/strobolights/dev/mecl/ecl/src/../.git/logs/HEAD")))
  (when commit-id
    (let ((last nil))
      (with-open-file (file commit-id :direction :input :element-type :default
			    :external-format :default)
	(loop for l = (read-line file nil nil nil)
	   while l
	   do (setf last l)))
      (when last
	(handler-case
	    (let* ((start (position #\Space last)))
	      (when start
		(let ((end (position #\Space last :start (incf start))))
		  (when end
		    (setq si::+commit-id+ (subseq last start end))))))
	  (serious-condition ()))))))
;;;
;;; * Go back to build directory to start compiling
;;;
#+ecl-min
(setq *features* (cons :stage1 (remove :ecl-min *features*)))

(terpri)
(princ ";;;
;;; Now we are in shape to do something useful.
;;; End of bare.lsp")
(terpri)
(setf c::*compiler-break-enable* t)
