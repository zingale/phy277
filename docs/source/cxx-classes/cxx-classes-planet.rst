Example: Solar System Class
===========================

Let's build on our vector of planets (from :ref:`sec:vec-of-struct`),
but now make a class/struct that holds the data and member functions
that know how to operate on that data.

First well define the ``struct`` called ``SolarSystem`` and write the
constructor:

.. literalinclude:: ../../../examples/classes/solar/solar_system.H
   :language: c++
   :caption: ``solar_system.H``

Keeping with our strategy to reuse code, this uses our ``planet.H``
header from before (and will rely on the ``planet.cpp`` source file
that implemented some functions).

Some notes:

* After the constructor name and arguments there is a ``:`` and an
  initialization:

  .. code:: c++

     SolarSystem(const double mass)
       : star_mass{mass}
     {
        ...

  this is called the *initialization list*.  Any member data specified
  in that (comma-separated) list is initialized when an object is
  created as an instance of the class.

* In the constructor body we have an ``assert()`` statement---this
  will abort the code if it is false.  This is a way to add runtime
  checking to the code to ensure that it is being used properly /
  matching your assumptions.

* We end with some forward declarations of *member functions* of the
  class.  These functions will have access to the class data directly.

To *instantiate* the class, i.e., create a ``SolarSystem`` object, we would do:

.. code:: c++

   SolarSystem ss(1.0);

where we pass the constructor arguments at the time we create our object.

.. note::

   A class can have multiple constructors.  A constructor that takes
   no arguments is called the *default constructor*.

We provide implementations of the member functions in a separate file:

.. literalinclude:: ../../../examples/classes/solar/solar_system.cpp
   :language: c++
   :caption: ``solar_system.cpp``


Notes:

* For each of the member functions, since we are defining them outside
  of the ``struct SolarSystem {};``, we need to include the namespace
  and scope operator, ``::``, to reference the class that they belong
  to.

* Our ``add_planet()`` member function checks to see if a planet already exists.

Finally, we can use our ``SolarSystem`` class.  Here's a ``main()`` function:

.. literalinclude:: ../../../examples/classes/solar/test_solar_system.cpp
   :language: c++
   :caption: ``test_solar_system.cpp``

We can compile this using the same general ``GNUmakefile`` we developed previously.  We'll
add two features to it:

.. literalinclude:: ../../../examples/classes/solar/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

The first is a new target: ``clean``.  By doing

.. prompt:: bash

   make clean

We will remove all of the object files (``*.o``) and the executable.

The second new feature is the addition of some compilation flags:

.. code:: make

   CFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g

These are specific to the GNU compilers, and turn on some warnings
that help spot code mistakes.  See `GCC warning options
<https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>`_ for more
details.

The main advantage to using a class here is that we don't need to know
how the planet data is actually stored (in this case in a
``std::vector<Planet>``).  By creating member functions that are part
of the class, we hide the implementation details from the user.
Instead they are given a simple set of functions to interact with the
data.
