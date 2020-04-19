#include "fact.h"

MYABI int
fact(int x) {
  if (x < 2)
    return x;

  return x * fact(x - 1);
}

