#include <cmath>
#include <iostream>
int main()
{
    double hpi = std::acos(-1)/2;
#ifndef __clang__
    std::cout << "Π(0,0,π/2) = " << std::ellint_3(0, 0, hpi) << '\n'
              << "π/2 = " << hpi << '\n';
#endif              
}