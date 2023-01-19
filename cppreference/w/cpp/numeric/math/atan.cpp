#include <iostream>
#include <cmath>
 
int main()
{
    std::cout << "atan(1) = " << atan(1) << " 4*atan(1) = " << 4*atan(1) << '\n';
    // special values
    std::cout << "atan(Inf) = " << atan(INFINITY)
              << " 2*atan(Inf) = " << 2*atan(INFINITY) << '\n'
              << "atan(-0.0) = " << atan(-0.0) << '\n'
              << "atan(+0.0) = " << atan(0) << '\n';
}