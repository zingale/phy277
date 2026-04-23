********************************
Adding to our ``Vector2d`` Class
********************************

Let's extend our ``Vector2d`` class with the following operators / functions:


Multiplication by a scalar
==========================



Division by a scalar
====================


Dot product
===========


Cross product
=============


Absolute value / magnitude
==========================



Input stream operator, ``>>``
=============================

We want to overload ``>>`` so we can read directly into a ``Vector2d``
object, e.g.,

.. code:: c++

   Vector2d v;

   cin >> v;

Your function should look like:

.. code:: c++

   friend std::istream& operator>>(std::istream& is, Vector2d &v);

Notice that the ``Vector2d`` is not ``const``, since we will be modifying it.

You will want to read 2 pieces of data from the input stream and directly
set ``v.x`` and ``v.y``.



Test driver
===========

Here's a test driver that exercises these new capabilities.  It uses
assertions to ensure that we implemented them correctly.

