#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
 
using namespace std::chrono_literals;
 
int main()
{
    // The old way
    std::time_t oldt = std::time({});
 
    std::this_thread::sleep_for(2700ms);
 
    // The new way
    auto const now = std::chrono::system_clock::now();
    std::time_t newt = std::chrono::system_clock::to_time_t(now);
 
    std::cout << "newt - oldt == " << newt - oldt << " s\n";
}
