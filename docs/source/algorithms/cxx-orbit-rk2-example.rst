.. _sec:rk2-orbit:

***************************
2nd-order Runge-Kutta Orbit
***************************

The main utility of functions is that we can reuse them in a code.
Let's look at this by extending our Euler integration of an orbit
to do 2nd-order `Runge-Kutta <https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods>`_ integration.

The Euler method was based on a first-order difference approximation
to the derivative.  But a centered-difference approximation to $df/dt$
is second order accurate at the midpoint in time, so we can try to
update our system in the form:

$$\frac{{\bf r}^{n+1} - {\bf r}^n}{\tau} = {\bf v}^{n+1/2} + \mathcal{O}(\tau^2)$$

$$\frac{{\bf v}^{n+1} - {\bf v}^n}{\tau} = {\bf a}^{n+1/2} + \mathcal{O}(\tau^2)$$

Then the updates are:

$${\bf r}^{n+1} = {\bf r}^n + \tau \, {\bf v}^{n+1/2} + \mathcal{O}(\tau^3)$$

$${\bf v}^{n+1} = {\bf v}^n + \tau \, {\bf a}^{n+1/2} + \mathcal{O}(\tau^3)$$

This is locally third-order accurate (but globally second-order
accurate), but we don't know how to compute the state at the
half-time.

To find the $n+1/2$ state, we first use Euler's method to predict the
state at the midpoint in time.  We then use this provisional state to
evaluate the accelerations at the midpoint and use those to update the
state fully through $\tau$.

The two step process appears as:

$${\bf r}^\star = {\bf r}^n + (\tau / 2) {\bf v}^n$$

$${\bf v}^\star = {\bf v}^n + (\tau / 2) {\bf a}^n$$

then we use this for the full update:

$${\bf r}^{n+1} = {\bf r}^n + \tau \,  {\bf v}^\star$$

$${\bf v}^{n+1} = {\bf v}^n + \tau \, {\bf a}({\bf r}^\star)$$


Graphically this looks like the following:

First we take a half step and we evaluate the slope at the midpoint:

.. figure:: rk2_halfEuler.png
   :align: center
   :width: 90%
   :alt: An illustration of the first step of integration with 2nd-order Runge-Kutta.  Here we follow the initial slope for a half-step to the midpoint of the interval.

   The predictor part of RK2 integration.

.. figure:: rk2_final.png
   :align: center
   :width: 90%
   :alt: The second step of 2nd-order Runge-Kutta.  This illustrates how we follow the slope evaluated at the midpoint in the first step through the full timestep.

   The corrector / final update of RK2 integration.

Notice how the final step (the red line) is parallel to the slope we
computed at $t^{n+1/2}$.  Also note that the solution at $t^{n+1}$ is
much closer to the analytic solution than in the figure from Euler's
method.

This method is called 2nd-order Runge-Kutta.

Implementation
==============

To implement this, it would be nice to have a function that updates
the state based on the derivatives, like:

.. code:: c++

   OrbitState update_state(const OrbitState& state, const double dt,
                           const OrbitState& state_derivs);

This way we can easily do the update both times as needed via a simple function call.

.. tip::

   Later we'll learn how to use operator overloading to do something like:

   .. code:: c++

      OrbitState state{};
      double dt{};
      OrbitState state_derivs{};

      ...

      auto state_new = state + dt * state_derivs;



Our implementation looks largely the same as the first-order method:

.. literalinclude:: ../../../examples/numerical_algorithms/ODEs/orbit_rk2_example.cpp
   :language: c++
   :caption: ``orbit_rk2_example.cpp``

The main difference is that we compute an intermediate solution at the half-time:

.. code:: c++

   // get the derivatives at the midpoint in time
   auto state_star = update_state(state, 0.5 * dt, state_derivs);
   state_derivs = rhs(state_star);

This makes the final update time-centered, and gives us second-order accuracy.

When run with ``dt = 0.05``, we get:

.. figure:: orbit_rk2.png
  :align: center
  :width: 80%
  :alt: our orbit (y vs. x).  It is almost a complete circle.

We see that this is *far* better than the first-order Euler method.  It is
still not perfect, but as we cut the timestep, the solution should
improve much faster than the Euler case.

Error estimate
==============

We can estimate the error by computing the initial distance from the
Sun and comparing to the final distance from the Sun.  The orbit is
circular, so it should be constant.


.. admonition:: try it...

   Let's write an error function of the form:

   .. code:: c++

      double error(const std::vector<OrbitState>& history)

   that computes this error, and the output the error at the end of
   integration for a variety of timestep sizes.

   .. dropdown:: solution

      Here's a version of the code with the error function and a loop in the ``main``
      function that explores different timestep sizes.

      .. literalinclude:: ../../../examples/numerical_algorithms/ODEs/orbit_rk2_error.cpp
         :language: c++
         :caption: ``orbit_rk2_error.cpp``


      When this is run, we get:

      ::

          0.10000    0.0116001
          0.05000    0.0111227
          0.02500   0.00247085
          0.01250  0.000360686
          0.00625  4.69261e-05

      For very coarse ``dt``, we have a large error, but once ``dt`` is below ``0.05``,
      we see that the solution is converging 2nd-order or better.

      .. note::

         Comparing the starting and ending radius is just one error
         measure.  We could also consider the distance between the
         initial and final positions or the total energy of the
         system.  Each of these should converge 2nd order once the
         timestep is small enough.

