*************************
More ``vector`` functions
*************************

Size
====

We can always get the number of elements in a
vector via the ``.size()`` function:

.. code:: c++

   std::vector<int> int_vec{1, 2, 3, 4, 5};

   int nlen = int_vec.size();


.. note::

   ``size()`` technically returns a value of type ``std::size_t``, and
   here we implicitly *cast* it to an ``int``.  We learn more about
   casting later.

Adding to a vector
==================

Lets see how to create a vector and add some data to it.  We use the
member function ``.push_back()`` to this.  This will add an
element to the end of the vector.

Here's a simple example:

.. literalinclude:: ../../../examples/vectors/simple_vector.cpp
   :language: c++
   :caption: ``simple_vector.cpp``

We use ``push_back`` several times to add data to the end of a vector.  Here we
are using the ``.`` operator to indicate that we are performing the
``push_back`` on the vector ``container`` that we created.

.. note::

   ``push_back`` is a member function of the ``vector`` class.  There
   are others that we will see shortly.



.. admonition:: try it...

   We can see the size of the vector increase each time we add an element
   using ``.push_back()``.
