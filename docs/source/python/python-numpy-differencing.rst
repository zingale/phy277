****************************
Finite-Differencing in NumPy
****************************

Recall from :ref:`sec:difference-first-derivative`, that
a second-order accurate approximation to the second-derivative
is:

.. math::

   \left . \frac{df}{dx} \right |_{x_0} = \frac{f(x_0 + \Delta x) - f(x_0 - \Delta x)}{2\Delta x} + \mathcal{O}(\Delta x^2)

We can compute the derivative of a function in NumPy that is sampled
as an array by simply using views that are shifted by one element.  In terms of array indices, $i$, this would be

.. math::

   \frac{dx}{dx} \sim \frac{f(x_{i+1}) - f(x_{i-1}))}{x_{i+1} - x_{i-1}}

Note that for an array with $N$ elements, we'll have $N-2$
derivatives, because we need an extra point on each end.

Here's the code:

.. literalinclude:: ../../../example/python/derivative.py
   :language: c++
   :caption: ``derivative.py``
