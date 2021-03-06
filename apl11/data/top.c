/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */
#include "apl.h"

double top()
{
   struct item *p;
   double d;

   p = fetch1();
   if (p->type != DA ) error(ERR_implicit,"topval - bad data type");
   if (p->size != 1) error(ERR_implicit,"topval - size is not 1");
   d = p->datap[0];
   pop();
   return d;
}

