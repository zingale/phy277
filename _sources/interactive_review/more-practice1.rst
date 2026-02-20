**********************
More Practice Problems
**********************

Bash shell
==========

#. You do an ``ls`` in a directory and see the following:

   ::

      Castro_sdc.cpp  Castro_sdc_util.H  sdc_newton_solve.H  sdc_util.cpp
      Castro_sdc.H    Make.package       sdc_react_util.H    vode_rhs_true_sdc.H

   a. What is a wildcard pattern that matches all of the ``.cpp`` files?

      .. dropdown:: solution

         ``*.cpp``

   b. What is a wildcard pattern that matches all of the files that start with ``sdc``
      and end in ``.H``?

      .. dropdown:: solution

         ``sdc*.H``

#. You can to store the history of commands you typed in the Bash shell to a file
   called ``session.txt``.  How could you do this?

   .. dropdown:: solution

      .. prompt:: bash

         history > session.txt

C++ basics
==========

#. What is the difference between the following 2 declarations?

   .. code:: c++

      int a{1.5};
      double a{1.5};

   .. dropdown:: solution

      An ``int`` holds an integer, so it cannot express ``1.5`` and will truncate it to
      the integer ``1``.

#. We want to compute $e^x$, for $x = 2.0$ and output the result to the screen.
   Give the entire program that does this.

   .. dropdown:: solution

      .. code:: c++

         #include <iostream>
         #include <cmath>

         int main() {

             std::cout << std::exp(2.0) << std::endl;

         }


#. Are these two expressions different when computed?

   .. code:: c++

      y = a + (b * -c);

   .. code:: c++

      y = a + b * -c;

   .. dropdown:: solution

      They are equivalent.  Even though we are using ``( )`` in the first expression,
      the multiplication already has higher precedence than addition.

#. For a variable ``x`` that is ``double``, what is the meaning of this line:

   .. code::

      x += 2.0;

   .. dropdown:: solution

      This is equivalent to:

      .. code::

         x = x + 2.0;
