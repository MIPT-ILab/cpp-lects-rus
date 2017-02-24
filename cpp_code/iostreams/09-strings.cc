#include <string>
#include <iostream>
#include <sstream>

int
main ()
{
  std::ostringstream fst;
  int n;
  float f;

  fst << 42.2442;
  std::string s1 = fst.str();
  std::istringstream iss(s1);
  iss >> n >> f;
  std::string s2("value: ");
  std::ostringstream snd (s2, std::ios::out|std::ios::ate);
  snd << std::hex << n << " " << f;
  std::cout << snd.str() << std::endl;
}

