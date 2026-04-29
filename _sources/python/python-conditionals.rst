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
(this is analogous to C++ ``std::ranges::iota`` that we looked at):

.. code:: python

   for n in range(10):
       print(n)

Looping over containers
-----------------------

We already saw that we can use ``for`` to loop over elements of a list.  This also
works for characters in a string, and pretty much any other container in python.


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
