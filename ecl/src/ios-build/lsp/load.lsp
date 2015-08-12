;;; lsp/load.lsp.  Generated from load.lsp.in by configure.

(terpri)
(princ ";;; Loading src:lsp;export.lsp")
(load "src:lsp;export.lsp" :verbose nil)
(terpri)
(princ ";;; Loading src:lsp;defmacro.lsp")
(load "src:lsp;defmacro.lsp" :verbose nil)
(terpri)
(princ ";;; Loading src:lsp;helpfile.lsp")
(load "src:lsp;helpfile.lsp" :verbose nil)
(terpri)
(princ ";;; Loading src:lsp;evalmacros.lsp")
(load "src:lsp;evalmacros.lsp" :verbose nil)
(terpri)
(princ ";;; Loading src:lsp;cmuutil.lsp")
(load "src:lsp;cmuutil.lsp" :verbose nil)

(sys:*make-constant '+lisp-module-files+
'("src:lsp;export.lsp"
  "src:lsp;defmacro.lsp"
  "src:lsp;helpfile.lsp"
  "src:lsp;evalmacros.lsp"
  "src:lsp;setf.lsp"
  "src:lsp;predlib.lsp"
  "src:lsp;seq.lsp"
  "src:lsp;arraylib.lsp"
  "src:lsp;assert.lsp"
  "src:lsp;defstruct.lsp"
  "src:lsp;iolib.lsp"
  "src:lsp;listlib.lsp"
  "src:lsp;mislib.lsp"
  "src:lsp;numlib.lsp"
  "src:lsp;packlib.lsp"
  "src:lsp;seqlib.lsp"
  "src:lsp;trace.lsp"
#+old-loop
  "src:lsp;loop.lsp"
#-old-loop
  "src:lsp;loop2.lsp"
#+cmu-format
  "src:lsp;format.lsp"
  "src:lsp;defpackage.lsp"
  "src:lsp;ffi.lsp"
  "src:lsp;mp.lsp"
#+tk
  "src:lsp;tk-init.lsp"
  "build:lsp;config.lsp"
  "src:lsp;module.lsp"
  "src:lsp;cmdline.lsp"
  "src:lsp;autoload.lsp"
  "src:lsp;cdr-5.lsp"
))

(mapc #'(lambda (x)
         (terpri)
         (princ ";;; Loading ")
         (princ x)
         (load x :verbose nil))
 (cddddr +lisp-module-files+))
