#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

struct resource {
  resource() {
    std::cout << "created" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  void use() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
};

std::atomic<resource *> resptr { nullptr };

resource *getres() {
  static resource *p = new resource(); // thread-local
  return p;
}

void foo() {
  resource *p = getres();
  p->use();
}

int
main() {
  std::thread t1{foo};
  std::thread t2{foo};
  std::thread t3{foo};
  std::thread t4{foo};

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

