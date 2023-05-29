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

  // ------Pointer and Reference Variables
  int n = 5, *p = &n, &r = n;
  // r is just another name for n now
  // int *const r = &n is same, while const int *r is a pointer to a constant
  // hence we can do this
  r = 4; // which changes all the values n, *n and r
  // WARNING: use Reference Variables carefully, it destroys the information hiding principle
  //
  // ----------Pointers to functions
  double f(double x) {
    return x * 2;
  }

  // A summation function to find doubles using pointer of the function
  double sum(double (*f)(double), int l_lmt, int u_lmt) {
    double result = 0;
    for (int i = l_lmt, i < u_lmt, i++) {
      result += f(i);
    }

    return result;
  }
  cout << sum(f, 1, 5) << endl;

  return 0;
}


