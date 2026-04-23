***********
Homework #8
***********

.. important::

   The file submission requirements are different than previous homeworks.

   For each problem below, you need to submit a header file (``.H``) implementing
   the class described in the problem and a source file (``.cpp``) containing
   the ``main()`` function and any tests that the problem asks for.


.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.


1. *A simple class* : Create a class called ``Rectangle`` that describes a rectangle.
   This should be done in a header file.  Be sure to include a *header guard*.
   Your class should:

   * Have member data for the ``width`` and ``height`` of the rectangle

   * Implement *two* constructors for the class, one that takes a width and height, like:

     .. code:: c++

        Rectangle r(1.0, 2.0);

     and one that is appropriate for a square, which just takes a single length and
     initializes both the width and height to that value, e.g.,

     .. code:: c++

        Rectangle r(1.5);

   * Have two member functions, ``perimeter()`` that returns the perimeter of
     the rectangle and ``area()`` that returns the area.

   Next create a source file containing the ``main`` an show how to
   create (1) a rectangle and (2) a square, and for each, output their
   properties (perimeter and area) to the terminal.

2. *3D vectors* : Starting with our ``vector2d.H`` implementation (:ref:`sec:vector2d`),
   extend it to three-dimensions (call your new implementation ``vector3d.H``).

   You should:

   * Add ``z`` as member data.

   * Add a ``set_z`` function

   * Extend the addition (``+``), subtraction (``-``) and unary minus (the other ``-``)
     operators to work for a 3D vector.

   * Update the output stream operator ``<<``

   Don't worry about the additional operators we looked at in class---just focus on
   our original implementation linked above.

   Now write a ``main()`` function that exercises each of these operators---use the
   driver we created for the 2D implementation as the starting point.


