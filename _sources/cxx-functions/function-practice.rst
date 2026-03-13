*****************
Function Practice
*****************

Here are some practice problems to help us understand functions.

#. Write a function called ``swap`` that takes two numbers ``a`` and ``b``
   and swaps their values.  There is no return value.

   .. dropdown:: solution

      .. literalinclude:: ../../../examples/functions/swap.cpp
         :language: c++
         :caption: ``swap.cpp``

      Here we write 2 different versions of ``swap()`` ---one that
      takes ``double`` and one that takes ``int``.  We can do this,
      even though the function name is the same, because C++ can tell
      them apart by the datatypes they take.  This is a concept called
      *function overloading*.

      The functions are ``void`` since they don't explicitly return
      anything.  Instead the values passed in as arguments are
      modified directly (hence, using references, ``&``, in the
      function declaration).

      .. tip::

         Swapping objects is a key part of a sorting algorithm, so
         C++ provides `std::swap <https://en.cppreference.com/w/cpp/utility/swap.html>`_.

#. Write a function ``sum`` that accepts a ``std::vector`` of numbers and
   returns the sum.

   .. dropdown:: solution

      .. literalinclude:: ../../../examples/functions/sum.cpp
         :language: c++
         :caption: ``sum.cpp``

       This is pretty straightforward, with one implementation note.
       We accept the vector argument ``vec`` as a ``const`` reference.
       This is to prevent C++ from making a potentially-expensive copy
       (since the default is pass-by-value).  By marking it ``const``
       we are ensuring that the function ``sum`` cannot modify the
       contents of ``vec``.

#. Functions can be called `recursively
   <https://en.wikipedia.org/wiki/Recursion_(computer_science)>`_
   (i.e. the function calls itself on a smaller problem).

   Let's use recursion to write a function that computes the factorial
   of an integer.

   .. dropdown:: solution

      .. literalinclude:: ../../../examples/functions/fac.cpp
         :language: c++
         :caption: ``fac.cpp``

      We use a ``long`` datatype here to help deal with integer
      overflow (we will still overflow for a moderate sized integer
      though, even with ``long``).

      We also add a check to ensure that the input integer, ``N``
      is positive.  Otherwise, we will create infinite recursion and
      the program will crash.  Later we'll see how we can handle this
      with an assertion.

#. Let's rewrite our :ref:`sec:prime_numbers` example to use a function
   called ``is_prime()`` that takes an ``int`` and returns a ``bool``
   indicated whether the input number is prime.

   .. dropdown:: solution

      .. literalinclude:: ../../../examples/functions/primes.cpp
         :language: c++
         :caption: ``primes.cpp``

      This rewrite shows how using functions can make the code easier to
      understand.  Now the loop in ``main`` is much more readable, because
      we can see it is just checking if the loop variable is prime, using
      the ``is_prime()`` function.  And we can understand ``is_prime()``
      on its own.  So by splitting things up, we it allows us to understand
      the code in logical pieces.

#. Let's rewrite our :ref:`sec:homework4` problem of creating a vector
   of ``Point`` and finding the distance from the origin to use a function
   that finds the distance for a single ``Point``.

   .. dropdown:: solution

      .. literalinclude:: ../../../examples/functions/points.cpp
         :language: c++
         :caption: ``points.cpp``

      This is a straightforward change to the code.  The main utility here
      is that we can now easily use our ``dist()`` function elsewhere in our
      code as needed. 

#. Write a function called ``linspace`` that takes a minimum and
   maximum coordinate, $x_\mathrm{min}$ and $x_\mathrm{max}$, and a
   number of points, $N$ and returns a vector with $N$ points equally
   spaced between $x_\mathrm{min}$ and $x_\mathrm{max}$ (with those
   endpoints included).

   E.g., ``linspace(0, 1, 11)`` would return ``{0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}``.

   .. dropdown:: solution

      .. literalinclude:: ../../../examples/functions/linspace.cpp
         :language: c++
         :caption: ``linspace.cpp``

      This is a good example of a function that returns a ``std::vector``.
