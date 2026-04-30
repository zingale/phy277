**********************
Loops and ``if``-tests
**********************

.. important::

   python uses whitespace to denote a code block in if-statements, loops, functions,
   and more.

Loops
=====

The python ``while`` loop behaves just like in C++:

.. code:: python

   n = 0
   while n < 10:
       print(n)
       n += 1

Notice that the condition ends with a ``:`` and then the body of the
loop is indented.

For the loop above, we would usually use the `range
<https://docs.python.org/3/library/stdtypes.html#range>`_ function
(this is analogous to C++ ``std::ranges::iota`` that we looked at :ref:`sec:ranges-iota`):

.. code:: python

   for n in range(10):
       print(n)

Looping over containers
-----------------------

We already saw that we can use ``for`` to loop over elements of a list.  This also
works for characters in a string, and pretty much any other container in python.

For example, we can loop over characters in a string:

.. code:: python

   for c in "the quick brown fox jumps over the lazy dog":
       print(c)

but strings have lots of methods, and we can use the ``.split()`` method to
split based on spaces and loop over words:

.. code:: python

   for w in "the quick brown fox jumps over the lazy dog".split():
       print(c)


Conditionals
============

python if-statements work the same as in C++.  The C++ combination
``else if`` is contracted to ``elif`` in python, and whitespace is
used to denote the block that is executed for each branch:


.. code:: python

   x = 0

   if x < 0:
       print("negative")
   elif x == 0:
       print("zero")
   else:
       print("positive")


Examples
========

Machine epsilon
---------------

In :ref:`sec:homework5`, we found machine $\epsilon$ by looping
until $1 + \epsilon == 1$.  Let's rewrite that in python:

.. literalinclude:: ../../../examples/python/epsilon.py
   :language: python
   :caption: ``epsilon.py``

Notice how similar this code is to the C++ version.

Fibonacci sequence
------------------

Let's rewrite our :ref:`sec:fibonacci` example in python:

.. literalinclude:: ../../../examples/python/fibonacci.py
   :language: python
   :caption: ``fibonacci.py``

A few notes:

* We use ``input()`` to read from the terminal.  This will return
  a string, so we cast it to an ``int`` using ``int()``.

* We can easily access the last 2 elements of the list using
  ``fib[-1]`` and ``fib[-2]``.

* Unlike the C++ version (which used ``long``), we don't overflow
  even if we ask for 100 terms, because python integers grow
  as needed.

