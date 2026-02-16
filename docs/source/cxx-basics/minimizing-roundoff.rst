*******************
Minimizing Roundoff
*******************

Consider subtracting the square of two numbers---taking the difference
of two very close-in-value numbers is a prime place where roundoff can
come into play.

Instead of doing:

.. math::

   x^2 - y^2

we can instead do:

.. math::

   (x - y)(x + y)

by factoring this, we are subtracting more reasonably sized numbers, reducing the roundoff.

We can see this directly by doing this with single precision (`float`) and comparing to an answer computed via double precious (`double`)

Here's an example:

.. literalinclude:: ../../../examples/floating_point/subtraction.cpp
   :language: c++
   :caption: ``subtraction.cpp``


As another example, consider computing [#f1]_:

.. math::

   \sqrt{x + 1} - \sqrt{x}

We can alternately rewrite this to avoid the subtraction of two close numbers:

.. math::

   \sqrt{x + 1} - \sqrt{x} = (\sqrt{x + 1} - \sqrt{x})
        \left ( \frac{\sqrt{x+1} + \sqrt{x}}{\sqrt{x+1} + \sqrt{x}} \right )
        = \frac{1}{\sqrt{x+1} + \sqrt{x}}

Again we'll compare a single-precision calculation using each of these methods
to a double precision "correct answer".  To ensure that we use the
single-precision version of the ``std::sqrt()`` function, we will use single
precision literal suffix, e.g., ``1.0f`` tells the compiler that this is a
single-precision constant.

.. literalinclude:: ../../../examples/floating_point/squareroots.cpp
   :language: c++
   :caption: ``squareroots.cpp``

Notice that we get several more significant digits correct when we compute it with
the second formulation compared to the original form.

Summation algorithms
--------------------

Summing a sequence of numbers is a common place where roundoff error
comes into play, especially if the numbers all vary in magnitude and
you do not attempt to add them in a sorted fashion.  There are a
number of different summation algorithms that keep track of the loss
due to roundoff and compensate the sum, for example `the Kahan summation algorithm <https://en.wikipedia.org/wiki/Kahan_summation_algorithm#See_also>`_.

----

.. [#f1] this example is based on Yakowitz & Szidarovszky
