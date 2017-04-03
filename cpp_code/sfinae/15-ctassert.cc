template <bool cond> struct CT_ASSERT;
template <> struct CT_ASSERT<true> {};


int main () {
  CT_ASSERT <sizeof(int) == 6> {};
}
