//-----------------------------------------------------------------------------
//
// Correct braced strings generator
//
//-----------------------------------------------------------------------------
//
//
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

#ifdef ANALYZE
std::ostream &dbgs = std::cout;
#else
struct NullBuffer : public std::streambuf {
  int overflow(int c) override { return c; }
};

NullBuffer null_buffer;
std::ostream dbgs{&null_buffer};
#endif

struct brace_visitor {
  brace_visitor(int N) : N_(N), m_(2 * N - 2), j_(m_ - 1), braces_(2 * N, '(') {
    for (int i = 0; i < N; ++i)
      braces_[2 * i + 1] = ')';
  }

  bool last() const { return j_ == -1; }

  const std::string_view visit() { return braces_; }

  void next() {
    if (j_ == -1) restart();

    // P3: simple case (p == 0)
    dbgs << "\tP3, m = " << m_ << std::endl;
    braces_[m_] = ')';
    if (braces_[m_ - 1] == ')') {
      m_ -= 1;
      braces_[m_] = '(';
      return;
    }

    // P4: look up j
    dbgs << "\tP4 start:" << braces_ << std::endl;
    j_ = m_ - 1;
    int k = 2 * N_ - 2;
    while (braces_[j_] == '(' && j_ >= 0) {
      braces_[j_] = ')';
      braces_[k] = '(';
      j_ = j_ - 1;
      k = k - 2;
    }

    // P5: increment jth position
    dbgs << "\tP5 start:" << braces_ << std::endl;
    if (j_ > 0)
      braces_[j_] = '(';
    m_ = 2 * N_ - 2;
  }

  void restart() { *this = brace_visitor(N_); }

private:
  int N_;
  int m_, j_;
  std::string braces_;
};

