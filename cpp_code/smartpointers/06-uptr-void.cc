#include <memory>

using std::unique_ptr;

template <typename T>
struct VDel {
  void operator()(void *s) { delete static_cast<T*>(s); }
};

int
main ()
{
  unique_ptr<void, VDel<int>> u(new int(42));
}


