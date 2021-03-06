/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */

#include "apl.h"

ex_shell(){

   /* If the environment variable SHELL is defined, attempt to
    * execute that shell.  If not, or if that exec fails, attempt
    * to execute the standard shell, /bin/sh
    */

   char *getenv(), *sh, cmd[128];

   sh = getenv("SHELL");
   if (sh == 0) sh = "/bin/sh";
   system(sh);
}

