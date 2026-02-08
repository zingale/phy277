*****************
Different Editors
*****************

We already looked at ``nano`` to edit files.  An editor not only allows us to write our source
code, but it can also help us by:

* Doing syntax highlighting of the language

* Handle indentation for us

* Show mismatched ``)`` and ``}`` in our code

* Highlight syntax errors

and more.

Let's look at some common editors

.. figure:: https://imgs.xkcd.com/comics/real_programmers.png
   :width: 90%
   :align: center
   :alt: xkcd comic on editors

   from XKCD

nano
====

``nano`` is a pretty basic editor and very easy to use.  We already saw that when we saved our
``hello.cpp`` it recognized it as C++ code and highlighted it in different colors.

There are some basic customizations you can make by creating a ``~/.nanorc`` file,
some of which are listed here: `customizing nano <https://timnash.co.uk/customising-nano-productivity-friday/>`_

You will be able to complete all of the course work using nano as your
editor.  However you are encouraged to explore alternatives.


emacs
=====

`Emacs <https://www.gnu.org/software/emacs/>`_ is a powerful editor that has a large number of extensions.

You can run emacs in a terminal (instead of a separate window), by doing:

.. prompt:: bash

   emacs -nw

This is useful for remote connections.

Some basic commands with emacs:

* :kbd:`Ctrl-x` :kbd:`Ctrl-c` : exit without saving

* :kbd:`Ctrl-x` :kbd:`Ctrl-s` : save the file

* :kbd:`Ctrl-g` : break out of whatever command you may be in the middle of

* :kbd:`Ctrl-Space` : set a mark (starting point) for selecting text

* :kbd:`Ctrl-w` : cut the text (into the "kill ring")

* :kbd:`Ctrl-y` : paste the text from the kill ring (``y`` is for yank)

Here's my `emacs config file <https://github.com/zingale/mysystem/blob/master/.emacs>`_ file.


vim/vi
======

`vim <https://www.vim.org/>`_ (or vi) has a large user base, like emacs, but
has a very different interface.  vi has two modes: *normal mode* (or command mode)
where you enter commands like save, delete, cut / paste, etc. and
*insert mode* where you enter text into the editor.

You can open a file for editing by:

.. prompt:: bash

   vi file.txt

by default you are in command mode.

* To get into insert mode, press :kbd:`i`

* To return to command mode press the :kbd:`ESC` key

Documentation is available here: https://www.vim.org/docs.php

To save the file and exit you enter command mode (:kbd:`ESC`) and type ``:wq``

An interactive tutorial is available via `OpenVIM <https://openvim.com/>`_.


VS Code
=======

`VS Code <https://code.visualstudio.com/>`_ is a graphical editor that
is extremely popular today.  It has a large number of extensions.

One of the most popular extensions is the `Remote - SSH
<https://code.visualstudio.com/docs/remote/ssh>`_ extension that
allows you to run VS Code on your local machine and edit files on a
remote machine (connecting via SSH).

There are extensive introductory videos here: https://code.visualstudio.com/docs/introvideos/basics
