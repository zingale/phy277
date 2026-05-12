.. _sec:funcs-as-args:

********************************
Passing a Function to a Function
********************************

Sometimes we want to write a function that takes another function as an argument.
We'll use this a lot when we learn about numerical methods, for instance, writing
a function that computes an integral of a user-supplied function.

We use `std::function
<https://en.cppreference.com/w/cpp/utility/functional/function.html>`_
(defined in the ``functional`` header) to define a function argument.


We need to give the signature of the function in the template arguments (``< >``).
For instance, for our function:

.. code:: c++

   double sum(double x, double y) {
       return x + y;
   }

The *function type* is ``double(double, double)`` ---it takes 2
``double`` as arguments and returns a ``double``.  So we would use
``std::function<double(double, double)> f`` as an argument to define
the function ``f``, e.g.,

.. code:: c++

   void f(std::function<double(double, double> f) {
       // do stuff with f ...
   }

could be called as:

.. code:: c++

   f(sum);

using our ``sum`` function defined above.

Example
=======

Here's a concrete example---let's write a function called ``fill``
that takes a vector ``x`` and a function ``f`` and returns a new
vector created by calling the function ``f`` on each value in ``x``:

.. literalinclude:: ../../../examples/functions/vector_fill.cpp
   :language: c++
   :caption: ``vector_fill.cpp``
