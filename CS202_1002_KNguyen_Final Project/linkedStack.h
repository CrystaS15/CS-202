#ifndef LINKED_STACK_H
#define LINKED_STACK_H

/* Name: Kristy Nguyen, NSHE ID# 5006243601, CS 202-1002, Final Project
 * Description: linkedStack header to implement stack using linked list */

#include <iostream>
#include <cassert>

using namespace std;

// Linked Stack node structure
template <class myType>
struct nodeType {
  myType info;
  nodeType<myType> *link;
};

// Linked Stack class definition
template <class myType>
class linkedStack {
  private:
    nodeType<myType> *stackTop;
    int count;

    myType rSum (nodeType<myType> *) const;
    // performs a recursive summation
    void copyStack (const linkedStack<myType>&);
    // makes an identical copy of a stack

  public:
    bool operator == (const linkedStack<myType>&);
    // overloaded == compares current and passed stacks

    bool operator != (const linkedStack<myType>&);
    // overloaded != compares current and passed stacks

    linkedStack ();
    // constructor initializes stack to empty state

    linkedStack (const linkedStack<myType>&);
    // copy constructor creates a new, deep copy of passed stack
    
    ~linkedStack ();
    // destructor deletes stack (including allocated memory)

    void deleteStack ();
    // reinitializes stack to an empty state

    bool isStackEmpty() const;
    // determines whether stack is empty

    void push (const myType&);
    // add passed item to top of stack

    myType peek () const;
    // return current top of stack

    myType pop();
    // return and remove top item from stack

    int stackCount () const;
    // return count of items currently on stack

    myType stackSum () const;
    // return sum of all items currently on stack
    // use recursive rSum () function

};

// Linked Stack function definitions

/* function_identifier: compares current and passed stacks
 * parameters: otherStack (const linkedStack<myType>&)
 * return type: bool (true if same) */
template <class myType>
bool linkedStack<myType>::operator == (const linkedStack<myType>& otherStack) {
  if (this == &otherStack)
    return true;

  return false;
}

/* function_identifier: compares current and passed stacks
 * parameters: otherStack (const linkedStack<myType>&)
 * return type: bool (true if not same) */
template <class myType>
bool linkedStack<myType>::operator != (const linkedStack<myType>& otherStack) {
  if (this != &otherStack)
    return true;

  return false;
}

/* constructor_identifier: (default) initializes stack to empty state
 * parameters: none
 * return type: none */
template <class myType>
linkedStack<myType>::linkedStack () {
  stackTop = nullptr;
  count = 0;
}

/* constructor_identifier: (copy) creates a new, deep copy of passed stack
 * parameters:  (const linkedStack<myType>&)
 * return type: none */
template <class myType>
linkedStack<myType>::linkedStack (const linkedStack<myType>& otherStack) {
  stackTop = nullptr;
  copyStack (otherStack);
}

/* destructor_identifier: deletes stack (including allocated memory)
 * parameters: none
 * return type: none */
template <class myType>
linkedStack<myType>::~linkedStack () {
  deleteStack ();
}

/* function_identifier: reinitializes stack to an empty state
 * parameters: none
 * return type: none */
template <class myType>
void linkedStack<myType>::deleteStack () {

  nodeType<myType> *temp; // pointer to delete node

  while (stackTop != nullptr) { // while elements are in stack...

    temp = stackTop; // temp points to current node

    stackTop = stackTop->link; // advance stackTop to next node

    delete temp; // deallocate memory occupied by temp

  }

  count = 0;

  return;
}

/* function_identifier: determines whether stack is empty
 * parameters: none
 * return type: bool (stackTop == nullptr) */
template <class myType>
bool linkedStack<myType>::isStackEmpty() const {
  return (stackTop == nullptr);
}

/* function_identifier: add passed item to top of stack
 * parameters:  newElement (const myType&)
 * return type: none */
template <class myType>
void linkedStack<myType>::push (const myType& newElement) {
  
  // Pointer to create new node
  nodeType<myType> *newNode;

  // Create new node and store newElement in info field
  newNode = new nodeType<myType>;
  newNode->info = newElement; 

  // Insert newNode at top of the stack
  newNode->link = stackTop; 

  // Make stackTop point to the top element
  stackTop = newNode; 

  count++;

  return;
}

/* function_identifier: return current top of stack
 * parameters: none
 * return type: myType (stackTop->info) */
template <class myType>
myType linkedStack<myType>::peek () const {
  
  assert(stackTop != nullptr); // if stack is empty, terminate program

  return stackTop->info; // return top element
}

/* function_identifier: return and remove top item from stack
 * parameters: none
 * return type: myType (stackTop->info) */
template <class myType>
myType linkedStack<myType>::pop() {
  
  nodeType<myType> *temp; // pointer to deallocate memory
  myType topElement = stackTop->info;

  if (stackTop != nullptr) {
    
    temp = stackTop; // temp points to top of the stack

    stackTop = stackTop->link; // advance stackTop to next node

    delete temp; // deallocate memory pointed to by temp
  }

  count--;

  return topElement; // return top element
}

/* function_identifier: return count of items currently on stack
 * parameters: none
 * return type: int (count) */
template <class myType>
int linkedStack<myType>::stackCount () const {
  return count;
}

/* function_identifier: return sum of all items currently on stack
 * parameters: none
 * return type: myType (rSum(stackCount)) */
template <class myType>
myType linkedStack<myType>::stackSum () const {
  return rSum(stackCount);
}

/* function_identifier: performs a recursive summation
 * parameters: element position (nodeType<myType> *)
 * return type: myType (recursive sum) */
template <class myType>
myType linkedStack<myType>::rSum (nodeType<myType> *elementPos) const {
  if (elementPos > 0)
    return (stackTop[elementPos] + rSum(elementPos-1));

  return stackTop[0];
}

/* function_identifier: makes an identical copy of a stack
 * parameters: otherStack (const linkedStack<myType>&)
 * return type: none */
template <class myType>
void linkedStack<myType>::copyStack (const linkedStack<myType>& otherStack) {

  nodeType<myType> *newNode, *current, *last;

  if (stackTop != nullptr) // make stack empty if not already empty
    deleteStack ();

  if (otherStack.stackTop == nullptr)
    stackTop = nullptr;
  else {

    // Current points to the stack to be copied
    current = otherStack.stackTop; 

    count = otherStack.count;

    // Copy stackTop element of the stack
    stackTop = new nodeType<myType>; // create node
    stackTop->info = current->info; // copy info
    stackTop->link = nullptr; // set link field to nullptr
    last = stackTop; // last points to node
    current = current->link; // current points to next node

    // Copy remaining stack
    while (current != nullptr) {
      newNode = new nodeType<myType>;

      newNode->info = current->info;
      newNode->link = nullptr;
      last->link = newNode;
      last = newNode;
      current = current->link;
    }

  }

  return;
}

#endif