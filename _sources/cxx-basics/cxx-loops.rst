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


``continue`` and ``break``
==========================

Sometimes we want to exit a loop early or skip the remainder of the
loop block if some conditions is met.  This is where ``continue`` and
``break`` come into play.

It is not uncommon to write an infinite loop, like:

.. code:: c++

   for (;;) {
       // do stuff
   }

or

.. code:: c++

   while (true) {
       // do stuff
   }

In this case, we will want a way to bail out.  Here's an (silly)
example of asking for a word from a user and telling them how many
letters it contains.  But if they enter "0", we exit:

.. literalinclude:: ../../../examples/statements/infinite_loop.cpp
   :language: c++
   :caption: ``infinite_loop.cpp``

``continue`` is used to skip to the next iteration.  Here's an example
that loops over elements of a vector but only operates on them if they
are even numbers, in which case, it negates them.

.. literalinclude:: ../../../examples/statements/continue_example.cpp
   :language: c++
   :caption: ``continue_example.cpp``
