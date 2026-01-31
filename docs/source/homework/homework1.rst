***********
Homework #1
***********

For this assignment, create a *single text file* in a ``nano`` called
``homework1.txt`` and provide the sequence of commands needed for
each problem.

.. note::

   You may not use generative AI / large-language models for any part
   of this assignment.


1. Starting in your home directory:

   * Create directory structure:

     .. code:: bash

        ~/homework/1/files/

   * Now move into the ``files/`` sub-directory you created, and create
     a file called ``problem.txt`` using the ``touch`` command.

2. For this problem we will use the same directory-structure/files
   from the shell lessons (see :ref:`sec:shell-sample-data` to remember
   how to get this).

   * Change to the directory:

     .. code:: bash

        ~/shell-lesson-data/exercise-data/alkanes

   * Now make a subdirectory under that called ``tests/``
     and change directory into ``tests/``.

   * From *within* ``tests/`` copy the files ``cubane.pdb``
     ``ethane.pdb``, and ``octane.pdb`` from the directory above you
     into your current directory.  You should use a single command for
     it.


3. Let's consider two ways to do the same task---moving a file
   to a new location.  We want to move a file ``~/answer.txt``
   to ``~/homeworks/answer.txt``

   * Method 1: copy + delete

     * In your home directory, create a file called ``answer.txt`` using ``touch``

     * Create a directory called ``homeworks/``

     * *Copy* the file ``answer.txt`` into ``homeworks/``

     * Delete the version of ``answer.txt`` in your home-directory
       (only the version ``homeworks/answer.txt``) should remain.

   * Method 2: moving

     * Back in your home directory, create a file canned ``answer2.txt`` (again using ``touch``).

     * *Move* this file, using a single command, into the
       ``homeworks/`` directory you created previously.


