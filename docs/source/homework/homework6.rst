***********
Homework #6
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


1. *Function practice I* :

2. *Function practice II* :

3. *Centered difference* :

   At the end of our discussion on derivatives, we saw the
   :ref:`sec:centered-diff`.  Let's code this up and explore the
   error.

   We'll call this discrete approximation to the derivative $D^c(x)$,
   so:

   $$D^c(x) = \frac{f(x + \Delta x) - f(x - \Delta x)}{2\Delta x}$$

   Consider the derivative of $f(x) = \sin(x)$ at $x=1$.

   Compute the centered difference approximation for $\Delta x = 0.1$,
   $0.05$, $0.025$, and $0.0125$, and make a table giving $\Delta x$,
   $D^c(x)$, and the error compared to the analytic solution, :math:`e
   \equiv |f^\prime(x) - D^c(x)|`.

   Your implementation should:

   * Use C++ functions for $f(x)$ and $f^\prime(x)$

   * Use a C++ function for $D^c(x)$ that takes a function as an argument ($f(x)$), using the
     ``std::function<>`` method we discussed in :ref:`sec:funcs-as-args`.

   * Use ``std::format()`` to make the columns line up for the output
     done with each $\Delta x$.

   .. tip::

      You should see the error drop by a factor of 4 each time $\Delta
      x$ is cut in half.

