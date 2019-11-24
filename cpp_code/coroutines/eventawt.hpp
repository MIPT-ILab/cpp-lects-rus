#pragma once
#include <cassert>
#include <experimental/coroutine>
#include <iostream>

class evt_awaiter_t {
  void *state_;

  struct awaiter {
    evt_awaiter_t &event_;
    std::experimental::coroutine_handle<> coro_ = nullptr;
    awaiter *next_ = nullptr;
    awaiter(evt_awaiter_t &event) noexcept : event_(event) {}
    bool await_ready() const noexcept {
      std::cout << "await_ready: " << std::boolalpha << event_.is_set()
                << std::endl;
      return event_.is_set();
    }
    bool await_suspend(std::experimental::coroutine_handle<> coro) noexcept;
    void await_resume() noexcept {}
  };

  friend class awaiter;

public:
  evt_awaiter_t(bool set = false) : state_{set ? this : nullptr} {}
  evt_awaiter_t(const evt_awaiter_t &) = delete;
  evt_awaiter_t &operator=(const evt_awaiter_t &) = delete;
  evt_awaiter_t(evt_awaiter_t &&) = delete;
  evt_awaiter_t &operator=(evt_awaiter_t &&) = delete;

public:
  bool is_set() const noexcept { return state_ == this; }
  awaiter operator co_await() noexcept { return awaiter{*this}; }

  void set() noexcept;
  void reset() noexcept { state_ = nullptr; }
};

bool evt_awaiter_t::awaiter::await_suspend(
    std::experimental::coroutine_handle<> coro) noexcept {
  void const *const setstate = &event_;
  coro_ = coro;
  void *oldval = event_.state_;
  std::cout << "await_suspend: " << std::boolalpha << (oldval == setstate)
            << std::endl;
  if (oldval == setstate)
    return false;
  next_ = static_cast<awaiter *>(oldval);
  event_.state_ = this;
  return true;
}

void evt_awaiter_t::set() noexcept {
  std::cout << "set: " << std::boolalpha << (state_ == this) << std::endl;

  if (state_ == this)
    return;

  auto *waiters = static_cast<awaiter *>(state_);
  while (waiters) {
    auto *next = waiters->next_;
    waiters->coro_.resume();
    waiters = next;
  }
}
