*********
The Shell
*********

.. admonition:: reading

   We will loosely follow the Software Carpentry lesson on `The Unix Shell <https://swcarpentry.github.io/shell-novice/>`_


The shell
=========

The `shell <https://en.wikipedia.org/wiki/Unix_shell>`_ is your
interface to the operator system.  It implements a `REPL interface <https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop>`_:
Read, Execute, Print, Loop.  This means it:

* Reads: Bash will read a command that you enter at the promot

* Executes: Bash will execute the command

* Prints: the output from the command will be printed to the terminal

* Loops: the process repeats, with the prompt waiting to read your next
  command.

The power of the shell is that we can easily combine different tools
together to create powerful commands to manipulate files on the
computer.

Accessing the shell
===================

To access the shell, we need to open a terminal on the computer.  This
will present us with the `command prompt
<https://en.wikipedia.org/wiki/Command-line_interface#Command_prompt>`_,
which typically is a ``$`` (although it can be customized)`.

We already saw the ``echo`` command:

.. prompt:: bash

   echo Hello, World

But there are many more commands that we will learn shortly.


Which shell?
============

There are a wide variety of shells that are used today.  The default
on many systems is `BASH <https://www.gnu.org/software/bash/>`_.  Others
that you might commonly encounter are `zsh <https://en.wikipedia.org/wiki/Z_shell>`_ and
`fish <https://fishshell.com/>`_.

We'll focus on BASH, and most of what we learn here will apply
directly to the other shells.

Some online shell documentation:

* The `Software Carpentry Unix Shell <https://swcarpentry.github.io/shell-novice/>`_ lesson

* The official `Bash Reference Manual <https://www.gnu.org/software/bash/manual/html_node/index.html>`_

A basic "cheat sheet" is available here: `Unix/Linux Command Reference <https://upload.wikimedia.org/wikipedia/commons/7/79/Unix_command_cheatsheet.pdf>`_.


Configuring Bash
================

Every time we open a terminal, the shell reads a special file called
``.bashrc``.  This file contains commands that customize our shell
in various ways.

As the semester goes on, we'll add to this file to make our lives
easier.

We can look at the current contents of our ``.bashrc`` file by doing:

.. prompt:: bash

   cat ~/.bashrc
