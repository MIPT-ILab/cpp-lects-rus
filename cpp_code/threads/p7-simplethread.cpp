#include <thread>
#include <cstdio>

using namespace std;

void 
my_thread_func (void)
{
  printf ("%s", "Hello, world\n");
}

int 
main (void)
{
  std::thread t(my_thread_func);
  t.join();
  return 0;
}
