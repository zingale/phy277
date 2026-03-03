**********************
Memory: Stack vs. Heap
**********************

.. admonition:: reading

   `Stack vs. heap memory allocation <https://www.geeksforgeeks.org/dsa/stack-vs-heap-memory-allocation/>`_ from geeksforgeeks.

``std::vector`` and ``std::array`` also use different regions of memory
in the computer.

Stack
=====

The stack is where the variables we have been creating like:

.. code:: c++

   double x{};
   int a{};

live (this is not required by C++, but it is what most systems do).
These are sometimes called `automatic variables
<https://en.wikipedia.org/wiki/Automatic_variable>`_.  When we enter a
program unit (like ``main``) these variables are placed on the *stack*
(in the order we encounter them).  And when we leave the program unit,
they are popped off, automatically freeing up the resources.

Note that the stack is generally small, and if we try to put too much data on the stack, we can encounter a `stack overflow <https://en.wikipedia.org/wiki/Stack_overflow>`_ and the program will crash.

``std::array`` (typically) puts its data on the stack.

 
Heap
====

The heap is the region of memory where dynamically allocated resources
typically live---this means that the memory is allocated at runtime.
We won't consider manual memory management in this class, but ``std::vector``
will allocate its memory on the heap.

In older C++, we needed to be careful to manually free the memory on the heap,
since it is not automatic, as with the stack.  This could lead to memory leaks
and crashes.  In modern C++, for objects like ``std::vector``, when the object
goes out of scope (e.g., we leave the function where we created it), a special
function called the destructor is automatically called freeing the resources.

