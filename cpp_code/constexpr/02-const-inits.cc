#include <iostream>

using std::cout;
using std::endl;

struct S {
  static const int sz;
};

const int page_sz = 4 * S::sz;

const int S::sz = 256; /* too late */

int arr[page_sz];

int
main (void)
{
  cout << page_sz << " " << S::sz << endl;
  return 0;
}

