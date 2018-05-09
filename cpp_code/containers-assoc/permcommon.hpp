//------------------------------------------------------------------------------
//
//  Common includes and defines for permutations
//
//------------------------------------------------------------------------------
//
// Permutation support extensively uses standard library. Most common uses
// collected here
//
//------------------------------------------------------------------------------

#ifndef PERMCOMMON_GUARD_
#define PERMCOMMON_GUARD_

#include <cassert>
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::equal;
using std::find;
using std::forward;
using std::initializer_list;
using std::iota;
using std::logic_error;
using std::make_pair;
using std::make_reverse_iterator;
using std::map;
using std::min_element;
using std::mismatch;
using std::move;
using std::next;
using std::ostream;
using std::ostream_iterator;
using std::pair;
using std::prev;
using std::rbegin;
using std::rend;
using std::reverse;
using std::rotate;
using std::runtime_error;
using std::set;
using std::sort;
using std::string;
using std::stringstream;
using std::transform;
using std::unordered_map;
using std::unordered_set;
using std::vector;

template <typename T> struct reversion_wrapper { T &iterable; };

template <typename T> auto begin(reversion_wrapper<T> w) {
  return rbegin(w.iterable);
}

template <typename T> auto end(reversion_wrapper<T> w) {
  return rend(w.iterable);
}

template <typename T> reversion_wrapper<T> reverse(T &&iterable) {
  return {iterable};
}

#endif