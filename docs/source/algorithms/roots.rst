************
Root Finding
************

Given a function :math:`f(x)`, the *root-finding* problem is to find
all of the :math:`x` such that :math:`f(x) = 0`.

Root finding algorithms often need a range that bracket the root,
:math:`x_0`, i.e. :math:`x_0 \in [x_l, x_r]`.

Notice that (for most functions) near :math:`f(x) = 0`, :math:`f(x)` changes sign,
so often we will check that :math:`f(x_l) \cdot f(x_r) < 0`.

.. figure:: newton-basins.png
   :align: center
   :alt: A function that crosses y=0 three times.

There are a large number of `root finding algorithms <https://en.wikipedia.org/wiki/Root-finding_algorithms>`_.

Bisection
=========

Bisection works by iteratively cutting the range where the root is located in half.
The basic idea is as follows:

* Iterate until error is small:

  * Compute :math:`f_l = f(x_l)` and :math:`f_r = f(x_r)`

  * Define :math:`x_m = (x_l + x_r) / 2` and :math:`f_m = f(x_m)`

  * If :math:`f_l \cdot f_m < 0` then the :math:`x_0 \in [x_l, x_m]`, so define :math:`x_r = x_m`;
    otherwise set :math:`x_l = x_m`

  * Define the error as $|x_r - x_l|$

Here's an animation of bisection finding a root:

.. figure:: bisection.gif
   :align: center
   :alt: An animation of bisection finding the zero of a parabola.

Here's an implementation:

.. literalinclude:: ../../../examples/numerical_algorithms/roots/bisection.cpp
   :language: c++
   :caption: ``bisection.cpp``

A few features:

* We use a ``namespace`` to hold the parameters that affect the
  behavior of the root finding algorithms.  This ensures that if we
  ``#include`` another header file that defines a variable ``ATOL``, ``RTOL``, or ``MAX_ITER``,
  that it does not clash with our versions.

  .. tip::

     A `namespace <https://en.cppreference.com/w/cpp/language/namespace.html>`_ can be
     used to put a number of orbits or functions into their own scope.  You can then
     access them using the scope operator ``::``.  This is a way to group together
     related concepts and makes the code easier to read.

  This is not required here, but it does help organize our code better.

* We use both a relative and absolute tolerance for assessing the error.  Convergence
  is met when:

  .. math::

     \epsilon < \mathrm{RTOL} |x_0| + \mathrm{ATOL}

  This ensures that if the current estimate of the root, :math:`x_0`,
  is close to zero then :math:`\mathrm{ATOL}` is used but if the root
  :math:`x_0` is large, then :math:`\mathrm{RTOL}` use used for the
  error.

* We have a maximum number of iterations, ``Roots::MAX_ITER``, after which
  we exit with an error.  This ensures we don't get stuck in an infinite
  loop if something goes wrong.

Bisection is slow to converge---it only reduces the error by a factor of 2 each iteration.

.. note::

   Bisection will fail to find the root for :math:`f(x) = x^2`.


Newton's method
===============

For `Newton's method
<https://en.wikipedia.org/wiki/Newton's_method>`_, we start by Taylor
expanding the function about some initial guess for the root,
:math:`x_0`:

.. math::

   f(x_0 + \delta x) \approx f(x_0) + \left . \frac{df}{dx} \right |_{x_0} \delta x + ~ ...

if :math:`x_0` is close to the actual root, then :math:`\delta x` is a correction that
will bring it closer to the actual root, and the higher order terms in this expansion
will be small, so we can neglect them.  This tells us that the correction is:

.. math::

   \delta x = -\frac{f(x_0)}{df/dx|_{x_0}}

Then we can correct our guess:

.. math::

   x_0 \leftarrow x_0 + \delta x

and iterate on this procedure until :math:`|\delta x|` is small.

Here's an animation showing the method converging:

.. figure:: newton.gif
   :align: center
   :alt: An animation of Newton's method finding the root of a function.

There are a few things to note here:

* The initial guess needs to be good---if it is not, then the higher
  order terms, which start with :math:`\delta x^2` are not small, and
  we should not have neglected them.

* We need a good estimate of the derivative.  Ideally this means that we
  supply a function that computes the derivative analytically.

* Newton's method can fail in a variety of ways, including `entering a cycle <https://en.wikipedia.org/wiki/Newton's_method#Oscillatory_behavior>`_.

.. note::

   If we don't have an analytic form of the derivative, then we can compute it via
   finite-differences.   This can give rise to the `secant method <https://en.wikipedia.org/wiki/Secant_method>`_.

Here's an implementation:

.. literalinclude:: ../../../examples/numerical_algorithms/roots/newton.cpp
   :language: c++
   :caption: ``newton.cpp``


