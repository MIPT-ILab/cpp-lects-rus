#pragma once
#include <cassert>
#include <experimental/coroutine>
#include <iostream>
#include <optional>

// really no method for resume
// if we once gave up control we will never retain it

template <typename T> class resume_optional {
  struct optional_awaiter {
    std::optional<T> opt_;

    optional_awaiter(std::optional<T> opt) : opt_{opt} {}

    bool await_ready() { return opt_.has_value(); }
    auto await_resume() { return opt_.value(); }
    void await_suspend(std::experimental::coroutine_handle<>) {}
  };

public:
  struct promise_type {
    std::optional<T> opt_;
    using coro_handle = std::experimental::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return std::experimental::suspend_never{}; }
    auto final_suspend() { return std::experimental::suspend_always{}; }
    optional_awaiter await_transform(std::optional<T> value) {
      return optional_awaiter{value};
    }
    void return_value(T value) { opt_ = value; }
  };

  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  resume_optional(coro_handle handle) : handle_(handle) { assert(handle); }
  resume_optional(resume_optional &) = delete;
  resume_optional(resume_optional &&rhs) : handle_(rhs.handle_) {
    rhs.handle_ = nullptr;
  }

  std::optional<T> current_value() const {
    if (handle_)
      return handle_.promise().opt_;
    return std::nullopt;
  }

  ~resume_optional() {
    if (handle_)
      handle_.destroy();
  }

private:
  coro_handle handle_;
};
