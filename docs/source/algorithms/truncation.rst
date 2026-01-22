*****************************
Roundoff vs. truncation error
*****************************

Consider the Taylor expansion of :math:`f(x)` about some point :math:`x_0`:

.. math::

   f(x) = f(x_0 + \Delta x) = f(x_0) + \left . \frac{df}{dx} \right |_{x_0} \Delta x + \mathcal{O}(\Delta x^2)

where :math:`\Delta x = x - x_0`

We can solve for the derivative to find an approximation for the first derivative:

.. math::

   \left . \frac{df}{dx} \right |_{x_0} = \frac{f(x_0 + \Delta x) - f(x_0)}{\Delta x} + \mathcal{O}(\Delta x)

This shows that this approximation for the derivative is first-order accurate in :math:`\Delta x`---that is the truncation error of the approximation.

We can see the relative size of roundoff and truncation error by using this approximation
to compute a derivative for different values of :math:`\Delta x`:

.. literalinclude:: ../../../examples/floating_point/truncation_vs_roundoff.cpp
   :language: c++
   :caption: ``truncation_vs_roundoff.cpp``

It is easier to see the behavior if we make a plot of the output:

.. figure:: error_plot.png
   :align: center
   :width: 80%

Let's discuss the trends:

* Starting with the largest value of :math:`\Delta x`, as
  we make :math:`\Delta x` smaller, we see that the error decreases.
  This is following the expected behavior of the truncation error
  derived above.

* Once our :math:`\Delta x` becomes really small, roundoff error starts
  to dominate.  In effect, we are seeing that:

  .. math::

     (x_0 + \Delta x) - x_0 \ne 0

  because of roundoff error.

* The minimum error here is around :math:`\sqrt{\epsilon}`, where :math:`\epsilon` is
  machine epsilon.

