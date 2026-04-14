*****************
A Git Walkthrough
*****************

We'll do a walkthrough on git.

.. important::

   You should install `git` on your laptop to follow along.

   For:

   * Windows: follow the `Software Carpentry bash install <https://carpentries.github.io/workshop-template/install_instructions/#shell>`_ instructions.  This will install ``git``.

   * Mac: try doing

     .. prompt:: bash

        git --version

     in a terminal.  If it is not found, then the terminal should tell you
     how to install the "command line developer tools".  Do not install XCode---we
     don't need it.

   * Linux: ``git`` is likely already installed.  If not, you can install it using your
     distribution's package manager.

There are a few ways in which we can use git.  We'll start by assuming
that we are the only developer on a project and learn the basics and
then we'll see how to share what we've done locally and remotely using
GitHub.

.. important::

   You should create a `GitHub account <https://github.com>`_.  Pick a
   username that is professional and meaningful.

Let's start by setting up our git environment:

.. prompt:: bash

   git config --global user.name "name"
   git config --global user.email "email"
   git config --global core.editor "nano -w"

Replace ``name`` with your name and ``email`` with your email.  This sets ``nano``
as our default editor, but you can choose something else that you are comfortable
with (see https://swcarpentry.github.io/git-novice/02-setup.html).

This information will be stored in a file called ``.gitconfig`` in your home directory.


Our goal here is to create a project (we'll call the directory
``project/``) and have git keep track of the files and changes to our
project.

1. First create a project directory with some basic content:

   .. prompt:: bash

      mkdir project
      cd project
      echo "this is the start of my awesome new project" > README

2. Now let's tell git that we want to track this directory.

   .. prompt:: bash

      git init

   If you do ``ls -a`` you will see a ``.git/`` sub-directory in our project now.

3. At this point, we haven't told git about any of our files.  To tell git
   to track the file ``README`` we do:

   .. prompt:: bash

      git add README
      git commit README

   .. note::

      When you ``commit``, and editor window will pop up asking you to
      make a commit message.  This is where you describe the change so
      "future you" or someone else can understand why the change was
      made.

   We can now ask git the state of our project with

   .. prompt:: bash

      git status

   You should see something like:

   .. code:: bash

      On branch main
      nothing to commit, working tree clean

   We can also see our log message:

   .. prompt:: bash

      git log

   The output will look like:

   .. code:: bash

      commit 2001a0e996110926a576dcb5fc13fc8022864d0b (HEAD -> main)
      Author: Michael Zingale <michael.zingale@stonybrook.edu>
      Date:   Sun Jan 30 13:11:24 2022 -0500

          my first change

   But should show your name, and the long string of numbers of
   letters after ``commit`` on the first line will be different.  We'll call
   the string the *hash*.  More on that later...

4. Now let's modify the file

   Open the file with nano and add a second line of text:

   .. prompt:: bash

      nano README

   Here's my file:

   .. prompt:: bash

      cat README

   .. code:: bash

      this is the start of my awesome new project
      this is now under version control!

   What does git think about our changes?

   .. prompt:: bash

      git status

   you should see something like:

   .. code:: bash

      On branch main
      Changes not staged for commit:
        (use "git add <file>..." to update what will be committed)
        (use "git checkout -- <file>..." to discard changes in working directory)

              modified:   README

      no changes added to commit (use "git add" and/or "git commit -a")

   This is telling you that you have local changes but you haven't yet
   told git to care about them.

   Let's ``add`` the changes:

   .. prompt:: bash

      git add README

   and now ``git status`` will show something like:

   .. code:: bash

      On branch main
      Changes to be committed:
        (use "git reset HEAD <file>..." to unstage)

              modified:   README

   .. admonition:: What is add really doing?

      Git has a concept call the *staging area*.  When we ``add`` a
      file, git puts the changes into the staging area.  We can add
      multiple changes via separate ``git add`` invocations, and git
      will accumulate these in the staging area.

      Once we do ``git commit``, git will record the all of the
      changes that are staged into a "commit".


   To have git track these changes, we can now just do:

   .. prompt:: bash

      git commit

   Notice that we didn't specify the file here---all the changes that
   were staged were part of that commit.

   If we now do ``git log``, we'll see that there is a second commit
   in our project, and it has a different unique hash:

   .. code:: bash

      commit 78b6925752e8388dddb3d65b6355bfeeb87b87a7 (HEAD -> main)
      Author: Michael Zingale <michael.zingale@stonybrook.edu>
      Date:   Sun Jan 30 14:23:09 2022 -0500

          make some modifications

      commit 2001a0e996110926a576dcb5fc13fc8022864d0b
      Author: Michael Zingale <michael.zingale@stonybrook.edu>
      Date:   Sun Jan 30 13:11:24 2022 -0500

          my first change

This repo now captures the state of our project.  Next we'll see how to use branches to
help our development process.


Summary
=======

We learned:

* ``git init``

* ``git add``

* ``git commit``

* ``git status``

* ``git log``
