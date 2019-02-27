// by V. Mustya

#include <atomic>
#include <cassert>
#include <thread>

volatile unsigned __attribute__((aligned (256))) a { 1 };
std::atomic<unsigned> __attribute__((aligned (256))) b { 1 };

extern "C"
void updateboth() {
  while (a) {
    a += 1;
    unsigned bl = b.load(std::memory_order_relaxed);
    bl += 1;
    b.store(bl, std::memory_order_release);
  }
}

extern "C"
void readboth() {
  unsigned al, bl;
  do {
    bl = b.load(std::memory_order_acquire);
    al = a;

    assert(bl <= al);
  } while (bl);
}

int main() {
  std::thread reader(readboth);
  std::thread updater(updateboth);

  reader.join();
  updater.join();

  return 0;
}

