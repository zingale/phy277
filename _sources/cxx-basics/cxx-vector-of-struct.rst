*****************
Vector of Structs
*****************

Let's look at a program that stores the basic properties for the
planets in our solar system and then loops over them and computes
their orbital period using Kepler's third law:

.. math::

   \left ( \frac{P}{\mathrm{year}} \right )^2 = \left ( \frac{a}{\mathrm{AU}} \right )^3

.. literalinclude:: ../../../examples/structs/struct_example.cpp
   :language: c++
   :caption: ``struct_example.cpp``

Some notes:

* We will use a vector of our ``struct``:

  .. code:: c++

     std::vector<Planet> planets;

  This is no different than when we made vectors of ``double`` or other types.
  We still index it the same and the same member functions can be used.

* We put the definition of ``Planet`` outside of the ``main()`` function.

* In the initialization of the ``planets`` vector, we use
  list-initialization for each of the planets in its own set of
  ``{}``.

* Notice that our vector ``planets`` is ``const``.  This means that we
  cannot add to it (e.g., via ``.push_back()``).


.. note::

   As mentioned above, a ``class`` is very similar to a ``struct`` in
   C++.  The main difference is that in a ``struct`` all of the
   members are publicly accessible while in a ``class``, they are
   private unless we make them public.

.. note::

   A common consideration when organizing data that is associated
   together is whether to do a struct-of-arrays or an
   array-of-structs.  See this discussion on `AoS and SoA
   <https://en.wikipedia.org/wiki/AoS_and_SoA>`_.

   In our planet example above, we created an array of structs.  This
   is a natural organization if we want to loop over planets and
   access their data individually.


