#include <iostream>
using namespace std;

template<class genType, int size=50>
class genClass{
  genType storage[size];
};

// Initializing the types
genClass<int> intObject;
genClass<float> floatObject;
genClass<int, 100> intObject2;

// using the template structure for swap fn 
template<class genMeth>
void swap(genMeth& el1, genMeth& el2) {
  genMeth tmp = el1;
  el1 = el2;
  el2 = tmp;
}

int main () {
  genMeth<int> el1 = 5, el2 = 7;
  swap(el1, el2);
  cout << el1 << endl;
  return 0;
}

