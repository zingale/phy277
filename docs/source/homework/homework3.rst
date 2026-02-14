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
