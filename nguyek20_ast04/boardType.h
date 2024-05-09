#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H

/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 4
 * Description: provides basic puzzle board functionality
 */

class boardType 
{
  protected:
    int size;
    int **board;
  private:
    static const int BSIZE_MIN = 3;
    static const int BSIZE_MAX = 50;
  public:
    boardType(int); // constructor
    ~boardType(); // destructor
    void setCell(int, int, int);
    int getCell(int, int) const;
    int getOrder() const;
    void printGrid() const;
};

#endif