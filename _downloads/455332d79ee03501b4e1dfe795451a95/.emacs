;; .emacs

(load-theme 'tango-dark)


(custom-set-variables
 ;; uncomment to always end a file with a newline
 ;'(require-final-newline t)
 ;; uncomment to disable loading of "default.el" at startup
 ;'(inhibit-default-init t)
 ;; default to unified diffs
 '(diff-switches "-u"))

;;; uncomment for CJK utf-8 support for non-Asian users
;; (require 'un-define)

; electric indentation
(electric-indent-mode 0)


; C++ 4 spaces indenting
(setq-default c-default-style "linux"
              c-basic-offset 4)

; just spaces
(setq-default indent-tabs-mode nil)

; C++ seems to override the default tabs.  See
; https://emacs.stackexchange.com/questions/12173/confusion-by-the-usage-of-indent-tabs-mode-nil

(defun endless/c-hook ()
  (setq indent-tabs-mode nil))
(add-hook 'c++-mode-hook #'endless/c-hook)


; wind move -- use shift + arrows to change windows
(when (fboundp 'windmove-default-keybindings)
  (windmove-default-keybindings))


; show the function name on the status bar
(which-function-mode 1)


;; 24.1 changed how backspace worked
(setq delete-active-region nil)


;; show line numbers
(add-hook 'prog-mode-hook 'display-line-numbers-mode)


