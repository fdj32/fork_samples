#include <iostream>
#include <iomanip>
#include <chrono>
 
int main()
{
    for (const int i : {2020, 0x8000, 0x8001, 0xFFFF, 0x18000}) {
        const std::chrono::year y{i};
        std::cout << std::boolalpha
            << "input year: " << std::setw(6) << i
            << " │ internal value: " << std::setw(7) << static_cast<int>(y)
            << " │ ok(): " << y.ok() << '\n';
    }
}