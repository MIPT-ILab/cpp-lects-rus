// cl -await -EHsc -O2 state_machine_measure.cc
// cl -await -EHsc state_machine_measure.cc -DDEBUG
// cl -await -EHsc state_machine_measure.cc -DEBUG -Zi

#include <ctime>
#include <iostream>
#include <string>
#include <utility>

#include "generator.hpp"
#include "resumable.hpp"
#include "states_opt.hpp"

#ifdef DEBUG
#define log(x) printf(x)
#else
#define log(x)
#endif

enum class State : char { A = 1, B, C };
enum class Sym : char { A, B, Term };

// FSM:
// A -- 'a' --> B
// A -- 'b' --> C
// B -- 'a' --> C
// B -- 'b' --> A
// C -- 'a' --> A
// C -- 'b' --> B

// basic test inp1.fsm: aaabba
// start: A
// output: ABCACBC

State transition(State state, Sym sym) {
  switch (state) {
  case State::A:
    if (sym == Sym::A)
      return State::B;
    else
      return State::C;
  case State::B:
    if (sym == Sym::A)
      return State::C;
    else
      return State::A;
  case State::C:
    if (sym == Sym::A)
      return State::A;
    else
      return State::B;
  }
  return state;
};

using stm_t = state_machine<State, Sym, decltype(&transition)>;

generator<Sym> input_seq(unsigned long long n) {
  char c;
  while (n-- > 0) {
    c = (rand() % 2) ? 'a' : 'b';
    switch (std::tolower(c)) {
    case 'a':
      co_yield Sym::A;
      break;
    case 'b':
      co_yield Sym::B;
      break;
    default:
      co_yield Sym::Term;
      break;
    }
  }

  for (;;)
    co_yield Sym::Term;
}

resumable_noinc StateA(stm_t &stm) {
  for (;;) {
    log("A\n");
    bool finish = co_await stm.get_awaiter(State::A);
    if (finish)
      break;
  }
}

resumable_noinc StateB(stm_t &stm) {
  for (;;) {
    log("B\n");
    bool finish = co_await stm.get_awaiter(State::B);
    if (finish)
      break;
  }
}

resumable_noinc StateC(stm_t &stm) {
  for (;;) {
    log("C\n");
    bool finish = co_await stm.get_awaiter(State::C);
    if (finish)
      break;
  }
}

int main() {
  clock_t start, fin;
  int n, m;
  std::cin >> n >> m;
  assert(n > 1);
  assert(m > 1);

  start = clock();

  for (int i = 0; i < m; ++i) {
    auto gen = input_seq(n);
    stm_t stm{std::move(gen), transition};
    stm.add_state(State::A, StateA);
    stm.add_state(State::B, StateB);
    stm.add_state(State::C, StateC);
    stm.run(State::A); // initial state is A
  }
  fin = clock();

  printf("Elapsed: %lg seconds\n", (double)(fin - start) / CLOCKS_PER_SEC);
}
