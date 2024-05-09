/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 3
 * Description: demonstrate dateType class functions properly
 * Input: 
 * Output:  */

#include <iostream>
#include <string>

#include "dateType.h"

using namespace std;

// -----
//  CS 202 - Assignment #3, Provided Main
//	Uses the dateType class to test.
//	The dateType class extends the dayType class and
//	includes some additional functionality.

// -----
//  Note, while dateTypeclass is derived from dayType class,
//	that is hidden from the client program.
//	As such, all of the previous dayType functions
//	and some more are provided by dateType class.
//	The key addition is the day and month name strings.

int main() {

//  -----
//  Various declarations with different constructors.

	string bars;
	bars.append(25,'-');

	dateType today, tomorrow, yesterday;
	dateType tempDay;

	dateType dueDate (2, 19, 2020);
	dateType newYear (1, 1, 2020);
	dateType birthDay (1, 27, 1996);

// -----
//  Set and display federal holdays for 2020.
//		examples of array using dayType object.
//		uses and tests setDate() function.

	dateType federalHolidays2020[10];

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
		federalHolidays2020[i].printFormattedDate();
	cout << endl;

// -----
//  Simple tests for printDate
//	Note, also shows default constructor results

	cout << bars << endl;
	cout << "Today is: ";
	today.printFormattedDate();
	cout << endl;
	tempDay = today;

	cout << "Due Date is: ";
	dueDate.printFormattedDate();
	cout << endl;

// -----
//  Show tomorrow and yesterday.
// 	uses nextDay() and prevDay() functions.
//	uses simpiler date print format

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
	newYear.printFormattedDate();

	cout << "News Year Eve: ";
	tempDay = newYear;
	tempDay.prevDay();
	tempDay.printFormattedDate();

	cout << endl;
	cout << "Next Month: ";
	tempDay = newYear;
	tempDay.nextDay(32);
	tempDay.printFormattedDate();

	cout << "Last Quarter Month: ";
	tempDay = newYear;
	tempDay.prevDay(90);
	tempDay.printFormattedDate();

	cout << "Mid Year: ";
	tempDay = newYear;
	tempDay.nextDay(182);
	tempDay.printFormattedDate();
	cout << endl;

// -----
//  Read birthday.
//	uses getYear() for possible remark.

	cout << endl;
	cout << bars << endl;
	cout << "When is your birthday?" << endl;
	birthDay.readDate();

	if ( (today.getYear()-birthDay.getYear()) <= 12) {
		cout << (today.getYear()-birthDay.getYear());
		cout << " years old, seriously?" << endl;
		cout << endl;
	}

	cout << "Your birthday ";
	birthDay.printFormattedDate();
	cout << "Yeah, " << birthDay.getDayName() << "'s are lucky!" << endl;
	cout << endl;
	cout << "Your lucky number is " << birthDay.getMonth() << " + ";
	cout << birthDay.getDate() << " + " << birthDay.getYear() << " = ";
	cout << (birthDay.getMonth() + birthDay.getDate() + birthDay.getYear());
	cout << endl;
	cout << endl;

    return 0;
}

