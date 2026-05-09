*****************
Final Exam Review
*****************

.. note::

   The final exam will cover the topics since the previous exam.

   Python will be part of the exam, however, there will not be
   questions on NumPy and matplotlib, since we did not have enough
   time to practice those.

.. important::

   This set of examples is not exhaustive, so you should go back and
   read through the notes, run the example codes, and look at my
   homework solutions.


File I/O
========

#. You create a file as:

   .. code:: c++

      std::ofstream of("file.txt");

   a. How do you output a string to it?

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         You simply use the output stream operator, ``<<``:

         .. code:: c++

            std::string s{"hello"};
            of << s;

   b. If the file already exists, what happens to its existing
      contents when you open it this way?

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         The contents are overwritten.  To append to the file,
         see the discussion at the end of :ref:`sec:cxx-io`.

   c. How would you change this line if you wanted to *read from*
      ``file.txt``?

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         You would need to create a ``std::ifstream``---this is the input stream.

Standard Library Algorithms
===========================

#. Given a ``std::vector<int> v{2, 5, 8, 5, 10};``, write one line using
   ``std::ranges::count`` to count how many times 5 appears.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. code:: c++

         auto num = std::ranges::count(v, 5);

      This will look over the entire vector and count how many ``5`` it contains.

#. What does ``v.end()`` point to? Why should an iterator loop usually stop at it
   ``< v.end()`` or it ``!= v.end()`` instead of including ``v.end()``?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      ``v.end()`` points to *one-past* the end of the vector.

#. Use ``std::ranges::find`` to search for 8 in a vector. What should you check
   before dereferencing the returned iterator?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      We should check if it is pointing to ``v.end()``, like:

      .. code:: c++

         bool found{};
         auto it = std::ranges::find(v, 8);
         if (it != v.end()) {
              found = true;
         }

#. Write a lambda that returns true if an integer is odd. Then use it with
   ``std::ranges::count_if``.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      Assuming our vector is called ``v``, we can do:

      .. code:: c++

         auto num = std::ranges::count_if(v, [] (int e) {return e % 2 != 0;});

      The lambda-function here, ``[] (int e) {return e % 2 != 0;}``, captures
      nothing from the surrounding scope (``[]``), takes a single int ``e`` as
      the argument, and then checks the modulus of ``e`` with 2 to determine
      if it is odd.  The return value here is ``bool``, which C++ can determine
      automatically.

#. For ``std::views::iota(3, 8)``, what values are produced?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      This produces the sequence of integers that starts at ``3`` and goes up
      to, but not including ``8``, so it would result in ``3, 4, 5, 6, 7``.
      This behavior is identical to python's ``range()`` function.

#. Suppose an iterator ``pos`` points to the element 200 in a vector. What
   does ``v.insert(pos, 150)`` do?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      This will insert the number ``150`` into the vector ``v`` just before
      the element ``200``.

#. In this example, we use a *lambda function*.  If we instead wanted
   to use a traditional function, how would we rewrite this (show both
   the new function and the updated ``sort`` call).

   .. code:: c++

      std::ranges::sort(titles,
                        [] (const std::string& a, const std::string& b)
                           {return a.size() < b.size();});

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      We would first write a function that returns a ``bool``, like:

      .. code:: c++

         bool compare(const std::string& a, const std::string& b) {
             return a.size() < b.size();
         }

      and then our call would look like:

      .. code:: c++

         std::ranges::sort(titles, compare);

Software Engineering / Version Control
======================================

#. These lines are in a ``GNUmakefile``:

   .. code:: make

      planet_sort_split.o: planet_sort_split.cpp planet.H
           g++ -std=c++20 -c planet_sort_split.cpp

   a. In the first line, what does the name to the left of the ``:`` mean?
      and what are the files to the right of the ``:``?

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         The name before the ``:`` is the *target*---it is what we want to produce.
         The list of files after the ``:`` are the dependencies---those are the
         files we need in order to make the target.

   b. What does the ``-c`` do in the ``g++`` command?

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         This simply compiles the file without linking it to make an executable.  It
         produces an object file (``planet_sort_split.o`` in this case).

         In general, we do this on files that don't contain a ``main`` function,
         and then once all the object files are created, we *link* them together
         to make the executable.

