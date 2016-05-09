template <typename T>
constexpr int somepred() {
  return 14;
}

template <>
constexpr int somepred<int>() {
  return 88;
}

template <typename T>
concept bool C1() {
  return somepred<T>() == 88; // somepred evaluated!
}

template <typename T>
concept bool C2() {
  return requires (T t) {
    somepred<T>() == 88; // somepred typechecked!
  };
}


bool foo (C1 x);
bool bar (C2 x);

int main () {
  foo (1); // ok for int
  // foo (1.0); // fail for double
  bar (1); // ok for int
  bar (1.0); // ok for double
}
