****
Grep
****

.. admonition:: reading

   We will loosely follow the Software Carpentry `Finding Things
   <https://swcarpentry.github.io/shell-novice/07-find.html>`_
   lesson from `The Unix Shell
   <https://swcarpentry.github.io/shell-novice/>`_

The final handy Unix command we'll look at (for now) is ``grep``.
``grep`` searches for patterns in files (or input that is piped to it).

Let's start in ``~/shell-lesson-data/exercise-data/writing/``

Counting chapters
=================

The file ``LittleWomen.txt`` has the entire novel Little Women (along
with some copyright text indicating it is public domain).

Let's figure out how many chapters there are in Little Women.  We imagine
that the word ``Chapter`` should appear.  So let's do:

.. prompt:: bash

   grep Chapter LittleWomen.txt

This returns nothing.

If we do:

.. prompt:: bash

   man grep

we see that if we use the ``-i`` flag, then it will do the search as case-insensitive.  So
maybe that's the problem.  Let's try again, now as:

.. prompt:: bash

   grep -i Chapter LittleWomen.txt

Now we see a lot of output.  Some of it looks like:

::

    CHAPTER ONE
    CHAPTER TWO
    CHAPTER THREE
    CHAPTER FOUR

These are clearly what we were looking for.  But other instance look like:

::

    the chapter, and don't be impertinent, miss'."

This is a case where the characters in the book were talking about chapters.  That's
not what we want.

In this case, we can recognize that the actual book chapters are all upper case, so
we can do:

.. prompt:: bash

   grep CHAPTER LittleWomen.txt

And we get:

::

    CHAPTER ONE
    CHAPTER TWO
    CHAPTER THREE
    CHAPTER FOUR
    CHAPTER FIVE
    CHAPTER SIX
    CHAPTER SEVEN
    CHAPTER EIGHT
    CHAPTER NINE
    CHAPTER TEN
    CHAPTER ELEVEN
    CHAPTER TWELVE
    CHAPTER THIRTEEN
    CHAPTER FOURTEEN
    CHAPTER FIFTEEN
    CHAPTER SIXTEEN
    CHAPTER SEVENTEEN
    CHAPTER EIGHTEEN
    CHAPTER NINETEEN
    CHAPTER TWENTY
    CHAPTER TWENTY-ONE
    CHAPTER TWENTY-TWO
    CHAPTER TWENTY-THREE
    CHAPTER TWENTY-FOUR
    CHAPTER TWENTY-FIVE
    CHAPTER TWENTY-SIX
    CHAPTER TWENTY-SEVEN
    CHAPTER TWENTY-EIGHT
    CHAPTER TWENTY-NINE
    CHAPTER THIRTY
    CHAPTER THIRTY-ONE
    CHAPTER THIRTY-TWO
    CHAPTER THIRTY-THREE
    CHAPTER THIRTY-FOUR
    CHAPTER THIRTY-FIVE
    CHAPTER THIRTY-SIX
    CHAPTER THIRTY-SEVEN
    CHAPTER THIRTY-EIGHT
    CHAPTER THIRTY-NINE
    CHAPTER FORTY
    CHAPTER FORTY-ONE
    CHAPTER FORTY-TWO
    CHAPTER FORTY-THREE
    CHAPTER FORTY-FOUR
    CHAPTER FORTY-FIVE
    CHAPTER FORTY-SIX
    CHAPTER FORTY-SEVEN

and we can just read off from this that there are 47 chapters.

Of course, we could also do:

.. prompt:: bash

   grep CHAPTER LittleWomen.txt  | wc -l


What if we weren't so lucky and the word "chapter" wasn't distinguishable from
its use in the text?

In this case, we could recognize that the "chapter" we are interested in always
appears at the very start of the line.  We can use the ``^`` character in our search
to indicate that we want to start at the beginning of the line, e.g,:

.. prompt:: bash

   grep -i "^Chapter" LittleWomen.txt

There are many other patterns that we'll see can be useful, and we'll introduce those
as we need them later in the course.


Counting character appearances
==============================

One of the main characters is "Jo".  If we do:

.. prompt:: bash

   grep Jo LittleWomen.txt

we see all of her appearances, but we also see a character "John".

In this case, we can use the ``-w`` option to match on words.  If we do:

.. prompt:: bash

   grep -w Jo LittleWomen.txt

then it no longer matches "John".

