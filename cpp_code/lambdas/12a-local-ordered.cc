#include <iostream>

using std::cout;
using std::endl;

auto factory (int parameter) 
{
  static int a = 0;
  auto func = [=] (int argument) {
    static int b = 0;
    a += parameter; 
    b += argument;
    return a + b;
  };
  return func;
}

int 
main ()
{
  auto func1 = factory(1);
  auto func2 = factory(2);
  cout << func1(20) << " ";
  cout << func1(30) << " ";
  cout << func2(20) << " "; 
  cout << func2(30) << endl;
}

