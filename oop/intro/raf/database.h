#ifndef DATABASE
#define DATABASE

#include <fstream>
using namespace std;

template<class T>
class Database {
  public:
    Database();
    void run();

  private:
    fstream database;
    char fName[20];
    ostream& print(ostream&);
    void add(T&);
    bool find(T&);
    void modify(T&);
    friend ostream& operator<<(ostream& out, Database& db) {
      return db.print(out);
    }
};

#endif // !DATABASE

