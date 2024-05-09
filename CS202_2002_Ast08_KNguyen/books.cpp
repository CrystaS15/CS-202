/* Name: Kristy Nguyen, NSHE ID #5006243601, CS 202-1002, Assignment 8
 * Description: Main program to test functions for book data type.
 // Provide functionality for reading and storing book information */

#include <iostream>
#include <fstream>
#include <string>

#include "bookDataType.h"

using namespace std;

int main(int argc, char *argv[])
{

// *****************************************************************
//  Headers, declarations...

	string	bars = "";
	string	stars = "";
	string	indent1 = "";
	string	indent2 = "";
	string	docFile = "";			// input document file name
	bool	showExtra = false;		// show extra book information

	const char *bold = "\033[1m";
	const char *unbold = "\033[0m";
	const char *green = "\033[32m";
	const char *red = "\033[31m";
	const char *underline = "\033[4m";

	bars.append(60, '-');
	stars.append(60, '*');
	indent1.append(4, ' ');
	indent2.append(2, ' ');

// *****************************************************************
//  Get command line information...

	bookDataType	myBookData;
	unsigned int	randomBook=0;

	if (myBookData.getBookArguments(argc, argv, docFile, showExtra)) {

		cout << bold << stars << endl << "CS 202 - Assignment #8" << endl <<
				"Book Data Project" << unbold << endl;
		cout << endl;

		myBookData.setExceptionsFileName("errs_" + docFile.substr(0,
					docFile.size()-4) + ".txt");

		// Get book data.
		if (myBookData.readBookData(docFile) ) {
			cout << endl << bold << green << underline <<
				"Book Data Summary" << unbold << endl;

			cout << indent1 << "Book File:  " <<
				myBookData.getBookFileName() << endl;
			cout << indent1 << "Book Count: " <<
				myBookData.getBookCount() << endl;
			cout << indent1 << "Web Page File: " <<
				myBookData.getWebPageFileName() << endl;
			cout << indent1 << "Exceptions File: " <<
				myBookData.getExceptionsFileName() << endl;

			cout << indent1 << "Error Counts: " << endl;
			cout << indent1 << indent2 << "Book ID Errors:    " <<
				myBookData.getReadBookIDErrors() << endl;
			cout << indent1 << indent2 << "Pub Year Errors:   " <<
				myBookData.getReadBookYearErrors() << endl;
			cout << indent1 << indent2 << "Ave Rating Errors: " <<
				myBookData.getReadBookAveRatingErrors() << endl;
			cout << indent1 << indent2 << "Duplicate Errors:  " <<
				myBookData.getReadBookDuplicateErrors() << endl;
			cout << indent1 << indent2 << "Total Errors:      " <<
				(myBookData.getReadBookIDErrors() +
				myBookData.getReadBookYearErrors() +
				myBookData.getReadBookAveRatingErrors() +
				myBookData.getReadBookDuplicateErrors()) << endl;
			cout << endl;

			if (showExtra) {
				cout << bars << endl;
				cout << "Personalized Book Recommendation:" << endl;
				randomBook = rand()%myBookData.getBookCount();
				myBookData.showBookData(randomBook);

				if (myBookData.getBookCount() > 1000) {
					cout << "Other Recommendations:" << endl;
					myBookData.showBookData(219);
					cout << "Other Recommendations:" << endl;
					myBookData.showBookData(5972);
				}

				if (myBookData.getBookCount() > 1000) {
					myBookData.setTopBooksLimit(7);
					myBookData.findHighestRatedBooks();
					myBookData.showHighestRatedBooks();
					// uncomment the next two lines if you do the extra credit
					// myBookData.setWebPageFileName("top7Books.html");
					// myBookData.buildWebPage("CS 202 Top Books Page");
				} else {
					myBookData.setTopBooksLimit(3);
					myBookData.findHighestRatedBooks();
					myBookData.showHighestRatedBooks();
					// uncomment the next two lines if you do the extra credit
					// myBookData.setWebPageFileName("top3Books.html");
					// myBookData.buildWebPage("CS 202 Top Three Books Page - Small Data Set");
				}
			}
		} else {
			cout << bold << red << "Unable to read books file." << unbold << endl;
		}
	}

// *****************************************************************
//  All done.

	cout << endl;
	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}

