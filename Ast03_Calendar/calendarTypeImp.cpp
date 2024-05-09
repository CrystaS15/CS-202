/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: demonstrate calendarType class functions properly
 * Input: 
 * Output:  */

#include <iostream>
#include <string>
#include <iomanip>

#include "dateType.h"
#include "calendarType.h"

using namespace std;

/* constructor_identifier: same as dateType() constructor
 * parameters: none
 * return value: none */
calendarType::calendarType() : dateType() {}

/* constructor_identifier: same as dateType(int, int, int)
 * parameters: month, date, year (all int)
 * return value: none */
calendarType::calendarType(int month, int date, int year) : 
                dateType(month, date, year) {}

/* function_identifier: prints the month calendar box
 * parameters: none
 * return value: none */
void calendarType::printMonthBox() const {
  int weekDayNum = 0;

  weekDayNum = getDayNumber(month, date, year);

  cout << " ---------------------------------- " << endl;
  cout << "| " << monthName;
  cout << setw(32 - monthName.length()) << right << year << " |" << endl;
  cout << " ---------------------------------- " << endl;
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << endl;
  cout << " ---------------------------------- " << endl;
  cout << "|" << setw(5*weekDayNum) << right;

  for (int i = 1; i <= dayType::daysInMonth(month, year); i++) {
    if (i == 1) {
      cout << "|";
    }
    if (i <= 9) {
      cout << "  " << i << " |";
    }
    if (i > 9) {
      cout << " " << i << " |";
    }
    weekDayNum++;
    if (weekDayNum == 7) {
      cout << endl;
      weekDayNum = 0;
      if (weekDayNum == 0 && i != dayType::daysInMonth(month, year)) {
        cout << "|";
      }
    }
    if (i == dayType::daysInMonth(month, year) && weekDayNum != 0) {
      cout << setw(5*(7-weekDayNum)) << right << "|" << endl;
    }
  }
  cout << " ---------------------------------- " << endl << endl;
}

/* function_identifier: prints the year calendar box
 * parameters: none
 * return value: none */
