#include "iostream"
#include "string.h"
#include "stdlib.h"
using namespace std;

struct Node {
  public:
    char* name;
    int age;

  Node (char *n, int a) {
    name = strdup(n);
    age = a;
  }

  // copy constructor
  Node (const Node& n) {
    name = strdup(n.name);
    age = n.age;
  }

  // "=" operator
  Node& operator= (const Node& n) {
    // prevent self assignment
    if (this != &n) {
      if (name != 0)
        free(name);
      
      name = strdup(n.name);
      age = n.age;
    }
    return *this;
  }

  // destructor
  ~Node() {
    if (name != 0) // free only if used
      free(name);
  }
};

int main() {
  Node node1 ("victor", 5), node2(node1);
  Node node3 = node2;
  cout << "hello" << endl;
  return 0;
}


