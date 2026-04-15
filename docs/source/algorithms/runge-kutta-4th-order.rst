*********************
4th-order Runge-Kutta
*********************

One of the most widely-used methods for ODE integration is 4th-order
Runge-Kutta (RK4).  This consists of 4 stages, each estimating the
slope of the solution at a different time or with a different
prediction of the state.  These are then combined in a final update to
advance the solution.  The sequence is illustrated below:

.. tab-set::

   .. tab-item:: Stage 1

      The advance begins by estimating the derivatives (righthand side or
      slope) at time $t^n$.  We'll call this ${\bf k}_1$.

      $${\bf k}_1 = {\bf f}(t^n, {\bf y}^n)$$

      .. figure:: rk4_k1.png
         :align: center
         :width: 90%


   .. tab-item:: Stage 2

       We then follow the slope ${\bf k}_1$ to the midpoint in time,
       $t^{n+1/2}$ and evaluate the slope there.  We call the new slope ${\bf
       k}_2$.

       $${\bf k}_2 = {\bf f}(t^n + \tau/2, {\bf y}^n + (\tau/2) {\bf k}_1)$$

       .. figure:: rk4_k2.png
          :align: center
          :width: 90%


   .. tab-item:: Stage 3

      We then go back to the start, but this time follow the new slope,
      ${\bf k}_2$ to the midpoint in time, $t^{n+1/2}$.  We again evaluate
      the slope here, and call it ${\bf k}_3$.

      $${\bf k}_3 = {\bf f}(t^n + \tau/2, {\bf y}^n + (\tau/2) {\bf k}_2)$$

      .. figure:: rk4_k3.png
         :align: center
         :width: 90%

   .. tab-item:: Stage 4

      Finally, we go back to the start and follow ${\bf k}_3$ for the full
      timestep, to $t^{n+1}$ and evaluate the slope there, calling it ${\bf
      k}_4$.

      $${\bf k}_4 = {\bf f}(t^n + \tau, {\bf y}^n + \tau {\bf k}_3)$$

      .. figure:: rk4_k4.png
         :align: center
         :width: 90%

   .. tab-item:: Final update

       We then get the updated solution using a linear combination of the 4
       slopes:

       $${\bf y}^{n+1} = {\bf y}^n + \frac{\tau}{6} ({\bf k}_1 + 2 {\bf k}_2 + 2 {\bf k}_3 + {\bf k}_4)$$

       .. figure:: rk4_final.png
          :align: center
          :width: 90%

       Note the similarity of RK4 to Simpson's rule for integration.

.. admonition:: try it...

   Let's modify our orbit integration code to do RK4.

   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      .. literalinclude:: ../../../examples/numerical_algorithms/ODEs/orbit_rk4_error.cpp
         :language: C++
         :caption: ``orbit_rk4_error.cpp``

      When run, we see the convergence as:

      ::

          0.10000    0.0202442
          0.05000  0.000547327
          0.02500  1.67785e-05
          0.01250  5.22248e-07
          0.00625  1.63047e-08
