#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename Container, typename ConstIterator>
typename Container::iterator 
remove_constness(Container& c, ConstIterator it) 
{
  return c.erase(it, it);
}

int
main ()
{
  vector<int> v = {1, 3, 5, 7, 11};
  auto ci = v.cbegin();
  ci += 3;
  auto i = remove_constness (v, ci);
  cout << *i << endl;
}

