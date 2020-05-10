#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "myranges.hpp"

template <typename Range>
class mychunks_view : public ranges::view_adaptor<mychunks_view<Range>, Range> {
  using Base = ranges::view_adaptor<mychunks_view<Range>, Range>;
  class adaptor : public ranges::adaptor_base {
    using adaptor_base::prev;
    size_t n_;
    ranges::sentinel_t<Range> end_;

  public:
    adaptor() = default;
    adaptor(size_t n, ranges::sentinel_t<Range> end) : n_{n}, end_{end} {}

    auto read(ranges::iterator_t<Range> it) const {
      return ranges::views::take(ranges::make_subrange(it, end_), n_);
    }
    void next(ranges::iterator_t<Range> &it) const {
      ranges::advance(it, n_, end_);
    }
  };

  adaptor begin_adaptor() const {
    return adaptor{n_, ranges::end(this->base())};
  }
  size_t n_;
  friend ranges::range_access;

public:
  mychunks_view() = default;
  mychunks_view(Range rng, size_t n) : Base{std::move(rng)}, n_{n} {}
};

template <typename Integral> auto mychunks(Integral n) {
  return ranges::make_view_closure([n]<typename Range>(Range rng) {
    return mychunks_view<Range>(rng, size_t(n));
  });
}

int main() {
  // auto chunklist = ranges::views::ints(1, 13) | ranges::views::chunk(4);
  auto chunklist = ranges::views::ints(1, 13) | mychunks(4);

  for (auto rng : chunklist) {
    ranges::copy(rng, ranges::ostream_iterator<int>{std::cout, " "});
    std::cout << std::endl;
  }
}
