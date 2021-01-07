constexpr void g(bool b) { if (b) throw; }

// ill-formed, no diagnostic required by [dcl.constexpr]
constexpr int f() { g(true); return 0; }

template <int N> struct S {};

int main() {
  // S<f()> s; // trigger hidden bug
}