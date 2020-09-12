#include <thread>
#include <iostream>

int x = 0;

void  
foo ()
{
  std::thread([&] {
    ++x;
  }).detach();
  ++x;
}

int
main ()
{
  foo ();
  std::cout << x << std::endl;
  return 0;
}
