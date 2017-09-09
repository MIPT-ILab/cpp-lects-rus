#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <new>
#include <string>
#include <sstream>
#include <utility>

using std::cout;
using std::endl;
using std::forward;
using std::free;
using std::malloc;
using std::ostringstream;
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

void addToStream(ostringstream&) {}

template<typename T, typename... Args>
void 
addToStream(ostringstream& a_stream, T&& a_value, Args&&... a_args)
{
  a_stream << forward<T>(a_value);
  addToStream(a_stream, forward<Args>(a_args)...);
}

template<typename... Args>
string 
concat(Args&&... a_args)
{
    ostringstream s;
    addToStream(s, forward<Args>(a_args)...);
    return s.str();
}

__attribute__ ((noinline)) string
foo (bool ssl, const string& path, const string& query) {
  return concat (ssl ? "http" : "https", "://", path, "/", query);
}

int
main ()
{
  printf("%s\n", "Started");
  string s = foo(true, "myurl", "?v=1");
  cout << s << endl;
}

