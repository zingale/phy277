*******************
Python Introduction
*******************


Hello, World
============

Let's start by a simple "Hello, World" program.
Put the following into a file ``hello.py``:

.. code:: python

   print("Hello, World")

and then we can run it as:

.. prompt:: bash

   python hello.py

This invokes the *python interpreter*, ``python``, which runs the code in our file.
We can already see some similarities with C++:

* ``print()`` is a function that takes arguments

* ``"Hello, World"`` is a string.


Using python
============

There are several ways we can work with python:

* Writing scripts / programs in files ending with ``.py``
  For this we would use our editor to write the program
  and then run it via the ``python`` command, as we did above.

* Interactively, using the interpreter as a REPL, just
  like we saw with Bash in our discussion :ref:`sec:the_shell_repl`.

  * We can use the python, or `ipython <https://ipython.org/>`_
    interpreter for this.  These support command recall via
    the arrow keys and tab-completion.

  * We can use `jupyter notebooks <https://jupyter.org/>`_,
    which gives us a web-based environment for working with
    python, and can include code, plain text, output, and plots
    all in a single document (a notebook).

We will mostly work with just ``python``, both interactively
and for running scripts.


Learning more
=============

There are lots of resources online for learning more about python:

* Software carpentry offers 2 lessons on python, `programming with python <https://swcarpentry.github.io/python-novice-inflammation/>`_
  and `plotting and programming in python <https://swcarpentry.github.io/python-novice-gapminder/>`_ which give excellent
  walk-troughs of using python on real datasets.

* The `official python tutorial <https://docs.python.org/3.14/tutorial/index.html>`_
  is an excellent place to build off of the C++ knowledge we developed this semester.

* I have `python for scientific computing <https://sbu-python-class.github.io/python-science/Introduction.html>`_
  course notes online.



