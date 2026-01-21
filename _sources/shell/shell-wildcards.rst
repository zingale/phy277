Wildcards
=========

.. admonition:: reading

   `Wildcards <https://tldp.org/LDP/GNU-Linux-Tools-Summary/html/x11655.htm>`_ from the
   Linux Documentation Project.


When we want to match multiple files for an operation, we can use wildcards:

* ``*`` matches multiple (or 0) characters

* ``?`` matches a single character

Let's see how this works, by using the data in the ``~/shell-lesson-data/exercise-data/alkanes``
directory.

If we do ``ls -l`` we should see:

::

    total 24
    -rw-rw----. 1 mzingale mzingale 1158 Apr 23  2025 cubane.pdb
    -rw-rw----. 1 mzingale mzingale  622 Apr 23  2025 ethane.pdb
    -rw-rw----. 1 mzingale mzingale  422 Apr 23  2025 methane.pdb
    -rw-rw----. 1 mzingale mzingale 1828 Apr 23  2025 octane.pdb
    -rw-rw----. 1 mzingale mzingale 1226 Apr 23  2025 pentane.pdb
    -rw-rw----. 1 mzingale mzingale  825 Apr 23  2025 propane.pdb

This files contain information about the atomic structure of each compound (you
can just use ``cat`` to look at one).

We can list all the files that start with ``p`` by doing:

.. prompt:: bash

   ls p*

Here the ``*`` matches any number of characters.  So both ``pentane.pdb`` and ``propane.pdb``
match.

We could instead look for all the 6-letter compounds that end in -``ane`` by doing:

.. prompt:: bash

   ls ???ane.pdb

Now, the ``?`` matches exactly one character.  By using 3 of them in a row, we are requiring
3 (and only 3) characters followed by ``ane.pdb`` in the filename.

.. note::

   These wildcards, ``?`` and ``*``, are *expanded* by the shell first and then passed
   to the command we are using.  This means that we can use them with any Unix commands.
