************
More Vectors
************

Let's look at some more ways we can work with vectors.

Initializing
============

We can initialize a vector when we declare it.  The following creates a vector with 5 elements, all initialized to 0:

.. code:: c++

   std::vector<double> container(5, 0.0);

Notice that we are using ``()`` here instead of ``{}``.  As we'll see
later, this means that we are calling a function here to do the
initialization (the constructor).

Here we instead initialize a vector by telling it the values of each of the elements:

.. code:: c++

   std::vector<double> container2{10.0, 20.0, 30.0};

Size
====

As we saw earlier, we can always get the number of elements in a
vector via the ``size()`` function:

.. code:: c++

   std::vector<int> int_vec{1, 2, 3, 4, 5};

   int nlen = int_vec.size();


.. note::

   ``size()`` technically returns a value of type ``std::size_t``, and
   here we implicitly *cast* it to an ``int``.  We learn more about
   casting later.

.. admonition:: try it...

   We saw that we access an element via ``[]``.  What happens if we
   access the vector out of bounds?

