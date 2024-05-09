/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: demonstrate dayType class functions properly
 * Input: 
 * Output:  */

#include <iostream>
#include <string>

#include "dayType.h"

using namespace std;

// -----
//  CS 202 - Assignment #3, Provided Main.
//	Uses the dayType class to test basic functions.

int main()
{
//  -----
//  Various declarations with different constructors.

	string bars;
	bars.append(25,'-');

	dayType today, tomorrow, yesterday;
	dayType tempDay;

	dayType dueDate(2, 19, 2020);
	dayType newYear(1, 1, 2020);
	dayType birthDay(1, 27, 1996);

// -----
//  Set and display federal holdays for 2020.
//	examples of array using dayType object.
//	uses and tests setDate() function.

	dayType federalHolidays2020[10];

	federalHolidays2020[0].setDate(1,1,2020);
	federalHolidays2020[1].setDate(1,20,2020);
	federalHolidays2020[2].setDate(2,17,2020);
	federalHolidays2020[3].setDate(5,25,2020);
	federalHolidays2020[4].setDate(7,3,2020);
	federalHolidays2020[5].setDate(9,7,2020);
	federalHolidays2020[6].setDate(10,12,2020);
	federalHolidays2020[7].setDate(11,11,2020);
	federalHolidays2020[8].setDate(11,26,2020);
	federalHolidays2020[9].setDate(12,25,2020);

	cout << bars << endl;
	cout << endl;
	cout << "Federal Holidays for 2020:" << endl;
	for (int i=0; i<10; i++)
		federalHolidays2020[i].printDate();
	cout << endl;

// -----
//  Simple tests for printDate
//	Note, also shows default constructor results.

	tempDay = today;
	today.setDate(1, 31, 2020);

	cout << bars << endl;
	cout << "Today was: ";
	tempDay.printDate();
	cout << endl;
	cout << "Today is: ";
	today.printDate();
	cout << endl;

// -----
//  Show tomorrow and yesterday.
// 	uses and test nextDay() and prevDay() functions.

	cout << "Tomorrow is: ";
	tomorrow = today;
	tomorrow.nextDay();
	tomorrow.printDate();
	cout << endl;

	cout << "Yesterday was: ";
	yesterday = today;
	yesterday.prevDay();
	yesterday.printDate();
	cout << endl;

	cout << "Due Date is: ";
	dueDate.printDate();
	cout << endl;

// -----
//  Constructor and setDate() error testing.
//	Since all bad, date should be 1/1/1970.

	dayType badDate1(1, 32, 2020);
	dayType badDate2(1, -7, 2020);
	dayType badDate3(6, 31, 2020);
	dayType badDate4(2, 29, 2020);
	dayType badDate5(13, 27, 2020);
	dayType badDate6, badDate7, badDate8;
	dayType badDate9, badDate10, badDate11;

	badDate6.setDate(4, 31, 2020);
	badDate7.setDate(11, 31, 2020);
	badDate8.setDate(2, 29, 2013);
	badDate9.setDate(-1, 1, 2020);
	badDate10.setDate(1, 1, 1799);
	badDate11.setDate(1, 1, 3051);

	cout << bars << endl;
	cout << "Constructor and setDate error testing." << endl << endl;

	badDate1.printDate();
	badDate2.printDate();
	badDate3.printDate();
	badDate4.printDate();
	badDate5.printDate();
	badDate6.printDate();
	badDate7.printDate();
	badDate8.printDate();
	badDate9.printDate();
	badDate10.printDate();
	badDate11.printDate();
	cout << endl;

// -----
//  Tests for read a date from user.
//	uses readDate() function
//	then, show previous and next days for that date
//	then, show next month (30 days forward)
//	then, show last quarter (~90 days back)
//	then, show 1/2 year forward (365/2=182)

	cout << bars << endl;
	cout << "When is new years day? " << endl;
	newYear.readDate();
	cout << endl;
	cout << "News Year Day: ";
	newYear.printDate();

	cout << "News Year Eve: ";
	tempDay = newYear;
	tempDay.prevDay();
	tempDay.printDate();

	cout << endl;
	cout << "Next Month: ";
	tempDay = newYear;
	tempDay.nextDay(32);
	tempDay.printDate();

	cout << "Last Quarter Month: ";
	tempDay = newYear;
	tempDay.prevDay(90);
	tempDay.printDate();

	cout << "Mid Year: ";
	tempDay = newYear;
	tempDay.nextDay(182);
	tempDay.printDate();
	cout << endl;

// -----
//  Read birthday.
//	uses getYear() for possible remark.
//	note, since today may not really be 'today' the
//	silly ago remark may not be valid.

	cout << endl;
	cout << bars << endl;
	cout << "When is your birthday?" << endl;
	birthDay.readDate();

	if ( (today.getYear()-birthDay.getYear()) <= 12) {
		cout << (today.getYear()-birthDay.getYear());
		cout << " years old, seriously?" << endl;
	}

	cout << endl;
	cout << "Your lucky number is " << birthDay.getMonth() << " + ";
	cout << birthDay.getDate() << " + " << birthDay.getYear() << " = ";
	cout << (birthDay.getMonth() + birthDay.getDate() + birthDay.getYear());
	cout << endl;


    return 0;
}

