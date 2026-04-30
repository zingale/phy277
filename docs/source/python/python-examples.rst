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


Extended solar system class
===========================

We want to implement the functionality from :ref:`sec:cxx-class-solar-extend`.
In particular, we want our ``Planet`` class to have methods for adding and getting
a planet, and computing the period.

