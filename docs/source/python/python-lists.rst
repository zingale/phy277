*****
Lists
*****

Python lists are very similar to C++ ``std::vector``.  They serve
the same purpose.

In particular:

* We can loop over elements of a list using a ``for`` loop, very
  similar to the range-based loop we saw with C++.

* We use ``.append()`` in python they way we used ``.push_back`` in C++

* We use ``[]`` and 0-based indexing to get an element of a list---just like in C++

  * If we use a negative index, then we access elements from the end, e.g.,
    ``alist[-1]`` is the last element in a list ``alist``.  This is
    similar to the C++ ``.back()`` function.

* We can use the ``len()`` function to get the number of elements in a
  list.  Unlike C++ ``.size()``, this is not a member of the list
  class, so we would do ``len(alist)``.

.. grid:: 2

   .. grid-item-card:: python

      .. code:: python

         a_list = []
         a_list.append(1.0)
         a_list.append(2.0)

         for e in a_list:
             print(e)

      In python we don't need to specify
      the datatype.

   .. grid-item-card:: C++

      .. code:: c++

         std::vector<double> vec;
         vec.push_back(1.0);
         vec.push_back(2.0);

         for (auto e : vec) {
             std::cout << e << std::endl;
         }

      In C++, when we create a vector, we need to
      specify what type of data it carries.

.. note::

   Technically, python lists can hold a mix of different types, e.g., you can do:

   .. code:: python

      a_list = [1, 2.5, "string"]

   but this is rarely used in practice.  Usually we use them with a single
   type, much like with ``std::vector``.


Example
=======

Small-angle approximation
-------------------------

Let's revisit our :ref:`sec:vec-small-angle`, and rewrite it in python.

.. literalinclude:: ../../../examples/python/small_angle.py
   :language: python
   :caption: ``small_angle.py``

Notice:

* The format strings in the ``print`` statements are identical to the
  ones in the C++ code, except now we use an f-string.

* We don't need to put the loop conditions in ``( )``, in fact in python,
  it is discouraged.

* In python, we can use ``math.radians()`` to convert from degrees to
  radians.  The C++ standard library does not have a comparable
  function.


Average and standard deviation
------------------------------

Let's revisit our :ref:`sec:homework4` problem on finding the average
and standard deviation of a vector, now in python.

.. literalinclude:: ../../../examples/python/mean_stddev.py
   :language: python
   :caption: ``mean_stddev.py``

.. important::

   Writing explicit loops over the elements of a list is inefficient
   in python, because each iteration interacts with the interpreter.
   There are more efficient ways we can do this.  For example,
   we can use the built-in ``sum`` function:

   .. code:: python

      vsum = sum(values)

   and we can use `list comprehensions <https://docs.python.org/3.14/tutorial/datastructures.html#list-comprehensions>`_ as well, e.g.,

   .. code:: python

      vsigma = sum((e - vavg)**2 for e in values)

.. tip::

   When we cover the NumPy library later, we'll see that there are even
   easier ways to do this.

