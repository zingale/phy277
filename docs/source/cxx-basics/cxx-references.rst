**********
References
**********

.. admonition:: reading

   `C++ references <https://en.wikipedia.org/wiki/Reference_(C%2B%2B)#>`_ from Wikipedia

*References* in C++ provide access to an object indirectly.  It
essentially becomes another name for the object and allows you to
read and write to its memory directly.

We use the ``&`` operator to create a reference.

A great use of references is to access and modify data in containers
(like strings, vectors, and arrays) via a ranged-for loop.  We'll see
this next.


Basic example
=============

Here's a simple example:

.. literalinclude:: ../../../examples/references/simple_reference.cpp
   :language: c++
   :caption: ``simple_reference.cpp``

Since ``x_ref`` is a reference for ``x``, modifying its value directly
modifies ``x`` 's value as well.

.. note::

   You can define the reference as:

   .. code:: c++

      int& x;

   or

   .. code:: c++

      int &x;

.. important::

   A reference must be initialized when it is created.  You cannot do:

   .. code:: c++

      double x{3.14};
      double &x_ref;

      x_ref = x;

``const`` reference
===================

We can create a ``const`` reference that provides only read access to
an object:

.. code:: c++

   int a = 1.0
   const int& a_ref = a;

Now if we try to update ``a`` through ``a_ref``, we'll get a compile-time
error:

.. literalinclude:: ../../../examples/references/const_reference_example.cpp
   :language: c++
   :caption: ``const_reference_example.cpp``

``const`` references will be very useful when we start writing
functions and wish to pass objects in a *read-only*.

.. note::

   You cannot make a reference to a reference.


