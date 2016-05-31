#include <utility>
#include <iostream>

#if 0

template <typename C>
concept bool Int = std::is_integral<C>::value;

void check (Int x) {
  std::cout << "Brief" << std::endl;
}

constexpr bool check_always () { return true; }

template <typename C> 
requires /* std::is_integral<C>::value ||*/ check_always()
void check (C x) {
  std::cout << "Full" << std::endl;
}

#endif

template<typename T>
concept bool Subsumed() {
    return requires () { typename T::type1; };
}

template<typename T>
concept bool Subsuming() {
    return Subsumed<T>()
        && requires () { typename T::type2; };
}

struct M {
    using type1 = int;
    using type2 = int;
};

template<typename T>
struct TM;

template<Subsumed T>
struct TM<T> { TM() {std::cout << "Subsumed!\n";}  };

template<Subsuming T>
struct TM<T> { TM() {std::cout << "Subsuming!\n";}  };

int 
main (void) {
  TM<M> X{};
  return 0;
}
