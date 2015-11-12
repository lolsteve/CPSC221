//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>
//#include <algorithm> //for std::iter_swap

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::put_in(PuzzleState *elem) {
  // TODO:  Put your code here!
  heap.push_back(elem);
  swapUp(heap.size() - 1);
}

PuzzleState * HeapPriorityQueue::take_out() {
  assert(!is_empty());

  // TODO:  Put your code here!
  PuzzleState * returnElem = heap.front();
  heap.erase(heap.begin());
  heap[0] = heap.pop_back();
  swapDown(0);
  return returnElem;
}


bool HeapPriorityQueue::is_empty() {
  return (heap.size() == 0);
}

int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

void HeapPriorityQueue::swapDown(int index) {
    int leftChild = first_child(index);
    int rightChild = first_child(index) + 1;
    int min = index;
    if(leftChild < heap.size() && heap.at(leftChild).getBadness() < heap.at(min).getBadness())
        min = leftChild;
    if(rightChild < heap.size() && heap.at(rightChild).getBadness() < heap.at(min).getBadness())
        min = rightChild;
    if(min != i) {
        //std::iter_swap(heap.begin() + index), heap.begin() + min);
        swap(heap.begin() + index, heap.begin() + min);
        swapDown(min);
    }
}

void HeapPriorityQueue::swapUp(int index) {
    if(is_root(index)) return;
    int parent = parent(index);
    if(heap.at(index).getBadness() < heap.at(parent).getBadness()) {
        swap(heap.begin() + index, heap.begin() + parent);
        swapUp(parent);
    }
}

#endif
