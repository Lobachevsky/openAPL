# Makefile for memory 

include ../include/makefile.common

OBJECTS =  afreset.o alloc.o aplfree.o

Q.o:	$(OBJECTS)
	$(LD) -r -o Q.o $(OBJECTS)

$(OBJECTS):	../include/apl.h ../include/memory.h

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) core

