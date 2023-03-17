
 #include <cmath>
#include <iostream>

int main()
{
    std::cout << std::showpos
              << "tanh(+1) = " << std::tanh(+1) << '\n'
              << "tanh(-1) = " << std::tanh(-1) << '\n'
              << "tanh(0.1)*sinh(0.2)-cosh(0.2) = "
              << std::tanh(0.1) * std::sinh(0.2) - std::cosh(0.2) << '\n'
              // special values:
              << "tanh(+0) = " << std::tanh(+0.0) << '\n'
              << "tanh(-0) = " << std::tanh(-0.0) << '\n';
}
