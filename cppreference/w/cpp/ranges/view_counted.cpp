
 #include <ranges>
#include <iostream>

int main()
{
    const int a[] = {1, 2, 3, 4, 5, 6, 7};
    for(int i : std::views::counted(a, 3))
        std::cout << i << ' ';
    std::cout << '\n';

    const auto il = {1, 2, 3, 4, 5};
    for (int i : std::views::counted(il.begin() + 1, 3))
        std::cout << i << ' ';
    std::cout << '\n';
}
