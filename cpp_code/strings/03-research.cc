#include <cstdlib>
#include <iostream>
#include <new>
#include <string>

using std::cout;
using std::endl;
using std::free;
using std::malloc;
using std::size_t;
using std::string;

size_t allocated = 0;

void* 
operator new (size_t sz)
{
  void* p = malloc(sz);
  allocated += sz;
  return p;
}

void 
operator delete(void* p) noexcept
{
  free(p);
}

int
main()
{
  allocated = 0;
  string s = "hi";
  cout << "stack space = " << sizeof(s) << ", heap space = " 
       << allocated << ", capacity = " << s.capacity() << endl;
  return 0;
}
