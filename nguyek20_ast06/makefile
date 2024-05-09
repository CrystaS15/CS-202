# Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 6
# Description: Make file for Asst #6

CC	= g++ -Wall -pedantic -Wextra -std=c++11 -g

OBJS = main.o newtonType.o complexType.o
DEPS1 = bitmapImage.h
DEPS2 = complexType.h
DEPS3 = newtonType.h

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS) bitmapImage.o

main.o: main.cpp $(DEPS2) $(DEPS3)
	$(CC) -c main.cpp

complexType.o: complexType.cpp $(DEPS2)
	$(CC) -c complexType.cpp

newtonType.o: newtonType.cpp $(DEPS3) $(DEPS1)
	$(CC) -c newtonType.cpp

# -----
# clean by removing object file(s)

clean:
	rm $(OBJS)
