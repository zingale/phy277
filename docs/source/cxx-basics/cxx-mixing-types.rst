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

