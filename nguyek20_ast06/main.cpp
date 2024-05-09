//  CS 202 - Provided Main
// Name: 
// 	  Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 6
// Description:
// 	  This main uses the complexType and Newton fractal types.

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>

#include "complexType.h"
#include "newtonType.h"

using namespace std;

void displayImageData(newtonType &image);


// ****************************************************

int main(int argc, char *argv[])
{
	string	bars;
	bars.append(50,'-');

// ---------------------------------------------------
//  Get/check command line argument (-id).

	bool	showImageData = false;

	if (argc > 1 && string(argv[1]) == "-summary")
		showImageData = true;

// ---------------------------------------------------
//  Some quick tests for the complex type.

	complexType	val1(23.9, 34.7);
	complexType	val2(3.2, -4.1);
	complexType	num1, num2, num3, num4;

	complexType	ans1(27.1, 30.6);
	complexType	ans2(20.7, 38.8);
	complexType	ans3(218.75, 13.05);
	complexType	ans4(-2.43216, 7.72754);

	num1 = val1 + val2;
	num2 = val1 - val2;
	num3 = val1 * val2;
	num4 = val1 / val2;

	if ( (num1 != ans1) || !(num2 == ans2) ||
		(num3 != ans3) || !(num4 == ans4) ) {
		cout << "Error complex calulation are not correct." << endl;
		cout << "num1 = " << num1 << "    should be = " << ans1 << endl;
		cout << "num2 = " << num2 << "    should be = " << ans2 << endl;
		cout << "num3 = " << num3 << "    should be = " << ans3 << endl;
		cout << "num4 = " << num4 << "    should be = " << ans4 << endl;
		return 0;
	}

// ---------------------------------------------------
//  Simple, initial tests
//	Note, second image (newton2.bmp) is the one on the
//	assignment handout and is ~12MB.

	cout << endl << bars << endl;
	cout << "Newton Image Creation." << endl << endl;

	newtonType  nImage1(600, 600, "newton1.bmp",
			4.5, complexType(0.7, 0.27015));

	nImage1.createNewtonImage();
	nImage1.writeNewtonImageFile();

	newtonType nImage2(2000, 2000, "newton2.bmp",
			1.5, complexType(0.83300, 0.23780));

	nImage2.createNewtonImage();
	nImage2.writeNewtonImageFile();

// ---------------------------------------------------
//  Test set functions

	newtonType nImage3;

	nImage3.setImageSize(900, 900);
	nImage3.setImageFileName("newton3.bmp");
	nImage3.setScale(10.0);
	nImage3.setAvalue(complexType(0.23300, 0.23780));
	nImage3.createNewtonImage();
	nImage3.writeNewtonImageFile();

// ---------------------------------------------------
//  Test constructor

	cout << "Constructor Errors:" << endl;

	newtonType  badImage1(-100, 800, "newton1.bmp",
			0.9, complexType(-0.7, 0.27015));
	newtonType  badImage2(900, -200, "newton1.bmp",
			0.9, complexType(-0.7, 0.27015));
	newtonType  badImage3(900, 200000, "newton1.bmp",
			0.9, complexType(-0.7, 0.27015));
	newtonType  badImage4(600, 600, "newton1.jpg",
			0.9, complexType(-0.7, 0.27015));
	newtonType  badImage5(600, 600, "newton1",
			0.9, complexType(-0.7, 0.27015));
	newtonType  badImage6(500, 600, "newton1.bmmp",
			0.9, complexType(-0.7, 0.27015));
	newtonType  badImage7(500, 600, "newton1.bmp",
			0.9, complexType(-1.7, 0.27015));
	newtonType  badImage8(500, 600, "newton1.bmp",
			0.9, complexType(-0.7, 2.27015));
	newtonType  badImage9(500, 600, "newton1.bmp",
			0.9, complexType(-0.7, 0.27015));
	newtonType  badImage10(500, 600, "newton1.bmp",
			109.0, complexType(-0.7, 2.27015));
	newtonType  badImage11(500, 600, "newton1.bmp",
			0.0, complexType(-0.7, 2.27015));

	cout << endl;
	cout << "Setter Errors:" << endl;

	newtonType  badImage;

	badImage.setImageSize(-900, 600);
	badImage.setImageSize(900, -600);
	badImage.setImageSize(9, 6);
	badImage.setImageSize(90000, 600);
	badImage.setImageSize(900, 600000);

	badImage.setImageFileName("newton0");
	badImage.setImageFileName("newton0.bmmp");
	badImage.setImageFileName("newton0.bp");
	badImage.setImageFileName("newton0.gif");

	badImage.setScale(-1.0);
	badImage.setScale(211.0);
	badImage.setScale(0.0);

	badImage.setAvalue(complexType(-1.41453, 0.34364));
	badImage.setAvalue(complexType(0.41453, -1.34364));
	badImage.setAvalue(complexType(1.41453, 0.34364));
	badImage.setAvalue(complexType(0.41453, 1.34364));

	cout << endl;
	cout << "Should Show -> Image Creation Error:" << endl;

	badImage.createNewtonImage();

// ---------------------------------------------------
//  Test the read functions.
//	Try setting A=(0.99999, -0.77777)

	newtonType nImage4;

	cout << endl;
	cout << "Image Data Entry:" << endl;

	nImage4.readImageFileName();
	nImage4.readImageSize();
	nImage4.readAvalue();
	nImage4.readScale();
	nImage4.createNewtonImage();
	nImage4.writeNewtonImageFile();

// ---------------------------------------------------
//  call function to display image summary info.

	if (showImageData) {
		cout << endl << endl;
		displayImageData(nImage1);
		displayImageData(nImage2);
		displayImageData(nImage3);
		displayImageData(nImage4);
	}

// ---------------------------------------------------
//  Done, end program.

	return 0;
}

// ****************************************************
//  Simple function to display image data

void displayImageData(newtonType &image)
{
	string	fName;
	string	spaces = "   ";
	int	height, width;

	fName = image.getImageFileName();
	image.getImageSize(width, height);

	cout << "-----------------------------------------------------" << endl;
	cout << "Image:" << endl;
	cout << spaces << "File Name:   " << fName << endl;
	cout << spaces << "Image Size:  (" << height << "," <<
		width << ")" << endl;
	cout << spaces << "A value:     " << image.getAvalue() << endl;
	cout << spaces << "Scale: " << image.getScale() << endl;
	cout << endl;
}


