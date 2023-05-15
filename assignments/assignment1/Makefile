IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = fig05_06.o
_OBJ2 = find_replace.o
_OBJ3 = paragraph_stat.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: fig05_06 find_replace paragraph_stat

	
fig05_06: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

find_replace: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

paragraph_stat: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f fig05_06
	rm -f find_replace
	rm -f paragraph_stat
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 