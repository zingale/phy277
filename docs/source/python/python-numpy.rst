*****
Numpy
*****

The `NumPy library <https://numpy.org/>`_ extends python with an N-dimensional array,
and a large number of functions that operate on these arrays.

NumPy arrays allow you to write fast (optimized) code that works on
arrays of data. To do this, there are some restrictions on arrays:

* all elements are of the same data type (e.g. float)

* the size of the array is fixed in memory, and specified when you
  create the array (e.g., you cannot grow the array like you do with
  lists)

The nice part is that arithmetic operations work on entire arrays---this
means that you can avoid writing loops in python (which tend to be
slow). Instead the “looping” is done in the underlying compiled code.

.. note::

   In the short examples below, we will use the python interpreter
   interactively, i.e., run at the command line:

   .. prompt:: bash

      python

   then the prompt will appear as ``>>>``.


Importing
=========

The standard way to import NumPy is to rename it as you load it:

.. code:: pycon

   import numpy as np

Then we can use the ``np.`` namespace to refer to all of its functions
and classes.

.. tip::

   If NumPy is not installed on your machine, you can install it via pip:

   .. prompt:: bash

      pip install numpy

Array creation
==============

There are a few ways to create an array:

* as a sequence of integers:

  .. code:: pycon

     >>> a = np.arange(9)
     >>> a
     array([0, 1, 2, 3, 4, 5, 6, 7, 8])

* initialized with all zeros

  .. code:: pycon

     >>> a = np.zeros((3, 5))
     >>> a
     array([[0., 0., 0., 0., 0.],
            [0., 0., 0., 0., 0.],
            [0., 0., 0., 0., 0.]])

  analogous to this, there is ``np.ones``.

* from a list

  .. code:: pycon

     >>> a = np.array([1, 2, 4, 8, 16])
     >>> a
     array([ 1,  2,  4,  8, 16])

* as a evenly-spaced sequence between two limits:

  .. code:: pycon

     >>> a = np.linspace(0, 1, 11)
     >>> a
     array([0. , 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1. ])

  analogous to this, there is ``np.logspace`` for log-spaced sequences.


Array properties
================

NumPy arrays are instances of the `numpy.ndarray <https://numpy.org/doc/stable/reference/generated/numpy.ndarray.html>`_ class.
There are a large number of attributes that describe the array, including:

* ``.dim`` : the number of dimensions

* ``.dtype`` : the data type

* ``.shape`` : the shape of the array

Some of these properties can be modified.  For instance, we can do:

.. code:: pycon

   >>> a = np.arange(12)
   >>> a = a.reshape(4, 3)
   >>> a
   array([[ 0,  1,  2],
          [ 3,  4,  5],
          [ 6,  7,  8],
          [ 9, 10, 11]])
   >>> a.shape
   (4, 3)

Array operations
================

Basic math operations work element-by-element on arrays.  For example:

.. code:: pycon

   >>> a = np.array([1, 2, 3, 4])
   >>> b = np.array([10, 20, 30, 40])
   >>> a + b
   array([11, 22, 33, 44])
   >>> a / b
   array([0.1, 0.1, 0.1, 0.1])


Matrix multiplication uses the ``@`` operator.  For example, using the
same ``a`` and ``b`` as above, ``@`` will be a dot-product:

.. code:: pycon

   >>> a @ b
   np.int64(300)

For a two dimensional array, it would be the matrix multiplication operator.  Here's
an example:

.. code:: pycon

   >>> a = np.arange(9).reshape(3,3)
   >>> b = np.arange(12).reshape(3, 4)
   >>> a
   array([[0, 1, 2],
          [3, 4, 5],
          [6, 7, 8]])
   >>> b
   array([[ 0,  1,  2,  3],
          [ 4,  5,  6,  7],
          [ 8,  9, 10, 11]])
   >>> a @ b
   array([[ 20,  23,  26,  29],
          [ 56,  68,  80,  92],
          [ 92, 113, 134, 155]])


Universal functions
===================

All of the functions we saw in the ``math`` module are also available
in the ``numpy`` module, and now the ``numpy`` versions can work on
entire arrays, element-by-element.

For example, let's create an array of angles (in radians) and take the
cosine:

.. code:: python

   angles = np.linspace(0, np.pi, 9)
   >>> angles
   array([0.        , 0.39269908, 0.78539816, 1.17809725, 1.57079633,
          1.96349541, 2.35619449, 2.74889357, 3.14159265])
   >>> np.cos(angles)
   array([ 1.00000000e+00,  9.23879533e-01,  7.07106781e-01,  3.82683432e-01,
           6.12323400e-17, -3.82683432e-01, -7.07106781e-01, -9.23879533e-01,
          -1.00000000e+00])

.. important::

   The ability to do whole-array math like using operators and
   universal functions avoids the need for explicit loops.  This helps
   NumPy get good performance.

Slicing
=======
