.. _planetary_orbit:

************************
Example: Planetary Orbit
************************

Let's consider an example of integrating the orbit of Earth around the
Sun (we'll consider the mass of the Earth to be tiny compared to the
Sun so we can neglect the Sun's motion around the center of mass).

Kepler's third law tells us:

.. math::

   4\pi^2 a^3 = G M_\star P^2

where :math:`a` is the semi-major axis and :math:`P` is the period of the orbit.  If we work in
units of solar masses, astronomical units, and years, then this becomes:

.. math::

   a^3 = P^2

which implies that :math:`G M_\star = 4 \pi^2`.

The evolution of the planet is given by

.. math::

   \dot{\bf r} = {\bf v}

.. math::

   \dot{\bf v} = - \frac{G M_\star {\bf r}}{r^3}

where :math:`{\bf r} = (x, y)` and :math:`{\bf v} = (v_x, v_y)` are vectors.
This means that we have 4 equations overall to advance.

.. note::

   We use $\dot{y}$ as our notation for a time-derivative, $dy/dt$,

Euler's Method
==============

Using Euler's method, as we just learned, the solution begins with a
first-order accurate difference approximation to the derivative:

.. math::

   \frac{{\bf r}^{n+1} - {\bf r}^n}{\tau} = {\bf v}^n + \mathcal{O}(\tau)

.. math::

   \frac{{\bf v}^{n+1} - {\bf v}^n}{\tau} = {\bf a}({\bf r}^n,{\bf v}^n) + \mathcal{O}(\tau)

or

.. math::

   {\bf r}^{n+1} = {\bf r}^n + \tau {\bf v}^n + \mathcal{O}(\tau^2)

.. math::

   {\bf v}^{n+1} = {\bf v}^n + \tau {\bf a}({\bf r}^n,{\bf v}^n) + \mathcal{O}(\tau^2)


Implementation
==============

We'll store the state of the solution at a single instance in time in a ``struct``:

.. code:: c++

   struct OrbitState {
       double t;
       double x;
       double y;
       double vx;
       double vy;
   };

and we'll save the solution at each step in a vector:

.. code:: c++

   std::vector<OrbitState> orbit_history{};

This corresponds to the "array-of-structs" storage scheme we discussed earlier.


To make our code flexible, we'll write the following functions:

* A righthand side function, with the forward declaration:

  .. code:: c++

     OrbitState rhs(const OrbitState& state);

  we can evaluate this as needed by passing in an ``OrbitState`` and
  returning the derivative of that state with respect to time.

  As we've seen a few times now, we pass this in as a ``const`` reference
  for performance.  The ``const`` ensures that it is read-only.

* A function to write out the history:

  .. code:: c++

     void write_history(const std::vector<OrbitState>& history);

  We can adapt this as desired to write to the screen or a file (which
  we'll see soon).

* An integration function:

  .. code:: c++

     std::vector<OrbitState> integrate(const double a,
                                       const double tmax, const double dt);

  This manages the time-stepping, implementing Euler's method and
  storing the solution in our history vector each step.  At the end of
  integration it will return the history.


Implementation
==============

Implement the solver by filling in the details of the functions
described above.

.. literalinclude:: ../../../examples/numerical_algorithms/ODEs/orbit_example.cpp
   :language: c++
   :caption: ``orbit_example.cpp``

Plotting
========

We can plot the solution using ``gnuplot``.

First, when you run, redirect the output to a file:

.. prompt:: bash

   ./orbit_example > orbit.dat

Now run ``gnuplot``:

.. prompt:: bash

   gnuplot

Again, we'll use ``plot`` and plot different columns against
one another:

.. prompt::
   :prompts: gnuplot>

   plot 'orbit.dat' using 2:3 w l
   set size square
   replot

This will make something like:

.. figure:: orbit.png
  :align: center
  :width: 80%
  :alt: the GNUplot output window showing the orbit (plotting y vs x).  It should be a circle, but instead it only completes about 90% of the circumference and the radius drifts slightly outward in the orbit.

You can save the plot as:

.. prompt::
   :prompts: gnuplot>

   set term png
   set output "orbit.png"
   replot


