*********
Midterm 1
*********

Bash shell
==========


1. Consider the following directory structure on a computer:

   .. figure:: dirtree.png
      :align: center
      :scale: 80%

   where the ``/`` at the top of the tree is the root directory,
   ``bin/``, ``home/``, and ``opt/`` are subdirectories beneath ``/``,
   and so forth.

   Your username on this machine is ``student`` and the location of
   your home directory is marked.

   a. Give the full (absolute) path to the file ``analysis.txt``.

      .. admonition:: solution

         ``/home/student/data/draft/analysis.txt``

         Recall that absolute paths always begin with the root of the
         filesystem, ``/``.

   b. If you are in the directory ``final/``, give the *relative path*
      from there to the file ``analysis.txt``.

      .. admonition:: solution

         From ``final/``, we need to go up and directory and then down
         into ``draft``, so the relative path is ``../draft/analysis.txt``.

   c. If you are in the ``other/`` directory, give a way to change
      directory to your home directory.

      .. admonition:: solution

         Any of ``cd``, ``cd ..``, or ``cd ~`` would work.

   d. If you are unsure of where you are in the filesystem, what
      command can tell you your location?

      .. admonition:: solution

         You would use ``pwd``.

2. You are in your home directory on ``portal``.  Give the sequence of commands
   to (1) create a directory called ``tests/``, (2) change directory into ``tests``, and (3)
   open a file there with the text editor called ``README``.

   .. admonition:: solution

      .. prompt:: bash

         mkdir tests
         cd tests
         nano README

      You could use ``emacs`` instead of ``nano``--those are the 2 editors we've focused on.

3. ``ls`` in your directory and see the following files:

   ::

      report-A1.pdf  report-A1.txt  report-A2.pdf  report-A2.txt  report-A3.pdf  report-A3.txt
      report-B1.pdf  report-B1.txt  report-B2.pdf  report-B2.txt  report-B3.pdf  report-B3.txt
      report-C1.pdf  report-C1.txt  report-C2.pdf  report-C2.txt  report-C3.pdf  report-C3.txt

   a. Using wildcards, how do you select all the PDF files?

      .. admonition:: solution

         You could just do ``*.pdf`` or if you wanted to be more specific, ``report-*.pdf``.

   b. Using wildcards, how do you select all of the files that have an ``A`` in them?

      .. admonition:: solution

         There are several ways, including ``*A?.*`` and  ``report-A?.*``.

4. You created a file called ``topics.txt``.  An ``ls`` shows the
   following for your file:

   ::

     -rw-------. 1 user user       71 Feb 23  2026  topics.txt

   You are using a machine in your research group, and there is a
   directory on that machine called ``/home/common/`` that anyone on
   the machine can access.

   Give the commands to (1) *move* ``topics.txt`` into ``/home/common``, and (2)
   to allow *anyone* on the computer to be able to read-from and write-to the file.

   .. admonition:: solution

      To move the file:

      .. prompt:: bash

         mv topics.txt /home/common

      Then (assuming you are in ``/home/common``), to update the permissions,
      you could do:

      .. prompt:: bash

         chmod a+rw topics.txt

      or do it in two steps:

      .. prompt:: bash

         chmod a+r topics.txt
         chmod a+w topics.txt

      You could also use the numeric variation.

5. On the ``portal`` server, in a directory named ``files/`` under
   your home directory, you have a file called ``myscript.sh``.  Give
   the ``scp`` command that will copy that file from ``portal`` to
   your current directory on your computer (e.g., one of the desktops
   in the MathLab).

   .. admonition:: solution

      You want to pull the file from ``portal`` to your local machine,
      so you would do:

      .. prompt:: bash

         scp username@portal.mathlab.stonybrook.edu:~/files/myscript.sh .

      You could also write out the directory, as
      ``/home/username/files/myscript.sh`` instead of using ``~``.

6. You created a script called ``process.sh`` and already set it
   up with the permissions to be executable.  When run (it takes no
   arguments), it outputs a lot to the screen, so you want to redirect
   its output to a file named ``output.txt``.

   What is the full command to run the script and store the output in
   ``output.txt``?

   .. admonition:: solution

      .. prompt:: bash

         ./process.sh > output.txt


C++ basics
==========

7. In class, we've looked at a basic "Hello, World!" program a
   number of times.  Write a C++ program that outputs "Hello,
   World".

   .. admonition:: solution

      .. code:: c++

         #include <iostream>

         int main() {
             std::cout << "Hello, World" << std::endl;
         }

8. To compile a file named ``hello.cpp`` to produce an executable ``hello``, what
   is the full command that you use?

   .. admonition:: solution

      .. prompt:: bash

         g++ -o hello hello.cpp

9. Consider the following two lines:

   ::

      int a{-1.5};
      int b = 2 * a + 1;

   What is the value held by ``b`` after these lines are run?

   .. admonition:: solution

       ``-1.5`` cannot be represented as an ``int``, so it is
       converted by truncation, resulting in ``-1``, and then ``2 *
       (-1) + 1`` give ``-1``.

10. Consider the following two lines:

    ::

      double x{2.0};
      double y = x + 4 * x / 2;

    What is the value held by ``y`` after these lines are run?

    .. admonition:: solution

       Multiplication and division have highest precedence, so this
       is ``2.0 + (4 * 2.0 / 2)`` or ``6.0``.

11. You want to write a C++ program that computes $x^{3/2}$ using
    *double-precision floating point* and ``std::pow()``.  Recall that
    ``std::pow(x, y)`` means $x^y$.  Give the 2 lines of C++ code that
    (1) initialize ``x`` to a value of ``10``, and (2) compute
    $x^{3/2}$, assigning the value to a new variable ``y``.

    .. admonition:: solution

       .. code:: c++

          double x{10.0};
          double y = std::pow(x, 3.0/2.0);

       Note that for the power, we need to use floating point, and not ``3/2``.

12. The C++ math library includes a function ``cos(x)`` that will
    take the cosine of the input $x$.  You want to use this in your
    code.  Assume you have access to the value of $\pi$ as the variable
    ``pi``.

    a. What header do you need to ``#include``?

       .. admonition:: solution

          ``cmath``

    b. What is line(s) of code needed to take the cosine of $45^\circ$ and store the result
       in a variable called ``s``?  Use a datatype that gives the most precision.

       .. admonition:: solution

          The key to remember is that the trig functions want the angle in radians.  So we
          can do:

          .. code:: c++

             double s = std::cos(45.0 * pi / 180);
