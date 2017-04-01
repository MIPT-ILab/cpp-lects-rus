#include <iostream>

int 
main ()
{
  int i;

  for (i = 0; i < 10; ++i)
    std::cout << i << " : " << i*1000000000 << " : " << std::endl;

  return 0;
}

