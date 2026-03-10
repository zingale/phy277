.. _sec:more_functions:

***************************
Returning a ``std::vector``
***************************

Consider a function that takes a vector as input and returns a new one.

We can imagine:

.. code:: c++

   std::vector<double> f(const std::vector<double>& v_in) {

       std::vector<double> v_out;

       // do stuff to fill v_out based on v_in

       return v_out;

   }

This looks like it is returning ``v_out`` by value and that when we do:

.. code:: c++

   auto v_new = f(v_old);

that we need to make a copy from the function to the caller.

.. tip::

   We can use ``auto`` here because C++ knows the return type.  We could
   also be explicit and do:

   .. code:: c++

      std::vector<double> v_new = f(v_old);

But C++ instead provides optimizations (usually `return value optimization <https://en.wikipedia.org/wiki/Copy_elision#Return_value_optimization>`_) that eliminates the need for making a copy.  As a result,
there is little performance penalty in writing a function
that returns something large like a vector.


Updating via an argument
========================

An alternate method to create a vector via a function is to pass it through the argument list as a reference:

.. code:: c++

   void f(const std::vector<double>& v_in, std::vector<double>& v_out) {

       // fill v_out based on v_in

   }

Then we can do:

.. code:: c++

   std::vector<double> v_old{};
   std::vector<double> v_new{};

   f(v_old, v_new);


Returning a reference?
======================

.. danger::

   What about returning a reference?  We might think that we could do:

   .. code:: c++

      std::vector<double>& f(const std::vector<double>& v_in) {

          std::vector<double> v_out;

          // do stuff to fill v_out based on v_in

          return v_out;

      }

   The problem here is that ``v_out`` is destroyed at the end of the function
   ``f``, so the reference will be to something that no longer exists.
   This is not allowed---we cannot return a reference to a local
   variable.


Example
=======

Let's play with this.  Here's an example that tries several ways
to have a function create a new vector whose elements are initialized
to be twice those of the input vector:

.. literalinclude:: ../../../examples/functions/function_vector.cpp
   :language: c++
   :caption: ``function_vector.cpp``


