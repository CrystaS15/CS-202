#ifndef STATS_TYPE_H
#define STATS_TYPE_H

/*
Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 7
Description: statsType header file
// Provide functionality for providing basic statistical functions
*/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
using namespace std;

template <typename myType>
class statsType {
  private:
    int setSize;
    myType *dataSet;
    string fileName;
  public:
    statsType();
    // set fileName(string), setSize(int), and dataSet(pointer)

    statsType(string);
    // accept fileName, set setSize and dataSet

    ~statsType();
    // delete myType array and set dataSet, setSize, fileName

    string getFileName() const;
    // return current fileName

    bool setFileName(string);
    //  set class variable to passed value

    bool readFileName();
    // prompt for and read fileName from user
    
    bool readDataFile();
    // read data file (from fileName)

    myType getElement(int) const;
    // return data item of type myType...
    
    void setElement(int, myType);
    // set passed data item of myType...

    int getSetSize() const;
    // returns current set size

    void getLimits(myType &, myType &) const;
    // find and return min and max values in set via reference

    myType getMedian() const;
    // find and return median value in set
    
    myType getSum() const;
    // find and return sum for current data set

    myType getAverage() const;
    // find and return average for current data set using getSum()
    
    void insertionSort();
    // sorts data set with standard insertion sort

    void printDataSet() const;
    // print data items of myType with (9) values
    
    myType sampleStandardDeviation() const;
    // compute sample standard deviation^2 of current data set

    myType populationStandardDeviation() const;
    // compute population standard deviation of current class data
    
    myType skew() const;
    // calculate and return skew value

    myType FPcoeff() const;
    // calculate Fisher-Pearson standardized moment coefficient
    
    void benfordsGraph() const;
    // determine 1st digit and count occurrences for each

};

/* function_identifier: set fileName, setSize, and dataSet
 * parameters: none
 * return type: none */
template <typename myType>
statsType <myType>::statsType() {
  fileName = "";
  setSize = 0;
  dataSet = nullptr;
}

/* function_identifier: accept fileName and set setSize, dataSet
 * parameters: none
 * return type: none */
template <typename myType>
statsType <myType>::statsType(string sName) {
  fileName = sName;
  setSize = 0;
  dataSet = nullptr;
}


/* function_identifier: delete myType array and set dataSet, setSize, fileName
 * parameters: none
 * return type: none */
template <typename myType>
statsType <myType>::~statsType(){
  delete [] dataSet; // delete myType array
  
  // set dataSet(pointer), setSize(int), fileName(string)
  dataSet = nullptr;
  setSize = 0;
  fileName = "";
}

/* function_identifier: return current fileName
 * parameters: none
 * return type: fileName(string) */
template <typename myType>
string statsType<myType>::getFileName() const {
  return fileName;
}

/* function_identifier: set class variable to passed value
 * parameters: passed in sName (string)
 * return type: (bool) true if no error */
template <typename myType>
bool statsType<myType>::setFileName(string sName) {
  
  // file name must contain 1 character with extension '.txt' or '.dat'
  if (sName.length() < 5 &&
      (sName.find(".txt") == string::npos && 
        sName.find(".dat") == string::npos))
  {
    cout << "Error, invalid file name." << endl;
    return false;
  } 
  
  // file name must include extension '.txt' or '.dat'
  if(sName.find(".txt") == string::npos && 
      sName.find(".dat") == string::npos)
  {
    cout << "Error, file name must be '.txt' or '.dat' extension.";
    cout << endl;
    return false;
  }
  
  // file name must exist
  if (access(sName.c_str(), F_OK) == -1)
  {
    cout << "setFileName: Error, file does not exist." << endl;
    return false;
  }

  // accept fileName and return true
  fileName = sName;

  return true;
}

/* function_identifier: prompt for and read fileName from user
 * parameters: passed in sName (string)
 * return type: (bool) true if no error */
template <typename myType>
bool statsType<myType>::readFileName() {
  
  // string to user input file name
  string sName;

  // Prompt and re-prompt until valid input received
  do
  {
    cout << "Enter Input File Name: ";
    cin >> sName;

    // file name must contain 1 character with extension '.txt' or '.dat'
    if (sName.length() < 5 &&
        (sName.find(".txt") == string::npos && 
          sName.find(".dat") == string::npos))
      cout << "Error, invalid file name." << endl;
    
    // file name must include extension '.txt' or '.dat'
    if(sName.find(".txt") == string::npos && 
        sName.find(".dat") == string::npos)
    {
      cout << "Error, file name must be '.txt' or '.dat' extension.";
      cout << endl;
    }
    
    // file name must exist
    if (access(sName.c_str(), F_OK) == -1)
      cout << "Error, file name does not exist." << endl;

  } while (setFileName(sName) == false);
  
  // set fileName if setFileName(sName) is true
  if (setFileName(sName) == true)
  { 
    fileName = sName;
    return true;
  }

  return false;
}

/* function_identifier: read data file (from fileName)
 * parameters: none
 * return type: true if data successfully read */
