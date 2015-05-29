#include <functional>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

template <typename T> struct tag {typedef T value_type;};

static struct viper_t:tag<int>{viper_t() {};} viper;
static struct hedgehog_t:tag<string>{hedgehog_t() {};} hedgehog;

template <typename U>
struct Field
{
  typename U::value_type storage;
  auto& operator^(const U&) { return storage; }
};

template < typename ...Fields >
struct ctmap_t : public Field <typename decay<Fields>::type>... {};

template <typename ...Fields>
decltype(auto) ctmap (Fields&&...) 
{ 
  ctmap_t<Fields...> ret;
  return ret; 
}

auto main() -> int
{
  auto couple = ctmap (viper, hedgehog);
  couple^viper = 50;
  couple^hedgehog = "abcdef"; 
  return 0;
}

