***********
Homework #1
***********

.. admonition:: Completing this assignment

   For this assignment, create a *single text file* in ``nano`` called
   ``homework1.txt`` and provide the sequence of commands needed for
   each problem.

   You will then upload ``homework1.txt`` to Brightspace.

.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.


1. Starting in your home directory:

   * Create the directory structure:

     .. code:: bash

        ~/homework/1/files/

     .. dropdown:: solution

        Starting in your home directory:

        .. prompt:: bash

           mkdir homework
           cd homework
           mkdir 1
           cd 1
           mkdir files

        or

        .. prompt:: bash

           mkdir homework
           mkdir homework/1
           mkdir homework/1/files

        or if you looked a ``man mkdir``

        .. prompt:: bash

           mkdir -p homework/1/files

   * Now move into the ``files/`` sub-directory you created, and create
     a file called ``problem.txt`` using the ``touch`` command.

     .. dropdown:: solution

        .. prompt:: bash

           cd ~/homework/1/files
           touch problem.txt


2. For this problem we will use the same directory-structure/files
   from the shell lessons (see :ref:`sec:shell-sample-data` to remember
   how to get this).

   * Change to the directory:

     .. code:: bash

        ~/shell-lesson-data/exercise-data/alkanes

     .. dropdown:: solution

        .. prompt:: bash

           cd ~/shell-lesson-data/exercise-data/alkanes

   * Now make a subdirectory under that called ``tests/``
     and change directory into ``tests/``.

     .. dropdown:: solution

        .. prompt:: bash

           mkdir tests
           cd tests

   * From *within* ``tests/`` copy the files ``cubane.pdb``,
     ``ethane.pdb``, and ``octane.pdb`` from the directory above
     into your current directory.  You should use a single command for
     it.

     .. dropdown:: solution

        .. prompt:: bash

           cp ../cubane.pdb ../ethane.pdb ../octane.pdb .

3. Let's consider two ways to do the same task---moving a file
   to a new location.  We want to move a file ``~/answer.txt``
   to ``~/homeworks/answer.txt``

   * Method 1: copy + delete

     * In your home directory, create a file called ``answer.txt`` using ``touch``

     * Create a directory called ``homeworks/``

     * *Copy* the file ``answer.txt`` into ``homeworks/``

     * Delete the version of ``answer.txt`` in your home-directory
       (only the version ``homeworks/answer.txt``) should remain.

     .. dropdown:: solution

        .. prompt:: bash

           touch answer.txt
           mkdir homeworks
           cp answer.txt homeworks/
           rm answer.txt

   * Method 2: moving

     * Back in your home directory, create a file named
       ``answer2.txt`` (again using ``touch``).

     * *Move* this file, using a single command, into the
       ``homeworks/`` directory you created previously.

     .. dropdown:: solution

        .. prompt:: bash

           touch answer2.txt
           mv answer2.txt homeworks

4. Using ``man ls``, find the option/flag that sorts files by size
   (largest file first).  In addition to this new option, also use
   the ``-l`` option to get a long listing.

   * Give the ``ls`` command that will do this sorting + long listing

     .. dropdown:: solution

        .. prompt:: bash

           ls -lS

        or

        .. prompt:: bash

           ls -l -s

        or

        .. prompt:: bash

           ls -l --size

   * In ``~/shell-lesson-data/exercise-data/alkanes/``, show the
     (long-listing) output when you sort by size

     .. dropdown:: solution

        ::

          -rw-rw----. 1 zingale zingale 1828 Apr 23  2025 octane.pdb
          -rw-rw----. 1 zingale zingale 1226 Apr 23  2025 pentane.pdb
          -rw-rw----. 1 zingale zingale 1158 Apr 23  2025 cubane.pdb
          -rw-rw----. 1 zingale zingale  825 Apr 23  2025 propane.pdb
          -rw-rw----. 1 zingale zingale  622 Apr 23  2025 ethane.pdb
          -rw-rw----. 1 zingale zingale  422 Apr 23  2025 methane.pdb

