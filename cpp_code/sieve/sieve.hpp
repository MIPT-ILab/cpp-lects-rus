#ifndef SIEVE_GUARD_
#define SIEVE_GUARD_

#include <array>
#include <iostream>
#include <climits>

// upper bound for log2(N)
static inline constexpr size_t
static_log (size_t N) 
{
  size_t res = 1;
  while ((N >> res) > 0)
    res++;

  // see if exact_log
  if ((N & (1 << res)) != 0)
    res += 1;

  return res;
}

static inline constexpr int
iabs (int x)
{
  return (x > 0) ? x : (-x);
}

// lower bound for square root of a
static inline constexpr size_t
isqrt(size_t n)
{
  int a = 1;
  int b = n;
  
  while (iabs(a-b) > 1)
    {
      b = n / a;
      a = (a + b) / 2;
    }

  return a;
}

// size of sieve for N-th prime is N * (log(N) + log(log(N)))
// also we are using every bit and makes 2 sieves
static inline constexpr size_t
arrsz (size_t N, size_t E) {
  return (N * (static_log(N) + static_log(static_log(N)))) / (E * CHAR_BIT * 3);
}

template <size_t N, typename Elem>
using SieveType = std::array<Elem, arrsz(N, sizeof(Elem))>;

template <size_t N, typename Elem>
static inline void
mark (std::array<SieveType<N, Elem>, 2>& s, unsigned long long n) 
{
  int snum = (((n + 1) % 6) == 0) ? 0 : (((n - 1) % 6) == 0) ? 1 : -1;
  if (snum == -1) return;
  unsigned long long primenum = ((n + 1 - 2 * snum) / 6) - 1;
  size_t wordnum = primenum / (sizeof(Elem) * CHAR_BIT);
  size_t bitnum = primenum % (sizeof(Elem) * CHAR_BIT);

  if (wordnum >= arrsz(N, sizeof(Elem)))
    return;

  s[snum][wordnum] |= (1 << bitnum);
}

template <size_t N, typename Elem>
static inline void
build_sieves (std::array<SieveType<N, Elem>, 2>& s) {
  const size_t bord = N;
  for (size_t k = 1; k < bord; ++k)
    for (size_t kprime = k; kprime < bord; ++kprime)
      {
        unsigned long long n;
        n = (6 * k - 1) * (6 * kprime - 1); mark<N, Elem> (s, n); 
        n = (6 * k + 1) * (6 * kprime - 1); mark<N, Elem> (s, n);
        n = (6 * k - 1) * (6 * kprime + 1); mark<N, Elem> (s, n);
        n = (6 * k + 1) * (6 * kprime + 1); mark<N, Elem> (s, n);
      }
}

template <size_t N, typename Elem = unsigned char>
class Sieve {
  std::array<SieveType<N, Elem>, 2> sieve_{};
public:
  Sieve() 
  {
    build_sieves<N>(sieve_);
  }

  bool 
  is_prime (unsigned long long n) 
  {  
    if ((n == 2) || (n == 3)) return true;
    int snum = (((n + 1) % 6) == 0) ? 0 : (((n - 1) % 6) == 0) ? 1 : -1;
    if (snum == -1) return false;
    unsigned long long primenum = ((n + 1 - 2 * snum) / 6) - 1;
    size_t wordnum = primenum / (sizeof(Elem) * CHAR_BIT);
    size_t bitnum = primenum % (sizeof(Elem) * CHAR_BIT);
    if (wordnum >= arrsz(N, sizeof(Elem)))
      throw std::runtime_error("Requested too large number for sieve");
    return ((sieve_[snum][wordnum] & (1 << bitnum)) == 0);
  }

  unsigned long long
  nth_prime (unsigned long n) 
  {
    if (n < 3) return (n + 1);
    unsigned long long t = 1; 
    int addend = -1;
    unsigned long cnt = 2;
    for (;;) 
    {
      if (is_prime(6*t + addend)) {
        cnt += 1;
      }

      if (cnt == n)
        break;

      addend = -addend;
      if (addend == -1)
        t += 1;
    }

    return (6*t + addend);
  }
public:
  class iterator {
    Sieve *parent_;
    int n;
  public:
    iterator(Sieve *parent, int npos) : parent_(parent), n(npos) {}
    iterator& operator++ () { ++n; return *this; }
    iterator operator++ (int) { return iterator(n++); }
    iterator& operator-- () { --n; return *this; }
    iterator operator-- (int) { return iterator(n--); }
    bool operator==(iterator rhs) { return n == rhs.n; }
    bool operator!=(iterator rhs) { return n != rhs.n; }
    unsigned long long operator*() 
    { 
      return 0;
    }
  };

  iterator begin() { return iterator(this, 0); }
  iterator end() { return iterator(this, arrsz(N, sizeof(Elem)) * 2 + 1); }
};


#if 0
http://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls
http://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622
template <size_t N, typename Elem>
static inline bool operator == (typename Sieve<N, Elem>::iterator lhs, typename Sieve<N, Elem>::iterator rhs) 
{
  return (lhs.operator==(rhs));
}

template <size_t N, typename Elem>
static inline bool operator != (typename Sieve<N, Elem>::iterator lhs, typename Sieve<N, Elem>::iterator rhs) {
  return !(lhs == rhs);
}
#endif

#endif