void calendarType::printYearBox() const {
  int weekDayNum = 0;

  weekDayNum = getDayNumber(month, date, year);

  // Bars for Jan-Feb top boxes
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;

  // Title for Jan-Feb boxes
  cout << "| " << "January" << "                     ";
  cout << year << " |" << "\t";
  cout << "| " << "February" << "                    ";
  cout << year << " |" << endl;

  // Bars under title Jan-Feb boxes
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;

  // Weekdays labels for Jan-Feb boxes
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << "\t";
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << endl;

  // Bars under weekday labels
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;
  
  // Spaces before the 1st day (Jan)
  cout << "|" << setw(5*weekDayNum) << right;

  /* January month box */
  for (int i = 1; i <= 31; i++) {
    if (i == 1) {
      cout << "|";
    }
    if (i <= 9) {
      cout << "  " << i << " |";
    }
    if (i > 9) {
      cout << " " << i << " |";
    }
    weekDayNum++;
    if (weekDayNum == 7) {
      cout << endl;
      weekDayNum = 0;
      if (weekDayNum == 0 && i != 31) {
        cout << "|";
      }
    }
    if (i == 31 && weekDayNum != 0) {
      cout << setw(5*(7-weekDayNum)) << right << "|" << endl;
      cout << "|" << setw(5*7) << right << "|" << endl;
    }
  }
  cout << " ---------------------------------- " << endl;

  // Title for Mar-Apr boxes
  cout << "| " << "March" << "                       ";
  cout << year << " |" << "\t";
  cout << "| " << "April" << "                       ";
  cout << year << " |" << endl;

  // Bars under title Mar-Apr boxes
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;

  // Weekdays labels for Mar-Apr boxes
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << "\t";
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << endl;

  // Bars under weekday labels
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;
  
  // Spaces before the 1st day (Mar)
  cout << "|" << setw(5*weekDayNum) << right;

  /* March month box */
  for (int i = 1; i <= 31; i++) {
    if (i == 1) {
      cout << "|";
    }
    if (i <= 9) {
      cout << "  " << i << " |";
    }
    if (i > 9) {
      cout << " " << i << " |";
    }
    weekDayNum++;
    if (weekDayNum == 7) {
      cout << endl;
      weekDayNum = 0;
      if (weekDayNum == 0 && i != 31) {
        cout << "|";
      }
    }
    if (i == 31 && weekDayNum != 0) {
      cout << setw(5*(7-weekDayNum)) << right << "|" << endl;
      cout << "|" << setw(5*7) << right << "|" << endl;
    }
  }
  cout << " ---------------------------------- " << endl;

  // Title for May-June boxes
  cout << "| " << "May" << "                         ";
  cout << year << " |" << "\t";
  cout << "| " << "June" << "                        ";
  cout << year << " |" << endl;

  // Bars under title May-June boxes
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;

  // Weekdays labels for May-June boxes
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << "\t";
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << endl;

  // Bars under weekday labels
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;
  
  // Spaces before the 1st day (May)
  cout << "|" << setw(5*weekDayNum) << right;

  /* May month box */
  for (int i = 1; i <= 31; i++) {
    if (i == 1) {
      cout << "|";
    }
    if (i <= 9) {
      cout << "  " << i << " |";
    }
    if (i > 9) {
      cout << " " << i << " |";
    }
    weekDayNum++;
    if (weekDayNum == 7) {
      cout << endl;
      weekDayNum = 0;
      if (weekDayNum == 0 && i != 31) {
        cout << "|";
      }
    }
    if (i == 31 && weekDayNum != 0) {
      cout << setw(5*(7-weekDayNum)) << right << "|" << endl;
      cout << "|" << setw(5*7) << right << "|" << endl;
    }
  }
  cout << " ---------------------------------- " << endl;

  // Title for July-Aug boxes
  cout << "| " << "July" << "                        ";
  cout << year << " |" << "\t";
  cout << "| " << "August" << "                      ";
  cout << year << " |" << endl;

  // Bars under title July-Aug boxes
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;

  // Weekdays labels for July-Aug boxes
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << "\t";
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << endl;

  // Bars under weekday labels
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;
  
  // Spaces before the 1st day (July)
  cout << "|" << setw(5*weekDayNum) << right;

  /* July month box */
  for (int i = 1; i <= 31; i++) {
    if (i == 1) {
      cout << "|";
    }
    if (i <= 9) {
      cout << "  " << i << " |";
    }
    if (i > 9) {
      cout << " " << i << " |";
    }
    weekDayNum++;
    if (weekDayNum == 7) {
      cout << endl;
      weekDayNum = 0;
      if (weekDayNum == 0 && i != 31) {
        cout << "|";
      }
    }
    if (i == 31 && weekDayNum != 0) {
      cout << setw(5*(7-weekDayNum)) << right << "|" << endl;
      cout << "|" << setw(5*7) << right << "|" << endl;
    }
  }
  cout << " ---------------------------------- " << endl;

  // Title for Sep-Oct boxes
  cout << "| " << "September" << "                   ";
  cout << year << " |" << "\t";
  cout << "| " << "October" << "                     ";
  cout << year << " |" << endl;

  // Bars under title Sep-Oct boxes
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;

  // Weekdays labels for Sep-Oct boxes
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << "\t";
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << endl;

  // Bars under weekday labels
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;
  
  // Spaces before the 1st day (Sep)
  cout << "|" << setw(5*weekDayNum) << right;

  /* Sep month box */
  for (int i = 1; i <= 30; i++) {
    if (i == 1) {
      cout << "|";
    }
    if (i <= 9) {
      cout << "  " << i << " |";
    }
    if (i > 9) {
      cout << " " << i << " |";
    }
    weekDayNum++;
    if (weekDayNum == 7) {
      cout << endl;
      weekDayNum = 0;
      if (weekDayNum == 0 && i != 30) {
        cout << "|";
      }
    }
    if (i == 30 && weekDayNum != 0) {
      cout << setw(5*(7-weekDayNum)) << right << "|" << endl;
      cout << "|" << setw(5*7) << right << "|" << endl;
    }
  }
  cout << " ---------------------------------- " << endl;

  // Title for Nov-Dec boxes
  cout << "| " << "November" << "                    ";
  cout << year << " |" << "\t";
  cout << "| " << "December" << "                    ";
  cout << year << " |" << endl;

  // Bars under title Nov-Dec boxes
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;

  // Weekdays labels for Nov-Dec boxes
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << "\t";
  cout << "| Su | Mo | Tu | We | Th | Fr | Sa |" << endl;

  // Bars under weekday labels
  cout << " ---------------------------------- ";
  cout << "\t";
  cout << " ---------------------------------- " << endl;
  
  // Spaces before the 1st day (Nov)
  cout << "|" << setw(5*weekDayNum) << right;

  /* Nov month box */
  for (int i = 1; i <= 30; i++) {
    if (i == 1) {
      cout << "|";
    }
    if (i <= 9) {
      cout << "  " << i << " |";
    }
    if (i > 9) {
      cout << " " << i << " |";
    }
    weekDayNum++;
    if (weekDayNum == 7) {
      cout << endl;
      weekDayNum = 0;
      if (weekDayNum == 0 && i != 30) {
        cout << "|";
      }
    }
    if (i == 30 && weekDayNum != 0) {
      cout << setw(5*(7-weekDayNum)) << right << "|" << endl;
      cout << "|" << setw(5*7) << right << "|" << endl;
    }
  }
  cout << " ---------------------------------- " << endl;
}