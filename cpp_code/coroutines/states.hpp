//------------------------------------------------------------------------------
//
// State machine implementation
//
// Abstracts away states and symbols.
// see also: state_machine.cc
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#pragma once
#include <cassert>
#include <map>
#include <vector>

#include "generator.hpp"
#include "coroinclude.hpp"

using coro_t = coro::coroutine_handle<>;

template <typename State, typename Sym> class state_machine {
  State current_;
  std::map<State, coro_t> states_;
  generator<Sym> gen_;

public:
  state_machine(generator<Sym> &&g) : gen_{std::move(g)} {}

  void run(State initial) {
    current_ = initial;
    states_[initial].resume();
  }

  template <typename F> void add_state(State x, F stf) {
    states_[x] = stf(*this).handle();
  }

  coro_t operator[](State s) { return states_[s]; }

  State current() const { return current_; }

  template <typename F> auto get_awaiter(F transition);

  Sym genval() const { return gen_.current_value(); }
  void gennext() { gen_.move_next(); }
};

template <typename F, typename Sym, typename SM> struct stm_awaiter : public F {
  SM &stm_;
  stm_awaiter(F f, SM &stm) : F{f}, stm_{stm} {}
  bool await_ready() const noexcept { return false; }
  coro_t await_suspend(coro_t) noexcept {
    stm_.gennext();
    auto sym = stm_.genval();
    auto newstate = F::operator()(sym);
    return stm_[newstate];
  }
  bool await_resume() noexcept { return (stm_.genval() == Sym::Term); }
};

template <typename State, typename Sym>
template <typename F>
auto state_machine<State, Sym>::get_awaiter(F transition) {
  return stm_awaiter<F, Sym, decltype(*this)>(transition, *this);
}
