*******
Classes
*******

Python doesn't make a distinction between a ``struct`` and a
``class``---we always use the ``class`` keyword.  For example,
we can create our ``struct Planet`` from :ref:`sec:structplanet` as:

.. literalinclude:: ../../../examples/python/planet.py
   :language: python
   :caption: ``planet.py``

Some notes:

* In python, the constructor (``__init__``) returns an object, so
  we create a ``Planet`` like:

  .. code:: python

     p = Planet("Earth")

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

* Our ``planets`` list contains ``Planet``, this is similar to C++
  ``std::vector<Planet> planets``.

Operator overloading
====================

We can overload ``+``, ``-``, ``*``, ``/``, ... in python just like in
C++.  This is done by creating functions like ``__add__(self, x)__``
for addition, etc.  There are many of these `special method names
<https://docs.python.org/3/reference/datamodel.html#special-method-names>`_
that we can implement (see in particular the `emulating numeric types
<https://docs.python.org/3/reference/datamodel.html#emulating-numeric-types>`_
section).


Mathematical vector example
===========================

Let's implement a python version of our C++ :ref:`sec:vector2d`.

.. tip::

   We can put the class definition in its own ``.py`` file, and as long
   as that is in the same directory (or installed in a systemwide search path),
   we can ``import`` it.

   This works similar to creating a header file in C++.

Here's a python module that implements our vector class:

.. literalinclude:: ../../../examples/python/vector.py
   :language: python
   :caption: ``vector.py``

Some comments:

* We use ``isinstance`` to check if the type of ``other`` makes sense.  If not,
  we raise an `exception <https://docs.python.org/3/library/exceptions.html>`_
  that halts the execution.

* In addition to ``__str__``, we also include ``__repr__`` which is the *representation*
  of our object.  That is used when the ``Vector`` is displayed via means other than ``print``
  see this `stackoverflow discussion on __repr__ vs __str__ <https://stackoverflow.com/questions/1436703/what-is-the-difference-between-str-and-repr>`_.

* The ``/`` operator is called ``__truediv__`` in python.

* We have a ``__matmul__`` operator, which is invoked by the ``@`` operator.
  This is intended to be used for dot-products and matrix multiplication.

* Just like in C++, we treat ``vec * a`` and ``a * vec`` differently
  (where ``vec`` is a ``Vector``), since we cannot assume the objects
  commute under multiplication.  We use ``__rmul__`` to express
  right-multiplication.

and here's an example of using it---note the ``import vector`` at the top.

.. literalinclude:: ../../../examples/python/test_vector.py
   :language: python
   :caption: ``test_vector.py``

.. important::

   When we do ``import vector`` we are importing the module named ``vector``.  We
   need to use that module name as the namespace when accessing the contents of the
   module, so we do ``vector.Vector()`` to create an instance of our ``Vector`` class.