#. If I compile a ``program.cpp`` as:

   .. prompt:: bash

      g++ -O3 -o program program.cpp

   what is the meaning of ``-O3``?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      This enables optimization (and in this case, a high-level of optimization).  The
      resulting code can run much faster than unoptimized code.

#. ``git status`` shows ``newton.cpp`` under ``Untracked files``---how
   do you put this file under git control?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      We need to *add* it to our git repository, by doing:

      .. prompt:: bash

         git add newton.cpp

#. What does it mean for a variable to be *shadowing* another variable in C++?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      This means that we created a object with the same name as one in
      the surrounding scope.  This may not be a problem, but if we
      think that we are actually working on the version of the object
      in the outer scope, then our local copy will *shadow* that and
      any changes we make to it will not be reflected in the outer scope.

#. We have a header ``solver.H`` in our current directory.  This
   header provides a function ``newton`` in it.  We want to use this
   in our code.  How do we include this header so the compiler will
   find it.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      You need to use ``"`` in the ``#include``, like:

      .. code:: c++

         #include "solver.H"

      See :ref:`sec:multiplefiles`.

Classes
=======

#. What is the main difference between a ``struct`` and a ``class`` in C++?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      The default accessibility of member data and functions.  With ``class``, everything
      is private by default, so we need to explicitly make it ``public``.  With ``struct``,
      everything is public by default.

#. What is a constructor, and when is it called?  What name is given
   to the constructor function?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      The constructor is the special member function that is called when we create
      an object / instance of our class.  The constructor function has the same
      name as the class.

#. What is an initialization list? In the code below, what member data is initialized?

   .. code:: c++

      SolarSystem(double mass)
          : star_mass(mass)
      {}

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      Here, the initialization list is the `: star_mass(mass)` following the constructor
      function's arguments.  It initializes member data as the object is created, and
      before the body of the constructor function is executed.

      In this example, we are initializing the member data ``star_mass``.

#. Consider the following:

   .. code:: c++

      struct Circle {

          // member data
          double radius{};

          // constructor
          Circle(double r) {
              radius = r;
          }
      };

   a. How would you create a ``Circle`` with a radius of ``5``?

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

          .. code:: c++

             Circle c(5);

   b. Rewrite this to make the member data private
      and add a *getter* function that returns the radius.

      Show how you would call this function given a ``Circle`` object ``c``.

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         .. code::

            class Circle {

            private:

                // member data
                double radius{};

            public:

                // constructor
                Circle(double r) {
                    radius = r;
                }

                // getter
                double r() {
                    return radius;
                }
            };

         We would call this as:

         .. code::

            auto radius = c.r();

   c. How would you add another constructor that takes no arguments
      and sets the radius to ``1`` by default?

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         The second constructor would have the same name, but a different
         argument list (so C++ can tell them apart).  In this case, it would
         take no arguments:

         .. code:: c++

            Circle() {
                radius = 1;
            }

#. In our ``Vector2d`` class, we had 2 different operators for
   multiplying by a scalar:

   .. code::

      Vector2d operator*(double a) {
          return Vector2d(x * a, y * a);
      }

      friend Vector2d operator*(double a, const Vector2d& v);

   What is the difference between these?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      The first is a member function, and for a ``Vector2d`` named ``v`` and
      a scalar ``a``, it would be invoked when our ``Vector2d`` is to the left
      of the multiplication operator, i.e. ``v * a``.

      The second is a friend.  The function itself is outside of the class, so
      it is not a member function.  This is involved when our class is to the
      right of the operator, i.e., ``a * v``.

