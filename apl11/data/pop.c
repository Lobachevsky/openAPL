/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */
/* #include <stdio.h> */
#include "apl.h"

pop()
{
   struct item *p;

   if(sp <= stack) error(ERR_botch,"pop - stack underflow");
   p=sp[-1];
   if (p) {
      switch(p->type) {
      default:
         printf("[bad type: %d]\n", p->type);
         error(ERR_botch,"pop - unrecognised type");
         break;
         
      case LBL:
         ((struct nlist *)p)->use = 0;     /* delete label */

      case LV:
         break;

      case DA:
      case CH:
         aplfree(p->datap);
         aplfree(p);
         break;

      case QQ:
      case QD:
      case EL:
      case NIL:
      case QX:
      case QV:
         aplfree(p);
      }
   }
   sp--;
}

