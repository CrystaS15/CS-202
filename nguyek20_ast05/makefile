# CS 202
# Make file for spirograph program

CC	= g++ -Wall -pedantic -Wextra -std=c++11 -g
OBJS	= spiro.o spiroType.o
DEPS1	= spiroType.h
DEPS2	= bitmapImage.h

all: spiro

spiro: $(OBJS)
	$(CC) -o spiro $(OBJS) bitmapImage.o

spiro.o:	spiro.cpp $(DEPS1)
	$(CC) -c spiro.cpp

spiroType.o:	spiroType.cpp $(DEPS1) $(DEPS2)
	$(CC) -c spiroType.cpp

# -----
# clean by removing object files.

clean:
	rm	$(OBJS)

