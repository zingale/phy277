*************************
Navigating the Filesystem
*************************

.. admonition:: reading

   We will loosely follow the Software Carpentry lesson on `Navigating Files and Directories <https://swcarpentry.github.io/shell-novice/02-filedir.html>`_



First walkthrough
=================

Let's walkthrough the `Navigating Files and Directories
<https://swcarpentry.github.io/shell-novice/02-filedir.html>`_
lesson together.  You are also encouraged to work through it on your
own outside of class.


Filesystem terminology
======================

We'll use the following terms throughout here:

* ``file system`` : the collection (and organization) of all of the files stored on your computer

* ``file`` : a single unit containing a collection of data

* ``directory`` :  (also known as a folder) a collection of files and directories

* ``home directory`` : your default directory.  When you first open a shell on your computer,
  this is where you are.





Summary
=======

We learned the following commands:

* ``pwd`` : print working directory (where you currently are in the file system)

* ``ls`` : list the contents of a directory

* ``cd`` : change directory


There are a few special directories that always exist the help us navigate:

* ``.`` : the current directory

* ``..`` : one directory above us

* ``~`` : our home directory

The ``/`` character has 2 roles:

* The ``/`` directory is the *root* of the filesystem

* A path uses ``/`` to separate directory names

.. tip::

   The Unix shell uses tab-completion to make it easier to type.
   Start typing a path (or command) and then press the *Tab* key and
   it will either complete it (if there is a unique file / command) or
   display the possible completions.

.. tip::

   You can navigate through your history of commands using the up and down arrows.

