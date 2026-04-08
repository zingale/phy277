*****************
Vector Algorithms
*****************

Here we'll look at some of the standard library algorithms that
don't modify the container.  We'll use ``std::vector`` for all
these examples, but other containers in C++ work as well.


Checking if any element matches
===============================


Counting repetitions
====================


Finding an element
==================

Here's an example of using ``find`` on a vector
(using `std::find <https://en.cppreference.com/w/cpp/algorithm/find>`_):

.. literalinclude:: ../../../examples/vectors/find_example.cpp
   :language: c++
   :caption: ``find_example.cpp``

If we want to know the index of the element we found, we could use
`std::distance() <https://en.cppreference.com/w/cpp/iterator/distance>`_

.. literalinclude:: ../../../examples/vectors/distance_example.cpp
   :language: c++
   :caption: ``distance_example.cpp``


