#include <utility>
#include <functional>
#include <iostream>

using namespace std;

struct Default 
{
    int foo() const {return 1;}
};
 
struct NonDefault 
{
    NonDefault(const NonDefault&) {}
    int foo() const {return 1;}
};

auto main () -> int
{
  decltype (Default().foo()) n1 = 1; // int n1
  // decltype(NonDefault().foo()) n2 = n1; // will not compile
  decltype (declval<NonDefault>().foo()) n2 = n1; // int n2
  decltype((*(NonDefault*)nullptr).foo()) n3 = n1; // int n2
  return 0;
}

