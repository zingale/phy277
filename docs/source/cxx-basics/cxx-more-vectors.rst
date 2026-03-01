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


