/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 4
 * Description: required functions for boardType class
 */

#include <iostream>
#include <iomanip>
#include <string>

#include "boardType.h"

using namespace std;

/* constructor_identifier: verify passed size
 * parameters: size
 * return value: none */
boardType::boardType(int bSize) 
{
  bool valid; // verify passed size

  size = bSize; // set passed size to size class variable

  // Check if passed size is between SIZE_MIN and SIZE_MAX
  if (size >= BSIZE_MIN && size <= BSIZE_MAX)
    valid = true;
  else
    valid = false;

  if (valid)
  {
    // allocate memory for size rows
    board = new int * [size]; 

    // allocate the columns
    for (int i = 0; i < size; i++)
      board[i] = new int [size];

    // set all values to 0
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        board[i][j] = 0;
  }
  else 
  {
    // display error messages
    cout << "Error, invalid board size." << endl;
    cout << "No board created." << endl;
    
    board = nullptr; // board class variable set to NULL

    size = 0;
  }
}

/* destructor_identifier: delete dynamically allocated memory
 * parameters: none
 * return value: none */
boardType::~boardType()
{
  // return memory allocated to columns
  for (int i = 0; i < size; i++)
    delete [] board[i];
  
  // return memory allocated to rows
  delete [] board;
}

/* function_identifier: return contents at passed row & column
 * parameters: rows (int) and cols (int)
 * return value: rows (int) and cols (int) */
int boardType::getCell(int rows, int cols) const
{
  if ((rows < 0||rows >= size) || (cols < 0||cols >= size))
  {
    cout << "Error, invalid board location." << endl;
    return 0;
  }
  return board[rows][cols];
}

/* function_identifier: set contents at passed row and column location
 * parameters: rows (int), cols (int), value (int)
 * return value: none */
void boardType::setCell(int rows, int cols, int value)
{
  if ((rows < 0||rows >= size) || (cols < 0||cols >= size))
    cout << "Error, invalid board location." << endl;
  else
    board[rows][cols] = value;
  
  return;
}

/* function_identifier: return board size
 * parameters: none
 * return value: none */
int boardType::getOrder() const
{
  return size;
}

/* function_identifier: print grid in formatted manner
 * parameters: none
 * return value: none */
void boardType::printGrid() const
{
  cout << "   "; // empty space before very top bars

  // top bars
  for (int i = 0; i < size; i++)
    cout << " _____";
  cout << endl;

  // print each row
  for (int i = 0; i < size; i++)
  {
    // print part1: top third of cell row
    cout << "   |";
    for (int part1 = 0; part1 < size; part1++)
      cout << "     |";
    cout << endl;

    // print part2: middle of cell row
    cout << "   |";
    for (int part2 = 0; part2 < size; part2++)
      cout << setw(4) << right << board[i][part2] << " |";
    cout << endl;

    // print part3: last third of cell row
    cout << "   |";
    for (int part3 = 0; part3 < size; part3++)
      cout << "_____|";
    cout << endl;
  }

  // neatly end line for space at the bottom
  cout << endl;
  
  return;
}