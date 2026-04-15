***********
Homework #8
***********

.. admonition:: Completing this assignment

   For the each of the problems below, write a separate C++ program
   named in the problem :samp:`problem{N}.cpp`, where :samp:`{N}` is the
   problem number.

   .. important::

      Make sure your that ``g++`` can compile your code.  For some of
      the problems here, you will need to use ``-std=c++20``.

   Upload your C++ source files (*not the executables produced by
   g++*) to Brightspace.



.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.


1. *File I/O* : Update your projectile motion code from the previous homework
   (:ref:`sec:homework7`) to write the output to a file.  Have your
   ``main`` function do the integration for both $C=0$ and $C=0.3$,
   writing each integration to a separate file.

2. *Transforming* : `std::ranges::transform
   <https://en.cppreference.com/w/cpp/algorithm/ranges/transform>`_
   takes a range (vector for us), an output iterator (where to start
   writing the result), and an operator (the function to apply to each
   element).

   For instance, given a vector ``v`` of ``double``, we could do:

   .. code:: c++

      std::ranges::transform(v, v.begin(), f)

   where ``f`` is a function of the form ``double f(double e)``,
   and the result would be to apply ``f(e)`` to each element, ``e``, of ``v``,
   updating our vector in-place.

   Let's use this to convert a vector of indices into $x$ values.

   Start with:

   .. code::

      std::vector<double> is{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   and define $x_\mathrm{min} = 1$, $x_\mathrm{max} = 2$, and
   :math:`\Delta x = (x_\mathrm{max} - x_\mathrm{min}) / (N-1)`, where $N$
   is the number of elements in the vector.

   Now, apply the transformation: :math:`f(e) = x_\mathrm{min} + e \Delta x`
   to the vector, using ``std::ranges::transform``.

   Finally, loop over the vector and output the updated elements.

3. *Bounds* : An operation we often want to do is search through a
   sorted list of numbers and find the interval that contains an
   desired value.  This comes up in interpolation, for example.

   Consider the following vector:

   .. code:: c++

      std::vector<double> temp_vec{0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0, 7.5, 10.0};

   For a value ``T0``, we want to find the index into the vector,
   ``i``, such that ``temp_vec[i-1] < T0 <= temp_vec[i]``.  We can get
   an iterator to ``temp_vec[i]`` using `std::ranges::lower_bound
   <https://en.cppreference.com/w/cpp/algorithm/ranges/lower_bound>`_.

   .. note::

      There is a similar function, ``std::ranges::upper_bound`` ---they
      differ only in how they handle the case where we are searching for
      a value that is in our vector:

      * ``std::ranges::lower_bound`` returns an iterator to the first element $\ge$ ``T0``

      * ``std::ranges::upper_bound`` returns an iterator to the first element $>$ ``T0``

   Write a code that finds the *index* for:

   * ``T0 = 1.2``
   * ``T0 = 3.0`` ---note: this is one of the data points in the vector.

   .. tip::

      You'll want to use ``std::distance`` to convert the iterator into a
      distance from the beginning of the container, just like we did in class.

   Also check what happens in the case that our ``T0`` is out of the limits
   of our ``temp_vec`` by finding the index for:

   * ``T0 = 0.05``
   * ``T0 = 20``

