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

.. tip::

   An iterator can be thought of as a special type of pointer.  Iterators have
   restrictions on their use, depending on the container---this makes
   them more safe to use.

If we think about an iterator like:

.. code:: c++

   auto it = container.cbegin();

Then we can access the next element in ``container`` by incrementing
the iterator, ``it++``.

If we want to see the value in ``container`` that the iterator is
pointing to, then we need to dereference it---just as with pointers,
this is done with the ``*`` operator:

.. code:: c++

   std::cout << "cbegin is " << *it << std::endl;

.. note::

   C++ doesn't support printing the iterator itself, e.g.,

   .. code:: c++

      std::cout << it << std::endl;

   does not compile.  If you want to see the memory address (for some reason),
   you need to dereference the iterator and then take the address of the object
   it is pointing to, e.g.,

   .. code:: c++

      std::cout << &(*it) << std::endl;

Looping with iterators
======================

Here's an example of looping over an entire vector using iterators:

.. literalinclude:: ../../../examples/standard_library/iterator_loop.cpp
   :language: c++
   :caption: ``iterator_loop.cpp``

Notice that we advance the iterator to point to the next element in
the vector using ``++it``.  We could also do ``it += 4`` to skip
4 elements (but it is up to us to ensure that we don't go past the end).

.. important::

   Remember that ``container.cend()`` points to one past the last element.
   This is why we use the ``<`` operator here, and not ``<=``.

There's really no advantage in this example in using iterators vs. the
ranged-for loop we've been using until now.
