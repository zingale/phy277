*****
emacs
*****

I'll use the emacs editor for most of the class.  You are welcome to
continue to use nano if you prefer.

The best way to learn an editor is by using it.  So we'll go over
some key commands in emacs and I'll introduce more as the semester
goes on.

.. tip::

   A quick reference card summarizing the basic commands is available
   here: :download:`emacs reference card <https://www.gnu.org/software/emacs/refcards/pdf/refcard.pdf>`

Quick tour
==========


.. tip::

   The official emacs website has a `helpful guided tour to introduce emacs <https://www.gnu.org/software/emacs/tour/>`_.

Most commands in emacs start use either the :kbd:`Ctrl` key or
something that emacs calls the "Meta" key, and a single character.
E.g. :kbd:`Ctrl-a` will go to the start of the line.

.. note::

   For the "Meta" key, you have two options:

   * Hold down :kbd:`Alt` and the other letter in the command.

   * Press (and release) :kbd:`ESC` and then press the other letter in the command.

   I'll use :kbd:`M-x` to indicate when the meta key is used (in this case, in combination with :kbd:`x`).


Let's open emacs while we try these commands:

.. prompt:: bash

   emacs -nw


Working with files
------------------

* :kbd:`Ctrl-x` :kbd:`Ctrl-f` : read a file into emacs

* :kbd:`Ctrl-x` :kbd:`Ctrl-s` : save a file to the filesystem


Moving around the file
----------------------

To move the cursor, you can just use the arrow keys.  Other
options include:

* :kbd:`Ctrl-a` : go to the beginning of the line

* :kbd:`Ctrl-e` : go to the end of the line

* :kbd:`Ctrl-v` : page down

* :kbd:`M-v` : page up

* :kbd:`M-<` : go to the beginning of the file

* :kbd:`M->` : go to the end of the file


.. tip::

   Since :kbd:`Ctrl-v` is mapped as "page down", to paste something into your emacs
   buffer that you copied from a different application (like the web browser), use
   :kbd:`Ctrl-Shift-v`.

Abort / undo
------------

* :kbd:`Ctrl-g` : stop the current command (partially typed or
  running)

* :kbd:`Ctrl-x` :kbd:`u` : undo

* :kbd:`Ctrl-l` : redraw the screen


Searching
---------

* :kbd:`Ctrl-s` : search forward

* :kbd:`Ctrl-r` : search backward

* :kbd:`M-%` : query-replace text


Marking
-------

In emacs, for a lot of commands, we define a region by first *marking* the start
and then going to the end and executing the command.

* :kbd:`Ctrl-Space` : set a mark

Killing / deleting
------------------

In emacs, *killing* is used to mean cut.  The removed text is put into a
buffer where it can be *yanked* back.

* :kbd:`Ctrl-k` : kill from cursor to the end of the line

* :kbd:`Ctrl-w` : kill the region (from the mark to the cursor position)

* :kbd:`Ctrl-y` : yank back killed text


Formatting
----------

* :kbd:`TAB` : auto-indent the line (really nice for source code)

* :kbd:`M-q` : word wrap a paragraph

Exiting
-------

* :kbd:`Ctrl-x` :kbd:`Ctrl-c` : exit emacs completely



