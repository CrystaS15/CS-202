# Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 7
# Description: Make file for Asst #7

CC = g++ -Wall -pedantic -Wextra -Wextra -std=c++11 -g

OBJS = main.o
DEPS1 = statsType.h

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS)

main.o: main.cpp $(DEPS1)
	$(CC) -c main.cpp

# -----
# clean by removing object file(s)

clean:
	rm $(OBJS)