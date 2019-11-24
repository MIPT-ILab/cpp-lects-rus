#pragma once
#include <cassert>
#include <experimental/coroutine>
#include <iostream>

struct resumable {
  struct promise_type {
    using coro_handle = std::experimental::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return std::experimental::suspend_always(); }
    auto final_suspend() { return std::experimental::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  resumable(coro_handle handle) : handle_(handle) { assert(handle); }
  resumable(resumable &) = delete;
  resumable(resumable &&rhs) : handle_(rhs.handle_) { rhs.handle_ = nullptr; }
  bool resume() {
    if (!handle_.done())
      handle_.resume();
    return !handle_.done();
  }
  ~resumable() {
    if (handle_)
      handle_.destroy();
  }

private:
  coro_handle handle_;
};

struct resumable_no_wait {
  struct promise_type {
    using coro_handle = std::experimental::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return std::experimental::suspend_never(); }
    auto final_suspend() { return std::experimental::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  resumable_no_wait(coro_handle handle) : handle_(handle) { assert(handle); }
  resumable_no_wait(resumable_no_wait &) = delete;
  resumable_no_wait(resumable_no_wait &&rhs) : handle_(rhs.handle_) {
    rhs.handle_ = nullptr;
  }
  bool resume() {
    if (!handle_.done())
      handle_.resume();
    return !handle_.done();
  }
  ~resumable_no_wait() {
    if (handle_)
      handle_.destroy();
  }

private:
  coro_handle handle_;
};

struct resumable_no_own {
  struct promise_type {
    using coro_handle = std::experimental::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return std::experimental::suspend_never(); }

    // this one is critical: no suspend on final suspend
    // effectively means "destroy your frame"
    auto final_suspend() { return std::experimental::suspend_never(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  resumable_no_own(coro_handle handle) {}
  resumable_no_own(resumable_no_own &) {}
  resumable_no_own(resumable_no_own &&rhs) {}
};
