.. _sec:shell-sample-data:

****************
Some Sample Data
****************


To help us understand some basic shell operations, we will all work
with a collection of files and directories.  Type (or copy/paste) the
following commands into your terminal to get the files we need (we'll
explain their meaning later):

.. prompt:: bash

   curl https://swcarpentry.github.io/shell-novice/data/shell-lesson-data.zip --output shell-lesson-data.zip
   unzip shell-lesson-data.zip

.. tip::

   Remember you can click on the copy button in the upper right of the text box and then paste into your
   terminal using :kbd:`Ctrl-Shift-v`.

This data set comes from the `Software Carpentry project <https://software-carpentry.org/>`_.

This creates a directory on the filesystem named
``shell-lesson-data/``.  To begin, we want to "change directory" into
that directory, using the ``cd`` command:

.. prompt:: bash

   cd shell-lesson-data
