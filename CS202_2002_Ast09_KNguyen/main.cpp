/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS202 - 1002, Assignment #9
 * Description: Recursion Set - Provided Main. */ 

// ----------------------------------------------------------------------------
//  Incldues

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <limits>

#include "recursionSet.h"

using namespace std;

// ----------------------------------------------------------------------------
//  Main program to test the class functions.

int main()
{
// ----------------------------------------------------------------------------
//  Declarations and display of simple header.

	const char *bold = "\033[1m";
	const char *unbold = "\033[0m";
	const char *green = "\033[32m";
	const char *red = "\033[31m";
	const char *underline = "\033[4m";

	string	bars = "";
	bars.append(60, '-');

	cout << endl;
	cout << bold << underline << "CS 202 – Recursion Set Program" <<
				unbold << endl << endl;

// ----------------------------------------------------------------------------
//  Test recursive ackerman() function.

	cout << bars << endl;
	cout << "Tak Function:" << endl << endl;

	recursionSet <long int> tst1;

	cout << "   tak(18,12,6): " << tst1.tak(18,12,6) << endl;
	cout << "   tak(10,7,5): " << tst1.tak(10,7,5) << endl;
	cout << "   tak(70,60,54): " << tst1.tak(70,60,54) << endl;
	cout << "   tak(70,60,52): " << tst1.tak(70,60,52) << endl;
	cout << "   tak(70,60,53): " << tst1.tak(70,60,53) << endl;
	cout << "   tak(70,60,51): " << tst1.tak(70,60,51) << endl;
	cout << "   tak(23,16,5): " << tst1.tak(23,16,5) << endl;


// ------------------------------------------------------------------------------
//  Test square root function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Square Root Function:" << endl << endl;

	const	double	epsilon = 0.0001;

	double	num1 = 25.0;
	double	num2 = 2.0;
	double	num3 = 6561.0;
	double	num4 = 39871.0;
	double	userNum = 0.0;

	recursionSet <double> tst2;

	cout << "Square Root of " << num1 << " is "
		<< tst2.squareRoot(num1, epsilon) << endl;
	cout << "Square Root of " << num2 << " is "
		<< tst2.squareRoot(num2, epsilon) << endl;
	cout << "Square Root of " << num3 << " is "
		<< tst2.squareRoot(num3, epsilon) << endl;
	cout << "Square Root of " << num4 << " is "
		<< tst2.squareRoot(num4, epsilon) << endl;

	cout << endl;
	string	pmt1 = "Enter number: ";
//	userNum = static_cast<double>(tst2.readValue(pmt1));
	userNum = tst2.readValue(pmt1);

	if (userNum > 0)
		cout << "Square Root of " << userNum << " is "
			<< tst2.squareRoot(userNum, epsilon) << endl;

// ----------------------------------------------------------------------------
//  Test recursive sum function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Recursive Sum Function:" << endl << endl;

	recursionSet <int> tst3;

	cout << "-------" << endl << "Set #1:" << endl;
	tst3.generateElements(15);
	tst3.printSet(8);
	cout << endl << endl;
	cout << "The sum is: " << tst3.recursiveSum() << endl;
	cout << endl;

	cout << "-------" << endl << "Set #2:" << endl;
	tst3.generateElements(75);
	tst3.printSet(8);
	cout << endl << endl;
	cout << "The sum is: " << tst3.recursiveSum() << endl;

// ----------------------------------------------------------------------------
//  Test recursive sort function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Recursive Insertion Sort:" << endl << endl;

	recursionSet <float> tstFlt;

	cout << "------------------" << endl << "Set #2 (sorted):" << endl;
	tst3.recursiveInsertionSort();
	tst3.printSet(8);

	cout << endl << endl;
	cout << "------------------" << endl << "Set #3 (unsorted):" << endl;
	tstFlt.generateElements(12);
	for (int i=0; i<12; i++)
		tstFlt.setElement(i, tstFlt.getElement(i)+0.5);
	tstFlt.printSet(8);
	cout << endl << endl;
	cout << "------------------" << endl << "Set #3 (sorted):" << endl;
	tstFlt.recursiveInsertionSort();
	tstFlt.printSet(8);

// ----------------------------------------------------------------------------
//  Test copy constructor.
//	copy previous tst3 object into tst4 object.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Copy Constructor Test:" << endl;

	recursionSet <int> tst4(tst3);

	cout << endl;
	if (tst3 == tst4)
		cout << "Copy Constructor Succeeded." << endl;
	else
		cout << "Copy Constructor Failed." << endl;

	cout << endl;
	tst4.setElement(73, 0);					// error
	tst4.setElement(42, 1);					// error
	tst4.setElement(3, 2);					// modify the copy
	tst4.recursiveInsertionSort();

	cout << endl << "Modified List (16 replaced with 2):" << endl;
	tst4.printSet(8);

	cout << endl << endl;
	if (tst3 == tst4)
		cout << "Error, copy of set not modified." << endl;
	else
		cout << "Success, copy of set modified." << endl;	// it should be modified

// ----------------------------------------------------------------------------
//  Test recursive printSeptenary() function.

	cout << endl << endl;
	cout << bars << endl;
	cout << "Septenary Function:" << endl << endl;

	recursionSet <long long> tst5;
	int	num5 = 0;
	string	pmpt5 = "Enter integer value ";
	int	sNum1 = 123, sNum2=234, sNum3=1200000;

	cout << "Septenary value of " << sNum1 << ": ";
	tst5.printSeptenary(sNum1);
	cout << endl;
	cout << "Septenary value of " << sNum2 << ": ";
	tst5.printSeptenary(sNum2);
	cout << endl;
	cout << "Septenary value of " << sNum3 << ": ";
	tst5.printSeptenary(sNum3);
	cout << endl << endl;

	num5 = tst5.readValue(pmpt5);
	if (num5 > 0) {
		cout << "Septenary value of " << num5 << ": ";
		tst5.printSeptenary(num5);
	}

// ----------------------------------------------------------------------------
//  test parentheses checking function

	cout << endl << endl;
	cout << bars << endl;
	cout << "Check Parentheses Function" << endl <<endl;

	recursionSet <string> tst6;

	string	parens[] = {	"(()()())",			// good
				"if ((x ==y) && (z==q))",	// good
				"( ( ( ) ) ( ( ( ) ) ) )",	// good 
				"( ( (asdf) ) ( ( ( ) ) ) )",	// good
				"( ( ( ) )",			// bad
				")(",				// bad
				"( ( !fasle ) )",		// good
				"if ((x ==y) && (z==q)",	// bad
				"if () && () else ())",		// bad
				"if (() && ()"			// bad
			};
	int	parensLen = sizeof(parens) / sizeof(parens[0]);

	// loop to check all provided strings
	for (int i=0; i < parensLen; i++) {
		cout << "The parentheses in string: " << parens[i];
		if (tst6.checkParentheses(parens[i]))
			cout << green << " : is correctly balanced." <<
						unbold << endl;
		else
			cout << red << " : is not correctly balanced." <<
						unbold << endl;
	}

// ----------------------------------------------------------------------------
//  Done...

	cout << endl;
	cout << bars << endl;

	return 0;
}

// ============================================================================

