.. _planetary_orbit:

************************
Example: Planetary Orbit
************************

Let's consider an example of integrating the orbit of Earth around the
Sun (we'll consider the mass of the Earth to be tiny compared to the
Sun so we can neglect the Sun's motion around the center of mass).

`Kepler's third law <https://en.wikipedia.org/wiki/Kepler%27s_laws_of_planetary_motion>`_ tells us:

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

.. important::

   This is 4 first-order ordinary differential equations, so we need 4
   initial conditions.

We want to evolve the orbit of Earth around the Sun using these ODEs.

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

This corresponds to the "array-of-structs" storage scheme we discussed in our :ref:`sec:vec-of-struct` section.


To make our code flexible, we'll write the following functions:

* A righthand side function, that takes an ``OrbitState`` and returns
  an ``OrbitState``:

  .. code:: c++

     OrbitState rhs(const OrbitState& state);

  We can compute all of the ODE righthand sides from the input state
  and then return the derivatives using an ``OrbitState`` (there, each
  component will actually be the derivative in time).

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

  An important parameter here is ``dt``---the size of our timestep.  We'll
  see that it has a large influence on the quality of our solution.

Implementation
==============

Here's our implementation:

.. literalinclude:: ../../../examples/numerical_algorithms/ODEs/orbit_example.cpp
   :language: c++
   :caption: ``orbit_example.cpp``

Some notes:

* We make ``GM`` a ``const``, since it should not change.

* In our ``integrate`` function, we create an ``OrbitState`` named ``state``.
  This will hold the current state at the start of each step / loop iteration,
  and be advanced to the new time at the end of the loop iteration.

  Note that when we do:

  .. code:: c++

     orbit_history.push_back(state);

  We are making a copy of ``state`` and storing it in our ``orbit_history`` vector.

* We have a check to ensure that the last step does not take us past
  the maximum time we want to evolve for:

  .. code:: c++

     if (state.t + dt > tmax) {
         dt = tmax - state.t;
     }

Running
=======

This is set up for Earth (the semi-major axis is 1 AU), and to
integrate for 1 year.  After this time, the Earth should be right back
where it started.  Any difference in the final position from the initial
position is integration error.

From our method, we expect that the error will decrease by a factor of 2 each time
we cut the timestep in half.

We control is the timestep.  Our default, ``dt = 0.05`` corresponds to
1/20th of a year.  The main question is---how small does our timestep
need to be to get an acceptable solution?

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

   set size ratio -1
   set xlabel "x"
   set ylabel "y"
   plot 'orbit.dat' using 2:3 notitle w l

This will make something like:

.. figure:: orbit.png
  :align: center
  :width: 80%
  :alt: the GNUplot output window showing the orbit (plotting y vs x).  It should be a circle, but instead it really moves far from the center as it orbits.

.. tip::

   We used a new gnuplot command here:

   .. prompt::
      :prompts: gnuplot>

      set size ratio -1

   This ensures that the aspect ratio of the coordinates is preserved
   (so a circle will appear as a circle in our plot).

You can save the plot as:

.. prompt::
   :prompts: gnuplot>

   set term png enhanced
   set output "orbit.png"
   replot


Look how bad this is!!!

We should have a nice circular orbit, but it goes way off a circle and
out to much greater distances in the solar system.

The problem here is that our timestep is too large---truncation
error is dominating.

.. admonition:: try it...

   Let's see how the solution behaves as we cut the timestep.