#. Write a class ``Timer`` with private member data ``seconds`` and a member function
   ``add_time(double dt)`` that adds ``dt`` to the stored ``seconds``, and another
   member function, ``get_time()`` that returns the stored time.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. code:: c++

         class Timer {

             double seconds;

         public:

             Timer()
                 : seconds{}
             {}

             void add_time(double dt) {
                 seconds += dt;
             }

             double get_time() {
                 return seconds;
             }
         };

#. Currency exchange.

   a. Create a class called ``Currency`` that holds a ``double`` and a
      ``string``.  The ``double`` is the ``value`` and the ``string`` is the
      ``country`` of the currency (e.g., ``"US"``, ``"Euro"``, ...).  Give
      a constructor that takes both pieces of data.

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         .. code:: c++

            class Currency {

                double value;
                std::string country;

            public:

                Currency(double v, std::string c)
                    : value(v), country(c)
                {}
            };

   b. We want to be able to add two ``Currency`` objects.  The operator
      function will look like:

      .. code:: c++

         Currency operator+ (const Currency& other)

      Fill in the details---include a check that we are adding currencies from
      the same country.

      .. dropdown:: solution
         :color: muted
         :icon: pencil
         :animate: fade-in-slide-down

         The operator function would look like:

         .. code:: c++

            Currency operator+ (const Currency& other) {
                if (country != other.country) {
                    std::cout << "Error: countries do not match" << std::endl;
                    std::exit(1);
                }
                return Currency(value + other.value, country);
            }

Python
======

#. What is the python version of a C++ ``std::vector`` that we focused
   on in class?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

       A list.  In python we create a list using ``[]``.

#. Given the following:

   .. code:: python

      a = [1, 2, 4, 8, 16]

   write a loop (in python) that loops over the elements
   and prints them out.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. code:: python

         for e in a:
             print(e)

#. Some times in class, I put an ``f`` in front of the ``"`` in a
   string---what does this mean?

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      This is a f-string or format-string.  It uses similar formatting codes
      as C++ ``std::format``, but also allows us to put the object we are outputting
      inside that ``{}``, before the ``:``.

#. How would I write this C++ if-test in python?

   .. code:: c++

      int sign;
      if (x == 0) {
          sign = 0;
      } else if (x > 0) {
          sign = 1;
      } else {
          sign = -1;
      }

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. code:: python

         if x == 0:
             sign = 0
         elif x > 0:
             sign = 1
         else:
             sign = -1

      Notice that in python we don't need to declare our ``sign`` outside of the
      if-block---scoping works differently in python.

#. What is the python equivalent of this C++ code

   .. code:: c++

      double x{2.5};
      double y{1.2};

      double z = std::pow(x, y);

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      We can use the ``**`` operator, so we can do:

      .. code:: python

         x = 2.5
         y = 1.2
         z = x**y

#. What is the result of the following python code:

   .. code:: python

      def func(x, normalization=None):
          xi = x
          if normalization:
              xi = x / normalization

          return xi**3 + xi + 1

      func(2, normalization=2)

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      We are using the keyword argument ``normalization``, so inside
      the function, ``normalization`` will have the value ``2``.  So
      ``xi`` will be ``1`` in the function (``2 / 2``), and we get
      ``3`` as the result.

#. This was the first class we wrote in C++:

   .. code:: c++

      struct Circle {

          // member data
          double radius{};

          // constructor
          Circle(double r) {
              radius = r;
          }

          // member functions
          double circumference() {
              return 2.0 * std::numbers::pi * radius;
          }

          double area() {
              return std::numbers::pi * radius * radius;
          }

      };

   write a python version of it.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

       .. code:: python

          class Circle:
              def __init__(self, r):
                  self.radius = r

              def circumference(self):
                  return 2.0 * math.pi * self.radius

              def area(self):
                  return math.pi * self.radius**2

       In python, the constructor is ``__init__`` and all member
       functions (or methods in python lingo) have ``self`` as the
       first argument.
