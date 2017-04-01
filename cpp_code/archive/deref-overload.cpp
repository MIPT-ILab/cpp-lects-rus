struct T {
  int x = 5;
  int foo (void) { return x; }
};

class Tptr {
  T *t_;
public:
  Tptr(T *rhs) : t_(rhs) {};
  T operator*() const { return *t_; }
  T* operator->() const { return t_; }
};

int
main (void) {
  T t;
  Tptr pt(&t);

  pt->x = 6;
  (*pt).foo();
  return 0;  
}

