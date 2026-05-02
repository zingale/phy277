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

Extended solar system class
===========================

We want to implement the functionality from :ref:`sec:cxx-class-solar-extend`.
In particular, we want our ``Planet`` class to have methods for adding and getting
a planet, and computing the period.


Planetary orbit integrator
==========================

Let's review our :ref:`planetary_orbit` example in python.  As we do it, we
can put all of the functions inside of a class.
