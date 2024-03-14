#ifndef PATRON_H
#define PATRON_H

#include "Book.h"
#include "CheckedOutBooks.h"

class Patron
{
public:
    Patron(){};
    bool operator==(const Patron &pt) const
    {
        return strcmp(name, pt.name) == 0;
    }

private:
    char *name;
    list<CheckedOutBooks> books;
};

#endif