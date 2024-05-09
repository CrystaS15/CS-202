#ifndef SPIRO_TYPE_H
#define SPIRO_TYPE_H

/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 5
 * Description: provide basic Spirograph drawing functions
     spiroType class should inherit bitmap image functions from bitmapImage class
*/

#include <string>
#include "bitmapImage.h"

using namespace std;

class spiroType : private bitmapImage
{
  private:
    double radiusFixed;
    double radiusMoving;
    double offsetAmount;
    string drawColor;
    string fileName;
    int const W_MIN = 100;
    int const W_MAX = 10000;
    int const H_MIN = 100;
    int const H_MAX = 10000;

  public:
    // default constructor call base class
    // and set file name to null string
    spiroType();

    // non-default constructor accept width, height, and file name string
    // and call base class cosntructor
    spiroType(int, int, string);

    // copy constructor creates new object from passed object (deep copy)
    spiroType(const spiroType&);
    
    // create Spirograph (epicycloid) drawing
    void createSpiroImage();
    
    // read width and height from input
    // ensure width is between W_MIN (100) & W_MAX (10000)
    // ensure height is between H_MIN (100) & H_MAX (10000)
    // ensure aspect ratio (width/height) is between 1.0 and 2.0
    // set base class width and height variables
    void readImageSize();
    
    // read file name from input 
    // and ensure it has '.bmp' extension
    void readFileName();
    
    // sets file name class variable
    void setFileName(string);
    
    //  set base class width and height variables
    void setImageSize(int, int);
    
    // fill entire image with provided color (using base class functions)
    void initImage(int);
    
    // creates image file using class variables for file name
    // with a 24-bit depth (using appropriate base class functions)
    void createImageFile();
    
    // sets class variables for 
    // radiusFixed, radiusMoving, offsetAmount, and drawColor
    void setParameters(double, double, double, string);
    
    // read from user, set class variables for 
    // radiusFixed, radiusMoving, offsetAmount, and drawColor
    // radius and offset values must be between 0.0 and H_MIN or W_MIN
    void readParameters();

    // returns appropriate values 
    // or performs appropriate function using base class...
    double getRadiusFixed() const;
    double getRadiusMoving() const;
    double getOffsetAmount() const;
    string getDrawColor() const;
    int getHeight() const;
    int getWidth() const;
    string getFileName() const;
    int getPixel(int, int) const;
    
};

#endif