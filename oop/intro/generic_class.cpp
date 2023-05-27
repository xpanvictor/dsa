
template<class genType, int size=50>
class genClass{
  genType storage[size];
}

// Initializing the types
genClass<int> intObject;
genClass<float> floatObject;
genclass<int, 100> intObject2;

// using the template structure for swap fn 
template<class genMeth>
void swap(genMet& el1, genMeth& el2) {
  genMeth tmp = el1;
  el1 = el2;
  el2 = tmp;
}

