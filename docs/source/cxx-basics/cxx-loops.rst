*****
Loops
*****


``for`` loops
=============

We already saw how to loop over the elements of a vector:

.. code:: c++

   for (auto e : vec) {
       // work on e
   }

Now we'll look at another type of ``for`` loop.  This takes the form:

.. code:: c++

   for (initializer ; condition ; iterator) {
        // do stuff
   }

For example, to iterate from ``i = 0`` to ``i = 9``, we could do:

.. code:: c++

   for (int i = 0; i < 10; ++i) {
       // work with i
   }

We can use this to index a vector as well.  For example:

.. literalinclude:: ../../../examples/loops/vector_loop_manual.cpp
   :language: c++
   :caption: ``vector_loop_manual.cpp``

.. tip::

   The behavior of the prefix and postfix operator is essentially the same when it is
   on its own line.  Also in the ``for`` construction:

   .. code:: c++

      for (int i = 0; i < 10; ++i) {
          ...

   it doesn't matter much which version you use---although you will
   commonly see the prefix version used since it does not make a copy,
   and therefore can be faster.

.. note::

   Just like with ``if``, there is a single-statement form of ``for``
   that doesn't use brackets for the loop body---this should be
   avoided.



``while`` loops
===============

The other type of loop in C++ is a ``while`` loops.  This takes the form:

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

The loop body is only ever executed if the condition is true.

.. warning::

   There is another form of the ``while`` loop that has the form:

   .. code:: c++

      do {
          // do stuff
      } while (condition);

   In this case, all of the statements in the loop body are executed at least once.

   The ``do {} while (condition)`` form `is discouraged <https://clang.llvm.org/extra/clang-tidy/checks/cppcoreguidelines/avoid-do-while.html>`_.

