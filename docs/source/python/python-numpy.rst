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

.. code:: python

   import numpy as np

Then we can use the ``np.`` namespace to refer to all of its functions
and classes.

.. tip::

   If NumPy is not installed on your machine, you can install it via pip:

   .. code:: python

      pip install numpy

Array creation
==============

There are a few ways to create an array:

* as a sequence of integers:

  .. code:: python

     a = np.arange(9)

  this produces:

  ::

      array([0, 1, 2, 3, 4, 5, 6, 7, 8])

* initialized with all zeros

  .. code:: python

     a = np.zeros((3, 5))

  Here we specify the shape---3 rows and 5 columns.  This produces:

  ::

     array([[0., 0., 0., 0., 0.],
            [0., 0., 0., 0., 0.],
            [0., 0., 0., 0., 0.]])

  analogous to this, there is ``np.ones``.

* as a evenly-spaced sequence between two limits:

  .. code:: python

     a = np.linspace(0, 1, 11)

  this produces:

  ::

    array([0. , 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1. ])

  analogous to this, there is ``np.logspace`` for log-spaced sequences.

Array properties
================


Array operations
================


Universal functions
===================


Slicing
=======
