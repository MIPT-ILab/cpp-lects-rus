template <typename T> struct TD;

int main () {
  // TD<decltype("Hello, world!")> tType;
  decltype(auto) cstr = "Hello, world!";

  TD<decltype(cstr)> tType;
}
