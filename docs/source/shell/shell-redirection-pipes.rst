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


Pipes
=====

The ``sort`` command will sort lines / output.  By default, it sorts alphabetically,
but we can change it to sort numerically using the ``-n`` option 

.. tip::

   Do

   .. prompt:: bash

      man sort

   to see all the available options.

To sort out ``lines.txt`` we can do:

.. prompt::

   sort -n lines.txt

But what if we didn't want to create the intermediate file ``lines.txt``, but instead sort
the output from ``wc -l`` directly?  This can be accomplished using a `pipe <https://en.wikipedia.org/wiki/Pipeline_(Unix)#Pipelines_in_command_line_interfaces>`_, ``|``.

By doing:

.. prompt:: bash

   wc -l *.pdb | sort -n

we are *piping* the output from ``wc`` into ``sort``, where it is taken as the input.
And we get the same result without having to create an intermediate file.

``head`` and ``tail``
=====================

The commands ``head`` and ``tail`` show just the beginning or end (respectively) of a
file (or piped input).  By default 10 lines are shown, but this can be controlled via
the ``-n`` flag.

For instance, to see the shortest file in our ``alkanes`` directory, we could do:

.. prompt:: bash

   wc -l *.pdb | sort -n | head -n 1

For the longest file, we need to get right of the last line, which represents the total.
There are several ways we can do this.

One way (and maybe a bit awkward) is to do:

.. prompt:: bash

   wc -l *.pdb | sort -n | tail -n 2 | head -n 1

Here we get the last 2 lines of the file, understanding that, out of those 2 lines, we want
the first line (as it is not the total).

Alternately, using ``man wc``, we can learn that adding the option
``--total=never`` suppresses the printing of the total, so we could
instead do:

.. prompt:: bash

   wc -l --total=never *.pdb | sort -n | tail -n 1

which gives:

.. code:: bash

   30 octane.pdb




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


