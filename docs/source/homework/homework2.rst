***********
Homework #2
***********

.. admonition:: Completing this assignment

   For the problems below, create a *single text file* in ``nano`` called
   ``homework2.txt`` and record the commands that you need to do to
   accomplish the goal of each problem.  If the problem asks for your
   to capture the output of a command, copy-paste it into this same text file.

   Upload your ``homework2.txt`` to Brightspace *as well as* the script
   that you write in the last problem.

.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.

1. *scp practice*

   * On your laptop or one of the MathLab machines, create a file of
     the form :samp:`{username}.txt`, where you replace
     :samp:`{username}` with your ``portal`` username / NetID.

   * Using ``scp`` (or ``pscp`` if you are using Windows / PuTTY), transfer
     the file to ``portal.mathlab.stonybrook.edu`` into the directory
     ``/home/phy277_spr26``.

     This is a directory that is world readable / writable.

   * Copy the exact ``scp`` command you used and the output from the
     transfer when you did it on the command line (this will show, for
     instance, the transfer speed, percentage complex, etc.) and put it
     in your ``homework2.txt`` file that you will submit for this assignment.

   * Finally, ``ssh`` into ``portal`` and do an ``ls -l`` on the directory
     you copied the file to.  What are the permissions on your file, and
     who (user, group members, and others) has access to read and write it?

   .. important::

      This directory only exists on ``portal`` and not ``portal2``.



2. *pipes*

   In class, we learned the ``sort`` and ``wc`` commands, and how they
   work with pipes (``|``).  Now for two new commands:

   *  ``uniq`` : remove repeated lines from the input

   * ``cut`` : this will extract just a portion of a line from input

   Here's an example.  Go to ``~/shell-lesson-data/exercise-data/animal-counts``

   The file ``animals.csv`` is a `command-separate values file
   <https://en.wikipedia.org/wiki/Comma-separated_values>`_.  If we
   look at the file (just use ``cat``) we see that the first column is
   the date, the second column is an animal, and the third column is a
   count (number of times the animal was seen).  These columns are separated
   by a comma, ``,``.

   If we do:

   .. prompt:: bash

      cut -d , -f 2 animals.csv

   Then we get just the middle column.  Here the ``-d`` flag specifies
   the *delimiter* separating the columns, and the ``-f`` flag
   specifies which field we want (the second).

   .. tip::

      Remember, you can do ``man cut`` to learn these options.

   The output of this is:

   ::

      deer
      rabbit
      raccoon
      rabbit
      deer
      fox
      rabbit
      bear

   We want to get just the types of animals that were seen, so any duplicates should
   be removed.

   If you just pipe the output to ``uniq`` it doesn't work, since ``uniq`` only looks
   at the previous line.  So you need to sort the output first.

   *Your task:* Give the bash one-line sequence (several commands connected
   with pipes) that will give you just the list of animals observed,
   with no duplicates.


3. *a script*

   In ``~/shell-lesson-data/exercise-data/alkanes``, you'll find a
   collection of files that describe different alkane molecules.
   Your task here is to write a simple shell script that takes
   the name of a file and outputs how many atoms is has.

   You can find the lines containing an atom in the file by using ``grep``
   to look for ``ATOM``.

   For our script, we want to run it like:

   .. prompt:: bash

      ./myscript cubane.pdb

   In the script, we can reference the filename that follows our
   script using the variable ``$1``.  For instance, a script that had this:

   .. code:: bash

      #!/bin/bash

      echo $1

   would just echo whatever the first argument to your script was.

   *Your task:*

   * Create a file called ``myscript.sh`` in ``nano``.  It should start
     with

     .. code:: bash

        #!/bin/bash

     as we discussed in :ref:`sec:executable_scripts`.

   * Add the sequence of commands that ``grep`` the input file (``$1``) and
     count the number of lines that have an atom.

   * Finally, modify the file permissions, giving you
     (and only you---not group or other users) the ability to execute
     your script simply as ``./myscript.sh``

   For this problem, in your ``homework2.txt`` file, share the command you used
   in the last step for the permissions.  Also upload your script separately
   to Brightspace.

