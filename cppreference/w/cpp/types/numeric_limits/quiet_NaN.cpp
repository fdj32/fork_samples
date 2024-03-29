
 #include <iostream>
#include <limits>
#include <cmath>

int main()
{
    std::cout << std::numeric_limits<double>::quiet_NaN()     << ' ' // nan
              << std::numeric_limits<double>::signaling_NaN() << ' ' // nan
              << std::acos(2)    << ' '   // nan
              << std::tgamma(-1) << ' '   // nan
              << std::log(-1)    << ' '   // nan
              << std::sqrt(-1)   << ' '   // -nan
              << 0 / 0.0         << '\n'; // -nan

    std::cout << "NaN == NaN? " << std::boolalpha
              << ( std::numeric_limits<double>::quiet_NaN() ==
                   std::numeric_limits<double>::quiet_NaN() ) << '\n';
}
