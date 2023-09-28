
#include <iostream>
#include "intSLList.h"


IntSLList::~IntSLList() {
  for (IntSLLNode * p; !isEmpty(); ) {
    p = head->next;
    delete head;
    head = p;
  }
}

void IntSLList::addToHead(int el) {
  head = new IntSLLNode(el, head);
  if (tail == 0) // first element
    tail = head;
}

void IntSLList::addToTail(int el) {
  // if list is not empty 
  if (tail != 0) {
    tail->next = new IntSLLNode(el);
    tail = tail->next;
  }
  else head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
  int el = head->info;
  IntSLLNode * tmp = head;
  if (head == tail)
    head = tail = 0;
  else head = head->next;
  delete tmp;
  return el;
}

int IntSLList::deleteFromTail() {
  int el = tail->info;
  if (head == tail) {
    delete head;
    head = tail = 0;
  } else {
    IntSLLNode *tmp;
    for (tmp = head; tmp->next != 0; tmp = tmp->next);
    delete tail;
    tail = tmp; // tail is current tmp node
    tail->next = 0; // change the next to 0 since previous next been deleted
  }
  return el;
}

void IntSLList::deleteNode(int el) {
}

