/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: dayType class
 * Input: none
 * Output: none */

#ifndef DAY_TYPE_H
#define DAY_TYPE_H

class dayType {

    public:
      dayType(int=1, int=1, int=1970);
      void printDate() const;
      int getDate() const;
      int getMonth() const;
      int getYear() const;
      void setDate(int, int, int);
      void readDate();
      void nextDay();
      void nextDay(int);
      void prevDay();
      void prevDay(int);

    private:
      // no members in private
  
    protected:  
      int month;
      int date;
      int year;
      bool isLeapYear(int) const;
      int daysInMonth(int, int) const;
};

#endif