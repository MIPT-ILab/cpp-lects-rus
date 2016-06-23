#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <stdexcept>
#include <chrono>
#include <ctime>

using namespace std;

#ifndef VARIANT
#error "You need to pass -DVARIANT=[1|2|3]"
#endif

#if (VARIANT == 1)

bool 
is_prime (unsigned x) 
{
  assert (x > 1);
  unsigned r = (unsigned) ceil (sqrt (x));
  for (unsigned i = 2; i <= r; ++i)
    if ((x % i) == 0)
      return false;
  return true;  
}

#elif  (VARIANT == 2)

bool is_prime (unsigned x) {
  assert (x > 1);
  if ((x % 2) == 0) return false;
  unsigned r = (unsigned) ceil (sqrt (x));
  for (unsigned i = 3; i <= r; i += 2)
    if ((x % i) == 0)
      return false;
  return true;  
}

#elif  (VARIANT == 3)

bool is_prime (unsigned x) {
  assert (x > 1);
  if (((x % 2) == 0) || ((x % 3) == 0)) 
    return false;
  if (x < 9) 
    return true;
  unsigned r = (unsigned) ceil (sqrt (x));
  for (unsigned i = 5; i <= r; i += 6) {
    if (((x % i) == 0) || ((x % (i + 2)) == 0))
      return false;
  }
  return true;  
}

#else

#error "You need to pass -DVARIANT=[1|2|3]"

#endif

int
main (void)
{
  for (unsigned j = 19; j < 32; j += 1)
    {
      unsigned i, t = (1 << j);
      for (i = 1; i < 1000; i += 2)
        {
          if (is_prime(t - i))
            {
              // cout << "2^" << j << " - " << i << " is prime" << endl;
              auto t_start = std::chrono::high_resolution_clock::now();
              is_prime(t - i);
              auto t_end = std::chrono::high_resolution_clock::now();
              // std::cout << "CPU time used: " << std::chrono::duration<double, std::milli>(t_end-t_start).count() << endl;
              cout << j << ", " << std::chrono::duration<double, std::milli>(t_end-t_start).count() << endl;
              break;
            }
        }
    }
}

void
process_command_line (int argc, char **argv, int &k)
{
  if (argc < 2)
    {
      cerr << "usage: \"" << argv[0] << " k\" where k is position count" << endl;
      throw std::runtime_error("incorrect command line");
    }

  k = atoi (argv[1]);

  if (k <= 0)
    {
      cerr << "k shall be > 0" << endl;
      throw std::runtime_error("incorrect command line");
    }
}

