# Makefile for print

include ../include/makefile.common

OBJECTS = print.o ex_hprint.o ex_print.o\
	fp_print.o lt_print.o

Q.o:	$(OBJECTS)
	$(LD) -r -o Q.o $(OBJECTS)

$(OBJECTS):	../include/apl.h

print.o:	../include/format.h

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

