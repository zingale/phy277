***********
Homework #3
***********

.. admonition:: Completing this assignment

   For the each of the problems below, write a separate C++ program
   named in the problem :samp:`problem{N}.cpp`, where :samp:`{N}` is the
   problem number.

   **Make sure your code compiles with ``g++``**.

   Upload your C++ source files (*not the executables produced by
   ``g++``) to Brightspace.

.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.



1. Write a program to compute 0.3 / 0.1 - 3, once with ``float``
   datatypes and a second time with ``double`` datatypes.  Output with
   enough precision to see if you get the expected result.


2. Consider the `quadratic equation <https://en.wikipedia.org/wiki/Quadratic_equation>`_:
   $x^2 + b x + c = 0$.  The two solutions can be expressed using the standard
   result we learned in algebra:

   $$x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$

   or alternately using Muller's method:

   $$x = \frac{2c}{-b \mp \sqrt{b^2 - 4ac}}$$

   These are analytically equivalent (for non-zero $a$ and $c$), but
   they will have different roundoff error properties.

   Let's take:

   * $a = 0.001$
   * $b = 1000$
   * $c = 0.001$

   *Your task:*

   Write a program that does the following:

   * Compute the 2 roots using the first expression (the standard
     method) using ``float`` data types, and output them to the screen.

   * Compute the 2 roots again, now using the alternate expression
     (Muller's method), again using ``float``, and output them to the
     screen.

   * Finally, to assess which is the most accurate when roundoff is involved,
     compute the 2 roots using the first expression again, but now using
     ``double`` data types, and output them to the screen.

   What do you observe?

3. Integrer overflow: short type -- print out maximum value
   initialize an int to the maximum value and add 1
   print out result
