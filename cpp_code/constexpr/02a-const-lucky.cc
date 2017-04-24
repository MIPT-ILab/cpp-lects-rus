#include <iostream>

using std::cout;
using std::endl;

struct S 
{
  static const int sz = 256;
};

const int page_sz = 4 * S::sz; // ok!

const int S::sz;

int arr[page_sz];

int
main (void)
{
  cout << page_sz << " " << S::sz << endl;
  return 0;
}

