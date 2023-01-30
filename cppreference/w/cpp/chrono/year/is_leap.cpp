#include <iostream>
#include <chrono>
 
int main()
{
    using namespace std::chrono_literals;
    for (const std::chrono::year y : {2020y, 2021y, 2000y, 3000y}) {
        if (const int iy{ static_cast<int>(y) }; y.is_leap()) {
            std::cout << iy << " is a leap year because it is divisible by "
                      << (iy % 400 == 0 ? "400\n" : "4 and not divisible by 100\n");
        } else {
            std::cout << iy << " is not a leap year\n";
        }
    }
}