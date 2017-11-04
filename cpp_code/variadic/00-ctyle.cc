#include <cstdarg>
#include <iostream>

using std::cout;
using std::endl;

int sum_all(int nargs, ...) {
  va_list ap;
  int cnt = 0;
  va_start(ap, nargs);

  for (int i = 0; i < nargs; ++i)
    cnt += va_arg(ap, int);

  va_end(ap);
  return cnt;
}

#define NUMARGS(...) (sizeof((int[]){__VA_ARGS__})/sizeof(int)) 
#define DOSUM(...) sum_all(NUMARGS(__VA_ARGS__), __VA_ARGS__)

int
main ()
{
  cout << DOSUM(1, 5, 9);
}

