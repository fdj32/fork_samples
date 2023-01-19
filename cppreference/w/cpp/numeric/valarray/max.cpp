#include <valarray>
#include <iostream>
 
int main()
{
    std::valarray<double> a{1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Maximum value : " << a.max() << "\n";
}