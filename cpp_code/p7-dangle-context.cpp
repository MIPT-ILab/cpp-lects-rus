#include <iostream>
#include <functional>

using namespace std; 

struct Monitor {
  ~Monitor () { cout << "destroyed" << endl; }
};

int
main ()
{
  function<void()> f;

  {
    Monitor m;
    auto k = [&mref = m] { cout << "may use m here" << endl; }; 
    f = k;
  } 

  f();
}

