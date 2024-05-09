//  Kristy Nguyen
//  CS 202
//  Provided Main Program

//  Sorting algorithms assignment.

//  Implements:
//	bubble sort
//	selection sort
//	quick sort

// ***********************************************************************
//  Includes and prototypes.
  
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

#include "sortAlgorithms.h"

// *******************************************************************

int main()
{
// ------------------------------
//  Declarations and headers.

	string	stars;
	stars.append(60,'-');
	string	sortName = "";

	chrono::time_point<chrono::system_clock> t1, t2;

	int		setLength;
	const	int	testSetSize = 10000000;
	const	int	bigSetSize = 10000000;

	const int	searchLen = 5000;
	int		searchValues[searchLen];

	int		countFound = 0;
	int		countNotFound = 0;

// ------------------------------
//  Command line args ok, display initial headers.

	cout << stars << endl;
	cout << "CS 202 - Assignment #10" << endl;
	cout << "Sorting Algorithms." << endl;
	cout << endl;

// ------------------------------
//  Generate random values.

	sortAlgorithms	myData;

	// read set length (reads until good data entered)
	setLength = myData.readValue();

	cout << "Generating Data..." << endl;

	// create random data
	myData.generateDataRandom(setLength);

	cout << "  Set Size: " << myData.getLength() << endl << endl;

// ------------------------------
//  If print option, show numbers (if < 1000).

	if (myData.getLength() <= 1000)
		myData.printData();

// ------------------------------
//  Perform bubble sort on random data

	sortName = "Bubble Sort";

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	cout << sortName << "..." << endl;
	myData.bubbleSort();

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << sortName << " took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	if (!myData.sanityCheck()) {
		cout << "Error, epic " << sortName << " fail." << endl;
		cout << "Do not pass go, do not collect score." << endl;
	}

// ------------------------------
//  Perform selection sort on random data

	sortName = "Selection Sort";

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	cout << endl;
	cout << sortName << "..." << endl;
	myData.selectionSort();

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << sortName << " took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	if (!myData.sanityCheck()) {
		cout << "Error, epic " << sortName << " fail." << endl;
		cout << "Do not pass go, do not collect score." << endl;
	}

// ------------------------------
//  Perform quick sort on random data

	sortName = "Quick Sort";

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	cout << endl;
	cout << sortName << "..." << endl;
	myData.quickSort();

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << sortName << " took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	if (!myData.sanityCheck()) {
		cout << "Error, epic " << sortName << " fail." << endl;
		cout << "Do not pass go, do not collect score." << endl;
	}


// ------------------------------
//  Perform count sort on random data

	sortName = "Count Sort";

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	cout << endl;
	cout << sortName << "..." << endl;
	myData.countSort();

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << sortName << " took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	if (!myData.sanityCheck()) {
		cout << "Error, epic " << sortName << " fail." << endl;
		cout << "Do not pass go, do not collect score." << endl;
	}


// ------------------------------
//  Generate non-random (i.e., presorted data)
//	call bubble sort

	sortAlgorithms	testDataSet1;

	testDataSet1.generateDataNonRandom(testSetSize);

	sortName = "Bubble Sort (non-random data)";

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	cout << endl;
	cout << sortName << "..." << endl;
	myData.bubbleSort();

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << sortName << " took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	if (!myData.sanityCheck()) {
		cout << "Error, epic " << sortName << " fail." << endl;
		cout << "Do not pass go, do not collect score." << endl;
	}

// ------------------------------
//  Generate non-random (i.e., presorted data)
//	call quick sort

	sortAlgorithms	testDataSet2;

	testDataSet2.generateDataNonRandom(testSetSize);

	sortName = "Quick Sort (non-random data)";

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	cout << endl;
	cout << sortName << "..." << endl;
	myData.quickSort();

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << sortName << " took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	if (!myData.sanityCheck()) {
		cout << "Error, epic " << sortName << " fail." << endl;
		cout << "Do not pass go, do not collect score." << endl;
	}


// ------------------------------
//  Create new data set
//	pick random numbers to search for
//	search for various numbers -> unsorted

	sortAlgorithms	bigDataSet;

	// create random data
	bigDataSet.generateDataRandom(bigSetSize);

	for (int i=0; i < searchLen; i++)
		searchValues[i] = rand()%100 + 1;

	countFound = 0;
	countNotFound = 0;

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	for (int i = 0; i < searchLen; i++) {
		if (bigDataSet.isItemInUnsortedSet(searchValues[i]))
			countFound++;
		else
			countNotFound++;
	}

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << endl;
	cout << "Unsorted searches took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	cout << "  Search stats:   Found: " << countFound << "  Not Found: " <<
		countNotFound << endl;


// ------------------------------
//  Sort data set
//	search for various numbers -> sorted

	bigDataSet.countSort();

	countFound = 0;
	countNotFound = 0;

	// start timer...
	t1 = chrono::high_resolution_clock::now();

	for (int i = 0; i < searchLen; i++) {
		if (bigDataSet.isItemInSortedSet(searchValues[i]))
			countFound++;
		else
			countNotFound++;
	}

	// stop timer
	t2 = chrono::high_resolution_clock::now();

	// show time
	cout << endl;
	cout << "Sorted searches took: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " milliseconds" << endl;

	cout << "  Search stats:   Found: " << countFound << "  Not Found: " <<
		countNotFound << endl;

// ------------------------------
//  Done, terminate program.

	cout << endl;
	cout << "Game over, thanks for playing." << endl;

	return 0;
}

