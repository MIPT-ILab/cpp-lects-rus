#include <iostream>
#include <map>

using std::map;
using std::cout;
using std::endl;

map<int, int> cache;

template <int (*f)(int)> int 
memoize(int x) 
{
  if (cache.find(x) != cache.end()) 
    return cache[x];

  cache[x] = f(x);
  return cache[x];
}

int 
fib(int n) 
{
  if (n < 2) return n;
  return memoize<fib>(n - 1) + memoize<fib>(n - 2);
}

int
main (void)
{
  cout << fib (6) << endl;
}

