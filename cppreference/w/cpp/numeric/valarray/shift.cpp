
 #include <iostream>
#include <valarray>


int main() {
    std::valarray<int> v{1, 2, 3, 4, 5, 6, 7, 8};

    for (auto const& val : v) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    std::valarray<int> v2 = v.shift(2);

    for (auto const& val : v2) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
