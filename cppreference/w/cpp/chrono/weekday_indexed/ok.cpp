
 #include <iostream>
#include <chrono>

int main()
{
    std::cout << std::boolalpha;

    std::chrono::weekday_indexed wdi {std::chrono::Tuesday[2]};
    std::cout << (wdi.ok()) << ' ';
    wdi = {std::chrono::weekday(42)[2]}; 
    std::cout << (wdi.ok()) << ' ';
    wdi = {std::chrono::Tuesday[-4]}; 
    std::cout << (wdi.ok()) << '\n';
}
