*****************
Numerical Library
*****************

Standard math functions are provided by the `C++ numerics library
<https://cplusplus.com/reference/cmath/>`_ which are accessed through
the ``<cmath>`` header.

This provides math functions like $\sin(x)$

.. important::

   Trigonometric functions like $\sin(x)$ expect their arguments to be
   in radians.

For raising numbers to a power, e.g., $x^y$, we use the
``std::pow()`` function.  This differs a bit from some languages
which have an operator for exponentiation, like ``x**y``.

Let's look at some examples.


Sine of angle in degrees
========================

Here's an example of:

* initializing an angle in degrees
* converting the angle to radians
* computing the sine of the angle in radians

.. literalinclude:: ../../../examples/floating_point/sine.cpp
   :language: c++
   :caption: sine.cpp


Powers
======

In addition to ``std::pow()``, there are some functions for common powers,
like ``std::sqrt()`` for $x^{1/2}$, and ``std::cbrt()`` for $x^{1/3}$.
These tend to be faster than using ``std::pow()``.

.. literalinclude:: ../../../examples/floating_point/power.cpp
   :language: c++
   :caption: power.cpp

Exponential and logs
====================

Let's look at some examples of exponentiation and logarithms.

.. important::

   ``std::log()`` is the natural logarithm.  For common
   logarithm (base-10), use ``std:log10()``.

.. literalinclude:: ../../../examples/floating_point/exp_log.cpp
   :language: c++
   :caption: exp_log.cpp

Absolute value
==============

.. caution::

   You may see some examples on the internet that add the
   line

   .. code:: c++

      using namespace std;

   and then access functions without the ``std::`` namespace.

   This can be dangerous, since you might not get the function
   you intend from the C++ standard library.

   This can be especially dangerous with ``std:abs()``.

.. literalinclude:: ../../../examples/floating_point/absolute.cpp
   :language: c++
   :caption: absolute.cpp




