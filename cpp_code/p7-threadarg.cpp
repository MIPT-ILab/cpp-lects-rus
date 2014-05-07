#include <thread>
#include <cstdio>

using namespace std;

void 
my_thread_func (const char *msg)
{
  printf ("%s\n", msg);
}

void 
increment(int& i)
{
  ++i;
}

int 
main (void)
{
  int x = 42;

  std::thread t1 (my_thread_func, "Hello, world!");
  t1.join ();

  std::thread t2 (increment, std::ref (x));
  t2.join ();

  printf ("x value is %d\n", x);

  return 0;
}

