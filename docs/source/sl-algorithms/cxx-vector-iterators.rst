****************
Vector Iterators
****************


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

