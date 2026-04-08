*******
Sorting
*******

We can sort a vector using `std::ranges::sort
<https://en.cppreference.com/w/cpp/algorithm/ranges/sort.html>`_.
This requires that we provide a function that tells sort how to
compare 2 elements.

Here's an example that sorts some strings using the default comparison
(alphabetically) and then again with a custom comparison function that
sorts by string length:

.. literalinclude:: ../../../examples/functions/algorithms_functions.cpp
   :language: c++
   :caption: ``algorithms_functions.cpp``

We'll revisit this yet again when we learn about *lambda functions*.
