#ifndef SIMPLE_TEST_RESOURCE_
#define SIMPLE_TEST_RESOURCE_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#if defined(EXPERIMENTAL)
#include <experimental/memory_resource>
#else
#include <memory_resource>
#endif

#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::find_if;

#if defined(EXPERIMENTAL)
using std::experimental::pmr::get_default_resource;
using std::experimental::pmr::memory_resource;
using std::experimental::pmr::polymorphic_allocator;
template <typename T>
using vector = std::vector<T, polymorphic_allocator<T>>;
#else
using std::pmr::get_default_resource;
using std::pmr::memory_resource;
using std::pmr::vector;
#endif

class test_resource : public memory_resource {
  struct allocation_rec {
    void *ptr_;
    size_t nbytes_, nalign_;
  };

  memory_resource *parent_;
  vector<allocation_rec> blocks_;

public:
  explicit test_resource(memory_resource *parent = 
                          get_default_resource()): 
    parent_(parent), blocks_(parent) {}

  memory_resource *parent() const { return parent_; }

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
    cout << "a: " << bytes << "\t to: " << ret << endl;
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

#endif
