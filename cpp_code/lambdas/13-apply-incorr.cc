#include <iostream>

template <typename T>
T apply (T(*f)())
{
  return f();
}

template <typename T>
using fptr = T(*)();

int 
main ()
{
  auto l = []{return 2;};
  std::cout << apply(+l) << std::endl;
}