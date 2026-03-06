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


1. We'll write a simple code that does projectile motion.

   If we assume that our projectile starts at a position $(x, y) = (0, 0)$,
   and is launched with a velocity $v$ at an angle $\theta$ from the horizontal,
   then the equations of motion are:

   $$x = x_0 + v \cos\theta \, t$$
   $$y = y_0 + v \sin\theta \, t + \frac{1}{2} g t^2$$

   Use SI units, where $g = -9.81~\mathrm{m~s^{-2}}$.

   * Create a ``struct`` called ``Projectile`` with 3 data members: ``t``, ``x``, ``y``

   * Ask the user for an angle (positive, from the horizontal),
     initial velocity, and a time interval $\Delta t$ at which we want
     to store the projectile's position.

   * Create a ``std::vector`` of ``Projectile``

   * Start at $t = 0$ and $(x, y) = 0$, and loop for as long as the
     projectile is in the air and:

     * Compute the current $x$ and $y$ position of the projectile

     * If $y < 0$ exit the loop; otherwise, store the position in your vector.

       .. tip::

          Use a ``while`` loop here.

     * Increment the time by $\Delta t$

   * Finally, output the trajectory as rows with 3 columns: $t$, $x$, and $y$.

   Later we'll see how to plot this output.


