***********
Homework #4
***********

.. admonition:: Completing this assignment

   For the each of the problems below, write a separate C++ program
   named in the problem :samp:`problem{N}.cpp`, where :samp:`{N}` is the
   problem number.

   .. important::

      Make sure your that ``g++`` can compile your code.  For some of
      the problems here, you will need to use ``-std=c++20``.

   Upload your C++ source files (*not the executables produced by
   g++*) to Brightspace.



.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.


1. In our vector example, :ref:`sec:vec-averaging`, we computed the
   average of a vector of data.

   Starting with this example, extend the code to compute the
   standard deviation of the vector, defined as:

   $$\sigma = \sqrt{ \frac{1}{N} \sum_{i=1}^N (x_i - \mu)^2 }$$

   where $\mu$ is the average.

   Have your code output the average and standard deviation.

2. Consider a ``struct`` that defines a point in the 2D plane:

   .. code:: c++

      struct Point {
          double x;
          double y;
      };

   You want to compute the distance from the origin for a collection
   of ``Point`` objects.  For this problem, we will work with the
   following points $(x, y)$:

   $$(1.5, 2.3), (3.2, 1.6), (5.3, 0.1), (8.6, 2.5)$$

   Your task:

   * Create a ``std::vector`` that holds ``Point`` data and initialize
     it with the data given above.

   * Loop over the points in your vector and compute the distance from the
     origin, $d = \sqrt{x^2 + y^2}$, for each point

   * Within the loop body, output the distance to the screen using ``std::format``
     to give a line for each point of the form:

     ::

        Point ( 1.50, -2.30) is  2.746 from the origin.

3. Let's find the maximum element in a vector.  The ``algorithm``
   library provides ``std::max(a, b)`` which will return
   whichever of ``a`` or ``b`` is the largest.

   Starting with the vector:

   .. code:: c++

      std::vector<double> vec{-100.3, 5.64, -25.3, 10.9, 50.3, -2.4, 13.9};

   With a program that uses a ranged-for loop (what we've been using
   in class) and ``std::max`` to find the maximum value in the vector.

   .. tip::

      You'll want to start with the maximum value initialized to
      a very small value so the first element you check in the vector
      will become the maximum.  Using ``std::numeric_limits`` can
      help here.

   .. note::

      You should add:

      .. code:: c++

         #include <algorithm>

      to your code to get access to ``std::max``.
