#ifndef STUDENT
#define STUDENT
#include "personal.h"

class STUDENT : public Personal {
  public:
    Student();
    Student(char*, char* char*, int, long, char*);
    void writeToFile(fstream&) const;
    void readFromFile(fstream&);
    int size() const {
      return Personal::size() + majorLen;
    }

  protected:
    char *major;
    const int majorLen;
    ostream& writeLegibly(ostream&);
    friend ostream& operator<<(ostream& out, Student& sr) {
      return sr.readFromConsole(in);
    }
};

#endif // !STUDENT
