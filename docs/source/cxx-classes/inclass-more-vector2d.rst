********************************
Adding to our ``Vector2d`` Class
********************************

Let's extend our ``Vector2d`` class with the following operators / functions.


Multiplication by a scalar
==========================

We need to consider 2 different multiplication operations---given a
``Vector2d v`` and a ``double a``, we can do:

.. code:: c++

   auto v1 = v * a;
   auto v2 = a * v;

In the first, our ``Vector2d`` object appears to the left of the
operator, so this is a member of the class, and the function will
look like:

.. code:: c++

   Vector2d operator* (double a);

But for the second, our ``Vector2d`` is to the right of the operator,
so we need to create this function outside of the class, but give it
permission to access a ``Vector2d`` 's data---this means it needs to
be a ``friend``:

.. code:: c++

   friend Vector2d operator* (double a, const Vector2d& v);

In both cases, this operator returns a new ``Vector2d``.


Division by a scalar
====================

For division, it only makes sense to do ``v / a``, where ``v`` is
a ``Vector2d`` and ``a`` is a double.  For this operation, our
object is to the left of the operator, so this would be a member
of the class.  This function would look like:

.. code:: c++

   Vector2d operator/ (double a);


Dot product
===========

For vectors $u$ and $v$, the dot-product is $u_x v_x + u_y v_y$.

We could imagine overloading ``*`` to work for doing the dot-product
of two vectors, e.g., ``u * v`` would do ``u.x * v.x + u.y *
v.y``.  But this could be confusing, because some might think it is
the element-wise multiplication operation, ``Vector2d(u.x * v.x,
u.y * v.y)``.

In python, the ``@`` operator serves as the dot-product operator, but
no such operator exists in C++.  So we'll use a function:

.. code:: c++

   double dot(const Vector2d& v);

Cross product
=============

For vectors $u$ and $v$, the cross-product is $u \times v = (u_x v_y -
u_y v_x) \hat{z}$.  We'll just return the magnitude, since we don't
have the ability in ``Vector2d`` to express the $z$-component of a
vector.

.. code:: c++

   double cross(const Vector2d& v);

Magnitude
=========

The magnitude of a vector $v$ is $|v| = \sqrt{v_x^2 + v_y^2}$.  We'll
implement this as a function ``abs`` to be similar to the absolute
value function we already use from the standard library:

.. code:: c++

   double abs();


Equality test
=============

We want the ``==`` operator to be able to do assertions.  This
has the form:

.. code:: c++

   bool operator== (const Vector2d& v) const;

Note the ``const`` after the parameter list---this indicates that
this function can be used on a ``const Vector2d``.  This ``const``
is basically saying that this operator will not modify our object.
This is called a *const member function*.

But with C++20, we could also use the default comparison operator,
since our object is simple enough for the compiler to understand:

.. code:: c++

   bool operator==(const Vector2d& v) const = default;

Input stream operator, ``>>``
=============================

We want to overload ``>>`` so we can read directly into a ``Vector2d``
object, e.g.,

.. code:: c++

   Vector2d v;

   cin >> v;

Your function should look like:

.. code:: c++

   friend std::istream& operator>>(std::istream& is, Vector2d &v);

Notice that the ``Vector2d`` is not ``const``, since we will be modifying it.

You will want to read 2 pieces of data from the input stream and directly
set ``v.x`` and ``v.y``.



Test driver
===========

Here's a test driver that exercises these new capabilities.  It uses
assertions to ensure that we implemented them correctly.

.. literalinclude:: ../../../examples/classes/vector-improved/test_vectors.cpp
   :language: c++
   :caption: ``test_vectors.cpp``

