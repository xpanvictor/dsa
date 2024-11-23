
#include <iomanip>
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
public:
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
    this->push (el);
  }
};

template <class T> class BstNode
{
public:
  BstNode () { left = right = 0; }
  BstNode (const T &el, BstNode<T> *left = 0, BstNode<T> *right = 0)
  {
    this->el = el;
    this->left = left;
    this->right = right;
  }

  T el;
  BstNode<T> *left, *right;
};

template <class T> class BST
{
public:
  BST () { root = 0; }
  BST (BstNode<T> *r) { root = r; }

  void
  clear ()
  {
    clear (root);
    root = 0;
  }

  void
  printTree ()
  {
    print (root);
    cout << endl;
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
  void findAndDeleteByMerging (const T &);
  void deleteByMerging (BstNode<T> *);
  void balance (T data[], int first, int last);
  void createBackbone ();

protected:
  BstNode<T> *root; // a pointer to parent node - root
  void clear (BstNode<T> *);

  void
  print (BstNode<T> *node, int space = 0, int indent = 4)
  {
    if (node == nullptr)
      return;
    space += indent;
    // print right child first
    print (node->right, space);
    // print this node
    std::cout << endl;
    std::cout << std::setw (space) << node->el;
    // then left child
    print (node->left, space);
  }
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
