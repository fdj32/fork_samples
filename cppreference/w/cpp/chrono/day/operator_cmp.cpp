#include <iostream>
#include <chrono>
 
int main()
{
    std::chrono::day d1{15};
    std::chrono::day d2{20};
 
    d1 == d2 ? std::cout << "d1 and d2 are equal\n"
             : std::cout << "d1 and d2 are not equal\n";
 
    auto res = d1 <=> d2;
    if (res < 0)
        std::cout << "d1 is less than d2\n";
    else if (res > 0)
        std::cout << "d1 is greater than d2\n";
    else
        std::cout << "d1 and d2 are equal\n";
 
    using namespace std::literals::chrono_literals;
 
    std::cout << std::boolalpha
              << (6d < 9d) << ' ' << (6d == 6d) << ' ' << (6d <= 9d) << ' '
              << (9d > 6d) << ' ' << (9d != 6d) << ' ' << (9d >= 6d) << '\n';
}