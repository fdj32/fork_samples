
 #include <array>
#include <iostream>
#include <iomanip>
#include <ranges>

int main()
{
    constexpr std::array data{ 0, -1, -2, 3, 1, 4, 1, 5, };

    auto view = std::ranges::drop_while_view{
        data, [](int x) { return x <= 0; }
    };

    std::cout << std::boolalpha;
    for (int x: data) {
        std::cout << "predicate(" << std::setw(2) << x << "): "
                  << view.pred()(x) << '\n';
    }
}
