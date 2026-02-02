*********************
Redirection and Pipes
*********************

.. admonition:: reading

   We will loosely follow the Software Carpentry `Pipes and Filters
   <https://swcarpentry.github.io/shell-novice/04-pipefilter.html>`_
   lesson from `The Unix Shell
   <https://swcarpentry.github.io/shell-novice/>`_


The real power of Unix is combining basic commands that do one thing well
together with other commands to build a powerful pipeline.

Let's start in our ``~/shell-lesson-data/exercise-data/alkanes`` directory.

Counting lines and words
========================

The ``wc`` command will give the number of lines, words, and characters in a file.
For example:

.. prompt:: bash

   wc cubane.pdb

gives:

.. code:: bash

   20  156 1158 cubane.pdb

So we see that it has 20 lines.  We can also give it all the files, e.g.,

.. prompt:: bash

   wc *.pdb

.. tip::

   Use ``man wc`` to remind yourself what the output means and what options
   ``wc`` takes.  For example, ``wc -l`` will give just the number of lines.


Redirection
===========

Suppose we want to capture the output of the number of lines in all the files.
We could copy and paste it into ``nano``, but we can instead *redirect* the output
to a file using the ``>`` operator:

.. prompt:: bash

   wc -l *.pdb > lines.txt

We can then use ``cat lines.txt`` to see the output.

.. tip::

   For very long files, ``cat`` will overfill the screen (and maybe the buffer
   for the terminal).  In this case, we can use the ``less`` command, which
   implements a ``pager``


Summary
=======

We learned the following commands:

* ``wc`` : count the number of lines, words, and characters in a file

* ``cat`` : print the contents of a file to the terminal

* ``less`` : a *pager* that outputs the contents of a file one screen-full at a time

* ``sort`` : sort the input data

* ``head`` : output the first 10 (or specified number of) lines of a file

* ``tail`` : output the last 10 (or specified number of) lines of a file

We also learned:

* ``>`` redirect the output to a file

* ``>>`` append the output to a file

* ``|`` pass the output of one command to the input of the next


