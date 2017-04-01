#include <iostream>

using namespace std;

constexpr int 
ipow (int x, int n) 
{ 
  int r = x;
  while (--n > 0) r *= x;
  return r;
}

constexpr int t = ipow (5, 2);

int
main (void)
{
  cout << t << endl;
  return 0;
}

