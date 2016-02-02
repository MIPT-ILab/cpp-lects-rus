#include "max.hpp"

/* block instantiation here */
extern template int max<int> (int, int);

int 
bar (int x, int y)
{
  return max (x + 1, y);
}

