#include <iostream>
#include <mutex>
#include <thread>

struct resource {
  resource() {
    std::cout << "c";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  void use() {
    std::cout << "u";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
};

resource *resptr;
std::once_flag resflag;

void init_resource() { resptr = new resource(); }

void foo() {
  std::call_once(resflag, init_resource);
  resptr->use();
}

int main() {
  std::thread t1{foo};
  std::thread t2{foo};
  std::thread t3{foo};
  std::thread t4{foo};

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << "\n";
}
