****************
Indexing Strings
****************


Indexing
========

.. literalinclude:: ../../../examples/strings/string-indexing.cpp
   :language: c++
   :caption: string-indexing.cpp

.. caution::

   You need to be aware that indexing is in terms of bytes, and if a
   character (like ``"π"``) requires more than a single byte, you
   might be get what you expect.

   We can use the ``.size()`` function on a string to see how many
   bytes it requires.

   .. literalinclude:: ../../../examples/strings/size.cpp
      :language: c++
      :caption: ``size.cpp``

   For this reason, it is best to stick with the ASCII character set.

