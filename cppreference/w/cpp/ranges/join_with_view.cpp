
 #include <iostream>
#include <ranges>
#include <vector>
#include <string_view>

int main() {
    using namespace std::literals;

    std::vector v{"This"sv, "is"sv, "a"sv, "test."sv};
    auto joined = v | std::views::join_with(' ');

    for (auto c : joined) std::cout << c;
    std::cout << '\n';
}
