#pragma once
#include <cassert>
#include <experimental/coroutine>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>

#include "generator.hpp"

using coro_t = std::experimental::coroutine_handle<>;

template <typename State, typename Sym, typename F> class state_machine {
  State current_;
  std::map<State, coro_t> states_;
  generator<Sym> gen_;
  F tf_;

public:
  using StateT = State;

  state_machine(generator<Sym> &&g, F tf) : gen_{std::move(g)}, tf_{tf} {}

  State translate(State state, Sym sym) { return tf_(state, sym); }

  void run(State initial) {
    current_ = initial;
    states_[initial].resume();
  }

  template <typename F> void add_state(State x, F stf) {
    states_[x] = stf(*this).handle();
  }

  coro_t operator[](State s) { return states_[s]; }

  State current() const { return current_; }

  decltype(auto) get_awaiter(State s);

  Sym genval() const { return gen_.current_value(); }
  void gennext() { gen_.move_next(); }
};

template <typename SM, typename State> struct stm_awaiter {
  State s_;
  SM &stm_;
  stm_awaiter(State s, SM &stm) : s_{s}, stm_{stm} {}
  bool await_ready() const noexcept { return false; }
  coro_t await_suspend(coro_t) noexcept {
    stm_.gennext();
    auto sym = stm_.genval();
    auto newstate = stm_.translate(s_, sym);
    return stm_[newstate];
  }
  bool await_resume() noexcept { return (stm_.genval() == Sym::Term); }
};

template <typename State, typename Sym, typename F>
decltype(auto) state_machine<State, Sym, F>::get_awaiter(State s) {
  using awt = stm_awaiter<decltype(*this), State>;
  using sawt = std::shared_ptr<awt>;
  static std::unordered_map<State, sawt> m;
  if (m.end() == m.find(s))
    m[s] = std::make_shared<awt>(s, *this);
  return *m[s].get();
}
