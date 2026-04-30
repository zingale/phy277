.. _sec:simpsons-rule:

**************************************
High-order Integration: Simpson's Rule
**************************************

One of the most popular methods of numerical integration is `Simpson's
rule <https://en.wikipedia.org/wiki/Simpson%27s_rule>`_.

In the rectangle rule we used a constant in each interval.  In the
trapezoid rule, we used a line.  In Simpson's rule, we use a parabola.
Since we need 3 points for a parabola, we need to use 2 intervals at a
time.

Visually, this appears as:

.. figure:: simpsons_N6.png
   :alt: dividing the area under a curve into 6 intervals, and fitting a parabola to 3 pairs of intervals
   :align: center
   :width: 80%


Derivation
==========

To derive Simpson's rule, we would choose a parabola of the form:

$$f(x) = a (x - x_0)^2 + b (x - x_0) + c$$

and we fit it to 3 points: $(x_0, f_0)$, $(x_1, f_1)$, $(x_2, f_2)$, where we assume
that these are equally spaced, $x_1 = x_0 + \Delta x$ and $x_2 = x_1 + \Delta x$.

Then evaluating it at the 3 points we have:

.. math::

   f_0 = c

.. math::

   f_1 = a \Delta x^2 + b\Delta x + c

.. math::

   f_2 = 4 a \Delta x^2 + 2 b \Delta x + c

This can be solved analytically to get:

.. math::

   f(x) = \frac{f_0 - 2 f_1 + f_2}{2 \Delta x^2} (x - x_0)^2
      + \frac{-3 f_0 + 4 f_1 - f_2}{2 \Delta x} (x - x_0) + f_0

and then we can integrate this from $[x_0, x_2]$ or equivalently
$[x_0, x_0 + 2 \Delta x]$, giving:

$$\frac{\Delta{}x \left(f_{0} + 4 f_{1} + f_{2}\right)}{3}$$

Looping over N/2 intervals (and considering a pair at a time), we get:

$$\int_a^b f(x) dx = \frac{\Delta x}{3} \sum_{i = 0}^{N/2-1} (f_{2i} + 4 f_{2i+1} + f_{2i+2}) + \mathcal{O}(\Delta x^4)$$

Simpson's rule is 4th-order accurate.

.. important::

   If $N$ (the number of intervals) is odd, then you will have one
   interval left over.  You can extend Simpson's rule to consider
   a single remaining interval by integrating the parabola over only
   a single interval.

Implementation
==============

Here's an implementation of Simpson's rule, based on our ``trapezoid.cpp`` code:

.. literalinclude:: ../../../examples/numerical_algorithms/integration/simpsons.cpp
   :language: c++
   :caption: ``simpsons.cpp``

when run, this gives:

::

      N        I         error
         2    0.95833  8.99393e-03
         4    0.94970  3.64476e-04
         8    0.94936  2.07084e-05
        16    0.94934  1.26464e-06
        32    0.94934  7.85868e-08
        64    0.94934  4.90463e-09
       128    0.94934  3.06430e-10
       256    0.94934  1.91506e-11
       512    0.94934  1.19660e-12
      1024    0.94934  7.52731e-14
      2048    0.94934  5.66214e-15
      4096    0.94934  3.33067e-16
      8192    0.94934  2.22045e-15
     16384    0.94934  2.55351e-15


Notice:

* The errors are much better than the trapezoid rule when comparing
  the same number of intervals, $N$

* The error drops by a factor of 16 when we double the number of
  intervals---this is the $\mathcal{O}(\Delta x^4)$ convergence we
  expect from the truncation error.

* When we make the number of intervals really large, we eventually hit
  roundoff error, and we cannot improve the answer any further.
