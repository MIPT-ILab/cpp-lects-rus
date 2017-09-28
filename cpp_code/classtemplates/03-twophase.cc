template <typename T> struct Foo {
#ifdef BUG
  int use () { return illegal_name; } 
#else
  int use () { return T::illegal_name; } 
#endif
};

