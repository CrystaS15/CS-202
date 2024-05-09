# Kristy Nguyen, NSHE ID# 5006243601, CS202 - 1002, Assignment #11
# Description: makefile for Assignment 9

CC = g++ -Wall -pedantic -Wextra -std=c++11 -g

OBJS = main.o
DEPS = recursionSet.h

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS)

main.o: main.cpp $(DEPS)
	$(CC) -c main.cpp

# -----
# clean by removing object files

clean: rm $(OBJS)