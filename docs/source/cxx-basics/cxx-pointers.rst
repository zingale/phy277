********
Pointers
********

.. admonition:: reading

   `pointers <https://en.wikipedia.org/wiki/Pointer_(computer_programming)>`_ from Wikipedia

Pointers are similar to references in that they provide indirect access to an object's data.
However, in C++, references are much more widely used than pointers.

References and pointers can provide similar functionality.  Pointers
are more general but also more error-prone.  Some differences,
following `differences between references and pointers
<https://en.wikipedia.org/wiki/Reference_(C%2B%2B)#Relationship_to_pointers>`_:

* A pointer is an object.  It has it's own memory where the address of
  what it is pointing to is stored.  A reference is just an alias---another
  name for something.

* We can change what a pointer is pointing to.  A reference is set when
  it is initialized and cannot be made to refer to some other object.

* A pointer can point to nothing (``nullptr``).  A reference always
  refers to something (and that is set when it is initialized).

We define a pointer by using the ``*`` operator in the declaration, e.g.,

.. code:: c++

   int *x;

We read this as ``*x`` is a pointer to an ``int``.

Here's a simple example:

.. code:: c++

   int *a = nullptr;
   int b{};

   a = &b;

This has the pointer ``a`` point to the memory location of ``b`` (we
use the *address operator* ``&`` here).  Visually, this appears as:

.. figure:: 692px-Pointers.svg.png
   :align: center
   :width: 70%
   :alt: A diagram showing pointers and the memory they point to.

   A pointer, ``a`` that points to the memory location of variable ``b``.

   (Wikipedia/Sven)

We can access the data pointed to by the pointer by using the
*dereference operator*, ``*``.

Here's a more complete version of our example above, showing both the
value of the pointer (the memory address it points to) and the value
of the data there (dereferencing the pointer):

.. literalinclude:: ../../../examples/pointers/pointer.cpp
   :language: c++
   :caption: ``pointer.cpp``

Note: the memory address you see on your computer will be different
that what someone else sees, and also change if you rerun the program
some time later.  The operating system determines where ``b`` is stored
in memory when the program is run.

Full example
============

Here's an example showing how to access data via a reference or a pointer.

.. literalinclude:: ../../../examples/pointers/pointers_example.cpp
   :language: c++
   :caption: ``pointers_example.cpp``

.. note::

   We will not use pointers directly much in this class, but they are
   useful for managing memory.  We will not go into that topic in this
   class.

.. tip::

   It is a good idea to initialize all pointers (just like we do for
   all other object types).  C++ provides ``nullptr`` for this reason:

   .. code:: c++

      int *p = nullptr;

   This then allows us to use the pointer in a conditional, like:

   .. code:: c++

      if (p) {
          // do stuff
      }

