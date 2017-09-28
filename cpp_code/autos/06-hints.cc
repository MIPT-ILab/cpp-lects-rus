#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::iterator_traits;
using std::vector;

template<class T> 
struct container {
  template<class Iter> container(Iter beg, Iter end) { cout << "Ctored from Iter" << endl; }
};

#ifdef USERHINT
template<class Iter> container(Iter b, Iter e) -> container<typename iterator_traits<Iter>::value_type>;
#endif

int
main ()
{
  vector<double> v;
  auto d = container(v.begin(), v.end());
}

