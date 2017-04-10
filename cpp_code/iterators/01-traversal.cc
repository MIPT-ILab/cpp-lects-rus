#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

template <typename F> 
size_t
traverse_vec (vector<int> &v, F func) {
  size_t nelts = v.size();
  for (size_t i = 0; i != nelts; ++i)
    if (!func(v[i]))
      return i;
  return nelts;
}

template <typename C, typename F> 
size_t
traverse_simple (C &cont, F func) {
  size_t nelts = 0;
  for (auto it = cont.begin(); it != cont.end(); ++it, ++nelts)
    if (!func(*it))
      break;
  return nelts;
}

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
  list<int> lfst = {1, 2, 3, 4, 5, 6};
  MyArray<6> marr = {1, 2, 3, 4, 5, 6};
  cout << traverse (vfst, [](int& n) { cout << n << endl; return true; }) << endl;
  cout << traverse (lfst, [](int& n) { cout << n << endl; return true; }) << endl;
  cout << traverse (marr, [](int& n) { cout << n << endl; return true; }) << endl;
} 

