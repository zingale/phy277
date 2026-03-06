*****************
Practice Problems
*****************

Let's look at some practice problems on ``std::vector``, ``structs``, and references.


#. Let's modify :ref:`our struct Planet example <sec:vec-of-struct>` to
   add the period as a member and fill the period automatically via
   Kepler's law in a loop.


#. Create a vector with this list of names:

   ::

       luke
       leia
       han
       chewy
       obi-wan
       yoda
       vader
       lando

   Now loop over the names and use the ``std::toupper()`` function from
   ``cctype`` to capitalize the first letter in each name (updating the
   vector.

   Finally loop over the vector again and output the names.

#. Create a vector containing the numbers 0 through 9.

   Now loop over the vector, and modify each element to be the sum of
   itself and the all the previous elements.

   There are several ways to do this.  For this example, we will create
   a variable called ``previous`` that will be updated in the loop body
   to always hold the previous sum.

   Upon completion, output the new values to the screen.
