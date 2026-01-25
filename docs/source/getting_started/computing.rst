***********
Computation
***********

`Computers <https://en.wikipedia.org/wiki/Computer>`_ essentially do 2 things:

* Store information

* Operate on this information

Computers are very good at repeating the same task over and over again.

Our goal is to learn how to write instructions (programs) to automate
operations on files (via the Unix shell) and manage data / do
numerical calculations (via C++).

Limitations
===========

Computers have a finite amount of memory and we want our answers in a
reasonable amount of time.  This means that we will need to make
approximations in a lot of our work---a great example is storing real
numbers.  You cannot store the infinite real numbers in [0, 1] with a
finite amount of memory.  So computers will approximate how real
numbers are stored---we will learn about this format shortly.

Languages
=========

In physics and astronomy, a wide range of `programming languages
<https://en.wikipedia.org/wiki/Programming_language>`_ are commonly
used.  The job of a programming language is to bridge how humans think
and how computers think.  We write a program in a human-friendly way
(plain text with English keywords expressing logic) and then a tool
called a `compiler <https://en.wikipedia.org/wiki/Compiler>`_
translates this into instructions that the computer understands.


High-level languages have extensive libraries that implement
commonly-used features that you can rely on when writing your code,
saving you time.

There are many ways we can `categorize programming languages
<https://en.wikipedia.org/wiki/List_of_programming_languages_by_type>`_
(and there are exceptions to most of what I write here).  Some
examples:

* Compiled vs. interpreted

  * A compiled language is passed through a program called a
    *compiler* that translates the human-readable source code into
    instructions that are native to the CPU in your computer.

    Examples include: C, C++, and Fortran

  * An interpreted language is processed a runtime, by running the
    program through an `interpreter <https://en.wikipedia.org/wiki/Interpreter_(computing)>`_.

    Examples include: python, ruby, mathlab

Generally speaking, compiled languages generate faster code, but
interpreted language can be easier to program in.

* Dynamic vs. static typing

  When we work with data, we are going to store it in variables with a
  descriptive name, and then refer to that name throughout the program
  to access the data.

  * Dynamically typed languages do not require us to specify up front
    what type of data we are going to store in a variable.  It is
    inferred at runtime.

    This can give a lot of flexibility to codes.

    python is an example.


  * Statically typed languages require you to specify up front what
    type of data will be stored in a variable.

    This can allow the compiler to optimize the code.

.. note::

   You can implement any algorithm in any of these languages, but some
   make it easier than others.

Why C++?
========

This course aims to teach a compiled language, and traditionally,
Fortran and/or C++ are taught.

We will focus only on `C++ <https://en.wikipedia.org/wiki/C%2B%2B>`_.

C++ is:

* a modern compiled language

* updated with new features frequently (currently a 3-year cycle)

* used extensively in physics (in particular in high-energy physics
  and in high-performance computing in astrophysics)

* versatile

* widely used outside of academic research environments---this means
  that you can take your C++ skills to industry jobs if desired

.. important::

   We will focus on the `C++20 standard <https://en.wikipedia.org/wiki/C%2B%2B20>`_.
