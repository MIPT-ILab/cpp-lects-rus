#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <tuple>

using std::cout;
using std::endl;

template <unsigned int S> 
class Buffer 
{
  unsigned char bytes[S];
public:
  Buffer (std::initializer_list<unsigned char> li) { std::copy(li.begin(), li.end(), bytes); }

  unsigned char& operator[] (int n) { 
    assert ((n < S) && (n >= 0) && "Buffer::operator[] index out of range");
    return bytes[n]; 
  }
};

template <typename T, unsigned int S> 
class Array 
{
  T content[S];
public:
  Array (Buffer<S> b) {
    for (int i = 0; i != S; ++i)
      content[i] = b[i];
  }

  T& operator[] (int n) {
    assert ((n < S) && (n >= 0) && "Array<T>::operator[] index out of range");
    return content[n];
  }

  const T& operator[] (int n) const {
    assert ((n < S) && (n >= 0) && "Array<T>::operator[] index out of range");
    return content[n];
  }
};

template<typename Array, std::size_t... I>
decltype(auto) a2t_impl(const Array& a, std::index_sequence<I...>)
{
  return std::make_tuple(a[I]...);
}

template<typename T, unsigned int N, typename Indices = std::make_index_sequence<N>>
decltype(auto) a2t(const Array<T, N>& a)
{
  return a2t_impl(a, Indices());
}
 
template <typename T> 
class Array<T, 3> 
{
  T fst, snd, thrd;
public:
  explicit Array (int fst = 0, int snd = 0, int thrd = 0) : fst(fst), snd(snd), thrd(thrd) {}

  T& operator[] (int n) {
    if (n == 0) return fst;
    if (n == 1) return snd;
    if (n == 2) return thrd;
    assert (0 && "illegal Array<T, 3>::operator[] argument");
  }
};

int
main (void)
{
  Buffer<5> b({0, 1, 2, 3, 4});
  Array<int, 5> a (b);
  auto t = a2t (a);
  Array<int, 3> a3 (std::get<0>(t), std::get<2>(t), std::get<4>(t));
  cout << a3[1] << endl;
}


