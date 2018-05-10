//------------------------------------------------------------------------------
//
// Tests for permutation loops
//
//------------------------------------------------------------------------------

#include <chrono>
#include <iterator>

#include "idomain.hpp"
#include "permloops.hpp"
#include "perms.hpp"
#include "groups.hpp"

using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

template<typename F, typename ...Args>
auto duration(F&& func, Args&&... args) {
  auto start = steady_clock::now();
  forward<decltype(func)>(func)(forward<Args>(args)...);
  return duration_cast<milliseconds>(steady_clock::now() - start);
}

auto
test_simple_orbit() {
  using UD100 = UnsignedDomain<1, 100>;
  UD100 selt = 3;
  vector<UD100> init(100);
  iota(init.begin(), init.end(), 1);
  PermLoop<UD100> cyclic(init.begin(), init.end());
  vector<Permutation<UD100>> sgens {{cyclic}, {{1, 2}}};
  auto sv = s_orbit_vectors(selt, sgens.begin(), sgens.end());  
  auto ss = s_orbit_sets(selt, sgens.begin(), sgens.end());
  assert (ss.size() == sv.size());
  assert (ss.size() == 100);

  bool is_equal = equal(sv.begin(), sv.end(), ss.begin());
  assert (is_equal);

  auto su = s_orbit_usets(selt, sgens.begin(), sgens.end());

  // this will fail:
  // is_equal = equal(su.begin(), su.end(), ss.begin());
  // assert (is_equal);

  assert (su.size() == sv.size());
  for (auto x : su)
    assert(ss.count(x) != 0);

  auto os = orbit_sets(selt, sgens.begin(), sgens.end());

  // note: this not work!
  // assert (os.size() == om.size());

  auto om = orbit_maps(selt, sgens.begin(), sgens.end());
  auto um = orbit_umaps(selt, sgens.begin(), sgens.end());

  assert (om.size() == 100);
  assert (om.size() == um.size());

  return 0;
}

template <size_t N> auto
test_perf_sorbit_vecs() {
  using UD = UnsignedDomain<1, N>;
  UD selt = 3;
  vector<UD> init(N);
  iota(init.begin(), init.end(), 1);
  PermLoop<UD> cyclic(init.begin(), init.end());
  vector<Permutation<UD>> sgens {{cyclic}, {{1, 2}}};
  auto sv = s_orbit_vectors(selt, sgens.begin(), sgens.end());  
  return sv.size();
}

template <size_t N> auto
test_perf_sorbit_sets() {
  using UD = UnsignedDomain<1, N>;
  UD selt = 3;
  vector<UD> init(N);
  iota(init.begin(), init.end(), 1);
  PermLoop<UD> cyclic(init.begin(), init.end());
  vector<Permutation<UD>> sgens {{cyclic}, {{1, 2}}};
  auto sv = s_orbit_sets(selt, sgens.begin(), sgens.end());  
  return sv.size();
}

template <size_t N> auto
test_perf_sorbit_usets() {
  using UD = UnsignedDomain<1, N>;
  UD selt = 3;
  vector<UD> init(N);
  iota(init.begin(), init.end(), 1);
  PermLoop<UD> cyclic(init.begin(), init.end());
  vector<Permutation<UD>> sgens {{cyclic}, {{1, 2}}};
  auto sv = s_orbit_usets(selt, sgens.begin(), sgens.end());  
  return sv.size();
}

template <size_t N> auto
test_perf_orbit_maps() {
  using UD = UnsignedDomain<1, N>;
  UD selt = 3;
  vector<UD> init(N);
  iota(init.begin(), init.end(), 1);
  PermLoop<UD> cyclic(init.begin(), init.end());
  vector<Permutation<UD>> sgens {{cyclic}, {{1, 2}}};
  auto sv = orbit_maps(selt, sgens.begin(), sgens.end());  
  return sv.size();
}

template <size_t N> auto
test_perf_orbit_umaps() {
  using UD = UnsignedDomain<1, N>;
  UD selt = 3;
  vector<UD> init(N);
  iota(init.begin(), init.end(), 1);
  PermLoop<UD> cyclic(init.begin(), init.end());
  vector<Permutation<UD>> sgens {{cyclic}, {{1, 2}}};
  auto sv = orbit_umaps(selt, sgens.begin(), sgens.end(), N);  
  return sv.size();
}

int
main()
{
  // test correctness and warmup things
  test_simple_orbit();

#ifdef SIMPLE
  cout << "vectors: ";
  auto dv = duration([]{test_perf_sorbit_vecs<10000>();});
  cout << dv.count() << endl;
  cout << "sets: ";
  auto ds = duration([]{test_perf_sorbit_sets<10000>();});
  cout << ds.count() << endl;
#ifdef UNORD
  cout << "usets: ";
  auto du = duration([]{test_perf_sorbit_usets<10000>();});
  cout << du.count() << endl;
#endif
#endif

#ifdef FULL
  cout << "maps (orbit + generators): ";
  auto dm = duration([]{test_perf_orbit_maps<2000>();});
  cout << dm.count() << endl;
  cout << "umaps (orbit + generators): ";
  auto dum = duration([]{test_perf_orbit_umaps<2000>();});
  cout << dum.count() << endl;
#endif
}
