// slist example
// clang++ --std=c++17 -Xclang -flto-visibility-public-std 05-slist.cc

#include <cstdio>

#include "slist.hpp"

size_t memory = 0;
size_t alloc = 0;

void *operator new(size_t s) noexcept(false) {
  memory += s;
  ++alloc;
  return malloc(s);
}

void operator delete(void *p) noexcept {
  --alloc;
  free(p);
}

void memuse() {
  printf("memory = %zu\n", memory);
  printf("alloc = %zu\n", alloc);
}

int main() {
  constexpr size_t sz = 1000 * sizeof(int);
  alignas(int) char buffer[sz];

  monotonic_buffer_resource res(buffer, sz);

  slist<int> s(&res);
  s.push_back(10);
  s.push_back(20);
  s.push_front(30);
  s.push_front(40);

  slist<int> s1(s, s.get_allocator());
  slist<int> s2(move(s1));

  for (auto x : s2)
    printf("%d\n", x);

  memuse();
}
