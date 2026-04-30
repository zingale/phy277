*******
Classes
*******

Python doesn't make a distinction between a ``struct`` and a
``class``---we always use the ``class`` keyword.  For example,
we can create our ``struct Planet`` from :ref:`sec:structplanet` as:

.. literalinclude:: ../../../examples/planet.py
   :language: python
   :caption: ``planet.py``

Some notes:

* The ``__init__`` function is the constructor in python.  Unlike C++,
  in python, there is only a single constructor.

* All member functions (methods) of the class take a first argument
  traditionally called ``self``.  This is the python equivalent of the
  C++ ``this`` pointer.  ``self`` refers to the object that we are
  working on (an instance of the class).

  When we access data stored in the class, we do it through ``self``,
  e.g., ``self.name``.

* The ``_str__`` method is python's version of overloading ``<<`` for
  output.  This is the function that is called when we ``print()`` a
  ``Planet``.  It returns a string that we would like ``print`` to
  display.


