
 #include <iostream>
#include <chrono>

int main()
{
    constexpr std::chrono::day d {15};
    constexpr unsigned day = static_cast<unsigned>(d);
    std::cout << "The day is: " << day << '\n';
}
