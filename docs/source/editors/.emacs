;; .emacs


(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(diff-switches "-u")
 '(package-selected-packages '(flycheck)))


(require 'package)

(add-to-list 'package-archives
             '("MELPA Stable" . "https://stable.melpa.org/packages/") t)
(package-initialize)


(load-theme 'tango-dark)

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


;; C+
(add-hook 'c++-mode-hook 'flycheck-mode)
;(add-hook 'c++-mode-hook (lambda () (setq flycheck-gcc-language-standard "c++23")))
;(add-hook 'c++-mode-hook (lambda () (setq flycheck-cppcheck-language-standard "c++23")))
(with-eval-after-load 'flycheck
  ;; Use C++23 for GCC
  (setq-default flycheck-gcc-language-standard "c++23")

  ;; Use C++23 for Clang
  (setq-default flycheck-clang-language-standard "c++23"))


; wind move -- use shift + arrows to change windows
(when (fboundp 'windmove-default-keybindings)
  (windmove-default-keybindings))


; show the function name on the status bar
(which-function-mode 1)


;; 24.1 changed how backspace worked
(setq delete-active-region nil)


;; show line numbers
(add-hook 'prog-mode-hook 'display-line-numbers-mode)


(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )


;; show the matching paranthesis
(show-paren-mode 1)
