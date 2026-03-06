.. _sec:reading-input:

*************
Reading Input
*************

We already saw a basic example of reading from the user when we looked at
our :ref:`sec_first_project`.

``std::cin`` works like ``std::cout``, except it reads from input.  An
we use the input stream operator, ``>>`` now.

.. literalinclude:: ../../../examples/reading/simple_read.cpp
   :language: c++
   :caption: ``simple_read.cpp``

Notice that we create the object / variable that we want to store the input in,
and then we read from ``std::cin`` into that variable.

.. caution::

   Nothing in this example checks if a number was actually entered.

We can look at ``std::cin.fail()`` to see if the read failed (it will
be ``1`` if it fails)).

.. literalinclude:: ../../../examples/reading/check_read.cpp
   :language: c++
   :caption: ``check_read.cpp``

.. tip::

   Shortly we will see how to test on the value returned by ``std::cin.fail()``.

