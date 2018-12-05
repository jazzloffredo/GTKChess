TARGET=chess_app

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=	main.o king.o queen.o bishop.o knight.o rook.o pawn.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o

king.o: src/king.c
	$(CC) -c $(CCFLAGS) src/king.c $(GTKLIB) -o king.o

queen.o: src/queen.c
	$(CC) -c $(CCFLAGS) src/queen.c $(GTKLIB) -o queen.o

bishop.o: src/bishop.c
	$(CC) -c $(CCFLAGS) src/bishop.c $(GTKLIB) -o bishop.o

knight.o: src/knight.c
	$(CC) -c $(CCFLAGS) src/knight.c $(GTKLIB) -o knight.o

rook.o: src/rook.c
	$(CC) -c $(CCFLAGS) src/rook.c $(GTKLIB) -o rook.o

pawn.o: src/pawn.c
	$(CC) -c $(CCFLAGS) src/pawn.c $(GTKLIB) -o pawn.o

clean:
	rm -f *.o $(TARGET)
