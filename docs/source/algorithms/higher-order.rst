***************************
Higher-order Approximations
***************************

The derivative we just considered is first-order accurate.  If we cut
$\Delta x$ in half, our error drops by a factor of 2 (at least until
roundoff error dominates).


.. _sec:centered-diff:

Centered-difference approximation
=================================

.. note::

   Higher-order here means better truncation error, not a higher (e.g. second) derivative.

Let's look back at our difference approximation, but now consider Taylor expanding
$f(x_0 + \Delta x)$ and $f(x_0 - \Delta x)$:

.. math::

   f(x_0 + \Delta x) = f(x_0) + \left . \frac{df}{dx} \right |_{x_0} \Delta x +
                                \frac{1}{2} \left . \frac{d^2f}{dx^2} \right |_{x_0} \Delta x^2 +
                                \mathcal{O}(\Delta x^3)

.. math::

   f(x_0 - \Delta x) = f(x_0) - \left . \frac{df}{dx} \right |_{x_0} \Delta x +
                                \frac{1}{2} \left . \frac{d^2f}{dx^2} \right |_{x_0} \Delta x^2 -
                                \mathcal{O}(\Delta x^3)

Now, if we subtract these, we get:

.. math::

   f(x_0 + \Delta x) - f(x_0 - \Delta x) = 2 \left . \frac{df}{dx} \right |_{x_0} \Delta x + \mathcal{O}(\Delta x^3)

Notice that the $\Delta x^2$ term cancels out.  Now solving for the
first derivative, we have:

.. math::

   \left . \frac{df}{dx} \right |_{x_0} = \frac{f(x_0 + \Delta x) - f(x_0 - \Delta x)}{2  \Delta x}  + \mathcal{O}(\Delta x^2)

We see that this is second-order accurate.  This is sometimes called a
*centered-difference*.
