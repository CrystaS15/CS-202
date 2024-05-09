/*
  Name:
    Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 6
  Description:
    Implementation file for newtonType.h
    Functions for newtonType.h
*/

// #include "bitmapImage.h"
// #include "complexType.h"
#include "newtonType.h"
#include <cmath>
// #include <string>

/* constructor_identifier: initialize class variables
 * parameters: none
 * return type: none */
newtonType::newtonType()
{
  setImageSize(0, 0);
  fileName = "";
  scale = 1.0;

  // set A value to (1.0, 0.0i)
  aValue.setComplex(1.0, 0.0);
}

/* constructor_identifier: accept width, height, file name, scale value, complex constant
 * parameters: width, height, fileName, scale value, complex constant
 * return type: none */
newtonType::newtonType(int w, int h, string name, double sValue, complexType complex)
{
  // define aspect ratio
  // double aRatio = 0.0;

  // accept width & height, display error if necessary
  setImageSize(w, h);
  
  // accept aspect ratio, display error if necessary
  // aRatio = w / h;
  /*
  if (aRatio < 0.5 || aRatio > 3.0)
  {
    cout << "Aspect ratio (" << w << " / " << h << ")" << ": " << aRatio << ". ";
    cout << "Error, invalid aspect ratio. ";
    cout << "Must be between 0.5 and 3.0." << endl; 
  }
  */

  // accept fileName, display error if necessary
  setImageFileName(name);

  // define variables to store real and imaginary parts
  double realA = 0.0;
  double imaginaryB = 0.0;
  
  // get current real and imaginary part
  complex.getComplex(realA, imaginaryB);

  // accept scale value, display error if necessary
  if ((realA >= A_MIN && realA <= A_MAX) && (imaginaryB >= A_MIN && imaginaryB <= A_MAX))
    if (sValue <= SCALE_MIN || sValue > SCALE_MAX)
      cout << "Error, invalid scale value." << endl;
    
  scale = sValue;

  // accept complex constant
  // each part of complex A value >= A_MIN and <= A_MAX
  

  // if valid, set values; otherwise display error
  if ((realA >= A_MIN && realA <= A_MAX) && 
      (imaginaryB >= A_MIN && imaginaryB <= A_MAX))
    aValue.setComplex(realA, imaginaryB);
  else
    cout << "Error, complex A value is out of range." << endl;

}

/* constructor_identifier: copy image and all class variables
 * parameters: newtonType object
 * return type: none */
newtonType::newtonType(const newtonType& newton) : bitmapImage()
{
  // copy width and height
  setImageSize(newton.getWidth(), newton.getHeight());

  // set fileName to empty string
  fileName = "";

  // copy remaining class variables
  scale = newton.scale;
  aValue = newton.aValue;

  // call createNewtonImage() function

}

/* function_identifier: prompt and read file name from user
// ensure file name is valid and has '.bmp' extension
 * parameters: none
 * return type: none */
void newtonType::readImageFileName() 
{
  string nFileName = "";

  do
  {
    // Prompt & user input output file name
    cout << "Enter Image File Name: ";
    getline(cin, nFileName);

    // If file name is too short
    if (nFileName.length() <= 4)
    {
      cout << "Error, invalid file name." << endl;
      cout << "Please re-enter." << endl;
    }

    // If file name does not have '.bmp' extension
    if (nFileName.find(".bmp") == string::npos)
    {
      cout << "Error, file name must be '.bmp' extension." << endl;
      cout << "Please re-enter." << endl;
    }
    
  } while (nFileName.length() <= 4 || 
           nFileName.find(".bmp") == string::npos);
  
  fileName = nFileName;

}

/* function_identifier: set file name class variable
 * parameters: passed in file name
 * return type: none */
void newtonType::setImageFileName(string nFileName)
{
  // If file name is too short
  if (nFileName.length() <= 4)
    cout << "Error, invalid file name." << endl;

  // If file name does not have '.bmp' extension
  if (nFileName.find(".bmp") == string::npos)
    cout << "Error, file name must be '.bmp' extension." << endl;
  
  // set file name class variable
  if (nFileName.length() > 4 && nFileName.find(".bmp") != string::npos)
    fileName = nFileName;
}

/* function_identifier: return file name
 * parameters: none
 * return type: string fileName*/
string newtonType::getImageFileName() const
{
  return fileName;
}

/* function_identifier: return width and height via reference
 * parameters: reference parameters width and height
 * return type: none*/
void newtonType::getImageSize(int& w, int& h) const
{
  w = bitmapImage::getWidth();
  h = bitmapImage::getHeight();
}

