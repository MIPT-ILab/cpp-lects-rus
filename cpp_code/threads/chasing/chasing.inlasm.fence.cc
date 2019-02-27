#include <cassert>
#include <thread>

volatile unsigned __attribute__((aligned (256))) a = 1;
volatile unsigned __attribute__((aligned (256))) b = 1;

extern "C"
void updateboth() {
  while (a) {
    a++;
    // Inner Shareable Store-Store barrier
    __asm__ __volatile__ ("dmb ishst\n" : : : "memory");
    b++;
  }
}

extern "C"
void readboth() {
  unsigned al, bl;
  do {
    bl = b;
    // Inner Shareable Load-Load and Load-Store barrier
    __asm__ __volatile__ ("dmb ishld\n" : : : "memory");
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

