**************************
Derivatives and Truncation
**************************

Difference approximation to first derivative
============================================

Consider the Taylor expansion of :math:`f(x)` about some point :math:`x_0`:

.. math::

   f(x) = f(x_0 + \Delta x) = f(x_0) + \left . \frac{df}{dx} \right |_{x_0} \Delta x + \mathcal{O}(\Delta x^2)

where :math:`\Delta x = x - x_0`

We can solve for the derivative to find an approximation for the first derivative:

.. math::

   \left . \frac{df}{dx} \right |_{x_0} = \frac{f(x_0 + \Delta x) - f(x_0)}{\Delta x} + \mathcal{O}(\Delta x)

This shows that this approximation for the derivative is first-order
accurate in :math:`\Delta x`---that is the `truncation error
<https://en.wikipedia.org/wiki/Truncation_error_(numerical_integration)>`_
of the approximation.

.. note::

   We use `big-O notation <https://en.wikipedia.org/wiki/Big_O_notation>`_ here to indicate
   the truncation error.  By writing $\mathcal{O}(\Delta x)$, we are saying that there are
   terms of order $\Delta x$ that we are neglecting.  These indicates the leading term
   of the truncation error.

.. note::

   This is called a `finite-difference approximation
   <https://en.wikipedia.org/wiki/Numerical_differentiation#Finite_differences>`_ to the
   derivative.

Roundoff vs. truncation
=======================

We can see the relative size of roundoff and truncation error by using
this approximation to compute a derivative for different values of
:math:`\Delta x`:

.. literalinclude:: ../../../examples/floating_point/truncation_vs_roundoff.cpp
   :language: c++
   :caption: ``truncation_vs_roundoff.cpp``

Some notes about this code:

* We use a ``while`` loop, and continue to loop so long as ``dx`` is larger than
  machine epsilon.

* We are storing the absolute value of the error---we don't care about
  the sign here.

When we run this, we'll see:

::

             0.1    0.0429386
            0.05    0.0212575
           0.025    0.0105741
          0.0125    0.0052732
         0.00625   0.00263311
        0.003125   0.00131568
       0.0015625  0.000657619
      0.00078125  0.000328755
     0.000390625  0.000164364
     0.000195313  8.21783e-05
     9.76563e-05  4.10883e-05
     4.88281e-05  2.05439e-05
     2.44141e-05  1.02719e-05
      1.2207e-05  5.13594e-06
     6.10352e-06  2.56797e-06
     3.05176e-06    1.284e-06
     1.52588e-06  6.41936e-07
     7.62939e-07  3.20994e-07
      3.8147e-07  1.60632e-07
     1.90735e-07   8.0596e-08
     9.53674e-08  3.92685e-08
     4.76837e-08  1.94779e-08
     2.38419e-08   1.2493e-08
     1.19209e-08  3.17978e-09
     5.96046e-09  3.17978e-09
     2.98023e-09  1.54467e-08
     1.49012e-09  5.90591e-08
     7.45058e-10  5.90591e-08
     3.72529e-10  8.99525e-08
     1.86265e-10  8.99525e-08
     9.31323e-11  5.06094e-07
     4.65661e-11  5.06094e-07
     2.32831e-11  1.87809e-06
     1.16415e-11  1.87809e-06
     5.82077e-12  7.65865e-06
     2.91038e-12  1.14148e-05
     1.45519e-12  1.14148e-05
     7.27596e-13  1.14148e-05
     3.63798e-13  0.000141173
     1.81899e-13  0.000141173
     9.09495e-14  0.000469179
     4.54747e-14   0.00168988
     2.27374e-14   0.00319293
     1.13687e-14   0.00319293
     5.68434e-15   0.00657269
     2.84217e-15   0.00657269
     1.42109e-15    0.0715523
     7.10543e-16    0.0715523
     3.55271e-16    0.0846977


It is easier to see the behavior if we make a plot of the output:

.. figure:: error_plot.png
   :align: center
   :width: 80%
   :alt: A comparison of truncation error and roundoff error as dx is changed.

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

.. tip::

   For computing a finite-difference approximation to a derivative, $\Delta x$
   should be chosen such that $|\Delta x / x_0| \sim \sqrt{\epsilon}$.
