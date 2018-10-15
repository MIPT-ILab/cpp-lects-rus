#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;

int main () {
  cout << "Parent id: " << std::this_thread::get_id() << endl;
  thread t([](){ cout << "Spawned id: " << std::this_thread::get_id() << endl; });
  t.join();
  return 0;
}

