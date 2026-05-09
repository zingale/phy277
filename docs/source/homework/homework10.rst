************
Homework #10
************

.. important::

   The file submission requirements are different than previous homeworks.

   For the C++ problems below, you need to submit a header file (``.H``) implementing
   the class described in the problem and a source file (``.cpp``) containing
   the ``main()`` function and any tests that the problem asks for.

   For the python problems below, you need to submit a python source file (``.py``).

.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.


1. *Multi-dimensional array extensions* : Start with our
   :ref:`sec:contiguous-array-here` implementation from class.  Add the
   following member functions:

   * ``.sum()`` : returns the sum of all the elements in the array.

   * ``.max()`` : returns the maximum value in the array.

   * ``.min()`` : returns the minimum value in the array.

   Write a test driver, and create an array representing the  following 5 by 4 matrix:

   .. math::

      \left ( \begin{array}{ccccc}
          -20.0 & 4.5 & 1.45 & 7.9 \\
          -1.2 & -10.4 & 8.9 & 6.49 \\
          12.7 & 14.4 & 6.5 & -10.9 \\
          -2.4 & 2.15 & 1.15 & 20.4 \\
          -22.5 & 64.5 & -1.8 & -7.1
      \end{array} \right )

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      First the updated header:

      .. literalinclude:: array.H
         :language: c++
         :caption: ``array.H``

      Here I chose to use the ranges and iterator algorithms, but you
      could have also written the loop (or loops) out explicitly.

      Now the driver.

      .. literalinclude:: hw10_p1_test_array.cpp
         :language: c++
         :caption: ``test_array.cpp``

      There are a few ways to initialize the array.  Here I create
      a vector (and just use newlines to make it look 2D) and then
      copy in.  You could also just manually write out

      .. code:: c++

         a(0, 0) = -20;
         a(0, 1) = 4.5;
         ...

      .. tip::

         An alternate way to do the initialization, is to create
         another constructor that takes a `std::initializer_list <https://en.cppreference.com/cpp/utility/initializer_list>`_ and then
         copy from that.

         The constructor would look like:

         .. code:: c++

            Array(std::initializer_list<std::initializer_list<double>> values)
                : _rows(values.size()),
                  _cols(values.begin()->size()),
                  _data()
            {
                assert(_rows > 0);
                for (const auto& row : values) {
                    // Ensure all rows have the same number of columns
                    assert(static_cast<int>(row.size()) == _cols);
                    _data.insert(_data.end(), row.begin(), row.end());
                }
            }

         and the initialization would look like:

         .. code:: c++

            Array a{{-20.0, 4.5, 1.45, 7.9},
                    {-1.2, -10.4, 8.9, 6.49},
                    {12.7, 14.4, 6.5, -10.9},
                    {-2.4, 2.15, 1.15, 20.4},
                    {-22.5, 64.5, -1.8, -7.1}};

          However, this is beyond what we covered in class.


2. In :ref:`sec:function-practice`, we wrote a function ``is_prime()``
   took an ``int`` and returned a ``bool`` indicating whether the
   number was prime.  Here's the code we produced:

   .. literalinclude:: ../../../examples/functions/primes.cpp
      :language: c++
      :caption: ``primes.cpp``


   Rewrite this example in python---your solution should include a
   python function named ``is_prime``.

3. In class, we write a python version of :ref:`sec:python-trapezoid`.
   Modify this to implement Simpson's rule for integration (see our C++
   version at :ref:`sec:simpsons-rule`).

4. Write a *python* program that:

   * creates an empty list, ``angles``

   * using a loop, adds the numbers $n \pi / 8$ for $n = 0, 1, \ldots 8$
     to ``angles``

   * creates a new list ``sines``, and using a second loop,
     adds the sine of each angle in ``angles`` to our new list ``sines``.

   * finally, outputs the results as (angle, sine) pairs, one
     pair per line.
