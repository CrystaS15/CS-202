#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS 202-1002, Assignment 10
 * Description: sortAlgorithms implementation file
 // sort algorithms set class will iomplement multiple sort algorithms and support functions */


class sortAlgorithms {
  private:
    int length;
    int *myArray;
    bool isDataSorted;
    static const int LIMIT = 1000;
    static const int MIN_LENGTH = 100;
    static const int MAX_LENGTH = 10000000;
    bool binarySearch(int, int, int);
    void quickSort(int, int);
    int partition(int, int);
    void swap(int &, int &);

  public:
    sortAlgorithms();
    ~sortAlgorithms();
    void generateDataRandom(int);
    void generateDataNonRandom(int);
    int getLength();
    int getItem(int);
    void printData();
    int readValue() const;
    bool isItemInUnsortedSet(int);
    bool isItemInSortedSet(int);
    void bubbleSort();
    void selectionSort();
    void quickSort();
    void countSort();
    bool sanityCheck() const;
    
};

#endif