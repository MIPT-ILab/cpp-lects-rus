#include <set>

int 
main ()
{
  class X {};
  std::set<X> x;
  x.insert(X{});
}

