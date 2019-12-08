#pragma once
#include <cassert>
#include <experimental/coroutine>
#include <list>

using coro_t = std::experimental::coroutine_handle<>;

class evt_awaiter_t {
  struct awaiter;

  // natural list: this is top and we will amend to top
  awaiter *top_ = nullptr;
  bool set_;

  struct awaiter {
    evt_awaiter_t &event_;
    awaiter *next_;
    coro_t coro_ = nullptr;
    awaiter(evt_awaiter_t &event) noexcept : event_(event) {}

    bool await_ready() const noexcept { return event_.is_set(); }

    void await_suspend(coro_t coro) noexcept {
      coro_ = coro;
      event_.push_awaiter(this);
    }

    void await_resume() noexcept { event_.reset(); }
  };

public:
  evt_awaiter_t(bool set = false) : set_{set} {}
  evt_awaiter_t(const evt_awaiter_t &) = delete;
  evt_awaiter_t &operator=(const evt_awaiter_t &) = delete;
  evt_awaiter_t(evt_awaiter_t &&) = delete;
  evt_awaiter_t &operator=(evt_awaiter_t &&) = delete;

public:
  bool is_set() const noexcept { return set_; }
  void push_awaiter(awaiter *a) {
    awaiter *oldtop = top_;
    top_ = a;
    a->next_ = oldtop;
  }

  awaiter operator co_await() noexcept { return awaiter{this}; }

  void set() noexcept {
    set_ = true;
    auto cur_ = top_;
    top_ = nullptr;
    while (cur_) {
      cur_->coro_.resume();
      cur_ = cur_->next_;
    }
  }

  void reset() noexcept { set_ = false; }
};
