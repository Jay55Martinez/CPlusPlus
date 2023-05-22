IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = DiceRoll.o DiceRollDef.o
_OBJ2 = Phishing.o
_OBJ3 = Maze.o MazeDef.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: DiceRoll Phishing Maze
	
DiceRoll: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

Phishing: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

Maze: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f DiceRoll
	rm -f Phishing
	rm -f Maze
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 