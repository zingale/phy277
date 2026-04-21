***************************
Example: Solar System Class
***************************

Let's build on our vector of planets (from :ref:`sec:vec-of-struct`),
but now make a class/struct that holds the data and member functions
that know how to operate on that data.

Implementation
==============

First well define the ``struct`` called ``SolarSystem`` and write the
constructor:

.. literalinclude:: ../../../examples/classes/solar/solar_system.H
   :language: c++
   :caption: ``solar_system.H``

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

  .. note::

     In this simple example, we really did not need to use an initialization list, but there
     are situations when it is desired or even required:

     * if any of our member data is ``const`` or a reference.

     * if we have other classes as our member data (including things like ``std::vector``)
       and initializing them involves some overhead.  It can be faster to do the initialization
       via the initialization list.

     See the stack overflow `Why should I prefer to use member
     initialization lists?
     <https://stackoverflow.com/questions/926752/why-should-i-prefer-to-use-member-initialization-lists>`_
     discussion.


* In the constructor body we have an ``assert()`` statement---this
  will abort the code if it is false.  This is a way to add runtime
  checking to the code to ensure that it is being used properly /
  matching your assumptions.

* We implement the member functions directly in the header.  They are
  small, so there doesn't seem to be a need to break them out into
  a separate ``.cpp`` file.

* Our ``add_planet()`` member function checks to see if a planet
  already exists.

This uses ``planet.H`` header from before:

.. literalinclude:: ../../../examples/classes/solar/planet.H
   :language: c++
   :caption: ``planet.H``


To *instantiate* the class, i.e., create a ``SolarSystem`` object, we would do:

.. code:: c++

   SolarSystem ss(1.0);

where we pass the constructor arguments at the time we create our object.

Driver
======

Finally, we can use our ``SolarSystem`` class.  Here's a ``main()`` function:

.. literalinclude:: ../../../examples/classes/solar/test_solar_system.cpp
   :language: c++
   :caption: ``test_solar_system.cpp``

The main advantage to using a class here is that we don't need to know
how the planet data is actually stored (in this case in a
``std::vector<Planet>``).  By creating member functions that are part
of the class, we hide the implementation details from the user.
Instead they are given a simple set of functions to interact with the
data.

Building
========

We can compile this using the same general ``GNUmakefile`` we
developed previously.  We'll add two features to it:

.. literalinclude:: ../../../examples/classes/solar/GNUmakefile
   :language: make
   :caption: ``GNUmakefile``

The first is a new target: ``clean``.  By doing

.. prompt:: bash

   make clean

We will remove all of the object files (``*.o``) and the executable.

The second new feature is the addition of some compilation flags:

.. code:: make

   CFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g -std=c++20

We saw these in our :ref:`sec:compiler-flags` discussion.

