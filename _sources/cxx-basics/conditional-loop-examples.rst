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

