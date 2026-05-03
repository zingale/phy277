*****************
More On Templates
*****************

Templating our ``Array``
========================

Let's revisit our :ref:`sec:contiguous-array`, and make the data type a template parameter.
Then we can create an array of ``int`` as:

.. code:: c++

   Array<int> x(4, 3);

``static_assert``
=================

Notice that we can create an ``Array<std::string>``---but that's really not our intent,
and we are likely going to do things that only make sense with numbers.

.. code:: c++

   Array<std::string> x(5, 5, "x");

We can add a ``static_assert`` to disallow this---a static assert is evaluated at compile time.
Just instead of our ``Array`` constructor, we just add:

.. code:: c++

   static_assert (std::is_arithmetic_v<T>);

This ensures that ``T`` is an arithmetic type (integer or floating point type).

.. note::

   This is defined in ``<type_traits>``

There are additional type checks like ``is_integral_v`` and ``is_floating_point_v``
