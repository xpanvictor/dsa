#include <iostream>
using namespace std;

// recursive for fib
unsigned long
fib (unsigned long n)
{
  static int i = 0;
  i++;
  cout << "fib_count: " << i << endl;
  if (n < 2)
    return n;
  return fib (n - 1) + fib (n - 2);
}

unsigned long
iterativeFib (long n)
{
  static int i = 0;
  if (n < 2)
    {
      return n;
    }
  else
    {
      // taking note of the counters
      long current = 1, tmp, prev = 0, k = 2;

      // just adding up from beginning
      for (; k <= n; ++k)
        {

          cout << "iter_count: " << ++i << endl;
          tmp = current; // necessary ? to swap current value for prev
          current += prev;
          prev = tmp;
        }

      return current;
    }
}

int
main ()
{
  cout << "Enter number for fibs: ";
  int n = 0;
  cin >> n;
  cout << "Testing recursive & iterative fib n = " << n << endl;
  cout << "fib(" << n << ") = " << fib (n) << endl;
  cout << "iter fib(" << n << ") = " << iterativeFib (n) << endl;
  return 0;
}
