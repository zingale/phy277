*****
Views
*****

Views are a special type of range---it does not own its own data,
and it is *lazy*---it generates the data as needed.

A nice example of this is `std::views::iota <https://en.cppreference.com/w/cpp/ranges/iota_view.html>`_.  This generates in increasing order from a beginning value
up to (but not including the end value).  E.g.,

.. code:: c++

   std::views::iota(0, 5)

would give the numbers ``0``, ``1``, ``2``, ``3``, and ``4``.

We can use this in a for-loop:

.. literalinclude:: ../../../examples/views/iota.cpp
   :language: c++
   :caption: ``iota.cpp``

