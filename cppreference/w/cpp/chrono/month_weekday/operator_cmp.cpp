#include <iostream>
#include <chrono>
 
int main()
{
    constexpr auto mwdi1 {std::chrono::March/std::chrono::Friday[1]};
    constexpr std::chrono::month_weekday mwdi2 {std::chrono::month(3),
                                                std::chrono::weekday(5)[1]};
    std::cout << std::boolalpha << (mwdi1 == mwdi2) << '\n';
}