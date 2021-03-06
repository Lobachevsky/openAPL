/* Copyright U S WEST Advanced Technologies, Inc.
 * You may use, copy, modify and sublicense this Software
 * subject to the conditions expressed in the file "License".
 */
#include <signal.h>
#include <stdio.h>
#include "apl.h"
#include "config.h"

#ifdef HAVE_LIBREADLINE
#include <readline/readline.h>
#endif
 
char headline[] = 
"openAPL "
"Version 0"
#include "patchlevel.h"
"\n";

main(argc, argp)
char **argp;
{
   int pid, sigs, file_id ;
   static int fflag;
   int intr();
   struct apl_statement *input_line;

#ifdef HAVE_LIBREADLINE
/* Allow conditional parsing of the ~/.inputrc file. */
rl_readline_name = "openapl";
#endif


   mkcore = 0;		/* if "1", produce core image upon fatal error */
   normalExit = 0;	/* set to true when doing a normal exit */
   sandboxflg = 0;	/* initial security value, changed by command line */
   sandbox = sandboxflg;	/* sandbox is set whenever Quad-LX is run,
   				 * upon return it is set to sandboxflg */
   time(&startTime);

   /* setup scratch files */
   pid = getpid();
   scr_file = malloc(32);
   ws_file = malloc(32);
   sprintf(scr_file, "/tmp/apled.%d", pid);
   sprintf(ws_file, "/tmp/aplws.%d", pid);

   //input_line=(struct apl_statement *)alloc(sizeof(struct apl_statement));
   //current_line=&input_line;
  
   sigs = 1;

   /* other flags... */
   echoflg = !isatty(0);
   use_readline=0;

   /* diagnostics */
   mem_trace = 0;	/* dynamic memory allocation */
   code_trace = 0;	/* pseudo code */
   stack_trace = 0;	/* local stack */

   while(argc > 1 && argp[1][0] == '-'){
      argc--;
      argp++;
      while(*++*argp) switch(**argp){
      case 'e':   echoflg = 1;   break;
      case 'q':   echoflg = 0;   break;
      case 'd':
      case 'D':   sigs = 0; break;
      case 'c':
      case 'C':   mkcore = 1;   break;
      case 'r':   use_readline=1; break;
      case 't':   scr_file  += 5;
                  ws_file += 5; break;
      case 's':   sandbox = sandboxflg = 1; break;
      }
   }

   /* initialisation */
   iorigin= INITIAL_iorigin;
   pagewidth= INITIAL_pagewidth;
   PrintP= INITIAL_PrintP;
   tolerance = INITIAL_tolerance;
   quote_quad_prompt[0] = '\0';

   zero = 0;
   one = 1;
   pi = 3.141592653589793238462643383;

   if (sigs) catchsigs();                  /*   Catch signals  */
   fppinit();

   /*
    * open ws file
    */

   close(opn(WSFILE,0600));
   wfile = opn(WSFILE,2);

   sp = stack;
   fflag = 1;
   ifile = 0;
   if (signal(SIGINT, intr) == -1) signal(SIGINT, SIG_IGN);
   printf(headline);
   //setexit();
   if(fflag) {
      fflag = 0;
      if(argc > 1 && (file_id = opn(argp[1], 0)) > 0){
         wsload(file_id);
         printf(" %s\n", argp[1]);
         close(file_id);
      }
      else {
         if((file_id=open("continue",0)) < 0) printf("clear ws\n");
         else {
            wsload(file_id);
            printf(" continue\n");
            close(file_id);
         }
      }
      eval_qlx();               /* eval latent expr, if any */
   }
   //setjmp(reset_env);
   /* return to this point to reset the state and context to original */
   setjmp(cold_restart);

   gsip=&prime_context;	/* global state indicator */ 
   gsip->Mode=immed;
   gsip->suspended=0;
   gsip->prev=(struct Context *)NULL;
   gsip->sp=0;
   gsip->ptr=0;
   gsip->text=(char *)NULL;
   gsip->pcode=(char *)NULL;
   //gsip->xref=(char *)NULL;
   //setjmp(gsip->env);	/* come back here after longjmp() */

   mainloop();
}

