********************
Working with Strings
********************

Find and Replace
================

``string`` has find and replace member functions.  Here's an example of
extracting the basename of a file from a path and then replacing the
extension.

There are a lot of different ways we can do a replace:
`std::string::replace calls
<https://www.cplusplus.com/reference/string/string/replace/>`_ .

.. literalinclude:: ../../../examples/strings/string_replace.cpp
   :language: c++
   :caption: ``string_replace.cpp``

.. tip::

   C++17 introduced the ``filesystem`` library that includes a `stem
   function <https://en.cppreference.com/w/cpp/filesystem/path/stem>`_
   that can do this as well.  We'll look at the filesystem library
   later.

Other Functions
===============

There are a large number of member functions that work on strings.
See for instance: https://www.cplusplus.com/reference/string/string/


.. admonition:: try it...

   Let's try to use ``std::string::find_first_of``, following this:
   https://www.cplusplus.com/reference/string/string/find_first_of/
