*************************
C++ Fundamental Datatypes
*************************

.. admonition:: reading

   `Fundamental types <https://en.cppreference.com/w/cpp/language/types>`_ from cppreference.com

Data is stored in computer memory.  We'll refer to the data in memory
as an `object <https://en.wikipedia.org/wiki/Object_(computer_science)>`_.

We can access this data:

* directly: using a descriptive object name

* indirectly: using a pointer or a reference to the memory location
  (more on this later...)

Data stored in the object can be:

* *mutable* : we can change it---these are `variables
  <https://en.wikipedia.org/wiki/Variable_(computer_science)>`_

* *immutable* : it cannot be changed---these are `constants
  <https://en.wikipedia.org/wiki/Constant_(computer_programming)>`_

Here we'll see how do declare objects using descriptive names.


Memory
======

The smallest unit of storage is the `bit <https://en.wikipedia.org/wiki/Bit>`, simply a ``1`` or ``0``.
This is something that can be expressed by the hardware in your computer.

Computer memory is usually thought about in terms of `bytes <https://en.wikipedia.org/wiki/Byte>`_,
with the standard (today) of 1 byte = 8 bits.

We tend to use the SI prefixes for these, so 1 kilobyte = 1000 bytes.

But your filesystem will likely use `base-2 prefixes
<https://en.wikipedia.org/wiki/Byte#Units_based_on_powers_of_2_(IEC_Prefixes)>`_,
so 1 kibibyte (KiB) = 1024 bytes.

.. important::

   When we want to store something in C++, we need to tell the
   compiler what type of data we are storing, and that will in turn
   tell it how many bytes of memory to allocate for the data.

Types
=====

There are several basic types of data:

* ``bool`` : a 1-bit true or false

* ``char`` : a 1-byte character (like ``'a'``)

* ``int`` : an integer

* ``float`` : a single precision floating point number

* ``double`` : a double precision floating point number

.. note::

   A `floating point number
   <https://en.wikipedia.org/wiki/Floating-point_arithmetic>`_ is any
   number with a decimal point, like ``2.0`` or ``1.e-20``.

   Generally, floating point numbers cannot be exactly represented on
   a computer, since there are infinite numbers on the number line
   between :math:`[0, 1]`, but the computer only has a finite amount
   of memory.

.. tip::

   *Single* and *double* precision refer to how much memory (and therefore
   how much precision) is used to store the numbers.  Usually single
   precision uses 32 bits and double precision uses 64 bits.

   More on this later...

There are also modifiers that can be used with many of these like: ``short``, ``unsigned``, ``long``.

A table of C++ datatypes is provided in the `CPlusPlus tutorial variables section <https://www.cplusplus.com/doc/tutorial/variables/>`_

Scientific notation
===================

We write numbers in scientific notation like $5.2 \times 10^{11}$.
We'll refer to the $5.2$ as the significand, and the $11$ as the
exponent, so a floating point number is written as:

$$\mathrm{significand} \times 10^\mathrm{exponent}$$

On a computer (as with your calculator), we use the ``e`` character to separate the sigificand
and exponent, so $5.2\times 10^{11}$ would be written as ``5.2e11``.


Defining and initialization
===========================

We can define a variable as:

.. code:: c++

   int i;
   float x;
   double slope;

This tells the computer how much memory it needs to reserve for each of these
objects.

.. tip::

   C++ variable names are case-sensitive, so ``x`` and ``X`` are distinct.

.. warning::

   Variable names can include letters, numbers, and ``_``, but cannot
   begin with a number.  Additionally, there are some reserved
   keywords (like ``int``) that cannot be used as variable names.

Assignment
----------

To assign a value to an object, we need to use the assignment operator, ``=``.
E.g.,

.. code:: c++

   i = 1;


Initializing
------------

There are a few ways to initialize.  Here are the two we'll see the most:

.. code:: c++

   int i = 0;
   double x{};

Both of these will initialize the variable to ``0``.  The ``{}``
notation is more flexible, since it will work with more complicated
objects that we will encounter later.

.. important::

   It is always a good idea to initialize a variable with a starting
   value.  Otherwise, most compilers will leave it undefined and you
   can run into problems if you try to use it without first
   remembering to initialize it.

We'll see a third way to initialize objects when we look at classes
(and constructors).

.. caution::

   Consider the following code:

   .. code:: c++

      #include <iostream>

      int main() {

          double x;

          double y = 10;

          std::cout << x + y << std::endl;

      }

   Here we are using ``x`` without initializing it.  This behavior is
   undefined, and can lead to errors that can be hard to track down.


``const``
=========

Objects defined with ``const`` cannot be changed, so you are required
to initialize the immediately:

.. code:: c++

   const double G = 6.67e-8;

.. admonition:: Try it...

   Let's write an example using a ``const`` variable and try to modify it.

   What happens?

