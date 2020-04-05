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
  polymorphic_allocator_delete(palloc_t alloc) : alloc_(std::move(alloc)) {}
  template <typename T> void operator()(T *ptr) {
    std::pmr::polymorphic_allocator<T> talloc(alloc_);
    talloc.destroy(ptr);
    talloc.deallocate(ptr, 1);
  }
};

class Bar {
#ifdef NOSSO  
  std::pmr::string data{"data really long data string to break SSO"};
#else  
  std::pmr::string data{"data"};
#endif
};

class Foo {
  std::unique_ptr<Bar, polymorphic_allocator_delete> bar_;

public:
  Foo() : bar_(nullptr, {{std::pmr::get_default_resource()}}) {
    std::pmr::polymorphic_allocator<Bar> alloc{
        std::pmr::get_default_resource()};
    Bar *const bar = alloc.allocate(1);
    alloc.construct(bar);
    bar_.reset(bar);
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
