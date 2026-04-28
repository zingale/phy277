*********************
Strings and ``print``
*********************

Strings
=======

Python allows both single- and double-quotes to be used with strings.  It does not distinguish
between a string and a character (like C++ does).  For example:

.. code:: python

   s1 = "this is a string"
   s2 = 'this is also a string'

If we look at the type, ``type(s1)``, we would see that it is a ``str`` object.

Just like C++ has a lot of functions that work on strings, python has a large library
for strings.  We can do:

.. code:: python

   help(str)

to see these functions.

Format strings
==============

C++'s ``std::format`` was inspired by python and uses the same formatting.  In python, we invoke
the ``format()`` function on a string (it is a member function of the string class), so we can do:

.. code:: python

   a = 1
   b = 2.5
   c = "string"
   print("a = {:2}, b = {:.3f}, c = {:10}".format(a, b, c))

but python also has `f-strings <https://docs.python.org/3/reference/lexical_analysis.html#f-strings>`_
which allow us to put the values directly into the ``{ }`` in the format string.

.. code:: python

   print(f"a = {a:2}, b = {b:.3f}, c = {c:10}")

.. important::

   An f-string has the form: ``f" ... "`` ---with a leading ``f``.

``print``
=========

python doesn't have a stream operator like C++'s ``<<``.  Instead we use ``print``.  By
default ``print`` adds a newline, but we can suppress this by passing the ``end=""`` argument
to print, e.g.:

.. code:: python

   print("this is print without a newline", end="")

see ``help(print)`` for more information.
