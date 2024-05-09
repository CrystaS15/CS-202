/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS 202-1002, Assignment 10
 * Description: sortAlgorithms implementation file
 // sort algorithms set class will iomplement multiple sort algorithms and support functions */

#include "sortAlgorithms.h"
#include <iostream>
#include <iomanip>

using namespace std;

/* constructor_identifier: initialize class variables
 * parameters: none
 * return type: none */
sortAlgorithms::sortAlgorithms() {
  length = 0;
  myArray = nullptr;
  isDataSorted = false;
}


/* destructor_identifier: free allocated memory
 * parameters: none
 * return type: none */
sortAlgorithms::~sortAlgorithms() {
  delete [] myArray;

  myArray = nullptr;
}


/* function_identifier: dynamically allocate myArray, populate randomly
 * parameters: size (int)
 * return type: none */
void sortAlgorithms::generateDataRandom(int size) {
  
  // dynamically allocate myArray
  myArray = new int[size];

  // set length to size
  length = size;

  for (int i = 0; i < length; i++)
    myArray[i] = rand() % LIMIT;

  
  return;
}

/* function_identifier:dynamically allocate myArray, populate non-randomly
 * parameters: size (int)
 * return type: none */
void sortAlgorithms::generateDataNonRandom(int size) {
  
  // dynamically allocate myArray
  myArray = new int [size];

  // set length to size
  length = size;

  int k = LIMIT;
  for (int i = 0; i < length; i++) {
    myArray[i] = k;
    if (i % ((length/LIMIT)+1) == 0)
      k--;
  }


  return;
}

/* function_identifier: return current length/size of data set
 * parameters: none
 * return type: int(length) */
int sortAlgorithms::getLength() {
  return length;
}

/* function_identifier: return data item at passed index
 * parameters: passed index (int)
 * return type: int(myArray[pIndex]) */
int sortAlgorithms::getItem(int pIndex) {
  
  // Ensure passed index is valid
  if (pIndex < 0 || pIndex >= length) {
    cout << "getItem: Error, passed index is not valid." << endl;
    return 0;
  }

  return myArray[pIndex];

}

/* function_identifier: print current length/size of data set
 * parameters: none
 * return type: none */
void sortAlgorithms::printData() {
  
  // define variable for counter
  int counter = 0;

  // Loop through data, formatting data items accordingly
  for (int i = 0; i < length; i++) {
    cout << " " << setw(6) << myArray[i];
    counter++;
    
    // 10 items per line, reset counter
    if (counter == 10) {
      cout << endl;
      counter = 0;
    }
  }

  cout << endl;
  
  return;
}

/* function_identifier: prompt and read a number from user
 * parameters: none
 * return type: int(inputValue) */
int sortAlgorithms::readValue() const {
  
  // Variable to input value
  int inputValue = 0;

  do {

    // Prompt and user input value
    cout << "Enter Value: ";
    cin >> inputValue;
    cout << endl;

    try {
      
      // Invalid input 
      if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        throw 0; // throw (errNum) 0
      }

      // Out of range
      if (inputValue < MIN_LENGTH || inputValue > MAX_LENGTH) {
        cin.clear();
        cin.ignore(100, '\n');
        throw 1; // throw (errNum) 1
      }

    }
    catch (int errNum) {
      
      // if the error number is 0, invalid input error
      if (errNum == 0) {
        cout << "readValue: Error, invalid value." << endl;
      }

      // if the error number is 1, out of range error
      if (errNum == 1) {
        cout << "readValue: Error value " << inputValue;
        cout << " not between " << MIN_LENGTH;
        cout << " and " << MAX_LENGTH << "." << endl;
      }

    }
  
  // Continue looping (unlimited) until valid input is received
  } while (cin.fail() || (inputValue < MIN_LENGTH || inputValue > MAX_LENGTH));

  return inputValue;
}

/* function_identifier: sequentially search data set for passed value
 * parameters: passed value (int)
 * return type: bool() */
bool sortAlgorithms::isItemInUnsortedSet(int pValue) {
  // return true if passed value is found
  for (int i = 0; i < length; i++) {
    if (pValue == myArray[i])
      return true;
  }

  return false;
}

/* function_identifier: call binary search to search for passed value
 * parameters: passed value (int)
 * return type: bool (true if found) */
bool sortAlgorithms::isItemInSortedSet(int pValue) {
  
  if (binarySearch(pValue, 0, length-1) && isDataSorted) 
    return true;
  
  return false;
}

/* function_identifier: use bubble sort to sort current data set
 * parameters: none
 * return type: none */
