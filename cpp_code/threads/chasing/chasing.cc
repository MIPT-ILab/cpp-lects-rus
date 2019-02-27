// by V. Mustya

#include <cassert>
#include <thread>

volatile unsigned
  __attribute__ ((aligned(256))) a = 1;
volatile unsigned 
  __attribute__ ((aligned(256))) b = 1;

extern "C"
void updateboth() {
  while (a) {
    a++;
    b++;
  }
}

extern "C"
void readboth() {
  unsigned al, bl;
  do {
    bl = b;
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

