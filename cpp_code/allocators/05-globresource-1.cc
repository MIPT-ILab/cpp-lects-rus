// default memory resource example

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "testresource.hpp"

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

#if defined(EXPERIMENTAL)
using std::experimental::pmr::new_delete_resource;
using std::experimental::pmr::set_default_resource;
template <typename T>
using vector = std::vector<T, polymorphic_allocator<T>>;
using string = std::basic_string<char, std::char_traits<char>, 
                                 polymorphic_allocator<char>>;
#else
using std::pmr::new_delete_resource;
using std::pmr::set_default_resource;
using std::pmr::string;
using std::pmr::vector;
#endif

class Bar {
  // now it is pmr::string
  string data {"data"};
};

class Foo {
  unique_ptr<Bar> bar_{make_unique<Bar>()};
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