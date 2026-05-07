*****************
Final Exam Review
*****************

.. note::

   The final exam will cover the topics since the previous exam.

   Python will be part of the exam, however, there will not be
   questions on NumPy and matplotlib, since we did not have enough
   time to practice those.

.. important::

   This set of examples is not exhaustive, so you should go back and
   read through the notes, run the example codes, and look at my
   homework solutions.


File I/O
========

#. You create a file as:

   .. code:: c++

      std::ofstream of("file.txt");

   a. How do you output a string to it?

   b. If the file already exists, what happens to its existing
      contents when you open it this way?

   c. How would you change this line if you wanted to *read from*
      ``file.txt``?


Standard Library Algorithms
===========================

#. Given a ``std::vector<int> v{2, 5, 8, 5, 10};``, write one line using
   ``std::ranges::count`` to count how many times 5 appears.

#. What does ``v.end()`` point to? Why should an iterator loop usually stop at it
   ``< v.end()`` or it ``!= v.end()`` instead of including ``v.end()``?

#. Use ``std::ranges::find`` to search for 8 in a vector. What should you check
   before dereferencing the returned iterator?

#.  Write a lambda that returns true if an integer is odd. Then use it with
    ``std::ranges::count_if``.

#. For ``std::views::iota(3, 8)``, what values are produced?

#. Suppose an iterator ``pos`` points to the element 200 in a vector. What
   does ``v.insert(pos, 150)`` do?

#. In this example, we use a *lambda function*.  If we instead wanted
   to use a traditional function, how would we rewrite this (show both
   the new function and the updated ``sort`` call).

   .. code:: c++

      std::ranges::sort(titles,
                        [] (const std::string& a, const std::string& b)
                           {return a.size() < b.size();});


Software Engineering / Version Control
======================================

#. These lines are in a ``GNUmakefile``:

   .. code:: make

      planet_sort_split.o: planet_sort_split.cpp planet.H
           g++ -std=c++20 -c planet_sort_split.cpp

   a. In the first line, what does the name to the left of the ``:`` mean?
      and what are the files to the right of the ``:``?

   b. What does the ``-c`` do in the ``g++`` command?

#. If I compile a ``program.cpp`` as:

   .. prompt:: bash

      g++ -O3 -o program program.cpp

   what is the meaning of ``-O3``?

#. ``git status`` shows ``newton.cpp`` under ``Untracked files``---how
   do you put this file under git control?

#. What does it mean for a variable to be *shadowing* another variable in C++?

#. We have a header ``solver.H`` in our current directory.  This
   header provides a function ``newton`` in it.  We want to use this
   in our code.  How do we include this header so the compiler will
   find it.


Classes
=======

#. What is the main difference between a ``struct`` and a ``class`` in C++?

#. What is a constructor, and when is it called?  What name is given
   to the constructor function?

#. What is an initialization list? In the code below, what member data is initialized?

   .. code:: c++

      SolarSystem(double mass)
          : star_mass{mass}
      {}

#. Consider the following:

   .. code:: c++

      struct Circle {

          // member data
          double radius{};

          // constructor
          Circle(double r) {
              radius = r;
          }
      };

   a. How would you create a ``Circle`` with a radius of ``5``?

   b. Rewrite this to make the member data private
      and add a *getter* function that returns the radius.

      Show how you would call this function given a ``Circle`` object ``c``.

   c. How would you add another constructor that takes no arguments
      and sets the radius to ``1`` by default?

#. In our ``Vector2d`` class, we had 2 different operators for
   multiplying by a scalar:

   .. code::

      Vector2d operator*(double a) {
          return Vector2d(x * a, y * a);
      }

      friend Vector2d operator*(double a, const Vector2d& v);

   What is the difference between these?

#. Write a class ``Timer`` with private member data ``seconds`` and a member function
   ``add_time(double dt)``.

#. Currency exchange.

   a. Create a class called ``Currency`` that holds a ``double`` and a
      ``string``.  The ``double`` is the ``value`` and the ``string`` is the
      ``country`` of the currency (e.g., ``"US"``, ``"Euro"``, ...).  Give
      a constructor that takes both pieces of data.

   b. We want to be able to add two ``Currency`` objects.  The operator
      function will look like:

      .. code:: c++

         Currency operator+ (const Currency& other)

      Fill in the details---include a check that we are adding currencies from
      the same country.

Python
======

#. What is the python version of a C++ ``std::vector`` that we focused
   on in class?

#. Given the following:

   .. code:: python

      a = [1, 2, 4, 8, 16]

   write a loop (in python) that loops over the elements
   and prints them out.

#. Some times in class, I put an ``f`` in front of the ``"`` in a
   string---what does this mean?

#. How would I write this C++ if-test in python?

   .. code:: c++

      int sign;
      if (x == 0) {
          sign = 0;
      } else if (x > 0) {
          sign = 1;
      } else {
          sign = -1;
      }

#. What is the python equivalent of this C++ code

   .. code:: c++

      double x{2.5};
      double y{1.2};

      double z = std::pow(x, y);

#. What is the result of the following python code:

   .. code:: python

      def func(x, normalization=None):
          xi = x
          if normalization:
              xi = x / normalization

          return x**3 + x + 1

      func(2, normalization=2)

#. This was the first class we wrote in C++:

   .. code:: c++

      struct Circle {

          // member data
          double radius{};

          // constructor
          Circle(double r) {
              radius = r;
          }

          // member functions
          double circumference() {
              return 2.0 * std::numbers::pi * radius;
          }

          double area() {
              return std::numbers::pi * radius * radius;
          }

      };

    write a python version of it.


