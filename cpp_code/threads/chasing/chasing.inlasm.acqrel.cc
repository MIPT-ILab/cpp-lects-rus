#include <cassert>
#include <thread>

volatile unsigned __attribute__((aligned (256))) a = 1;
volatile unsigned __attribute__((aligned (256))) b = 1;

extern "C"
void updateboth() {
  while (a) {
    a++;
    register unsigned bl = b + 1;
    // For a Store-Release, observers in the shareability domain of the address accessed by the Store-Release
    // observe accesses in the following order:
    //   1. All of the following for which the shareability of the address accessed requires that the observer
    //   observes the access:
    //     * Reads and writes caused by loads and stores that appear in program order before the
    //     Store-Release.
    //     * Writes that were observed by the PE executing the Store-Release before it executed the
    //     Store-Release.
    //   2. The write caused by the Store-Release.
    // There are no other ordering requirements on loads or stores that appear in program order after the
    // Store-Release.
    __asm__ __volatile__ ("stlr %w0, [%1]"
                          :
                          : "r"(bl), "r"(&b)
                          : "memory");
  }
}

extern "C"
void readboth() {
  register unsigned al, bl;
  do {
    // For a Load-Acquire, observers in the shareability domain of the address accessed by the Load-Acquire
    // observe accesses in the following order:
    //   1. The read caused by the Load-Acquire.
    //   2. Reads and writes caused by loads and stores that appear in program order after the Load-Acquire for
    //   which the shareability of the address accessed by the load or store requires that the observer observes
    //   the access.
    // There are no additional ordering requirements on loads or stores that appear before the Load-Acquire.
    __asm__ __volatile__ ("ldar %w0, [%1]\n"
                          : "=r"(bl)
                          : "r" (&b)
                          : "memory");
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

