
 #include <iostream>
#include <limits>

int main()
{
    std::cout << "max() = " << std::numeric_limits<float>::max() << '\n'
              << "max_exponent10 = " << std::numeric_limits<float>::max_exponent10 << '\n'
              << std::hexfloat << '\n'
              << "max() = " << std::numeric_limits<float>::max() << '\n'
              << "max_exponent = " << std::numeric_limits<float>::max_exponent << '\n';
}
