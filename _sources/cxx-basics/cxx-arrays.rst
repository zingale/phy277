******
Arrays
******

.. admonition:: reading

   `std::array at cppreference.com <https://en.cppreference.com/w/cpp/container/array>`_

Arrays have many similarities to vectors.  In particular, both arrays and vectors
store the data contiguously in memory.  This means you get good cache performance
when looping over elements.

But there are some key differences:

* Vectors can grow in size as needed to accommodate additional data.
  In contrast, arrays are fixed-size.

* Arrays also are allocated in a different part of memory by default
  (the stack rather than the heap---more on this later).

* Arrays do not initialize their elements by default when declared.


Here's a simple example:

.. literalinclude:: ../../../examples/arrays/simple_array.cpp
   :language: c++
   :caption: ``simple_array.cpp``

Declaring the array takes 2 arguments in the ``<>``---the datatype and the number of elements.

Notice that when we look over the elements, they are uninitialized.

We can use an initializer list to give initial values, like:

.. code:: c++

   std::array<int, 10> int_arr{0};

If you don't give all the values, the remainder are initialized to 0:

.. admonition:: try it...

   What are the values from this:

   .. code:: c++

      std::array<int, 10> int_arr{1, 2};

We can use the same set of algorithms we saw with vectors on arrays, like ``sort``, ``find``, etc.


.. caution::

   In C and older C++, you will see fixed-side arrays declared as:

   .. code:: c++

      double x[10];
      int p[10][20];

   The ``std::array`` is a more modern wrapper for these---it has the
   advantage that it knows the size of the array.


