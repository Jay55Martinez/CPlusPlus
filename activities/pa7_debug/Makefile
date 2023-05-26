IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -std=c++11 -O0

ODIR=.
NAME=3d_dynamic
LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = 3d_dynamic.o
_OBJ1 = 3dmatrix.o
_OBJ2 = charptr.o
_OBJ3 = practice_1.o
_OBJ4 = practice_2.o
_OBJ5 = struct.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: 3d_dynamic 3dmatrix charptr practice_1 practice_2 struct

3d_dynamic : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

3dmatrix : $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

charptr : $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

practice_1 : $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

practice_2 : $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

struct : $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f 3d_dynamic
	rm -f 3dmatrix
	rm -f charptr
	rm -f practice_1
	rm -f practice_2
	rm -f struct
	rm -f *.o
etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append  