*****************
In-Class Review I
*****************

This is a review of some of the concepts we covered up to this point in the semester.

.. important::

   This set of examples is not exhaustive, so you
   should go back and read through the notes and run the example codes.


Bash shell
==========

#. You log into a computer--how do you find out what directory you
   are currently in?

   .. dropdown:: solution

      .. prompt:: bash

         pwd

      The ``pwd`` command stands for *print working directory*.


#. How can you return to your home directory from anywhere on the
   filesystem?

   .. dropdown:: solution

      You can simply do:

      .. prompt:: bash

         cd

      ``cd`` with out any arguments always brings you home.

      You could also do:

      .. prompt:: bash

         cd ~

      or give ``cd`` the full / absolute path to your home directory.

#. What is the full command that will transfer a file from your home
   directory on ``portal`` to your current directory on the desktop
   computer you are sitting at in the MathLab?

   .. dropdown:: solution

      We use ``scp`` (secure copy) for this:

      .. prompt:: bash

         scp username@portal.mathlab.stonybrook.edu:~/file .

      That will transfer a file called ``file`` in your home directory
      (``~/``) on ``portal`` to the current directory (``.``) on your
      local machine.  You would substitute your NetID for ``username``.

#. Here's an example filesystem on a computer you are using:

   ::

     /
     ├── etc
     ├── home
     │   ├── common
     │   ├── system-admin
     │   ├── teacher
     │   └── user
     │       └── files
     │           ├── report1.txt
     │           ├── report2.txt
     │           └── report3.txt
     └── opt

   Your home directory is ``user``

   a. What is the full (absolute) path to the file ``report1.txt``?

      .. dropdown:: solution

         .. code:: bash

            /home/user/files/report1.txt

         Remember: absolute paths begin at the root of the filesystem (``/``).

   b. If you are in the ``files/`` directory, how do you copy all of
      the files there to the ``common/`` directory?  Give a single
      command for this.

      .. dropdown:: solution

         We would use the copy command, ``cp``.  There are several variations of how
         we could specify the source files and the destination.  You could do:

         .. prompt:: bash

            cp report1.txt report2.txt report3.txt /home/common

         With ``cp``, the last argument on the command line is always the destination.
         Here we explicitly write out the 3 files we wish to copy.

         We could also use wildcards, like:

         .. prompt:: bash

            cp *.txt /home/common

         In this case, ``*.txt`` will match any file in our directory that ends in ``.txt``.

   c. Using wildcards, what is a single expression that matches all of
      the files under ``files/``?

      .. dropdown:: solution

         In addition to ``*.txt`` that we used above, we could do any of these:

         * ``*`` : this matches every file in the directory.  In this
           case, this is okay, since we want all the files.  But
           usually that is not the case.

         * ``report*.txt`` : this will match any file that starts with
           ``report`` and has the ``.txt`` extension.

         * ``report?.txt`` : this will match any file that starts with
           report, then has a single character (can be a letter or a
           number) and then ends in ``.txt``.

   d. You want to delete the directory ``files/`` and everything in
      it.  How do you do this?

      .. dropdown:: solution

         Starting in your home directory, you can do:

         .. prompt:: bash

            rm -f files

         This will recursively delete the directory, by first deleting all the files
         in it, and then removing the directory.  This can be dangerous if you did
         not setup the ``alias`` for ``rm`` to always be ``rm -i`` (prompt you before deleting).

         Another way would be:

         .. prompt:: bash

            cd files
            rm *.txt
            cd ..
            rmdir files

         This first changes directory into ``files``, then (using a
         wildcard) removes all the files, then changes directory back
         up a level (``..``) and then uses ``rmdir``, which only works
         on an empty directory.

#. You have a file on a group server (``directory.txt``)--how do you
   make sure that anyone on the machine can read it, but only you can
   write to it?

   .. dropdown:: solution

      You can do this in a few ways.  One way is:

      .. prompt:: bash

         chmod a+r directory.txt
         chmod a-w directory.txt
         chmod u+w directory.txt

      The first two lines set the permissions for everyone (user, group, and other), while the last
      line restores write permissions for the user.


