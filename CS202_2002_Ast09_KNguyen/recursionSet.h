#ifndef RECURSION_SET_H
#define RECURSION_SET_H

/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS202 - 1002, Assignment #9
 * Description: Recursion Set - recursionSet header file */

#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

template <class myType>
class recursionSet 
{
  
  private:
    int length;
    myType *mySet;
    int static const MAX_VALUE = 5000000;
    int static const LIMIT = 1000;

    myType recSqRoot(myType, myType, myType) const;
    myType rSum(int) const;
    bool recChkPar(string, int, int) const;
    void recInsSort(int, int);
    void insertInOrder(myType, int, int);
  
  public:
    recursionSet();
    recursionSet(const recursionSet<myType>&);
    ~recursionSet();
    int getSetLength() const;
    void generateElements(int);
    myType getElement(int) const;
    void setElement(int, myType);
    int readValue(const string) const;
    void printSet(int) const;
    bool operator == (const recursionSet<myType>&);
    myType tak(myType, myType, myType) const;
    void printSeptenary(myType) const;
    myType squareRoot(myType, myType) const;
    myType recursiveSum() const;
    bool checkParentheses(string) const;
    void recursiveInsertionSort();

};

/* constructor_identifier: set length to 0 and mySet to nullptr
 * parameters: none
 * return type: none */
template <class myType>
recursionSet <myType>::recursionSet() 
{
  length = 0;
  mySet = nullptr;
}

/* constructor_identifier: copy constructor create new, deepy copy from passed object
 * parameters: myRecurs (passed object)
 * return type: none */
template <class myType>
recursionSet <myType>::recursionSet(const recursionSet<myType>& myRecurs) 
{
  length = myRecurs.length; // copy length

  // dynamically allocate array for mySet
  mySet = new myType[length];

  // deep copy mySet array elements
  for (int i=0; i<length; i++) {  
    mySet[i] = myRecurs.mySet[i];
  }

}

/* destructor_identifier: delete myType array, set mySet to nullptr, set length to 0
 * parameters: none
 * return type: none */
template <class myType>
recursionSet <myType>::~recursionSet()
{
  delete [] mySet; // delete mySet array

  // set mySet to nullptr and length to 0
  mySet = nullptr;
  length = 0;
}

/* function_identifier: return class length
 * parameters: none
 * return type: int (length) */
template <class myType>
int recursionSet <myType>::getSetLength() const
{
  return length;
}

/* function_identifier: dynamically create array and fill with random values
 * parameters: size of array
 * return type: none */
template <class myType>
void recursionSet <myType>::generateElements(int sizeLimit)
{
  // dynamically allocate mySet of size sizeLimit
  mySet = new myType[sizeLimit];

  length = sizeLimit;

  // cast and fill array with random values
  for (int i = 0; i < sizeLimit; i++) {
    mySet[i] = static_cast<myType>(rand()%LIMIT);
  }

  return;
}

/* function_identifier: get and return element from passed index
 * parameters: passed index
 * return type: myType (mySet[pIndex]) */
template <class myType>
myType recursionSet <myType>::getElement(int pIndex) const
{
  // bounds checking
  if (pIndex < 0 || pIndex >= length) {
    cout << "getElement: Error, invalid index." << endl;
    return {};
  }
  
  return mySet[pIndex];
}

/* function_identifier: set element in the class array at the given index location
 * parameters: passed index (int) and myValue (myType)
 * return type: none */
template <class myType>
void recursionSet <myType>::setElement(int pIndex, myType myValue)
{
  mySet[pIndex] = myValue; // set element at passed index to myValue

  return;
}

/* function_identifier: prompt with passed string and read in number
 * parameters: passed in string (const string)
 * return type: int (numInput) */
template <class myType>
int recursionSet <myType>::readValue(const string pString) const
{
  int numInput = 0; // user input number
  int errorCount = 0; // error counter

  do {
    try {
      // Prompt for and user input number
      cout << pString;
      cin >> numInput;

      if (numInput < 1 || numInput > MAX_VALUE) {
        errorCount++;
        throw 0;
      }
      if (errorCount > 3) {
        throw 0.0;
      }
      if (cin.fail()) {
        throw "string";
      }
    }
    catch (string) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "readValue: Error, invalid value." << endl;
      return 0;
    }
    catch (int) {
      cout << "readValue: Error, value " << numInput;
      cout << " not between 1 and " << MAX_VALUE << "." << endl;
    }
    catch (double) {
      cout << "readValue: Sorry, too many errors." << endl;
      return 0;
    }
    // loop if user input is incorrect
  } while (errorCount <= 3 && (numInput < 1 || numInput > MAX_VALUE));

  return numInput;
}

/* function_identifier: print formatted class array with passed number of values per line
 * parameters: passed number of values (int)
 * return type: none */
template <class myType>
void recursionSet <myType>::printSet(int pNumValues) const
{
  int counter = 0;
  
  // loop through data
  for (int i = 0; i < length; i++) {
    cout << setw(5) << mySet[i] << "\t";
    counter++;

    // increment counter until passed number of values per line
    if (counter == pNumValues) {
      cout << endl;
      counter = 0;
    }
  }

  return;
}

