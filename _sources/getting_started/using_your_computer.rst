***********************
Using your own computer
***********************

If you want to use your own laptop, then you have a few options:

* Use your laptop as a terminal to connect to the remove machines
  setup for this class (``portal`` and ``portal2``).

* Install the Bash shell and compilers on your laptop and develop on
  your machine directly.

* Install a Linux virtual machine on your computer.

.. tip::

   The `Software Carpentry instructions for setting your Unix
   environment
   <https://carpentries.github.io/workshop-template/install_instructions/#shell>`_
   give an excellent description of how to prepare your personal
   Windows, Mac, or Linux computer.

.. warning::

   Due to the large variations in personal machines, we cannot support
   software on your personal machine.


Using the remote servers
========================

To access ``portal`` or ``portal2``, you need to install an `SSH
client <https://en.wikipedia.org/wiki/Secure_Shell>`_ (later in the
semester, it will be helpful to have an `X11 / X Window server
<https://en.wikipedia.org/wiki/X_Window_System>`_)

Once it is installed, you can *ssh* into
``portal.mathlab.stonybrook.edu`` or
``portal2.mathlab.stonybrook.edu``.

Windows
-------

The standard SSH client for Windows is `putty
<https://www.ssh.com/academy/ssh/putty/download>`_.  This is freely
downloadable and can be installed following the instructions at that
link.

An X11 server that has been recommended for use with putty is `Xming
<http://www.straightrunning.com/XmingNotes/>`_.

MacOS
-----

You can open the ``Terminal`` app on your Mac to access the Unix shell.  MacOS usually
has an SSH client installed by default.

Later in the semester, if you want an X11 server, you can install `XQuartz <https://www.xquartz.org/>`_.
Some people recommend `doing this via Homebrew <https://formulae.brew.sh/cask/xquartz>`_


Linux
-----

If you are running Linux on your personal machine, you should already have an SSH client installed.


Using your personal machine directly
====================================

You need to install the Unix shell and compilers directly on your machine.

Windows
-------

Use the `Windows Subsystem for Linux
<https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux>`_ (version
2).  This is a virtual machine that runs from within your Windows OS
and gives you (essentially) an entire Linux environment.  To install
this, follow the instructions from Microsoft:
https://learn.microsoft.com/en-us/windows/wsl/install


MacOS
-----

You should have most of what you need, but other software can be installed via ``brew``.
See the `homebrew instructions <https://brew.sh/>`_.

.. note::

   The shell we will use in this class is `Bash
   <https://en.wikipedia.org/wiki/Bash_(Unix_shell)>`_.  Your Mac
   might use a different default shell, so some of the more advanced
   topics might differ slightly.

   You can check your shell by doing:

   .. prompt:: bash

      echo $SHELL

   If necessary, you can `change your default shell <https://support.apple.com/guide/terminal/change-the-default-shell-trml113/mac>`_.


Linux
-----

You likely have everything you need already for the class.  You can access a terminal from your
software launcher.


Using a Linux Live Distribution
===============================

A "live" distribution of Linux runs directly from a USB stick, without having to install anything locally.
It can be a little slow, but should provide all the tools you need.

One recommendation is the Fedora Linux.  You can find instructions on how to write the image to a USB stick
and boot into a live Fedora session here:
https://docs.fedoraproject.org/en-US/fedora/latest/preparing-boot-media/

For C++ programming, you will need to install the compiler *each time you start the live session* as:

.. prompt:: bash

   dnf install gcc-c++



