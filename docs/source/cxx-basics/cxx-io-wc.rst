*******************
I/O Example: ``wc``
*******************

Let's write our own version of ``wc``.  Here's a text file:
:download:`lorem-ipsum.txt <./lorem-ipsum.txt>`.

Let's write a C++ code the counts the number of lines, words, and
characters from the input file.

We don't know how to take a command line argument (yet), so let's
just hardcode the file name into the program for now.

.. literalinclude:: ../../../examples/io/wc_example.cpp
   :language: c++
   :caption: ``wc_example.cpp``

The trickiest part of this is counting words.  There could be multiple
spaces or newlines separating words.  We count a word only when we
encounter a space or newline for the first time.
