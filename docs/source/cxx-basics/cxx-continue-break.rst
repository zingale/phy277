**************************
``continue`` and ``break``
**************************

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
