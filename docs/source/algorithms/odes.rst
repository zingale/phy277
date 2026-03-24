*******************************
Ordinary Differential Equations
*******************************

Consider an ordinary differential equation,

.. math::

   \frac{dy}{dt} = f(y)

To solve this we need some initial conditions, $y(t = 0) = 0$.

To advance this system, we can use a finite difference approximation
for the time-derivative:

.. math::

   \frac{y^{n+1} - y^n}{\tau} = f(y^n)

where $y^n$ means $y(t = t^n)$ and $y^{n+1}$ means $y(t = t^n + \tau)$
where $\tau$ is the *timestep* that we use to advance the system.

To evolve the system for a long time, we take many steps of size $\tau$.

The new solution is then:

.. math::

   y^{n+1} = y^n + \tau f(y^n) + \mathcal{O}(\tau^2)

This method is called Euler's method.

This shows that each time we take a step, we make an error (called
*truncation error*) of :math:`\mathcal{O}(\tau^2)`.  Over the course
of the orbit we will take :math:`N = T / \tau` steps, so the global
error will be :math:`\mathcal{O}(\tau)`.

Visually, our method looks like:

.. figure:: rk2_Euler.png
   :align: center
   :width: 90%
   :alt:  A plot of an exponential function with a point marked as the starting point for integration (labelled y^n).  A straight line follows the initial slope to the new time, giving the point y^{n+1} which is well below the analytic value of the function at that time.

We evaluate the derivative at the start of the timestep and follow
that slope to the new time.  As shown in the figure, the error in this
method is the difference between the true solution (black line) and
the data point at the new time, $y^{n+1}$.
