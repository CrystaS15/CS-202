#ifndef WORD_LADDER_H
#define WORD_LADDER_H

/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS202-1002, Final Project
 * Description: Word Ladder header file */

#include <string>

using namespace std;

/* Word Node Structure */
struct wordNode {
  string info;
  wordNode *prev;
  wordNode *link;
};

/* Word Ladder Class */
class wordLadder {
  private: 
    int count;
    wordNode *first;
    wordNode *ladderEnd;

    bool isOneApart (const string, const string) const;
    // determine if passed words are one letter apart or not

    void insertWord (const string);
    // used by readDictionary function to insert words in linked list

    wordNode *searchPtr (const string &) const;
    // search dictionary for passed word
    // return address of node (in linked list) if found
    // return nullptr if not found

  public: 
    wordLadder ();
    // constructor initializes class variables

    ~wordLadder ();
    // destructor frees allocated memory for both ladder and dictionary

    bool readDictionary (const char *);
    // attempt to open and read passed dictionary file name

    bool findLadder (const string, const string);
    // find a word ladder

    bool validWord (const string) const;
    // attempt to find passed word in dictionary

    void printLadder ();
    // print word ladder, including header

    void resetLadder ();
    // reset prev field of every wordNode to nullptr

};

#endif