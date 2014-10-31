#include <cstdio>

struct A
{
  int x, y;
};


int 
main (void)
{
  struct A *pa = new A;
  pa = new A (); 
}

