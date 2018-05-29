// default memory resource example

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <random>

#include "testresource.hpp"

using std::cout;
using std::endl;
using std::make_unique;
using std::string;
using std::unique_ptr;

class Bar {
  string data{"data"};
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