#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;

int main () {
  thread t([](){ cout << "Hello, world!" << endl; });
#if defined(JOIN)
  t.join();
#elif defined(DETACH)
  t.detach();
#else
#warning "use -DJOIN or -DDETACH or you will have problems"
#endif
  return 0;
}

