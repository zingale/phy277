*****
Final
*****

C++
===

#. *Ranges and iterators.*

   For these questions, you have a `` std::vector`` named ``vec``:

   a. ``vec.begin()`` points to the first element of the vector.  What
      does ``vec.end()`` point to?

      .. admonition:: solution

         ``vec.end()`` points to one-past the last element in ``vec``.

   b. Consider the line: ``auto it = std::ranges::max_element(vec);``

      i.  What name did we use for the concept that ``it`` represents?

          .. admonition:: solution

             We called it an *iterator*

      ii. How do I get the value of the maximum element from ``it``?

          .. admonition:: solution

             You need to dereference it, i.e., ``*it``.

#. *Lambda-functions.* This line tests if any element in a
   ``std::vector<int>`` named ``vec`` is even:

   .. code:: c++

      auto result = std::ranges::any_of(vec, [] (int e) {return e % 2 == 0;});

   Here we provide the function that tests each element as a *lambda
   function*.  Rewrite this by writing a separate function to do this
   test, *and* show how the ``std::ranges::any_of()`` call is
   modified to call your function.

   .. admonition:: solution

      .. code:: c++

         bool is_even(int e) {
             return e % 2 == 0;
         }

         std::ranges::any_of(vec, is_even);

#. *Classes.* Consider the following class:

   .. code:: c++

      class Thing {
          double x;
          double y;

          Thing(double _x, double _y) {
              x = _x;
              y = _y;
          }
      };

   a. Both the class and a function inside the class are named
      ``Thing``---what special name do we give that function in
      the context of object-oriented programming?

      .. admonition:: solution

         We called it the *constructor*

   b. If you do ``Thing t(1, 2);`` in your ``main`` function, you get
      the compilation error:

      ::

        error: ‘Thing::Thing(double, double)’ is private within this context

      How can you fix this? (there are a few ways, be specific about
      what change you are suggesting).

      .. admonition:: solution

         You can either add ``public:`` to the body of the class (just before the constructor),
         or you can change ``class`` to ``struct``.

#. *Operators.* In our *mathematical vectors* ``Vector2d`` class, we
   had the following two operators for $-$:

   .. code:: c++

      Vector2d operator-(const Vector2d& vec) {
          return Vector2d(x - vec.x, y - vec.y);
      }

      Vector2d operator-() {
          return Vector2d(-x, -y);
      }

   What is the difference between these?  Given two ``Vector2d``
   objects, ``u`` and ``v``, give an example of operations that would
   call each of these ``-`` operators.

   .. admonition:: solution

      The first is subtraction and the other is the unary minus
      (negation).

      Doing ``u - v`` will call the first and doing ``-u`` will call
      the second.

#. Consider the following class ``Roster`` that represents a classroom
   of students:

   .. code:: c++

      struct Student {
          std::string name;
          int id{};
          double grade{};
      };

      struct Roster {
          std::vector<Student> students;

          Roster() {}

          // add your functions here
      };


   a. Write a member function for ``Roster`` named ``add_student``
      that takes a name, id, and grade (of the types defined in
      ``Student``) and adds the student to the ``students`` vector.

      .. admonition:: solution

         .. code:: c++

            void add_student(std::string name, int id, double grade) {
                Student s{.name=name, .id=id, .grade=grade};
                students.push_back(s);
            }

   b. Write a member function for ``Roster`` that returns the number
      of students.

      .. admonition:: solution

         .. code:: c++

            int num_students() {
                return students.size();
            }

#. *Software engineering.*

   a. You have a directory with multiple ``.cpp`` files and
      headers, and there is a ``GNUmakefile``.  What *single
      command* could you type to compile and link all the sources?

      .. admonition:: solution

         ``make``

   b. What tool did we cover in class that allows you to keep track of
      changes to a software project?

      .. admonition:: solution

         git

   c. I have a header file ``myheader.H`` in my directory.  For the
      ``.cpp`` file in the same directory, can I use ``#include
      <myheader.H>`` and ``#include "myheader.H"`` interchangeably?
      Why or why not?

      .. admonition:: solution

         They are not interchangeable.  You need to do ``#include
         "myheader"``---the version with quotes will first look in the
         current directory for the header file.

Python
======

6. How would you rewrite this C++ code in python using an f-string?

   .. code:: c++

      double x{2.65};
      double y{1.2e-16};
      std::cout << std::format("x = {:5.3f}, y = {:9.4g}", x, y) << std::endl;

   .. admonition:: solution

      .. code:: python

         x = 2.65
         y = 1.2e-16
         print(f"{x = {x:5.3f}, y = {y:9.4g}")

#. Rewrite this C++ code in python:

   .. code:: c++

      std::vector<int> vec{1, 5, -2, 13, 8, 9, 4, 12};
      std::vector<int> divisible{};
      for (auto e : vec) {
          if (e % 3 == 0) {
              divisible.push_back(e);
          }
      }

   .. admonition:: solution

      .. code:: python

         vec = [1, 5, -2, 13, 8, 9, 4, 12]
         divisible = []

         for e in vec:
             if e % 3 == 0:
                 divisible.append(e)

#. What is the python equivalent of:

   a. ``auto y = std::pow(x, 4);``

      .. admonition:: solution

         .. code:: python

            y = x**4

   b. ``auto y = std::sin(std::numbers::pi * x / 180);``

      .. admonition:: solution

         .. code:: python

            y = math.sin(math.pi * x / 180)

         or

         .. code:: python

            y = math.sin(math.radians(x))

Everything
==========

10. Tell me something that you learned in class that you enjoyed.
