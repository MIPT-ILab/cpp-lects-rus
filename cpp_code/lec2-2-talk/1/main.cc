#include "stack.hpp"

int
main (void)
{
  Stack<int> x = fill_int_stack (10, 10);
  assert (x.top () == 10);
  empty_int_stack (std::move (x));
  assert (x.empty ());
  return 0;
}

