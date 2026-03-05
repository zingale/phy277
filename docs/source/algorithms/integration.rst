***********
Integration
***********

In calculus, you saw a definition of a definite integral that looked
something like:

$$I \equiv \int_a^b f(x) dx = \lim_{\Delta x \rightarrow 0} \sum_{i = 1}^N f(x_i) \Delta x$$

where the number of intervals you divide $[a, b]$ into, $N$, is
defined such that $N = (b -a) / \Delta x$.

Also recall that this definition is directly related to the
interpretation of an *integral representing the area under a curve*.

Rectangle rule
==============

The simplest way to compute the integral is to treat each interval as a rectangle:

.. figure:: rectangle_N6.png
   :alt: dividing the area under a curve into 6 intervals, each represented as a rectangle
   :align: center
   :width: 80%

   The rectangle rule---we divide the area under the curve into intervals ($N = 6$ shown here)
   and represent each as a rectangle.

Adding up the area of each rectangle, we have an approximation to the integral:

$$\int_a^b f(x) dx = {\Delta x} \sum_{i=0}^{N-1} f_i + \mathcal{O}(\Delta x)$$

Trapezoid rule
==============


.. figure:: trapezoid_N6.png
   :alt: dividing the area under a curve into 6 intervals, with the left and right function values connected by a line, making each interval a trapezoid.
   :align: center
   :width: 80%

   The trapezoid rule---again using $N = 6$, we connect the left and right function values for each interval,
   making trapezoids.


$$\int_a^b f(x) dx = \frac{\Delta x}{2} \sum_{i=0}^{N-1} (f_i + f_{i+1}) + \mathcal{O}(\Delta x^2)$$
