********************
Looping Over Vectors
********************

Often we will want to loop over the elements contained in a vector,
and C++ provides a `range-based loop
<https://en.cppreference.com/w/cpp/language/range-for>`_ for this
purpose.  For example to loop over all elements and output them to the
terminal, we could do:

.. code:: c++

   for (auto e : container) {
       std::cout << e << std::endl;
   }

Here we see a new keyword, ``auto``.  Each pass through this loop,
``e`` will take on the next value in our ``vector`` called
``container``.  The body of the loop is contained in the ``{...}``.

C++ requires that we declare the data type of
``e``.  In this case, the compiler knows that it will have to be a
``double``, since the ``vector`` is a vector of ``double``, so we can
use the ``auto`` keyword to have the compiler automatically deduce the
data type.


Small-angle approximation example
=================================

In your homework, you looked at the small angle approximation for a variety on angles.
We can write that code a lot more compactly now with loops:

.. literalinclude:: ../../../examples/vectors/sine_loop.cpp
   :language: c++
   :caption: ``sine_loop.cpp``



In-class example
================


.. admonition:: try it...

   Let's add a loop to our code and compute the average of the elements
   in the vector.

