IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.
NAME=BestDeals
LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(NAME).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	./$(NAME)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f $(NAME)
	rm -f *.o
etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append  