**********
Structures
**********

.. admonition:: reading

   `structures discussion at cppreference.com <https://en.cppreference.com/w/c/language/struct>`_

A structure (or ``struct``) is a compound datatype that can hold a mix
of data.  In C++, a ``struct`` shares many similarities to a
``class``---both hold data as well as functions that work on the data
(called *members*).

.. _sec:structplanet:

Creating a ``struct``
=====================

Consider the following:

.. code:: c++

   struct Planet
   {
       std::string name;
       double a{};            // semi-major axis
       double e{};            // eccentricity
   };

This is a structure that can describe some basic properties of a planet, including its
name, semi-major axis, and eccentricity of the orbit.

.. tip::

   A common mistake is to forget the ``;`` after the definition of the ``struct``.


We can create a ``Planet`` object via:

.. code:: c++

   Planet p;

Then we can access the different members of the ``struct`` using the "``.``" operator,
e.g. ``p.name``, ``p.a``, and ``p.e``.


Initializing a ``struct``
=========================

There are several ways we can initialize our ``struct``.  Once we create a ``Planet``, we
can initialize the components separately, or we can use a list-initialization.

.. literalinclude:: ../../../examples/structs/struct_init.cpp
   :language: c++
   :caption: ``struct_init.cpp``


.. note::

   We define the ``struct`` ``Planet`` *outside* of the ``main`` function.

