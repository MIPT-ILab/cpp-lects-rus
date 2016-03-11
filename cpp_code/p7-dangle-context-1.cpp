#include <iostream>
#include <functional>

using namespace std; 

struct NC
{
    NC()                     = default;
    NC(NC const&)            = delete;
    NC& operator=(NC const&) = delete;
    NC(NC&&)                 = default;
};
 
#define nocopy nocopy_value_ = NC()

struct Monitor {
  ~Monitor () { cout << "destroyed" << endl; }
};

int
main ()
{
  function<void()> f;

  {
    Monitor m;
    auto k = [nocopy, &mref = m] { cout << "may use m here" << endl; };
    k (); 
    // f = k;
  } 

  // f();
}

