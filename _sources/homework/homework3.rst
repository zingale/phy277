***********
Homework #3
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



1. *Roundoff I*: To get a sense of roundoff, write a program to
   compute ``0.3 / 0.1 - 3`` with ``double`` datatypes.  Output with
   enough precision to see if you get the expected result.

   .. dropdown:: solution

      .. literalinclude:: hw3_p1_roundoff.cpp
         :language: c++
         :caption: ``hw3_p1_roundoff.cpp``

   When run, this gives ``-4.44089e-16`` and not zero, demonstrating
   that there is roundoff error in this expression.

2. *Roundoff II*: Now let's see how to mitigate roundoff error.

   Consider the function:

   $$f(x) = \frac{1}{\sqrt{x^3 + 1} - 1}$$

   defined for $x > 0$.  When $x$ is small, roundoff error
   from the subtraction will dominate the answer.  We want
   to see if we can get a better result.

   By by multiplying and dividing $f(x)$ by
   $\sqrt{x^3 + 1} + 1$, you get an analytically
   equivalent expression without any subtractions.
   Call this new expression $g(x)$.

   *your task*: Write a program to evaluate $f(x)$ and $g(x)$ for the values of
   $x$: ``1.e-4``, ``1.e-5``, and ``1.e-6``.

   .. note::

      Don't just multiply $f(x)$ by $\sqrt{x^3 + 1} + 1$ in your code---you
      need to do this analytically and simplify to define $g(x)$.

   What do you observe?

   .. dropdown:: solution

      .. literalinclude:: hw3_p2_roundoff.cpp
         :language: c++
         :caption: ``hw3_p2_roundoff.cpp``

      when run, we get:

      ::

         0.0001 1.99982e+12 2e+12
         1e-05 2.2518e+15 2e+15
         1e-06 inf 2e+18

      Notice that for the smallest value of ``x``, we get an ``inf``
      from the original expression.  This is because we are doing
      ``std::pow(1.e-6, 3.0) + 1.0`` which is the same as
      ``1.e-18 + 1.0``, which because of roundfoff is ``1.0``,
      so the denominator cancels!.


3. *Trig functions:* Consider $\sin(x)$.  The Taylor expansion of $\sin(x)$ is:

   $$\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} + \ldots$$

   Let's consider the `small-angle approximation <https://en.wikipedia.org/wiki/Small-angle_approximation>`_:

   $$\sin(x) \approx x$$

   where $x$ is measured in radians.

   We want to see how good this approximation is for different values of $x$

   *Your task*: write a program that computes $\sin(x)$ and the error,
   $\epsilon \equiv|\sin(x) - x|$, for $x = 5^\circ, 10^\circ, 20^\circ, \mbox{and}\ 40^\circ$.

   .. note::

      You'll need to convert these angles to radians in your code using
      the value of $\pi$ that C++ provides.

   Have your program output, for each angle, a line with
   the angle in degrees, the angle in radians, the sine of the angle,
   and the error in the small-angle approximation (4 columns).

   .. dropdown:: solution

      .. literalinclude:: hw3_p3_sine.cpp
         :language: c++
         :caption: ``hw3_p3_sine.cpp``

      when run, we get:

      ::

         5 0.0872665 0.0871557 0.00011072
         10 0.174533 0.173648 0.000884748
         20 0.349066 0.34202 0.00704571
         40 0.698132 0.642788 0.0553441

      We see that the error is less than 1% even for 20 degrees.

4. *Overflow*: A ``short int`` uses only 2 bytes of memory instead of
   4 bytes for a normal ``int``.  This means that there are only $2^{16}$
   of $32,768$ possible values.  We want to see overflow in action.

   *Your task*: write a program that does the following:

   * Initialize a ``short int`` to the largest possible value,
     following the ideas we saw in class in the :ref:`sec:reporting_limits`
     discussion.

   * Use the postfix operator (see :ref:`sec:prefix_and_postfix`) to
     increment the value of your variable.

   * Output the updated value to the screen.

   .. dropdown:: solution

      .. literalinclude:: hw3_p4_overflow.cpp
         :language: c++
         :caption: ``hw3_p2_roundoff.cpp``

      when run, we get:

      ::

         x is now: -32768

      Because a ``short int`` is signed, when we overflow by exceeding
      the maximum integer it can represent we can the smallest (most
      negative) integer.

