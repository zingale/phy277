****************************
Create Files and Directories
****************************

.. admonition:: reading

   We will loosely follow the Software Carpentry `Working with Files
   and Directories
   <https://swcarpentry.github.io/shell-novice/03-create.html>`_
   lesson from `The Unix Shell
   <https://swcarpentry.github.io/shell-novice/>`_


Let's start in ``~/shell-lesson-data/exercise-data/writing``:

.. prompt:: bash

   cd ~/shell-lesson-data/exercise-data/writing

Making a new directory
======================

We want to put a new document here (our thesis) and we will organize it in its own sub-directory.
The command to make a new directory is ``mkdir`` (for *make directory*).  We can do:

.. prompt:: bash

   mkdir thesis

and then change directory into it and print the current directory:

.. prompt:: bash

   cd thesis
   pwd

This should show something like:

.. code:: bash

   /home/mzingale/shell-lesson-data/exercise-data/writing/thesis

.. tip::

   Don't use spaces in directory or file names.  This makes navigation difficult.

   Likewise, don't start a directory or filename with a ``-``, since most commandline tools
   will interpret this as an option / flag.

Creating a new file
===================

We already did a quick example of creating a ``hello.cpp`` earlier,
using the *nano* editor.  Let's create a new file now, called
``thesis.txt``:

.. prompt:: bash

   nano thesis.txt

The editor will open with an empty file.  Write a few sentences, like the screenshot below

.. figure:: thesis-nano.png
   :align: center
   :width: 90%
   :alt: nano in our terminal with some text for our thesis.

   The nano editor with our ``thesis.txt``

Now save it using
the combination :kbd:`Ctrl-O` to write, and the exit with :kbd:`Ctrl-X`.

.. admonition:: Try it...

   Sometimes we need a file to exist, but we don't care if there is anything
   in it.  We can use the ``touch`` command for this---if a file with the
   name does not exist, it will create it as an empty file.

   .. prompt:: bash

      touch topics.txt

   We can see the file sizes by using the ``-l`` flag to ``ls``:

   .. prompt:: bash

      ls -l

   This will show something like:

   .. code:: bash

      total 4
      -rw-r-----. 1 mzingale mzingale 75 Jan 19 13:08 thesis.txt
      -rw-r-----. 1 mzingale mzingale  0 Jan 19 13:16 topics.txt

   There are a lot of columns here, but the 5th column gives the size
   in bytes for our file.


Looking at our file
===================

If we do ``ls``, then we'll see our file.

If we want to see the contents of the file from the command line, we can use
the ``cat`` command:

.. prompt:: bash

   cat thesis.txt

.. tip::

   For very long files, the output will scroll past our screen without stopping.
   Instead we can use the ``more`` command, which acts as a *pager*.  We'll
   see this more in a bit.


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

Deleting files
==============


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


Wildcards
=========

Summary
=======

We learned the following commands:

* ``mkdir`` : make a directory

* ``nano`` : a basic text editor

* ``touch`` : update a file's timestamp (and create an empty file if it does not exist)

* ``cat`` : display the contents of a file (it has other uses which we'll explore later)

* ``mv`` : move a file or directory

* ``cp`` : copy a file or directory

* ``rm`` : remove a file (and/or directory if done recursively)

We also learned about wildcards:

* ``*`` matches multiple (or 0) characters

* ``?`` matches a single character

Exercises
=========

.. admonition:: Try it...

   From your home directory, create a directory / file structure that looks like::

      project
      ├── code
      ├── data
      │   ├── experiment-01.txt
      │   ├── experiment-02.txt
      │   └── experiment-03.txt
      └── results

