/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */
#include "apl.h"
/* #include <string.h>
#include <dirent.h> */

clear()
{
   struct nlist *n;

   for(n=nlist; n->namep; n++) {
      n->use = 0;
      n->itemp = 0;
      n->namep = 0;
   }
   afreset();   /* release all dynamic memory */
   gsip = 0;   /* reset state indicator */

   iorigin= INITIAL_iorigin;
   pagewidth= INITIAL_pagewidth;
   PrintP= INITIAL_PrintP;
   tolerance = INITIAL_tolerance;

}
