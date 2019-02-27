// by V. Mustya

#include <atomic>
#include <cassert>
#include <thread>

std::atomic<unsigned> __attribute__((aligned (256))) a { 1 };
std::atomic<unsigned> __attribute__((aligned (256))) b { 1 };

extern "C"
void update() {
  while (a) {
    a++;
    b++;
  }
}

extern "C"
void readboth() {
  unsigned al, bl;
  do {
    bl = b.load();
    al = a.load();

    assert(bl <= al);
  } while (bl);
}

int main() {
  std::thread reader(readboth);
  std::thread updater(update);

  reader.join();
  updater.join();

  return 0;
}

