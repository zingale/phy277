*************************
Why Use the Command Line?
*************************


We will interact with the operating system via a `command-line interface <https://en.wikipedia.org/wiki/Command-line_interface>`_.
We are all used to the point-and-click `graphical user interfaces
<https://en.wikipedia.org/wiki/Graphical_user_interface>`_ of modern
computers.  So why use the command line?

There are a few reasons (and see the excellent discussion that is part
of the `Software Carpentry Unix shell notes
<https://swcarpentry.github.io/shell-novice/instructor/instructor-notes>`_):

* Scientific computing often involves automating workflows and
  repetitive tasks.

  We want to eliminate the potential for a person to make mistakes
  as much as possible, to ensure reproducibility.  Writing scripts
  for our workflows promotes this.

* Supercomputing facilities are access via remote connections and
  almost exclusively use some type of Linux OS.

  .. tip::

     Take a look at the `Top 500 list of fastest computers
     <https://top500.org/lists/top500/2025/11/>`_

  Even a research group's server is likely accessed remotely.

* Much of the analysis software we use is written as a command line
  tool that is meant to be incorporated into a script, or chained
  together with other tools.

* It helps us understand how the computer thinks about our files and
  data.

* Unix/Linux is a multi-user operating system.  We often will be
  using shared-resources in a research group.  This means we will
  not be sitting directly in front of the computer.

The MathLab machines run `Linux
<https://en.wikipedia.org/wiki/Linux>`_ which is an open-source
`Unix-like operating system
<https://en.wikipedia.org/wiki/Unix-like>`_.  Linux powers much of the
internet and high-performance computing systems.

.. note::

   You may already be using a Unix-like operating system.

   * ChromeOS / chromebooks are running Linux
   * Android phones are running Linux
   * MacOS is a Unix-like operating system (it just hides it by default)
   * many embedded systems run Linux (routers, TVs, car entertainment systems, ...)
