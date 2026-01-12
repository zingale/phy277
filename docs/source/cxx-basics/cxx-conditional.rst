**********************
Conditional Statements
**********************

``if``-test
===========

We've already been using if-tests quite a bit.  So let's look a little more at their syntax:

.. code:: c++

   if (condition1) {
      // do things if condition1 is true

   } else if (condition2) {
      // do things if condition1 is false but condition 2 is true

   } else {
      // do things only if both condition1 and condition2 are false

   }


.. tip::

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

.. note::

   C++17 also allows for a form with an initializer before the
   conditional (e.g., to open a file).  We will not explore this here.


.. tip::

   There is also a simple `ternary operator
   <https://en.wikipedia.org/wiki/%3F:>`_ in C++ of the form:

       *condition* ``?`` *true-result* ``:`` *false result*

   Where *true-result* is the value used if *condition* is ``true``
   and *false-result* otherwise.

   For instance:

   .. code:: c++

      int i{10};

      double x = (i > 5) ? 1.0 : 0.0;


``switch`` statement
====================

A switch statement takes action on a single expression, and has many different
cases that can take different actions.  For example:

.. code:: c++

   int i{2};
   std::string text{};

   switch (i) {

      case 0:
          text = "zero";
          break;

      case 1:
          text = "one";
          break;

      case 2:
      case 3:
      case 4:
          text = "2 <= i <= 4";
          break;

      default:
          text = "i > 4";

   }


.. warning::

   Notice that each ``case`` region ends with ``break``.  If you omit the
   ``break``, then the flow "falls through" to the next options.

