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


Now save it using
the combination :kbd:`Ctrl-O` to write, and the exit with :kbd:`Ctrl-X`.


Summary
=======

We learned the following commands:

* ``mkdir`` : make a directory

* ``nano`` : a basic text editor

* ``touch`` : update a file's timestamp (and create an empty file if it does not exist)

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

