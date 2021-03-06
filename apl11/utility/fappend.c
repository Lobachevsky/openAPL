/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */
 
#include "apl.h"

fappend(fd, ap)
struct item *ap;
{
   struct item *p;
   char *p1;
   int i, dim0, dim1, sb[32];
   char b[200];

   p = ap;
   if( p->rank != 2 && p->rank != 1 ) error(ERR_rank,"");
   if(p->type != CH) error(ERR_domain,"not character type");
   dim1 = p->dim[1];
   dim0 = p->dim[0];
   if(p->rank == 1) dim1 = dim0;
   p1 = (char *)(p->datap);
   if(p->rank == 2) {
      for(i=0; i<dim0; i++){
         copy(CH, p1, b, dim1);
         p1 += dim1;
         b[ dim1 ] = '\n';
         write(fd, b, dim1+1);
      }
   }
   else write(fd, p->datap, dim0);
}
