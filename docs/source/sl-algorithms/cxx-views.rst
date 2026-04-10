*****
Views
*****

Views are a special type of range---it does not own its own data,
and it is *lazy*---it generates the data as needed.

``iota``
========

A nice example of this is `std::views::iota <https://en.cppreference.com/w/cpp/ranges/iota_view.html>`_.  This generates integers in increasing order from a beginning value
up to (but not including the end value).  E.g.,

.. code:: c++

   std::views::iota(0, 5)

would give the numbers ``0``, ``1``, ``2``, ``3``, and ``4``.

We can use this in a for-loop:

.. literalinclude:: ../../../examples/views/iota.cpp
   :language: c++
   :caption: ``iota.cpp``

Reverse loop
============

We can loop over a vector in reverse using `std::views::reverse <https://en.cppreference.com/w/cpp/ranges/reverse_view.html>`_.

.. literalinclude:: ../../../examples/views/reverse.cpp
   :language: c++
   :caption: ``reverse.cpp``

.. note::

   An alternate way to do this is to use a range adaptor of the form:

   .. code:: c++

      for (auto e : v | std::views::reverse) {
          std::cout << e << std::endl;
      }

   With range adaptors, you can chain a lot of them together to create
   complex views into the data.
