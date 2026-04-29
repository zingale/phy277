*********
Functions
*********

Python functions work in much the same way as C++ functions.

Here's a simple function that takes a single argument:

.. code:: python

   def func(i):
       return 2 * i

Notice:

* We start functions in python with the ``def`` keyword, followed by
  the function name, argument list, and a ``:``.

* Since python is dynamically typed, we don't need to specify the
  argument type (``i``) or the type of the return value.

* The body of the function is indented.

We can call this function simply as:

.. code:: python

   a = func(2)

.. note::

   python functions always return a value.  If you do not include a
   ``return`` statement, then a special quantity, ``None`` will be
   returned.


Keyword arguments
=================

We can have *keyword arguments* to a function.  If we do not provide a
value for these arguments when we call the function, then the default
value is used.

Here's an example:

.. code:: python

   def my_sin(theta, in_degrees=False):
       if in_degrees:
           return math.sin(math.radians(theta))
       return math.sin(theta)

If we call this without specifying ``in_degrees``, then the function will treat ``theta`` as in radians.
If we set ``in_degrees=True`` when we call the function, then it will treat it as degrees.
For example:

.. code:: python

   my_sin(math.pi/4)
   my_sin(45, in_degrees=True)



Lambda functions
================

Just like C++, python has lambda functions.  They are used in much the
same way---sometimes we need a function once, as an argument to
another function.

The syntax of a lambda function is: :samp:`lambda {args} : {statement}`,
where :samp:`{args}` are the arguments of the function.

.. note::

   Python lambda functions are limited to a single statement in the function body.
   Furthermore, we do not use an explicit ``return`` statement.

As an example, consider the `sort <https://docs.python.org/3/library/stdtypes.html#list.sort>`_
function on a list---it can take a *key* argument that provides a function
used for sorting (much like we saw in C++).

We can rewrite our C++ sorting example (see :ref:`sec:lambda-sort`) in python:

.. literalinclude:: ../../../examples/python/sort_example.py
   :language: python
   :caption: ``sort_example.py``

Some examples
=============

Trapezoid rule integration
--------------------------

Let's rewrite our :ref:`sec:trapezoid-rule` example in python.  We
want a python function ``trapezoid`` that takes a range and a function
to integrate.

.. literalinclude:: ../../../examples/python/trapezoid.py
   :language: python
   :caption: ``trapezoid.py``

Notice:

* In python, the function that we pass into ``trapezoid()`` is treated
  like any other object, and we don't need to give it a special type
  or other specifier.

* We have a multi-line string just after the function definition (in
  python, multi-line strings use triple quotes, `"""`.  This is a
  *docstring*---this is what ``help()`` provides when we ask about a
  function.

  If we do:

  .. code:: python

     help(trapezoid)

  you'll see this help.

* We use a lambda-function to pass in the integrand.



