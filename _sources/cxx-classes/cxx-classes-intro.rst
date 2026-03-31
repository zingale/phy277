Introduction to Classes
=======================

.. admonition:: reading

   `C++ classes <https://en.wikipedia.org/wiki/C%2B%2B_classes>`_ from Wikipedia

Classes are a fundamental part of the `object-oriented programming <https://en.wikipedia.org/wiki/Object-oriented_programming>`_ paradigm.
A class is an object that holds both data and functions that know how to operate on the data.

.. tip::

   In C++, both ``struct`` and ``class`` create a class, with the difference being
   whether the data is publicly accessible by default.

We'll start by making a simple container that holds a vector.  It is not very
useful (since it doesn't do much that ``std::vector`` doesn't already do).

.. literalinclude:: ../../../examples/classes/simple-class.cpp
   :language: c++
   :caption: ``simple-class.cpp``
