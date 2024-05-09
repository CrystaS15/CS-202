/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: calendar class inherited from dateType inherited from dayType
 * Input: none
 * Output: none */

#ifndef CAL_TYPE_H
#define CAL_TYPE_H

#include "dateType.h"

using namespace std;

class calendarType : public dateType {
    public:
        calendarType();
        calendarType(int, int, int);
        void printMonthBox() const;
        void printYearBox() const;
};

#endif