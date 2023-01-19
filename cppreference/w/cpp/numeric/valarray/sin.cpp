#include <valarray>
#include <iostream>
#include <numbers>
#include <cmath>
 
int main()
{
    std::valarray<double> v1 = {0, 0.25, 0.5, 0.75, 1};
    std::valarray<double> v2 = std::sin(v1 * std::numbers::pi);
 
    for(double n : v2)
        std::cout << std::fixed << n << ' ';
    std::cout << '\n';
}