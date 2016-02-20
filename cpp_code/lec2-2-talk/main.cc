#include "stack.hpp"

int
main (void)
{
  Stack<float> f;
  f.push (1.0f);
  f.push (2.0f);
  Stack<int> x = fill_int_stack (10, 10);
  assert (x.top () == 10);
  Stack<float> f1 = f;
  Stack<double> d = coerce_stack(f1);
  assert (!d.empty());
  assert (!x.empty ());
  return 0;
}

