*********************
Compiler Optimization
*********************

When writing numerical codes, we often want the fastest performance we can get.
Compilers can make `optimizations to our code <https://en.wikipedia.org/wiki/Optimizing_compiler>`_ to get better performance.  This can include eliminating common subexpressions, unrolling loops to get better cache performance, inlining functions to reduce the overhead of a call, and utilizing special hardware instructions. 

Optimization often requires multiple passes from the compiler, which
makes the compilation take longer, but the resulting code can be much
faster.

Optimization flags
==================

Most compilers use ``-O`` to specify optimization, and the amount of
optimization can be controlled using ``-O1`` to the least optimization
to ``-O3`` for aggressive optimization.  At the highest level of
optimization, the compiler may transform math in a way that is
algebraically equivalent but has different roundoff.

.. tip::

   You can see what the different optimization levels do by looking at
   ``man g++``.

``NDEBUG``
==========

By default, the C++ standard library has asserts that check at runtime that
the library is being used as intended.  These can be disabled by passing the
flag ``-DNDEBUG`` to ``g++``.
