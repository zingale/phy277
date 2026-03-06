********************
Preview of Functions
********************

We have already been using C++ functions, and soon we'll learn how to write our own.

For example, ``std::sin()`` from ``<cmath>`` is a function.  Any function in C++ will:

* Take arguments passed in through the ``()``.

  For example, we do ``std::sin(x)``, and here
  ``x`` is an argument.

  Some functions will take multiple arguments (separated by ``,``) and some may not take any,
  as with ``epsilon()`` in the line:

  .. code:: c++

     std::numeric_limits<double>::epsilon()

* Return a value.

  For both ``std::sin(x)`` and the ``epsilon()``, these functions
  returned a ``double``, which we capture via assignment, e.g,:

  .. code:: c++

     double x{};
     double y = std::sin(x);

The one function that we have been writing so far is ``main()``, which has a return type of ``int``.



Function prototype
==================

We call the combination of the return type, function name, and arguments, *without the function body* the prototype.
This is the declaration for the function.

A prototype has the form:

::

   return-type  name (argument1, argument2, ...);

The actual implementation of the function can be provided elsewhere (again, more on this later...).

For our ``sin(x)`` function, we would find the prototype / declaration in the ``cmath`` header.
On my machine, this is in ``/usr/include/c++/15/``

It could take the form:

.. code:: c++

   double sin(double x);




