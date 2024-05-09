#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS 202-1002, Final Project
 * Description: linkedQueue header to implement queue with linked list */

#include <iostream>
#include <cassert>

using namespace std;

// Linked Queue node structure
template <class Type>
struct queueNode {
  Type info;
  queueNode<Type> *link;
};

// Linked Queue class definition
template <class Type>
class linkedQueue {
  private:
    queueNode<Type> *queueFront;
    queueNode<Type> *queueRear;
    int count;

    void copyQueue (const linkedQueue<Type>&);
    // used by copy constructor and overloaded =

  public:
    linkedQueue<Type>& operator = (const linkedQueue<Type>&);
    // overloaded = creates a new, deep copy of queue

    linkedQueue ();
    // constructor initializes queue to empty state

    linkedQueue (const linkedQueue<Type>&);
    // copy constructor creates new, deep copy of passed queue

    ~linkedQueue ();
    // destructor should delete queue (including allocated memory)

    bool isEmptyQueue () const;
    // determine whether queue is empty

    void initializeQueue ();
    // create and initialize new, empty queue

    void enqueue (const Type&);
    // add passed item to back of queue

    Type front () const;
    // return current front of queue

    Type back () const;
    // return current back of queue

    Type dequeue ();
    // remove and return front item from queue

    int queueCount (); 
    // return current count of elements in queue 

    void printQueue ();
    // print current elements of queue
    
};

/* function_identifier: creates a new, deep copy of queue
 * parameters: otherQueue (const linkedQueue<Type>&)
 * return type: linkedQueue<Type>& (*this) */
template <class Type>
linkedQueue<Type>& linkedQueue<Type>::operator = (const linkedQueue<Type> &otherQueue) {
  if (this != &otherQueue) // avoid self copy
    copyQueue (otherQueue);

  return *this;
}

/* constructor_identifier: (default) initializes queue to empty state
 * parameters: none
 * return type: none */
template <class Type>
linkedQueue<Type>::linkedQueue () {
  queueFront = nullptr;
  queueRear = nullptr;
  count = 0;
}

/* constructor_identifier: (copy) creates new, deep copy of passed queue
 * parameters: otherQueue (const linkedQueue<Type>&)
 * return type: none */
template <class Type>
linkedQueue<Type>::linkedQueue (const linkedQueue<Type> &otherQueue) {
  queueFront = nullptr;
  copyQueue (otherQueue);
}

/* destructor_identifier: should delete queue (including allocated memory) 
 * parameters: none 
 * return type: none */
template <class Type>
linkedQueue<Type>::~linkedQueue () {
  initializeQueue ();
}

/* function_identifier: determine whether queue is empty 
 * parameters: none 
 * return type: bool (queueFront == nullptr) */
template <class Type>
bool linkedQueue<Type>::isEmptyQueue () const {
  return (queueFront == nullptr);
}

/* function_identifier: create and initialize new, empty queue 
 * parameters: none 
 * return type: none */
template <class Type>
void linkedQueue<Type>::initializeQueue () {

  queueNode<Type> *temp;

  while (queueFront != nullptr) { // while elements are in queue

    temp = queueFront; // temp points to current node

    queueFront = queueFront->link; // advance first to next node

    delete temp; // deallocate memory occupied by temp

  }

  count = 0;

  queueRear = nullptr; // set rear to nullptr

  return;
}

/* function_identifier: add passed item to back of queue 
 * parameters: newElement (const Type&)
 * return type: none */
template <class Type>
void linkedQueue<Type>::enqueue (const Type& newElement) {

  queueNode<Type> *newNode;

  newNode = new queueNode<Type>; // create new node

  newNode->info = newElement; // store info
  newNode->link = nullptr; // initialize link to nullptr

  if (queueFront == nullptr) { // if queue is empty

    queueFront = newNode;
    queueRear = newNode;

  } 
  
  else { // add newNode at the end
    queueRear->link = newNode;
    queueRear = queueRear->link;
  }

  count++;

  return;
}

/* function_identifier: return current front of queue 
 * parameters: none 
 * return type: Type (queueFront->info) */
template <class Type>
Type linkedQueue<Type>::front () const {
  assert(queueFront != nullptr);

  return queueFront->info;
}

/* function_identifier: return current back of queue 
 * parameters: none 
 * return type: Type (queueRear->info) */
template <class Type>
Type linkedQueue<Type>::back () const {
  assert(queueRear != nullptr);

  return queueRear->info;
}

/* function_identifier: remove and return front item from queue 
 * parameters: none 
 * return type: Type (queueFront->info) */
template <class Type>
Type linkedQueue<Type>::dequeue () {
  
  queueNode<Type> *temp;
  Type frontElement = queueFront->info;

  if (!isEmptyQueue ()) {
    
    temp = queueFront; // temp points to first node

    queueFront = queueFront->link; // advance queueFront

    delete temp; // delete first node

    count--;

    if (queueFront == nullptr) // if queue is empty after deletion...
      queueRear = nullptr; // set queueRear to nullptr

  }

  else 
    cout << "Cannot remove from an empty queue" << endl;

  return frontElement;
}

/* function_identifier: return current count of elements in queue 
 * parameters: none 
 * return type: int (count) */
template <class Type>
int linkedQueue<Type>::queueCount () {
  return count;
}

/* function_identifier: print current elements of queue 
 * parameters: none 
 * return type: none */
template <class Type>
void linkedQueue<Type>::printQueue () {

  queueNode<Type> *current; // pointer to traverse list

  current = queueFront; // current points to first node

  while (current != nullptr) { // while more data to print 
    cout << current->info << " ";
    current = current->link;
  }

  return;
}

/* function_identifier: used by copy constructor and overloaded = 
 * parameters: otherQueue (const linkedQueue<Type>&)
 * return type: none */
template <class Type>
void linkedQueue<Type>::copyQueue (const linkedQueue<Type>& otherQueue) {

  queueNode<Type> *newNode, *current;

  if (!isEmptyQueue ()) // Make queue empty if not empty
    initializeQueue ();

  if (otherQueue.queueFront == nullptr) {
    queueFront = nullptr;
    queueRear = nullptr;
    count = 0;
  }

  else {

    // Current points to stack to be copied
    current = otherQueue.queueFront;

    count = otherQueue.count;

    // Copy the first node
    queueFront = new queueNode<Type>; // create new node

    queueFront->info = current->info; // copy info
    queueFront->link = nullptr; // set link field to nullptr

    queueRear = queueFront; // last points to first node
    current = current->link; // current points to next node

    // Copy remaining queue
    while (current != nullptr) {
      newNode = new queueNode<Type>;

      newNode->info = current->info;
      newNode->link = nullptr;
      queueRear->link = newNode;
      queueRear = newNode;
      current = current->link;
    }

  }

  return;
}

#endif