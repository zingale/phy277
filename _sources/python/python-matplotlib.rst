**********
matplotlib
**********

`matplotlib <https://matplotlib.org/>`_ is the core visualization package in python.
We import it as:

.. code:: python

   import matplotlib.pyplot as plt

This puts all of the main plotting functions / classes into the ``plt`` namespace.

Anatomy of a figure
===================

.. figure:: anatomy1.png
   :align: center
   :width: 80%
   :alt: a schematic showing a figure, set of axes, and various plot elements with their corresponding matplotlib name.

   The main elements of a matplotlib figure (figure from http://matplotlib.org/faq/usage_faq.html#parts-of-a-figure)


Basic plotting
==============

Let's start with a simple example of plotting $\sin(x)$.  We'll first create
an array of $x$ values using ``np.linspace``, and then make the plot:

.. literalinclude:: ../../../examples/matplotlib/basic.py
   :language: python
   :caption: ``basic.py``

here's the figure it produces:

.. figure:: ../../../examples/matplotlib/basic.png
   :align: center
   :width: 90%

   A plot of sin(x)

Here's how we make the plot:

* We use the matplotlib `subplots <https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplots.html>`_ function to create a ``Figure`` and ``Axes`` object.

* We use `plot <https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.plot.html>`_ to make the plot, simply giving the $x$ and $y$ arrays of data to plot.

* We set the $x$ and $y$ labels using `set_xlabel <https://matplotlib.org/stable/api/_as_gen/matplotlib.axes.Axes.set_xlabel.html>`_ and ``set_ylabel`` on the ``Axes`` object.

* We use `savefig <https://matplotlib.org/stable/api/_as_gen/matplotlib.figure.Figure.savefig.html>`_ on the ``Figure`` to save a PNG file.


.. tip::

   There is a lot of additional styling that can be done.  A good place to see what
   is possible is the `examples gallery <https://matplotlib.org/stable/gallery/index.html>`_.



Visualizing 2-d arrays
======================

.. literalinclude:: ../../../examples/matplotlib/heatmap.py
   :language: python
   :caption: ``heatmap.py``

here's the figure it produces:

.. figure:: ../../../examples/matplotlib/heatmap.png
   :align: center
   :width: 90%

   A "heatmap" style plot of an array.



Other plot types
================

The `matplotlib example gallery <https://matplotlib.org/stable/gallery/index>`_ has lots
of examples of output together with the code used to produce the figure.  This is the
best way to learn.
