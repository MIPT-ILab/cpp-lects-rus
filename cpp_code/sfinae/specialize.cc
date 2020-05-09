#include <iostream>

template <typename T, typename U> struct S {
  int operator()() const { return 42; }
};

template <typename T> struct S<T, T> {
  int operator()() const { return 32; }
};

template <typename T> struct S<T, int> {
  int operator()() const { return 22; }
};

template <> struct S<int, int> {
  int operator()() const { return 2; }
};

int main() {
  S<float, long> s1;
  S<float, float> s2;
  S<float, int> s3;
  S<int, int> s4;

  std::cout << s1() << " " << s2() << " " << s3() << " " << s4() << std::endl;
}