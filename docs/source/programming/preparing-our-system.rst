**********************************
Preparing ``portal`` / ``portal2``
**********************************

.. tip::

   Review how to access our remote servers :ref:`sec:remote_servers`.


The default compilers on ``portal`` and ``portal2`` are GCC 11.  These
are quite old, and don't support all of the language features we need.
The GCC 15 compilers are available however, so we can use those
instead.  To activate them, we need to do:

.. prompt:: bash

   scl enable gcc-toolset-15 bash

This will create a new Bash shell with the environment variables set to
point to this version of the compilers.

It is not recommended to add this command directly to our ``.bashrc``, but
we can instead ``source`` a script that accomplishes the same setup by adding:

.. code:: bash

   source /opt/rh/gcc-toolset-15/enable

to the end of our ``.bashrc``.

You'll need to log in again for this to take effect.

.. important::

   You need to modify ``portal`` and ``portal2`` separately.  Files are not
   shared between the machines.

.. tip::

   You can check which version of the compilers are active by doing:

   .. prompt:: bash

      g++ --version

