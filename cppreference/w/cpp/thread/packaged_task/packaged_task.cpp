
 #include <future>
#include <iostream>
#include <thread>

int fib(int n)
{
    if (n < 3) return 1;
    else return fib(n-1) + fib(n-2);
}

int main()
{
    std::packaged_task<int(int)> fib_task(&fib); 

    std::cout << "starting task\n";
    auto result = fib_task.get_future();
    std::thread t(std::move(fib_task), 42);

    std::cout << "waiting for task to finish..." << std::endl;
    std::cout << result.get() << '\n';

    std::cout << "task complete\n";
    t.join();
}
