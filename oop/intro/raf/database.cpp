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

template<class T>
void Database<T>::modify(T& d) {
  database.open(fName, ios::in | ios::out | ios::binary);
  
}

template<class T>
bool Database<T>::find(T& d) {
  T tmp;
  database.open(fName, ios::in | ios::binary);
  while(!database.eof()) {
    tmp.readFromFile(database);
    if (tmp == d) {// overloaded ==
      database.close();
      return true;
    }
  }
  database.close();
  return false;
}

