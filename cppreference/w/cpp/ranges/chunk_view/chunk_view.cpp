
 #include <algorithm>
#include <iostream>
#include <ranges>

int main()
{
    auto i = std::views::iota(0, 10);
    auto w = std::ranges::chunk_view(i, 4);

    std::ranges::for_each(w, [](auto const v)
    {
        for (auto e : v)
            std::cout << e << ' ';
        std::cout << '\n';
    });
}
