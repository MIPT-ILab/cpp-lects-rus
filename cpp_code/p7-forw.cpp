#include <utility>
#include <cstdio>

using namespace std;

void __attribute__ ((noinline)) g(int &&t) { fprintf (stderr, "(1)\n"); }

void __attribute__ ((noinline)) g(int &t)  { fprintf (stderr, "(2)\n"); }

void __attribute__ ((noinline)) h1(int &&t) { g(t); }

template <typename T>
void __attribute__ ((noinline)) h2(T &&t) { g(t); }

template <typename T>
void __attribute__ ((noinline)) h3(T &&t) { g(std::move(t)); }

template <typename T>
void __attribute__ ((noinline)) h4(T &&t) { g(std::forward<T>(t)); }

int 
main (void)
{
  int x = 0;
  h1(1);
  /* h1(x); compilation error */
  h2(1);
  h2(x);
  h3(1);
  h3(x);
  h4(1);
  h4(x); 
  return 0;
}

