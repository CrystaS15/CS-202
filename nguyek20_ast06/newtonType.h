#ifndef NEWTONTYPE_H
#define NEWTONTYPE_H

/*
  Name:
    Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 6
  Description:
    Implement generalized Newton fractal algorithm
    Provide basic utility functions
    Inherit from bitmap image class, bitmapImage, and utilize complexType
      class for complex calculations
*/

#include "bitmapImage.h"
#include "complexType.h"
#include <string>

class newtonType : protected bitmapImage {
  private:
    static constexpr int WD_MIN=100, WD_MAX=10000;
    static constexpr int HT_MIN=100, HT_MAX=10000;
    static constexpr double A_MIN=-1.0, A_MAX=1.0;
    static constexpr double SCALE_MIN=0.0, SCALE_MAX=50.0;
    complexType aValue;
    double scale;
    string fileName;
    bool verifyParameters();
  public:
    newtonType();
    newtonType(int, int, string, double=1.0, 
                complexType=complexType(1.0, 0.0));
    
    newtonType(const newtonType&);
    void readImageFileName();
    void setImageFileName(string);
    string getImageFileName() const;
    void readImageSize();
    void setImageSize(int, int);
    void getImageSize(int &, int &) const;
    void readAvalue();
    void setAvalue(complexType);
    complexType getAvalue() const;
    void readScale();
    void setScale(double);
    double getScale() const;
    void createNewtonImage();
    void writeNewtonImageFile();
};

#endif
