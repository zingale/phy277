Extending our Solar System Class
=================================

Let's make our class more useful.  Lets implement the following functions:

.. code:: c++

   Planet* get_planet(const std::string& name);

This will take the name of a planet, and if it exists
in our ``SolarSystem``, it will return a pointer to the ``Planet``.
If the planet does not exist, then the pointer will be ``nullptr``.

.. code:: c++

   double get_period(const std::string& name);

This will take a planet ``name`` and compute and return its
period.

Implementation
--------------

Here's our updated class:

.. literalinclude:: ../../../examples/classes/solar_better_2/solar_system.H
   :language: c++
   :caption: new ``solar_system.H``

Some notes:

* We've rewritten our ``add_planet`` check on whether the planet
  already exists to use `std::ranges::any_of
  <https://en.cppreference.com/w/cpp/algorithm/ranges/all_any_none_of.html>`_.
  This will return ``true`` if we already have a planet with that
  name.  This makes the code more compact.

  We use a lambda-function here.

* Our ``get_planet`` function uses `std::ranges::find_if
  <https://en.cppreference.com/w/cpp/algorithm/ranges/find.html>`_ to
  find the planet with the name we provide.  This returns an iterator
  that points to the planet.  If the planet does not exist, then the
  iterator will point to one-past the last element, ``planets.end()``.

  We want to return a pointer to the ``Planet`` in the vector, and not the
  iterator, so we do:

  .. code:: c++

     return &(*it);

  This first dereferences the iterator, ``*it``, to get the underlying
  ``Planet``, and then it takes the address of that, using the ``&``
  operator.

  If the planet does not exist, then we return ``nullptr``.

Driver
------

Here's a driver using our new implementation:

.. literalinclude:: ../../../examples/classes/solar_better_2/test_solar_system.cpp
   :language: c++
   :caption: new ``test_solar_system.cpp``


.. admonition:: try it...

   Let's use our ``get_planet`` function to get a pointer to one of
   the planets, and then print its properties using the ``<<``
   operator.  We need to remember to dereference the pointer in this
   case.
