Extending our Solar System Class
=================================

Let's make our class more useful.  Lets implement the following functions:

* ``get_planet(name)`` : This will take the name of a planet and
  return the ``Planet`` object.

  We have a choice of how we want to do this.

  * We can return a pointer to the ``Planet`` in the ``planets``
    vector.  This would look like:

    .. code:: c++

       Planet* get_planet(const std::string& name);

    This will take the name of a planet, and if it exists in our
    ``planets`` vector, it will return a pointer to the
    ``Planet``.  If the planet does not exist, then the pointer will
    be ``nullptr``.

  * We can return a reference to the ``Planet`` in the ``planets``
    vector.  This would look like:

    .. code:: c++

       Planet& get_planet(const std::string& name);

    This is similar to the pointer version, but we need to deal
    with the case where the planet is not found.  There is no
    ``nullptr`` equivalent for references---a reference must always
    refer to a valid object.  So we can adopt the convention that
    we return an empty ``Planet`` object, i.e., ``Planet{}``.

  * We can return a copy of the ``Planet`` in the ``planets``
    vector.  This would look like:

    .. code:: c++

       Planet get_planet(const std::string& name);

    We would still use an empty ``Planet`` for the case where
    the name is not found.

  .. important::

     The first two approaches (returning ``Planet*`` and ``Planet&``
     would allow a user to directly modify the data in the ``planets``
     vector via the return value.  This may not be what we want.
     In that case, we can add the ``const`` qualifier to the return
     type in the function definition to ensure that it cannot be used
     to modify the data.

   We'll take the second approach here (a reference), but we'll make it
   ``const``.  I'll also include an implementation that uses the pointer
   separately so you can compare, if desired.

* ``get_period(name)`` : This will take the name of the planet and compute
  its period using Kepler's laws.  If the planet doesn't exist, we'll have
  it return ``-1``.  This function will look like:

  .. code:: c++

     double get_period(const std::string& name);


Implementation
--------------

Here's our updated class:

.. literalinclude:: ../../../examples/classes/solar_reference/solar_system.H
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

.. literalinclude:: ../../../examples/classes/solar_reference/test_solar_system.cpp
   :language: c++
   :caption: new ``test_solar_system.cpp``


.. admonition:: try it...

   Let's use our ``get_planet`` function to get a pointer to one of
   the planets, and then print its properties using the ``<<``
   operator.  We need to remember to dereference the pointer in this
   case.
