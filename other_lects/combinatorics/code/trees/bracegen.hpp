//-----------------------------------------------------------------------------
//
// Correct braced strings generator: reusable header
//
//-----------------------------------------------------------------------------
//
// Based on TAOCP 7.2.1.6 - P
//
//-----------------------------------------------------------------------------
//
// This software is licensed under GPLv3
//
//-----------------------------------------------------------------------------

#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

#ifndef ANALYZE
#define ANALYZE 0
#endif

#define dbgs                                                                   \
  if (!ANALYZE) {                                                              \
  } else                                                                       \
    std::cout

struct brace_visitor {
  brace_visitor(int N)
      : N_(N), leftmost_closing_(2 * N - 2),
        active_tail_(leftmost_closing_ - 1), braces_(2 * N, '(') {
    for (int i = 0; i < N; ++i)
      braces_[2 * i + 1] = ')';
  }

  bool last() const { return active_tail_ == -1; }

  const std::string_view visit() { return braces_; }

  void next() {
    if (active_tail_ == -1)
      restart();

    // P3: simple case (p == 0)
    dbgs << "\tP3, m = " << leftmost_closing_ << std::endl;
    braces_[leftmost_closing_] = ')';
    if (braces_[leftmost_closing_ - 1] == ')') {
      leftmost_closing_ -= 1;
      braces_[leftmost_closing_] = '(';
      return;
    }

    // P4: look up new active tail
    dbgs << "\tP4 start:" << braces_ << std::endl;
    active_tail_ = leftmost_closing_ - 1;
    int k = 2 * N_ - 2;
    while (braces_[active_tail_] == '(' && active_tail_ >= 0) {
      braces_[active_tail_] = ')';
      braces_[k] = '(';
      active_tail_ = active_tail_ - 1;
      k = k - 2;
    }

    // P5: increment active tail position
    dbgs << "\tP5 start:" << braces_ << std::endl;
    if (active_tail_ > 0)
      braces_[active_tail_] = '(';
    leftmost_closing_ = 2 * N_ - 2;
  }

  void restart() { *this = brace_visitor(N_); }

private:
  int N_;
  int leftmost_closing_, active_tail_;
  std::string braces_;
};
