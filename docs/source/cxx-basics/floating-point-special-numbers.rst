*********************************
Special Floating Point Quantities
*********************************

IEEE 754 defines a few special quantities:

* ``NaN`` (not a number) is the result of ``0.0/0.0`` or ``std::sqrt(-1.0)``

* ``Inf`` (infinity) is the result of ``1.0/0.0``

* ``-0`` is a valid number and the standard says that ``-0`` is equivalent to ``0``


We can test on these values using `std::isnan
<https://en.cppreference.com/w/cpp/numeric/math/isnan>`_ and
`std::isinf
<https://en.cppreference.com/w/cpp/numeric/math/isinf.html>`_.  For
instance, here we generate a NaN:

.. literalinclude:: ../../../examples/floating_point/nan.cpp
   :language: c++
   :caption: ``nan.cpp``

