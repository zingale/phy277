*****
emacs
*****

I'll use the emacs editor for most of the class.  You are welcome to
continue to use nano if you prefer.

.. tip::

   The best way to learn an editor is by using it.  So we'll go over
   some key commands in emacs and I'll introduce more as the semester
   goes on.


Quick tour
==========




Some configuration
==================

Run in terminal by default
--------------------------

Instead of having to remember to add ``-nw`` to the ``emacs`` command,
we can add the following to our ``.bashrc`` file to have it run that way
each time:

::

  emacs() { command emacs -nw "$@"; }

You can add this at the very end of the file (on its own line).

.. important::

   Be sure the end your ``.bashrc`` with a newline (i.e., pressing the
   "enter" key after adding the above line).


``.emacs`` configuration file
-----------------------------


On ``portal`` or ``portal2``, you can add the following ``.emacs`` file to your home directory
to setup some C++ support:

:download:`.emacs <./.emacs>`

.. tip::

   An easy way to put this on the remote server is to right-click the link and
   select "copy link", and then on the remote machine, do:

   .. prompt:: bash

      wget <paste-link-here>

   where you paste the link you copied, as indicated.  

you can check that the file is in the right place by doing:

.. prompt:: bash

   ls -l ~/.emacs

if it says ``No such file or directory`` that it is not installed properly.

This will allow us to use the `flycheck package <https://www.flycheck.org/en/latest/user/installation.html>`_
for C++.  To enable this do the following:

* Start emacs:

  .. prompt:: bash

     emacs -nw

* In emacs, enter the command:

  ::

    M-x package-install

  press the "enter" key, and then type:

  ::

    flycheck

* exit emacs (``C-x C-c``)
