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

As noticed previously, in python the number of bits used to store an integer
will grow as needed, preventing overflow.

For example:

.. code:: python

   a = 123456789012345678901234567890
   print(a.bit_length())

shows that this number requires 97-bits.

.. note::

   Here we are seeing that python treats integers as objects of the ``int`` class,
   and ``.bit_length()`` is a member-function (or a *method*, in python naming conventions).


Floating point
==============

Floating-point math works the same in python as in C++.  The core operators
are ``+``, ``-``, ``*``, and ``/``, just like in C++,  and the
operator precedence is the same as well.

Just like in C++, when we do an operation involving an integer and a floating point
number, the result is a floating point number.  E.g.,

.. code:: python

   1 + 2.0

is a ``float``.

Floating point limits
---------------------

The python equivalent of the C++ ``std::numeric_limits`` is `sys.float_info <https://docs.python.org/3/library/sys.html#sys.float_info>`_:

.. code:: python

   import sys
   print(sys.float_info)


``**`` operator
---------------

Python has a power operator, ``**``, so we can do $x^{5/2}$ as ``x**2.5``.


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


``help``
========

python has a ``help`` function that will provide a description of a
function and the arguments that it takes.  For instance, we can do:

.. code:: python

   import math
   help(math.cos)

Built-in help is a core-feature of python.
This works for any function / module in the python standard library,
and for most functions / modules in other libraries that we will used.
