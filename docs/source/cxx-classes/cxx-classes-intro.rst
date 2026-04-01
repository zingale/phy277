Introduction to Classes
=======================

.. admonition:: reading

   `C++ classes <https://en.wikipedia.org/wiki/C%2B%2B_classes>`_ from Wikipedia

Classes are a fundamental part of the `object-oriented programming <https://en.wikipedia.org/wiki/Object-oriented_programming>`_ paradigm.
A class is an object that holds both data and functions that know how to operate on the data.

.. tip::

   In C++, both ``struct`` and ``class`` create a class, with the difference being
   whether the data is publicly accessible by default.

We'll start by making a class that describes a circle:

.. literalinclude:: ../../../examples/classes/simple-class.cpp
   :language: c++
   :caption: ``simple-class.cpp``

Let's understand the syntax:

* We use ``struct`` just like we did before, but now in addition to data, there are
  functions inside the ``{ }`` that define the ``struct``.

* We start with the *member data*.  In this class, there is only piece of member data,
  ``radius``---the radius of our circle.

* We have one special function here, the *constructor*---it has the same name as the
  class, ``Circle``.  This is what is called when we create an instance of our class,
  e.g.,

  .. code::

     Circle c(2.0);

  calls our ``Circle(double r)`` function in our class ``Circle``.

* We have two *member functions*:

  * ``circumference()`` will return the circumference of the circle

  * ``area()`` will return the area of the circle

  Notice that we don't need to pass the radius into this functions.  Since they are
  members of the class, they will use the member data ``radius`` directly.  We
  invoke these on our instance of the class, e.g.,

  .. code::

     auto C = c.circumference();

  This is the power of classes---the functions work directly on the data that is
  a member of the class.

 
