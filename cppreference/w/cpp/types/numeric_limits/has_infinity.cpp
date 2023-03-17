
 #include <iostream>
#include <limits>

int main()
{
    std::cout << std::boolalpha
              << std::numeric_limits<int>::has_infinity << '\n'
              << std::numeric_limits<long>::has_infinity << '\n'
              << std::numeric_limits<float>::has_infinity << '\n'
              << std::numeric_limits<double>::has_infinity << '\n';
}
