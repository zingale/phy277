***************************
In-class: Second-Derivative
***************************

Let's investigate a second-derivative, $d^2f/dx^2$.  We can start with the same
Taylor expansions:

.. math::

   f(x_0 + \Delta x) = f(x_0) + \left . \frac{df}{dx} \right |_{x_0} \Delta x +
                                \frac{1}{2} \left . \frac{d^2f}{dx^2} \right |_{x_0} \Delta x^2 +
                                \mathcal{O}(\Delta x^3)

.. math::

   f(x_0 - \Delta x) = f(x_0) - \left . \frac{df}{dx} \right |_{x_0} \Delta x +
                                \frac{1}{2} \left . \frac{d^2f}{dx^2} \right |_{x_0} \Delta x^2 -
                                \mathcal{O}(\Delta x^3)

Now, instead of subtracting them, we add them:

.. math::

   f(x_0 + \Delta x) + f(x_0 - \Delta x) = 2 f(x_0)  + \left . \frac{d^2f}{dx^2} \right |_{x_0} \Delta x^2 + \mathcal{O}(\Delta x^4)

Notice that the $\Delta x$ and $\Delta x^3$ terms cancel out.  Now solving for the
second derivative, we have:

.. math::

   \left . \frac{d^2f}{dx^2} \right |_{x_0} = \frac{f(x_0 + \Delta x) - 2 f(x_0) + f(x_0 - \Delta x)}{\Delta x^2}  + \mathcal{O}(\Delta x^2)

We see that this is second-order accurate.

.. admonition:: try it...

   Let's code up the second derivative and test it on

   $$f(x) = x^4 + x^2 + 1$$

   This has the second derivative:

   $$f^{\prime\prime}(x) = 12 x^2 + 2$$

.. dropdown:: solution
   :color: muted
   :icon: pencil
   :animate: fade-in-slide-down

   .. literalinclude:: ../../../examples/numerical_algorithms/derivatives/second_derivative.cpp
      :language: c++
      :caption: ``second_derivative.cpp``

