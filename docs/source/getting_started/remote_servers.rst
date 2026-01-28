************************
``portal`` / ``portal2``
************************


The remote machines we will use for this class have all the up-to-date
software we will need.  The hostnames of these machines are:

* ``portal.mathlab.stonybrook.edu``
* ``portal2.mathlab.stonybrook.edu``

You may use either or both machines, but note that they are not
mirrored.  So any files you put on one will not be reflected
on the other.


.. warning::

   After 3 unsuccessful login attempts, you will be locked out
   of the machine for an hour.

   Being locked out of ``portal`` or ``portal2`` is not an
   excuse for turning in homework late.  Plan ahead! and don't
   wait until the last minute.

.. warning::

   ``portal`` and ``portal2`` are not backed-up.  You will want
   to save any important files to another machine.

Accessing the remote servers
============================

The `ssh <https://en.wikipedia.org/wiki/Secure_Shell>`_ command allows for a secure
connection to a remote machine.  At the terminal prompt we can do:

.. prompt:: bash

   ssh -l <username> portal.mathlab.stonybrook.edu

where you replace ``<username>`` with your NetId.  You will then be prompted for
your password (the one associated with your NetId).

.. note::

   Currently the MathLab machines are misconfigured, so we need to use the
   `IP address <https://en.wikipedia.org/wiki/IP_address>`_ directly instead
   of the `hostname <https://en.wikipedia.org/wiki/Hostname>`_.

   For ``portal`` we would do:

   .. prompt:: bash

      ssh -l <username> 129.49.76.141

   and for ``portal2`` we would do:

   .. prompt:: bash

      ssh -l <username> 129.49.76.142

.. tip::

   Here we see that ``ssh`` takes options that after the command that modify the
   default behavior (sometimes we call these *switches*).  These typically start
   with a ``-`` or ``--``.

   We'll see that most Unix commands have options that we can use.

If the connection is successful, then you will should see a prompt like:

::

  [mzingale@portal ~]$

in the terminal.  This shows (the ``@portal``) that you are connected to portal.


.. TODO -- add screenshots
