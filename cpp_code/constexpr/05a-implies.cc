#include <iostream>

using std::cout;
using std::endl;

void foo (int const *) { cout << 1 << endl; }
void foo (int * const) { cout << 2 << endl; }

constexpr int arr[] = {2, 3, 5, 7, 11};
constexpr const int *x = &arr[3];

int 
main ()
{
  foo(x);
}

