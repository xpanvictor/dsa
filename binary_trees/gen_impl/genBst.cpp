
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

template <class T>
void
BST<T>::breadthFirst ()
{
  Queue<BstNode<T> *> tree_queue;
  BstNode<T> *p = root;
  if (p != 0)
    {
      tree_queue.enqueue (p);
      while (!tree_queue.empty ())
        {
          p = tree_queue.dequeue ();
          visit (p);
          if (p->left != 0)
            tree_queue.enqueue (p->left);
          if (p->right != 0)
            tree_queue.enqueue (p->right);
        }
    }
}

template <class T>
void
BST<T>::inorder (BstNode<T> *p)
{
  // uses double recursion to accomplish LVR inorder traversin
  if (p != 0)
    {
      inorder (p->left);
      visit (p); // inner visit layer
      inorder (p->right);
    }
}

template <class T>
void
BST<T>::iterativePreorder ()
{
  // uses a stack for operation
  Stack<BstNode<T> *> iter_stack;
  BstNode<T> *p = root;
  if (p != 0)
    {
      iter_stack.push (p);
      while (!iter_stack.empty ())
        {
          p = iter_stack.pop ();
          visit (p); // visit first
          if (p->right != 0)
            iter_stack.push (p->right);
          if (p->left != 0) // pushing left later to be on top of stack
            iter_stack.push (p->left);
        }
    }
}
