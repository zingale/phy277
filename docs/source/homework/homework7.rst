.. _sec:homework7:

***********
Homework #7
***********

.. admonition:: Completing this assignment

   Upload your C++ source file (*not the executables produced by
   g++*) **and** the plot output (a PNG file) to Brightspace.

   .. important::

      Make sure your that ``g++`` can compile your code.  You
      may need to use ``-std=c++20``.


.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.


1. *Projectiles with air-resistance* :

   Let’s try solving for projectile motion with drag (air resistance).

   We want to solve:

   .. math::

      \dot{\bf r} &= {\bf v} \\
      \dot{\bf v} &= \frac{1}{m} {\bf F}_a({\bf v}) - |g| \hat{\bf y}

   where ${\bf r} = (x, y)$ is the position vector, ${\bf v} = (v_x,
   v_y)$ is the velocity vector, $m$ is the mass of the projectile and

   .. math::

      {\bf F}_a({\bf v}) = - \frac{1}{2}C \rho_\mathrm{air} A |v| {\bf v}

   is the `Newton drag term
   <https://en.wikipedia.org/wiki/Projectile_motion#Trajectory_of_a_projectile_with_Newton_drag>`_
   that is applicable for large Reynolds numbers (turbulent), and
   $\rho_\mathrm{air}$ is the density of air, $C$ is the drag
   coefficient, $A$ is the cross-sectional area of the projectile.

   .. note::

      Gravity only affects the vertical ($y$) component of velocity,
      but drag affects both, since it is proportional to ${\bf v}$.

   We'll consider a baseball.  Then we can take:

   * $C = 0.3$

   * $A = \pi (d/2)^2$ with the diameter of a bassball, $d = 0.074~\mathrm{m}$

   * $m = 0.145~\mathrm{kg}$

   * $\rho_\mathrm{air} = 1.2~\mathrm{kg~m^{-3}}$

   and we take the gravitational acceleration to be $g = -9.81~\mathrm{m~s^{-2}}$,

   We’ll imagine throwing the baseball from some height, $y_0$, above the
   ground ($y = 0$) at an angle $\theta$ from the horizontal with velocity magnitude $v_0$.

   This means our initial conditions are:

   .. math::

      x_0 &= 0 \\
      y_0 &= y_0 \\
      {v_x}_0 &= v_0 \cos(\theta) \\
      {v_y}_0 &= v_0 \sin(\theta)

   and we want to integrate until the ball hits the ground,
   :math:`y(t_\mathrm{max}) = 0`.

   .. admonition:: Your task

      Solve this system using our 2nd-order Runge-Kutta method.

      You should structure your program the same way we did for our
      :ref:`sec:rk2-orbit` code in class.  The main differences will be
      to the righthand side function and the stopping criterion.

      Run the case with and without drag (you can set $C = 0$ for no
      drag), and plot the results together on the same plot.

   .. tip::

      If you have 2 output files, ``file1.txt`` and ``file2.txt``, you
      can plot both of them together in gnuplot as:

      .. prompt::
         :prompts: gnuplot>

         plot 'file1.txt' using 1:2 title "no drag", 'file2.txt' using 1:2 title "drag"

      This will plot column 2 vs. column 1 from each file as separate
      lines and label them in the plot.


   .. dropdown:: solution
      :color: muted
      :icon: pencil
      :animate: fade-in-slide-down

      Here's the code:

      .. literalinclude:: ./hw7-projectile-rk.cpp
         :language: c++
         :caption: ``projectile-rk.cpp``

      This prompts the user for the drag coefficient when run.  You can run
      both cases as:

      .. prompt:: bash

         echo 0.0 | ./projectile  > proj-nodrag.txt
         echo 0.3 | ./projectile  > proj-drag0.3.txt

      .. note::

         It's fine also if you just hardcode the value of $C$ into the
         program and recompile each time.

      To make the plot, given the output names above, we can use this
      GNUplot script:

      .. literalinclude:: projectile-drag.gp
         :language: gnuplot
         :caption: ``projectile-drag.gp``

      which produces this image:

      .. figure:: projectile-drag.png
         :align: center
         :width: 85%

         The motion of the projectile with and without drag.

