***********
Homework #5
***********

.. admonition:: Completing this assignment

   For the each of the problems below, write a separate C++ program
   named in the problem :samp:`problem{N}.cpp`, where :samp:`{N}` is the
   problem number.

   .. important::

      Make sure your that ``g++`` can compile your code.  For some of
      the problems here, you will need to use ``-std=c++20``.

   Upload your C++ source files (*not the executables produced by
   g++*) to Brightspace.



.. important::

   All work must be your own.

   You may not use generative AI / large-language models for any part
   of this assignment.


1. *Computing $\epsilon$* :

   When we discussed :ref:`sec:floating_point`, we learned about $\epsilon$, the smallest
   number that can be added to one that gives a result distinct from $1$.

   .. note::

      I originally wrote "that can be added to one that gives a result
      indistinguishable from $1$".  This will differ by a factor of 2 from
      the statement above.

      For this assignment, I am not worrying about a factor of 2.  We really
      want to understand the order-of-magnitude.

   Let's estimate that now.  We will write a program that starts with
   a large guess for $\epsilon$ and then, using a loop, continually
   cuts it until roundoff makes $1 + \epsilon$ indistinguishable from
   $1$:

   Structure your program as follows:

   * initialize $\epsilon = 1$

   * loop, using a while construct, testing if $1 + \epsilon \ne 1$:

     * cut $\epsilon$ in half

   * output $\epsilon$

   You loop should continue until the test fails.  At that point, $\epsilon$
   should be close to the actual value.

   .. dropdown:: solution

      .. literalinclude:: hw5_p1_epsilon.cpp
         :language: c++
         :caption: ``epsilon.cpp``

      Note that the value printed out here is the first value for which
      $1 + \epsilon = 1$.  You may instead be interested in the last value
      that passed the loop conditions, which is twice this.

   This gives:

   ::

       epsilon ~ 1.11022e-16


2. *Projectile motion* : We'll write a simple code that does projectile motion.

   If we assume that our projectile starts at a position $(x, y) = (0, 0)$,
   and is launched with a velocity $v$ at an angle $\theta$ from the horizontal,
   then the equations of motion are:

   $$x = x_0 + v \cos\theta \, t$$
   $$y = y_0 + v \sin\theta \, t + \frac{1}{2} g t^2$$

   Use SI units, where $g = -9.81~\mathrm{m~s^{-2}}$.

   Structure your code as follows:

   * Create a ``struct`` called ``Projectile`` with 3 data members: ``t``, ``x``, ``y``

   * Ask the user for an angle (positive, from the horizontal),
     initial velocity magnitude (m/s), and a time interval $\Delta
     t$ (s) at which we want to store the projectile's position.

     .. note::

        $\Delta t$ should be chosen to be much smaller (~ few %) than
        the flight time of the projectile.

   * Create a ``std::vector`` of ``Projectile``

   * Start at $t = 0$ and $(x, y) = 0$, and loop for as long as the
     projectile is in the air ($y >= 0$).

     .. tip::

        Use a ``while`` loop here.

     * Compute the current $x$ and $y$ position of the projectile

     * Store the position in your vector.

     * Increment the time by $\Delta t$

   * Finally, output the trajectory as rows with 3 columns: $t$, $x$,
     and $y$.  Use ``std::format`` to make the data line up neatly
     in columns.

   Later we'll see how to plot this output.

   .. dropdown:: solution

      .. literalinclude:: hw5_p2_projectile.cpp
         :language: c++
         :caption: ``projectile.cpp``

      Some comments on the code:

      * We read in all 3 inputs with a single line:

        .. code:: c++

           std::cin >> angle >> vmag >> dt;

        alternately, we could do:

        .. code:: c++

           std::cin >> angle;
           std::cin >> vmag;
           std::cin >> dt;

      * We access the last element of our vector in
        our ``while`` loop:

        .. code:: c++

           while (trajectory[trajectory.size()-1].y >= 0.0)

        Each iteration through the loop, this will be reevaluated
        and ``trajectory[trajectory.size()-1]`` will always be
        the last ``Projectile`` object added to our vector.

      We can plot this by doing using gnuplot.

      .. tip::

         When outputting the header, I started with a ``#``---gnuplot
         will ignore this line (it treats anything starting with ``#``
         as a comment.

      If we want to redirect the output to a file, we need to
      have a way to send in the input that ``cin`` will read.
      We can do this as:

      .. prompt:: bash

         echo 45 10 0.1 | ./projectile > out

      This will set the angle to 45 degrees, the velocity to 10 m/s,
      and the timestep to 0.1 s.

      Here's a gnuplot script that will plot the output:

      .. literalinclude:: projectile.gp
         :language: gnuplot
         :caption: ``projectile.gp``

      and the resulting plot:

      .. figure:: projectile.png
         :width: 80%
         :align: center
         :alt: a plot of y vs. x for our projectile.

