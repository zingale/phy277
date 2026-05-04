********
Examples
********

Let's rewrite some of our C++ codes in python to see how the language works.


Counting and more
=================

Python lists have a ``count`` method.  Let's implement our :ref:`sec:ranges-count`
example.

What about doing a ``count_if``?

The rough equivalent of ``std::ranges::find`` is the ``index`` method.

``enumerate``
-------------

If we want to find the indices for multiple matches, we can use ``enumerate()``
to loop over a list.


Root-finding
============

Let's rewrite our :ref:`sec:root-bisection` root-finding method in python.
This is almost a one-to-one translation.  The main thing we change is that
``root`` is now passed back as the return value, and it is set to ``None``
if the root could not be found.  We can do this in python because
we don't need to specify the types.  In C++ this is harder.


.. literalinclude:: ../../../examples/python/bisection.py
   :language: python
   :caption: ``bisection.py``

Note that we end with a call to ``main()``.  This is the part that will be executed
if we run this as:

.. prompt:: bash

   python bisection

We can make it such that we can either run this on the command line (as above) or import
the module (i.e., ``import bisection``) by changing this to:

.. code:: python

   if __name__ == "__main__":
       main()

Here, ``__name__`` is a built-in that will only be equal to ``__main__`` if we are
running from the commandline.

Extended solar system class
===========================

We want to implement the functionality from :ref:`sec:cxx-class-solar-extend`.
In particular, we want our ``Planet`` class to have methods for adding and getting
a planet, and computing the period.


Planetary orbit integrator
==========================

Let's review our :ref:`planetary_orbit` example in python.  As we do it, we
can put all of the functions inside of a class.
