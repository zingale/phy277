***************
Getting Started
***************

For this class, we will be working with Linux systems and learning to
use the bash command line, C++ programming, and some basic software
engineering techniques.

MathLab
=======

The computers in the MathLab (S-235) have are a bit out-dated, so we
will mostly use them as terminals to access remote servers that
are more up-to-date.

.. note::

   This actually mimics how we often work in the real world, especially
   using research computing resources.

The remote machines are:

* ``portal.mathlab.stonybrook.edu``
* ``portal2.mathlab.stonybrook.edu``

You may use either or both machines, but note that they are not
mirrored.  So any files you put on one will not be reflected
on the other.

.. important::

   After 3 unsuccessful login attempts, you will be locked out
   of the machine for an hour.

The Terminal
============

Our standard interface to the computer is the command line, accessible
via the terminal app.

The terminal is our window to the computer.  It runs an interactive
shell called `Bash <https://en.wikipedia.org/wiki/Bash_(Unix_shell)>`_
that operates as a `REPL
<https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop>`_:

* Read: Bash will read a command that you enter at the promot

* Execute: Bash will execute the command

* Print: the output from the command will be printed to the terminal

* Loop: the process repeats, with the prompt waiting to read your next
  command.

Accessing the remote servers
----------------------------

The `ssh <https://en.wikipedia.org/wiki/Secure_Shell>`_ command allows for a secure
connection to a remote machine.  At the terminal prompt we can do:

.. prompt:: bash

   ssh -l <username> portal.mathlab.stonybrook.edu

where you replace ``<username>`` with your NetId.  You will then be prompted for
your password (the one associated with your NetId).

If the connection is successful, then you will should see a prompt like:

::

  [mzingale@portal ~]$

in the terminal.  This shows (the ``@portal``) that you are connected to portal.


.. TODO -- add screenshots
