template <typename T, typename U>
concept bool Weak_equality_comparable() {
  return requires(T t, U u) {
    {t == u} -> bool;
  };
}

template <typename T, typename U = T>
concept bool Equality_comparable() {
  return Weak_equality_comparable<T, U>() &&
         Weak_equality_comparable<U, T>();
}

template <typename T>
requires Equality_comparable<T>()
bool check(T, T);

