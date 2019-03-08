// C++98 stateless alloc

#ifndef STATELES_ALLOC_GUARD__
#define STATELES_ALLOC_GUARD__

#include <cstdio>
#include <limits>
#include <memory>

using std::numeric_limits;

template<typename T> 
struct logging_alloc {
  typedef T value_type;
  typedef T* pointer;

  logging_alloc() { printf("default ctor\n"); }

  logging_alloc(const logging_alloc&) { 
    printf("copy ctor\n");
  }

#if __cplusplus < 201103L
// -- 0.1. these required only for C++98, but having it is good practice
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

// --- 0.2. rebind will be deprecated in C++20, but required in C++98
  template <typename U> struct rebind { 
    typedef logging_alloc<U> other;
  };

// --- 0.3. C++98 also requires construct and destroy
  void construct(pointer p, const T& t) { 
    printf("construct\n");
    new(p) T(t); 
  }

  void destroy(pointer p) { 
    printf("destroy\n");
    p->~T(); 
  }

// --- 0.4. C++98 also explicitly requires max_size
  size_type max_size() const { 
    printf("max_size\n");
    return numeric_limits<size_type>::max() / sizeof(T);
  }
#endif

// --- 1. basic functionality C++11
  T* allocate (size_t n) {
    printf("allocate %zu elements\n", n);
    return static_cast<T*>(::operator new(n * sizeof(value_type))); 
  }
  void deallocate(T* p, size_t n) { 
    printf("deallocate\n");
    ::operator delete(p); 
  }

// --- 3. coercion
  template<typename U> 
  logging_alloc(const logging_alloc<U>&) {
    printf("coercion ctor\n");
  }
};

// --- 2. comparisons
template <typename T, typename U>
bool operator== (const logging_alloc<T>&,
                 const logging_alloc<U>&) {
  return true;
}

template <typename T, typename U>
bool operator!= (const logging_alloc<T>&,
                 const logging_alloc<U>&) {
  return false;
}

#endif