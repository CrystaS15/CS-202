/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: dateType class inherited from dayType
 * Input: none
 * Output: none */

#ifndef DATE_TYPE_H
#define DATE_TYPE_H

#include <string>
#include "dayType.h" // base class

using namespace std;

class dateType : public dayType {
  public:
    dateType();
    dateType(int, int, int);
    void printFormattedDate() const;
    string getMonthName() const;
    string getDayName() const;
    void nextDay();
    void nextDay(int);
    void prevDay();
    void prevDay(int);
    void setDate(int, int, int);
    void readDate();
  private:
    // no private
  protected:
    string monthName;
    string dayName;
    void setDateStrings();
    int getDayNumber(int, int, int) const;
};

#endif