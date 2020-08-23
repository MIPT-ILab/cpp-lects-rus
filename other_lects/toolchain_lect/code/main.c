#include <stdio.h>

unsigned fact(unsigned);

int __attribute__((constructor))
foo() {
  printf("Before main!\n");
}

int
main ()
{
  printf("%d\n", fact(10));
}

