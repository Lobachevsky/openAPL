/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */

#include "apl.h"
#include <stdio.h>

/*
 * fundef - defines a function
 * Once a file has been edited by the user, this routine
 * will read into the workspace file.  It will also attempt
 * a compile of just the header and return an error if
 * the parser cannot use it.
 *
 * It uses a mix of buffered and nonbuf IO.
 */
 
int fundef(f)
{
   int a;
   char *iline, *status, *c;
   struct nlist *np;
   char b[512];
   FILE *infile;

   infile=fdopen(f,"r");	/* duplicate unbuffered file f into
   				 * buffered file infile */
   iline=alloc(LINEMAX);
   /* alloc is a wrapper for malloc, probably takes care of
    * dynamic memory alloaction.
    */
   status=fgets(iline,LINEMAX,infile);
   if (status == NULL || 0 == strcmp(iline,(char *)&"\n") ) { 
      printf("Blank function header. \n");
      return(0);
   };
   c = compile_old(iline, 2);
   aplfree(iline);
   if (c == 0 ) goto out;
   copy(IN, c+1, &np, 1);
   sichk(np);
   erase(np);
   np->use = ((struct chrstrct *)c)->c[0];
   aplfree(c);
   np->label = lseek(wfile, 0L, 2);
   fseek(infile, 0L, 0); /* set file pointer to BOF */
   while((a=fread(b, 1, 512, infile)) > 0) write(wfile, b, a);
   write(wfile, "", 1);
out:
   close(infile);
   return(1);
}

