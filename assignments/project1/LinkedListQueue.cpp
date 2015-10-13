//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedListQueue::put_in(PuzzleState *elem)
{
    node * temp = new node;
    temp->data = elem;
    if(is_empty()) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = tail->next;
    }
    size++;
    cout << size << endl;
}

PuzzleState *LinkedListQueue::take_out()
{
    assert(!is_empty());
    PuzzleState *ret = head->data;
    node *temp = head;
    head = head->next;
    delete temp;
    size--;
    cout << size << endl;
    return ret;
}

bool LinkedListQueue::is_empty()
{
    return size == 0;
}

LinkedListQueue::~LinkedListQueue()
{
    while(size != 0)
        take_out();
}

#endif

