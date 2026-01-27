*************
Shell History
*************

``history``
===========

You can do:

.. prompt:: bash

   history

To see the history of commands that you've run since the start of your
shell session (there is a limit, so very old commands may not show
up).

You can also easily repeat a command from your history by using the ``!``
operator:

* ``!`` + the number next to a command in your history (e.g., ``!100``)
  will rerun that command.

* ``!`` + a character (or several characters) will run the most recent command
  in your history that starts with the same characters.  E.g., if you have
  ``ls -l`` in your history as the most recent command starting with the letter "l", then
  doing ``!l`` will rerun that command.


Arrow keys
==========

You can scroll through your shell history using the arrow keys.

* :kbd:`↑` will scroll backwards through your history

* :kbd:`↓` will scroll forwards through your history

When you find a command you want to rerun, just hit :kbd:`Enter`.

