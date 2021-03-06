/* openAPL, Copyright (C) Branko Bratkovic 1999
 * This file is free software and is covered by the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 *
 * For more details see the GNU General Public License (GPL) in
 * the docs directory.
 */

/* Use GNU readline routine to get a line of user input */
/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
#include <stdio.h>
#include "apl.h"
#include "config.h"

/* A static variable for holding a line of user input */
static char *line_read = (char *)NULL;

char *getinput(prompt)
     char *prompt;
{
  int Length;
  char *iline;
  char input_buffer[LINEMAX];
#ifdef HAVE_LIBREADLINE
  char *readline();
  
  if(isatty(0) && use_readline) {
     /* Get a line from the user. */
     line_read=readline(prompt);
     /* check for EOF (unlikely from readline) */
     if (line_read == NULL) {
        free(line_read);
        return(NULL);
     }
     /* readline admin */
     add_history(line_read);
     /* convert line_read into apl dynamic memory */
     Length=strlen(line_read);
     iline=(char*)alloc(Length+2);
     strncpy(iline,line_read,Length+1);
     free(line_read);
     strcat(iline,"\n");	/* because readline zaps the \n */
     return(iline);
  }
  else {
#else
#warning Readline support has not been included!
  {
#endif
     printf("%s",prompt);
     /* Get a line from the user. */
     Length=(int)fgets(input_buffer,LINEMAX,stdin);
     /* check for EOF (which happens when stdin is from a file) */
     if(Length==0) return(NULL);
     /* convert static memory user_input into apl dynamic memory */
     Length=1+strlen(input_buffer);
     iline=(char*)alloc(Length);
     strncpy(iline,input_buffer,Length);
     return(iline);
  }
}
