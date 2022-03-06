#include <iostream>
#include <thread>
#include <utility>

using std::cout;
using std::endl;
using std::thread;

void divide(int &result, int a, int b) { result = a / b; }

int main() {
  int result;
  thread t(divide, std::ref(result), 30, 6);
  t.join();
  cout << "result: " << result << endl;
}
