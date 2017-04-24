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

template <typename T>
class MyVector {
  T *arr_;
  size_t size_;
public:
  MyVector (size_t nelts, T value) 
    : arr_(new T[nelts]), size_(nelts) {
    for (auto n = 0; n != nelts; ++n)
      arr_[n] = value;
  }
  template <typename Iter, 
           typename = decltype(*std::declval<Iter&>(), ++std::declval<Iter&>(), void())>
  MyVector (Iter fst, Iter lst) {
    size_ = 0;
    for (auto it = fst; it != lst; ++it)
      size_ += 1;
    arr_ = new T[size_];
    int idx = 0;
    for (auto it = fst; it != lst; ++it)
      arr_[idx++] = *it;
  }
  ~MyVector () { delete [] arr_; }
public:
  int *begin() { return arr_; }
  int *end() { return arr_ + size_; }
};

int
main ()
{
  vector<int> vfst = {1, 2, 3, 4, 5, 6};
  MyVector<int> mvecdiap (vfst.begin(), vfst.end());
  MyVector<int> mvec (2, 2);
  cout << traverse (mvecdiap, [](int& n) { cout << n << endl; return true; }) << endl; 
  cout << traverse (mvec, [](int& n) { cout << n << endl; return true; }) << endl; 
}

