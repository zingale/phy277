****************
Some Sample Data
****************




Setting up
==========

To help us understand some basic shell operations, we will all work
with a collection of files and directories.  Type the following
commands (we'll explain their meaning later) to get the files we
need

.. prompt:: bash

   curl https://swcarpentry.github.io/shell-novice/data/shell-lesson-data.zip --output shell-lesson-data.zip
   unzip shell-lesson-data.zip

This data set comes from the Software Carpentry project.

This creates a directory on the filesystem named ``shell-lesson-data/``.  To begin, we want to
"change directory" into that directory, using the ``cd`` command:

.. prompt:: bash

  cd shell-lesson-data

