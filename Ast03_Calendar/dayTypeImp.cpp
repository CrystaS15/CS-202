/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: demonstrate dayType class functions properly
 * Input: 
 * Output:  */

#include <iostream>
#include <string>
#include "dayType.h"

using namespace std;

/* constructor_identifier: set date to passed values
 * parameters: passed values for month, date, year
 * return value: none */
dayType::dayType (int m, int d, int y) {
  month = 1;
  date = 1;
  year = 1970;
  // Months with 31 days
  if (m == 1||m == 3||m == 5||m == 7||m == 8||m == 10||m == 12) {
    if (d <= 31 && d > 0) {
  	  if (y >= 1800 && y <= 3050) {
    	  month = m;
        date = d;
        year = y;
      }
    }
  }

  // Month of February
  else if(m == 2) {
    if (y >= 1800 && y <= 3050) {
      
      // If leap year is true, 29 days
      if (isLeapYear(y) == true) {
    		if (d <= 29 && d > 0) {
		  month = m;
		  date = d;
		  year = y;
		}
      }
      
      // Else 28 days
      else {
      	if (d <= 28 && d > 0) {
      		month = m;
      		date = d;
      		year = y;
      	}
      }
    }
    
  }
  
  // Months with 30 days
  else if (m == 4||m == 6||m == 9||m==11) {
    if (d <= 30 && d > 0) {
      if (y >= 1800 && y <= 3050) {
	month = m;
        date = d;
        year = y;
      }
    }
  }
}

/* function_identifier: print date in mm/dd/yyyy format
 * parameters: none
 * return value: none */
void dayType::printDate() const {
  cout << "Date: ";
  cout << month << "/" << date << "/" << year << endl;
  
  return;
}

/* function_identifier: return current date
 * parameters: none
 * return value: date (int) */
int dayType::getDate() const {
  return date;
}

/* function_identifier: return current month
 * parameters: none
 * return value: month (int) */
int dayType::getMonth() const{
  return month;
}

/* function_identifier: return current year
 * parameters: none
 * return value: year (int) */
int dayType::getYear() const {
  return year;
}

/* function_identifier: increment current class date one day
 * parameters: none
 * return value: none */
void dayType::nextDay() {
  date++; // increment day by 1

  if (date > 31) { 
    // Months with 31 days
    if (month == 1||month == 3||month == 5
        ||month == 7||month == 8||month == 10) {
      month++;
      date = 1;
    }
    // Month of December to New Year
    if (month == 12) { 
      month = 1;
      date = 1;
      year++;
    }
  }
  // Month of February and NOT leap year
  else if (date > 28 && isLeapYear(year) == false) {
    if (month == 2) {
      month++;
      date = 1;
    }
  }
  // Month of February and IS leap year
  else if (date > 29 && isLeapYear(year) == true) {
    if (month == 2) {
      month++;
      date = 1;
    }
  }
  else if (date > 30) {
    // Months with 30 days
    if (month == 4||month == 6||month == 9||month == 11) {
      month++;
      date = 1;
    }
  }

  return;
}

/* function_identifier: decrement current class date one day
 * parameters: none
 * return value: none */
void dayType::prevDay() {
  date--; // decrement date 1 day

  if (date < 1) {
    // Months with 31 days to Months with 30 days
    if (month == 5||month == 7||month == 10||month == 12) {
      month--;
      date = 30;
    }
    // Month January to December
    else if (month == 1) {
      month = 12;
      date = 31;
      year--;
    }
    // Month March to February
    else if (month == 3) {
      // If Leap Year, day == 29
      if (isLeapYear(year) == true) {
        month--;
        date = 29;
      }
      // If not Leap Year, day == 28
      else if (isLeapYear(year) == false) {
        month--;
        date = 28;
      }
    }
    // Months with 30 days to Months with 31 days
    else if (month == 2||month == 4||month == 6
             ||month == 8||month == 9||month == 11) {
      
      month--;
      date = 31;
    }
  }

  return;
}

/* function_identifier: increment current class date by day(s) passed
 * parameters: next day number
 * return value: none */
