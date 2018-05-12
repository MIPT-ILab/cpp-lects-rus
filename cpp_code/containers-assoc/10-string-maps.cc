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

#ifdef USE_BOOST
#include <boost/container/flat_map.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/list_of.hpp>

using boost::container::flat_map;
using namespace boost::bimaps;
#endif


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
auto duration(F&& func, Args&&... args) 
{
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

template <typename T, size_t N, size_t M>
auto do_basic_map_test(int keylen, int valen) 
{
  // filling
  T x;
  for (size_t i = 0; i < N; ++i) {
    auto key = random_string(keylen);
    auto val = random_string(valen);
    x.insert(make_pair(key, val));
  }

  // using: find keys and change values
  for (size_t i = 0; i < M; ++i) {
    auto key = random_string(keylen);
    auto it = x.find(key);
    if (it != x.end())
      it->second = random_string(valen);
  }

  return x.size();
}

template <typename T, size_t N, size_t M>
auto do_basic_bimap_test(int keylen, int valen) 
{
  // filling
  T x;
  for (size_t i = 0; i < N; ++i) {
    auto key = random_string(keylen);
    auto val = random_string(valen);
    x.left.insert(make_pair(key, val));
  }

  // using: find keys and change values
  for (size_t i = 0; i < M; ++i) {
    auto key = random_string(keylen);
    auto it = x.left.find(key);
    if (it != x.left.end())
      it->second = random_string(valen);
  }

  return x.size();
}

// something like map or unordered map
template <typename T, size_t N>
auto do_test(int keylen, int valen) 
{
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

  return x.size();
}

// something like multimap or unordered multimap
template <typename T, size_t N>
auto do_m_test(int keylen, int valen) 
{
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

  return x.size();
}

int
bench1() {
  // tests for {something like map} string -> string
  constexpr size_t N = 100000;
  constexpr size_t M = 10000000;
  constexpr size_t KeyLen = 3;
  constexpr size_t VaLen = 19;

  cout << "bench 1: maps vs unrodered_maps" << endl;
  cout << "maps: " << duration([]{do_basic_map_test<map<string, string>, N, M>(KeyLen, VaLen);}).count() << endl;
  cout << "umaps: " << duration([]{do_basic_map_test<unordered_map<string, string>, N, M>(KeyLen, VaLen);}).count() << endl;
#ifdef USE_BOOST
  cout << "fmaps: " << duration([]{do_basic_map_test<flat_map<string, string>, N, M>(KeyLen, VaLen);}).count() << endl;
  cout << "bimaps: " << duration([]{do_basic_bimap_test<bimap<set_of<string>, list_of<string>>, N, M>(KeyLen, VaLen);}).count() << endl;
#endif
  return 0;
}

int
bench2() 
{
  // four tests: 
  // map key => [values]
  // multimap key => value
  // unordered_map key => [values]
  // unordered_multimap key => value

  constexpr size_t N = 80000;
  constexpr size_t KeyLen = 3;
  constexpr size_t VaLen = 19;

  cout << "bench 2: maps vs multimaps" << endl;
  cout << "maps: " << duration([]{do_test<map<string, vector<string>>, N>(KeyLen, VaLen);}).count() << endl;
  cout << "mmaps: " << duration([]{do_m_test<multimap<string, string>, N>(KeyLen, VaLen);}).count() << endl;
  cout << "umaps: " << duration([]{do_test<unordered_map<string, vector<string>>, N>(KeyLen, VaLen);}).count() << endl;
  cout << "ummaps: " << duration([]{do_m_test<unordered_multimap<string, string>, N>(KeyLen, VaLen);}).count() << endl;
  return 0;
}

int main() 
{  
  // some cache warmup
  do_basic_map_test<map<string, string>, 10000, 10000>(3, 19);
#ifdef BENCH1
  bench1();
#endif
#ifdef BENCH2
  bench2();
#endif
  return 0;
}
