
 #include <chrono>
#include <iostream>
#include <thread>
using namespace std::chrono_literals;

void f()
{
    std::cout << "Output from thread...";
    std::this_thread::sleep_for(2s);
    std::cout << "...thread calls flush()" << std::endl;
}

int main()
{
    std::jthread t1{f};
    std::this_thread::sleep_for(1000ms);
    std::clog << "This output from main is not tie()'d to cout\n";
    std::cerr << "This output is tie()'d to cout\n";
}
