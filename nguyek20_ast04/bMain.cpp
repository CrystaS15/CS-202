/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 4
 * Description: design & implement 2 C++ classes to provide Magic Square program
 */

//  CS 202 Provided Main
//	Simple testing for boardType class.
//	Does not do much...

#include <iostream>
#include <iomanip>
#include <string>

#include "boardType.h"

using namespace std;

int main()
{
// ---------------------------------------
//  Misc. delcarations.

	string	stars;
	stars.append(60,'*');
	int	i=1;

	boardType brd0(3);
	boardType brd1(11);
	boardType brd2(12);

// ---------------------------------------
//  These declarations should give error message...

	cout << endl;
	cout << "*** Error Testing " << stars << endl;
	cout << " 5 Declaration errors..." << endl;
	cout << endl;

	boardType badBrd1(1);
	boardType badBrd2(60);
	boardType badBrd3(-6);
	boardType badBrd4(0);
	boardType badBrd5(2);

// ---------------------------------------
//  These invalid board access should give error message...

	cout << endl << "*** Error Testing " << stars << endl;
	cout << " 4 invalid board locations..." << endl << endl;

	if (badBrd1.getCell(1,1) != 0)
		cout << "Error accessing badBrd1." << endl;
	badBrd1.setCell(1,1,1);

	if (badBrd2.getCell(0,0) != 0)
		cout << "Error accessing badBrd2." << endl;
	badBrd2.setCell(0,0,1);

	cout << endl << "Output badBrd3 (should be empty):" << endl;
	badBrd3.printGrid();

// ---------------------------------------
//  Print board 0, 3x3 -> should be all 0's.

	cout << "*** Board #0 " << stars << endl;
	cout << " 3 x 3 -> All zero's" << endl;
	cout << endl;

	brd0.printGrid();

// ---------------------------------------
//  Try some functions with board #1
//	when brd1 goes out of scope, destructor is called...

	cout << "*** Board #1 " << stars << endl;
	cout << " 11 x 11 -> numbered" << endl;
	cout << endl;

	{
		for (int r=0; r<brd1.getOrder(); r++)
			for (int c=0; c<brd1.getOrder(); c++)
				brd1.setCell(r,c,i++);

		brd1.printGrid();
	}

// ---------------------------------------
//  Try some functions with board #2
//	NOTE, to see the printed magic square grid correctly
//	on the screen, it will be necessary to expand the size

	cout << "*** Board #2 " << stars << endl;
	cout << " 12 x 12 -> 1's in main diagonals, 0's otherwise." << endl;
	cout << " 5 bad board location accesses..." << endl;
	cout << endl;

	brd2.setCell(0,12,1);		// error
	brd2.setCell(12,0,1);		// error
	brd2.setCell(12,12,1);		// error
	brd2.setCell(0,-1,1);		// error
	brd2.setCell(-1,0,1);		// error

	for (int i=0; i<brd2.getOrder(); i++)
		brd2.setCell(i,i,1);

	for (int i=0, j=11; i<brd2.getOrder(); i++, j--)
		brd2.setCell(i,j,1);

	brd2.printGrid();

	cout << stars << endl;
	cout << endl;

// ---------------------------------------
//  All done.

	return 0;
}

