#include <iostream>
#include <chrono>
using namespace std::chrono;
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymwdl {Tuesday[last]/11/2020};
    std::cout << (ymwdl.ok()) << ' ';
    ymwdl = Tuesday[last]/-2/2021;
    std::cout << (ymwdl.ok()) << ' ';
    ymwdl += months(0); // Normalize month
    std::cout << (ymwdl.ok()) << '\n';
}