*******
Strings
*******

.. admonition:: reading

   `std::string <https://cplusplus.com/reference/string/string/>`__ on cplusplus.com

``std::string``
===============

A C++ ``std::string`` holds a sequence of characters.  When working
with strings, we include the ``<string>`` header.

.. note::

   In C++, single characters (``char``) are enclosed in single-quotes, e.g., ``'A'``,
   while strings are enclosed in double quotes, e.g. ``"string"``.

.. warning::

   C++ can also use older C-style strings, which are essentially a
   `null-terminated <https://en.wikipedia.org/wiki/Null-terminated_string>`_ array of characters, e.g.,

   .. code:: c++

      char c_string[] = "this is my string";

   These are quite inflexible and can lead to coding errors if you are
   not careful, and we will avoid them as much as possible.

Here's a first example.  We'll create a string and we'll concatenate
another string onto it using the ``+`` operator:

.. literalinclude:: ../../../examples/strings/string_example.cpp
   :language: c++
   :caption: ``string_example.cpp``

In this example, the strings that we add to our initial
string are actually C-style strings, but ``std::string`` knows how to
work with them.

.. note::

   We used an `escape sequence
   <https://en.cppreference.com/w/cpp/language/escape>`_ here, ``\n``,
   to create a newline.  ``\n`` is slightly different than
   ``std::endl``---the latter also flushes the output buffer.

We can use a constructor to create an initial
string filled with a character repeated many times.  For instance,
here's an 80-character line:

.. literalinclude:: ../../../examples/strings/string-repeat.cpp
   :language: c++
   :caption: string-repeat.cpp


Here, ``'-'`` is a ``char`` and not a string.

.. note::

   A nice overview of working with C++ strings is provided by "hacking C++":
   `std::string <https://hackingcpp.com/cpp/std/string.png>`_


String math
===========

There are a lot of operators and functions that can work on strings.  See
https://en.cppreference.com/w/cpp/string/basic_string.html

We can concatenate strings using the ``+`` operator:

.. literalinclude:: ../../../examples/strings/string-cat.cpp
   :language: c++
   :caption: string-cat.cpp

