#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

/*
  Name: 
    Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 6
  Description: 
    Provide complex number operations.
    Implement the overloaded functions to support complex numbers.
*/

#include <iostream>

using namespace std;

class complexType {
  // friend functions
  friend ostream& operator << (ostream&, const complexType&);
  friend istream& operator >> (istream&, complexType&);

  private:
    double realPart, imaginaryPart;
    // (a,b) a represents realPart, b represents imaginaryPart
  
  public:
    complexType (double=0.0, double=0.0);
    // constructor

    complexType operator + (const complexType&);
    complexType operator - (const complexType&);
    complexType operator * (const complexType&);
    complexType operator / (const complexType&);
    // overloaded operational functions
    
    bool operator == (const complexType&);
    bool operator != (const complexType&);
    // overloaded relational functions
    
    void setComplex(const double&, const double&);
    void getComplex(double&, double&) const;
    
    double abs() const;
    // |(a,b)| = sqrt(a^2 + b^2)
};

#endif