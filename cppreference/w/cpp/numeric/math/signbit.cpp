#include <iostream>
#include <cmath>
 
int main()
{
    std::cout << std::boolalpha
              << "signbit(+0.0) = " << std::signbit(+0.0) << '\n'
              << "signbit(-0.0) = " << std::signbit(-0.0) << '\n';
}