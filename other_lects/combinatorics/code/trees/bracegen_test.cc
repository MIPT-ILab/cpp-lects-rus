//-----------------------------------------------------------------------------
//
// Correct braced strings generator: testing app
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
#include "bracegen.hpp"

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

  brace_visitor visitor(n);

  while(!visitor.last()) {
    std::cout << visitor.visit() << std::endl;
    visitor.next();
  }
}
