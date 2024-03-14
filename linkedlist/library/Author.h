// Author class def

// TODO: consider an entity class

#ifndef AUTHOR_H
#define AUTHOR_H

#include <string.h>
#include <list>
#include "Book.h"

using namespace std;

class Author
{
public:
    Author();
    bool operator==(const Author &ar) const
    {
        return strcmp(ar.name, name) == 0;
    }

private:
    char *name;
    list<Book> books;
};

#endif // !AUTHOR_H