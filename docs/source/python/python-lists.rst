*****
Lists
*****

Python lists are very similar to C++ ``std::vector``.  They serve
the same purpose.

In particular:

* We can loop over elements of a list using a ``for`` loop, very
  similar to the range-based loop we saw with C++.

* We use ``.append()`` in python they way we used ``.push_back`` in C++

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

* the format strings in the ``print`` statements are identical to the
  ones in the C++ code, except now we use an f-string.

* in python, we can use ``math.radians()`` to convert from degrees to
  radians.  The C++ standard library does not have a comparable
  function.


Average and standard deviation
------------------------------

Let's revisit our :ref:`sec:homework4` problem on finding the average
and standard deviation of a vector, now in python.



.. note::

   When we cover the NumPy library later, we'll see that there are even
   easier ways to do this.
