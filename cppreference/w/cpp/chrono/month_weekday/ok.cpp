#include <iostream>
#include <chrono>
 
int main()
{
    std::cout << std::boolalpha;
 
    auto mwdi {std::chrono::March/std::chrono::Friday[1]};
    std::cout << (mwdi.ok()) << ' ';
    mwdi = {std::chrono::month(17)/std::chrono::Friday[1]}; 
    std::cout << (mwdi.ok()) << ' ';
    mwdi = {std::chrono::March/std::chrono::Friday[-4]}; 
    std::cout << (mwdi.ok()) << '\n';
}