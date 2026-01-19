*****************************
Copying, Moving, and Deleting
*****************************

Copying files
=============

Let's say we want to make a copy (backup) of our thesis.  We use the ``cp`` command for this.
This has the syntax :samp:`cp {origin} {destination}`.

Let's start by just making a copy in our own directory.  We can do this as:

.. prompt:: bash

   cp thesis.txt thesis-backup.txt

If we do ``ls -l`` we should see both the original and copy present.

We could put the copy in a different location, like our home directory, by including
the path in the destination, like:

.. prompt:: bash

   cp thesis.txt ~/thesis-backup.txt



Moving files
============

Maybe we want to put the backup in a separate directory.

We could copy it there, but we already made a copy.  Instead let's move
our copy to a new directory called ``backup/`` under our ``thesis/`` directory.

Starting in ``~/shell-lesson-data/exercise-data/writing/thesis/``, we can do:

.. prompt:: bash

   mkdir backup
   mv thesis-backup.txt backup

Here we are using a *relative path* for the destination.

.. note::

   We didn't need to specify the filename in the *destination* part of
   the ``mv``---in this case, it will keep the filename the same, but
   just move it into the new directory.

   We could equivalently do:

   .. prompt:: bash

      mv thesis-backup.txt backup/thesis-backup.txt

   We could also be more explicit and do:

   .. prompt:: bash

      mv thesis-backup.txt ./backup/thesis-backup.txt

.. tip::

    Both ``cp`` and ``mv`` can copy/move multiple files to a
    destination in a single command.  In this case, the last argument
    is used as the destination.

    So to move both ``thesis-backup.txt`` and ``topics.txt``, we could
    do:

    .. prompt:: bash

       mv thesis-backup-txt topics.txt backup


Deleting files
==============

To delete files, we use the ``rm`` command (short for *remove*).

Let's remove the empty file ``topics.txt``:

.. prompt:: bash

   rm topics.txt

.. admonition:: Try it...

   We also put a copy of ``thesis-backup.txt`` in our home directory.  Remove that file.

To remove a directory, we need to first remove all the files in the directory, and then we can remove the directory using ``rmdir``.
Let's remove the ``backup/`` directory.  First go back to your ``thesis/`` sub-directory.  Then:

.. prompt:: bash

   rm backup/thesis-backup.txt
   rmdir backup

.. tip::

   We can do a recursive ``rm`` to remove all the contents of a directory and the directory itself, by doing:

   .. prompt:: bash

      rm -r backup

.. caution::

   Linux does not have an "undelete" function.  When you remove a file
   on the command line it is gone for good.  Therefore you should
   always double check the ``rm`` command you typed before hitting :kbd:`Enter`.

   Another good practice is to use ``rm`` in *interactive mode*, where
   it will prompt you before removing a file (and ``cp`` and ``mv``
   can be used this way too).

   To make this the default, add the following lines to your ``.bashrc``:

   .. code:: bash

      alias rm='rm -i'
      alias cp='cp -i'
      alias mv='mv -i'


Summary
=======

We learned the following commands:

* ``mv`` : move a file or directory

* ``cp`` : copy a file or directory

* ``rm`` : remove a file (and/or directory if done recursively)


Exercises
=========

