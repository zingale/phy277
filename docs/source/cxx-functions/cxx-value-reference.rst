******************************
Passing by Value vs. Reference
******************************

Passing by value
================

When we write a function like:

.. code:: c++

   void f(double x) {
       // do stuff -- the caller won't see any changes to x
   }

and then call it as:

.. code:: c++

   double z{0};
   f(z);

The value of ``z`` in our caller is copied into the value of ``x`` in
the function ``f()``.  This is a *pass-by-value* argument (sometimes
called *value semantics*).

.. note::

   C++ uses pass-by-value by default *except* for C-style arrays, which are
   passed as a pointer to the first element.  This is another reason why you
   should use ``std::array`` for arrays, since it will be clearer in function.

.. caution::

   Any changes we make to ``x`` Inside of ``f()`` will not be reflected
   back to the caller, so ``z`` will be unmodified by anything that
   happens in the function.

Let's see this in action:

.. literalinclude:: ../../../examples/functions/pass_by_value.cpp
   :language: c++
   :caption: ``pass_by_value.cpp``

Many times this is what we want.  But not always.

Passing by reference
====================

What if we want to
allow the function to modify its argument and for those modifications
to be reflected to the caller?  In this case, we use a reference
argument:

.. code:: c++

   void g(double &x) {
       // anything we do to x will be reflected back to the caller
   }


Here's our example updated:

.. literalinclude:: ../../../examples/functions/pass_by_reference.cpp
   :language: c++
   :caption: ``pass_by_reference.cpp``

Now we see that upon returning from the function, the data we passed
into the function as an argument is updated.

Sometimes: ``const`` reference
==============================

Sometimes, if the object we are passing is big (like a
``std::vector``), then the copy incurred by passing by value is
expensive.  If we use a reference, then there is no copy, and
passing the object is faster.

If we know that we only want the function we are calling to read
from the object and not write to it, we can mark the reference as
const, like:

   .. code:: c++

      void h(const std::vector<double>& x) {
          // x is passed as a reference, but we cannot modify it
      }

and this can be more efficient.

We'll use this in the future, and we will also see that some tools
can suggest this to us to help optimize our codes.
