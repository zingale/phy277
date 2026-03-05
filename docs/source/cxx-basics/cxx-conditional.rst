*****************
``if`` Statements
*****************

So far, we have not been making decisions based on the values our
variables hold.  Let's see how to do this.  The ``if`` statement
allows us to test on values and take actions.

The basic form is:

.. code:: c++

   if (condition1) {
      // do things if condition1 is true

   } else if (condition2) {
      // do things if condition1 is false but condition 2 is true

   } else {
      // do things only if both condition1 and condition2 are false

   }

Here ``condition`` is something that will evaluate to ``true`` or
``false``, and this is a place where we will use the
:ref:`sec:relational_ops` we've seen previously.

Again we use ``{ }`` to group the statements into blocks for each part
of the conditional.

.. caution::

   There is a form of an if-statement that does not use brackets if
   there is only a single statement to execute:

   .. code:: c++

      if (condition)
          statement;

   This is potentially dangerous---if someone later edits the code
   and decides that they want to add another statement to that
   condition, they might do:

   .. code:: c++

      if (condition)
          statement;
          another_statement;

   But since there are no braces, only ``statement`` is
   conditionally-executed.  ``another_statement`` is not part of the
   if-test and will always be executed.

   For this reason, it is always best to use brackets.

Simple example
==============

Here's an example that reads an integer from the user and then outputs
whether it is positive, negative, or zero:

.. literalinclude:: ../../../examples/conditionals/if-example.cpp
   :language: c++
   :caption: ``if-example.cpp``

.. note::

   We read input from the user using ``std::cin`` as discussed in
   :ref:`sec:reading-input`.


Scope
=====

Consider the following example:

.. literalinclude:: ../../../examples/conditionals/if-scope.cpp
   :language: c++
   :caption: ``if-scope.cpp``

Since we declare the variable ``rem`` inside of an ``if`` block (i.e., inside the ``{ }``),
it is not available to us outside of the block.

If we want to set a variable inside of an ``if`` condition, then we
need to declare the variable outside.  This is an issue of *scope*.
Most variables in C++ have lifetimes limited to the block (``{ }``) in
which they are defined.


Ternary operator
================

There is also a simple `ternary operator
<https://en.wikipedia.org/wiki/%3F:>`_ in C++ of the form:

       *condition* ``?`` *true-result* ``:`` *false result*

Where *true-result* is the value used if *condition* is ``true``
and *false-result* otherwise.

For instance:

.. code:: c++

   int i{10};

   double x = (i > 5) ? 1.0 : 0.0;

This tends not to be very readable, but there are some rare instances where it is needed.


``switch`` statement
====================

C++ also has a `switch statement
<https://en.cppreference.com/w/cpp/language/switch.html>`_, which we
will not consider.  We can accomplish any logic needed with the
``if`` - ``else`` constructs.
