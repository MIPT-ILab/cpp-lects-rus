#include <atomic>
#include <iostream>
#include <thread>

using std::atomic;
using std::cout;
using std::endl;
using std::thread;

struct User;

struct Resource {
  atomic<User *> owner {nullptr};
  void use() {
    cout << "used!" << endl;
  }
};

struct User {
  atomic<bool> done {false};
  void useItPolitely(Resource &res, User &other) {
    while (!done) {
      // if no owner, take resource
      if (res.owner == nullptr)
        res.owner = this;
      
      // if owner not me, wait
      if (res.owner != this) {
        std::this_thread::yield();
        continue;
      }

      // if owner me, but other not done, yield
#if !defined(NOLIVELOCK)
      if (!other.done) {
        res.owner = nullptr;
        continue;
      }
#endif      
      
      res.use();
      res.owner = nullptr;
      done = true;
    }
  }
};

int main ()
{
  Resource common;
  User fst, snd;
  common.owner = &fst;
  thread t1{[&]() mutable { fst.useItPolitely(common, snd); }};
  thread t2{[&]() mutable { snd.useItPolitely(common, fst); }};
  t1.join(); t2.join();
}

