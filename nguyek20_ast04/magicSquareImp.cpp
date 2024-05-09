/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 4
 * Description: functions for magic square creation functionality
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

#include "boardType.h" // base class
#include "magicSquareType.h" // inherited class (public)

using namespace std;

/* constructor_identifier: set title and allow base class to create grid
 * parameters: bSize(int) and bTitle(string)
 * return value: none */
magicSquareType::magicSquareType(int bSize, string bTitle) : boardType(bSize)
{
  title = bTitle;
}

/* function_identifier: return magic number/sum
 * parameters: none
 * return value: magic number/sum (int) */
int magicSquareType::magicNumber() const
{
  int magicNumber = 0;
  int n = size;

  magicNumber = n * ((pow(n, 2)+1)/2);

  return magicNumber;
}

/* function_identifier: validate magic square by ensuring magic number
 * parameters: none
 * return value: whether each row/column/diagonals sum to magic number */
bool magicSquareType::validateMagicSquare() const
{
  // Sum variables
  int rowSum = 0;
  int columnSum = 0;
  int leftDiagonalSum = 0;
  int rightDiagonalSum = 0;

  // check and validate sum of each row
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      rowSum += board[i][j];

    if (rowSum != magicNumber())
      return false;
    
    rowSum = 0;
  }

  // check and validate sum of each column
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      columnSum += board[j][i];

    if (columnSum != magicNumber())
      return false;

    columnSum = 0;
  }

  // check and validate sum of left diagonal
  for (int i = 0; i < size; i++)
  {
    leftDiagonalSum += board[i][i];
  }
  if (leftDiagonalSum != magicNumber())
    return false;
  
  // check and validate sum of right diagonal
  for (int i = size-1; i >= 0; i--)
  {
    rightDiagonalSum += board[i][i];
  }
  if (rightDiagonalSum != magicNumber())
    return false;

  return true;
}

/* function_identifier: return current title value
 * parameters: none
 * return value: title(string) */
string magicSquareType::getTitle() const
{
  return title;
}

/* function_identifier: set title to passed value
 * parameters: bTitle(string)
 * return value: none */
void magicSquareType::setTitle(string bTitle) 
{
  title = bTitle;

  return;
}

/* function_identifier: reset each cell entry to 0 and clear title string
 * parameters: none
 * return value: none */
void magicSquareType::clearMagicSquare()
{
  // reset each cell entry to 0
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      board[i][j] = 0;
    }
  }

  title = ""; // clear title string

  return;
}

/* function_identifier: prompt user for a title
 * parameters: none
 * return value: none */
void magicSquareType::readMagicSquare()
{
  // Prompt to enter (size x size) Magic Square
  cout << "Enter " << size << "x" << size << " Magic Square.";
  cout << endl << endl;

  

  do
  {
    // Prompt and user input title
    cout << "Enter Title: ";
    getline(cin, title);

  } while (title.length() == 0);

  cout << endl;

  // Prompt and user input magic square values
  cout << "Enter Magic Square Values (" << size << "x" << size << ")";
  cout << endl;

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cin >> board[i][j];
    }
    //cout << endl;
  }

  cout << endl;

  return;
}

/* function_identifier: display header information
 * parameters: none
 * return value: none */
void magicSquareType::printMagicSquare() const
{
  cout << "\033[1m" << "CS 202 - Magic Squares" << endl;
  cout << "  Title: " << title << endl;
  cout << "  Magic Square, order: " << size << endl;
  cout << "  Magic Number: " << magicNumber() << "\033[0m" << endl;

  boardType::printGrid();

  return;
}

/* function_identifier: create magic square based on current order
 * parameters: none
 * return value: none */
void magicSquareType::createMagicSquare()
{


  // odd order
  if (size % 2 == 1)
  {
    int n = size;
    int i = 0;
    int j = n/2;
    
    for (int k = 1; k < n*n; k++)
    {
      // set 1st number
      if (k==1)
        board[i][j] = k;
      
      // wraps the row
      else if (i < 0 && j < size)
      {
        i = size-1;
        board[i][j] = k;
      }
      
      // wraps column
      else if (i >= 0 && i < size && j >= size)
      {
        j = 0;
        board[i][j] = k;
      }
      
      // check if number exists or out of square
      else if(board[i][j] != 0 || (i < 0 && j >= size))
        board[i+1][j] = k + 1;
      
      // default: place integer in board
      else
        board[i][j] = k;

      i--; // increment up one row
      j++; // increment up one column
    }
  }

  // multiple of 4
  else if (size % 4 == 0)
  {

  }

  // multiple of 2 but not 4
  else if (size % 2 == 0 && size % 4 != 0)
  {

  }
  
  return;
}