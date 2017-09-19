#include "max.hpp"

int 
foo (int x, int y)
{
  return max<int> (x, y + 1);
}

