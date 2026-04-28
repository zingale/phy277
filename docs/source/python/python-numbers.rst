**************************
Integers, Floats, and Math
**************************

.. tip::

   python is dynamically-typed, so we don't need to give the datatype
   when creating a variable / object.  Instead the type is inferred
   from the object we are assigning a variable to.

Integers
========

To create an integer in python, we simply assign a variable:

.. code:: python

   a = 10

Since we didn't include a decimal point, this is treated as an integer.

We can use the ``type`` function to ask python what datatype an object
is holding:

.. code:: python

   type(a)

this returns ``int``.

Integer division works differently in python than in C++:

.. code:: python

   h = 1/2
   print(h, type(h))

This outputs:

::

    0.5 <class 'float'>

Floating point
==============

Floating-point math works the same in python as in C++, and the
operator precedence is the same as well.

For example



``math`` module
===============

The python `math module <https://docs.python.org/3/library/math.html>`_ provides much of the same
functionality as the C++ standard library does when we include ``<cmath>``.

We first need to *import* it:

.. code:: python

   import math

then we can access all it's functionality using the ``.`` operator (for instance, ``math.cos()``.

We can get the value of $\pi$ as ``math.pi``:

.. code:: python

   print(math.pi)

Just like in C++, the trig function expect arguments in radians, so we can find $\cos(45^\circ)$
as:

.. code:: python

   angle = 45 * math.pi / 180
   c = math.cos(angle)

we can also use ``math.radians`` to convert it for us:

.. code:: python

   c = math.cos(math.radians(45))


