***************
``std::format``
***************

.. note::

   We will look at the C++20 way to format output.  An alternate way
   to set precision and how wide an output field is can be found in
   the `iomanip library <https://cplusplus.com/reference/iomanip/>`_

.. important::

   You need to use C++20 for this method.  This means using GCC >= 13,
   and adding the ``-std=c++20`` flag when compiling.

`std::format
<https://en.cppreference.com/w/cpp/utility/format/format.html>`_ takes
a string as the first argument with ``{}`` embedded as placeholders
and then inserts the remaining arguments into the string, in order, in
the ``{}``.

We'll look at its basic usage.

Basic output
============

Here's a simple example:

.. literalinclude:: ../../../examples/format/format_simple.cpp
   :language: c++
   :caption: ``format_simple.cpp``

When run, this outputs ``x = 10; y = 0.000123; a = test`` with a new line (since
we added the ``\n``;

Each variable / object we specify as an argument after the first
argument is inserted *in order* into the ``{}`` in the format string.

.. note::

   You need to include the ``<format>`` header to use ``std::format``.

.. tip::

   We don't need to make an intermediate string, we could just send the
   output of ``std::format`` to the output stream, ``std::cout`` directly
   like:

   .. code:: c++

      std::cout << std::format("x = {}; y = {}; a = {}\n", x, y, a);

If we include more arguments after the format string than there are ``{}``, the
extra arguments are just ignored:

.. literalinclude:: ../../../examples/format/format_too_many.cpp
   :language: c++
   :caption: ``format_too_many.cpp``

If we don't provide enough arguments, then the code will not compile.

Formatting
==========

Within the ``{}`` we can specify the formatting using `format specifiers <https://en.cppreference.com/w/cpp/utility/format/spec.html>`_.

.. note::

   These specifiers are the same as used in the Python programming
   language.  A detailed overview is given in the python docs for the
   `format specification mini-language
   <https://docs.python.org/3/library/string.html#formatspec>`_

The basic form is ``{:specifier}``, where the specifier has fields giving:

* Filling and alignment
* sign, 0 padding
* width
* precision
* type

We;ll look at the basic cases that we usually care about---mainly
specifying the width of the output, the precision, and the type.

Here's an example:

.. literalinclude:: ../../../examples/format/format_specifiers.cpp
   :language: c++
   :caption: ``format_specifiers.cpp``

this gives:

::

    (x = 010; y = 1.23e-06; z = 10.2 a = test      )

Let's see what these do:

* for the ``int x{10}``, we use the specifier ``03d``.  This uses 3
  characters for the width of the field, puts ``0`` s in any empty
  field, and the ``d`` specifies that it is an integer.

* for the ``double y{1.23e-6}``, the specifier ``8.3g`` says to use 8 characters
  for the width with 3 digits of precision after the decimal, and the ``g``
  asks it to use scientific notation for large exponents and fixed formatting
  for small exponents.

* for the ``double z{10.25}``, the specifier ``4.1f`` says to use 4 characters
  for the width with 1 digit of precision after the decimal, and the ``f``
  requires it to use fixed-format (never switch to scientific notation).

* finally, for the ``std::string a{"test"}``, the specifier ``10`` says to
  use 10 characters for the width.  Since our string is only 4 characters
  long, we see that it adds spaces to the end.

.. tip::

   Specifying the width is a great way to output data in columns, which will make
   it easy to plot.  We'll see this later.


``std::print``
==============

In C++23, things become even simpler, with the addition of ``std::print`` and ``std::println``.
For example, we can do:

.. literalinclude:: ../../../examples/format/println.cpp
   :language: c++
   :caption: ``println.cpp``

and compile this as:

.. prompt:: bash

   g++ -std=c++23 -o println println.cpp

The difference between ``std::print`` and ``std::println`` is that ``std::println`` adds
a newline to the end.

.. note::

   This requires GCC >= 14

