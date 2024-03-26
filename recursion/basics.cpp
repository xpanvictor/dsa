#include <iostream>

using namespace std;

// Reversing characters
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

// Nested recursion
int
nested_sum (int n)
{
  // cout << "case: " << n << endl;
  if (n == 0 || n > 4)
    return n;
  return nested_sum (2 + nested_sum (n * 2));
}

// Ackerman & Rozsa function
int
A (int n, int m)
{
  if (n == 0)
    return m + 1;
  if (n > 0 && m == 0)
    return A (n - 1, 1);
  return A (n - 1, A (n, m - 1));
}

int
main ()
{
  cout << "Testing reverse_chars with nontail recursion; type in chars: ";
  reverse_chars ();
  cout << endl;

  cout << "Testing nested sum of h(n) = h(2 + h(n * 2)) if n <= 4 != 0"
       << endl;
  cout << nested_sum (2) << endl;

  cout
      << "Testing Ackermann and Rozsa function with A(3,1) and A(4,1) to show "
         "growth:"
      << endl;
  cout << A (3, 1) << " grows to " << A (4, 1) << endl;
}
