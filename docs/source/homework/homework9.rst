***********
Homework #9
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

   * Have member functions, ``perimeter()``, that returns the perimeter of
     the rectangle and ``area()``, that returns the area.

   * Have a third member function, ``is_square()`` that returns ``true`` if
     the ``Rectangle`` is a square.

   Next create a source file containing the ``main`` and show how to
   create:

   * a rectangle
   * a square

   and for each, output their
   properties (perimeter,area, and the result of the test if it is
   square) to the terminal.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      First the header:

      .. literalinclude:: rectangle.H
         :language: c++
         :caption: ``rectangle.H``

      Notice that since I used that ``class`` keyword, I need to explicitly make the
      constructors and member functions ``public``.

      Now the driver:

      .. literalinclude:: hw9_p1_test_rectangle.cpp
         :language: c++
         :caption: ``test_rectangle.cpp``


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

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      First the header:

      .. literalinclude:: vector3d.H
         :language: c++
         :caption: ``vector3d.H``

      The extension to 3-D is straightforward---we just need to
      include the new ``z`` component in all operations.

      Now the driver:

      .. literalinclude:: hw9_p2_test_vector3d.cpp
         :language: c++
         :caption: ``test_vector3d.cpp``

3. *Temperature logger* : Let's write a class called
   ``TemperatureLog`` that stores measurements of temperature at
   different times.  Here's how you should construct it:

   * The member data will be a ``vector`` of ``TemperatureReading``, which is
     defined as:

     .. code:: c++

        struct TemperatureReading {
            double time;
            double temp;
        };

     You can create this member data as:

     .. code::

        std::vector<TemperatureReading> log;

   * The constructor will take no arguments.  You would create a log just as:

     .. code::

        TemperatureLog tlog;

     and it will hold no data initially.

   * A member function ``add_data`` will be used to add a (time, temperature)
     pair.  You can have it take each quantity as a separate argument or
     write it to take a ``TemperatureReading`` object.

   Next you will add 3 member functions that act of the data:

   * The function ``mean()`` will return the average temperature.

   * The function ``max()`` will return the maximum temperature.

   * The function ``time_of_max()`` will return the time when the maximum
     temperature was reached.

   For these, you can use the ranges libraries or explicitly loop over the
   elements of ``log``.

   Finally, write a driver / ``main()`` that creates a ``TemperatureLog`` and adds the following
   and adds the following data:

   ======  ===========
    time   temperature
   ======  ===========
    10        75
    15        68
    22        79
    40        85
    49        96
    55        88
    62        78
    70        71
    76        62
   ======  ===========

   and uses your functions to output:

   * the average temperature
   * the maximum temperature
   * the time of the maximum temperature

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      First the header file.  Here's a version that uses the standard library
      algorithms:

      .. literalinclude:: temperature_logger.H
         :language: c++
         :caption: ``temperature_logger.H``

      Some notes:

      * I use ``std::accumulate`` and ``std::ranges::max_element`` here.  For
        ``std::ranges::max_element``, we get an iterator, and need to dereference it
        to get the value it points to.

      * For the ``time_of_max`` function, I first call the ``max()`` function.  Then
        I use ``std::ranges::find_if`` with a lambda function that looks for the element
        whose temperature matches the max temperature.

      If instead you wanted to explicitly loop over the elements of our log, here's
      a version of the header that does that;

      .. literalinclude:: temperature_logger_loops.H
         :language: c++
         :caption: ``temperature_logger_loops.H``

      Now the driver:

      .. literalinclude:: hw9_p3_test_temp_log.cpp
         :language: c++
         :caption: ``test_temp_log.cpp``
