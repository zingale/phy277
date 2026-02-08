*************************
C++ Fundamental Datatypes
*************************

.. admonition:: reading

   `Fundamental types <https://en.cppreference.com/w/cpp/language/types>`_ from cppreference.com

Data is stored in computer memory.  We'll refer to the data in memory
as an `object
<https://en.wikipedia.org/wiki/Object_(computer_science)>`_.

We can access this data:

* directly: using a descriptive object name

* indirectly: using a pointer or a reference to the memory location

Data stored in the object can be:

* *mutable* : we can change it---these are `variables
  <https://en.wikipedia.org/wiki/Variable_(computer_science)>`_

* *immutable* : it cannot be changed---these are `constants
  <https://en.wikipedia.org/wiki/Constant_(computer_programming)>`_

There are several basic types of data:

* ``bool`` : a 1-bit true or false

* ``char`` : a 1 byte character (like ``'a'``)

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

   *Single* and *double* precision refer to how much memory (and therefore
   how much precision) is used to store the numbers.  Usually single
   precision uses 32 bits and double precision uses 64 bits.
   More on this later...

There are also modifiers that can be used with many of these like: ``short``, ``unsigned``, ``long``.

A table of C++ datatypes is provided in the `CPlusPlus tutorial variables section <https://www.cplusplus.com/doc/tutorial/variables/>`_

Defining and Initialization
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

