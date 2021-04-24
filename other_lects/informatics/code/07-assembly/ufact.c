// #include "fact.h"

unsigned
fact(unsigned x) {
  if (x < 2)
    return x;

  return x * fact(x - 1);
}

