*************
SL Algorithms
*************

We looked at some of the `algorithms that work on standard C++
containers <https://en.cppreference.com/w/cpp/algorithm>`_ (like
vectors) previously.  Now we can look at some more.

Consider ``std::sort()``---you can provide a function to ``sort``
that tells it how to do the comparison.

Here's an example that sorts some strings using the default comparison
(alphabetically) and then again with a custom comparison function that
sorts by string length:

.. literalinclude:: ../../../examples/functions/algorithms_functions.cpp
   :language: c++
   :caption: ``algorithms_functions.cpp``

We'll revisit this yet again when we learn about *lambda functions*.
