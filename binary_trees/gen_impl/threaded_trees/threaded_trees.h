#ifndef THREADED_TREES
#define THREADED_TREES

template <class T> class ThreadedNode
{
public:
  ThreadedNode () { left = right = 0; }

  ThreadedNode (const T &el, ThreadedNode *l, ThreadedNode *r)
  {
    left = l;
    right = r;
    el = el;
  }

  T el;
  ThreadedNode *left, *right;
  unsigned int successor : 1;
};

template <class T> class ThreadedTree
{
public:
  ThreadedTree () { root = 0; }
  void
  inorder ()
  {
  }

protected:
  ThreadedNode<T> *root;
};

#endif // !THREADED_TREES
