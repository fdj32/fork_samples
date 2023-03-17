
 #include <tuple>
#include <ranges>
#include <string>
#include <iostream>

template<class... Ts>
void print(std::tuple<Ts...> const& tuple)
{
    std::apply([&](auto&& arg, auto&&... args) {
        std::cout << arg;
        ((std::cout << args), ...);
    }, tuple);
    std::cout << '\n';
}

int main()
{
    const std::string v {"ABCDEF"};
    constexpr int window_size{4};

    std::cout
        << "window size = " << window_size << '\n'
        << "v = " << v << '\n';

    auto view = std::views::adjacent<window_size>(v); // overload (2)

    for (auto const& tuple: view)
    {
        print(tuple);
    }
}
