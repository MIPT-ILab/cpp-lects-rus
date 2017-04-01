#include <iostream>

#include "meta-fact.hpp"

int
main ()
{
  std::cout << factorial<6>::value << " == " <<  factorial2<6>::value << std::endl;
  return 0;
}

