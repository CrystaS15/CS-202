/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS202-1002, Final Project
 * Description: Word Ladder implementation file */

#include "wordLadder.h"
#include "linkedStack.h"
#include "linkedQueue.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

/* constructor_identifier: initializes class variables
 * parameters: none
 * return type: none */
wordLadder::wordLadder () {
  count = 0;
  first = nullptr;
  ladderEnd = nullptr;
}

/* destructor_identifier: frees allocated memory for both ladder and dictionary
 * parameters: none
 * return type: none */
wordLadder::~wordLadder() {
  wordNode *current;
  wordNode *temp;

  current = first;

  while (current != nullptr) {
    temp = current->link;
    delete current;
    current = temp;
  }

  first = nullptr;
}

/* function_identifier: attempt to open and read passed dictionary file name
 * parameters:  (const char *)
 * return type: bool ()  */
bool wordLadder::readDictionary (const char *dictFileName) {
  
  ifstream inFile;
  string tempWord;

  try {
    inFile.open(dictFileName);

    if ((access(dictFileName, F_OK)) == -1)
      throw 0;

    if (!inFile.is_open())
      throw 0.0;

    while (!inFile.eof()) {
      getline(inFile, tempWord);
      insertWord(tempWord);
    }
    
    if (inFile.eof())
      inFile.close();

  }
  
  catch (int errInt) {
    if (errInt == 0) {
      // cout << "Error " << errInt << ": " << "File (" << dictFileName;
      // cout << ") does not exist." << endl;
      return false;
    }
  } 

  catch (double errDouble) {
    if (errDouble == 0.0) {
      // cout << "Error " << errDouble << ": " << "File named \"";
      // cout << dictFileName << "\" is unable to open." << endl;
      return false;
    }
  }

  return true;
}

/* function_identifier: find a word ladder
 * parameters:  (both string)
 * return type: bool () */
bool wordLadder::findLadder (const string /* word1 */, const string /* word2 */) {

  /* linkedQueue<wordNode*> myQueue;

  myQueue.enqueue(searchPtr(word1)); // enqueue pointer to first word

  wordNode *search1 = searchPtr(word1);

  search1->prev = search1; // prev pointer points to itself

  while (!myQueue.isEmptyQueue()) {

    wordNode *queueDel = myQueue.dequeue(); // dequeue an element
    wordNode *tempHead = first; 

    while (tempHead != nullptr) { // loop through dictionary
      if (tempHead->prev == nullptr) { // word is not enqueued
        
        if (isOneApart(tempHead->info, queueDel->info)) {
          tempHead->prev = queueDel;
        }

        if (tempHead->info == word2) {
          ladderEnd = tempHead;
          return true;
        }

        myQueue.enqueue(tempHead);

      }
    }
    tempHead = tempHead->link;
  } */
  
  return false;
}

/* function_identifier: attempt to find passed word in dictionary
 * parameters:  (const string)
 * return type: bool () */
bool wordLadder::validWord (const string passedWord) const {

  if (searchPtr(passedWord) != nullptr)
    return true;
  
  return false;
}

/* function_identifier: print word ladder, including header
 * parameters: none
 * return type: none */
void wordLadder::printLadder () {

  /* linkedStack<wordNode*> myStack;

  wordNode *holdEnd = ladderEnd;
  wordNode *current;

  while (holdEnd != holdEnd->prev) {
    myStack.push(holdEnd);
    holdEnd = holdEnd->prev;
  }

  current = myStack.peek();

  while (current != nullptr) {
    cout << current->info << endl;
    current = current->link;
  } */
  
  return;
}

/* function_identifier: reset prev field of every wordNode to nullptr
 * parameters: none
 * return type: none */
void wordLadder::resetLadder () {

  wordNode *current;

  current = first;

  while (current != nullptr) {
    current->prev = nullptr;
    current = current->link;
  }

  return;
}

/* function_identifier: determine if passed words are one letter apart or not
 * parameters: word1 and word2 (both const string)
 * return type: bool (true if words are one letter apart) */
bool wordLadder::isOneApart (const string word1, const string word2) const {

  int differenceCount = 0;

  for (int i = 1; i <= 5; i++) {
    if (word1[i] != word2[i])
      differenceCount++;
  }

  if (differenceCount == 1)
    return true;

  return false;
}

/* function_identifier: used by readDictionary function to insert words in linked list
 * parameters: newItem (const string)
 * return type: none */
void wordLadder::insertWord (const string newItem) {

  wordNode *current; // pointer to traverse list
  wordNode *trailCurrent = nullptr; // pointer just before current
  wordNode *last = nullptr;

  wordNode *newNode; // pointer to create node

  bool found;

  newNode = new wordNode; // create node
  newNode->info = newItem; // store newItem in node
  newNode->link = nullptr; // set link field of node to nullptr

  if (first == nullptr) { // Case 1: List is empty
    first = newNode;
    last = newNode;
    count++;
  }
  else {
    current = first;
    found = false;

    while (current != nullptr && !found) { // search list 
      
      // if info of current node >= newItem, stop search
      if (current->info >= newItem)
        found = true;
      
      // otherwise make next node the current node
      else {
        trailCurrent = current;
        current = current->link;
      }

    }

    if (current == first) { // Case 2: newItem < smallest item
      newNode->link = first;
      first = newNode;
      count++;
    }

    else { // Case 3: newItem > largest item
      trailCurrent->link = newNode;
      newNode->link = current;

      if (current == nullptr)
        last = newNode;

      count++;
    }

  }

  return;
}

/* function_identifier: search dictionary for passed word
 * parameters: searchItem (const string &)
 * return type: wordNode address (current) */
wordNode *wordLadder::searchPtr (const string &searchItem) const {

  bool found = false;
  wordNode *current;

  current = first;

  while (current != nullptr && !found) {
    if (current->info >= searchItem) {
      found = true;
    }
    else
      current = current->link;
    
    if (found)
      found = (current->info == searchItem);
    
  }

  if (found)
    return current;

  return nullptr;
}