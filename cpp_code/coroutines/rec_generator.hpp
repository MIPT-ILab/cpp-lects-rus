#pragma once

#include <experimental/coroutine>
#include <utility>

template<typename T>
struct rec_generator {
  struct promise_type {
    struct awaitable {
      awaitable(promise_type* childp): child_(childp){}

      bool await_ready() { return child_ == nullptr; }
      void await_suspend(std::experimental::coroutine_handle<promise_type>){}
      void await_resume(){}

      promise_type* child_;
    };

    promise_type() : value_(nullptr), root_(this), leaf_(this){}

    promise_type(const promise_type&) = delete;
    promise_type(promise_type&&) = delete;

    auto get_return_object() noexcept { return rec_generator<T>{*this}; }
    auto initial_suspend() noexcept { return std::experimental::suspend_always{}; }
    auto final_suspend() noexcept { return std::experimental::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }
    void return_void() noexcept {}

    auto yield_value(T& value) noexcept {
      value_ = std::addressof(value);
      return std::experimental::suspend_always{};
    }

    auto yield_value(T&& value) noexcept {
      value_ = std::addressof(value);
      return std::experimental::suspend_always;
    }

    auto yield_value(rec_generator& generator) {
      if (generator.promise_ != nullptr) {
        root_->leaf_ = generator.promise_;
        generator.promise_->root_ = root_;
        generator.promise_->leaf_ = this;
        generator.promise_->resume();

        if (!generator.promise_->is_complete())
          return awaitable{ generator.promise_ };

        root_->leaf_ = this;
      }

      return awaitable{ nullptr };
    }

    // Don't allow any use of 'co_await' inside the rec_generator coroutine.
    template<typename U>
    std::experimental::suspend_never await_transform(U&& value) = delete;

    void destroy() noexcept {
      std::experimental::coroutine_handle<promise_type>::from_promise(*this).destroy();
    }

    bool is_complete() noexcept {
      return std::experimental::coroutine_handle<promise_type>::from_promise(*this).done();
    }

    T& value() noexcept {
      assert(this == root_);
      assert(!is_complete());
      return *(leaf_->value_);
    }

    void pull() noexcept {
      assert(this == root_);
      assert(!leaf_->is_complete());

      leaf_->resume();

      while (leaf_ != this && leaf_->is_complete()){
        leaf_ = leaf_->leaf_;
        leaf_->resume();
      }
    }

  private:
    void resume() noexcept {
      std::experimental::coroutine_handle<promise_type>::from_promise(*this).resume();
    }

    std::add_pointer_t<T> value_;
    promise_type* root_;
    promise_type* leaf_;
  };

  rec_generator() noexcept : promise_(nullptr) {}

  rec_generator(promise_type& promise) noexcept : promise_(&promise) {}

  rec_generator(rec_generator&& other) noexcept
    : promise_(other.promise_) {
    other.promise_ = nullptr;
  }

  rec_generator(const rec_generator& other) = delete;
  rec_generator& operator=(const rec_generator& other) = delete;

  ~rec_generator() {
    if (promise_ != nullptr)
      promise_->destroy();
  }

  rec_generator& operator=(rec_generator&& other) noexcept {
    if (this == &other)
      return *this;
    
    if (promise_ != nullptr)
      promise_->destroy();

    promise_ = other.promise_;
    other.promise_ = nullptr;
  }
  
  T value() { return promise_->value(); }
  
  bool next() {
    promise_->pull();
    if (promise_->is_complete())
      return false;
    return true;    
  }
  
  void swap(rec_generator& other) noexcept {
    std::swap(promise_, other.promise_);
  }

private:
  promise_type* promise_;
};
