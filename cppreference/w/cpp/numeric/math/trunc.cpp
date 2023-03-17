
 #include <cmath>
#include <iostream>
#include <initializer_list>

int main()
{
    const auto data = std::initializer_list<double>{
        +2.7, -2.9, +0.7, -0.9, +0.0, 0.0, -INFINITY, +INFINITY, -NAN, +NAN
    };

    std::cout << std::showpos;
    for (double const x : data) {
        std::cout << "trunc(" << x << ") == " << std::trunc(x) << '\n';
    }
}
