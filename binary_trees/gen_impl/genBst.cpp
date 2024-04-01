
#include "genBst.h"

template <class T>
T *
BST<T>::search (BstNode<T> *p, const T &el) const
{
  // Uses an iterative search to find el
  // base case:
  while (p != 0)
    {
      if (p->el == el)
        return &p->el;
      if (p->el > el)
        p = p->right, el; // gt use right subtree
      else
        p = p->left, el;
    }
  // Not found, return 0
  return 0;
}