/* function_identifier: set width and height
 * parameters: passed in width and height
 * return type: none */
void newtonType::setImageSize(int w, int h)
{
  // error for incorrect width
  if ((w < WD_MIN || w > WD_MAX) && w != 0)
  {
    cout << "Error, width must be between 100 and 10000." << endl;
    return;
  }
  
  // error for incorrect height
  if ((h < HT_MIN || h > HT_MAX) && h != 0)
  {
    cout << "Error, height must be between 100 and 10000." << endl;
    return;
  }
    
  // set width and height if correct width and height
  if ((w >= WD_MIN && w <= WD_MAX)&&(h >= HT_MIN && h <= HT_MAX))
    bitmapImage::setSize(w, h);
}

/* function_identifier: prompt for and read width and height
 * parameters: none
 * return type: none */
void newtonType::readImageSize()
{
  // variables to input width and height
  int w = 0;
  int h = 0;

  // variable for aspect ratio
  double aRatio = 0.0;
  
  // Prompt and user input width and height until valid inputs received
  do
  {
    cout << "Enter image size (width, height): ";
    cin >> w >> h;

    // error for incorrect width
    if (w < WD_MIN || w > WD_MAX)
    {
      cout << "Error, width must be between 100 and 10000." << endl;
      cout << "Please re-enter." << endl;
    }

    // define aspect ratio and error for incorrect aspect ratio
    aRatio = w / h;
    if (aRatio < 0.5 || aRatio > 3.0)
    {
      cout << "Error, invalid aspect ratio. ";
      cout << "Must be between 0.5 and 3.0." << endl;
      cout << "Please re-enter." << endl;
    }
      
    // error for incorrect height
    if (h < HT_MIN || h > HT_MAX)
    {
      cout << "Error, height must be between 100 and 10000." << endl;
      cout << "Please re-enter." << endl;
    }

  } while ((w < WD_MIN || w > WD_MAX) || 
            (h < HT_MIN || h > HT_MAX) ||
            (aRatio < 0.5 || aRatio > 3.0));
  
  bitmapImage::setSize(w, h);
}

/* function_identifier: return complex A value
 * parameters: none
 * return type: none */
complexType newtonType::getAvalue() const
{
  return aValue;
}

/* function_identifier: set complex constant to passed value
// ensure values (real and imaginary) are between A_MIN and A_MAX
 * parameters: complexType object
 * return type: none */
void newtonType::setAvalue(complexType complex)
{
  // define variables to store real and imaginary parts
  double realA = 0.0;
  double imaginaryB = 0.0;
  
  // get current real and imaginary part
  complex.getComplex(realA, imaginaryB);

  // if valid, set values; otherwise display error
  if ((realA >= A_MIN && realA <= A_MAX) && 
      (imaginaryB >= A_MIN && imaginaryB <= A_MAX))
    aValue.setComplex(realA, imaginaryB);
  else
    cout << "Error, A value is out of range." << endl;

  return;
}

/* function_identifier: prompt for and read complex A value from user
 * parameters: none
 * return type: none */
void newtonType::readAvalue()
{
  // define variables in order to store current class variables
  double realA = 0.0;
  double imaginaryB = 0.0;

  // declare complexType object
  complexType complex;

  // Prompt and user input complex A value and repeat until valid
  do
  {
    cout << "Enter the complex A value (r,i): ";
    cin >> complex;

    // get current class variables
    complex.getComplex(realA, imaginaryB);

    // error for incorrect aValue range
    if ((realA < A_MIN||realA > A_MAX) ||
          (imaginaryB < A_MIN||imaginaryB > A_MAX))
      cout << "Error, A value is out of range." << endl;

  } while ((realA < A_MIN||realA > A_MAX) ||
            (imaginaryB < A_MIN||imaginaryB > A_MAX));
  
  // setComplex aValue because no longer in error checking loop
  aValue.setComplex(realA, imaginaryB);
  
}

/* function_identifier: return scale value
 * parameters: none
 * return type: none */
double newtonType::getScale() const
{
  return scale;
}

/* function_identifier: verify passed value and set class variable if valid
 * parameters: passed in scale value
 * return type: none */
void newtonType::setScale(double sValue)
{
  if (sValue <= SCALE_MIN || sValue > SCALE_MAX)
    cout << "Error, invalid scale value." << endl;
    
  scale = sValue;
}

/* function_identifier: prompt for and read scale value from user
// ensure scale value is > SCALE_MIN and <= SCALE_MAX
 * parameters: none
 * return type: none */
