// C++98 stateless alloc
#include <list>
#include <vector>

#include "stateless.hpp"

using std::list;
using std::vector;

int main() {
  // 0. enabling allocator in C++98
  vector<int, logging_alloc<int>> v;

  // 1. basic functionality for C++11
  for (int i = 0; i < 16; ++i)
    v.push_back(i);
  printf("---\n");
  vector<int, logging_alloc<int>> v2 = v;
  v2.push_back(16);

  // 2. this line will fail to compile without operator== and operator!=
  v = v2;

  // 3. this line will not compile without coercion
  list<int, logging_alloc<int>> l(v.begin(), v.end());
}
