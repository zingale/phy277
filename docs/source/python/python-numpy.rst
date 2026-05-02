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


Array operations
================

Basic math operations work element-by-element on arrays.


Matrix multiplication uses the ``@`` operator.


Universal functions
===================


Slicing
=======
