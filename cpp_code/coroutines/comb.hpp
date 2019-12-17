//------------------------------------------------------------------------------
//
// this file implements all combinations from 0 .. n-1 of t
// usage (combinations of 3 from 0..4):
//
//  all_comb ac(5, 3);
//  do {
//    for (auto it = ac.begin(); it != ac.end(); ++it)
//      std::cout << *it << " ";
//    std::cout << std::endl;
//  } while (ac.nexcomblen_comb());
//
// output:
// 0 1 2
// 0 2 3
// ... etc ...
//
// Details may be found in Knuth, algorithm R from 7.2.1.3 (vol 4A)
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#pragma once

#include <cassert>
#include <numeric>
#include <vector>

class all_comb {
  std::vector<int> combination_;
  int total_;

public:
  auto begin() { return combination_.begin(); }
  auto end() { return std::prev(combination_.end()); }

  all_comb(int n, int t) : combination_(t + 1), total_(n) {
    assert(n > 0 && "Makes no sense to combine things out of nothing");
    assert(t > 0 && "Makes no sense to combine zero number of things");
    assert(n > t && "Makes no sense to have n <= t");
    reinit();
  }

  void reinit() {
    std::iota(combination_.begin(), combination_.end(), 0);
    combination_.back() = total_;
  }

  bool next_comb() {
    bool skipr4 = false;
    int comblen_ = combination_.size() - 1;

    if ((comblen_ % 2) == 1) {
      if (combination_[0] + 1 < combination_[1]) {
        combination_[0] += 1;
        return true;
      }
    } else {
      if (combination_[0] > 0) {
        combination_[0] -= 1;
        return true;
      }
      skipr4 = true;
    }

    int j = 2;

    for (;;) {
      // step R4
      if (!skipr4) {
        assert(combination_[j - 1] == combination_[j - 2] + 1);
        if (combination_[j - 1] >= j) {
          combination_[j - 1] = combination_[j - 2];
          combination_[j - 2] = j - 2;
          break;
        }
        j += 1;
      }

      // step R5
      assert(combination_[j - 2] == j - 2);
      if (combination_[j - 1] + 1 < combination_[j]) {
        combination_[j - 2] = combination_[j - 1];
        combination_[j - 1] += 1;
        break;
      }

      j += 1;
      if (j > comblen_) {
        reinit();
        return false;
      }
      skipr4 = false;
    }
    return true;
  }
};