#. What do you expect the output of the following command sequence to mean?

   .. prompt:: bash

      grep -i yellow database.txt | wc -l

   .. dropdown:: solution

      This will return the number of lines in ``database.txt`` that contain the word ``yellow``,
      without worrying about case.

#. Suppose you wanted to see the last 10 commands you entered at the Bash
   prompt--what command sequence could do this?

   .. dropdown:: solution

      You could do:

      .. prompt:: bash

         history 10

      or if you didn't realize ``history`` could take a number (like me!), you could do:

      .. prompt:: bash

         history | tail -10

#. You have an executable in your current directory called ``hello``.  If you
   just do:

   .. prompt:: bash

      hello

   you get an error ("command not found").  How do you run this.

   .. dropdown:: solution

      You need to give the path to the executable.  A relative path works, so you
      can just do

      .. prompt:: bash

         ./hello

      Here, the ``./`` means "in this directory.

#. What command do I use to search for all instances of a particular
   word in a file?

   .. dropdown:: solution

      We use ``grep``.

C++ basics
==========

#. Suppose I wanted to store the number ``0.3`` with the most precision
   possible--what C++ data type would I use?

   .. dropdown:: solution

      Since this number has a decimal point, we need a floating point
      type.  We know ``float`` and ``double``, but ``double`` has more
      precision (it is double precision, or 64-bit floating point).

#. How can I compute $\sqrt{5.0}$?  Is there a particular header file
   I would need to include?

   .. dropdown:: solution

      We could do:

      .. code:: c++

         std::sqrt(5.0);

      We could also do:

      .. code:: c++

         std::pow(5.0, 0.5);

      In either case, we need to include the ``cmath`` header.

#. How do I compile a program called ``power.cpp`` to make an executable
   named ``power``?

   .. dropdown:: solution

      We do:

      .. prompt:: bash

         g++ -o power power.cpp

#. When I write ``std::cout``, what is the meaning of the ``::``?

   .. dropdown:: solution

      This is the *scope operator*. It means "look inside ``std`` to find ``cout``".
      We call ``std`` the *namespace*.

#. Consider this code:

   .. code:: c++

      double x{1.5};
      double y = 2.0 + x * 5.0;

   what is the value of ``y``?

   .. dropdown:: solution

      The thing to remember here is that multiplication, ``*``, has higher precedence than addition, ``+``.
      So this is  ``2.0 + (1.5 * 5.0)`` or ``9.5``.

#. Consider this code:

   .. code:: c++

      int x{2};
      int y = 2 * x * x / 3;

   what is the value of ``y``?

   .. dropdown:: solution

      All operators here have the same precedence, so we go left to right.  Just computing this
      we would get ``8/3``, but the result is an ``int``, so the decimal part is discarded, and we
      get ``2``.

#. Consider this code:

   .. code:: c++

      int x{2};
      int y = 2*-x;

   what is the value of ``y``?

   .. dropdown:: solution

      Here, the ``-`` is the *unary minus* or "negation operator".  It simply changes the sign of ``x``,
      and it has the highest precision here.  So this is equivalent to ``2 * (-2)``.

#. Every C++ program needs a function with what name?

   .. dropdown:: solution

      ``main``

#. Consider the following code:

   .. code:: c++

      double x{1/3};
      std::cout << 3 * x << std::endl;

   what value is output to the screen?

   .. dropdown:: solution

      The key here is that ``1/3`` is integer math, so this evaluates to ``0``, and as a result,
      ``0`` is output to the screen.

#. Consider the following code:

   .. code:: c++

      double x{1.0};
      double eps{1.e-30};

      bool y = (x + eps) != 1.0

   what value would you expect ``y`` to have?

   .. dropdown:: solution

      Compared to ``1.0``, the number ``1.e-30`` (or $10^{-30}$) is
      very small, and it is below the roundoff precision, so we would
      get ``1.0 + 1.e-30 = 1.0``.  (Remember that machine epsilon is ~
      ``1.e-16``).

      The ``!=`` relation operator is *not equals*, so this is effectively asking if 1.0 is not equal to 1.0,
      and the answer is ``false``, so ``y`` gets set to ``false`` or ``0``.
