****************************
And (``&&``) and Or (``||``)
****************************

Sometimes we want to combine tests in a single conditional.  For this
we use the logical operators:

* ``a && b`` : the *add* operator.  It returns ``true`` if both ``a`` and ``b`` are ``true``.

* ``a || b`` : the *or* operator.  It returns ``true`` if either (of
  both) of ``a`` or ``b`` are ``true``.

* ``! a`` : the *not* operator.  It turns ``true`` if ``a`` is ``false``.

Keep in mind the `precedence of these operators <https://en.cppreference.com/w/cpp/language/operator_precedence.html>`_ in expressions.

Here's an example.  Let's ask the user for an integer and then test if it is divisible by
*both* 2 and 3:

.. literalinclude:: ../../../examples/conditionals/divisible.cpp
   :language: c++
   :caption: ``divisible.cpp``

