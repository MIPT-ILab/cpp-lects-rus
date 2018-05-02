//------------------------------------------------------------------------------
//
//  Integral domains
//
//------------------------------------------------------------------------------
//
//  Integral domain encodes integral diapasone [A, B]
//  Say Idom<unsigned, 1, 7> encodes range [1, 2, 3, 4, 5, 6, 7]
//
//------------------------------------------------------------------------------

#ifndef IDOM_GUARD_
#define IDOM_GUARD_

#include <stdexcept>
#include <string>

using std::string;
using std::to_string;

template <typename T, T start_, T fin_>
struct Idom {
  T val_;
  Idom(T val) : val_(val) {
    if (val > fin_) throw std::out_of_range(string("value too big for domain: ") + to_string(val));
    if (val < start_) throw std::out_of_range("value too small for domain");
  }
  operator T() const { return val_; }

  using type = T;
  static constexpr T start = start_;
  static constexpr T fin = fin_;
};

template <unsigned start_, unsigned fin_>
using UnsignedDomain = Idom<unsigned, start_, fin_>;

template <char start_, char fin_>
using CharDomain = Idom<char, start_, fin_>;

#endif
