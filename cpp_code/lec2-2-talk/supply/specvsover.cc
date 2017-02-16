#include <iostream>

using std::cout;
using std::endl;

template <typename T, typename U> void foo(T, U) { cout << 1 << endl; }
template <typename T, typename U> void foo(T*, U*) { cout << 2 << endl; }
template <> void foo<int*, int*>(int*, int*) { cout << 3 << endl; }

int
main (void)
{
	int x;
	foo (&x, &x);
}

