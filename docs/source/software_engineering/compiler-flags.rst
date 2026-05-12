.. _sec:compiler-flags:

*******************************
Making the Compiler Do the Work
*******************************

Compilers have lots of options that affect the compilation.  So far,
with ``g++`` we've been using:

* ``-o`` to name the executable
* ``-std=c++20`` to use the C++20 standard

But we can also have the compiler warn us about problematic C++ code
we may have written.  A useful set of options is:

.. prompt:: bash

   g++ -Wall -Wextra -Wshadow -Wpedantic

These have the following effects:

* ``-Wall`` : this turns on options that warn about things most users deem problematic.

* ``-Wextra`` : enables additional warnings that most people think are good to check
  for.

* ``-Wshadow`` : this checks if we redefine a variable / object that exists in the
  surrounding scope.

* ``-Wpedantic`` : makes sure that you conform to the language standard and not rely
  on any extensions that the compiler might support.

.. note::

   All of the code included in these course notes is tested with these
   compiler flags automatically each time a change is made (through
   this `test.py script
   <https://github.com/zingale/phy277/blob/main/test.py>`_).


"Comparing different types" warning
===================================

Here's an example of a case of using the wrong type in a loop that can be caught with these flags:

.. literalinclude:: ../../../examples/compiler-warnings/types.cpp
   :language: c++
   :caption: ``types.cpp``

when we compile this with these additional flags, we see:

::

   types.cpp: In function ‘int main()’:
   types.cpp:7:23: warning: comparison of integer expressions of different signedness: ‘int’ and ‘std::array<double, 10>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
       7 |     for (int i = 0; i < x.size(); ++i) {
         |                     ~~^~~~~~~~~~

This is telling us that we are comparing a signed ``int`` and an unsigned ``int``.

In this case, we can fix this, by doing:

.. code:: c++

   for (std::size_t i = 0; i < x.size(); ++i) {

since ``std::size_t`` is the same type as return by ``x.size()`` (for
this compiler, a ``long unsigned int``).

"Unused variable" warning
=========================

Here's an example of catching unused variables:

.. literalinclude:: ../../../examples/compiler-warnings/unused.cpp
   :language: c++
   :caption: ``unused.cpp``

when we build this, we get:

::

    unused.cpp: In function ‘int main()’:
    unused.cpp:3:12: warning: variable ‘y’ set but not used [-Wunused-but-set-variable]
        3 |     int x, y, z;
          |            ^
    unused.cpp:3:15: warning: unused variable ‘z’ [-Wunused-variable]
        3 |     int x, y, z;
          |               ^

These are actually two different messages.  Variable ``z`` is never
used, so we should just remove it.  But for variable ``y``, we assign
it a value, but then never access that value.  Maybe we meant to?
Sometimes, this is intentional, in which case we can use the
`[[maybe_unused]] attribute
<https://en.cppreference.com/w/cpp/language/attributes/maybe_unused.html>`_
to silence the compiler warning.

Shadowing warning
=================

Here's an example of shadowing:

.. literalinclude:: ../../../examples/compiler-warnings/shadow.cpp
   :language: c++
   :caption: ``shadow.cpp``

when we build with ``-Wshadow``, we see:

::

    shadow.cpp: In function ‘int main()’:
    shadow.cpp:9:16: warning: declaration of ‘x’ shadows a previous local [-Wshadow]
        9 |         double x;
          |                ^
    shadow.cpp:6:12: note: shadowed declaration is here
        6 |     double x{1.0};
          |            ^
