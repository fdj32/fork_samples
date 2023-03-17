
 #include <chrono>
#include <iostream>

int main()
{
    constexpr std::chrono::year y1 {2020}, y2 {-020}, y3 {98304};
    std::cout << y1 << '\n'
              << y2 << '\n'
              << y3 << '\n';
}
