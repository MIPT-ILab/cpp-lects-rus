// default memory resource example

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

#include "testresource.hpp"

class Bar {
  pmr::string data {"data"};
};

class Foo {
  unique_ptr<Bar> d_bar{make_unique<Bar>()};
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