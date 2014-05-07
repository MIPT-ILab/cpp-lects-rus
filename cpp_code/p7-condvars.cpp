#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable c;
std::mutex mu;

void thread_func() 
{ 
  /* ... */
  std::unique_lock<std::mutex> lock(mu);
  /* ... */
  printf ("Notification issued\n");
  c.notify_one(); /* It also releases the unique lock */
  /* ... */
}

int 
main (void)
{
  std::unique_lock<std::mutex> lock(mu); /* Lock the mutex */
  std::thread t1(thread_func); 

  printf ("Waiting started\n");

  c.wait(lock); /* This unlocks the mutex mu and allows thread_func to lock it */

  printf ("Waiting complete\n");

  /* ... */

  t1.join();
  return 0;
}
