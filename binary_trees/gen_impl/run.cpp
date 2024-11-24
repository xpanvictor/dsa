#include "genBst.h"

int
main ()
{
  // some nodes
  BstNode<int> n7 (60);
  BstNode<int> n6 (45);
  BstNode<int> n5 (35);
  BstNode<int> n4 (25);
  BstNode<int> n3 (50, &n6, &n7);
  BstNode<int> n2 (30, &n4, &n5);
  BstNode<int> n1 (40, &n2, &n3);

  // pass root to tree
  BST<int> bt (&n1);

  // Iterative preorder
  cout << "IterativePreorder: ";
  bt.iterativePreorder ();
  cout << endl;

  // Iterative inorder
  cout << "IterativeInorder: ";
  bt.iterativeInorder ();
  cout << endl;

  // Iterative postorder
  cout << "IterativePostOrder: ";
  bt.iterativePostorder ();
  cout << endl;

  // Insert el
  cout << "Inserting element to tree \n";
  bt.insert (24);
  cout << "IterativePreorder: ";
  bt.iterativePreorder ();

  // create back bone
  bt.printTree ();
  cout << "\nCreating backbone";
  bt.createBackbone ();
  bt.printTree ();
}
