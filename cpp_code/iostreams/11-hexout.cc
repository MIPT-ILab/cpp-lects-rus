#include <iostream>

int 
main ()
{
  std::ostream hexout(std::cout.rdbuf());
  hexout.setf (std::ios::hex, std::ios::basefield);
  hexout.setf (std::ios::showbase);

  std::cout << 42 << " ";
  hexout << 42 << std::endl;
}

