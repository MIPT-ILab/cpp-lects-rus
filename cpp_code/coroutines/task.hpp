// ref from https://abseil.io/blog/20180713-coroutine-types

template <typename T = void>
struct [[nodiscard]] task {
  struct promise_type {
    variant<monostate, T, exception_ptr> result;
    coroutine_handle<> waiter; // who waits on this coroutine
    
    auto get_return_object() { return task{*this}; }
    void return_value(T value) { result.template emplace<1>(std::move(value)); }
    void unhandled_exception() { result.template emplace<2>(std::current_exception()); }
    suspend_always initial_suspend() { return {}; }
    auto final_suspend() {
      struct final_awaiter {
        bool await_ready() { return false; }
        void await_resume() {}
        auto await_suspend(coroutine_handle<promise_type> me) {
          return me.promise().waiter;
        }
      };
      return final_awaiter{};
    }
  };
  
  task(task&& rhs) : h(rhs.h) { rhs.h = nullptr; }
  ~task() { if (h) h.destroy(); }
  explicit task(promise_type& p) : h(coroutine_handle<promise_type>::from_promise(p)) {}
  
  bool await_ready() { return false; }
  T await_resume() {  
    auto& result = h.promise().result;
    if (result.index() == 1) return get<1>(result);
    rethrow_exception(get<2>(result));
  }
  void await_suspend(coroutine_handle<> waiter) {
    h.promise().waiter = waiter;
    h.resume();
  }
  auto _secret() { return h; } // to help sync_await
  
private:
  coroutine_handle<promise_type> h;
};
