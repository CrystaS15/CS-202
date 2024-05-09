# Name: Kristy Nguyen, NSHE ID #5006243601, CS 202-1002, Assignment 8
# Description: bookDataType makefile

CC = g++ -Wall -pedantic -Wextra -std=c++11 -g

OBJS = books.o bookDataTypeImp.o
DEPS = bookDataType.h

all: books

books: $(OBJS)
	$(CC) -o books $(OBJS)

books.o: books.cpp $(DEPS)
	$(CC) -c books.cpp

bookDataTypeImp.o: bookDataTypeImp.cpp $(DEPS)
	$(CC) -c bookDataTypeImp.cpp

# -----
# clean by removing object files

clean: 
	rm $(OBJS)