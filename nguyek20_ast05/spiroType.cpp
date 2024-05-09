/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 5
 * Description: provide basic Spirograph drawing functions
     spiroType class should inherit bitmap image functions from bitmapImage class
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

#include "bitmapImage.h" // base class
#include "spiroType.h" // inherited class (private)

using namespace std;

/* constructor_identifier: (default) 
// calls base class, set file name to null string
 * parameters: none
 * return value: none */
spiroType::spiroType() : bitmapImage()
{
  // bitmapImage() creates empty bitmap object
  
  fileName = "";
}

/* constructor_identifier: (non-default) 
// accept width, height, and file name string
// and call base class constructor
* parameters: width(int), height(int), fileName(string)
* return value: none */
spiroType::spiroType(int sWidth, int sHeight, string sFileName) 
          : bitmapImage(sWidth, sHeight)
{
  // define aspect ratio
  double aspectRatio = sWidth/sHeight;
  
  // accept width, height, fileName string
  fileName = sFileName;
  
  // If file name is too short
    if (sFileName.length() <= 4)
    {
      cout << "Error, invalid file name." << endl;
    }

    // If file name does not have '.bmp' extension
    if (sFileName.find(".bmp") == string::npos)
    {
      cout << "Error, file name must be '.bmp' extension." << endl;
    }

  // Error for wrong width and height ranges 
  if (sWidth < W_MIN || sWidth > W_MAX)
  {
    cout << "Error, width must be between 100 and 10000." << endl;
  }
  if (sHeight < H_MIN || sHeight > H_MAX)
  {
    cout << "Error, height must be between 100 and 10000." << endl;
  }
  if ( aspectRatio < 1.0 || aspectRatio > 2.0)
  {
    cout << "Error, invalid aspect ratio. Must be between 1.0" <<
      "and 2.0." << endl;
  }
  
}

/* constructor_identifier: (copy) 
// creates new object from passed object (deep copy)
* parameters: spiroType (passed object)
* return value: none */
spiroType::spiroType(const spiroType& spiro) : bitmapImage()
{
  // copy width and height
  setSize(spiro.getWidth(), spiro.getHeight());

  // copy file name
  fileName = spiro.fileName;

  // copy remaining class variables 
  radiusFixed = spiro.radiusFixed;
  radiusMoving = spiro.radiusMoving;
  offsetAmount = spiro.offsetAmount;
  drawColor = spiro.drawColor;

  createSpiroImage();

}

/* function_identifier: create Spirograph (epicycloid) drawing
 * parameters: none
 * return value: none */
void spiroType::createSpiroImage()
{
  // x and y for equations
  double x = 0.0;
  double y = 0.0;

  // x and y for casting to int
  int actualX = 0;
  int actualY = 0;

  // RGB values
  int red = 0;
  int green = 0;
  int blue = 0;

  // convert "red" to int
  if(drawColor == "red")
  {
    red = 255;
    green = 0;
    blue = 0;
  }

  // convert "green" to int
  if (drawColor == "green")
  {
    red = 0;
    green = 255;
    blue = 0;
  }

  // convert "blue" to int
  if (drawColor == "blue")
  {
    red = 0;
    green = 0;
    blue = 255;
  }
  
  // equations for spirograph
  for (double t = 0.0; t <= 360.0; t += 0.01)
  {
    x = ( (radiusFixed+radiusMoving)*cos(t) ) + 
    ( offsetAmount*cos( (radiusFixed+radiusMoving)*(t/radiusMoving) ) );
    y = ( (radiusFixed+radiusMoving)*sin(t) ) + 
    ( offsetAmount*sin( (radiusFixed+radiusMoving)*(t/radiusMoving) ) );

    // static_cast to int x and y
    actualX = static_cast<int>(x) + getWidth()/2;
    actualY = static_cast<int>(y) + getHeight()/2;

    // setPixelRGB
    bitmapImage::setPixelRGB(actualX, actualY, red, green, blue);
  }
  
  return;
}

/* function_identifier: read width and height from input
 * parameters: none
 * return value: none */
void spiroType::readImageSize()
{
  int sWidth = 0;
  int sHeight = 0;
  double aspectRatio = 0.0;
  do
    {
      // Prompt to enter image size
      cout << "Enter image size (width, height): ";
      cin >> sWidth >> sHeight;

      setImageSize(sWidth, sHeight);

      aspectRatio = sWidth/sHeight;
      
      // Error for incorrect width and height inputs
      if (sWidth < W_MIN || sWidth > W_MAX)
      {
	      cout << "Error, width must be between 100 and 10000."
	          << endl << "Please re-enter." << endl;
      }
      if (sHeight < H_MIN || sHeight > H_MAX)
      {
	      cout << "Error, height must be between 100 and 10000."
	          << endl << "Please re-enter." << endl;
      }
      
      // Error for aspect ratio
      if (aspectRatio < 1.0 || aspectRatio > 2.0)
      {
        cout << "Error, invalid aspect ratio. "
            << "Must be between 1.0 and 2.0." << endl
            << "Please re-enter." << endl;
      }
      
    } while ((sWidth < W_MIN || sWidth > W_MAX) ||
             (sHeight < H_MIN || sHeight > H_MAX) ||
             (aspectRatio < 1.0 || aspectRatio > 2.0));
  
  return;
}

