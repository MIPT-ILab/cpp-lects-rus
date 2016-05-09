#include <cstdio>

// 1st req form

template <typename T, typename U>
requires requires(T t, U u) { t == u; }
bool check (T&& lhs, U&& rhs);

struct noeq {
  noeq (int x) {}
};

int main (void) {
  check (1, 1);
  check (1, 1.0);
  check (1, noeq(1));
  return 0;
}
