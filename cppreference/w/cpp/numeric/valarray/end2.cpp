
 #include <iostream>
#include <valarray>
#include <algorithm>

int main()
{
    const std::valarray<char> va {
        'H', 'e', 'l', 'l', 'o', 
        ',', ' ', 
        'C', '+', '+', '!', '\n'
    };

    std::for_each(
        std::begin(va),
        std::end(va),
        [](char c) {
            std::cout << c;
        });
}
