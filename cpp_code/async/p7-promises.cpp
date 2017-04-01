#include <utility>
#include <thread>
#include <future>
#include <iostream>

int
main (void)
{
  auto promise = std::promise<std::string>();

  auto producer = std::thread([&]
    {
      promise.set_value("Hello World\n");
    });

  auto future = promise.get_future();

  auto consumer = std::thread([&]
    {
      std::cout << future.get();
    });

  producer.join();
  consumer.join();

  return 0;
}
