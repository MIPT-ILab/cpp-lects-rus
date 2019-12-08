#pragma once
#include <cassert>
#include <experimental/coroutine>
#include <list>

using coro_t = std::experimental::coroutine_handle<>;

class evt_awaiter_t {
  struct awaiter;

  // we want to pop front and push back WITHOUT iterator invalidation
  std::list<awaiter> lst_;
  bool set_;

  struct awaiter {
    evt_awaiter_t &event_;
    coro_t coro_ = nullptr;
    awaiter(evt_awaiter_t &event) noexcept : event_(event) {}

    bool await_ready() const noexcept { return event_.is_set(); }

    void await_suspend(coro_t coro) noexcept {
      coro_ = coro;
      event_.push_awaiter(*this);
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
  void push_awaiter(awaiter a) { lst_.push_back(a); }

  awaiter operator co_await() noexcept { return awaiter{*this}; }

  void set() noexcept {
    set_ = true;
#if INEFF
    auto ntoresume = lst_.size();
    while (ntoresume > 0) {
      lst_.front().coro_.resume();
      lst_.pop_front();
      ntoresume--;
    }
#else
    std::list<awaiter> toresume;
    toresume.splice(toresume.begin(), lst_);
    for (auto s: toresume)
      s.coro_.resume();    
#endif    
  }

  void reset() noexcept { set_ = false; }
};
