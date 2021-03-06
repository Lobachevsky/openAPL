# openAPL

Welcome to openAPL
------------------
APL is "A Programming Language"; its strength is in the
ease with which a programmer can manipulate arrays of 
numbers.

openAPL is a GPLed open source version of APL based on the
older freely available apl\11.

APL uses a special character set that openAPL supports on the 
Linux console and under X11.

Required Additional Packages
----------------------------
In addition to openAPL, you may need some of the following:
1. If you intend to run openAPL under X11, download a copy
   of the source code for rxvt4apl from the same location as
   openAPL.  Note, RedHat Linux users may be able to use
   the rxvt that comes with their distribution.
2. If you want to print APL functions on a Postscript(TM)
   compatible printer, get a copy of a2gs (by the way, a2ps 
   will not do).
3. If you want to print APL functions on an Epson(TM) or
   compatible printer, get a copy of fprint, (ie fontprint).

Instructions
------------
Instructions for compiling and installing openAPL are located at:

...openAPL/docs/install_guide/Installation	and
...openAPL/docs/install_guide/terminals

To summarise, these are the major steps:
1. Edit the file 'configure' to select options such as destination
   directory and print filters.  Run the commands:

	$> ./configure
	$> make
and	$> make install		#as root

2. Test your Linux virtual console and/or the rxvt program for
   8-bit clean operation, (if necessary) configure, make and
   install rxvt4apl.

3. Install a print filter (optional). 

4. Fine tune the control files for things such as your preferred
   editor and X11 font.


Documentation
-------------
It is assumed that the user is familiar with APL or has
some other resource for learning it - if not, refer to
the file ...openAPL/docs/project/Resources.  User
instructions specific to openAPL can be found at 

...openAPL/docs/user_guide

Copyright
---------
openAPL, Copyright (C) Branko Bratkovic 1998, 1999
openAPL is free software and is covered by the GNU General
Public License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

For more details see the GNU General Public License (GPL) in
the directory  ...openAPL/docs.
