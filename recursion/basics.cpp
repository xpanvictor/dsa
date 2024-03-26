#include <iostream>

using namespace std;

void
reverse_chars ()
{
  char ch;
  cin.get (ch);

  if (ch != '\n')
    {
      reverse_chars ();
      cout.put (ch);
    }
}

int
main ()
{
  cout << "Testing reverse_chars with nontail recursion; type in chars: ";
  reverse_chars ();
}
