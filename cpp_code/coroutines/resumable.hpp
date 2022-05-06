//------------------------------------------------------------------------------
//
// Header for simplest resumables
//
// resumable -- simplest promise-resumable return object
// see also: hellocoro.cc
//
// resumable_no_wait -- see also hello_no_coro.cc
// resumable_no_own
// resumable_cancelable -- see also cancelable.cc
// resumable_noinc -- weakly incapsulated resumable object
// resume_optional -- see also optional.cc
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#pragma once
#include <cassert>
#include <iostream>
#include <optional>

#include "coroinclude.hpp"

//------------------------------------------------------------------------------
//
// resumable
//
//------------------------------------------------------------------------------

struct resumable {
  struct promise_type {
    using coro_handle = coro::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return coro::suspend_always(); }
    auto final_suspend() noexcept { return coro::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = coro::coroutine_handle<promise_type>;
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

//------------------------------------------------------------------------------
//
// resumable_no_wait
//
//------------------------------------------------------------------------------

struct resumable_no_wait {
  struct promise_type {
    using coro_handle = coro::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return coro::suspend_never(); }
    auto final_suspend() { return coro::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = coro::coroutine_handle<promise_type>;
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

//------------------------------------------------------------------------------
//
// resumable_no_own
//
//------------------------------------------------------------------------------

struct resumable_no_own {
  struct promise_type {
    using coro_handle = coro::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return coro::suspend_never(); }

    // this one is critical: no suspend on final suspend
    // effectively means "destroy your frame"
    auto final_suspend() { return coro::suspend_never(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = coro::coroutine_handle<promise_type>;
  resumable_no_own(coro_handle handle) {}
  resumable_no_own(resumable_no_own &) {}
  resumable_no_own(resumable_no_own &&rhs) {}
};

//------------------------------------------------------------------------------
//
// resumable_cancelable
//
//------------------------------------------------------------------------------

struct suspend_tunable {
  bool tune_;
  suspend_tunable(bool tune = true) : tune_(tune) {}
  bool await_ready() const noexcept { return tune_; }
  void await_suspend(coro::coroutine_handle<>) const noexcept {}
  void await_resume() const noexcept {}
};

struct resumable_cancelable {
  struct promise_type {
    bool is_cancelled = false;
    using coro_handle = coro::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return coro::suspend_always(); }
    auto final_suspend() { return coro::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }

    auto await_transform(coro::suspend_always) {
      if (is_cancelled)
        return suspend_tunable{true};
      return suspend_tunable{false};
    }
  };

  using coro_handle = coro::coroutine_handle<promise_type>;
  resumable_cancelable(coro_handle handle) : handle_(handle) { assert(handle); }
  resumable_cancelable(resumable_cancelable &) = delete;
  resumable_cancelable(resumable_cancelable &&rhs) : handle_(rhs.handle_) {
    rhs.handle_ = nullptr;
  }
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

//------------------------------------------------------------------------------
//
// resumable_noinc
//
//------------------------------------------------------------------------------

struct resumable_noinc {
  struct promise_type {
    using coro_handle = coro::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return coro::suspend_always(); }
    auto final_suspend() { return coro::suspend_always(); }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = coro::coroutine_handle<promise_type>;
  resumable_noinc(coro_handle handle) : handle_(handle) { assert(handle); }
  resumable_noinc(resumable_noinc &) = delete;
  resumable_noinc(resumable_noinc &&rhs) : handle_(rhs.handle_) {
    rhs.handle_ = nullptr;
  }
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

//------------------------------------------------------------------------------
//
// resume_optional
//
//------------------------------------------------------------------------------

template <typename T> class resume_optional {
  struct optional_awaiter {
    std::optional<T> opt_;

    optional_awaiter(std::optional<T> opt) : opt_{opt} {}

    bool await_ready() { return opt_.has_value(); }
    auto await_resume() { return opt_.value(); }
    void await_suspend(coro::coroutine_handle<>) {}
  };

public:
  struct promise_type {
    std::optional<T> opt_;
    using coro_handle = coro::coroutine_handle<promise_type>;
    auto get_return_object() { return coro_handle::from_promise(*this); }
    auto initial_suspend() { return coro::suspend_never{}; }
    auto final_suspend() { return coro::suspend_always{}; }
    optional_awaiter await_transform(std::optional<T> value) {
      return optional_awaiter{value};
    }
    void return_value(T value) { opt_ = value; }
    void unhandled_exception() { std::terminate(); }
  };

  using coro_handle = coro::coroutine_handle<promise_type>;
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
