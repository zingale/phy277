********
Plotting
********

We can plot the solution using ``gnuplot``.

First, when you run, redirect the output to a file:

.. prompt:: bash

   ./orbit_example > orbit.dat

Now run ``gnuplot``:

.. prompt:: bash

   gnuplot

A simple plot in ``gnuplot`` is made using the ``plot`` command,
specifying the file with the data, the columns to use for x and y
axes, and any styling (like ``w l`` for *with-lines*):

.. prompt::
   :prompts: gnuplot>

   plot 'orbit.dat' using 2:3 w l
   set size square
   replot

This will make something like:

.. figure:: orbit.png
  :align: center
  :width: 80%
  :alt: the GNUplot output window showing the orbit (plotting y vs x).  It should be a circle, but instead it only completes about 90% of the circumference and the radius drifts slightly outward in the orbit.

You can save the plot as:

.. prompt::
   :prompts: gnuplot>

   set term png
   set output "orbit.png"
   replot


For more info, see: http://www.gnuplot.info/

