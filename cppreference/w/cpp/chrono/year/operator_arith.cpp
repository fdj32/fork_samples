#include <iostream>
#include <chrono>
 
int main()
{
    using namespace std::literals::chrono_literals;
    std::cout << std::boolalpha;
 
    std::chrono::year y {2020};
 
    y += std::chrono::years(12);
    std::cout << (y == 2032y) << ' ';
 
    y -= std::chrono::years(33);
    std::cout << (y == 1999y) << '\n';
}