void sortAlgorithms::bubbleSort() {

  // Variables created to help 'swap' elements
  int temp;
  bool swapped = false;
 
  // Visualgo bubbleSort algorithm
  do {

    swapped = false;
    for (int i = 0; i < length; i++) {

      if (myArray[i] < myArray[i+1]) {
        // Swap left element with right element
        temp = myArray[i];
        myArray[i] = myArray[i+1];
        myArray[i+1] = temp;

        // Set swap flag to true
        swapped = true;
      }

    }
  // Continue looping if swapped flag is true
  } while (swapped);

  isDataSorted = true;

  return;
}

/* function_identifier: use selection sort to sort current data set
 * parameters: none
 * return type: none */
void sortAlgorithms::selectionSort() {
  
  int temp; // variable to help swap elements
  int currentMax; // variable to store current max

  for (int i = 0; i < length-1; i++) {
    currentMax = i; // assume max is current element
    for (int j = i+1; j < length; j++) {
      
      // Store current element as new max if the element is greater
      if (myArray[j] > myArray[currentMax]) {
        currentMax = j;
      }

      if (currentMax != i) {
        temp = myArray[i];
        myArray[i] = myArray[currentMax];
        myArray[currentMax] = temp;
      }
    }
  }

  isDataSorted = true;

  return;
}

/* function_identifier: public quick sort calls private quick sort
 * parameters: none
 * return type: none */
void sortAlgorithms::quickSort() {

  // calls quickSort with 0 and length-1
  quickSort(0, length-1);

  isDataSorted = true;

  return;
}

/* function_identifier: use count sort algorithm to sort current data set
 * parameters: none
 * return type: none */
void sortAlgorithms::countSort() {
  // Dynamically create counter array to count individual elements
  int *counter = new int[LIMIT];
  
  // Dynamically allocate temp array to store sorted elements
  int *temp = new int[length];

  // Initialize counter array
  for (int i = 0; i < LIMIT; i++) 
    counter[i] = 0;

  // Initialize temp array
  for (int i = 0; i < length; i++) 
    temp[i] = 0;

  // Store count of each element 
  for (int i = 0; i < length; i++) 
    counter[myArray[i]]++;

  // Change so counter[i] contains actual position of element
  for (int i = 1; i <= LIMIT; ++i) 
    counter[i] += counter[i-1];

  // Store sorted elements in temp array 
  for (int i = length - 1; i >= 0; i--) {
    temp[counter[ myArray[i] ] - 1] = myArray[i];
    counter[myArray[i]]--;
  }

  // Copy temp array into myArray from largest to smallest element
  for (int i = 0; i < length; i++) 
    myArray[i] = temp[length-1-i];

  // De-allocate dynamically allocated memory
  delete [] counter;
  counter = nullptr;
  delete [] temp;
  temp = nullptr;

  isDataSorted = true;

  return;
} 

/* function_identifier: ensure data is sorted
 * parameters: none
 * return type: bool() */
bool sortAlgorithms::sanityCheck() const {
  // ensure each element is >= following element
  for (int i = 0; i < length; i++) {
    if (myArray[i] < myArray[i+1]) {
      return false;
    }
  }

  return true;
}

/* function_identifier: implement recursive binary search
 * parameters: passed item, first index, last index
 * return type: bool (true if passed item found) */
bool sortAlgorithms::binarySearch(int searchNum, int firstIndex, int lastIndex) {

  int middleElement = firstIndex + (lastIndex-firstIndex) / 2;
  
  if (myArray[middleElement] == searchNum)
    return true;

  /* Commented out due to SEG FAULT error */

  // else if (myArray[middleElement] > searchNum)
  //   return binarySearch(searchNum, firstIndex, middleElement-1);

  // else if (myArray[middleElement] < searchNum)
  //   return binarySearch(searchNum, middleElement+1, lastIndex);

  return false;
}

/* function_identifier: private quick sort to sort current data
 * parameters: low, high (both int)
 * return type: none */
void sortAlgorithms::quickSort(int low, int high) {

  int p = partition(low, high);

  if (low < high) {
    quickSort(low, p-1);
    quickSort(p+1, high);
  }

  return;
}

/* function_identifier: implements Lomuto partitioning scheme
 * parameters: low, high (both int)
 * return type: int (i) */
int sortAlgorithms::partition(int low, int high) {
  int pivot = myArray[high];
  int i = low;
  for (int j = low; j < high; j++) {
    if (myArray[j] > pivot) {
      swap(myArray[i], myArray[j]);
      i++;
    }
  }
  swap(myArray[i], myArray[high]);

  return i;
}

/* function_identifier: swap passed elements
 * parameters: left and right elements (both int)
 * return type: none */
void sortAlgorithms::swap(int& leftElement, int& rightElement) {
  int temp = leftElement;

  leftElement = rightElement;
  rightElement = temp;

  return;
}
