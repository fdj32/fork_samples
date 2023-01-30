#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    auto ymwdi {std::chrono::Wednesday[1]/1/2021};
    std::cout << (ymwdi.ok()) << ' ';
    ymwdi = std::chrono::year(2021)/std::chrono::month(1)/
            std::chrono::Wednesday[42];
    std::cout << (ymwdi.ok()) << '\n';
}