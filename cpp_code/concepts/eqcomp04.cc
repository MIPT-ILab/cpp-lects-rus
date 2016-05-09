// overconstrained case

template <typename T, typename U>
concept bool Equality_comparable() {
  return requires(T t, U u) {
    {t == u} -> bool;
    {u == t} -> bool;
    {t != u} -> bool;
    {u != t} -> bool; 
  };
}

template <typename T, typename U>
requires Equality_comparable<T, U>()
bool check (T&& lhs, U&& rhs);

struct Test {
  bool operator== (Test);
};

bool foo (Test x, Test y) {
  return check(x, y);
}

