//------------------------------------------------------------------------------
//
//  Group theoretical algorithms
//
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------

#include "perms.hpp"

#define SHOWCOSETREPS

// HCGT, page 78. Simplest and far from ideal orbit calculation
template<typename T, typename RandIt>
set<T> simple_orbit(T num, RandIt gensbeg, RandIt gensend) {
  set<T> orbit;
  set<T> next = {num};
  map<T, Permutation<T>> reps;
  Permutation<T> id {};
  reps[num] = id;

  while (!next.empty()) {
    set<T> tmp {};
    orbit.insert(next.begin(), next.end());
    for (const auto &elem : next)
      for (auto igen = gensbeg; igen != gensend; ++igen) {
        auto newelem = igen->apply(elem); // elem ^ gen
        if (orbit.count(newelem) == 0) {
          tmp.insert(newelem);
          reps[newelem] = product(reps[elem], *igen); // T[delta] * gen
        }
      }
    next.swap(tmp);
  }

#ifdef SHOWCOSETREPS
  cout << "Coset representatives:" << endl;
  for (auto &&g : reps)
    cout << g.first << ": " << g.second << endl;
#endif

  return orbit;
}

// orbit, using pure vectors
template<typename T, typename RandIt>
vector<T> orbit0(T num, RandIt gensbeg, RandIt gensend) {
  vector<T> orbit;
  vector<T> next = {num};
  while (!next.empty()) {
    vector<T> tmp {};
    orbit.insert(orbit.end(), next.begin(), next.end());
    for (const auto &elem : next)
      for (auto igen = gensbeg; igen != gensend; ++igen) {
        auto newelem = igen->apply(elem); // elem ^ gen
        if (find(orbit.begin(), orbit.end(), newelem) == orbit.end())
          tmp.push_back(newelem);
      }
    next.swap(tmp);
  }
  return orbit;
}

// orbit, using pure vectors and sorted orbit
template<typename T, typename RandIt>
vector<T> orbit1(T num, RandIt gensbeg, RandIt gensend) {
  vector<T> orbit;
  vector<T> next = {num};
  while (!next.empty()) {
    vector<T> tmp {};
    orbit.insert(orbit.end(), next.begin(), next.end());
    sort(orbit.begin(), orbit.end());
    for (const auto &elem : next)
      for (auto igen = gensbeg; igen != gensend; ++igen) {
        auto newelem = igen->apply(elem); // elem ^ gen
        if (!binary_search(orbit.begin(), orbit.end(), newelem))
          tmp.push_back(newelem);        
      }
    next.swap(tmp);
  }
  return orbit;
}

// orbit, using sets
template<typename T, typename RandIt>
set<T> orbit2(T num, RandIt gensbeg, RandIt gensend) {
  set<T> orbit;
  vector<T> next = {num};
  while (!next.empty()) {
    vector<T> tmp {};
    orbit.insert(next.begin(), next.end());
    for (const auto &elem : next)
      for (auto igen = gensbeg; igen != gensend; ++igen) {
        auto newelem = igen->apply(elem); // elem ^ gen
        if (orbit.count(newelem) == 0)
          tmp.push_back(newelem);        
      }
    next.swap(tmp);
  }
  return orbit;
}

// orbit, using sets
template<typename T, typename RandIt>
set<pair<T, Permutation<T>>> orbit3(T num, RandIt gensbeg, RandIt gensend) {
  set<pair<T, Permutation<T>>> orbit;
  Permutation<T> id {};
  vector<pair<T, Permutation<T>>> next {make_pair(num, id)};
  while (!next.empty()) {
    vector<pair<T, Permutation<T>>> tmp {};
    orbit.insert(next.begin(), next.end());
    for (auto&& [elem, curgen] : next)
      for (auto igen = gensbeg; igen != gensend; ++igen) {
        auto newelem = igen->apply(elem); // elem ^ gen
        if (find_if(orbit.begin(), orbit.end(), 
             [newelem](auto&& elt) { return (newelem == elt.first); }) == orbit.end()) {
          auto newgen = product(curgen, *igen);
          tmp.push_back(make_pair(newelem, newgen));       
        } 
      }
    next.swap(tmp);
  }
  return orbit;
}
