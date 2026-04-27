*******************
Python Introduction
*******************


Hello, World
============

Let's start by a simple "Hello, World" program.
Put the following into a file ``hello.py``:

.. code:: python

   print("Hello, World")

and then we can run it as:

.. prompt:: bash

   python hello.py

This invokes the *python interpreter*, ``python``, which runs the code in our file.
We can already see some similarities with C++:

* ``print()`` is a function that takes arguments

* ``"Hello, World"`` is a string.


Comparing python and C++
===================================

Python and C++ have a number of similarities but also important
differences that we will encounter when we apply our C++ knowledge to
writing python programs.

Similarities
------------

* Both are object-oriented languages, and use the ``.`` operator as
  the member-access operator.  We will write classes and work with objects
  in the same way.

* Both have a robust standard library that provides many of the same
  features.  For example. the python equivalent of ``std::vector`` is
  a list.

* The C++ ``std::format`` library was inspired by python, and the same
  formatting syntax works.

* Floating point math works the same way---both languages follow the
  same IEEE standard and have single- and double-precision math.


Differences
-----------

.. list-table::
   :header-rows: 1
   :width: 85%

   * - python
     - C++

   * - python is an `interpreted language <https://en.wikipedia.org/wiki/Interpreter_(computing)>`_

       We run a python program by doing ``python program.py``

     - C++ requires using the compiler (e.g. ``g++``) to translate the source
       into machine-specific instructions

   * - python is dynamically typed---we don't need to specify ahead of time
       what type of data a variable/object refers to

       .. code:: python

          # a floating point number
          x = 2.5

          # an integer
          a = 1

     - all objects in C++ must have their datatypes specified ahead of time

       .. code:: C++

          double x{2.5};
          int a{1};

   * - python statements typically end at the newline

     - C++ uses a semicolon, ``;``, to terminate a statement

   * - python uses whitespace to denote code blocks for ``if``, ``for``, functions, etc.

       .. code:: python

          if x > 0:
               print("x is positive")

     - C++ uses curly braces, ``{ }``

       .. code:: C++

          if (x > 0) {
              std::cout << x << std::endl;
          }

   * - integers behave differently in python, in 2 important ways

       * integer division results in a float, i.e. ``1 / 2`` is ``0.5``
         in python

       * The size of an int (in bytes) expands as needed, so there is
         no overflow, i.e., we can store ``a = 123456789012345678901234567890``

     - in C++, integer division results in an integer, so ``1 / 2`` is ``0``.

   * - python can be slow.  Scientific libraries (like NumPy) and
       avoiding loops can help.

     - C++ is generally fast if you use modern language features and
       compiler optimization.

   * - python scope works differently than C++.  For example:

       .. code:: python

          x = 10
          if x > 0:
              y = x + 1

          # we can access y here

     - in the C++ version:

       .. code:: C++

          int x{10};
          if (x > 0) {
              int y = x + 1;
          }

          // we cannot access y here

   * - python doesn't have references and pointers.  However, the standard
       python interpreter is written in C, so those concepts still exist
       behind the scenes.

       An important way this comes up is in passing objects to functions.
       In python, we can think of objects as passed by reference, not value (see `python data structures <https://en.wikipedia.org/wiki/Python_syntax_and_semantics#Data_structures>`_).

     - In C++, when we pass objects to a function, they are passed by
       value, unless we make the function argument a reference (add
       the ``&``).


