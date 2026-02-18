********
Review I
********

This is a review of some of the concepts we covered up to this point in the semester.

.. important::

   This set of examples is not exhaustive, so you
   should go back and read through the notes and run the example codes.


Bash shell
==========

#. You log into a computer--how do you find out what directory you
   are currently in?


#. How can you return to your home directory from anywhere on the
   filesystem?


#. What is the full command that will transfer a file from your home
   directory on ``portal`` to your current directory on the desktop
   computer you are sitting at in the MathLab?


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

   b. If you are in the ``files/`` directory, how do you copy all of
      the files there to the ``common/`` directory?  Give a single
      command for this.

   c. Using wildcards, what is a single expression that matches all of
      the files under ``files/``?

   d. You want to delete the directory ``files/`` and everything in
      it.  How do you do this?

#. You have a file on a group server (``directory.txt``)--how do you
   make sure that anyone on the machine can read it, but only you can
   write to it?

#. What do you expect the output of the following command sequence to mean?

   .. prompt:: bash

      grep -i yellow database.txt | wc -l

#. Suppose you wanted to see the last 10 commands you entered at the Bash
   prompt--what command sequence could do this?

#. You have an executable in your current directory called ``hello``.  If you
   just do:

   .. prompt:: bash

      hello

   you get an error ("command not found").  How do you run this.

#. What command do I use to search for all instances of a particular
   word in a file?


C++ Basics
==========

#. Suppose I wanted to store the number ``0.3`` with the most precision
   possible--what C++ data type would I use?

#. How can I compute $\sqrt{5.0}$?  Is there a particular header file
   I would need to include?

#. How do I compile a program called ``power.cpp`` to make an executable
   named ``power``?

#. When I write ``std::cout``, what is the meaning of the ``::``?

#. Consider this code:

   .. code:: c++

      double x{1.5};
      double y = 2.0 + x * 5.0;

   what is the value of ``y``?

#. Consider this code:

   .. code:: c++

      int x{2};
      int y = 2 * x * x / 3;

   what is the value of ``y``?

#. Consider this code:

   .. code:: c++

      int x{2};
      int y = 2*-x;

   what is the value of ``y``?

#. Every C++ problem needs a function with what name?

#. Consider the following code:

   .. code:: c++

      double x{1/3};
      std::cout << 3 * x << std::endl;

   what value is output to the screen?

