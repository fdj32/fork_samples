#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
 
int main()
{
#ifndef __clang__
    using namespace std::chrono_literals;
 
    const std::time_t t = std::time(nullptr); // usually has "1 second" precision
 
    const auto from = std::chrono::system_clock::from_time_t(t);
 
    std::this_thread::sleep_for(500ms);
 
    const auto diff = std::chrono::system_clock::now() - from;
 
    std::cout << diff << " ("
              << std::chrono::round<std::chrono::milliseconds>(diff)
              << ")\n";
#endif
}