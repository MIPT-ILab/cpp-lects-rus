#include <cstdlib>
#include <iostream>
#include <new>
#include <string>
#include <cstdio>

using std::cout;
using std::endl;
using std::free;
using std::malloc;
using std::size_t;
using std::string;
using std::printf;

void* 
operator new (size_t sz)
{
  printf ("Allocating %d of heap\n", sz);
  void* p = malloc(sz);
  return p;
}

void 
operator delete(void* p) noexcept
{
  free(p);
}

__attribute__ ((noinline)) string
foo (bool ssl, const string& path, const string& query) {
  string a = ssl ? "https" : "http";
  a = a + "://" + path + "/" + query;
  return a;
}

int
main ()
{
  printf("%s\n", "Started");
  string s = foo(true, "myurl", "?v=1");
  cout << s << endl;
}
