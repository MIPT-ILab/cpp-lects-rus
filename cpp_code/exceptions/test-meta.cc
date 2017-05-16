#include <iostream>

using std::cout;
using std::endl;

#if defined(STRUCT)
#include "struct_approach.hpp"
#elif defined(FUNC)
#include "func_approach.hpp"
#elif defined(ISSAME)
#include "is_same_approach.hpp"
#else
#include "except_approach.hpp"
#endif

#define T8(x) x,x,x,x,x,x,x,x
#define T64(x) T8(x),T8(x),T8(x),T8(x),T8(x),T8(x),T8(x),T8(x)
#define T512(x) T64(x),T64(x),T64(x),T64(x),T64(x),T64(x),T64(x),T64(x)
#define T4096(x) T512(x),T512(x),T512(x),T512(x),T512(x),T512(x),T512(x),T512(x)
#define T32768(x) T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x)
#define T262144(x) T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x)
#define T1MB(x) T262144(x),T262144(x),T262144(x),T262144(x)
#define T2MB(x) T1MB(x),T1MB(x)

int
main ()
{
  cout << all_true<T2MB(true)>::value << endl;
}

