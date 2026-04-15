***************************
Working with Multiple Files
***************************

.. _sec:multiplefiles:

As our projects grow in size, it becomes beneficial to spread our code
over multiple files.  This has several benefits:

* It logically groups functions by task, making it easier to
  understand

* It allows for easy code reuse.

* Smaller files compile quicker than a larger file, and we only need
  to compile a file if the code changes.

* In version control, there is less chance of conflict when different
  people edit at once.

Generally speaking, we'll talk about two types of files:

* *Header files* : these contain the forward declarations of the
  functions we are going to use, as well as any types (``structs``,
  etc.) that we define.

  As we'll see shortly, we can also put entire (usually short)
  functions in headers so the compiler can *inline* the code,
  resulting in faster performance.

  A header file will be ``#include``-ed into source files.

* *Source files* : these implement the functions defined in the header
  (the function definitions corresponding to the forward declarations),
  and of course the ``main()`` function.


Splitting our planet sort example
=================================

Let's consider our example of :ref:`sorting planets <sec:sorting_planets>`.

We'll start with a header file defining our ``struct`` and the operator
declaration:

.. literalinclude:: ../../../examples/multiple_files/planet-source/planet.H
   :language: c++
   :caption: ``planet.H``

A few things to note:

* At the very top is a `header guard
  <https://en.wikipedia.org/wiki/Include_guard>`_.

  The is used to ensure that we don't include a header twice in any
  program unit.  As with the ``#include`` directives we've been using,
  the ``#ifndef`` and ``#define`` directives are processed by the
  `C preprocessor <https://en.wikipedia.org/wiki/C_preprocessor>`_.

* We only have the forward declaration for ``operator<<`` and not the
  definition of the function itself here.

.. note::

   Header files usually have the extension ``.H`` or ``.hpp``.  I'll use ``.H``
   throughout this course.


Now we'll create a source file that implements the ``<<`` operator:

.. literalinclude:: ../../../examples/multiple_files/planet-source/planet.cpp
   :language: c++
   :caption: ``planet.cpp``
We use ``"`` in the ``#include`` for ``planet.H``:

.. code:: c++

   #include "planet.H"

This gives us the forward declaration we need for this function.

.. important::

   The compiler treats

   .. code:: c++

      #include <planet.H>

   and

   .. code:: c++

      #include "planet.H"

   differently.

   When using quotes ``"..."``, the compiler will look
   in the current directory for the header first, and then in the
   system include paths.

   When using ``< ..>``, it will look in the system include
   paths, but not your current directory (unless you
   explicitly force it to).

   Additional paths to search can be specified using the ``-I``
   flag to the compiler (we won't consider this).

Finally, we'll put the ``main()`` in a third file:

.. literalinclude:: ../../../examples/multiple_files/planet-source/planet_sort_split.cpp
   :language: c++
   :caption: ``planet_sort_split.cpp``


Compiling
=========

To produce an executable, we need to compile each of the ``.cpp`` files first
and then link them all together.  Here are the steps:

.. prompt:: bash

   g++ -std=c++20 -c planet.cpp
   g++ -std=c++20 -c planet_sort_split.cpp
   g++ -o planet_sort_split planet.o planet_sort_split.o

.. note::

   We see a new compiler flag, ``-c``.  This tells the compiler to
   compile the file, but not do the final linking step to make
   the executable.  This results in an output file with the ``.o``
   extension (for *object*).

The first two commands are the compilation step.  The take the source file
and produce an object file (e.g., ``planet.cpp`` → ``planet.o``).

The final command is the link step---notice that we use the same command,
``g++``, as the compiler and linker.  In this case, we tell it the name
for our executable and then give it the list of all object files that it
needs to link together.

Notice that we don't explicitly do anything with the header file,
``planet.H``---the preprocessor includes this as part of the
compilation step.

.. admonition:: try it...

   What happens if you don't pass ``planet.o`` to the link step?


One definition rule
===================

An important concept when working with multiple files is the
`One Definition Rule <https://en.wikipedia.org/wiki/One_Definition_Rule>`_
(ODR).

This means that we can only have a single definition of a function or
type in our program.

A consequence of the ODR is that if you put a function entirely in a
header, then you need to make it `inline
<https://en.cppreference.com/w/cpp/language/inline>`_.

Here's an example of putting our ``operator<<`` function directly into the
``planet.H`` header.  Now we add ``inline`` before the function, and we no
longer need ``planet.cpp``

.. literalinclude:: ../../../examples/multiple_files/planet-inline/planet.H
   :language: c++
   :caption: ``planet.H``

We can compile the source now simply as:

.. prompt:: bash

   g++ -std=c++20 -o planet_source planet_sort_split.cpp

