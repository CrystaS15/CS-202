// CS202 - Provided Main.

/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 5

 * Description: 
//	This simple main creates some spiograph image files.
//	Test various aspects of the sprioType class.

*/

#include <cstdlib>
#include <iostream>
#include <string>

#include "spiroType.h"

using namespace std;

void displayImageData(spiroType);


// =============================================================================

int main()
{
	cout << endl << "CS 202 - Assignment #8." << endl;
	cout << "Spirograph Program." << endl << endl;

// ----------------------------------------------
//  Some initial error testing.

	cout << "Bad Constructor (should be error)" << endl;
	spiroType	image0(10,10,"none.bmp");		// bad constructor
	cout << endl << endl;

// ----------------------------------------------
//  Create spirograph image #1.
//	get file name and image size information from user.

	spiroType	image1;

	image1.readFileName();
	image1.readImageSize();
	image1.readParameters();
	image1.initImage(0);
	image1.createSpiroImage();
	image1.createImageFile();

// ----------------------------------------------
//  Create spirograph image #2.

	int img2width = 1280;
	int img2height = 800;
	spiroType	image2(img2width,img2height,"spiro2.bmp");

	image2.initImage(0);
	image2.setParameters(57, 108, 43, "red");
	image2.createSpiroImage();
	image2.createImageFile();

// ----------------------------------------------
//  Create spirograph image #3.

	spiroType	image3;

	image3.setImageSize(640,480);
	image3.setFileName("spiro3.bmp");
	image3.setImageSize(img2width, img2height);
	image3.setParameters(106, 8, 58, "green");
	image3.initImage(0);
	image3.createSpiroImage();
	image3.createImageFile();

// ----------------------------------------------
//  Create spirograph image #4 based on image #2.

	spiroType image4(image2);

	image4.setFileName("spiro4.bmp");
	image4.createSpiroImage();
	image4.createImageFile();

// ----------------------------------------------
//  Create spirograph image #5 based on image #2.
//	image 5 should include image 2 (in red) and the
//	new image (in green).

	spiroType image5(image2);

	image5.setFileName("spiro5.bmp");
	image5.setParameters(200, 8, 17, "green");
	image5.createSpiroImage();
	image5.createImageFile();

// ----------------------------------------------
//	Create spirograph image #6 (small).

	spiroType image6;

	image6.setFileName("spiro6.bmp");
	image6.setImageSize(200,200);
	image6.setParameters(51, 13, 15, "blue");
	image6.initImage(0);
	image6.createSpiroImage();
	image6.createImageFile();

// ----------------------------------------------
//  Display summary for files created...

	cout << endl << endl << "************************************************" << endl;
	cout << "Image Summary Information:" << endl << endl;

	displayImageData(image1);
	displayImageData(image2);
	displayImageData(image3);
	displayImageData(image4);
	displayImageData(image5);
	displayImageData(image6);

	cout << endl;

// ----------------------------------------------
//  All done, end program.

	return 0;
}

// =============================================================================
//  Simple support function
//	display the image information for reference.

void displayImageData(spiroType image)
{
	double	rF, rM, oA;
	string	dC, fName;

	fName = image.getFileName();
	rF = image.getRadiusFixed();
	rM = image.getRadiusMoving();
	oA = image.getOffsetAmount();
	dC = image.getDrawColor();

	cout << "---------------------------------------------------------------" << endl;
	cout << "Image:" << fName << endl;
	cout << "\tRadius Fixed  = " << rF << "\t\tRadius Moving = " << rM << endl;
	cout << "\tOffset Amount = " << oA << "\t\tDraw Color    = " << dC << endl;
}

// =============================================================================

