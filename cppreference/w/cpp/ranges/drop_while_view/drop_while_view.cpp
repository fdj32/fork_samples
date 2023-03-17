
 #include <array>
#include <iostream>
#include <ranges>

int main()
{
    constexpr std::array data{ 0, -1, -2, 3, 1, 4, 1, 5, };

    auto view = std::ranges::drop_while_view{
        data, [](int x) { return x <= 0; }
    };

    for (int x: view) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
