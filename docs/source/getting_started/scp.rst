******************************
``scp`` and Transferring Files
******************************

When working on a remote machine, we often want to transfer files from
the remote machine to our local computer.  The tool for this is
``scp``, the `secure copy protocol <https://en.wikipedia.org/wiki/Secure_copy_protocol>`_.

.. tip::

   If you are using Windows and using PuTTY, then the ``pscp`` command can be
   used.  See `this pscp tutorial <https://tonyteaches.tech/putty-pscp-tutorial/>`_ for
   an example.

   The basic process (after installing ``pscp``) is:

   * Open ``cmd`` in Windows (you can just use the program search bar)
   * Do :samp:`pscp {username}@portal.mathlab.stonybrook.edu:/home/{username}/file.txt .`

   Notice that we write the absolute path to the file on ``portal`` and do not use
   ``~`` to reference the home directory, since that doesn't seem to work with ``pscp``.



``scp`` example
===============

Let's recreate our ``hello.cpp`` on our local machine (the computer
you are sitting in front of).

.. literalinclude:: ../../../examples/hello/hello.cpp
   :language: c++
   :caption: ``hello.cpp``

Now, we want to transfer this to ``portal.mathlab.stonybrook.edu``.  We can do this as:

.. prompt:: bash

   scp hello.cpp username@portal.mathlab.sunysb.edu:~/

Just like with ``cp``, this takes the form of :samp:`scp {source} {destination}`

Here, for destination, we have 3 parts plus some separators:

* your username on the remote machine (written as :samp:`{username}` here)
* the machine name (``portal.mathlab.sunysb.edu`` here)
* the path on the destination machine (``~/`` here)

These are separated with a ``@`` and a ``:``, in the form: :samp:`{username}@{machine}:{path}`.

In this example, we are pushing the file from our local machine to ``portal``.  We could
also pull a file from ``portal`` to our local machine.

.. admonition:: try it...

   Create a file ``test.txt`` on ``portal`` with some simple text and transfer it
   to your local machine using ``scp``.

.. important::

   In order to be able to ``ssh`` into a machine or ``scp`` a file to a remote machine,
   that remote machine needs to be setup to run an SSH server.  This is often not
   the case by default.

   This means that for this class, you should push to ``portal`` / ``portal2`` and pull
   from there, instead of initiating the ``scp`` on ``portal`` / ``portal2`` and trying
   to push to your laptop.




