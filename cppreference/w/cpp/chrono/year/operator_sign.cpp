#include <iostream>
#include <chrono>
 
int main()
{
    constexpr std::chrono::year y {2020};
    constexpr auto ny = -y;
    std::cout << "The year " << (int)y << " negated is " << (int)ny << "\n";      
}