#include <iostream>

using std::cout;
using std::endl;

constexpr auto getFactorializer = []{
  unsigned int optimization[6] = {};
  auto for_each = [](auto *b, auto *e, auto pred){
    auto *it = b;
    while (it != e) pred(it++ - b);
  };

  for_each(optimization,optimization+6,[&](int n){
    if (!n) optimization[n]=1;
    else optimization[n] = n * optimization[n-1];
  });

  auto FacImpl = [=](auto fac, unsigned n){
    if (n<=5) return optimization[n];
    return n * fac(fac, n-1);
  };

  auto Fact = [=](int n){
    return FacImpl(FacImpl, n);
  };

  return Fact;
};

constexpr auto Factorial = getFactorializer();
static_assert(Factorial(5) == 120, "");
static_assert(Factorial(10) == 3628800, "");

int main () {
  cout << Factorial(10) << endl;
}
