// cl -await -EHsc subscribers.cc

#include <iostream>
#include <string>
#include <utility>

#include "resumable.hpp"
#include "generator.hpp"
#include "states.hpp"

enum class State : char { A, B };
enum class Sym : char { A, B, Term };

using stm_t = state_machine<State, Sym>;

generator<Sym> input_seq(std::string s) {
  for(char c : s) {
    switch (std::tolower(c)) {
      case 'a': co_yield Sym::A; break;
      case 'b': co_yield Sym::B; break;
      default: co_yield Sym::Term; break;
    }
  }
  
  for(;;)
    co_yield Sym::Term;
}

resumable_noinc StateA(stm_t &stm) {  
  auto transition = [](auto sym) {
    if (sym == Sym::B)
      return State::B;
    return State::A;
  };
  
  for(;;) {
    std::cout << "State A" << std::endl;
    bool finish = co_await stm.get_awaiter(transition);
    if (finish)
      break;
  }
}

resumable_noinc StateB(stm_t &stm) {
  auto transition = [](auto sym) {
    if (sym == Sym::A)
      return State::A;
    return State::B;
  };

  for(;;) {
    std::cout << "State B" << std::endl;
    bool finish = co_await stm.get_awaiter(transition);
    if (finish)
      break;
  }
}

int main() {  
  auto gen = input_seq("aaabbaba");
  stm_t stm{std::move(gen)};
  stm.add_state(State::A, StateA);
  stm.add_state(State::B, StateB);
  stm.run(State::A); // initial state is A
  
  std::string st = (stm.current() == State::A ? "A" : "B");
  std::cout << "State machine in state " << st << std::endl;
}
