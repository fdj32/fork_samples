
 #include <print>
#include <ranges>

int main()
{
    static constexpr auto v = {1, 2, 3, 4};
    constexpr auto w { std::ranges::chunk_view(v, 2) };
    std::println("{}", w.base());
}
