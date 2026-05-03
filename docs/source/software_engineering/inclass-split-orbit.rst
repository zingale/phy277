.. _orbit_split:

*********************************************
In-Class Example: Splitting Up Our Orbit Code
*********************************************

Let's go back to our :ref:`planetary_orbit` code and split it up into
a header and a ``.cpp`` file.

The header should define the ``OrbitState`` struct and use ``inline``
functions for the associated functions.  The ``main`` should be in its
own ``.cpp`` file.

.. dropdown:: solution
   :color: muted
   :icon: pencil
   :animate: fade-in-slide-down

    Here's our header file:

    .. literalinclude:: ../../../examples/orbits/orbit_split/orbit.H
       :language: c++
       :caption: ``orbit.H``

   and our driver:

    .. literalinclude:: ../../../examples/orbits/orbit_split/test_orbit.cpp
       :language: c++
       :caption: ``test_orbit.cpp``


