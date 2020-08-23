#include <stdio.h>

struct st {
  int a;
  int b;
};

struct st foo = {1,2};
struct st bar = {3,4};

int main() {
  struct st *p = &foo;
  foo.a++;
  printf("p->a is %d\n", p->a);
  p = &bar;
  printf("p->b is %d\n", p->b);
  return 0;
}

