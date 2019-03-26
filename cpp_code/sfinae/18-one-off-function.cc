#include <functional>
#include <iostream>
#include <memory>
#include <utility>

using ftype = int();

int foo(std::function<ftype> f) {
  return f();
}

template <typename T> class fire_once;

template <typename R, typename... Args> 
class fire_once<R(Args...)> {
  std::unique_ptr<void, void (*)(void *)> ptr{nullptr, +[](void *) {}};
  R (*invoke)(void *, Args...) = nullptr;

public:
  fire_once() = default;
  fire_once(fire_once &&) = default;
  fire_once &operator=(fire_once &&) = default;

  // constructor from anything callable
  template <typename F> fire_once(F &&f) {
    auto pf = std::make_unique<F>(std::move(f));
    invoke = +[](void *pf, Args... args) -> R {
      F *f = reinterpret_cast<F *>(pf);
      return (*f)(std::forward<Args>(args)...);
    };
    ptr = {pf.release(), [](void *pf) {
             F *f = reinterpret_cast<F *>(pf);
             delete f;
           }};
  }

  // invoke if R not void
  template <typename R2 = R,
            std::enable_if_t<!std::is_same<R2, void>{}, int> = 0>
  R2 operator()(Args... args) && {
    R2 ret = invoke(ptr.get(), std::forward<Args>(args)...);
    clear();
    return ret;
  }

  // invoke if R is void
  template <typename R2 = R,
            std::enable_if_t<std::is_same<R2, void>{}, int> = 0>
  R2 operator()(Args... args) && {
    invoke(ptr.get(), std::forward<Args>(args)...);
    clear();
  }

  void clear() {
    invoke = nullptr;
    ptr.reset();
  }

  explicit operator bool() const { return (bool)ptr; }
};

int foo(fire_once<ftype> f) {
  return std::move(f)();
}

int
main() {
  auto n = std::make_unique<int>(42);
#if !defined(CORRECT)
  std::function<ftype> f = [nrr = std::move(n)] { 
    std::cout << *nrr << std::endl;
    return 0;
  };
#else
  fire_once<ftype> f = [nrr = std::move(n)] { 
    std::cout << *nrr << std::endl;
    return 0;
  };
#endif
  foo(std::move(f));
}
