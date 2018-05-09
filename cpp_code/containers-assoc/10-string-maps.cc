#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::forward;
using std::generate_n;
using std::list;
using std::make_pair;
using std::map;
using std::multimap;
using std::string;
using std::unordered_map;
using std::unordered_multimap;
using std::vector;

using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

template<typename F, typename ...Args>
auto duration(F&& func, Args&&... args) {
  auto start = steady_clock::now();
  forward<decltype(func)>(func)(forward<Args>(args)...);
  return duration_cast<milliseconds>(steady_clock::now() - start);
}

string random_string(size_t length)
{
  auto randchar = [] {
    const char charset[] = "abcde";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[ rand() % max_index ];
  };
  string str(length, 0);
  generate_n(str.begin(), length, randchar);
  return str;
}

// something like map or unordered map
template <typename T, size_t N>
auto do_test(int keylen, int valen) {
  // filling
  T x;
  for (size_t i = 0; i < N; ++i) {
    auto key = random_string(keylen);
    auto val = random_string(valen);
    if (x.find(key) != x.end()) {
      x[key].push_back(val);
    }
    else
      x[key] = {val};
  }

  // using: finding different keys and making all values identical
  for (size_t i = 0; i < N; ++i) {
    auto key = random_string(keylen);
    auto newval = random_string(valen);
    auto it = x.find(key);
    if (it != x.end())
      for (auto& val: it->second)
        val = newval;
  }

  return x;
}

// something like multimap or unordered multimap
template <typename T, size_t N>
auto do_m_test(int keylen, int valen) {
  // filling
  T x;
  for (size_t i = 0; i < N; ++i) {
    auto key = random_string(keylen);
    auto val = random_string(valen);
    x.insert({key, val});
  }

  // using: finding different keys and making all values identical
  for (size_t i = 0; i < N; ++i) {
    auto key = random_string(keylen);
    auto newval = random_string(valen);
    auto range = x.equal_range(key);
    for (auto itx = range.first; itx != range.second; ++itx)
      itx->second = newval;
  }

  return x;
}

int main()
{  
  // four tests: 
  // map key => [values]
  // multimap key => value
  // unordered_map key => [values]
  // unordered_multimap key => value

  constexpr size_t N = 80000;
  constexpr size_t KeyLen = 3;
  constexpr size_t VaLen = 19;

  cout << "maps: " << duration([]{do_test<map<string, list<string>>, N>(KeyLen, VaLen);}).count() << endl;
  cout << "mmaps: " << duration([]{do_m_test<multimap<string, string>, N>(KeyLen, VaLen);}).count() << endl;
  cout << "umaps: " << duration([]{do_test<unordered_map<string, list<string>>, N>(KeyLen, VaLen);}).count() << endl;
  cout << "ummaps: " << duration([]{do_m_test<unordered_multimap<string, string>, N>(KeyLen, VaLen);}).count() << endl;
  return 0;
}
