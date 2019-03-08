// C++11 stateless alloc example 1
// compile with: 
// g++ 01-attempt-1.cc --std=c++11 -Wfatal-errors

#include <list>
#include <vector>
#include <cstdio>
#include <limits>
#include <memory>

using std::numeric_limits;
using std::list;
using std::vector;

template<typename T> 
struct logging_alloc
{
  typedef T value_type;
  typedef T* pointer;

  pointer allocate (size_t n) {
    printf("allocate %zu elements\n", n);
    return pointer(::operator new(n * sizeof(value_type)));
  }
  
  void deallocate(pointer p, size_t n) { 
    printf("deallocate\n");
    ::operator delete(p); 
  }
  
  logging_alloc() { printf("default ctor\n"); }
  logging_alloc(const logging_alloc&) { 
    printf("copy ctor\n");
  }
};

int
main () 
{
  vector<int, logging_alloc<int> > v;

  for (int i = 0; i < 16; ++i)
    v.push_back(i);
  printf("---\n");
  vector<int, logging_alloc<int> > v2 = v;
  v2.push_back(16);

// problems:
#if defined(PROBLEMS)
  v = v2;

  list<int, logging_alloc<int> > l(v.begin(), v.end());  
#endif
}
