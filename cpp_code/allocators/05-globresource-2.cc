// default memory resource example

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>

using std::byte;
using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

#include "testresource.hpp"

class polymorphic_allocator_delete {
public:
  polymorphic_allocator_delete(
      pmr::polymorphic_allocator<byte> allocator)
      : d_allocator(move(allocator)) {}
  template <typename T> void operator()(T *tPtr) {
    pmr::polymorphic_allocator<T>(d_allocator).destroy(tPtr);
    pmr::polymorphic_allocator<T>(d_allocator).deallocate(tPtr, 1);
  }

private:
  pmr::polymorphic_allocator<byte> d_allocator;
};

class Bar {
  pmr::string data {"data"};
};

class Foo {
  unique_ptr<Bar, polymorphic_allocator_delete> d_bar;
public:
  Foo() : d_bar(nullptr, {{pmr::get_default_resource()}}) {
    pmr::polymorphic_allocator<Bar> alloc{pmr::get_default_resource()};
    Bar *const bar = alloc.allocate(1);
    alloc.construct(bar);
    d_bar.reset(bar);
  }
};

int
main ()
{
  static test_resource newdefault{pmr::new_delete_resource()};
  pmr::set_default_resource(&newdefault);
  cout << "---" << endl;
  pmr::vector<Foo> foos;
  foos.emplace_back();
  foos.emplace_back();
  cout << "---" << endl;
}