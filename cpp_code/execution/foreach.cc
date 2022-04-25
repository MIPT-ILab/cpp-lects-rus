/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License Version 2.0 with LLVM Exceptions
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *   https://llvm.org/LICENSE.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <iterator>

#include <unifex/for_each.hpp>
#include <unifex/range_stream.hpp>
#include <unifex/single_thread_context.hpp>
#include <unifex/sync_wait.hpp>
#include <unifex/then.hpp>
#include <unifex/transform_stream.hpp>
#include <unifex/via_stream.hpp>

namespace ex = unifex;
namespace tt = unifex;

int main() {
  ex::single_thread_context context;

  ex::scheduler auto sched = context.get_scheduler();
  auto stream = ex::range_stream{0, 10} |
                ex::transform_stream([](int x) { return x * x; });
  ex::sender auto sender = ex::via_stream(sched, stream) |
                ex::for_each([](int x) { std::cout << x << std::endl; });
  tt::sync_wait(sender | ex::then([]() { std::cout << "done\n"; }));
}
