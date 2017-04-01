#include <mutex>
#include <cstdio>

std::mutex m;
unsigned counter = 0;

unsigned increment (void)
{
  std::lock_guard<std::mutex> lk(m);
  return ++counter;
}

unsigned query (void)
{
  std::lock_guard<std::mutex> lk(m);
  return counter;
}

int
main (void)
{
  increment ();
  printf ("querying: %d\n", query ());
  return 0;
}

