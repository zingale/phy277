************
Mixing types
************

You need to be careful when mixing different data types.  C++ will
implicitly *cast* objects to the more general type, sometimes with
unexpected consequences.  Later we'll see how to explicitly cast data
if needed.

.. admonition:: Try it...

   Try the following (you'll need to put this in a ``main()`` function and compile it):

   .. code:: c++

      // convert from Fahrenheit to Celsius

      double T_F {100.0};
      double T_C =  (T_F - 32) * (5 / 9);

      std::cout << "T_C = " << T_C << std::endl;


   Why doesn't this work as expected?


Casting
=======

We can use `static_cast <https://en.cppreference.com/w/cpp/language/static_cast.html>`_ to explicitly
convert one type to another.  For example:

.. code:: c++

   int a{5};
   double x = static_cast<double>(a);

will convert the integer ``a`` to a double-precision floating point object ``x``.

There are other types of casts in C++, but this is the one we will use the most.

.. admonition:: Try it...

   Let's explicitly cast the integers in the program above to see if it fixes our problem.
