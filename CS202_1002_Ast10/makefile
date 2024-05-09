# Name: Kristy Nguyen, NSHE ID# 5006243601, CS 202-1002, Assignment 10
# Description: sortAlgorithms makefile

CC = g++ -Wall -pedantic -Wextra -std=c++11 -g

OBJS = main.o sortAlgorithmsImp.o
DEPS = sortAlgorithms.h

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS)

main.o: main.cpp $(DEPS)
	$(CC) -c main.cpp

sortAlgorithmsImp.o: sortAlgorithmsImp.cpp $(DEPS)
	$(CC) -c sortAlgorithmsImp.cpp

# -----
# clean by removing object files

clean: 
	rm $(OBJS)