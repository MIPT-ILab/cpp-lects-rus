#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Hinant trick
template <typename Container, typename ConstIterator>
typename Container::iterator 
remove_constness(Container& c, ConstIterator it) {
  return c.erase(it, it);
}

int
main ()
{
  vector<int> v {1, 2, 3, 4, 5, 6, 7};
  auto crvi = v.crbegin(); 

  // 1 2 3 4 5 6 7 <

  crvi += 4;

  // 1 2 3 < 4 5 6 7 
  
  auto cvi = crvi.base();

  // 1 2 3 > 4 5 6 7 

  auto vi = remove_constness(v, cvi);
  *vi *= 2;

  cout << *crvi << " " << *vi << endl;
}

