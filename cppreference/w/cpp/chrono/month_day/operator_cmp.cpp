#include <iostream>
#include <chrono>
 
int main()
{
    constexpr auto md1 {std::chrono::August/15};
    constexpr auto md2 {std::chrono::month(8)/std::chrono::day(15)};
    std::cout << std::boolalpha << (md1 == md2) << '\n';
 
    static_assert(md1 <= md2);
}