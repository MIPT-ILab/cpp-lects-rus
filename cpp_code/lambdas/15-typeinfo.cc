#include <iostream>
#include <functional>
#include <utility>

using namespace std;

int f(int a) { return -a; }

int main (void)
{
  int x = 0;

  // fn1 and fn2 have the same type, but their targets do not
  function<int(int)> fn1(f),
                     fn2 ([](int a) {return -a;}),
                     fn3 ([x](int a) {return x-a;});
  cout << fn1.target_type().name() << endl 
       << fn2.target_type().name() << endl
       << fn3.target_type().name() << endl;
}

