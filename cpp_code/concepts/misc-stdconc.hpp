#include <utility>

template <class From, class To>
concept bool ConvertibleTo =
  std::is_convertible<From, To>::value &&
  requires(From (&f)()) {
    static_cast<To>(f());
  };

template < class T >
concept bool Destructible = std::is_nothrow_destructible<T>::value;

template < class T, class... Args >
concept bool Constructible =
  Destructible<T> && std::is_constructible<T, Args...>::value;

template < class T >
concept bool DefaultConstructible = Constructible<T>;

template < class T >
concept bool MoveConstructible =
  Constructible<T, T> && ConvertibleTo<T, T>;

template <class T>
concept bool CopyConstructible =
  MoveConstructible<T> &&
  Constructible<T, T&> && ConvertibleTo<T&, T> &&
  Constructible<T, const T&> && ConvertibleTo<const T&, T> &&
  Constructible<T, const T> && ConvertibleTo<const T, T>;

template< class T >
concept bool Swappable =
  requires(T& a, T& b) {
    std::swap(a, b);
  };
  
template< class T, class U >
concept bool SwappableWith =
  CommonReference<
    const std::remove_reference_t<T>&,
    const std::remove_reference_t<U>&> &&
  requires(T&& t, U&& u) {
    std::swap(std::forward<T>(t), std::forward<T>(t));
    std::swap(std::forward<U>(u), std::forward<U>(u));
    std::swap(std::forward<T>(t), std::forward<U>(u));
    std::swap(std::forward<U>(u), std::forward<T>(t));
  };  

template < class T, class U >
concept bool Assignable =
  std::is_lvalue_reference<T>::value &&
  CommonReference<
    const std::remove_reference_t<T>&,
    const std::remove_reference_t<U>&> &&
  requires(T t, U&& u) {
    { t = std::forward<U>(u) } -> Same<T>&&;
  };

template < class T >
concept bool Movable =
  std::is_object<T>::value &&
  MoveConstructible<T> &&
  Assignable<T&, T> &&
  Swappable<T>;

template <class T>
concept bool Copyable =
  CopyConstructible<T> &&
  Movable<T> &&
  Assignable<T&, const T&>;

template <class T>
concept bool Semiregular = Copyable<T> && DefaultConstructible<T>;

template <class T, class U>
concept bool WeaklyEqualityComparableWith =
  requires(const std::remove_reference_t<T>& t,
           const std::remove_reference_t<U>& u) {
    { t == u } -> Boolean&&;
    { t != u } -> Boolean&&;
    { u == t } -> Boolean&&;
    { u != t } -> Boolean&&;
  };

template < class T >
concept bool EqualityComparable = WeaklyEqualityComparableWith<T, T>;

template <class T>
concept bool StrictTotallyOrdered =
  EqualityComparable<T> &&
  requires(const std::remove_reference_t<T>& a,
           const std::remove_reference_t<T>& b) {
    { a < b }  -> Boolean&&;
    { a > b }  -> Boolean&&;
    { a <= b } -> Boolean&&;
    { a >= b } -> Boolean&&;
  };

template <class I>
concept bool WeaklyIncrementable =
  Semiregular<I> &&
  requires(I i) {
    typename ranges::difference_type_t<I>;
    requires SignedIntegral<ranges::difference_type_t<I>>;
    { ++i } -> Same<I>&; /* not required to be equality preserving */
    i++; /* not required to be equality preserving */
  };

template <class I>
concept bool Iterator =
  requires(I i) {
    { *i } -> auto&&; // Requires: i is dereferenceable
  } &&
  WeaklyIncrementable<I>;  

template < class I >
concept bool InputIterator =
  Iterator<I> && Readable<I> &&
  requires { typename ranges::iterator_category_t<I>; } &&
  DerivedFrom<ranges::iterator_category_t<I>, ranges::input_iterator_tag>;

template < class I >
concept bool ForwardIterator =
  InputIterator<I> &&
  DerivedFrom<ranges::iterator_category_t<I>, ranges::forward_iterator_tag> &&
  Incrementable<I> &&
  Sentinel<I, I>;
