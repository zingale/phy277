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

Bounds, iterators, and pointers
===============================

There are 2 ways to access the beginning and end of a ``vector``:

* ``.cbegin()``, ``.begin()`` : these will give you an *iterator* that
  points to the first element.  The difference is that accessing with
  ``.cbegin()`` will not allow you to modify the vector (the ``c`` is
  for ``const``).  You can increment an *iterator* loop over the
  contents of the vector.

* ``.cend()``, ``.end()`` : these will return an iterator that points
  *to one past the last element*.

An iterator can be thought of as a special type of *pointer*---a
topic that we will discuss much more later.  Iterators have
restrictions on their use, depending on the container---this makes
them more safe to use.

If we think about an iterator like:

.. code:: c++

   auto it = container.cbegin();

Then we can access the next element in ``container`` by incrementing the iterator, ``it++``.

If we want to see the value in ``container`` that the iterator is
pointing to, then we need to *dereference* it---this is done with the
``*`` operator:

.. code:: c++

   std::cout << "cbegin is " << *it << std::endl;

Here's an example of looping over an entire vector using iterators:

.. literalinclude:: ../../../examples/vectors/iterator_loop.cpp
   :language: c++
   :caption: ``iterator_loop.cpp``

Reverse iterators
=================

We can use ``std::rbegin()`` / ``std::rend()`` to iterate through a container
in reverse.

.. literalinclude:: ../../../examples/vectors/vector_reverse.cpp
   :language: c++
   :caption: ``vector_reverse.cpp``

