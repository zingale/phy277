*******
Vectors
*******

.. admonition:: reading

   `std::vector at cpluscplus.com <https://cplusplus.com/reference/vector/vector/>`_

C++ has the `standard library
<https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library>`_ (C++ SL)
which adds an immense amount of functionality to the language.  Let's
look at ``std::vector``.  A ``vector`` is a container that can hold
data of the same type (e.g., ``double``).  It differs from an array
that you might have used in other languages in that it is not a fixed
size---it can grow as needed to hold more data.

.. note::

   There are many other `types of containers in the C++ SL <https://en.cppreference.com/w/cpp/container.html>`_ that have
   different properties.  Vectors are one of the most useful.

``std::vector``
===============

Vectors are very useful to store data and loop over it, etc.
Information on the properties of C++ vectors can be found at the
`CPlusPlus vector page
<https://www.cplusplus.com/reference/vector/vector/>`_.
From that description, we see that vectors:

* store the data contiguously in memory

* can grow as needed (but occasionally, this means creating a new
  vector of larger size and copying data into it---a slow operation)

* have a lot of functions that can work on them

* can access any location directly

* are very efficient at adding data to the end, but not efficient for
  inserting data in the middle


Creating a vector
=================

When we create a vector, we need to specify what type of data it holds.  E.g.,
a vector that holds ``double`` precision numbers would be declared as:

.. code:: c++

   std::vector<double> a;

and a vector holding ``int`` would be declared as:

.. code:: c++

   std::vector<int> a;

These vectors are empty.  We can specify the data at initialization or add it later.

To initialize a vector with data, we can do:

.. code:: c++

   std::vector<double> a{1.0, 2.0, 4.0, 8.0};


Indexing vectors
================

Just like with strings, we can index a vector to access a single element.
We use 0-based indexing.

We can also access the first element using ``.front()`` and the last
element using ``.back()``.

.. literalinclude:: ../../../examples/vectors/vector_indexing.cpp
   :language: c++
   :caption: ``vector_indexing.cpp``



