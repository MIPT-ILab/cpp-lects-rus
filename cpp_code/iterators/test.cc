#include <iostream>

#include "sieve.hpp"

static const int TESTSZ = 1000;
using TESTT = unsigned char;

int
test1 (void) 
{
  std::array<SieveType<TESTSZ, TESTT>, 2> s{};
  std::cout << arrsz(TESTSZ, sizeof(TESTT)) << std::endl;
  std::cout << isqrt(TESTSZ) << std::endl;
  build_sieves<TESTSZ, TESTT>(s);

  std::cout << std::hex << "0x" << (unsigned) s[0][0] << " 0x" << (unsigned) s[0][1] << " ..." << std::endl;
  std::cout << "0x" << (unsigned) s[1][0] << " 0x" << (unsigned) s[1][1] << " ..." << std::dec << std::endl;

  for (int i = 1; i != 20; ++i) {
    std::cout << (6*i - 1) << ": " << ((s[0][(i / 8)] & (1 << (i % 8))) != 0) << std::endl;
    std::cout << (6*i + 1) << ": " << ((s[1][(i / 8)] & (1 << (i % 8))) != 0) << std::endl;
  }
  
  return 0;
}

int 
test2 (void)
{
  Sieve<TESTSZ, TESTT> s;
  int counter = 0;

  for (int i = 2; i != 100; ++i) {
    if (!s.is_prime(i)) continue;
    counter += 1;
    std::cout << i << " ";
    if (counter == 10) {
      counter = 0;
      std::cout << std::endl;
    }    
  }
  std::cout << std::endl;

  return 0;
}

int
test3 (void)
{
  Sieve<TESTSZ, TESTT> s;
  std::cout << "#" << TESTSZ << " prime is " << s.nth_prime(TESTSZ) << std::endl;
  return 0;
}

int
main (void)
{
  Sieve<50, TESTT> s;
  for (auto x : s) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}


