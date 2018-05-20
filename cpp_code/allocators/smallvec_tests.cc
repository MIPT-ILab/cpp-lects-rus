#include <iostream>
#include <new>
#include <vector>

#include "short_alloc.hpp"

// Replace new and delete just for the purpose of demonstrating that
//  they are not called.

size_t memory = 0;
size_t alloc = 0;

void* operator new(size_t s) noexcept(false)
{
    memory += s;
    ++alloc;
    return malloc(s);
}

void  operator delete(void* p) throw()
{
    --alloc;
    free(p);
}

void memuse()
{
    std::cout << "memory = " << memory << '\n';
    std::cout << "alloc = " << alloc << '\n';
}

// Create a vector<T> template with a small buffer of 200 bytes.
//   Note for vector it is possible to reduce the alignment requirements
//   down to alignof(T) because vector doesn't allocate anything but T's.
//   And if we're wrong about that guess, it is a compile-time error, not
//   a run time error.
template <class T, size_t BufSize = 200>
using SmallVector = std::vector<T, short_alloc<T, BufSize, alignof(T)>>;

int main()
{
    // Create the stack-based arena from which to allocate
    SmallVector<int>::allocator_type::arena_type a;
    // Create the vector which uses that arena.
    SmallVector<int> v{a};
    // Exercise the vector and note that new/delete are not getting called.
    v.push_back(1);
    memuse();
    v.push_back(2);
    memuse();
    v.push_back(3);
    memuse();
    v.push_back(4);
    memuse();
    // Yes, the correct values are actually in the vector
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';
}
