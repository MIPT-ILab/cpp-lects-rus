#include <iostream>
#include <utility>

auto wrap_state = [](auto x) {
  return [=](auto access) { return access(x); };
};

template <class STATE, class Func>
auto operator > (STATE s, Func f) {
  return s(f);
}

template <class STATE, class Func>
auto operator >= (STATE s, Func f) {
#if EAGER
  return wrap_state(s(f));
#else
  return s([f](auto sprime) {
    return wrap_state(f(sprime));
  });
#endif
}

int foo() {
  return 5;
}

int bar() {
  return 6;
}

int buz(int x, int y) {
  std::cout << "buz: " << x << " " << y << std::endl;
  return x + y;
}

int main() {
  auto nfoo = [](auto xz) { return std::make_pair(foo(), xz.second); };
  auto nbar = [](auto xz) { return std::make_pair(xz.first, bar()); };
  auto nbuz = [](auto xz) { return buz(xz.first, xz.second); };
  wrap_state(std::make_pair(0, 0)) >= nfoo >= nbar > nbuz;
}

