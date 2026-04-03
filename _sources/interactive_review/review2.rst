******************
In-Class Review II
******************

This is a review of some of the concepts we covered since the previous midterm.

.. important::

   This set of examples is not exhaustive, so you should go back and
   read through the notes, run the example codes, and look at my
   homework solutions.


``std::vector``
===============

#. What header file do we need to include to work with vectors?

   .. dropdown:: solution

      We need to ``#include <vector>``.

#. Given ``std::vector<int> a{4, 7, 2, 9};``

   a. Write one line that prints the number of elements in ``a``.

      .. dropdown:: solution

         .. code:: c++

            std::cout << a.size() << std::endl;

   b. Write one line that prints the first element.

      .. dropdown:: solution

         .. code:: c++

            std::cout << a[0] << std::endl;

   c. Write one line that changes the last element to ``10``.

      .. dropdown:: solution

         There are a few ways.  We could use ``.back()`` which
         returns a *reference* to the last element:

         .. code:: c++

            a.back() = 10;

         We could index it using ``a.size()-1`` (the ``-1`` accounts for
         the fact that we use 0-based indexing:

         .. code:: c++

            a[a.size()-1] = 10;

   d. Write one line that adds ``8`` to the end of the vector.

      .. dropdown:: solution

         We use ``.push_back()`` for this:

         .. code:: c++

            a.push_back(8);

#. Create an empty vector, ``vec``, of integers, and then add
   the integers ``1``, ``2``, and ``3`` to it.

   .. dropdown:: solution

      .. code:: c++

         std::vector<int> vec{};
         vec.push_back(1);
         vec.push_back(2);
         vec.push_back(3);


strings and formatting
======================

#. Given ``std::string s = "hello";``

   a. Write one line that prints the length of ``s``.

      .. dropdown:: solution

         We use ``.size()``, just like with vectors:

         .. code:: c++

            std::cout << s.size() << std::endl;

   b. Write one line that prints the first character.

      .. dropdown:: solution

         We index it starting with ``0``:

         .. code:: c++

            std::cout << s[0] << std::endl;

#. Given ``std::string first = "Ada";`` and ``std::string last = "Lovelace";``,
   write one line that creates ``full`` equal to ``"Ada Lovelace"``.

   .. dropdown:: solution

      We can use the ``+`` operator:

      .. code:: c++

         auto full = first + " " + last;

#. Given ``std::string s = "cat";``, write one line that changes it to ``"cats"``.

   .. dropdown:: solution

      The easiest way to do this is via addition, updating ``s``:

      .. code:: c++

         s += "s";

#. How would you use ``std::format`` to print out two double precision quantities,
   $x$ and $y$, to make a sentence like ``"x = 2.0, y = 3.0"``?

   .. dropdown:: solution

      Given:

      .. code:: c++

         double x{2};
         double y{3};

      we can do:

      .. code:: c++

         std::cout << std::format("x = {:.1f}, y = {:.1f}\n", x, y);

      here the ``.1f`` means "one digit after the decimal point and
      use fixed-point formatting".

      .. important::

         When using ``std::format``, we need to include the ``<format>`` header
         and also compile with C++20 support, ``-std=c++20``.

``struct``
==========

#. Consider a point in spherical coordinates, with components
   for $r$, $\theta$, $\phi$

   a. Create a ``struct`` called ``SphericalPoint`` that holds the data for a single point.

      .. dropdown:: solution

         .. code:: c++

            struct SphericalPoint {
                double r{};
                double theta{};
                double phi{};
            };

         Note the ``;`` at the end of the ``struct`` definition.

   b. Initialize a ``SphericalPoint`` named ``p`` for the point $(r,
      \theta, \phi) = (1, \pi/4, \pi/8)$

      .. dropdown:: solution

         The cleanest way to do this is:

         .. code:: c++

            SphericalPoint p{.r=1.0,
                             .theta=std::numbers::pi/4.0,
                             .phi=std::numbers::pi/8.0};

         Where we use ``std::numbers`` to get the value of $\pi$.

         .. important::

            As with ``std::format``, this is a C++20 feature, so we 
            need to enable C++20 support when compiling.
 
   c. We can get the $x$, $y$, and $z$ components as:

      .. math::

         x &= r \sin\theta \cos\phi \\
         y &= r \sin\theta \sin\phi \\
         z &= r \cos\theta

      Show the lines of code that compute this from ``p``

      .. dropdown:: solution

         We use the ``.`` operator to access the components of our ``struct``.
         Our code can be:

         .. code:: c++

            double x = p.r * std::sin(p.theta) * std::cos(p.phi);
            double y = p.r * std::sin(p.theta) * std::sin(p.phi);
            double z = p.r * std::cos(p.theta);

#. Consider the ``struct``:

   .. code:: c++

     struct Rectangle {
         double width{};
         double height{};
     };

   Create a ``Rectangle`` named ``box`` with width ``4.0`` and height
   ``2.5``.  Then write an expression that computes its area.

   .. dropdown:: solution

      After we create our ``Rectangle``, we access the components
      using the ``.`` operator:

      .. code:: c++

         Rectangle box{.width=4.0, .height=2.5};
         double area = box.width * box.height;

Functions
=========

#. Write a function ``square`` that takes a ``double`` named ``x`` and
   returns ``x*x``.

#. Write a function ``is_zero`` that takes an ``int n`` and returns
   ``true`` if ``n`` is zero.

#. Write a function ``print_hello`` that takes no arguments and prints ``"Hello"``.

#. Write a function ``add`` that takes two integers and returns their sum.

#. Imagine we write a function ``doit`` that takes a function as an argument.  We want to
   pass in a function like:

   .. code:: c++

      int add(int x, int y) {
          return x + y;
      }

   How would we write the argument for this in our function ``doit``?

#. Explain difference between a function that looks like:

   .. code:: c++

      void f1(double x) {
          // do stuff
      }

   and

   .. code:: c++

      void f1(double &x) {
          // do stuff
      }

Conditionals
============

#. Given ``int x;``, write an if/else statement that prints ``"even"``
   if ``x`` is even and ``"odd"`` otherwise.

#. Given ``double grade;``, write an if statement that prints ``"pass"`` if the grade
   is 60 or higher.

#. Given ``std::string s;``, write an if statement that prints ``"empty"`` if the string
   is empty.

#. Write an if-test that checks if an integer ``a`` is greater than 0 *and* a boolean
   ``test`` is true.

Loops
=====

#. Write a for loop that prints the integers 0 through 4.

#. Given ``std::vector<int> a{1,2,3,4};``, write a loop that prints each element of ``a``.

#. What is the difference in the way that these two loops work, given a vector ``vec``?

   .. code:: c++

      for (auto e : vec) {
          // do stuff
      }

   vs.

   .. code:: c++

      for (auto &e : vec) {
          // do stuff
      }

#. Given ``std::string s = "hello";``, write a loop that prints each character on its own line.

#. Given ``int n = 5;``, write a while loop that prints ``5 4 3 2 1``.

#. What is the difference between ``break`` and ``continue`` when used inside a loop?


Putting it together
===================

#. Given ``std::vector<int> a{1,2,3,4,5};``, write 1 to 3 lines that
   print all elements greater than ``3``.

#. Given ``std::string s = "apple";``, write 1 to 2 lines that print
   ``"long"`` if the string has more than 4 characters.

#. Write a function ``is_even`` that returns whether an integer is even.

#. Given ``std::vector<std::string> words{"red", "blue", "green"};``,
   write 1 to 3 lines that print each word.

#. Write a function that takes a vector of strings and returns
   the length of the longest string.

Numerical methods
=================

#. Our centered difference has a form:

   .. math::

      \left . \frac{df}{dx} \right |_{x_0} = \frac{f(x_0 + \Delta x) - f(x_0 - \Delta x)}{2 \Delta x} + \mathcal{O}(\Delta x^2)

   a. What is the meaning of $\mathcal{O}(\Delta x^2)$?

   b. If we get a error $E$ using a value $\Delta x$, what error should we
      expect if we use $\Delta x / 2$?

   c. What happens to the error if we make $\Delta x$ close to machine epsilon?

#. Given a function $f(x)$, if we want to find the zero, $x_0$, such that $f(x_0) = 0$,
   what is the requirement on the starting conditions for the bisection algorithm?

#. When we looked a integration, we saw the trapezoid rule and Simpson's rule.  Explain
   how they are different.

