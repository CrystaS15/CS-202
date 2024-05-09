/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: demonstrate dateType class functions properly
 * Input: 
 * Output:  */

#include <iostream>
#include <string>
#include <ctime> // for current date calculations

#include "dayType.h" // base class
#include "dateType.h" // derived class

using namespace std;

/* constructor_identifier: set current date and date strings
 * parameters: none
 * return value: none */
dateType::dateType() {
  time_t curr1;
  tm local;
  time (&curr1); // get current time_t value
  local=*(localtime(&curr1)); // dereference and assign
  month = local.tm_mon + 1;
  date = local.tm_mday;
  year = local.tm_year+1900;

  setDateStrings(); // update date strings
}

/* constructor_identifier: use dayType & set date strings
 * parameters: month, date, year
 * return value: none */
dateType::dateType(int month, int date, int year) : dayType(month, date, year) {
  /* Error checking for valid dates */

  setDateStrings(); // update date strings
}

/* function_identifier: print format in 
                        <day name>, <month name> <date>, <year> format
 * parameters: none
 * return value: none */
void dateType::printFormattedDate() const {
  cout << "Date: ";
  cout << dayName << ", " << monthName << " " << date << ", " << year;
  cout << endl;
  return;
}

/* function_identifier: set monthName and dayName to appropriate strings
 * parameters: none
 * return value: none */
void dateType::setDateStrings() {
  if (month == 1) {
    monthName = "January";
  }
  if (month == 2) {
    monthName = "February";
  }
  if (month == 3) {
    monthName = "March";
  }
  if (month == 4) {
    monthName = "April";
  }
  if (month == 5) {
    monthName = "May";
  }
  if (month == 6) {
    monthName = "June";
  }
  if (month == 7) {
    monthName = "July";
  }
  if (month == 8) {
    monthName = "August";
  }
  if (month == 9) {
    monthName = "September";
  }
  if (month == 10) {
    monthName = "October";
  }
  if (month == 11) {
    monthName = "November";
  }
  if (month == 12) {
    monthName = "December";
  }

  if (getDayNumber(month, date, year) == 0) {
    dayName = "Sunday";
  }
  if (getDayNumber(month, date, year) == 1) {
    dayName = "Monday";
  }
  if (getDayNumber(month, date, year) == 2) {
    dayName = "Tuesday";
  }
  if (getDayNumber(month, date, year) == 3) {
    dayName = "Wednesday";
  }
  if (getDayNumber(month, date, year) == 4) {
    dayName = "Thursday";
  }
  if (getDayNumber(month, date, year) == 5) {
    dayName = "Friday";
  }
  if (getDayNumber(month, date, year) == 6) {
    dayName = "Saturday";
  }

  return;
}

/* function_identifier: return day number 0-6 (0 for Sunday...)
 * parameters: month, date, year (all int)
 * return value: d (value for days of week) */
int dateType::getDayNumber(int month, int date, int year) const {
  int a = 0;
  int y = 0;
  int m = 0;
  int d = 0; // value for days of the week

  /* Calculate day number for days of week */
  a = (14 - month) / 12;

  y = year - a;

  m = month + (12*a) - 2;

  d = (date + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;

  return d;
}

/* function_identifier: set date to passed values
 * parameters: m (month), d (date), y(year)
 * return value: none */
void dateType::setDate(int m, int d, int y) {
  time_t curr1;
  tm local;
  time (&curr1); // get current time_t value
  local=*(localtime(&curr1)); // dereference and assign
  
  // Set date to passed values
  month = m;
  date = d;
  year = y;

  /* If error in dates, set date to current date */

  if (month < 1 || month > 12) {
    month = local.tm_mon + 1;
    date = local.tm_mday;
    year = local.tm_year+1900;
  }

  if (month == 1||month == 3||month == 5
      ||month == 7||month == 8||month == 10||month == 12) {
    
    if (date > 31 || date <= 0) {
      month = local.tm_mon + 1;
      date = local.tm_mday;
      year = local.tm_year+1900;
    }
  }

  else if(month == 2) {
     
    if (isLeapYear(year) == true) {
      if (date > 29 || date <= 0) {
	      month = local.tm_mon + 1;
        date = local.tm_mday;
        year = local.tm_year+1900;
      }
    }
     
    else if(isLeapYear(year) == false) {
      if (date > 28 || date <= 0) {
	      month = local.tm_mon + 1;
        date = local.tm_mday;
        year = local.tm_year+1900;
      }
    }
  }

  else if (month == 4||month == 6||month == 9||month==11) {
    if (date > 30 || date <= 0) {
      month = local.tm_mon + 1;
      date = local.tm_mday;
      year = local.tm_year+1900;
    }
  }

  if (year < 1800 || year > 3050) {
    month = local.tm_mon + 1;
    date = local.tm_mday;
    year = local.tm_year+1900;
  }

  setDateStrings(); // update date strings
}

/* function_identifier: increment current date by 1 (base)
 * parameters: none
 * return value: none */
void dateType::nextDay() {
  dayType::nextDay(); // call dayType nextDay()
  setDateStrings(); // update date strings
}

/* function_identifier: decrement current date by 1 (base)
 * parameters: none
 * return value: none */
void dateType::prevDay() {
  dayType::prevDay(); // call dayType prevDay()
  setDateStrings(); // update date strings
}

/* function_identifier: (base) increment current date by days passed
 * parameters: nDay [next day number]
 * return value: none */
void dateType::nextDay(int nDay) {
  dayType::nextDay(nDay); // call dayType nextDay(nDay)
  setDateStrings(); // update date strings
}

/* function_identifier: (base) decrement current date by days passed
 * parameters: pDay [previous day number]
 * return value: none */
void dateType::prevDay(int pDay) {
  dayType::prevDay(pDay); // call dayType prevDay(pDay)
  setDateStrings(); // update date strings
}

/* function_identifier: return string monthName from class variables
 * parameters: none
 * return value: monthName(string) */
string dateType::getMonthName() const {
  return monthName;
}

/* function_identifier: return string dayName from class variables
 * parameters: none
 * return value: dayName(string) */
string dateType::getDayName() const {
  return dayName;
}

/* function_identifier: read date (base) and set date strings
 * parameters: none
 * return value: none */
void dateType::readDate() {
  dayType::readDate(); // call dayType readDate()
  setDateStrings(); // update date strings
}