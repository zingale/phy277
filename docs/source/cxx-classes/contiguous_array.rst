.. _sec:contiguous-array:

******************************************
Example: Multidimensional Contiguous Array
******************************************

A common data-structure in scientific computing is a multidimensional
array.  For example, a mathematical matrix is best represented by a
two-dimensional array.  We want to look at some of the ways we can
do this in C++.

.. note::

   Unlike some languages (like Fortran, python w/ NumPy), C++ does not
   have a multidimensional array in its standard library.  This will
   improve in C++23 with the introduction of `std::mdspan
   <https://en.cppreference.com/cpp/container/mdspan>`_.  In a future
   standard (C++29?), another object, ``std::mdarray`` may be
   included.


``vector``-of-``vector``'s
==========================

If we consider:

.. code:: c++

   std::vector<std::vector<double>> array_2d;

Then this is creating a 1-d array that corresponds to the rows of our
array, where each element of this is a separate vector to store the
columns that make up that row.

This can be visualized as:

.. figure:: vector_of_vectors.png
   :align: center
   :width: 80%

   Illustration of a ``vector``-of-``vector``'s for a :math:`4\times
   3` array.

However, each of these row vectors are independent,
and can be in very disparate positions in memory.

We want an array where all the elements are stored *contiguously* in memory.

``array``-of-``array``'s
========================

We could alternately do an array-of-arrays using ``std::array``.  In this case,
we need to know the size of the array ahead of time.  Here's an example that creates
a 3×4 array (3 rows by 4 columns):

.. literalinclude:: ../../../examples/arrays/multid_array.cpp
   :language: c++
   :caption: ``multid_array.cpp``

The downside of this is that we need know how big our array is at
compile-time.  This is not always possible.  However, this type of
array is guaranteed to be contiguous in memory.

.. caution::

   The older C-style way to create an array like this is:

   .. code:: c++

      double M[3][4];

   but this should not be used.  When passing to a function,
   it behaves like a pointer, and the size information is lost.
   This makes it less convenient to work with.

.. caution::

   ``std::array`` places its data on the stack (see :ref:`sec:memory-stack-heap`).
   If the array is large, this can result in a *stack overflow* and the code crashing.
   Try creating an array of size 1024 × 1024.

Contiguous multi-dimensional array
==================================

Our goal now is to create a contiguous memory space that stores all the
elements of the 2-d array.  Further, we want to be able to specify
the size at runtime, instead of compile-time.

To make a contiguous vector, we will use a single ``vector``
dimensioned with a size of ``nrows * ncols``.

.. note::

   We have a choice to make---how do we unravel the multidimensional
   structure into a one-dimensional space?  There are two options:
   row-major and column-major ordering:

   .. figure:: row_column_major.png
      :align: center
      :width: 50%

   In row-major storage, the elements of each row are next to each
   other in memory, and after one row begins the next.  In
   column-major ordering, the elements of a column are next to each
   other in memory.  Most languages default to row-major ordering, so
   that's what we'll use.

We will overload the ``()`` operator to allow for us to index
into this one-dimensional buffer as ``a(nrow, ncol)``.

This can be visualized as:

.. figure:: struct_array.png
   :align: center
   :width: 90%

   Illustration of a one-dimensional ``vector`` wrapped in a ``struct`` that can be
   indexed as a two-dimensional array.

Implementation
==============

We will implement the main ``struct`` in a header so we can reuse this

.. literalinclude:: ../../../examples/contiguous_array/array.H
   :language: c++
   :caption: ``array.H``

Some comments on this implementation:

* We need to order things in the initialization-list in the same order
  they appear as member data in the class.

* We include the ``_data`` vector in the initialization-list without
  worrying about if its size is zero---the ``assert`` in the
  function body do that for us.

* We have two member functions for the ``()`` operator.  The first is for the
  case of a non-``const`` declared ``Array`` and the second is for a
  ``const`` declared ``Array``.

Here's a test program for the ``Array`` object.  Notice that we gain
access to the ``Array`` class via ``#include "array.H"``.

.. literalinclude:: ../../../examples/contiguous_array/test_array.cpp
   :language: c++
   :caption: ``test_array.cpp``

Notice a few things:

* When we loop over the elements of the ``Array`` we get the number of
  rows via ``.nrows()`` and the number of columns via ``.ncols()``.
  Technically these are of type ``std::size_t`` (which is some form
  of an ``unsigned int``).

* For ``Array y``, we use a range-for loop over the elements of
  ``_data`` directly---this is the one-dimensional representation of
  our array.  We can do this because the data is stored contiguously.

  Note though---this breaks the idea of encapsulation in a class, since
  we are accessing this data directly.

* When we try to index out of bounds, the ``assert`` statements catch
  this.

``GNUmakefile``
===============

Here's a makefile that builds this test program + a few others that
we'll compare with.

.. literalinclude:: ../../../examples/contiguous_array/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

.. note::

   The ``GNUmakefile`` has some helpful features.  To just
   build as is, we can do:

   .. prompt:: bash

      make

   If we instead want to turn on the ``assert``'s, then we do:

   .. prompt:: bash

      make DEBUG=TRUE

   To force a rebuild, we can do:

   .. prompt:: bash

      make clean
      make

   The ``assert``'s are handled by the C++ via the ``NDEBUG`` preprocessor
   directive, so setting ``-DNDEBUG`` tells the preprocessor to turn
   off the asserts.

This ``GNUmakefile`` is a little more complex than the previous ones
we looked at, since there are several possible targets defined.  The first
target, ``test_array`` in this case, is the default.  The other two targets
will be discussed below.

.. admonition:: try it...

   What would we need to change if we wanted to make this a ``class``
   instead of a ``struct``?




Some things to consider:

* Putting the ``operator()`` functions in ``array.H`` gives the
  compiler the opportunity to inline them.  This can have a big
  performance difference compared to putting their implementation in
  a separate C++ file.

* The ``std::array<std::array<>>`` is allocated on the stack, and we
  can quickly exceed the stack size.  Meanwhile, the ``Array`` class
  holds the data on the heap.

* In our ``GNUmakefile``, we have one additional feature---we are compiling
  with optimization via ``-O3``.  Look to see how the performance changes
  if we do not optimize.





