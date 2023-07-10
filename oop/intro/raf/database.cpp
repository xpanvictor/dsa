#include "student.h"
#include "personal.h"
#include "database.h"
using namespace std;

template<class T>
Database<T>::Database() {
}

template<class T>
void Database<T>::add(T& d) {
  database.open(fName, ios::in | ios::out | ios::binary);
  database.seekp(0, ios::end);
  d.writeToFile(database);
  database.close();
}

