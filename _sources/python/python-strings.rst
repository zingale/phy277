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



``print``
=========

python doesn't have a stream operator like C++'s ``<<``.  Instead we use ``print``.  By
default ``print`` adds a newline, but we can suppress this by passing the ``end=""`` argument
to print, e.g.:

.. code:: python

   print("this is print without a newline", end="")

see ``help(print)`` for more information.
