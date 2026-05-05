********
Examples
********

Let's rewrite some of our C++ codes in python to see how the language works.


Counting and more
=================

Python lists have a ``count`` method.  Let's implement our :ref:`sec:ranges-count`
example.

Given a list ``a``, we can just use ``a.count()``:

.. code:: pycon

   >>> a = [1, 1, 4, 6, 10, 1, 3, -2, -8, 0]
   >>> a.count(1)
   3

What about doing a ``count_if``?  That's a little more tricky, but
we can do a comprehension:

.. code:: pycon

   >>> num = len([e for e in a if e < 0])
   >>> num
   2

``enumerate``
-------------

The rough equivalent of ``std::ranges::find`` is the ``index`` method.

If we want to find the indices for multiple matches, we can use `enumerate <https://docs.python.org/3/library/functions.html#enumerate>`_
to loop over a list and get both the index and list element at the same time.

Using the same list as above:

.. code:: pycon

   >>> a = [1, 1, 4, 6, 10, 1, 3, -2, -8, 0]
   >>> indices = []
   >>> for n, e in enumerate(a):
   ...     if e == 1:
   ...         indices.append(n)
   ...
   >>> indices
   [0, 1, 5]

This can be done as a comprehension as well:

.. code:: pycon

   >>> indices = [n for n, e in enumerate(a) if e == 1]
   >>> indices
   [0, 1, 5]

.. tip::

   C++23 has an `enumerate function <https://en.cppreference.com/cpp/ranges/enumerate_view>`_ available in the standard library.


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

.. literalinclude:: ../../../examples/python/solar_system.py
   :language: python
   :caption: `solar_system.py`
