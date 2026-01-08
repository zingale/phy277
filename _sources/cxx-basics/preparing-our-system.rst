**********************************
Preparing ``portal`` / ``portal2``
**********************************

The default compilers on ``portal`` and ``portal2`` are GCC 11.  These
are quite old, and don't support all of the language features we need.
The GCC 15 compilers are available however, so we can use those
instead.  To activate them, we need to do:

.. prompt:: bash

   scl enable gcc-toolset-15 bash

This will create a new Bash shell with the environment variables set to
point to this version of the compilers.

It is not recommended to add this command directly to our ``.bashrc``, but
we can instead create a shortcut, by adding:

.. code:: bash

   gcc15() {
      scl enable gcc-toolset-15 bash
   }

To the end of our ``.bashrc``.  Then we can just type:

.. prompt:: bash

   gcc15

To setup the compilers (we need to do this each time we log into the machines).

You can check which version of the compilers are active by doing:

.. prompt:: bash

   g++ --version

