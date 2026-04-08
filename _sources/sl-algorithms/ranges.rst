**************
Ranges Library
**************

The C++20 algorithms library provides a number of useful functions
for working with containers.  There are two slightly different interfaces:

* Pre-C++20, we use iterator-based algorithms.  These take a beginning
  and ending iterator into a container to work on.

  e.g.:

  .. code:: c++

     auto it = std::find(vec.begin(), vec.end(), 42);

* In C++20, the `ranges library
  <https://cppreference.net/cpp/ranges.html>`_ was introduced.  This
  provides functions that operate directly on containers.

  e.g.:

  .. code:: c++

     auto it = std::ranges::find(vec, 42);

.. tip::

   In C++, a range is anything that we can iterate over.

For viewing, transforming, and filtering a container, the ranges
library is the more modern approach.  There are some instances
(like modifying the structure of the container) where we'll
use the iterator-based algorithms.


.. note::

   For some algorithms, the ranges versions don't come until standards
   after C++20.  An example is summing the elements of a vector.  In
   C++23, we could use ``std::ranges::fold_left()``, but here we'll
   use the iterator-based ``std::accumulate()``.

Algorithms
==========

A list of the algorithms in the ranges library can be found on the
`cppreference.net constrained algorithms page
<https://cppreference.net/cpp/algorithm/ranges.html>`_

This includes algorithms that search through a container, check conditions
on elements, and more.  Many of these take a function to work with.

This also includes algorithms that change our container, transforming it,
sorting it, etc.

Range adaptors
==============

The ranges library also provides `adaptors
<https://cppreference.net/cpp/ranges.html#Range_adaptors>`_ that can
change how we view a sequence.  We won't consider these here.

