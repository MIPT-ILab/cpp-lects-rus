module;

#include <cassert>

export module first.part;

import <string>;

namespace hello {

export std::string foo(int n) {
  assert(n < 42 && "argument shall be less than 42");
  return "Hello, world!";
}

}

