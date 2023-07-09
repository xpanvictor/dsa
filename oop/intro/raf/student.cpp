
#include "student.h"

Student::Student() : majorLen(10) {
  Personal();
  major = new char[majorLen + 1];
}