template <typename myType>
bool statsType<myType>::readDataFile() {
  ifstream inFile; // input file stream
  int countValue = 0; // variable to read in count of values
  
  // open file named fileName and display error if unable to open
  inFile.open(fileName);

  if (inFile.is_open() == false)
  {
    // cout << "readDataFile: ";
    // cout << "Error, file named " << fileName << "was unable to open.";
    // cout << endl;
    return false;
  }
  else {
    // skip first four lines of data file
    for (int i = 1; i < 5; i++) {
      inFile.ignore(100, '\n');
    }

    // set class variable equal to value read in from file
    inFile >> countValue;

    setSize = countValue;

    // allocate memory for array of setSize components of type myType
    dataSet = new myType[setSize];

    // read in values
    for (int i = 0; i < setSize; i++) {
      inFile >> dataSet[i];
    }

  }

  return true;
}

/* function_identifier: return data item of myType at location of passed index
 * parameters: passed index (int)
 * return type: myType */
template <typename myType>
myType statsType<myType>::getElement(int passedIndex) const {
  
  // Error for invalid index
  if (passedIndex < 0 || passedIndex >= setSize) {
    cout << "getElement: Error, invalid index value." << endl;
    return {};
  }
  else
    return dataSet[passedIndex];
  
}

template <typename myType>
void statsType<myType>::setElement(int passedIndex, myType myData) {
  
  // Error for invalid index
  if (passedIndex < 0 || passedIndex >= setSize) {
    cout << "setElement: Error, invalid index value." << endl;
    return;
  }
  else
    dataSet[passedIndex] = myData;

  return;
}


/* function_identifier: returns current setSize
 * parameters: none
 * return type: setSize (int) */
template <typename myType>
int statsType<myType>::getSetSize() const {
  return setSize;
}

/* function_identifier: find and return min and max values via reference
 * parameters: min and max of type myType
 * return type: none */
template <typename myType>
void statsType<myType>::getLimits(myType& myMin, myType& myMax) const {
  
  cout << fixed;
  
  // if there is no set...
  if (dataSet == nullptr || setSize == 0) {
    cout << "limits: Error, no set defined." << endl;
    myMin = {};
    myMax = {};
    return;
  }

  // initialize min and max variables
  myMin = dataSet[0];
  myMax = {};

  // Loop through myType array
  for (int i = 0; i < setSize; i++) {
    
    // find maximum value
    if (dataSet[i] > myMax)
      myMax = dataSet[i];

    // find minimum value
    if (dataSet[i] < myMin)
      myMin = dataSet[i];

  }
  
  
  return;
}

/* function_identifier: find and return median value in set
 * parameters: none
 * return type: none */
template <typename myType>
myType statsType<myType>::getMedian() const {
  // define median variable of type myType
  myType myMedian = {};
  
  // if there is no set...
  if (dataSet == nullptr || setSize == 0) {
    cout << "median: Error, no set defined." << endl;
    myMedian = 0;
    return {};
  }

  else {

    // median calculation for odd set
    if (setSize % 2 == 1) { 
      myMedian = dataSet[(setSize-1)/2];
    }
    // median calculation for even set
    else if (setSize % 2 == 0) {
      myMedian = (dataSet[(setSize/2)-1] + dataSet[setSize/2])/2.0;
    }
    
  }

  return myMedian;
}


/* function_identifier: find and return the sum for the current data set
 * parameters: none
 * return type: mySum (myType) */
template <typename myType>
myType statsType<myType>::getSum() const {
  // define sum variable of type myType
  myType mySum = {};

  // if there is no set...
  if (dataSet == nullptr || setSize == 0) {
    cout << "sum: Error, no set defined." << endl;
    mySum = 0;
    return {};
  }

  // calculate sum
  else {
    for (int i = 0; i < setSize; i++) {
      mySum += dataSet[i];
    }
  }

  return mySum;
}


/* function_identifier: find and return the average for current data set
 * parameters: none
 * return type: myAverage (myType) */
template <typename myType>
myType statsType<myType>::getAverage() const {
  // initialize a variable for average of type myType
  myType myAverage = {};

  // if there is no set...
  if (dataSet == nullptr || setSize == 0) {
    cout << "average: Error, no set defined." << endl;
    return {};
  }
  
  // calculate average
  else
    myAverage = getSum() / setSize;

  return myAverage;
}


/* function_identifier: sorts the data with standard insertion sort
 * parameters: none
 * return type: none */
template <typename myType>
void statsType<myType>::insertionSort() {
  // define value of type myType
  myType value = 0;

  // define counter variable called j
  int j = 0;

  // insertion sort algorithm
  for (int i = 1; i < setSize; i++) {
    value = dataSet[i];
    j = i - 1;
    while ((j>=0) && (dataSet[j] > value)) {
      dataSet[j+1] = dataSet[j];
      j--;
    }
    dataSet[j+1] = value;
  }

}

/* function_identifier: print data items of type myType with 9 values per line
 * parameters: none
 * return type: none */
