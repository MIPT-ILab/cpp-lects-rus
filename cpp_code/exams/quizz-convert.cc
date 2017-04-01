#include <iostream>

using std::cout;
using std::endl;

void f(char) { cout << 1 << endl; }

template <class T> void g(T t)
{
  f (1);
  f (T(1));
  f (t);
} 

enum E { e };

void f (E) { cout << 2 << endl; }
void f (int) { cout << 3 << endl; }

template<typename To, typename From> To convert(From x)
{
  return x;
}


int
main (void)
{
  int t;
  double d = convert<int, double> (t);

  g(e);
}

