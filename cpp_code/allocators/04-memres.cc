#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory_resource>

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
  constexpr size_t sz = 1000 * sizeof(double);
  alignas(double) char buffer[sz];
  std::pmr::monotonic_buffer_resource alloc(buffer, sz);
  double start = 0.0;
  std::pmr::vector<double> v1(&alloc);
  std::generate_n(std::back_inserter(v1), 10,
                  [start]() mutable { return (start += 1.1); });
  for (auto x : v1)
    std::cout << x << std::endl;
  
  memuse();
}
