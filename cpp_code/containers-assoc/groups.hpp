//------------------------------------------------------------------------------
//
//  Group theoretical algorithms
//
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------

#include "perms.hpp"

// simple orbit, using sorted vectors
template<typename T, typename RandIt>
auto s_orbit_vectors(T num, RandIt gensbeg, RandIt gensend) {
  vector<T> orbit, next = {num};
  while (!next.empty()) {
    vector<T> tmp {};
    orbit.insert(orbit.end(), next.begin(), next.end());
    sort(orbit.begin(), orbit.end());
    for (const auto &elem : next)
      for (auto igen = gensbeg; igen != gensend; ++igen)
        if (auto newelem = igen->apply(elem); 
            !binary_search(orbit.begin(), orbit.end(), newelem))
          tmp.push_back(newelem);
    next.swap(tmp);
  }
  orbit.erase(unique(orbit.begin(), orbit.end()), orbit.end());
  return orbit;
}

// simple orbit, using sets
template<typename T, typename RandIt>
auto s_orbit_sets(T num, RandIt gensbeg, RandIt gensend) {
  set<T> orbit, next = {num};
  while (!next.empty()) {
    set<T> tmp {};
    orbit.insert(next.begin(), next.end());
    for (const auto &elem : next)
      for (auto igen = gensbeg; igen != gensend; ++igen)
        if (auto newelem = igen->apply(elem); orbit.count(newelem) == 0)
          tmp.insert(newelem);        
    next.swap(tmp);
  }
  return orbit;
}

// simple orbit, using unordered sets
template<typename T, typename RandIt>
auto s_orbit_usets(T num, RandIt gensbeg, RandIt gensend) {
  // note: T::type!
  unordered_set<typename T::type> orbit, next = {num};
  while (!next.empty()) {
    unordered_set<typename T::type> tmp {};
    orbit.insert(next.begin(), next.end());
    for (const auto &elem : next)
      for (auto igen = gensbeg; igen != gensend; ++igen)
        if (auto newelem = igen->apply(elem); orbit.count(newelem) == 0)
          tmp.insert(newelem);        
    next.swap(tmp);
  }
  return orbit;
}

// orbit with reps, using sets
template<typename T, typename RandIt>
auto orbit_sets(T num, RandIt gensbeg, RandIt gensend) {
  set<pair<T, Permutation<T>>> orbit;
  Permutation<T> id {};
  set<pair<T, Permutation<T>>> next {{num, id}};
  while (!next.empty()) {
    set<pair<T, Permutation<T>>> tmp {};
    orbit.insert(next.begin(), next.end());
    for (auto&& [elem, curgen] : next)
      for (auto igen = gensbeg; igen != gensend; ++igen)
        if (auto newelem = igen->apply(elem);
            find_if(orbit.begin(), orbit.end(), 
             [newelem](auto&& elt) { return (newelem == elt.first); }) == orbit.end())
          tmp.emplace(newelem, product(curgen, *igen));
    next.swap(tmp);
  }
  return orbit;
}

// orbit with reps, using maps
template<typename T, typename RandIt>
auto orbit_maps(T num, RandIt gensbeg, RandIt gensend) {
  map<T, Permutation<T>> orbit, next {{ num, {} }};
  while (!next.empty()) {
    map<T, Permutation<T>> tmp {};
    orbit.insert(next.begin(), next.end());
    for (auto&& [elem, curgen] : next)
      for (auto igen = gensbeg; igen != gensend; ++igen)
        if (auto newelem = igen->apply(elem); orbit.find(newelem) == orbit.end())
          tmp.try_emplace(igen->apply(elem), product(curgen, *igen));
    next.swap(tmp);
  }
  return orbit;
}

// orbit with reps, using unordered maps
template<typename T, typename RandIt>
auto orbit_umaps(T num, RandIt gensbeg, RandIt gensend, size_t to_reserve = 0) {
  // note: T::type
  unordered_map<typename T::type, Permutation<T>> orbit, next {{ num, {} }};
  if (to_reserve)
    orbit.reserve(to_reserve);
  while (!next.empty()) {
    unordered_map<typename T::type, Permutation<T>> tmp {};
    orbit.insert(next.begin(), next.end());
    for (auto&& [elem, curgen] : next)
      for (auto igen = gensbeg; igen != gensend; ++igen)
        if (auto newelem = igen->apply(elem); orbit.find(newelem) == orbit.end())
          tmp.try_emplace(newelem, product(curgen, *igen));
    next.swap(tmp);
  }

#if 0
  cout << "Umap technical info:" << endl;
  cout << orbit.bucket_count() << endl;
  cout << orbit.load_factor() << endl;
#endif
  return orbit;
}
