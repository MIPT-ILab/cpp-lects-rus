// default memory resource example

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "testresource.hpp"

class polymorphic_allocator_delete {
  using palloc_t = std::pmr::polymorphic_allocator<std::byte>;
  palloc_t alloc_;

public:
  polymorphic_allocator_delete(palloc_t alloc) : alloc_(move(alloc)) {}
  template <typename T> void operator()(T *tPtr) {
    std::pmr::polymorphic_allocator<T> talloc(alloc_);
    talloc.destroy(tPtr);
    talloc.deallocate(tPtr, 1);
  }
};

class Bar {
  std::pmr::string data_;
  using palloc_t = std::pmr::polymorphic_allocator<std::byte>;

public:
#ifdef NOSSO  
  Bar(palloc_t alloc = {}) : data_{"data really long data string to break SSO"} {}
#else  
  Bar(palloc_t alloc = {}) : data_{"data"} {}
#endif
};

class Foo {
  using palloc_t = std::pmr::polymorphic_allocator<std::byte>;
  palloc_t alloc_;
  std::unique_ptr<Bar, polymorphic_allocator_delete> d_bar;

public:
  Foo() : d_bar(nullptr, {{std::pmr::get_default_resource()}}) {
    std::pmr::polymorphic_allocator<Bar> alloc{
        std::pmr::get_default_resource()};
    Bar *const bar = alloc.allocate(1);
    alloc.construct(bar);
    d_bar.reset(bar);
  }
};

int main() {
  static test_resource newdefault{std::pmr::new_delete_resource()};
  std::pmr::set_default_resource(&newdefault);
  std::cout << "---" << std::endl;
  std::pmr::vector<Foo> foos;
  foos.emplace_back();
  foos.emplace_back();
  std::cout << "---" << std::endl;
}