void dayType::nextDay(int nDay) {
  date += nDay; // add number of days passed to current date

  /* Subtract from the date if days exceeds the days of the month */
  if (date > 31) {
    // January
    if (month == 1) {
      month++;
      date -= 31;
    }
  }
  // Month of February and NOT leap year
  if (date > 28 && isLeapYear(year) == false) {
    if (month == 2) {
      month++;
      date -= 28;
    }
  }
  // Month of February and IS leap year
  if (date > 29 && isLeapYear(year) == true) {
    if (month == 2) {
      month++;
      date -= 29;
    }
  }

  if (date > 31) {
    // March
    if (month == 3) {
      month++;
      date -= 31;
    }
  }

  if (date > 30) {
    // April
    if (month == 4) {
      month++;
      date -= 30;
    }
  }

  if (date > 31) {
    // May
    if (month == 5) {
      month++;
      date -= 31;
    }
  }

  if (date > 30) {
    // June
    if (month == 6) {
      month++;
      date -= 30;
    }
  }

  if (date > 31) {
    // July
    if (month == 7) {
      month++;
      date -= 31;
    }
  }

  if (date > 31) {
    // August
    if (month == 8) {
      month++;
      date -= 31;
    }
  }

  if (date > 30) {
    // September
    if (month == 9) {
      month++;
      date -= 30;
    }
  }

  if (date > 31) {
    // October
    if (month == 10) {
      month++;
      date -= 31;
    }
  }

  if (date > 30) {
    // November
    if (month == 11) {
      month++;
      date -= 30;
    }
  }

  if (date > 31) {
    // December
    if (month == 12) {
      month = 1;
      date -= 31;
      year++;
    }
  }

  return;
}

/* function_identifier: decrement current class date by day(s) passed
 * parameters: previous day number
 * return value: none */
void dayType::prevDay(int pDay) {
  date -= pDay; // subtract number of days passed from date

  /* Add to the date until days are no longer negative */
  if (date < 1) {
    // December
    if (month == 1) {
      month = 12;
      date += 31;
      year--;
    }
  }

  if (date < 1) {
    // November
    if (month == 12) {
      month--;
      date += 30;
    }
  }

  if (date < 1) {
    // October
    if (month == 11) {
      month--;
      date += 31;
    }
  }

  if (date < 1) {
    // September
    if (month == 10) {
      month--;
      date += 30;
    }
  }

  if (date < 1) {
    // August
    if (month == 9) {
      month--;
      date += 31;
    }
  }

  if (date < 1) {
    // July
    if (month == 8) {
      month--;
      date += 31;
    }
  }

  if (date < 1) {
    // June
    if (month == 7) {
      month--;
      date += 30;
    }
  }

  if (date < 1) {
    // May
    if (month == 6) {
      month--;
      date += 31;
    }
  }

  if (date < 1) {
    // April
    if (month == 5) {
      month--;
      date += 30;
    }
  }

  if (date < 1) {
    // March
    if (month == 4) {
      month--;
      date += 31;
    }
  }

  if (date < 1) {
    // February and Leap Year
    if (month == 3 && isLeapYear(year) == true) {
      month--;
      date += 29;
    } 
    // February and NO Leap Year
    else if (month == 3 && isLeapYear(year) == false) {
      month--;
      date += 28;
    }
  }

  if (date < 1) {
    // January
    if (month == 2) {
      month--;
      date += 31;
    }
  }

  return;
}

/* function_identifier: set date based on passed values
 * parameters: passed values for month, date, year
 * return value: none */
void dayType::setDate(int m, int d, int y) {
  /* Default date */
  month = 1;
  date = 1;
  year = 1970;

  // Months with 31 days
  if (m == 1||m == 3||m == 5||m == 7||m == 8||m == 10||m == 12) {
    if (d <= 31 && d > 0) {
  	  if (y >= 1800 && y <= 3050) {
    	  month = m;
        date = d;
        year = y;
      }
    }
  }

  // Month of February
  else if(m == 2) {
    if (y >= 1800 && y <= 3050) {
      
      // If leap year is true, 29 days
      if (isLeapYear(y) == true) {
	      if (d <= 29 && d > 0) {
      	  month = m;
      	  date = d;
      	  year = y;
      	}
      }
      // Else 28 days
      else {
      	if (d <= 28 && d > 0) {
          month = m;
          date = d;
          year = y;
      	}
      }

    }
  }
  
  // Months with 30 days
  else if (m == 4||m == 6||m == 9||m==11) {
    if (d <= 30 && d > 0) {
      if (y >= 1800 && y <= 3050) {
	      month = m;
        date = d;
        year = y;
      }
    }
  }
  
  return;
}

/* function_identifier: read date in form mm/dd/yyyy
 * parameters: none
 * return value: none */
