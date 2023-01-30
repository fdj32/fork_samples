#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    std::chrono::month m {6};
    m += std::chrono::months(2);
    std::cout << (m == std::chrono::month(8)) << ' '
              << (m == std::chrono::August) << ' ';
 
    m -= std::chrono::months(3);
    std::cout << (m == std::chrono::month(5)) << ' '
              << (m == std::chrono::May) << ' ';
 
    m = std::chrono::October;
    m += std::chrono::months{8}; // ((10 += 8 == 18) % 12) == 6;
    std::cout << (m == std::chrono::June) << ' ';
 
    m -= std::chrono::months{std::chrono::December - std::chrono::February}; // -= 10
    // (6 -= 10) == -4; -4 % 12 == (12-4) == 8
    std::cout << (m == std::chrono::August) << '\n';
}