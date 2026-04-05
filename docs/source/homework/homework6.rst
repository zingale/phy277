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

   Let's understand different ways that functions can return
   information.  We want to write a function that accepts
   a ``double`` and simply squares it.

   * Our first version, called ``square1`` should accept
     our ``double`` and return a new double via a ``return``
     statement.  So we would call it as:

     .. code:: c++

        double x{2.0};
        double xsq = square1(x);

     Note that ``x`` is unchanged here.

   * Our second version, called ``square2``, will update the data
     passed in as an argument, with no return value.  So we would call
     it as:

     .. code:: c++

        double x{2.0};
        square2(x);

     Note that ``x`` is changed here, and is now $x^2$ after
     calling the function.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. literalinclude:: hw6_p1_square.cpp
         :language: c++
         :caption: ``square.cpp``

2. *Function practice II* :

   In :ref:`sec:homework4`, we found the maximum element of a
   vector.  Let's rewrite that now.  We'll do two slightly
   different concepts.

   * Create a function of the form:

     .. code:: c++

        double max_element(const std::vector<double>& vec)

     That takes a vector, ``vec``, and returns the maximum value
     in the vector.

     .. tip::

        We are taking the vector here as a ``const`` reference.  This
        avoids a potentially expensive copy (so it performs better), but
        still prevents us from modifying the contents of the vector.

   * Now, let's instead write a function that returns the index
     into the vector that contains the maximum element.  This
     function should be:

     .. code:: c++

        int max_index(const std::vector<double>& vec)

     which returns the index into ``vec`` that represents the
     maximum element.  E.g.,

     .. code:: c++

        int idx = max_index(vec);

     would tell us that the maximum element in ``vec`` is ``vec[idx]``.

     .. tip::

        Instead of using a ranged-for loop over the vector, you should
        loop using and integer representing the index, like:

        .. code:: c++

           for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
                // do stuff
           }

        and then you can access the current element of the vector as
        ``vec[i]`` inside the loop.  You will also need to keep track
        of which index has the maximum element as you go through the
        loop---you will need to figure out that logic on your own.

   Test both of your functions using the same vector as used in
   Homework 4.  You can also (optionally) test this by doing:

   .. code:: c++

      double max_val = max_element(vec);
      int idx = max_index(vec);

      if (vec[idx] == max_val) {
         std::cout << "our functions agree" << std::endl;
      }

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. literalinclude:: hw6_p2_max.cpp
         :language: c++
         :caption: ``max_function.cpp``


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

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. literalinclude:: hw6_p3_diff.cpp
         :language: c++
         :caption: ``difference.cpp``

      When run, this gives:

      ::

          0.1000  0.53940 9.00054e-04
          0.0500  0.54008 2.25098e-04
          0.0250  0.54025 5.62797e-05
          0.0125  0.54029 1.40703e-05

      and we see that halving $\Delta x$ drops the error by a factor
      of 4, as expected.
