// cl -await -EHsc -std:c++17 optional_shared.cc

#include <experimental/coroutine>
#include <iostream>
#include <memory>
#include <optional>
#include <utility>

template <typename T> class shared_optional {
  std::shared_ptr<std::optional<T>> opt_;

public:
  struct promise_type {
    shared_optional<T> opt;

    auto get_return_object() { return opt; }
    auto initial_suspend() { return std::experimental::suspend_never{}; }
    auto final_suspend() { return std::experimental::suspend_never{}; }
    void return_value(T value) { opt.emplace(std::move(value)); }
  };

  shared_optional() : opt_{std::make_shared<std::optional<T>>()} {}

  auto &operator*() const { return **opt_; }
  auto operator->() const { return &**opt_; }
  explicit operator bool() const { return static_cast<bool>(*opt_); }
  void reset() { opt_->reset(); }

  template <typename U> void emplace(U &&value) {
    opt_->emplace(std::forward<U>(value));
  }

  auto operator co_await() {
    struct awaiter {
      const shared_optional &input;
      bool await_ready() { return static_cast<bool>(input); }
      auto await_resume() { return *input; }
      void await_suspend(std::experimental::coroutine_handle<> coro) {
        coro.destroy();
      }
    };
    return awaiter{*this};
  }
};

shared_optional<int> five() { co_return 5; }

shared_optional<int> six() { co_return 6; }

shared_optional<int> empty() { return {}; }

shared_optional<int> sum() {
  auto a = co_await five();
  auto b = co_await six();

  co_return a + b;
}

shared_optional<int> sum2() {
  auto a = co_await five();
  auto b = co_await empty();

  co_return a + b;
}

std::ostream &operator<<(std::ostream &os, const shared_optional<int> &opt) {
  if (!opt)
    os << "(empty)";
  else
    os << *opt;
  return os;
}

int main() {
  auto opt = sum();
  std::cout << "sum: " << opt << std::endl;

  auto opt2 = sum2();
  std::cout << "sum2: " << opt2 << std::endl;
}
