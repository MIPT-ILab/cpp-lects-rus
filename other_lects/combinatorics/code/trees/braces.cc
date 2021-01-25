//-----------------------------------------------------------------------------
//
// Correct braced strings generator
//
//-----------------------------------------------------------------------------
//
//
//
//-----------------------------------------------------------------------------
//
// This software is licensed under GPLv3
//
//-----------------------------------------------------------------------------

#include <cassert>
#include <iostream>
#include <string>

#ifdef ANALYZE
std::ostream &dbgs = std::cout;
#else
struct NullBuffer : public std::streambuf {
  int overflow(int c) override { return c; }
};

NullBuffer null_buffer;
std::ostream dbgs{&null_buffer};
#endif

void visit_braces(int N) {
  int m = 2 * N - 1, j = m - 1;
  std::string braces(2 * N + 1, ')');
  for (int i = 1; i <= N; ++i)
    braces[2 * i - 1] = '(';

  while (j != 0) {
    // P2: visiting
    std::cout << braces.data() + 1 << std::endl;

    // P3: simple case (p == 0)
    dbgs << "\tP3, m = " << m << std::endl;
    braces[m] = ')';
    if (braces[m - 1] == ')') {
      m -= 1;
      braces[m] = '(';
      continue;
    }

    // P4: look up j
    dbgs << "\tP4 start:" << braces.data() + 1 << std::endl;
    j = m - 1;
    int k = 2 * N - 1;
    while (braces[j] == '(') {
      braces[j] = ')';
      braces[k] = '(';
      j = j - 1;
      k = k - 2;
    }
   
    // P5: increment jth position
    dbgs << "\tP5 start:" << braces.data() + 1 << std::endl;
    braces[j] = '(';
    m = 2 * N - 1;
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
