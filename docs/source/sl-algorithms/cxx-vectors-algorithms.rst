*****************
Vector Algorithms
*****************

Here we'll look at some of the standard library algorithms that
don't modify the container.  We'll use ``std::vector`` for all
these examples, but other containers in C++ work as well.


Counting repetitions
====================

We can use `std::ranges::count <https://en.cppreference.com/w/cpp/algorithm/ranges/count.html>`_ to
count how many instances of an element exist in a vector:

.. literalinclude:: ../../../examples/vectors/count_example.cpp
   :language: c++
   :caption: ``count_example.cpp``

.. note::

   If we did this manually, using a loop, we would have to write:

   .. code:: c++

      int count{};
      for (auto e : v) {
          if (e == 1) {
              count++;
          }
      }

   so the ``ranges`` library version is much more compact.

A variation, ``std::ranges::count_if`` takes a function that is used to determine if we count
an element (e.g., only counting odd elements).


Checking if any element matches
===============================

We can use `std::ranges::any_of <https://en.cppreference.com/w/cpp/algorithm/ranges/all_any_none_of.html>`_
to see if any element in the vector satisfies a condition.

This requires that we pass in a function
the works on a single element and returns a ``bool``.

.. literalinclude:: ../../../examples/vectors/any_element.cpp
   :language: c++
   :caption: ``any_element.cpp``

There is also an ``all_of`` and ``none_of`` variant.


.. _sec:std_ranges_find:

Finding an element
==================

Here's an example of using ``find`` on a vector
(using `std::ranges::find <https://en.cppreference.com/w/cpp/algorithm/ranges/find.html>`_):

.. literalinclude:: ../../../examples/vectors/find_example.cpp
   :language: c++
   :caption: ``find_example.cpp``

This returns an iterator that points to the first match in the vector.

.. important::

   Notice the check:

   .. code:: c++

      if (pos == container.end()) {
          std::cout << "element not found" << std::endl;
          return 1;
      }

   If ``std::ranges::find`` does not find a match, then it returns an iterator
   that points to one past the end of the vector (that's what ``.end()`` is).

If we want to know the index of the element we found, we could use
`std::ranges::distance <https://en.cppreference.com/w/cpp/iterator/ranges/distance.html>`_
and ask for the distance from the beginning of the vector:

.. literalinclude:: ../../../examples/vectors/distance_example.cpp
   :language: c++
   :caption: ``distance_example.cpp``


.. caution::

   ``std::ranges::distance`` will return a *signed* integer, since the distance
   count be negative, depending on the starting point we used.  But we can only
   index a vector using an unsigned integer (that is what ``std::size_t`` is,
   so we need to be careful when we do the indexing here.  We know we are safe
   because we use ``.begin()`` as the starting point.
