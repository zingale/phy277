*****
Loops
*****

``for`` loops
=============

We've already seen the basic structure of a for loop:

.. code:: c++

   for (initializer ; condition ; iterator) {
        // do stuff
   }

.. tip::

   The behavior of the prefix and postfix operator is essentially the same when it is
   on its own line.  Also in the ``for`` construction:

   .. code:: c++

      for (int i = 0; i < 10; ++i) {
          ...

   it doesn't matter much which version you use---although you will
   commonly see the prefix version used since it does not make a copy,
   and therefore can be faster.


We can do this for just a simple integer counter:

.. code:: c++

   for (int i = 0; i < 10; i += 2) {
        // we'll see i = 0, 2, 4, 6, 8
   }

or with an iterator, like:

.. code:: c++

   std::string my_string{"this is my string"};

   for (auto it = my_string.begin(); it < my_string.end(); ++it) {
        // work on the string character by character
   }

.. note::

   Just like with ``if``, there is a single-statement form of ``for``
   that doesn't use brackets for the loop body---this should be
   avoided.

We also saw the range-for loop that works with a variety of containers.  For example:

.. code:: c++

   std::vector<double> x{0.0, 1.0, 2.0, 3.0};

   for (auto e : x) {
       // work on the current element in x
   }



``while`` and ``do``-``while`` loops
====================================

There are two types of ``while`` loops in C++.  The first takes the form:

.. code:: c++

   while (condition) {
       // do stuff
   }

where the body is executed so long as ``condition`` is true.  For example:

.. code:: c++

   int i{0};

   while (i < 10) {
      i = 2*i;
   }

The loop body is only ever executed if the condition is true.  The
other form puts the ``while`` at the end:

.. code:: c++

   do {
       // do stuff
   } while (condition);

In this case, all of the statements in the loop body are executed at least once.

.. note::

   The ``do {} while (condition)`` form `is discouraged <https://clang.llvm.org/extra/clang-tidy/checks/cppcoreguidelines/avoid-do-while.html>`_.


Finally, you can loop over a range simply by using an initialization list:

.. literalinclude:: ../../../examples/statements/list_loop.cpp
   :language: c++
   :caption: ``list_loop.cpp``


