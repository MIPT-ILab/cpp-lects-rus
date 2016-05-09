// 1. expression

template <typename T> 
requires requires (T a, T b) { 
           a + b; 
         }
T test1 (T, T);

template <typename T>
requires requires() {
           typename T::inner;
         }
T test2 (T, T);

template <typename T>
requires requires(T x) {
           {*x} -> typename T::inner;
         }
T test3 (T, T);

template <typename T>
requires requires(T x) {
           {*x} -> typename T::inner;
         } &&
         requires() {
           typename T::inner;
         } &&
         requires (T a, T b) {
           a + b;
         }
T test4 (T, T);


struct HasInner {
  using inner = int;
};

struct HasDeref {
  using inner = int;
  inner operator*();
};

struct HasPlus {
  using inner = int;
  inner operator*();
  void operator+(HasPlus x);
};

int
main (void) {
  test1(1, 1);
  // test1(HasInner{}, HasInner{}); // no +
  test2(HasInner{}, HasInner{});
  // test2(1, 1); // no inner
  test3(HasDeref{}, HasDeref{});
  // test3(HasInner{}, HasInner{}); // no deref
  test4(HasPlus{}, HasPlus{});
  // test4(HasDeref{}, HasDeref{});
}
