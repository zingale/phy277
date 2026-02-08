*********
Operators
*********

C++ defines `a lot of operators <https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B>`_ that can be used on objects.  We'll
discuss them here in the context of math with numeric types, but these
operators can be extended to work with other types as well.

Mathematical operators
======================

The standard mathematics operators are:

* ``+`` : addition

* ``-`` : subtraction

* ``*`` : multiplication

* ``/`` : division

* ``%`` : modulus

In addition, ``+`` and ``-`` can be used as *unary operators*, e.g., to negate
a quantity:

.. code:: c++

   double x = -y;

.. note::

   Unlike in some languages, there is no operator for exponentiation, e.g., $x^y$.
   We'll see how to call a function to this shortly.

Relational operators
====================

Relational operators compare objects.  The main operators are:

* ``==`` : equal to

* ``!=`` : not equal to

* ``>`` : greater than

* ``<`` : less than

* ``>=`` : greater than or equal to

* ``<=`` : less than or equal to

.. note::

   C++20 introduces a three-way comparison, ``<=>``, which we will not consider.


Assignment operators
====================

Assignment modifies the value of the object to the left of the operator.  The assignment
operators include:

* ``a = b``  : set the value of a to that of b

* ``a += b`` : equivalent to ``a = a + b``

* ``a -= b`` : equivalent to ``a = a - b``

* ``a *= b`` : equivalent to ``a = a * b``

* ``a /= b`` : equivalent to ``a = a / b``

Precedence
==========

What happens when we have an expression like:

.. code:: c++

   a + b * c;

The language defines the order that operators are considered, called
*operator precedence*.

This table: `C++ Operator Precedence
<https://en.cppreference.com/w/cpp/language/operator_precedence>`_
lists the order in which operators are evaluated.

In the example above, multiplication has higher precedence, so it is
evaluated first, and then the addition is done.

.. tip::

   We can use parentheses to force a group to be evaluated first, e.g.,
   ``(a + b) * c``

.. admonition:: Try it...

   Play around with some expressions to explore the precedence of operators.


Prefix and postfix operators
============================

C++ also has the increment and decrement operators.

* ``a++`` is equivalent to ``a = a + 1``

* ``a--`` is equivalent to ``a = a - 1``

There are postfix versions of these, e.g., ``++a``.  The
difference between them is subtle.

The prefix operator is:

.. code:: c++

   int a{0}, b{0};
   b = ++a;

The prefix increment operator first increments the value of the object
and then returns a reference to the result.
So in the above example, the result would be ``b = 1``.

Now consider the postfix operator:

.. code:: c++

   int c{0}, d{0};
   d = c++;

Here, a copy of ``c`` is made, then ``c`` is incremented, and finally the copy is returned.
So in the above example, the result would be ``d = 0``.

.. tip::

   The behavior of the prefix and postfix operator is essentially the same when it is
   on its own line.  Also in the ``for`` construction:

   .. code:: c++

      for (int i = 0; i < 10; ++i) {
          ...

   it doesn't matter much which version you use---although you will
   commonly see the prefix version used since it does not make a copy,
   and therefore can be faster.


Associativity
=============

When an expression has two operators at the same precedence, `operator
associativity rules
<https://en.wikipedia.org/wiki/Operator_associativity>`_ come into
play.  Most operators in C++ are *left associative*---that is, they
are grouped from the left, but some are right associative (like the
unary operators and assignment) meaning that they are grouped from the
right.

Consider assignment:

.. code:: c++

   a = b = c

Since ``=`` has right associativity, we interpret this as ``a = (b = c)``, which can further
be thought of as ``b = c; a = c``.

.. note::

   In C++, assignment evaluates to the left value.

In the expression:

.. code:: c++

   a + b - c

Both ``+`` and ``-`` have the same precedence, and these are
left-associative, so first ``a + b`` is evaluated and then ``c`` is
subtracted from that result.
