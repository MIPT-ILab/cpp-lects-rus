#include <iostream>

using std::cout;
using std::endl;

struct S {
  static constexpr int sz = 256;
};

constexpr int page_sz = 4 * S::sz;

constexpr int S::sz; 

int arr[page_sz];

int
main (void)
{
  cout << page_sz << " " << S::sz << endl;
  return 0;
}

