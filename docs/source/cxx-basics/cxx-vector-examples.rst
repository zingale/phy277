****************************
Examples of Using ``vector``
****************************

Small-angle approximation example
=================================

In your homework, you looked at the small angle approximation for a
variety on angles.  We can write that code a lot more compactly now
with loops:

.. literalinclude:: ../../../examples/vectors/sine_loop.cpp
   :language: c++
   :caption: ``sine_loop.cpp``

Notice that we also use ``std::format`` here and set the column
widths to give a nice table output.

Averaging
=========

Let's see how to compute the average of a vector's elements.

.. literalinclude:: ../../../examples/vectors/average.cpp
   :language: c++
   :caption: ``average.cpp``

.. important::

   We need to initialize ``sum`` to ``0.0`` here (we did it using ``{}``),
   because we are adding to it in the loop.  If we didn't initialize it,
   its value would be undefined at the start.
