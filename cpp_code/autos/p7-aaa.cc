#ifdef V6
#include <string>
using namespace std::literals;
#endif

template <typename T> class TD;

class Empty {};

void foo() {
  auto v1 = 1;
  auto v2 = 1u;
  auto v3 = int(42);
  auto v4 = Empty{};

#ifdef LL
  auto v5 = long long(42);
#endif

  auto v6 = "string"s;
}

