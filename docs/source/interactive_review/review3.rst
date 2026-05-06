*****************
Final Exam Review
*****************

The final exam will cover the topics since the previous exam.

.. important::

   This set of examples is not exhaustive, so you should go back and
   read through the notes, run the example codes, and look at my
   homework solutions.


File I/O
========


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

Software Engineering
====================



Version Control
===============


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

Python
======

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

