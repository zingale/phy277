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


Formatting
==========




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

