***********************
Multidimensional Arrays
***********************

.. _sec:multidimensionalarrays:

We can have an array of arrays.  This would
again be fixed-size, so we'll need to specify both the number of rows
and the number of columns at compile time.

Here's an example:

.. literalinclude:: ../../../examples/arrays/multid_array.cpp
   :language: c++
   :caption: ``multid_array.cpp``

Notice that we need to explicitly set the size of both the
``row_arr_t`` and the ``fixed_mat_t``.  While this solves the issue we had
with our ``std::vector<std::vector<double>>`` where we could have rows
of varying length, it is less flexible in that we need to know the
size ahead of time.

There are a few features here that we have not yet seen.

* We use the ``format`` library to set the width (number of characters) to
  use when writing out our numbers.  This makes them line up nicely.

* We access the information in the arrays using a reference (with the
  ``&`` operator).  This gives us direct access to the memory without
  needing to make a copy.

We'll cover references next.

.. note::

   We could also do this with ``std::vector``.

