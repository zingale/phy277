********************
Vector Modifications
********************

Here are some examples that modify the container.



Inserting
=========

We saw that ``.push_back()`` is used to add an element to the end of a
vector.  To insert in the middle of the vector, we use
``.insert(it_pos)``, where ``it_pos`` is an iterator pointing to the
element in the vector we want to insert *in front of*.  (Note:
``insert()`` can actually allow you to insert multiple elements by
specifying an additional argument.)

Here's an example: we start with a vector with the elements ``100``, ``200``,
``300`` and then use ``insert()`` to put ``150`` in between ``100``
and ``200``.

.. literalinclude:: ../../../examples/vectors/insert_example.cpp
   :language: c++
   :caption: ``insert_example.cpp``

Erasing
=======

Erasing works similar to inserting.  We give an iterator pointing to
the start and end of the range we want to erase, and all elements up
to, but not including the end, are erased.

The end point being *exclusive* rather than *inclusive* is consistent
with ``.end()`` returning an iterator that points one-past the end of
the vector.

Here's an example that removes the first 4 elements of a vector.

What happens if we try to remove past the end?  To be save, we should
always add a check on whether our end is past ``.end()``.

.. literalinclude:: ../../../examples/vectors/vector_erase.cpp
   :language: c++
   :caption: ``vector_erase.cpp``

.. admonition:: try it...

   What happens if you use ``.cbegin()`` and/or ``.cend()`` instead
   ``.begin()`` and ``.end()``?

   Remember that the ``c`` in those functions is for ``const``---it
   provides read-only access to the elements through the iterator.

