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

struct suspend_tunable {
  bool tune_;
  suspend_tunable(bool tune = true) : tune_(tune) {}
  bool await_ready() const noexcept { return tune_; }
  void await_suspend(std::experimental::coroutine_handle<>) const noexcept {}
  void await_resume() const noexcept {}
};

struct resumable_cancelable{
  struct promise_type {
    bool is_cancelled = false;
    using coro_handle = std::experimental::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return std::experimental::suspend_always(); }
    auto final_suspend() { return std::experimental::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }

    auto await_transform(std::experimental::suspend_always){
      if(is_cancelled)
        return suspend_tunable{true};
      return suspend_tunable{false};
    }
  };

  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  resumable_cancelable(coro_handle handle) : handle_(handle) { assert(handle); }
  resumable_cancelable(resumable_cancelable &) = delete;
  resumable_cancelable(resumable_cancelable &&rhs) : handle_(rhs.handle_) { rhs.handle_ = nullptr; }
  void cancel() {
    if (handle_.done())
      return;
    handle_.promise().is_cancelled = true;
    handle_.resume();
  }
  bool resume() {
    if (!handle_.done())
      handle_.resume();
    return !handle_.done();
  }
  ~resumable_cancelable() {
    if (handle_)
      handle_.destroy();
  }

private:
  coro_handle handle_;
};
  
// weakly incapsulated resumable object
// have ability to open handle
struct resumable_noinc {
  struct promise_type {
    using coro_handle = std::experimental::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return std::experimental::suspend_always(); }
    auto final_suspend() { return std::experimental::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  resumable_noinc(coro_handle handle) : handle_(handle) { assert(handle); }
  resumable_noinc(resumable_noinc &) = delete;
  resumable_noinc(resumable_noinc &&rhs) : handle_(rhs.handle_) { rhs.handle_ = nullptr; }
  bool resume() {
    if (!handle_.done())
      handle_.resume();
    return !handle_.done();
  }
  ~resumable_noinc() {
    if (handle_)
      handle_.destroy();
  }
  coro_handle handle() {
    coro_handle h = handle_;
    handle_ = nullptr;
    return h;
  }

private:
  coro_handle handle_;
};
