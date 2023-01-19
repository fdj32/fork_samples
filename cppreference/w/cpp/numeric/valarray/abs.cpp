#include <valarray>
#include <iostream>
 
int main()
{
    std::valarray<int> v{1, -2, 3, -4, 5, -6, 7, -8};
    std::valarray<int> v2 = std::abs(v);
    for(auto n : v2) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}