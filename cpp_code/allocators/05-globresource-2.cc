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

#if defined(EXPERIMENTAL)
using std::experimental::pmr::get_default_resource;
using std::experimental::pmr::new_delete_resource;
using std::experimental::pmr::polymorphic_allocator;
using std::experimental::pmr::set_default_resource;
template <typename T>
using vector = std::vector<T, polymorphic_allocator<T>>;
using string = std::basic_string<char, std::char_traits<char>, 
                                 polymorphic_allocator<char>>;
#else
using std::pmr::get_default_resource;
using std::pmr::new_delete_resource;
using std::pmr::polymorphic_allocator;
using std::pmr::set_default_resource;
using std::pmr::string;
using std::pmr::vector;
#endif

#include "testresource.hpp"

class polymorphic_allocator_delete {
  polymorphic_allocator<byte> alloc_;
public:
  polymorphic_allocator_delete(polymorphic_allocator<byte> alloc)
      : alloc_(move(alloc)) {}
  template <typename T> void operator()(T *ptr) {
    polymorphic_allocator<T> talloc(alloc_);    
    ptr->~T(); // TODO: talloc.destroy(tPtr); when will be supported
    talloc.deallocate(ptr, 1);
  }
};

class Bar {
  // pmr::string here
  string data {"data"};
};

class Foo {
  // emulation of pmr::unique_ptr
  unique_ptr<Bar, polymorphic_allocator_delete> bar_;
public:
  Foo() : bar_(nullptr, {{get_default_resource()}}) {
    polymorphic_allocator<Bar> alloc{get_default_resource()};
    Bar *const bar = alloc.allocate(1);
    alloc.construct(bar);
    bar_.reset(bar);
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
