#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::for_each;
using std::vector;

template <typename C, typename F> void apply (C cont, F func) {
  for (auto elt : cont) 
    func (elt);
}

auto apply_alg = [] (auto cont, auto func) { 
  for_each (cont.begin(), cont.end(), func);
};

int
main ()
{
  vector<int> v {2, 3, 5, 7, 11, 13, 17};
  apply (v, [](int x){ cout << x << endl; });
  apply_alg (v, [](int x){ cout << x << endl; });
}

