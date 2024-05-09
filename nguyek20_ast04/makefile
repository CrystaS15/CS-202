# Make file for CS 202 assignment #3, magic squares

CC	= g++ -Wall -pedantic -Wextra -std=c++11 -g
OBJS	= magic.o boardTypeImp.o magicSquareImp.o
OBJS1	= bMain.o boardTypeImp.o
DEPS	= boardType.h magicSquareType.h
DEPS1	= boardType.h

all: magic

magic: $(OBJS)
	$(CC) -o magic $(OBJS)

magic.o:	magic.cpp $(DEPS)
	$(CC) -c magic.cpp

bMain: $(OBJS1)
	$(CC) -o bMain $(OBJS1)

bMain.o:	bMain.cpp $(DEPS1)
	$(CC) -c bMain.cpp

boardTypeImp.o:	boardTypeImp.cpp $(DEPS1)
	$(CC) -c boardTypeImp.cpp

magicSquareImp.o: magicSquareImp.cpp $(DEPS)
	$(CC) -c magicSquareImp.cpp

# -----
# clean by removing object files.

clean:
	rm -f $(OBJS)
	rm -f bMain.o

