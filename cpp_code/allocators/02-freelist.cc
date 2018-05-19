#include <list>
#include <vector>

#include "stateless.hpp"
#include "freelist.hpp"

using std::list;
using std::vector;

int
main ()
{
  vector<int, freelist_alloc<int>> v;
  for (int i = 0; i < 16; ++i)
    v.push_back(i);
  printf("---\n");
  list<int, freelist_alloc<int>> l(v.begin(), v.end());
  printf("---\n");
  l.remove(2);  
  l.remove(6);
  l.insert(l.begin(), -1);
  l.insert(l.begin(), -3);
  l.insert(l.begin(), -5);
  printf("---\n");
}
