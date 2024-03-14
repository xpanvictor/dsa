#include "Book.h"
#include "Patron.h"
#include "Author.h"
#include <iostream>

using namespace std;

list<Author> catalog['Z' + 1];
list<Patron> people['Z' + 1];

int menu()
{
    int response;
    cout << "Welcome to the Libray. The possible options are\n"
         << "1. Read a book\n"
         << "2. Borrow a book\n"
         << "3. Get a summary"
         << "Q: Quit the program!"
         << "Enter the number: " << endl;
    cin >> response;
    return response;
}

void resp() { cout << "Option noted" << endl; }

int main()
{
    while (true)
    {
        switch (menu())
        {
        case 1:
            resp();
            break;

        case 2:
            resp();
            break;

        case 'Q':
            cout << "Thanks for using the libray" << endl;
            return 0;

        default:
            cout << "Invalid resp, try again!" << endl;
        }
    }
}
