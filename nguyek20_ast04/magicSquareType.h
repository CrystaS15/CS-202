#ifndef MAGIC_SQUARE_TYPE_H
#define MAGIC_SQUARE_TYPE_H

/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 4
 * Description: provide magic square creation functionality
 */


#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "boardType.h" // base class

using namespace std;

// public inheritance from boardType class
class magicSquareType : public boardType
{
  private:
    string title;
  public:
    magicSquareType(int, string); // constructor
    void createMagicSquare();
    void printMagicSquare() const;
    void readMagicSquare();
    bool validateMagicSquare() const;
    void clearMagicSquare();
    int magicNumber() const;
    string getTitle() const;
    void setTitle(string);
};

#endif
