*******
Strings
*******

.. admonition:: reading

   `std::string <https://cplusplus.com/reference/string/string/>`__ on cplusplus.com

Character vs string
===================

In C++, there is a distinction between a single character and a string.

* Single quotes, ``'x'`` are used to hold a single character.  This will have the
  datatype ``char``,  e.g.,

  .. code:: c++

     char c = 'x';

* Double quotes, ``"This is a string"`` hold a collection of characters---what we
  call a string.  This uses the datatype ``std::string``, e.g.,

  .. code:: c++

     #include <string>

     std::string s = "This is a string";

.. warning::

   C++ can also use older C-style strings, which are essentially a
   `null-terminated <https://en.wikipedia.org/wiki/Null-terminated_string>`_ array of characters, e.g.,

   .. code:: c++

      char c_string[] = "This is my string";

   These are quite inflexible and can lead to coding errors if you are
   not careful, and we will avoid them as much as possible.


``std::string``
===============

A C++ ``std::string`` holds a sequence of characters.  When working
with strings, we include the ``<string>`` header.

Here's a first example.  We'll create a string and output it to the screen:

.. literalinclude:: ../../../examples/strings/string_example.cpp
   :language: c++
   :caption: ``string_example.cpp``


We can use a *constructor* to create an initial
string filled with a character repeated many times.  For instance,
here's an 80-character line:

.. literalinclude:: ../../../examples/strings/string-repeat.cpp
   :language: c++
   :caption: ``string-repeat.cpp``

We'll learn more about constructors when we discuss classes in C++.

Here, ``'-'`` is a ``char`` and not a string.

.. note::

   A nice overview of working with C++ strings is provided by "hacking C++":
   `std::string <https://hackingcpp.com/cpp/std/string.png>`_

Escape sequences
================

There are some important special characters that we don't type directly,
but instead we precede with a ``\``.  For instance, to add a new line
to a string, we can use ``\n``.


.. note::

   ``\n`` is slightly different than
   ``std::endl``---the latter also flushes the output buffer.

Here's a `list of escape sequences <https://en.cppreference.com/w/cpp/language/escape>`_.

.. admonition:: try it...

   Let's try the "bell", ``\a``, to see if it has an effect on our
   terminal.


String math
===========

There are a lot of operators and functions that can work on strings.  See
https://en.cppreference.com/w/cpp/string/basic_string.html

We can concatenate strings using the ``+`` operator:

.. literalinclude:: ../../../examples/strings/string-cat.cpp
   :language: c++
   :caption: ``string-cat.cpp``

