
 #include <valarray>
#include <iostream>

int main()
{
    int a[] = {1, 2, 3, 4};
    std::valarray va(a, 3); // uses explicit deduction guide
    for (int x : va)
        std::cout << x << ' ';
}
