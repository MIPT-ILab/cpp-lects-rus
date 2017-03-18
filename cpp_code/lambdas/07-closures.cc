#include <cassert>

int main ()
{
  auto identityf = [](auto x) 
  {
    struct Closure { 
      decltype(x) x_;
      decltype(x) operator() () { return x_; }
    };
    return Closure {x};
  };

  auto t = identityf(42);
  assert (t() == 42);
}

