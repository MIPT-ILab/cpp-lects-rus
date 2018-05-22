// slist example
// C:\Users\kvladimi\Downloads\MinGW\bin\g++ -Wfatal-errors --std=c++17  05-slist.cc -I "C:\Users\kvladimi\Downloads\MinGW\include" -L "C:\Users\kvladimi\Downloads\MinGW\lib" -lboost_container

#include <iostream>

#include "slist.hpp"

#include "boost/container/pmr/memory_resource.hpp"
#include "boost/container/pmr/monotonic_buffer_resource.hpp"
#include "boost/container/pmr/polymorphic_allocator.hpp"

using boost::container::pmr::monotonic_buffer_resource;
using boost::container::pmr::polymorphic_allocator;

using std::cout;
using std::endl;

size_t memory = 0;
size_t alloc = 0;

void* operator new(size_t s) noexcept(false)
{
    memory += s;
    ++alloc;
    return malloc(s);
}

void  operator delete(void* p) noexcept
{
    --alloc;
    free(p);
}

void memuse()
{
    std::cout << "memory = " << memory << '\n';
    std::cout << "alloc = " << alloc << '\n';
}

int
main ()
{
  constexpr size_t sz = 1000 * sizeof(int);
  char buffer[sz] alignas(int);

  monotonic_buffer_resource res(buffer, sz);

  slist<int> s(&res);
  s.push_back(10);
  s.push_back(20);
  s.push_front(30);
  s.push_front(40);

  for (auto x : s)
    cout << x << endl;

  memuse();
}
