#include <iostream>

using std::cout;
using std::endl;

template <typename T> 
void bar() 
{
  cout << "General" << endl;
}

template <> 
void bar<int>() 
{
  cout << "For int" << endl;
}

template <typename T> 
void foo (T x)
{
  cout << "Common" << endl;
}

template <> void 
foo (int *x)
{
  cout << "Specialized" << endl;
}

template <typename T> 
void foo (T *x)
{
  cout << "Overloaded" << endl;
}

template <typename T, typename U> 
void buz(T, U) 
{
  cout << "General" << endl;
} 

template <typename T, typename U> 
void buz(T*, U*)
{
  cout << "Overloaded" << endl;
}

template <> 
void buz<int*, int*>(int*, int*)
{
  cout << "Special" << endl;
}

int
main ()
{
  bar <int>();

  int x;  
  foo(&x);

  buz (&x, &x);
}

