#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "myranges.hpp"

template<class Rngs>
class interleave_view : public ranges::view_facade<interleave_view<Rngs>>
{
  struct cursor {
    std::size_t current_;
    std::vector<ranges::range_value_t<Rngs>> *rngs_;
    std::vector<ranges::iterator_t<ranges::range_value_t<Rngs>>> its_;
    decltype(auto) read() const { return *its_[current_]; }
    void next() {
      current_ = (current_ + 1) % its_.size();
      if(current_ == 0)
        ranges::for_each(its_, [](auto &it) { ++it; });
    }
    
    // we are done if any of ranges finished
    bool equal(ranges::default_sentinel_t) const {
      if(current_ != 0)
        return false;
      auto ends = *rngs_ | ranges::views::transform(ranges::end);
      return its_.end() != std::mismatch(
        its_.begin(), its_.end(), ends.begin(), std::not_equal_to<>{}).first;
    }
  };

  friend ranges::range_access;
  std::vector<ranges::range_value_t<Rngs>> rngs_;
  cursor begin_cursor() {
    return {0, &rngs_, ranges::views::transform(rngs_, ranges::begin) | ranges::to<std::vector>};
  }

public:
  interleave_view() = default;
  explicit interleave_view(Rngs rngs) : rngs_(std::move(rngs) | ranges::to<std::vector>) {}
};

auto myinterleave() {
  return ranges::make_view_closure([](auto &&rngs) {
    using Rngs = decltype(rngs);
    return interleave_view<ranges::views::all_t<Rngs>>(
      ranges::views::all(std::forward<Rngs>(rngs)));
  });
}

int main() {
  // chunklist = 
  //    1 2 3 4
  //    5 6 7 8
  //    9 10 11 12
  auto chunklist = ranges::views::ints(1, 13) | ranges::views::chunk(4);
  
  // interl = 1 5 9 2 6 10 3 7 11 4 8 12
  auto interl = chunklist | myinterleave();
  ranges::copy(interl, ranges::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;
}
