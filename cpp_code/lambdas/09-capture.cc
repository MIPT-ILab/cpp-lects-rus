#include <iostream>

using std::cout;
using std::endl;

int g = 1;
int foo (int b) 
{
  int x = 2;
  static int a = 3;
  if (b == 4) 
    {  
      int y = 5;
      auto lam = [=] { return x + y + a + b + g; };
      cout << lam() << endl;

      // 3 of 5 changes are ignored
      x += 1; y += 1; a += 1; b += 1; g += 1;

      cout << lam() << endl;
    }
}

int 
main ()
{
  foo (4);
}

