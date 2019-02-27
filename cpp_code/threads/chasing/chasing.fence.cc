#include <atomic>
#include <cassert>
#include <thread>

unsigned __attribute__((aligned (256))) a = 1;
unsigned __attribute__((aligned (256))) b = 1;

extern "C"
void updateboth() {
  while (a) {
    a++;
    // Inner Shareable Store-Store barrier
    std::atomic_thread_fence(std::memory_order_release);
    b++;
  }
}

extern "C"
void readboth() {
  unsigned al, bl;
  do {
    bl = b;
    // Inner Shareable Load-Load and Load-Store barrier
    std::atomic_thread_fence(std::memory_order_acquire);
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

