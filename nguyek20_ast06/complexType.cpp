/*
  Name: 
    Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 6
  Description: 
    Implementation file for complexType
    Functions for complexType
*/

#include "complexType.h"

#include <iostream>
#include <cmath>

using namespace std;

/* function_identifier: overload stream insertion operator
 * parameters: is (istream object), complex (complexType object) 
 * return type: is (istream object) */
istream& operator >> (istream& is, complexType& complex)
{
  // to store other characters
  char c;

  // to input real and imaginary variables
  double realA = 0.0; 
  double imaginaryB = 0.0;
  
  // read in (<value>, <value>)
  is >> c;
  is >> realA;
  is >> c;
  is >> imaginaryB;
  is >> c;
  
  // set read-in values to class variables
  complex.setComplex(realA, imaginaryB);

  return is;
}

/* function_identifier: overload stream extraction operator
 * parameters: os (ostream object), complex (complexType object) 
 * return type: os (ostream object) */
ostream& operator << (ostream& os, complexType const& complex)
{
  // to store values as current values in class variables
  double realA = 0.0;
  double imaginaryB = 0.0;

  // store variables as current values in class variables
  complex.getComplex(realA, imaginaryB);

  // cout in format (<value>, <value>i)
  os << "(" << realA << ", " << imaginaryB << "i)";

  return os;
}

/* constructor_identifier: set class variable to passed parameters
 * parameters: realA (double), imaginaryB (double)
 * return type: none */
complexType::complexType(double realA, double imaginaryB)
{
  realPart = realA;
  imaginaryPart = imaginaryB;
}

/* function_identifier: add complex numbers
 * parameters: complex (complexType&)
 * return type: tempComplex (complexType object) */
complexType complexType::operator + (const complexType& complex)
{
  // create tempComplex object to add (a,b) + (c,d)
  complexType tempComplex;

  // add a+c
  tempComplex.realPart = realPart + complex.realPart;
  // add b+d
  tempComplex.imaginaryPart = imaginaryPart + complex.imaginaryPart;

  return tempComplex;
}

/* function_identifier: subtract complex numbers
 * parameters: complex (complexType&)
 * return type: tempComplex (complexType object) */
complexType complexType::operator - (const complexType& complex)
{
  // create tempComplex object to subtract (a,b) - (c,d)
  complexType tempComplex;

  // subtract a-c
  tempComplex.realPart = realPart - complex.realPart;
  // subtract b-d
  tempComplex.imaginaryPart = imaginaryPart - complex.imaginaryPart;

  return tempComplex;
}

/* function_identifier: multiply complex numbers
 * parameters: complex (complexType&)
 * return type: tempComplex (complexType object) */
complexType complexType::operator * (const complexType& complex)
{
  // create tempComplex object to multiply (a,b)*(c,d)
  complexType tempComplex;

  // (ac - bd)
  tempComplex.realPart = (realPart*complex.realPart) - 
                          (imaginaryPart*complex.imaginaryPart);
  // (ad + bc)
  tempComplex.imaginaryPart = (realPart*complex.imaginaryPart) +
                                (imaginaryPart*complex.realPart);

  return tempComplex;
}

/* function_identifier: divide complex numbers
 * parameters: complex (complexType&)
 * return type: tempComplex (complexType object) */
complexType complexType::operator / (const complexType& complex)
{
  // create tempComplex object to divide (a,b)/(c,d)
  complexType tempComplex;

  if ((pow(complex.realPart, 2.0) +
        pow(complex.imaginaryPart, 2.0)) == 0)
  {
    cout << "Error, (c,d) should be non-zero." << endl;
    return tempComplex;
  }

  // (ac+bd) / (c^2+d^2)
  tempComplex.realPart = 
    // (ac+bd) /
    ((realPart*complex.realPart)+
     (imaginaryPart*complex.imaginaryPart)) / 
    // (c^2+d^2)
    (pow(complex.realPart, 2.0) +
     pow(complex.imaginaryPart, 2.0));
  
  // (-ad+bc) / (c^2+d^2)
  tempComplex.imaginaryPart =
    // (-ad+bc) /
    (-(realPart*complex.imaginaryPart) +
       (imaginaryPart*complex.realPart)) /
    // (c^2+d^2)
    (pow(complex.realPart, 2.0) +
     pow(complex.imaginaryPart, 2.0));

  return tempComplex;
}

/* function_identifier: absolute value of |(a,b)|
 * parameters: none
 * return type: tempAbs (double) */
double complexType::abs() const
{
  // double to calculate |(a,b)|
  double tempAbs = 0.0;

  // sqrt(a^2 + b^2)
  tempAbs = sqrt(pow(realPart, 2.0)+pow(imaginaryPart,2.0));

  return tempAbs;
}

/* function_identifier: compare complex values to epsilon
 * parameters: complex (complexType&)
 * return type: true if difference < EPSILON */
bool complexType::operator == (const complexType& complex)
{
  double EPSILON = 0.0001;
  
  // to subtract complex values
  double real = 0.0;
  double imaginary = 0.0;

  real = realPart - complex.realPart;
  imaginary = imaginaryPart - complex.imaginaryPart;

  // return true if difference < EPSILON
  if(fabs(real) < EPSILON && fabs(imaginary) < EPSILON)
    return true;
  
  return false;
}

/* function_identifier: compare complex values to epsilon
 * parameters: complex (complexType&)
 * return type: false if difference < EPSILON */
bool complexType::operator != (const complexType& complex)
{
  double EPSILON = 0.0001;
  
  // to subtract complex values
  double real = 0.0;
  double imaginary = 0.0;

  real = realPart - complex.realPart;
  imaginary = imaginaryPart - complex.imaginaryPart;

  // return false if difference < EPSILON
  if(fabs(real) < EPSILON && fabs(imaginary) < EPSILON)
    return false;
  
  return true;
}

/* function_identifier: set class variables to passed complex values
 * parameters: realA and imaginaryB (const double&)
 * return type: none */
void complexType::setComplex(const double& realA, const double& imaginaryB)
{
  realPart = realA;
  imaginaryPart = imaginaryB;
}

/* function_identifier: set passed complex values to class variables
 * parameters: realA and imaginaryB (const double&)
 * return type: none */
void complexType::getComplex(double& realA, double& imaginaryB) const
{
  realA = realPart;
  imaginaryB = imaginaryPart;
}