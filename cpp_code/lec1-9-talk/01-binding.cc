#include <iostream>

using namespace std;

// int& lref (int x) { return x; }
// const int& clref (int x) { return x + 0; }
// int&& rref (int x) { return x + 0; }
// int&& rvref (int &&x) { return x + 0; }
int& lvref (int &x) { return x; }

class Empty {};

int fovr (int &x) { cout << "ovr1" << endl; return x; }
int fovr (const int &x) { cout << "ovr2" << endl; return x; }
int fovr (int &&x) { cout << "ovr3" << endl; return x; }

int 
main (void) 
{
  int x = 1;
  int &a = x;
  int const &b = x;
  int const &c = x + 1;
  x = a + b + c;
  cout << a << " " <<  b << " " << c << endl;
  cout << &a << " " << &b << " " << &c << endl;

  int &&e = x + 0;
  int &&d = x + 1;
  d += 1;
  cout << d << " " << e << endl;

  int &g = lvref(x);
  cout << g << endl;

  Empty h;
  Empty &&i = std::move(h);
  
  cout << &h << " " << &i << endl;

  int &&j = std::move(x);
  j += 1;
  cout << j << " " << x << endl;

  const int k = 1;
  constexpr int kc = 1;

  fovr (1);
  fovr (x);
  fovr (k);
  fovr (kc);
  fovr (fovr (x));
}

