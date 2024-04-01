
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <class T> class Stack : public stack<T>
{
public:
  T
  pop ()
  {
    T tmp = this->top ();
    stack<T>::pop ();
    return tmp;
  }
};

template <class T> class Queue : public queue<T>
{
  T
  dequeue ()
  {
    T tmp = this->front ();
    this->pop ();
    return tmp;
  }
  void
  enqueue (const T &el)
  {
    push (el);
  }
};

template <class T> class BstNode
{
public:
  BstNode () { left = right = 0; }
  BstNode (const T &el, BstNode<T> *left = 0, BstNode<T> *right = 0)
  {
    el = el;
    left = left;
    right = right;
  }

  T el;
  BstNode<T> *left, *right;
};

template <class T> class BST
{
public:
  BST () { root = 0; }

  void
  clear ()
  {
    clear (root);
    root = 0;
  }

  bool
  isEmpty ()
  {
    return root == 0;
  }

  void
  preorder ()
  {
    preorder (root);
  }

  void
  postorder ()
  {
    postorder (root);
  }

  void
  inorder ()
  {
    inorder (root);
  }

  T *
  search (const T &el)
  {
    return search (root, el);
  }

  void breadthFirst ();
  void iterativePreorder ();
  void iterativeInorder ();
  void iterativePostorder ();
  void morrisInorder ();
  void insert (const T &);

protected:
  BstNode<T> *root; // a pointer to parent node - root
  void clear (BstNode<T> *);
  // search feature in protected mode
  T *search (BstNode<T> *, const T &) const;
  void preorder (BstNode<T> *);
  void inorder (BstNode<T> *);
  void postorder (BstNode<T> *);
  // just about to abstract the entire class
  virtual void
  visit (BstNode<T> *p)
  {
    cout << p->el << " ";
  }
};

#endif
