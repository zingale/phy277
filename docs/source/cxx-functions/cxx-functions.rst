*********
Functions
*********

.. admonition:: reading

   * `Functions <https://cplusplus.com/doc/tutorial/functions/>`_ from cplusplus.com


As we write increasingly complex code, it becomes helpful to split it apart into functions.  This has
several advantages:

* We can reuse the functionality provided by a function easily

* It becomes easier to test the code---we can test each function
  separately (unit tests)

* We can use the functions in other codes

* The design process becomes easier if we think of our code in terms
  of what functions are needed.  Then once we layout the flow of the
  code in terms of the major functions, we can implement them
  one-by-one.

Quite often in C++ we will split our code into multiple files, but for
now we'll work all within a single file.

Basic Example
=============

Let's start with a simple example, and then we'll talk about the structure:

.. literalinclude:: ../../../examples/functions/simple_function.cpp
   :language: c++
   :caption: ``simple_function.cpp``


Some things to note here:

* We include a `forward declaration
  <https://en.wikipedia.org/wiki/Forward_declaration>`_ of the
  function.

  .. code:: c++

     double sum(double x, double y);

  This just tells the compiler the function name, its return type, and
  what arguments it takes (and their types).  There is no function
  body.

  With this declaration, the compiler will now know that anytime we
  use ``sum()`` we need to pass it two ``double`` 's and it returns a
  ``double``.

  Often, we would put the forward declaration in a header file and the
  ``#include`` it just like we do with the standard C++ headers.

  Note that this code will compile even without the forward
  declaration because we have the actual function definition before it
  is used.  But this is not always possible.

* The function definition provides the actual implementation of the function.
  For our ``add`` function, it is:

  .. code:: c++

     double sum(double x, double y) {
        return x + y;
     }

* The function has its own scope---inside of the function, ``x`` and ``y`` are
  in scope and visible, but they are not available outside of the function.

* We use ``return`` to explicitly return a value to the caller of the function.

  Only one return will ever be executed in a function, but the
  function itself could have multiple returns that are executed
  depending on conditions inside the function itself.

.. admonition:: try it...

   #. Move the function definition to be after ``main`` and remove the
      forward declaration---does the code still compile?

   #. Now instead leave in the forward declaration, but remove the
      function definition---what happens when you compile now?


Void
====

It is possible to have a function that doesn't return anything---in
that case we mark it as ``void``.

Also, we can have a function that doesn't take any arguments.  Here's
an example:

.. code:: c++

   void hello();

   void hello() {
        std::cout << "hello" << std::endl;
   }


