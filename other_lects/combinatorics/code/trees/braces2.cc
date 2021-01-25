//-----------------------------------------------------------------------------
//
// Correct braced strings generator: no guard version
//
//-----------------------------------------------------------------------------
//
// Based on TAOCP 7.2.1.6 - P
//
//-----------------------------------------------------------------------------
//
// This software is licensed under GPLv3
//
//-----------------------------------------------------------------------------

#include <cassert>
#include <iostream>
#include <string>

#ifndef ANALYZE
#define ANALYZE 0
#endif

#define dbgs                                                                   \
  if (!ANALYZE) {                                                              \
  } else                                                                       \
    std::cout

void visit_braces(int N) {
  int m = 2 * N - 2, j = m - 1;
  std::string braces(2 * N, '(');
  for (int i = 0; i < N; ++i)
    braces[2 * i + 1] = ')';

  while (j != -1) {
    // P2: visiting
    std::cout << braces << std::endl;

    // P3: simple case (p == 0)
    dbgs << "\tP3, m = " << m << std::endl;
    braces[m] = ')';
    if (braces[m - 1] == ')') {
      m -= 1;
      braces[m] = '(';
      continue;
    }

    // P4: look up j
    dbgs << "\tP4 start:" << braces << std::endl;
    j = m - 1;
    int k = 2 * N - 2;
    while (braces[j] == '(' && j >= 0) {
      braces[j] = ')';
      braces[k] = '(';
      j = j - 1;
      k = k - 2;
    }

    // P5: increment jth position
    dbgs << "\tP5 start:" << braces << std::endl;
    if (j > 0)
      braces[j] = '(';
    m = 2 * N - 2;
  }
}

void print_usage(const char *pname) {
  std::cout << "Usage: '" << pname << " N'" << std::endl;
  std::cout << "Where N > 1 is number of left braces" << std::endl;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    print_usage(argv[0]);
    exit(1);
  }

  int n = std::stol(argv[1]);
  if (n < 2) {
    print_usage(argv[0]);
    exit(1);
  }

  visit_braces(n);
}
