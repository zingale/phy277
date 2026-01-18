*************************
Navigating the Filesystem
*************************

.. admonition:: reading

   We will loosely follow the Software Carpentry lesson on `Navigating
   Files and Directories
   <https://swcarpentry.github.io/shell-novice/02-filedir.html>`_

   You are also encouraged to work through it on your own outside of
   class.


Filesystem terminology
======================

We'll use the following terms throughout here:

* ``filesystem`` : the collection (and organization) of all of the
  files stored on your computer.

* ``file`` : a single unit containing a collection of data

* ``directory`` :  (also known as a folder) a collection of files and directories

* ``home directory`` : your default directory.  When you first open a shell on your computer,
  this is where you are.

Directory structure
===================

First, let's figure out where we are.  The "print working directory" command does this for us:

.. prompt:: bash

   pwd

You'll see something like this:

.. code:: bash

   /home/mzingale/shell-lesson-data

We call this full string the *path*.  Notice a few things:

* Forward slashes, ``/``, are used to separate the path into parts.

* The path begins with a ``/``---we call this the *root directory* of the filesystem.

* Your username is in the path.

Going home
==========

Each of us has a `home directory
<https://en.wikipedia.org/wiki/Home_directory>`_.  This is the
location in the filesystem where you have permission to read, write,
and modify files.  It is also the location in the filesystem that you
start in when you first log in or open a shell.

Changing to your home directory
-------------------------------

If we use the ``cd`` command without any arguments, it will take us home:

.. prompt:: bash

   cd
   pwd

This gives:

.. code:: bash

   /home/mzingale

.. tip::

   Your home directory is special that we have a shortcut for it, ``~``,
   so we can also do:

   .. prompt:: bash

      cd ~

We can use ``~`` as the starting point for changing directories.  E.g.,
each of these will put us in the ``shell-lesson-data/`` directory from
wherever we are on the filesystem:

.. prompt:: bash

   cd
   cd shell-lesson-data

.. prompt:: bash

   cd ~/shell-lesson-data

Absolute vs. relative path
--------------------------

Notice that the path to (my copy of) ``shell-lesson-data`` may be written either as:

* ``/home/mzingale/shell-lesson-data/`` (absolute path)

* ``~/shell-lesson-data/`` (relative path)

Each of these specifies the same location, one as an *absolute path* (this will always begin at the root of the filesystem, ``/``,
and the other a *relative path*.

Listing directory contents
==========================

The ``ls`` command lists the contents of a directory.  Starting in ``shell-lesson-data/``, if we do:

.. prompt:: bash

   ls

we will see:

.. code:: bash

   exercise-data  north-pacific-gyre

These are 2 sub-directories (directories beneath ``shell-less-data/``.  We can make this a little more
clear by adding the ``-F`` flag:

.. prompt:: bash

   ls -F

Then we see:

.. code:: bash

   exercise-data/  north-pacific-gyre/

This now adds a ``/`` to the end of any directories in the listing.

We use sub-directories to help organize our files.  Our complete project
has the structure:

.. code::

   shell-lesson-data
   ├── exercise-data
   │   ├── alkanes
   │   │   ├── cubane.pdb
   │   │   ├── ethane.pdb
   │   │   ├── methane.pdb
   │   │   ├── octane.pdb
   │   │   ├── pentane.pdb
   │   │   └── propane.pdb
   │   ├── animal-counts
   │   │   └── animals.csv
   │   ├── creatures
   │   │   ├── basilisk.dat
   │   │   ├── minotaur.dat
   │   │   └── unicorn.dat
   │   ├── numbers.txt
   │   └── writing
   │       ├── haiku.txt
   │       └── LittleWomen.txt
   └── north-pacific-gyre
       ├── goodiff.sh
       ├── goostats.sh
       ├── NENE01729A.txt
       ├── NENE01729B.txt
       ├── NENE01736A.txt
       ├── NENE01751A.txt
       ├── NENE01751B.txt
       ├── NENE01812A.txt
       ├── NENE01843A.txt
       ├── NENE01843B.txt
       ├── NENE01971Z.txt
       ├── NENE01978A.txt
       ├── NENE01978B.txt
       ├── NENE02018B.txt
       ├── NENE02040A.txt
       ├── NENE02040B.txt
       ├── NENE02040Z.txt
       ├── NENE02043A.txt
       └── NENE02043B.txt


More options
------------

``ls`` has a lot of options.  We can see the *manual page* for ``ls`` by doing:

.. prompt:: bash

   man ls

The options include some that sort the listing, others that show different sets of information, and more.

A helpful option is ``-a``, which shows *all* the files in a directory.  Let's look.  Doing:

.. prompt:: bash

   ls -a

Shows:

.. code:: bash

   .  ..  .DS_Store  exercise-data  north-pacific-gyre

.. note::

   ``man ls`` shows that we can do either ``-a`` or ``--all``, i.e., a short option or a long option.
   When typing commands on the commandline, we usually use the short options, to save keystrokes.  But
   these are equivalent.

We can combine the short option ``-a`` with the ``-F`` option we saw previously:

.. prompt:: bash

   ls -aF

gives:

.. code:: bash

   ./  ../  .DS_Store  exercise-data/  north-pacific-gyre/

Now we see the "hidden files"---those that begin with a ``.``, and we
see two special "files", ``.`` and ``..``---these are helpful for
navigation.

``.`` and ``..``
================

Every directory contains the special directories ``.`` and ``..``:

* ``.`` refers to the current directory
* ``..`` refers to the directory immediately above the one you are in.

For instance, starting in ``~/shell-lesson-data``, if we do:

.. prompt::

   pwd
   ls -aF .
   ls -aF ..

Then the output would look like:

.. code:: bash

   [mzingale@portal shell-lesson-data]$ pwd
   /home/mzingale/shell-lesson-data
   [mzingale@portal shell-lesson-data]$ ls -aF .
   ./  ../  .DS_Store  exercise-data/  north-pacific-gyre/
   [mzingale@portal shell-lesson-data]$ ls -aF ..
   ./             .bashrc   .emacs.d/         __MACOSX/              .Xauthority
   ../            .cache/   .gnuplot_history  .mozilla/              .zshrc
   .bash_history  .config/  hello*            shell-lesson-data/
   .bash_logout   .emacs    hello.cpp         shell-lesson-data.zip
   .bash_profile  .emacs~   .lesshst          .ssh/


.. admonition:: Try it...

   Let's use ``cd`` to move up and down through our project's directory structure.


Moving through the hierarchy
============================

Let's start at our home directory and navigate to ``~/shell-lesson-data/exercise-data/alkanes/``.
We can do this one directory at a time:

.. prompt:: bash

   cd shell-lesson-data
   cd exercise-data
   cd alkanes

or all at once:

.. prompt:: bash

   cd shell-lesson-data/exercise-data/alkanes/

.. tip::

   You can use the "Tab" key to autocomplete directory and file names once you
   type enough to be unique.

   Try doing: ``cd shel`` and hitting "Tab"

Last directory
==============

A final shortcut for navigating directories is doing ``cd -``.  This switches
to the previous directory we were in.  So for instance, doing:

.. prompt:: bash

   cd
   cd shell-lesson-data/exercise-data/alkanes/
   cd
   cd -

would bring us back to ``shell-lesson-data/exercise-data/alkanes/``.


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

   You can navigate through your history of commands using the up and down arrows.
