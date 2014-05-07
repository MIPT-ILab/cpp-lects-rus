#include <cstdio>

using namespace std;

struct S 
{
  static const int sz;
};

const int page_sz = 4 * S::sz;

const int S::sz = 256; /* too late */

int
main (void)
{
  printf ("%d, %d\n", page_sz, S::sz);
  return 0;
}

