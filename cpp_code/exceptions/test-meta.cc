// g++ test-meta.cc -DSZ=8 -DSTRUCT -ftemplate-depth=10000 -fconstexpr-depth=10000 -ftime-report -Wfatal-errors

#include <iostream>

using std::cout;
using std::endl;

#if defined(STRUCT)
#include "struct_approach_2.hpp"
#elif defined(MPL_STRUCT)
#include "hana_approach.hpp"
#elif defined(FUNC)
#include "new_func_approach.hpp"
#elif defined(NOEXCEPT)
#include "except_approach.hpp"
#elif defined(ISSAME)
#include "is_same_approach.hpp"
#else
#error "You shall define STRUCT, MPL_STRUCT, FUNC, ISSAME or NOEXCEPT"
#endif

#define T8(x) x,x,x,x,x,x,x,x
#define T64(x) T8(x),T8(x),T8(x),T8(x),T8(x),T8(x),T8(x),T8(x)
#define T512(x) T64(x),T64(x),T64(x),T64(x),T64(x),T64(x),T64(x),T64(x)
#define T4096(x) T512(x),T512(x),T512(x),T512(x),T512(x),T512(x),T512(x),T512(x)
#define T32768(x) T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x),T4096(x)
#define T262144(x) T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x),T32768(x)
#define T1048576(x) T262144(x),T262144(x),T262144(x),T262144(x)
#define T1572864(x) T1048576(x),T262144(x),T262144(x)
#define T2097152(x) T1048576(x),T1048576(x)
#define T4194304(x) T2097152(x),T2097152(x)
#define T8388608(x) T4194304(x),T4194304(x)

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

