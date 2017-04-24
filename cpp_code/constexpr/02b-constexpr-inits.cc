#include <iostream>

using std::cout;
using std::endl;

struct S {
  static constexpr int sz;
};

constexpr int page_sz = 4 * S::sz;

constexpr int S::sz = 256; 

int arr[page_sz];

int
main (void)
{
  cout << page_sz << " " << S::sz << endl;
  return 0;
}

