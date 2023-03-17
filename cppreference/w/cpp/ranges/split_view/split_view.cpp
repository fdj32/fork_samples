
 #include <string_view>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <ranges>
#include <vector>
#include <array>

int main()
{
    {
        auto view = std::views::iota(1, 20)
                  | std::views::transform([](int x) { return x % 5; });
        auto splitts = std::views::split(view, 0); // (2)
        for (const auto& split : splitts) {
            std::cout << "{ ";
            std::ranges::copy(split, std::ostream_iterator<int>(std::cout, " "));
            std::cout << "} ";
        }
    }
    std::cout << '\n';
    {
        const std::vector nums{ 1, -1, -1, 2, 3, -1, -1, 4, 5, 6 };
        const std::array delim{ -1, -1 };
        auto splitter = std::views::split(nums, delim); // (3)
        for (const auto& split : splitter) {
            std::cout << "{ ";
            std::ranges::copy(split, std::ostream_iterator<int>(std::cout, " "));
            std::cout << "} ";
        }
    }
    std::cout << '\n';
    {
        constexpr std::string_view JupiterMoons{
            "Callisto, Europa, Ganymede, Io, and 75 more"
        };
        constexpr std::string_view delim{", "};
        std::ranges::split_view moons_extractor{ JupiterMoons, delim }; // (3)
        for (const std::string_view moon : moons_extractor) {
            std::cout << std::quoted(moon) << ' ';
        }
    }
}
