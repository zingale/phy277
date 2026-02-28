*******
Vectors
*******

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

There are many ways 



Adding to a vector
==================

Lets see how to create a vector and add some data to it.

Here's a simple example:

.. literalinclude:: ../../../examples/vectors/simple_vector.cpp
   :language: c++
   :caption: ``simple_vector.cpp``

Notice the following:

* We specify the data type when creating a vector

* We use ``push_back`` to add data to the end of a vector.  Here we
  are using the ``.`` operator to indicate that we are performing the
  ``push_back`` on the vector ``container`` that we created.

* We access elements of a vector using ``[]`` with an index, and that
  indices start at 0.

* We can use the ``.size()`` `member function <https://en.wikipedia.org/wiki/C%2B%2B_classes#Member_functions>`_
  to get the number of elements in the vector.

