#include <stdint.h>

#define T int 
#include "max.h"
#undef T 
#define T float 
#include "max.h" 
#undef T 

#define T uint64_t 
#include "max.h"
#undef T 

#if 0
#define T float* 
#include "max.h"
#undef T 
#endif

#if 0
#define T const float& 
#include "max.h"
#undef T 
#endif

#if 0
#define T long long 
#include "max.h"
#undef T 
#endif

#if 0
#define T unsigned long long * const 
#include "max.h"
#undef T 
#endif

#if 0
#define T int& 
#include "max.h"
#undef T 
#endif

#define T int_least32_t 
#include "max.h"
#undef T 

#if 0
#define T void (*) (int, float) 
#include "max.h"
#undef T 
#endif


