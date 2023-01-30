#include <iostream>
#include <chrono>
 
int main()
{
    using namespace std::literals;
 
    constexpr std::chrono::weekday wd1{2};
    constexpr std::chrono::weekday wd2{std::chrono::Friday};
    // 1 January 2021 is a Friday
    constexpr std::chrono::weekday wd3{2021y/1/1}; 
 
    std::cout << std::boolalpha;
    std::cout << (wd1 == wd2) << "\n";
    std::cout << (wd2 == wd3) << "\n";
}