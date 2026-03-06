****************
``std::numbers``
****************

C++20 introduced `mathematical constants
<https://en.cppreference.com/w/cpp/numeric/constants.html>`_ via the
``<numbers>`` header.

For example, we can compute the area of a circle, using the value of $\pi$ from
this library:

.. literalinclude:: ../../../examples/floating_point/circle.cpp
   :language: c++
   :caption: ``circle.cpp``

.. important::

   By default, the compilers we are using assume C++17 as the
   standard.  For access to the ``<numbers>`` library, we need to tell
   the compiler to use the C++20 standard.  We do this by adding
   ``-std=c++20`` to the compile line, e.g.:

   .. prompt:: bash

      g++ -std=c++20 -o circle circle.cpp


