***********
Search Path
***********

When you enter a command at the command-line prompt, the shell needs to be able to find the command on the filesystem.
This is handled by the shell's `search path <https://en.wikipedia.org/wiki/PATH_(variable)>`_.

We can see the current path by doing:

.. prompt:: bash

   echo $PATH

If a command is not found in the search path, then you need to give the full absolute or relative path to the command.
For a command in your current directory, like ``myscript.sh``, we can do this by prepending ``./``, which means
"look in the current directory, ``.``", e.g.,

.. prompt:: bash

   ./myscript.sh


