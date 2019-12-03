// g++ state_class.cc --std=c++17
#include <iostream>
#include <utility>

template <typename S>
struct wrap_state {
  S&& x_;
  wrap_state(S&& x) : x_(std::move(x)) {}
  
  template <typename F>
  wrap_state then(F f) && { return wrap_state{f(x_)}; }

  template <typename F>
  auto finally(F f) && { return f(x_); }
};

template <typename S> wrap_state(S&&) -> wrap_state<S>;

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
  wrap_state(std::make_pair(0, 0)).then(nfoo).then(nbar).finally(nbuz);
}

