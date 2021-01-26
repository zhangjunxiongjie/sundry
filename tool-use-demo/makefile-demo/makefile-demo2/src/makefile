
# makefile 5
# head file
IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)
# build file
ODIR = obj
# static library
LDIR = ../lib
# share library
LIBS = -lm
# ???
_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 



# makefile 4
#CC = gcc
#CFLAGS = -I.
#DEPS = hellomake.h
#OBJ = hellomake.o hellofunc.o 

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake.out: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS)



# makefile 3
#CC = gcc
#CFLAGS = -I.
#DEPS = hellomake.h

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake.out: hellomake.o hellofunc.o 
#	$(CC) -o hellomake.out hellomake.o hellofunc.o 



# makefile 2
#CC=gcc
#CFLAGS=-I.

#hellomake.out: hellomake.o hellofunc.o
#	$(CC) -o hellomake.out hellomake.o hellofunc.o



# makefile 1
#hellomake.out: hellomake.c hellofunc.c
#	gcc -o hellomake.out hellomake.c hellofunc.c -I.






