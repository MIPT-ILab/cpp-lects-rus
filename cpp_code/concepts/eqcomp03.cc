#include <cstdio>

// 1st req form

template <typename T, typename U>
requires requires(T t, U u) { t == u; }
bool check (T&& lhs, U&& rhs) 
{
  std::printf("first\n");
  return (lhs == rhs);
}

// 2nd req form

template <typename T, typename U>
concept bool Equality_comparable() {
  return requires(T t, U u) {
    {t == u} -> bool;
  };
}

template <typename T, typename U>
requires Equality_comparable<T, U>()
bool check (T&& lhs, U&& rhs)
{
  std::printf("second\n");
  return (lhs == rhs);
}

struct eqcomp {
  eqcomp (int x) {}
  bool operator == (int x) { return true; }
};


int main (void) {
  check (1, 1.0);
  check (eqcomp(1), 1);
  return 0;
}
