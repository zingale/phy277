**************************************
Modifying ``vector`` Elements in Loops
**************************************

We've been looping over elements of a vector like this:

.. code:: c++

   std::vector<double> vec{1.0, 2.0, 3.0, 4.0};

   for (auto e : vec) {
       // do something with e
   }

Here, in the body of the loop (between the ``{ }``) we have access
to a *copy of the current element* of the vector ``vec`` (through ``e``).  We cannot
modify the contents of ``vec`` using ``e``, because ``e`` is a copy of the
current element.

If we want to modify what is actually stored in ``vec``, then we need to
access a reference to the current element in ``vec``.  We can do this as:


.. code:: c++

   std::vector<double> vec{1.0, 2.0, 3.0, 4.0};

   for (auto &e : vec) {
       // do something with e
   }

Now ``e`` is a reference to the element in ``vec``, and if we modify ``e``, then
the contents of ``vec`` reflect that change.



Example
=======

Here's an example showing different ways of accessing elements of a
vector and whether we can modify them:

.. literalinclude:: ../../../examples/references/vector_modify.cpp
   :language: c++
   :caption: ``vector_modify.cpp``

.. admonition:: try it...

   Let's modify :ref:`our struct Planet example <sec:structplanet>`
   to add the period as a member and fill the period automatically via
   Kepler's law in a loop.


