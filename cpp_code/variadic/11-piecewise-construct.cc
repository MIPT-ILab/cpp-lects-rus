#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::forward_as_tuple;

int
main ()
{
  pair <vector<int>, vector<int>> p (std::piecewise_construct,
                                     forward_as_tuple(), 
                                     forward_as_tuple(2, 3));

  cout << "(" << p.first.size() << ", " << p.second.size() << ")" << endl;
}

