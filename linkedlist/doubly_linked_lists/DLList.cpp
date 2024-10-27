
#include "DLList.h"

template <class T>
void
DoublyLinkedList<T>::addToDLLTail (const T &el)
{
  if (tail != 0)
    {
      tail = new DLLNode (el, 0, tail);
      tail->prev->next = tail;
    }
  else
    head = tail = new DLLNode (el);
}

template <class T>
T
DoublyLinkedList<T>::deleteFromDLLTail ()
{
  T el = tail->info;
  if (tail == head)
    {
      delete head;
      tail = head = 0;
    }
  else
    {
      tail = tail->prev;
      delete tail->next;
      tail->next = 0;
    }
  return el;
}
