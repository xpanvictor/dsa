
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

template <class T>
void
BST<T>::iterativePostorder ()
{
  // Stack to traverse with
  Stack<BstNode<T> *> travStack;
  BstNode<T> *p = root, *q = root; // we use q as a marker for visited
  while (p != 0)
    {
      // we have to go all the way left, first part
      for (; p->left != 0; p = p->left)
        travStack.push (p); // pushing so we can have a way to climb back up
      // check if there's no right or we've visited the right so we can visit
      // current BstNode
      if (p->right == 0 || p->right == q)
        {
          visit (p);
          q = p; // mark p as visited
          // check that stack aint empty, else we end fn
          if (travStack.empty ())
            return;
          // go back up by popping from the stack
          p = travStack.pop ();
        }
      // prepare next p by going back up, taking the right element that has
      // been found by we popped the p before, let's push it back since we are
      // still ordering
      travStack.push (p);
      // then we take the right again
      p = p->right;
    }
}

template <class T>
void
BST<T>::morrisInorder ()
{
  // linearize the tree completely
  BstNode<T> *p = root, *tmp = root;
  while (p != 0)
    {
      // order the left
      if (p->left == 0)
        {
          visit (p);
          p = p->right; // basically go to the right element and continue
        }
      else
        {
          // fetch the rightmost node of the currrent left descendant
          for (tmp = p->left; tmp->right != 0 || tmp->right == p;
               tmp = tmp->right)
            ;
          // make the current node the right of the leftmost node
          tmp->right = p;
          // then the new top or "root" will be the current top left
          p = p->left;
        }
    }
}

template <class T>
void
BST<T>::insert (const T &el)
{
  BstNode<T> *p = root, *prev = 0;
  while (p != 0)
    {
      prev = p;
      if (prev->el < el)
        p = p->right;
      else
        p = p->left;
    }

  if (root == 0)
    root = new BstNode<T> (el);
  else if (el < prev->el)
    prev->left = new BstNode<T> (el);
  else
    prev->right = new BstNode<T> (el);
}
