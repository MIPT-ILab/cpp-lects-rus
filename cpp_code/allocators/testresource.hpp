#ifndef SIMPLE_TEST_RESOURCE_
#define SIMPLE_TEST_RESOURCE_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <experimental/memory_resource>
#include <experimental/string>
#include <experimental/vector>

using std::cout;
using std::endl;
using std::find_if;

using namespace std::experimental;

class test_resource : public pmr::memory_resource {
  struct allocation_rec {
    void *ptr_;
    size_t nbytes_, nalign_;
  };

  pmr::memory_resource *parent_;
  pmr::vector<allocation_rec> blocks_;

public:
  explicit test_resource(memory_resource *parent = pmr::get_default_resource()): 
    parent_(parent), blocks_(parent) {}

  pmr::memory_resource *parent() const { return parent_; }

  ~test_resource() {
    cout << "leaked " <<  blocks_.size() << " blocks" << endl;
    for (auto &&b : blocks_) {
      cout << "\t ptr:" << b.ptr_ << endl;
      parent_->deallocate(b.ptr_, b.nbytes_, b.nalign_);
    }
  }

protected:
  void *do_allocate(size_t bytes, size_t alignment) override {
    void *ret = parent_->allocate(bytes, alignment);
    cout << "a: " << bytes << " to: " << ret << endl;
    blocks_.push_back(allocation_rec{ret, bytes, alignment});
    return ret;
  }

  void do_deallocate(void *p, size_t bytes, size_t alignment) override {
    auto i = find_if(blocks_.begin(), blocks_.end(),
                      [p](const allocation_rec& r){ return r.ptr_ == p; });
    if (i == blocks_.end())
      throw std::invalid_argument("deallocate: Invalid pointer");    
    blocks_.erase(i);
    parent_->deallocate(p, bytes, alignment);
  }

  bool do_is_equal(const memory_resource& other) const noexcept override {
    return this == &other;
  }
};

namespace std _GLIBCXX_VISIBILITY(default)
{
namespace experimental
{
inline namespace fundamentals_v2
{
namespace pmr {
  using string = ::std::basic_string<char, std::char_traits<char>, pmr::polymorphic_allocator<char>>;
}
}
}
}

#endif
