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
  // database.seekp(_, ios::cur);
  T tmp;
  while(!database.eof()) {
    tmp.readFromFile(database);
    if (tmp == d) {
      cin >> tmp;
      database.seekp(-d.size(), ios::cur);
      tmp.writeToFile(database);
      database.close();
      return;
    }
  }
  // logic for file not found
  database.close();
  cout << "The record to modify is not in the database!";
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

