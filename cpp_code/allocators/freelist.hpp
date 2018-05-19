// C++11 freelist alloc

#ifndef FREELIST_ALLOC_GUARD__
#define FREELIST_ALLOC_GUARD__

#include <cstdio>
#include <memory>
#include <type_traits>

using std::aligned_storage;

template <typename T>
class freelist_alloc {
  union node {
    node* next;
    typename aligned_storage<sizeof(T), alignof(T)>::type storage;
  };

  node* list = nullptr;

  void clear() noexcept {
    printf("clear\n");
    auto p = list;
    while (p) {
      auto tmp = p;
      p = p->next;
      delete tmp;
    }
    list = nullptr;
  }

public:
  using value_type = T;
  using size_type = std::size_t;
  using propagate_on_container_move_assignment = std::true_type;

  freelist_alloc() noexcept = default;
  freelist_alloc(const freelist_alloc&) noexcept {}

  template <typename U>
  freelist_alloc(const freelist_alloc<U>&) noexcept {}

  freelist_alloc(freelist_alloc&& other) noexcept :  list(other.list) {
    other.list = nullptr;
  }

  freelist_alloc& operator= (const freelist_alloc&) noexcept {
    return *this;
  }

  freelist_alloc& operator= (freelist_alloc&& other) noexcept {
    if (this == &other)
      return *this;
    clear();
    list = other.list;
    other.list = nullptr;
    return *this;
  }

  ~freelist_alloc() noexcept { 
    printf("freelist dtor\n");
    clear();
  }

  T* allocate(size_type n) {
    printf("allocate %zu from: ", n);
    if (n == 1) {
      auto ptr = list;
      if (ptr) {
        printf("freelist\n");
        list = list->next;
      } else {
        printf("new node\n");
        ptr = new node;
      }
      return reinterpret_cast<T*>(ptr);
    }

    printf("new memory\n");
    return static_cast<T*>(::operator new(n * sizeof(T)));
  }

  void deallocate(T* ptr, size_type n) noexcept {
    printf("deallocate %zu to: ", n);
    if (n == 1) {
      printf("freelist\n");
      auto node_ptr = reinterpret_cast<node*>(ptr);
      node_ptr->next = list;
      list = node_ptr;
    } else {
      printf("global delete\n");
      ::operator delete(ptr);
    }
  }    
};

template <typename T, typename U>
bool operator == (const freelist_alloc<T>&, const freelist_alloc<U>&) {
    return true;
}

template <typename T, typename U>
bool operator != (const freelist_alloc<T>&, const freelist_alloc<U>&) {
    return false;
}

#endif