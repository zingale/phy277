*************************
Datatype Sizes and Limits
*************************

Sizes
=====

When we declare an object in C++, the compiler will reserve memory to hold
the data.  The amount of memory needed depends on the datatype.

.. important::

   C++ guarantees a minimum size of the different types, but different
   compilers or processors may have different defaults.

We can explicitly determine this with a C++ program using
``sizeof()``---that returns the number of *bytes*

.. code:: c++

   std::cout << sizeof(double) << std::endl;

The following is guaranteed:

.. code:: c++

   sizeof(char) == 1 <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)

.. tip::

   If you want to guarantee a size for an ``int``, there are datatypes that explicitly
   require a fixed width, like ``int32_t``: https://en.cppreference.com/w/cpp/types/integer

Reporting limits
================

We can find out a lot about the range and precision of numbers that can be stored with a given type by using
`std::numeric_limits <https://en.cppreference.com/w/cpp/types/numeric_limits>`_:

.. literalinclude:: ../../../examples/limits/limits_test.cpp
   :language: c++
   :caption: ``limits_test.cpp``



Overflow and underflow
----------------------

What happens if we exceed the limits of a data type?
For floating point, we don't abruptly transition to ``0.`` (for underflow)
but instead start losing digits of precision as `subnormal numbers <https://en.wikipedia.org/wiki/Subnormal_number>`_.

For integers, it is more fun:

.. figure:: https://imgs.xkcd.com/comics/cant_sleep.png
   :align: center

   (`xkcd <https://imgs.xkcd.com/comics/cant_sleep.png>`_)

.. admonition:: Try it...

   Create a program that initializes a ``short`` integer and through
   addition triggers an overflow.

Floating point precision
------------------------

Precision is also important with floating point.  Consider the following: what do you expect?

.. code:: c++

   double a = 1.0;
   double b = -1.0;
   double c = 2.e-15;

   std::cout << (a + b) + c << std::endl;
   std::cout << a + (b + c) << std::endl;

With floating point, the `associate property
<https://en.wikipedia.org/wiki/Associative_property>`_ of addition
does not hold.



