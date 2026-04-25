*****
Lists
*****

Python lists are very similar to C++ ``std::vector``.  They serve
the same purpose.

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


Example
=======

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

