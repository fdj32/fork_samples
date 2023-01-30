#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    std::chrono::weekday wd {4};
    wd = wd + std::chrono::days(2);
    std::cout << (wd == std::chrono::weekday(6)) << ' '
              << (wd == std::chrono::Saturday) << ' ';
 
    wd = wd - std::chrono::days(3);
    std::cout << (wd == std::chrono::weekday(3)) << ' '
              << (wd == std::chrono::Wednesday) << ' ';
 
    wd = std::chrono::Tuesday;
    wd = wd + std::chrono::days{8}; // (((2 + 8) == 10) % 7) == 3;
    std::cout << (wd == std::chrono::Wednesday) << ' ';
 
    wd = wd + (std::chrono::Sunday - std::chrono::Thursday); // (3 + 3) == 6
    std::cout << (wd == std::chrono::Saturday) << '\n';
}