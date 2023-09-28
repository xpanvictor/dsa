
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
  if (!isEmpty()) {
    if (head == tail && el == head->info) { // one element
      delete head;
      head = tail = 0;
    } else if (head->info == el) {
      IntSLLNode * tmp = head;
      head = head->next;
      delete tmp;
    } else {// more than one element
      IntSLLNode * pred, * tmp;
      for (
          pred = head, tmp = head->next;
          tmp != 0 && !(tmp->info == el);
          pred = pred->next, tmp = tmp->next
        );
      // the tmp and pred deleted. tmp if el found is solved this way
      if (tmp != 0) {// for loop stopped cos el was found
        // remove tmp from list by changing prev's next to the next value
        pred->next = tmp->next;
        if (tmp == tail)
          tail = pred; // push tail to previous
        delete tmp;
      }
    }
  }
}

bool IntSLList::isInList(int el) const {
  IntSLLNode * tmp;
  for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
  return tmp != 0; // for loop stopped where it was el
}