template <typename myType>
void statsType<myType>::printDataSet() const {

  // width for first column
  cout << setw(6);

  // formatting for the rest of the data
  for (int i = 0; i < setSize; i++) {
    
    // other 8 columns
    cout << setw(8) << dataSet[i];

    // 9 numbers per line
    if ((i+1) % 9 == 0)
      cout << endl;
  }
  

  return;
}

/* function_identifier: compute sample standard deviation^2
 * parameters: none
 * return type: mySampleSD (myType) */
template <typename myType>
myType statsType<myType>::sampleStandardDeviation() const {
  
  // define variable for sample SD of type myType
  myType mySampleSD = {};
  myType mySum = {};

  // if there is no set...
  if (dataSet == nullptr || setSize == 0) {
    cout << "sampleStandardDeviation: Error, no set defined." << endl;
    return {};
  }
   
  // calculate mySum
  for (int i = 0; i < setSize; i++) {
    mySum += pow(dataSet[i] - getAverage(), 2.0);
  }

  // calculate sample standard deviation
  mySampleSD = sqrt(mySum / (setSize-1));

  return mySampleSD;
}


/* function_identifier: compute population standard deviation
 * parameters: none
 * return type: myPopulationSD (myType) */
template <typename myType>
myType statsType<myType>::populationStandardDeviation() const {
  
  // define variable for population SD of type myType
  myType myPopulationSD = {};
  myType mySum = {};

  // if there is no set...
  if (dataSet == nullptr || setSize == 0) {
    cout << "populationStandardDeviation: Error, no set defined." << endl;
    return {};
  }
   
  // calculate mySum
  for (int i = 0; i < setSize; i++) {
    mySum += pow(dataSet[i] - getAverage(), 2.0);
  }

  // calculate population standard deviation
  myPopulationSD = sqrt(mySum / setSize);


  return myPopulationSD;
}

/* function_identifier: calculate and return skew value
 * parameters: none
 * return type: mySkew (myType) */
template <typename myType>
myType statsType<myType>::skew() const {
  
  // declare variable for skew of type myType
  myType mySkew = {};

  if (dataSet == nullptr || setSize == 0) {
    cout << "skew: Error, no set defined." << endl;
    return {};
  }

  // calculate mySkew
  mySkew = (3*(getAverage() - getMedian())) / populationStandardDeviation();

  return mySkew;
}


/* function_identifer: calculate Fisher-Pearson standardized moment coefficient
 * parameters: none
 * return type: myFPcoeff (myType) */
template <typename myType>
myType statsType<myType>::FPcoeff() const {
  
  // define variable for FPcoeff of type myType
  myType myFPcoeff = {};
  myType mySum = {};
  myType average = getAverage();
  myType populationSD = populationStandardDeviation();

  // if there is no set...
  if (dataSet == nullptr || setSize == 0) {
    cout << "FPcoeff: Error, no set defined." << endl;
    return {};
  }

  // calculate mySum
  for (int i = 0; i < setSize; i++) {
    mySum += pow( (dataSet[i] - average)/populationSD , 3.0);
  }

  // calculate myFPcoeff
  myFPcoeff = (static_cast<myType>(setSize)/
              (static_cast<myType>(setSize-1)*
                static_cast<myType>(setSize-2))) * mySum;


  return myFPcoeff;
}

/* function_identifier: determine the 1st digit for each value and count occurences
 * parameters: none
 * return type: none */
template <typename myType>
void statsType<myType>::benfordsGraph() const {
  
  // int starCount[10] = {};
  // // int max = 0;

  // // 
  // int digits[10] = {};

  // myType temp;
  
  // string stringValue;

  // if dataSet nullptr...

  // for (int i = 0; i < setSize; i++) {
    
  //   temp = dataSet[i];
    
  //   while (temp >= 10) {
  //     temp = temp / 10;
  //   }

  //   if (temp < 10) 
  //     digits[i] = static_cast<int>(temp);
    
  //   if (digits[i] == i)
  //     digits[i]++;
    
  // }

  // for (int i = 0; i < setSize; i++) {
  //   stringValue = to_string(dataSet[i]);
  //   if (stringValue[i] == to_string(i))
  //     digits[i] += 1;
  // }

  // for (int i = 0; i < 10; i++) {
  //   starCount[i] = 50 * (static_cast<double>(digits[i]) / static_cast<double>(setSize));
  // }

  cout << "--------------------------------------------------" << endl;
  cout << "Benfords Law - Test Results" << endl;
  cout << "  Total Data Points: " << endl << endl;
  // cout << "digits (" << digits[0] << ")" << endl;
  // cout << "dataSet (" << dataSet[0] << ")" << endl;
  for (int i = 0; i < 10; i++) {
    
    cout << right << setw(3) << i;
    cout << right << setw(9) << " " << "| ";
    cout << setw(50) << setfill(' ');
    cout << endl;
    // cout << left << setfill('*') << setw(starCount[i]) << endl;
    // if (starCount[i] > max)
    //   max = starCount[i];
    
  }
  // cout << setfill(' ') << setw(11);
  // cout << setfill('-') << setw(max+6);
  // cout << endl;

  return;
}

#endif