void newtonType::readScale()
{
  // to read in scale value
  double sValue = 0.0;

  // Prompt and user input sValue until valid input received
  do
  {
    cout << "Enter scale (0-50): ";
    cin >> sValue;
    
    if(sValue <= SCALE_MIN || sValue > SCALE_MAX)
      cout << "Error, invalid scale value.  Please re-enter." << endl;

  } while (sValue <= SCALE_MIN || sValue > SCALE_MAX);
  
  // set class variable
  scale = sValue;

}

/* function_identifier: write image to file specified by fileName (24-bit) depth
 * parameters: none
 * return type: none */
void newtonType::writeNewtonImageFile()
{
  bitmapImage::saveToBitmapFile(fileName.c_str());
  return;
}

void newtonType::createNewtonImage()
{
  // variable declarations
  const double PI = 3.14159265358; // constant for pi

  complexType z; // complex number z

  double tolerance = 0.0001; // tolerance
  
  // complex numbers r1, r2, r3
  complexType r1(1.0, 0.0);
  complexType r2( -0.5, sin(2.0 * PI / 3.0) );
  complexType r3( -0.5, -sin(2.0 * PI / 3.0) );

  complexType num3(3.0, 0.0); // represents complex number 3
  
  // variables for coloring, reset, and tracked per pixel
  int count = 0;
  int countMax = 255 * 2;
  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;

  // real and imaginary parts
  double realA = 0.0;
  double imaginaryB = 0.0;

  // width and height
  int w = getWidth();
  int h = getHeight();

  // if parameters are incorrect, return
  if (verifyParameters() == false)
  {
    cout << "Unable to Generate Image." << endl;
    return;
  }

  // iterate through each pixel (x,y)
  for (int x = 0; x <= w; x++)
  {
    for (int y = 0; y <= h; y++)
    {
      // set initial z
      realA = ((scale * x) - (w/2.0)) / w;
      imaginaryB = ((scale * y) - (h/2.0)) / h;

      z.setComplex(realA, imaginaryB);

      while ((count < countMax) && 
              ((z-r1).abs() >= tolerance) &&
              ((z-r2).abs() >= tolerance) &&
              ((z-r3).abs() >= tolerance))
      {
        // calculate and iterate z
        if (z.abs() != 0)
          z = z - aValue * ( ( (z*z*z)-r1 ) / ( num3*(z*z) ) );
        count++;
      }

      // formula to set red
      if ((z-r1).abs() <= tolerance)
      {
        redValue = 255 - (2*count);
        greenValue = 0;
        blueValue = 0;
      }

      // formula to set green
      if ((z-r2).abs() <= tolerance)
      {
        redValue = 0;
        greenValue = 255 - (2*count);
        blueValue = 0;
      }

      // formula to set blue
      if ((z-r3).abs() <= tolerance)
      {
        redValue = 0;
        greenValue = 0;
        blueValue = 255 - (2*count);
      }

      // set pixels
      bitmapImage::setPixelRGB(x, y, redValue, greenValue, blueValue);
      
      // reset variables
      redValue = 0;
      greenValue = 0;
      blueValue = 0;
      count = 0;
    }
  
  }
   
}

bool newtonType::verifyParameters()
{
  // variables to get width, height, and store aspectRatio
  int w = 0;
  int h = 0;
  double aRatio = 0.0;

  // variables to get real and imaginary parts
  double realA = 0.0;
  double imaginaryB = 0.0;

  /* Width, Height, and Aspect Ratio verification */

  getImageSize(w, h);

  // error for incorrect width
  if (w < WD_MIN || w > WD_MAX)
    return false;
  
  // error for incorrect height
  if (h < HT_MIN || h > HT_MAX)
    return false;

  // error for incorrect aspect ratio
  aRatio = w / h;
  if (aRatio < 0.5 || aRatio > 3.0)
    return false;

  /* fileName verification */

  // If file name does not have '.bmp' extension
  if (fileName.length() <= 4)
    return false;

  // If file name does not have '.bmp' extension
  if (fileName.find(".bmp") == string::npos)
    return false;

  // if scale value is not valid
  if (scale <= SCALE_MIN || scale > SCALE_MAX)
    return false;

  /* aValue verification */

  // declare complexType object
  complexType complex;

  // get current class variables
  complex.getComplex(realA, imaginaryB);

  // if values are not between A_MIN and A_MAX
  if ((realA < A_MIN||realA > A_MAX) ||
          (imaginaryB < A_MIN||imaginaryB > A_MAX))
      return false;

  return true;
}