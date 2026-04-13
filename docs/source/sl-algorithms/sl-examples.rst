***********
SL Practice
***********

Let's do some more practice on using the standard library.

#. In :ref:`sec:homework6`, you wrote a function to find the maximum
   element in a vector.  Let's do that again, this time using
   `std::ranges::max_element
   <https://en.cppreference.com/w/cpp/algorithm/ranges/max_element>`_.

   Then use ``std::ranges::distance`` to find the index (just like
   we did with our :ref:`sec:std_ranges_find` example.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. literalinclude:: ../../../examples/standard_library/max_example.cpp
         :language: c++
         :caption: ``max_example.cpp``

      The key point here is that ``max_element`` returns an iterator
      to the maximum element in the vector.  We need to dereference it
      (using the ``*`` operator) to see the value it points to.

#. We can use `std::accumulate <https://en.cppreference.com/w/cpp/algorithm/accumulate.html>`_
   to sum the elements of a vector, or multiply them, or some other transformation.

   Write some code to find the sum of the elements and the product of
   the elements of a vector.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. literalinclude:: ../../../examples/standard_library/accumulate_example.cpp
         :language: c++
         :caption: ``accumulate_example.cpp``

      ``std::accumulate`` usually takes 4 arguments:

      * An iterator pointing to the beginning of the range to sum

      * An iterator pointing to one-past the end of the range to sum

      * An initial value for the accumulation

      * A function to do the operation that takes two arguments.  The
        first is the current accumulated value and the second is an
        element in the vector.

      For our sum, we want to start with ``0``, and then we add to this.
      With no operator as the 4th argument, ``std::accumulate`` will do a sum, so
      that allows us to do this call:

      .. code:: c++

         auto sum = std::accumulate(vec.begin(), vec.end(), 0.0);

      We could have used the C++ standard library `std::plus <https://en.cppreference.com/w/cpp/utility/functional/plus.html>`_ function to be more explicit:

      .. code:: c++

         auto sum = std::accumulate(vec.begin(), vec.end(), std::plus<int>{});

      or we could write our own (lambda) function and pass it in.

      For our product, we want to start with ``1``, since multiplying the
      first element by ``1`` will just give us the first element.  In this
      example, we write a lambda-function.  We could also use `std::multiplies <https://en.cppreference.com/w/cpp/utility/functional/multiplies.html>`_.

#. In our :ref:`sec:vector_any_element` example, we checked if any element in a
   vector was even.  Let's rewrite that using a lambda function.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. literalinclude:: ../../../examples/standard_library/any_element_lambda.cpp
         :language: c++
         :caption: ``any_element_lambda.cpp``

      In this example, our lambda function is simply:

      .. code:: c++

         [] (int e) {return e % 2 == 0;}

      This doesn't need to capture anything from the surrounding scope (``[]``)
      and works on a single element passed in (``(int e)``).  This function
      is equivalent to our original:

      .. code:: c++

         bool is_even(int e) {
             return e % 2 == 0;
         }

