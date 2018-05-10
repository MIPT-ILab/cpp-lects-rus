#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <unordered_set>

#ifndef NOBOOST
#include <boost/functional/hash/hash.hpp>
#endif

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::tie;
using std::unordered_set;

struct S {
  string first_name, last_name;
  bool less(const S& rhs) const {
    return tie(first_name, last_name) < tie(rhs.first_name, rhs.last_name);
  }
};

bool operator <(const S& lhs, const S& rhs) {
  return lhs.less(rhs);
}

bool operator==(const S& lhs, const S& rhs) {
  return !lhs.less(rhs) && !rhs.less(lhs);
}

namespace std 
{
  template <> struct hash<S> {
    using argument_type = S;
    using result_type = size_t;

    result_type operator()(argument_type const& s) const noexcept {
      result_type const h1 = hash<string>{}(s.first_name);
      result_type const h2 = hash<string>{}(s.last_name);
#ifndef NOBOOST
      return h1 ^ (h2 << 1);
#else
    size_t seed = 0;
    boost::hash_combine(seed, h1);
    boost::hash_combine(seed, h2);
    return seed;
#endif
    }
  };
}

int
main() {
  set<S> x = {{"A", "B"}, {"C", "D"}};
  unordered_set<S> y = {{"A", "B"}, {"C", "D"}};

  cout << x.size() << " " << y.size() << endl;
}