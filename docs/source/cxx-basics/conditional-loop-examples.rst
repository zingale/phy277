*************************
``if`` + Looping Examples
*************************

Prime numbers
=============

One way to check if a number $N$ is prime is to check if it is evenly divisible
by all integers up to $\sqrt{N}$.  Let's look at a code that can do this, up
to an arbitrary maximum integer.

.. literalinclude:: ../../../examples/conditionals/primes.cpp
   :language: c++
   :caption: ``primes.cpp``


Fibonacci sequence
==================

The `Fibonacci sequence
<https://en.wikipedia.org/wiki/Fibonacci_sequence>`_ is such that each
term is the sum of the previous two.  We can write a code to create a
vector with the Fibonacci sequence up to a desired number of terms.
We'll use a ``while`` loop for this, testing on the size of the
vector.

.. literalinclude:: ../../../examples/loops/fibonacci.cpp
   :language: c++
   :caption: ``fibonacci.cpp``

Some notes:

* We are using a ``long`` integer as the datatype for our vector.
  This is to help with integer overflows.  Even with ``long`` however,
  we will overflow the limits of the 64-bit integer at about 100
  terms.

  We could get a little further (~ 1 more element) by using an
  ``unsigned long``.

* We check to make sure the user asks for at least 3 elements, since
  we already start with ``{0, 1}``.  And we exit using `std::exit
  <https://en.cppreference.com/w/cpp/utility/program/exit.html>`_ if
  they ask for too few.
