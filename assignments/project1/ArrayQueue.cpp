#ifndef _ARRAYQUEUE_CPP
#define _ARRAYQUEUE_CPP

//ArrayQueue.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp file) is here to help get you
// started, but you are free to change function signatures, etc. as
// long as ArrayQueue is derived from BagOfPuzzleStates.
ArrayQueue::ArrayQueue() : capacity(INIT_SIZE), front(0) , back(capacity - 1), size(0)
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  array = new PuzzleState*[INIT_SIZE]; 
}

void ArrayQueue::put_in(PuzzleState *elem)
{
  ensure_capacity(size+1);
  size++;
  back = ( back + 1 ) % capacity;
  array[back] = elem;  
}

PuzzleState *ArrayQueue::take_out()
{
  assert(!is_empty());
  PuzzleState *temp_elem = array[front];
  front = (front+1) % capacity;
  size--;
  return temp_elem;

}

bool ArrayQueue::is_empty()
{
  return ( size == 0 );
}


void ArrayQueue::ensure_capacity(int n)
{
  if (capacity < n) {
    // Make plenty of room.
    int target_capacity = (n > 2*capacity) ? n : (2*capacity);

    PuzzleState **oldarray = array;
    array = new PuzzleState*[target_capacity];
    int foo[size];
    for( int i = 0; i < size; i++ ) {
        foo[i] = i;
    }
    int bar[size*2];
 
    int j = front;
    for ( int i = 0; i < size; i++){
      array[i] = oldarray[j];
      bar[i] = foo[j];
      j = (j + 1) % capacity;
    }

    for( int i = 0; i < size; i++ ) {
        cout << i << "\t" << foo[i] << "\t" << bar[i] << endl;
    }
    cout << "Front: " << front << endl;
    cout << "Back: " << back << endl;

    front = 0;
    back = size-1;
    capacity = target_capacity;

    cout << capacity << endl;

    delete [] oldarray;
  }
}


ArrayQueue::~ArrayQueue()
{
  delete [] array;
}

#endif
