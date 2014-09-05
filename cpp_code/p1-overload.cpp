#include <cstdio>

int foo (char x) { return 0;}  /* step 1 */
int foo (short x) { return 1;} /* step 1 */
int foo (int x) { return 2;}   /* step 0 */
int foo (...) { return 3;}     /* step 3 */
int foo (int &x) { return 4;}  /* step 4 */

int
main (void)
{
  std::printf ("result: %d\n", foo (10));
  return 0;
}