/* function_identifier: read file name from input 
// and ensure it has '.bmp' extension
* parameters: none
* return value: none */
void spiroType::readFileName()
{
  string sFileName = "";

  do
  {
    // Prompt & user input output file name
    cout << "Enter Output File Name: ";
    getline(cin, sFileName);

    setFileName(sFileName);

    // If file name is too short
    if (sFileName.length() <= 4)
    {
      cout << "Error, invalid file name." << endl;
      cout << "Please re-enter." << endl;
    }

    // If file name does not have '.bmp' extension
    if (sFileName.find(".bmp") == string::npos)
    {
      cout << "Error, file name must be '.bmp' extension." << endl;
      cout << "Please re-enter." << endl;
    }
    
  } while (sFileName.length() <= 4 || 
           sFileName.find(".bmp") == string::npos);
  
  return;
}

/* function_identifier: sets file name class variable
 * parameters: fileName(string)
 * return value: none */
void spiroType::setFileName(string sFileName)
{
  fileName = sFileName;

  return;
}

/* function_identifier: set base class width and height variables
 * parameters: base class width and height (both int)
 * return value: none */
void spiroType::setImageSize(int sWidth, int sHeight)
{
  // Error for wrong width and height ranges
  if (sWidth < W_MIN || sWidth > W_MAX)
  {
    cout << "Error, width must be between 100 and 10000." << endl;
  }
  if (sHeight < H_MIN || sHeight > H_MAX)
  {
    cout << "Error, height must be between 100 and 10000." << endl;
  }
  
  // Set width and height with bitmapImage::setSize
  bitmapImage::setSize(sWidth, sHeight);
  
  return;
}

/* function_identifier: fill entire image with provided color 
// (using base class functions)
* parameters: color (int) from base class
* return value: none */
void spiroType::initImage(int color)
{
  bitmapImage::fillWith(color);

  return;
}

/* function_identifier: creates image file using class variables
// for file name with a 24-bit depth 
// (using appropriate base class functions)
* parameters: none
* return value: none */
void spiroType::createImageFile()
{
  bitmapImage::saveToBitmapFile(fileName.c_str());
  return;
}

/* function_identifier: sets class variables for
// radiusFixed, radiusMoving, offsetAmount, and drawColor
* parameters: radiusFixed, radiusMoving, offsetAmount (double) and drawColor(string)
* return value: none */
void spiroType::setParameters(double rFixed, double rMoving, double oAmount, string dColor)
{
  radiusFixed = rFixed;
  radiusMoving = rMoving;
  offsetAmount = oAmount;
  drawColor = dColor;
  
  return;
}

/* function_identifier: read from user, set class variables for 
// radiusFixed, radiusMoving, offsetAmount, and drawColor
* parameters: none
* return value: none */
void spiroType::readParameters() 
{
  bool invalid = true; // loop condition for drawColor error checking
  int imageMin = 0; // variable to store minimum of image height/width

  // find and set width/height as minimum value
  if (getWidth() < getHeight())
  {
    imageMin = getWidth();
  }
  else
  {
    imageMin = getHeight();
  }
  
  // Prompt, user input, and error check for radiusFixed
  do
  {
    cout << "Enter Radius of fixed circle: ";
    cin >> radiusFixed;

    if (radiusFixed < 0 || radiusFixed > imageMin)
    {
      cout << "Invalid radius, please re-enter" << endl;
    }

  } while (radiusFixed < 0 || radiusFixed > imageMin);
  
  // Prompt, user input, and error check for radiusMoving
  do
  {
    cout << "Enter Radius of moving circle: ";
    cin >> radiusMoving;

    if (radiusMoving < 0 || radiusMoving > imageMin)
    {
      cout << "Invalid radius, please re-enter" << endl;
    }

  } while (radiusMoving < 0 || radiusMoving > imageMin);

  // Prompt, user input, and error check for offsetAmount
  do
  {
    cout << "Enter offset amount: ";
    cin >> offsetAmount;

    if (offsetAmount < 0 || offsetAmount > imageMin)
    {
      cout << "Invalid offset amount, please re-enter" << endl;
    }

  } while (offsetAmount < 0 || offsetAmount > imageMin);
  

  // Prompt, user input, and error check for drawColor
  while (invalid)
  {
    cout << "Enter draw color (red, green, blue): ";
    cin >> drawColor;

    if (drawColor == "red" || drawColor == "green" || 
        drawColor == "blue")
      invalid = false;
    else
      cout << "Invalid color, please re-enter" << endl;
  }

  setParameters(radiusFixed, radiusMoving, offsetAmount, drawColor);

  return;
}

/* function_identifier: returns radiusFixed
 * parameters: none
 * return value: radiusFixed(double) */
double spiroType::getRadiusFixed() const
{
  return radiusFixed;
}

/* function_identifier: return radiusMoving
 * parameters: none
 * return value: radiusMoving(double) */
double spiroType::getRadiusMoving() const
{
  return radiusMoving;
}

/* function_identifier: return offsetAmount
 * parameters: none
 * return value: offsetAmount(double) */
double spiroType::getOffsetAmount() const
{
  return offsetAmount;
}

/* function_identifier: return drawColor
 * parameters: none
 * return value: drawColor(string) */
string spiroType::getDrawColor() const
{
  return drawColor;
}

/* function_identifier: return height
 * parameters: none
 * return value: height(int) from bitmapImage */
int spiroType::getHeight() const
{
  return bitmapImage::getHeight();
}

/* function_identifier: return width
 * parameters: none
 * return value: width(int) from bitmapImage */
int spiroType::getWidth() const
{
  return bitmapImage::getWidth();
}

/* function_identifier: return fileName
 * parameters: none
 * return value: fileName(string) */
string spiroType::getFileName() const
{
  return fileName;
}

/* function_identifier: return pixelData (base)
 * parameters: xPixel (int), yPixel(int)
 * return value: getPixel(xPixel, yPixel) from bitmapImage */
int spiroType::getPixel(int xPixel, int yPixel) const
{
  return bitmapImage::getPixel(xPixel, yPixel);
}
