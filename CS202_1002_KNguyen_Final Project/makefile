# Name: Kristy Nguyen, NSHE ID 5006243601, CS202-1002 Final Project
# Description: Make file for Final Project

CC = g++ -Wall -pedantic -Wextra -std=c++11 -g

TOBJS =	testLLists.o 
LOBJS =	ladder.o ladderImp.o
DEPS1 =	wordLadder.h
DEPS2 =	linkedStack.h
DEPS3 =	linkedQueue.h

all: testLLists ladder

testLLists:	$(TOBJS)
	$(CC) -o testLLists $(TOBJS)

testLLists.o:	testLLists.cpp $(DEPS2) $(DEPS3)
	$(CC) -c testLLists.cpp

ladder:	$(LOBJS)
	$(CC) -o ladder $(LOBJS)

ladder.o:	ladder.cpp $(DEPS1)
	$(CC) -c ladder.cpp

ladderImp.o:	ladderImp.cpp $(DEPS1) $(DEPS2) $(DEPS3)
	$(CC) -c ladderImp.cpp

# -----
# clean by removing object files

clean:
	rm	$(TOBJS) $(LOBJS)