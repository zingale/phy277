Extending our Solar System Class
=================================

Let's make our class more useful.  Lets implement the following functions:

.. code:: c++

   int get_planet(const std::string& name, Planet& p_return);

   double get_period(const std::string& name);

The first will take a ``Planet`` in the argument list (by
reference) and if ``name`` exists, it will return its properties
through the reference.  The return value here is ``int`` and is
meant to return a status that we can check to see if the ``name``
was a valid planet.

The second will take a planet ``name`` and compute and return its
period.

.. dropdown:: solution

   The updated header is:

   .. literalinclude:: ../../../examples/classes/solar_better/solar_system.H
      :language: c++
      :caption: new ``solar_system.H``

   and corresponding functions:

   .. literalinclude:: ../../../examples/classes/solar_better/solar_system.cpp
      :language: c++
      :caption: new ``solar_system.cpp``

   and test driver:

   .. literalinclude:: ../../../examples/classes/solar_better/test_solar_system.cpp
      :language: c++
      :caption: new ``test_solar_system.cpp``


.. admonition:: try it...

   To understand the difference between a ``struct``, where everything is public, and
   a ``class`` where everything is private by default, let's edit ``solar_system.H``
   and change ``struct`` to ``class``.

   What happens when we compile?

   Now try adding a ``public:`` statement to the code.


.. tip::

   Instead of doing a ``get_planet()`` to return a copy of a planet from our
   solar system object, we can return an iterator using ``std::find_if()`` as:

   .. code:: c++

      std::vector<Planet>::iterator SolarSystem::find_planet(const std::string& name) {

          auto it = std::find_if(planets.begin(), planets.end(),
                                 [&] (const Planet& p) {return p.name == name;});

          return it;
      }

   Then we can do a check like:

   .. code:: c++

      auto it = find_planet("mars");
      if (it != planets.end()) {
          // planet already exists
      }

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