void dayType::readDate() {
  char slash1; // store first slash between mm/dd
  char slash2; // store second slash between dd/year
  bool invalid = false; // error check

  /* Prompt for user to enter date */
  cout << "Enter date (mm/dd/year): ";
  cin >> month >> slash1 >> date >> slash2 >> year;

  // Error & re-prompt until user correctly enters date format
  if (cin.fail() == true) {
    invalid = true;
    while (invalid) {
      cout << "Invalid date, please re-enter." << endl;

      cout << "Enter date (mm/dd/year): ";
      cin >> month >> slash1 >> date >> slash2 >> year;
      if (cin.fail() == false) {
	      invalid = false;
      }
    }
  }

  // Error & re-prompt if incorrect month
  if (month < 1 || month > 12) {
    invalid = true;
    while (invalid) {
      cout << "Invalid date, please re-enter." << endl;

      cout << "Enter date (mm/dd/year): ";
      cin >> month >> slash1 >> date >> slash2 >> year;
      if (month >= 1 && month <= 12) {
	      invalid = false;
      }
    }
  }

  /* Error & re-prompt for incorrect days with corresponding month */
  // Months with 31 days
  if (month == 1||month == 3||month == 5
      ||month == 7||month == 8||month == 10||month == 12) {
      if (date > 31 || date <= 0) {
        invalid = true;
      }
      while (invalid) {
        cout << "Invalid date, please re-enter." << endl;

        cout << "Enter date (mm/dd/year): ";
        cin >> month >> slash1 >> date >> slash2 >> year;
        if (date <= 31 && date > 0) {
          invalid = false;
        }
      }
  }
  
  // Month of February
  else if(month == 2) {
    // Error & re-prompt for leap year
    if (isLeapYear(year) == true) {
      if (date > 29 || date <= 0) {
	      invalid = true;
      }
      while (invalid) {
        cout << "Invalid date, please re-enter." << endl;
        
        cout << "Enter date (mm/dd/year): ";
        cin >> month >> slash1 >> date >> slash2 >> year;
        if (date <= 29 && date > 0) {
          invalid = false;
	      }
      }
    }
    // Error & re-prompt for not leap year
    else if(isLeapYear(year) == false) {
      if (date > 28 || date <= 0) {
	      invalid = true;
      }
      while (invalid) {
        cout << "Invalid date, please re-enter." << endl;

        cout << "Enter date (mm/dd/year): ";
        cin >> month >> slash1 >> date >> slash2 >> year;
        if (date <= 28 && date > 0) {
          invalid = false;
        }
      }
    }
  }
  
  // Months with 30 days
  else if (month == 4||month == 6||month == 9||month==11) {
    if (date > 30 || date <= 0) {
      invalid = true;
    }
    while (invalid) {
      cout << "Invalid date, please re-enter." << endl;
      
      cout << "Enter date (mm/dd/year): ";
      cin >> month >> slash1 >> date >> slash2 >> year;
      if (date <= 30 && date > 0) {
	      invalid = false;
      }
    }
  }
  
  // Error & re-prompt until correct year entered
  if (year < 1800 || year > 3050) {
    invalid = true;
    while (invalid) {
      cout << "Invalid date, please re-enter." << endl;
      
      cout << "Enter date (mm/dd/year): ";
      cin >> month >> slash1 >> date >> slash2 >> year;
      if (year >= 1800 && year <= 3050) {
	      invalid = false;
      }
    }
  }
  
  
  return;
}

/* function_identifier: checks if given year is a leap year
 * parameters: passed value for year
 * return value: true if leap year; false if not leap year */
bool dayType::isLeapYear(int y) const {
  if (y % 4 == 0) { // divisible by 4
    if (y % 100 != 0) // but not divisible by 100
      return true;
  }

  if (y % 400 == 0) // divisible by 400
    return true;
    
  return false;
}

/* function_identifier: tells how many days in given month
 * parameters: passed values for month and year
 * return value: number of days in a given month */
int dayType::daysInMonth(int m, int y) const {
  int days;

  // Months with 31 days
  if (m == 1||m == 3||m == 5
      ||m == 7||m == 8||m == 10||m == 12) {
      
    days = 31;
  }

  // February
  if (m == 2) {
    // Leap Year = 29 days
    if (isLeapYear(y) == true) {
      days = 29;
    }
    // No Leap Year = 28 days
    else {
      days = 28;
    }
  }

  // Months with 30 days
  if (m == 4||m == 6||m == 9||m==11) {
    days = 30;
  }

  return days;
}
