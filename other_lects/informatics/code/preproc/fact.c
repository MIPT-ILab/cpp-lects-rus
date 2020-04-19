#include "fact.h"

int fact(int x) {
  if (x < 3)
    return x;

  return fact(x - 1) * x;
}