/* function_identifier: compare if object is equal to its copy
 * parameters: passed in object (const recursionSet<myType>)
 * return type: bool (true if equal) */
template <class myType>
bool recursionSet <myType>::operator == (const recursionSet<myType>& myRecurs)
{
  // compare if object is equal to copy
  for (int i = 0; i < length; i++) {
    if (mySet[i] != myRecurs.mySet[i]) {
      return false;
    }
  }

  return true;
}

/* function_identifier: recursively compute Tak function
 * parameters: x, y, z (all myType parameters)
 * return type: myType */
template <class myType>
myType recursionSet <myType>::tak(myType x, myType y, myType z) const
{
  // if (y >= z)
    // return z;

  if (y < x)
    return tak(tak(x-1, y, z), tak(y-1, z, x), tak(z-1, x, y));
  
  return z;
}

/* function_identifier: print numberic argument in septenary format
 * parameters: passed in number (myType)
 * return type: none */
template <class myType>
void recursionSet <myType>::printSeptenary(myType pNum) const
{

  if (pNum > 7) {
    printSeptenary(pNum/7);
    cout << pNum % 7;
  }
  if (pNum <= 7)
    cout << pNum % 7;

  return;
}

/* function_identifier: perform recursive estimation of square root
 * parameters: x, epsilon (all myType)
 * return type: myType (recSqRoot(x, a, epsilon)) */
template <class myType>
myType recursionSet <myType>::squareRoot(myType x, myType epsilon) const
{
  return recSqRoot(x, x, epsilon);
}

/* function_identifier: recursively determines estimated square root
 * parameters: x, a, epsilon (all myType)
 * return type: myType */
template <class myType>
myType recursionSet <myType>::recSqRoot(myType x, myType a, myType epsilon) const
{
  if (abs(pow(a, 2.0)-x) > epsilon)
    return recSqRoot(x, ((pow(a, 2.0)+x)/(2*a)), epsilon);

  return a;
}

/* function_identifier: perform recursive summation of values
 * parameters: none
 * return type: rSum(length) */
template <class myType>
myType recursionSet <myType>::recursiveSum() const
{
  return rSum(length);
}

/* function_identifier: accepts length of data and performs recursive summation
 * parameters: rPosition (int)
 * return type: myType (recursiveSum()) */
template <class myType>
myType recursionSet <myType>::rSum(int rPosition) const
{
  if (rPosition > 0) 
    return mySet[rPosition] + rSum(rPosition-1);
  
  return mySet[0];
}

/* function_identifier: 
 * parameters: 
 * return type:  */
template <class myType>
bool recursionSet <myType>::checkParentheses(string parenStr) const
{
  return recChkPar(parenStr, 0, 0);
}

/* function_identifier: 
 * parameters: 
 * return type:  */
template <class myType>
bool recursionSet <myType>::recChkPar(string tempStr, int index, int parenCount) const
{
  if (index < static_cast<int>(tempStr.length())) {
    
    if (tempStr[index] == '(') {
      parenCount++;
      return recChkPar(tempStr, index+1, parenCount);
    }

    if (tempStr[index] == ')') {
      parenCount--;
      if (parenCount < 0) {
        return false;
      }
      return recChkPar(tempStr, index+1, parenCount);
    }

    if (tempStr[index] != '(' && tempStr[index] != ')') {
      return recChkPar(tempStr, index+1, parenCount);
    }

  }

  if (index == static_cast<int>(tempStr.length())) {
    if (parenCount == 0) {
      return true;
    }
    else {
      return false;
    }
  }

  return false;
}

/* function_identifier: sort data set array using recursive insertion sort
 * parameters: none
 * return type: none */
template <class myType>
void recursionSet <myType>::recursiveInsertionSort()
{
  // verify length is valid
  if (length <= 0)
    return;
  
  // if valid, perform recuursive sort
  else
    recInsSort(0, length-1);

  return;
}

/* function_identifier: recursive insertion sort
 * parameters: first index, last index (both int)
 * return type: none */
template <class myType>
void recursionSet <myType>::recInsSort(int fIndex, int lIndex) 
{

  if (fIndex < lIndex) {
    // recursively sort all but last element
    recInsSort(fIndex, lIndex-1);

    // insert last element in order from first through last positions
    insertInOrder(mySet[lIndex], fIndex, lIndex-1);
  }

  return;
}

/* function_identifier: recursively insert passed element in correct position
 * parameters: myElement (myType), starting index, ending index (both int)
 * return type: none */
template <class myType>
void recursionSet <myType>::insertInOrder(myType myElement, int sIndex, int eIndex)
{
  // if element is greater, insert element at the end
  if (myElement >= mySet[eIndex]) {
    mySet[eIndex+1] = myElement;
  }

  // if first is less than last, insert last element at end of sorted...
  else if (mySet[sIndex] < mySet[eIndex]) {
    mySet[eIndex+1] = mySet[eIndex];
    insertInOrder(myElement, sIndex, eIndex-1);
  }

  // otherwise insert last element at end of sorted...
  else {
    mySet[eIndex+1] = mySet[eIndex];
    mySet[eIndex] =  myElement;
  }

  return;
}


#endif
