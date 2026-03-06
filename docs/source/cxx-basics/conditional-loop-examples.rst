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

Some notes:

* We have nested loops here.  The outer loop using loop variable ``n``
  and the inner loop uses loop variable ``q``.

* In the inner loop, once we find a factor, we don't have to check any
  more---we already know it is not prime.  So we ``break``.  This
  jumps us out of the inner loop (the ``q`` loop), but *not* the outer
  loop.

  We don't have to do the ``break`` here, but it saves on
  computation---there is no point in checking more, so the code will
  run faster.

* Our final ``if``-test is just ``if (is_prime)``.  Since ``is_prime`` is
  a ``bool``, this is already a valid condition, and we don't need to do
  something like ``is_prime == true``.


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

* In our ``while`` loop, we are testing on the size of the vector.
  ``fib.size()`` will return a datatype of ``std::size_t``.  To be
  To be absolutely correct, we cast it to an ``int`` here, the
  same datatype as ``N``.  We probably don't have to, but this is
  safest.

* We check to make sure the user asks for at least 3 elements, since
  we already start with ``{0, 1}``.  And we exit using `std::exit
  <https://en.cppreference.com/w/cpp/utility/program/exit.html>`_ if
  they ask for too few.  This requires the ``cstdlib`` header.

  .. tip::

     It is tradition in Unix to exit with a non-zero code if a problem
     was encountered.  This can then be checked in a Bash script
     or the command line via the ``$?`` shell variable.

     See `Understanding exit status codes
     <https://www.howtouselinux.com/post/returning-exit-status-codes-in-bash-a-comprehensive-guide>`_
     for more details.
