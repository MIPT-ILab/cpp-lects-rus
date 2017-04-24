#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename C, typename F> 
size_t
traverse (C &cont, F func) {
  size_t nelts = 0;
  for (auto elt : cont)
    if (!(++nelts, func(elt)))
      break;
  return nelts;
}

template <int S>
class MyArray {
  int arr[S];
public:
  template <typename Iter>
  MyArray (Iter fst, Iter lst) {
    int idx = 0;
    for (auto it = fst; it != lst; ++it)
      {
        assert (idx < S);
        arr[idx++] = *it;
      }
  }
  template <typename ... Ts>
  MyArray (Ts ... ints) : arr {ints ...} {}    
public:
  int *begin() { return arr; }
  int *end() { return arr + S; }
};

int
main ()
{
  vector<int> vfst = {1, 2, 3, 4, 5, 6};
  MyArray<6> marr (vfst.begin(), vfst.end());
  cout << traverse (marr, [](int& n) { cout << n << endl; return true; }) << endl; 
}

