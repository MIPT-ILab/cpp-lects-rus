#include <utility>

#include "junkiter.hpp"

template <class T, class U>
concept bool DerivedFrom = std::is_base_of<U, T>::value;

template <typename I>
concept bool Iterator = requires() {
  typename I::value_type;
  typename I::difference_type;
  typename I::reference;
  typename I::pointer;
};

template <typename I>
concept bool InputIterator = Iterator<I> && 
  requires { typename I::iterator_category; } &&
  DerivedFrom<typename I::iterator_category, std::input_iterator_tag>;

template <typename I>
concept bool Incrementable = requires (I it) {
  ++it;
  it++;
};

template <typename I>
concept bool ForwardIterator = InputIterator<I> && 
  Incrementable<I> &&
  DerivedFrom<typename I::iterator_category, std::forward_iterator_tag>;

template <typename I>
concept bool Decrementable = requires (I it) {
  --it;
  it--;
};

template <typename I>
concept bool BidirectionalIterator = ForwardIterator<I> && 
  Decrementable<I> &&
  DerivedFrom<typename I::iterator_category, std::bidirectional_iterator_tag>;

template <typename I>
concept bool RandomAccess = requires (I it, typename I::difference_type n) {
  it + n;
  it - n;
};

template <typename I>
concept bool RandomAccessIterator = BidirectionalIterator<I> && 
  RandomAccess<I> &&
  DerivedFrom<typename I::iterator_category, std::random_access_iterator_tag>;

template <InputIterator Iter>
typename Iter::difference_type
my_distance(Iter first, Iter last) {
  typename Iter::difference_type n = 0;
  while (first != last) { ++first; ++n; }
  return n;
}

template <RandomAccessIterator Iter>
typename Iter::difference_type
my_distance(Iter first, Iter last) {
  return last - first;
}

int
main () {
  int arr[10];
  junk_iter_t fst(arr), snd(arr + 3);
  auto dist = my_distance(fst, snd);
}
