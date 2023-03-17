
 #include <iostream>
#include <chrono>

int main()
{
    using namespace std::chrono;

    constexpr year y1{2020};
    constexpr year y2{2021};

    std::cout << std::boolalpha << (y1 != y2) << '\n';

    static_assert(
        (2020y < 2023y) && (2020y == 2020y) && (2020y <= 2023y) &&
        (2023y > 2020y) && (2023y != 2020y) && (2023y >= 2020y)
    );
}
