// try: 
// > g++-10 -std=c++2a exec-singlethread.cc -lunifex -pthread

#include <iostream>

#include <unifex/execute.hpp>
#include <unifex/single_thread_context.hpp>

namespace ex = unifex;

int main() {
  ex::single_thread_context ctx;

  for (int i = 0; i < 5; ++i) 
    ex::execute(ctx.get_scheduler(), [i]() {
      std::cout << "hello execute: " << i << std::endl;
    });
}
