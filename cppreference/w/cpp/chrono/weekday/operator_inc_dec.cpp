#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    std::chrono::weekday wd {0}; // Sunday is 0 or 7
 
    --wd;
    std::cout << (wd == std::chrono::Saturday) << ' ';
 
    ++wd;
    std::cout << (wd == std::chrono::Sunday) << '\n';
}