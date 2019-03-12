// default memory resource example

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "testresource.hpp"

using std::byte;
using std::cout;
using std::endl;
using std::make_unique;
using std::move;
using std::unique_ptr;
using std::pmr::get_default_resource;
using std::pmr::new_delete_resource;
using std::pmr::polymorphic_allocator;
using std::pmr::set_default_resource;
using std::pmr::string;
using std::pmr::vector;

#include "testresource.hpp"

class polymorphic_allocator_delete {
  polymorphic_allocator<byte> alloc_;
public:
  polymorphic_allocator_delete(polymorphic_allocator<byte> alloc)
      : alloc_(move(alloc)) {}
  template <typename T> void operator()(T *tPtr) {
    polymorphic_allocator<T> talloc(alloc_);    
    tPtr->~T(); // TODO: talloc.destroy(tPtr); when will be supported
    talloc.deallocate(tPtr, 1);
  }
};

class Bar {
  string data_;
public:
  Bar(polymorphic_allocator<byte> alloc = {}): data_{"data", alloc} {}
};

class Foo {
  polymorphic_allocator<byte> alloc_;
  unique_ptr<Bar, polymorphic_allocator_delete> d_bar;
public:
  Foo() : d_bar(nullptr, {{get_default_resource()}}) {
    polymorphic_allocator<Bar> alloc{get_default_resource()};
    Bar *const bar = alloc.allocate(1);
    alloc.construct(bar);
    d_bar.reset(bar);
  }
};

int
main ()
{
  static test_resource newdefault{new_delete_resource()};
  set_default_resource(&newdefault);
  cout << "---" << endl;
  vector<Foo> foos;
  foos.emplace_back();
  foos.emplace_back();
  cout << "---" << endl;
}
