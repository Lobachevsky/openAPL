/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */

#include "parser.h"
#include "opt_codes.h"

/*
 * genlab -- generates label code onto label stacks.
 *
 * prologue:   AUTO-lab, CONST-linenum, NAME-lab LABEL
 *
 * epilog:   REST-lab
 */
genlab(np)
struct nlist *np;
{
   data lnumb;	//this used to be a global
   		//replaced with int lineNumber
		//needs to be recast, see below.
   /* label prologue */

   *labcpp++ = AUTO;
   labcpp += copy(IN, &np, labcpp, 1);
   *labcpp++ = CONST;
   *labcpp++ = 1;
   lnumb=(data)lineNumber;
   labcpp += copy(DA, &lnumb, labcpp, 1);
   *labcpp++ = NAME;
   labcpp += copy(IN, &np, labcpp, 1);
   *labcpp++ = LABEL;
   *labcpp = END;

   /* label epilog */

   *labcpe++ = REST;
   labcpe += copy(IN, &np, labcpe, 1);
   *labcpe = END;
}

