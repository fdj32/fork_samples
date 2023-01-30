#include <chrono>
#include <iostream>
 
int main()
{
    constexpr std::chrono::day d1 {31}, d2 {7}, d3 {42}, d4 {};
    std::cout << d1 << '\n'
              << d2 << '\n'
              << d3 << '\n'
              << d4 << '\n';
}