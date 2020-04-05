// default memory resource example

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "testresource.hpp"

class Bar {
#ifdef NOSSO  
  std::pmr::string data{"data really long data string to break SSO"};
#else  
  std::pmr::string data{"data"};
#endif
};

class Foo {
  std::unique_ptr<Bar> bar_{std::make_unique<Bar>()};
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