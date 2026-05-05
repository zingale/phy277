**********
More NumPy
**********

Copying arrays
==============

.. important::

   Simply using ``=`` does not make a copy, but much like with lists,
   you will just have multiple names pointing to the same ``ndarray``
   object

   Therefore, we need to understand if two arrays, ``A`` and ``B`` point to:

   * the same array, including shape and data/memory space

   * the same data/memory space, but perhaps different shapes (a view)

   * a separate copy of the data (i.e. stored completely separately in memory)

   All of these are possible.

Let's look at different ways to copy:

* ``B = A``

  this is assignment. No copy is made. ``A`` and ``B`` point to the same data
  in memory and share the same shape, etc. They are just two different
  labels for the same object in memory

* ``B = A[:]``

  this is a *view* or shallow copy. The shape info for ``A`` and ``B`` are
  stored independently, but both point to the same memory location for
  data

* ``B = A.copy()``

  this is a deep copy. A completely separate object will be created in
  memory, with a completely separate location in memory.

Views
-----

Consider the following:

.. code:: pycon

   >>> q = np.array([[1, 2, 3, 2, 1],
   ...               [2, 4, 4, 4, 2],
   ...               [3, 4, 4, 4, 3],
   ...               [2, 4, 4, 4, 2],
   ...               [1, 2, 3, 2, 1]])
   >>> a = q[1:4, 1:4]
   >>> a
   array([[4, 4, 4],
          [4, 4, 4],
          [4, 4, 4]])
   >>> a[:, :] = 0
   >>> q
   array([[1, 2, 3, 2, 1],
          [2, 0, 0, 0, 2],
          [3, 0, 0, 0, 3],
          [2, 0, 0, 0, 2],
          [1, 2, 3, 2, 1]])

Here we create a view ``a`` into array ``q`` that just consists of the middle
3×3 array of elements.

But when we zero-out the elements of ``a``, this change is reflected back into ``q``.

A view shares the underlying data of the original array, but has
separate metadata (size, shape, etc.).  Views in NumPy allow us to do efficient
operations on portions of arrays.

Boolean indexing
================


Avoiding loops
==============

