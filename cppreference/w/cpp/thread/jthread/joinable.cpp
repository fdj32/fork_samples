#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
 
void foo()
{
    std::this_thread::sleep_for(500ms);
}
 
int main()
{
    std::cout << std::boolalpha;
 
    std::jthread t;
    std::cout << "before starting, joinable: " << t.joinable() << '\n';
 
    t = std::jthread{foo};
    std::cout << "after starting, joinable: " << t.joinable() << '\n';
 
    t.join();
    std::cout << "after joining, joinable: " << t.joinable() << '\n';
 
    t = std::jthread{foo};
    t.detach();
    std::cout << "after detaching, joinable: " << t.joinable() << '\n';
 
}