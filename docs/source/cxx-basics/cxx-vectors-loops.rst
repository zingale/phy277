********************
Looping Over Vectors
********************

Often we will want to loop over the elements contained in a vector,
and C++ provides a `range-based loop
<https://en.cppreference.com/w/cpp/language/range-for>`_ for this
purpose.  For example to loop over all elements and output them to the
terminal, we could do:

.. literalinclude:: ../../../examples/vectors/vector_loop.cpp
   :language: c++
   :caption: ``vector_loop.cpp``

Here we see a new keyword, ``auto``.  Each pass through this loop,
``e`` will take on the next value in our ``vector`` called
``container``.  The body of the loop is contained in the ``{...}``.

C++ requires that we declare the data type of
``e``.  In this case, the compiler knows that it will have to be a
``double``, since the ``vector`` is a vector of ``double``, so we can
use the ``auto`` keyword to have the compiler automatically deduce the
data type.


List initializer
================

If we don't want to reuse the values that we are looping over, we can do a shortcut
like:

.. literalinclude:: ../../../examples/vectors/vector_initialization_list.cpp
   :language: c++
   :caption: ``vector_initialization_list.cpp``

Here, the values in the ``{ }`` in the ``for`` loop are in what is called an
`initializer_list <https://en.cppreference.com/w/cpp/utility/initializer_list.html>`_.
We won't worry about this distinction, but note that when we places the values
directly in the loop, as here, we cannot update or access these values outside of the loop.


