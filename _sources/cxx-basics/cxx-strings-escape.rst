****************
Escape Sequences
****************

There are some important special characters that we don't type directly,
but instead we precede with a ``\``.  For instance, to add a new line
to a string, we can use ``\n``.

.. literalinclude:: ../../../examples/strings/string-newline.cpp
   :language: c++
   :caption: ``string-newline.cpp``

When we run this, we see that a new line is output to the terminal.


.. tip::

   ``\n`` is slightly different than
   ``std::endl``---the latter also flushes the output buffer.  This can
   matter for performance, but we don't worry about this in this class.

Here's a `list of escape sequences <https://en.cppreference.com/w/cpp/language/escape>`_.

.. admonition:: try it...

   Let's try the "bell", ``\a``, to see if it has an effect on our
   terminal.

