#include <utility>
#include <iostream>
#include <memory>

using namespace std;

int
main (void)
{
  auto_ptr <int> told (new int(2));
  auto_ptr <int> sold (new int(3));

  told = sold;

  unique_ptr <int> t (new int(2));
  unique_ptr <int> s (new int(3));

  // t = s; -- cerr
  t = std::move (s);

  return 0;
}

