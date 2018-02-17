// g++ test-meta.cc -DSZ=8 -ftemplate-depth=10000 -fconstexpr-depth=10000 -ftime-report -Wfatal-errors

#include <iostream>

using std::cout;
using std::endl;

#if defined(STRUCT)
#include "struct_approach.hpp"
#elif defined(FUNC)
#include "func_approach.hpp"
#elif defined(ISSAME)
#include "is_same_approach.hpp"
#elif defined(NOEXCEPT)
#include "except_approach.hpp"
#else
#error "You shall define STRUCT, FUNC, ISSAME or NOEXCEPT"
#endif

#define T8(x) x,x,x,x,x,x,x,x
#define T64(x) T8(x),T8(x),T8(x),T8(x),T8(x),T8(x),T8(x),T8(x)
#define T512(x) T64(x),T64(x),T64(x),T64(x),T64(x),T64(x),T64(x),T64(x)
#define T4096(x) T512(x),T512(x),T512(x),T512(x),T512(x),T512(x),T512(x),T512(x)
#define T32768(x) T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x)
#define T262144(x) T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x)
#define T1MB(x) T262144(x),T262144(x),T262144(x),T262144(x)
#define T2MB(x) T1MB(x),T1MB(x)
#define T4MB(x) T2MB(x),T2MB(x)
#define T8MB(x) T4MB(x),T4MB(x)

#ifndef SZ
#define SZ 8
#endif

#define CONCAT1(X,Y) X ## Y
#define CONCAT(X,Y) CONCAT1(X,Y)

int
main ()
{
  cout << all_true<CONCAT(T,SZ)(true)>::value << endl;
}

