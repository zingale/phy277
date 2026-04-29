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

but also some differences, perhaps the biggest of which is that *there is no ``main`` function*.


Using python
============

Python is used not only for writing programs, but it is used interactively.

There are several ways we can work with python:

* Writing scripts / programs in files ending with ``.py``.
  For this we would use our editor to write the program
  and then run it via the ``python`` command, as we did above.

  .. tip::

     We can add the following line to our ``.emacs`` to have
     it automatically check our code as we write it (the same
     way we did with C++):

     ::

       (add-hook 'python-mode-hook 'flycheck-mode)

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

.. tip::

   We can use python as a calculator just by doing typing

   .. prompt:: bash

      python

   in our shell, and then typing math expressions (using much the same syntax
   as in C++), e.g.,  ``1 + 2 * 5``


Using the MathLab computers
===========================

For most of what are a going to do, we can just use the python version that
is the default on our computers (it is a bit old, but it's okay).  We can start
the python interpreter just by doing:

.. prompt:: bash

   python

When we need to install additionally libraries later, we can use the `pip command <https://pip.pypa.io/en/stable/>`_.

Using ``portal`` / ``portal2``
==============================

The default version of python on ``portal`` / ``portal2`` is python 3.9, which is quite old.
We can run python 3.12 by using the command:

.. prompt:: bash

   python3.12

you can install ipython with this version via:

.. prompt:: bash

   pip3.12 install ipython

Then when you do

.. prompt:: bash

   ipython

the ipython interpreter for python 3.12 will start up.

Using your own computer
=======================

If you want to setup python on your own computer, I would recommend
the Anaconda python distribution.  This will install the latest python
version and all of the libraries we typically need for scientific
computing.

You can download the installer at
https://www.anaconda.com/download/success?reg=skipped

Anaconda is available for Linux, Mac, and Windows, and is completely free.


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



