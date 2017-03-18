#include "stack.hpp"

Stack<int> 
fill_int_stack (int x, int n)
{
  int i;
  Stack<int> s;
  assert (n > 0);

  for (i = 0; i != n; ++i)
    s.push(x);

  return s;
}


