/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */
#include "apl.h"

/*
 *   parser generates the following for each  label
 *
 *   AUTO-name  CONST  NAME-name  LABEL
 *
 *   (where CONST is the label address)
 */

ex_label()
{
   struct nlist *n;

   ex_asgn();
   n = (struct nlist *)sp[-1];
   n->itemp->type = LBL;         /* lock out assignments */
   sp--;                     /* discard stack */
}

