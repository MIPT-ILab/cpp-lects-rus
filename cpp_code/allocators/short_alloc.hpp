#ifndef SHORT_ALLOC_H
#define SHORT_ALLOC_H

// The MIT License (MIT)
// 
// Copyright (c) 2015 Howard Hinnant
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstddef>
#include <cassert>

using std::size_t;
using std::max_align_t;

template <size_t N, size_t alignment = alignof(max_align_t)>
class arena
{
  char buf_[N] alignas(alignment);
  char* ptr_;

public:
  ~arena() {ptr_ = nullptr;}
  arena() noexcept : ptr_(buf_) {}
  arena(const arena&) = delete;
  arena& operator=(const arena&) = delete;

  template <size_t ReqAlign> char* allocate(size_t n);
  void deallocate(char* p, size_t n) noexcept;

  static constexpr size_t size() noexcept {return N;}
  size_t used() const noexcept { 
    return static_cast<size_t>(ptr_ - buf_);
  }

  void reset() noexcept { ptr_ = buf_; }

private:
  static size_t align_up(size_t n) noexcept {
    return (n + (alignment-1)) & ~(alignment-1);
  }

  bool pointer_in_buffer(char* p) noexcept {
    return ((buf_ <= p) && (p <= buf_ + N));
  }
};

template <size_t N, size_t alignment>
template <size_t ReqAlign>
char *arena<N, alignment>::allocate(size_t n) {
  static_assert(ReqAlign <= alignment, "alignment is too small for this arena");
  assert(pointer_in_buffer(ptr_) && "short_alloc has outlived arena");
  auto const aligned_n = align_up(n);
  if (static_cast<decltype(aligned_n)>(buf_ + N - ptr_) >= aligned_n) {
    char* r = ptr_;
    ptr_ += aligned_n;
    return r;
  }

  static_assert(alignment <= alignof(max_align_t), "you've chosen an "
                "alignment that is larger than alignof(max_align_t), and "
                "cannot be guaranteed by normal operator new");
  return static_cast<char*>(::operator new(n));
}

template <size_t N, size_t alignment>
void arena<N, alignment>::deallocate(char* p, size_t n) noexcept {
  assert(pointer_in_buffer(ptr_) && "short_alloc has outlived arena");
  if (!pointer_in_buffer(p))
    ::operator delete(p);

  n = align_up(n);
  if (p + n == ptr_)
    ptr_ = p;
}

template <class T, size_t N, size_t Align = alignof(max_align_t)>
class short_alloc
{
public:
  using value_type = T;
  static auto constexpr alignment = Align;
  static auto constexpr size = N;
  using arena_type = arena<size, alignment>;

private:
  arena_type& a_;

public:
  short_alloc(const short_alloc&) = default;
  short_alloc& operator=(const short_alloc&) = delete;

  short_alloc(arena_type& a) noexcept : a_(a) {
    static_assert(size % alignment == 0,
                  "size N needs to be a multiple of alignment Align");
  }

  const arena_type& arena() const { return a_; }

  template <class U>
  short_alloc(const short_alloc<U, N, alignment>& a) noexcept : a_(a.arena()) {}

  template <class Up> 
  struct rebind { using other = short_alloc<Up, N, alignment>; };

  T* allocate(size_t n) {
    char *res = a_.template allocate<alignof(T)>(n * sizeof(T));
    return reinterpret_cast<T*>(res);
  }

  void deallocate(T* p, size_t n) noexcept {
    a_.deallocate(reinterpret_cast<char*>(p), n * sizeof(T));
  }

  template <class U, size_t M, size_t A2>
  bool equals(const short_alloc<U, M, A2>& rhs) noexcept {
    return N == M && Align == A2 && &a_ == &rhs.arena();
  }
};

namespace {

template <class T, size_t N, size_t A1, class U, size_t M, size_t A2>
bool operator==(const short_alloc<T, N, A1>& x, 
                const short_alloc<U, M, A2>& y) noexcept
{
  return x.equals(y);
}

template <class T, size_t N, size_t A1, class U, size_t M, size_t A2>
bool operator!=(const short_alloc<T, N, A1>& x, 
                const short_alloc<U, M, A2>& y) noexcept
{
  return !(x == y);
}

}

#endif  // SHORT_ALLOC_H